/// @file     display.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    Ç¥ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ file
#define DISPLAY_C
#include "include/_include.h"

#define Z_SOURCE_NUM 		(3)						//	Source ï¿½ï¿½ï¿½ï¿½

//#define Z_Fade_Select			(10)				//	Fade Timer 100ms
#define Z_Fade_Select			(8)					//	Fade Timer 80ms
#define Z_ON_DimmingPercent		(100)				//	ON Dimming
#define Z_DimmingPercent		(40)				//	ï¿½ï¿½ï¿½Ï°ï¿½ ON
#define Z_DimmingPercent_Low	(10)				//	ï¿½ï¿½ ï¿½ï¿½ï¿½Ï°ï¿½

static void Operation_Display(void);

static void LED_EFFLUENT(void);
static void LED_HOT(void);
static void LED_PURE(void);
static void LED_COLD(void);
static void LED_AMOUNT(void);
static void LED_CUP(void);
static void LED_COLD_TEMP(void);
static void LED_WIFI(void);
static void LED_FILTER_CHANGE(void);
static void LED_FAUCET(void);
static void LED_ML(void);
static void LED_DEGREE(void);
static void LED_UV(void);
static void LED_HOTLOCK(void);
static void LED_PERCENT(void);
static void LED_HOTBAR(void);

static void SegDataSet(void);
static void SegDataClear(void);

/// @brief    Ç¥ï¿½Ãºï¿½ ï¿½Ê±ï¿½È­
/// @param    void
/// @return   void
void Display_Initialize(void)
{
	gu8_Fade_Select = Z_Fade_Select;				//	Fade Timer ï¿½Ê±â°ª
	gu8_ON_DimmingPercent = Z_ON_DimmingPercent;
	gu8_DimmingPercent = Z_DimmingPercent;			//	Dimming Percent ï¿½Ê±â°ª
	gu8_DimmingPercent_Low = Z_DimmingPercent_Low;	//	Dimming Percent ï¿½Ê±â°ª
}

/// @brief    Ç¥ï¿½Ãºï¿½ ï¿½ï¿½ï¿½ï¿½
/// @param    void
/// @return   void
void DisplayControl(void)
{
	U8 i;

	for (i = 0 ; i < DisplayNum_Max ; i++)
	{
		DisplayControl_Data[i].Display_CMD = LED_OFF;	//		Ç¥ï¿½ï¿½ CMD ï¿½Ê±ï¿½È­
	}

	SegDataClear();
	Operation_Display();							//	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Â¿ï¿½ ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½

	for (i = 0 ; i < DisplayNum_Max ; i++)
	{
		if (DisplayControl_Data[i].Display_CMD != DisplayControl_Data[i].Display_CMD_Before)	//	Ç¥ï¿½ï¿½ ï¿½ï¿½ï¿½Â°ï¿½ ï¿½ï¿½ï¿½Ï´ï¿½ ï¿½ï¿½ï¿???????
		{
			F_CommunicationCMD = SET;				//		ï¿½ï¿½ï¿??????? ï¿½ï¿½ï¿??????? ï¿½Û½ï¿½
		}
		DisplayControl_Data[i].Display_CMD_Before = DisplayControl_Data[i].Display_CMD;		//	ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	}
}

/// @brief    Data Clear
/// @param    void
/// @return   void
static void SegDataClear(void)
{
	U8 mu8_i;

	for (mu8_i = 0 ; mu8_i < Z_SOURCE_NUM ; mu8_i++)	//	Seg ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	{
		gu8_SegData[mu8_i].byte = 0x00;					//		clr
	}
}

/// @brief    ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½Data Ã³ï¿½ï¿½
/// @param    void
/// @return   void
static void Operation_Display(void)
{
	SegDataSet();									//	7-Segment ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ set

	LED_EFFLUENT();
	LED_HOT();
	LED_HOTBAR();
	LED_PURE();
	LED_COLD();
	LED_AMOUNT();
	
	if ((F_TestMode_LineFront == SET) && (gu16_TimerFCT_Incomplete_Display != 0)
		&& (F_TestMode_LineAuto != SET))	
	{
		return;	
	}
	LED_CUP();
	LED_COLD_TEMP();
	LED_WIFI();
	LED_FILTER_CHANGE();
	LED_FAUCET();
	LED_ML();
	LED_DEGREE();
	LED_UV();
	LED_HOTLOCK();
	LED_PERCENT();
}

/// @brief
/// @param    void
/// @return   void
static void SegDataSet(void)
{
	U16 mu16_Cup_buf = 0;
	U16 mu16_Seg_buf = 0;
	static I16 mi16_Seg_buf_forSEGTH = 0;
	U8 mu8_OPENSHORT_Error = 0;
	U8 mu8_TotalPercent = 0;
	U8 temp;
	U8 mu8_buf = 0;
	U16 mu16_temp = 0;
	U16 mu16_FrontTest = 0;

	static U8 mu8_AdFeedback_State = 0;      // »óÅÂ (0:VOL ÅØ½ºÆ®, 1:VOL °ª, 2:TEM ÅØ½ºÆ®, 3:TEM °ª)    
    U16 mu16_TemValue = 0;   // TEM °ª
    U16 mu16_VolValue = 0;  // VOL °ª
    U8 mu8_Thousands = 0;
    U8 mu8_Hundreds = 0;
    U8 mu8_Tens = 0;
    U8 mu8_Ones = 0;

	switch (DisplayControl_Data[Z_SEGMENT].Operation_CMD)	//	7-Segment ï¿½ï¿½ï¿½Ã¿ï¿½ ï¿½ï¿½ï¿½ï¿½
	{
		case SEG_OFF:								//		OFF ï¿½ï¿½ï¿½ï¿½
			break;
		case SEG_ON_FLIC:							//		`ON` ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
			SEG_OXX = DT_7seg[Z_NUM_O];
			SEG_XOX = DT_7seg[Z_NUM_n];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			break;
		case SEG_OFF_FLIC:							//		`OFF` ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
			SEG_OXX = DT_7seg[Z_NUM_O];
			SEG_XOX = DT_7seg[Z_NUM_F];
			SEG_XXO = DT_7seg[Z_NUM_F];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			break;
		case SEG_OFF_DISP:							//		`OFF` ï¿½ï¿½ï¿½ï¿½
			SEG_OXX = DT_7seg[Z_NUM_O];
			SEG_XOX = DT_7seg[Z_NUM_F];
			SEG_XXO = DT_7seg[Z_NUM_F];
			if (gu8_TimerOFF_Flic != 0)
			{
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else
			{
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			break;
		case SEG_ONOFF_MOVE:
			if (F_SleepMode_Display == SET)
			{
				if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*11))
				{
					SEG_XXO = DT_7seg[Z_NUM_S];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*10))
				{
					SEG_XOX = DT_7seg[Z_NUM_S];
					SEG_XXO = DT_7seg[Z_NUM_L];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*9))
				{
					SEG_OXX = DT_7seg[Z_NUM_S];
					SEG_XOX = DT_7seg[Z_NUM_L];
					SEG_XXO = DT_7seg[Z_NUM_E];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*8))
				{
					SEG_OXX = DT_7seg[Z_NUM_L];
					SEG_XOX = DT_7seg[Z_NUM_E];
					SEG_XXO = DT_7seg[Z_NUM_E];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*7))
				{
					SEG_OXX = DT_7seg[Z_NUM_E];
					SEG_XOX = DT_7seg[Z_NUM_E];
					SEG_XXO = DT_7seg[Z_NUM_P];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*6))
				{
					SEG_OXX = DT_7seg[Z_NUM_E];
					SEG_XOX = DT_7seg[Z_NUM_P];
					SEG_XXO = DT_7seg[Z_NUM_BAR];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*5))
				{
					SEG_OXX = DT_7seg[Z_NUM_P];
					SEG_XOX = DT_7seg[Z_NUM_BAR];
					SEG_XXO = DT_7seg[Z_NUM_O];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*4))
				{
					SEG_OXX = DT_7seg[Z_NUM_BAR];
					SEG_XOX = DT_7seg[Z_NUM_O];
					if (F_SleepMode == SET)
					{
						SEG_XXO = DT_7seg[Z_NUM_n];
					}
					else
					{
						SEG_XXO = DT_7seg[Z_NUM_F];
					}
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*3))
				{
					SEG_OXX = DT_7seg[Z_NUM_O];
					if (F_SleepMode == SET)
					{
						SEG_XOX = DT_7seg[Z_NUM_n];
					}
					else
					{
						SEG_XOX = DT_7seg[Z_NUM_F];
						SEG_XXO = DT_7seg[Z_NUM_F];
					}
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*2))
				{
					if (F_SleepMode == SET)
					{
						SEG_OXX = DT_7seg[Z_NUM_n];
					}
					else
					{
						SEG_OXX = DT_7seg[Z_NUM_F];
						SEG_XOX = DT_7seg[Z_NUM_F];
					}
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*1))
				{
					if (F_SleepMode == SET)
					{

					}
					else
					{
						SEG_OXX = DT_7seg[Z_NUM_F];
					}
				}
				else
				{

				}
			}
			else if (F_ColdOff_Display == SET)
			{
				if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*11))
				{
					SEG_XXO = DT_7seg[Z_NUM_C];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*10))
				{
					SEG_XOX = DT_7seg[Z_NUM_C];
					SEG_XXO = DT_7seg[Z_NUM_o];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*9))
				{
					SEG_OXX = DT_7seg[Z_NUM_C];
					SEG_XOX = DT_7seg[Z_NUM_o];
					SEG_XXO = DT_7seg[Z_NUM_L];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*8))
				{
					SEG_OXX = DT_7seg[Z_NUM_o];
					SEG_XOX = DT_7seg[Z_NUM_L];
					SEG_XXO = DT_7seg[Z_NUM_d];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*7))
				{
					SEG_OXX = DT_7seg[Z_NUM_L];
					SEG_XOX = DT_7seg[Z_NUM_d];
					SEG_XXO = DT_7seg[Z_NUM_BAR];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*6))
				{
					SEG_OXX = DT_7seg[Z_NUM_d];
					SEG_XOX = DT_7seg[Z_NUM_BAR];
					SEG_XXO = DT_7seg[Z_NUM_O];
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*5))
				{
					SEG_OXX = DT_7seg[Z_NUM_BAR];
					SEG_XOX = DT_7seg[Z_NUM_O];
					if (F_ColdOff == CLEAR)
					{
						SEG_XXO = DT_7seg[Z_NUM_n];
					}
					else
					{
						SEG_XXO = DT_7seg[Z_NUM_F];
					}
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*4))
				{
					SEG_OXX = DT_7seg[Z_NUM_O];
					if (F_ColdOff == CLEAR)
					{
						SEG_XOX = DT_7seg[Z_NUM_n];
					}
					else
					{
						SEG_XOX = DT_7seg[Z_NUM_F];
						SEG_XXO = DT_7seg[Z_NUM_F];
					}
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*3))
				{
					if (F_ColdOff == CLEAR)
					{
						SEG_OXX = DT_7seg[Z_NUM_n];
					}
					else
					{
						SEG_OXX = DT_7seg[Z_NUM_F];
						SEG_XOX = DT_7seg[Z_NUM_F];
					}
				}
				else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay/12)*2))
				{
					if (F_ColdOff == CLEAR)
					{

					}
					else
					{
						SEG_OXX = DT_7seg[Z_NUM_F];
					}
				}
				else
				{

				}
			}

			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_ERR_FLIC:						//		ï¿½ï¿½ï¿½ï¿½Ç¥ï¿½ï¿½
			SEG_OXX = DT_7seg[Z_NUM_E];
			SEG_XOX = DT_7seg[(gu8_ErrorCode & 0xf0)>>4];
			SEG_XXO = DT_7seg[(gu8_ErrorCode & 0x0f)];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			break;
		case SEG_FLUSHING:
			mu8_buf = (U8)((U32)gu16_Flushing_Hz_forDisplay * 90 / gu16_Flushing_TotalHz_forDisplay);
																	//	0 ~ 100% Ç¥ï¿½Ã¸ï¿½ ï¿½ï¿½ï¿½ï¿½ % ï¿½ï¿½ï¿???????
			if (mu8_buf <= 100)
			{
				mu8_TotalPercent = (U8)(100-mu8_buf);				//	[0 -> 100] Ç¥ï¿½ï¿½

			}

			/*	1% ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½ (ï¿½ï¿½ï¿½ï¿½) */
			if (mu8_TotalPercent >= 100)
			{
				SEG_OXX = DT_7seg[(mu8_TotalPercent / 100) % 10];	//	SEG 100ï¿½Ú¸ï¿½ Ç¥ï¿½ï¿½
				SEG_XOX = DT_7seg[Z_NUM_0];
				SEG_XXO = DT_7seg[Z_NUM_0];				
			}
			if (mu8_TotalPercent >= 10)
			{
				SEG_XOX = DT_7seg[(mu8_TotalPercent / 10) % 10];	//	SEG 10ï¿½Ú¸ï¿½ Ç¥ï¿½ï¿½
				SEG_XXO = DT_7seg[Z_NUM_0];	
			}

			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;

//		case SEG_CoL:
//			SEG_OXX = DT_7seg[Z_NUM_C];
//			SEG_XOX = DT_7seg[Z_NUM_o];
//			SEG_XXO = DT_7seg[Z_NUM_L];
//			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
//			break;
		case SEG_TOPCOVER:
#ifndef _AFTER_LPP_IMDCHANGE_
			if (INPUT_REED_SW_FAUCET == CLEAR)
			{
				SEG_OXX = DT_7seg[Z_NUM_F];
				SEG_XOX = DT_7seg[Z_NUM_L];
				SEG_XXO = DT_7seg[Z_NUM_o];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
#endif
			break;
		case SEG_ERR_HIS:							//		ï¿½ï¿½ï¿½ï¿½ï¿½Ì·ï¿½
			if (gu8_TimerErrorHistory == 0)			//			Ç¥ï¿½ï¿½ Å¸ï¿½Ì¸ï¿½ ï¿½ï¿½ï¿??????? ï¿½ï¿½
			{
				gu8_TimerErrorHistory = Z_TimerErrorHistory;
				if (++gu8_CounterErrorHistory >= Z_ErrorHistory)
				{
					gu8_CounterErrorHistory = 0;
				}
			}
			if (gu8_TimerErrorHistory < (Z_TimerErrorHistory-10))	//	ï¿½Ì·ï¿½ Ç¥ï¿½ï¿½ Å¸ï¿½Ì¸ï¿½ ï¿½ï¿½, 1ï¿½Ê´ï¿½ SEG OFFï¿½ï¿½ ï¿½Ï¿ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
			{
				if (gu8_ErrorHistory[gu8_CounterErrorHistory] == 0x00)
				{
					SEG_OXX = DT_7seg[Z_NUM_E];
					SEG_XOX = DT_7seg[Z_NUM_BAR];
					SEG_XXO = DT_7seg[Z_NUM_BAR];
				}
				else
				{
					SEG_OXX = DT_7seg[Z_NUM_E];
					SEG_XOX = DT_7seg[(gu8_ErrorHistory[gu8_CounterErrorHistory] & 0xf0) >> 4];
					SEG_XXO = DT_7seg[(gu8_ErrorHistory[gu8_CounterErrorHistory] & 0x0f)];
				}
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else
			{
				SEG_OXX = DT_7seg[gu8_CounterErrorHistory+1];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			break;
		case SEG_VER:
			if (F_TestMode_PBA == SET)
			{
				if (gu16_TimerVersionDisplay <= (Z_TimerPBATestDisplay/2))	//	ï¿½×½ï¿½Æ®ï¿½ï¿½ï¿??????? 1 Ç¥ï¿½ï¿½
				{
					SEG_OXX = DT_7seg[Z_NUM_t];
					SEG_XOX = DT_7seg[Z_NUM_E];
					SEG_XXO = DT_7seg[Z_NUM_1];
				}
				else								//	ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
				{
					if (INPUT_MODEL_NATIONAL == MODEL_KOREA)
					{
						SEG_XOX = DT_7seg[Z_NUM_K];
						SEG_XXO = DT_7seg[Z_NUM_r];
					}
					else
					{
						SEG_XOX = DT_7seg[Z_NUM_J];
						SEG_XXO = DT_7seg[Z_NUM_P];
					}
				}
			}
			else
			{
				if (gu16_TimerVersionDisplay <= 50)		//			?ï¿½ï¿½ ï¿½Ì³ï¿½ ï¿½ï¿½ï¿½ï¿½Ç¥ï¿½ï¿½
				{
#ifdef _FOR_DEVELOP_
					SEG_OXX = DT_7seg[(gu16_Front_ProgramVer & 0x0F00) >> 8];	//	DPP or LPP ï¿½Ü°ï¿½ Ç¥ï¿½ï¿½
#endif
					SEG_XOX = DT_7seg[(gu16_Front_ProgramVer & 0x00F0) >> 4];
					SEG_XXO = DT_7seg[(gu16_Front_ProgramVer & 0x000F)];

				}
				if (gu16_TimerVersionDisplay <= 100)				//			ï¿½Òµï¿½
				{

				}
				else if (gu16_TimerVersionDisplay <= 150)		//			?ï¿½ï¿½ ï¿½Ì³ï¿½ ï¿½ï¿½ï¿½ï¿½Ç¥ï¿½ï¿½
				{
#ifdef _FOR_DEVELOP_
					SEG_OXX = DT_7seg[(PROGRAM_VERSION_NO & 0x0F00) >> 8];	//	DPP or LPP ï¿½Ü°ï¿½ Ç¥ï¿½ï¿½
#endif
					SEG_XOX = DT_7seg[(PROGRAM_VERSION_NO & 0x00F0) >> 4];
					SEG_XXO = DT_7seg[(PROGRAM_VERSION_NO & 0x000F)];
				}
				else
				{
					if (gu8_ModelType_forNational == MODEL_KOREA)
					{
						if (gu8_ModelType_forCHP == MODEL_CHP)
						{
							SEG_OXX = DT_7seg[Z_NUM_C];
							SEG_XOX = DT_7seg[Z_NUM_H];
							SEG_XXO = DT_7seg[Z_NUM_P];
						}
						else
						{
							SEG_OXX = DT_7seg[Z_NUM_C];
							SEG_XOX = DT_7seg[Z_NUM_P];
						}
					}
					else							//	ï¿½Ïºï¿½ï¿½ï¿½
					{
						SEG_OXX = DT_7seg[Z_NUM_J];
						SEG_XOX = DT_7seg[Z_NUM_P];
					}
				}
			}
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_BOOT:							//		ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
//			temp = (U8)((Z_TimerBootDisplay - gu16_TimerBootDisplay));
//			if (temp <= 50)
//			{
//
//			}
//			else if (temp <= 100)
//			{
//				SEG_OXX = DT_7seg[Z_NUM_8];
//			}
//			else if (temp <= 150)
//			{
//				SEG_OXX = DT_7seg[Z_NUM_8];
//				SEG_XOX = DT_7seg[Z_NUM_8];
//			}
//			else
//			{
//				SEG_OXX = DT_7seg[Z_NUM_8];
//				SEG_XOX = DT_7seg[Z_NUM_8];
//				SEG_XXO = DT_7seg[Z_NUM_8];
//			}
//			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;

			SEG_OXX = DT_7seg[Z_NUM_8];
			SEG_XOX = DT_7seg[Z_NUM_8];
			SEG_XXO = DT_7seg[Z_NUM_8];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			break;
		case SEG_EFF:								//	ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
			if ((gu8_WaterSelect == HOT_WATER) && (gu8_HotStep >= Z_HotStep_20) && (gu8_HotStep < Z_HotStep_35) && (gu8_HotStep != Z_HotStep_02))		//	ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿??????? ï¿½ï¿½ï¿½Ã·ï¿½ Ç¥ï¿½ï¿½
			{
				if (gu16_HotEffStart_DeltaT != 0)
				{
					if ((gu16_HotEffStart_Standard >= gu16_HotEffStart_First) && (gi16_HeaterSensor.DEGREE < gi16_EffStartTargetTemp ))
					{
						if(gi16_HeaterSensor.DEGREE >= gu16_HotEff_HeaterSensor_BakUp )			/*** ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Âµï¿½ï¿½ï¿½ ï¿½ï¿½ï¿??????? ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿??????? ï¿½Ê°ï¿½ ï¿½Äµï¿½Ã³ï¿½ï¿½ ï¿½â··ï¿½Ì°ï¿½ ï¿½ï¿½ï¿½ï¿½Ï´ï¿??????? ï¿½ï¿½ï¿??????? Ç¥ï¿½ï¿½ Display % Ç¥ï¿½Ã°ï¿½  40% > 30% > 40% > 50% ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ***/
						{																		/*** ï¿½ï¿½ï¿???????ï¿½ï¿½ Ç¥ï¿½ÃµÇ´ï¿½ ï¿½ï¿½ï¿??????? ï¿½ß»ï¿½/ ï¿½Ì¿ï¿½ ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½Âµï¿½ï¿½ï¿½ ï¿½ï¿½ï¿??????? ï¿½ï¿½ï¿½ï¿½ï¿??????? ï¿½Âµï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿??????? ï¿½Ïµï¿½ï¿½ï¿½ ï¿½Ï¿ï¿½ ï¿½ï¿½ï¿??????? ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½. 	  ***/
							gu32_Display_PreHeat_Percent = (U32)(((U32)(gu16_HotEffStart_DeltaT - (gu16_HotEffStart_Standard - gi16_HeaterSensor.DEGREE)) * 100) / (gu16_HotEffStart_DeltaT));
							gu16_HotEff_HeaterSensor_BakUp = gi16_HeaterSensor.DEGREE;
						}
						else
						{
							gu32_Display_PreHeat_Percent = (U32)(((U32)(gu16_HotEffStart_DeltaT - (gu16_HotEffStart_Standard - gu16_HotEff_HeaterSensor_BakUp)) * 100) / (gu16_HotEffStart_DeltaT));
						}
					}

					if (gu32_Display_PreHeat_Percent >= 98)
					{
						SEG_OXX = DT_7seg[Z_NUM_1];
						SEG_XOX = DT_7seg[Z_NUM_0];
						SEG_XXO = DT_7seg[Z_NUM_0];
					}
					else if (gu32_Display_PreHeat_Percent >= 10)
					{
						SEG_XOX = DT_7seg[(gu32_Display_PreHeat_Percent / 10) % 10];
						SEG_XXO = DT_7seg[Z_NUM_0];
					}
					else{
						SEG_XXO = DT_7seg[Z_NUM_0];
					}

					DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_ON;					

#ifndef _HOT_TEMP_4STEP_
					if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80)
					{
						SEG_XOX = DT_7seg[Z_NUM_8];
						SEG_XXO = DT_7seg[Z_NUM_5];
					}
					else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR70_JP70)
					{
						SEG_XOX = DT_7seg[Z_NUM_7];
						SEG_XXO = DT_7seg[Z_NUM_0];
					}
					else
					{
						SEG_XOX = DT_7seg[Z_NUM_4];
						SEG_XXO = DT_7seg[Z_NUM_5];
					}
#else

#endif
				}
				else								//	ï¿½Â¼ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½, ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½ Âªï¿½ï¿½ ï¿½ï¿½ï¿??????? 0mlï¿½ï¿½ Ç¥ï¿½ï¿½
				{
					SEG_XXO = DT_7seg[Z_NUM_0];
					DisplayControl_Data[Z_LED_mL].Display_CMD = LED_DIMM;
					#ifndef _FRONT_LED_UP_
#else
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
#endif
				}
			}
			else if (gu16_CupSize == CUPSIZE_CONTINUE)	//	 ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ (Rotation Ç¥ï¿½ï¿½)
			{
#ifdef _HOT_TEST_
				if (gu8_WaterSelect == HOT_WATER)
				{
					if (gu8_TimerSEG_TH_Limit == 0)		//
					{
						gu8_TimerSEG_TH_Limit = Z_TimerSEG_TH_Limit;
						if (F_HotWater_DegreeDisplay_TH == CLEAR)
						{
							mi16_Seg_buf_forSEGTH =	gi16_HotOutSensor.DEGREE;	//	[1/10ï¿½ï¿½]
						}
						else
						{
							mi16_Seg_buf_forSEGTH =	gi16_HeaterSensor.DEGREE;	//	[1/10ï¿½ï¿½]
						}
					}

					if (mi16_Seg_buf_forSEGTH < 0)
					{
						SEG_OXX = DT_7seg[Z_NUM_BAR];
					}
					else if (mi16_Seg_buf_forSEGTH >= 100)
					{
//						SEG_OXX = DT_7seg[(mi16_Seg_buf_forSEGTH / 100) % 10];
						SEG_OXX = DT_7seg[mi16_Seg_buf_forSEGTH / 100];
					}

					if (abs(mi16_Seg_buf_forSEGTH) >= 10)
					{
						SEG_XOX = DT_7seg[(abs(mi16_Seg_buf_forSEGTH) / 10) % 10];
					}
					SEG_XXO = DT_7seg[abs(mi16_Seg_buf_forSEGTH) % 10];
#ifndef _FRONT_LED_UP_
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
#else
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
#endif
				}
#else
				if (gu8_TimerContSeg == 0)
				{
					gu8_TimerContSeg = Z_TimerContSeg;
					gu8_CounterContSeg++;
					if (gu8_CounterContSeg >= 20)
					{
						gu8_CounterContSeg = 0;
					}
				}
				SEG_OXX = DT_Cont_OXX[gu8_CounterContSeg];
				SEG_XOX = DT_Cont_XOX[gu8_CounterContSeg];
				SEG_XXO = DT_Cont_XXO[gu8_CounterContSeg];
#endif
			}
			else									//		ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½
			{
#ifdef _HOT_TEST_
				if (gu8_WaterSelect == HOT_WATER)
				{
					if (gu8_TimerSEG_TH_Limit == 0)		//
					{
						gu8_TimerSEG_TH_Limit = Z_TimerSEG_TH_Limit;
						if (F_HotWater_DegreeDisplay_TH == CLEAR)
						{
							mi16_Seg_buf_forSEGTH =	gi16_HotOutSensor.DEGREE;	//	[1/10ï¿½ï¿½]
						}
						else
						{
							mi16_Seg_buf_forSEGTH =	gi16_HeaterSensor.DEGREE;	//	[1/10ï¿½ï¿½]
						}
					}

					if (mi16_Seg_buf_forSEGTH < 0)
					{
						SEG_OXX = DT_7seg[Z_NUM_BAR];
					}
					else if (mi16_Seg_buf_forSEGTH >= 100)
					{
//						SEG_OXX = DT_7seg[(mi16_Seg_buf_forSEGTH / 100) % 10];
						SEG_OXX = DT_7seg[mi16_Seg_buf_forSEGTH / 100];
					}

					if (abs(mi16_Seg_buf_forSEGTH) >= 10)
					{
						SEG_XOX = DT_7seg[(abs(mi16_Seg_buf_forSEGTH) / 10) % 10];
					}
					SEG_XXO = DT_7seg[abs(mi16_Seg_buf_forSEGTH) % 10];
#ifndef _FRONT_LED_UP_
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
#else
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
#endif
				}
				else
				{
#else
				if ((gu8_WaterSelect == HOT_WATER) && (F_HotWater_DegreeDisplay == SET))
				{
					if (gu8_TimerSEG_TH_Limit == 0)		//
					{
						gu8_TimerSEG_TH_Limit = Z_TimerSEG_TH_Limit;
						if (F_HotWater_DegreeDisplay_TH == CLEAR)
						{
							mi16_Seg_buf_forSEGTH =	gi16_HotOutSensor.DEGREE/10;	//	[1/1ï¿½ï¿½]
						}
						else
						{
							mi16_Seg_buf_forSEGTH =	gi16_HeaterSensor.DEGREE/10;	//	[1/1ï¿½ï¿½]
						}
					}

					if (mi16_Seg_buf_forSEGTH < 0)
					{
						SEG_OXX = DT_7seg[Z_NUM_BAR];
					}
					else if (mi16_Seg_buf_forSEGTH >= 100)
					{
						SEG_OXX = DT_7seg[(mi16_Seg_buf_forSEGTH / 100) % 10];
					}

					if (abs(mi16_Seg_buf_forSEGTH) >= 10)
					{
						SEG_XOX = DT_7seg[(abs(mi16_Seg_buf_forSEGTH) / 10) % 10];
					}
					SEG_XXO = DT_7seg[abs(mi16_Seg_buf_forSEGTH) % 10];
#ifndef _FRONT_LED_UP_
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
#else
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
#endif
				}
				else
				{
#endif
					mu16_Cup_buf = gu16_Effluent_CupLitter_forSegDisplay;

					if (gu16_Effluent_Hz > 5)			//	?ï¿½ï¿½ï¿?? ì£¼íŒŒ?ï¿½ï¿½ï¿?? 5Hz ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½ ê³„ì‚°?ï¿½ï¿½ Cup ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ (?ï¿½ï¿½?ï¿½ï¿½ï¿?? else)
					{
						if (gu16_Effluent_Hz_forSegDisplay >= gu16_Effluent_Hz)
						{							
							mu16_Seg_buf = (U16)((mu16_Cup_buf*(((U32)((U32)gu16_Effluent_Hz_forSegDisplay-gu16_Effluent_Hz) * 100) / gu16_Effluent_Hz_forSegDisplay))/100);	//	?ï¿½ï¿½?ï¿½ï¿½ ê³„ì‚° ê³µì‹
						}
					}
					else
					{
						mu16_Seg_buf = mu16_Cup_buf;
					}
					gu16_Effluent_Amount_SegDisplay = mu16_Seg_buf;	//	?ï¿½ï¿½ê·¸ë¨¼?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ ï¿?? ?ï¿½ï¿½?ï¿½ï¿½

								
					//	ï¿½Ö´ë°ª 990ï¿½ï¿½ï¿½ï¿½
					if(mu16_Seg_buf >= 1000)	//	ìµœï¿½?? ?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½
					{
						SEG_XOX = DT_7seg[Z_NUM_1];
						SEG_XXO = DT_7seg[Z_NUM_L];
					}
					else
					{					
						if (mu16_Seg_buf >= 100)
						{
							SEG_OXX = DT_7seg[(mu16_Seg_buf/100)%10];
						}
						if (mu16_Seg_buf >= 10)
						{
							SEG_XOX = DT_7seg[(mu16_Seg_buf/10)%10];
						}
						SEG_XXO = DT_7seg[Z_NUM_0];
						DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
					}
#ifndef _FRONT_LED_UP_
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_DIMM;
#else
				
#endif
#ifndef _HOT_TEST_
				}
#endif
#ifdef _HOT_TEST_
				}
#endif
			}
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_SOUND:
			SEG_OXX = DT_7seg[Z_NUM_BAR];
			SEG_XOX = DT_7seg[gu8_Sound_Type];
			SEG_XXO = DT_7seg[Z_NUM_BAR];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_MOVING:
			if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_AUTO_LEVEL)
			{
				SEG_OXX = DT_7seg[Z_NUM_A];
				SEG_XOX = DT_7seg[Z_NUM_U];
				SEG_XXO = DT_7seg[Z_NUM_t];
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_1_LEVEL)
			{
				SEG_XXO = DT_7seg[Z_NUM_1];
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_2_LEVEL)
			{
				SEG_XXO = DT_7seg[Z_NUM_2];
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_3_LEVEL)
			{
				SEG_XXO = DT_7seg[Z_NUM_3];
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_4_LEVEL)
			{
				SEG_XXO = DT_7seg[Z_NUM_4];
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_5_LEVEL)
			{
				SEG_XXO = DT_7seg[Z_NUM_5];
			}	
			else
			{
				
			}											
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;			
			break;
		case SEG_STE:
			SEG_OXX = DT_7seg[Z_NUM_S];
			SEG_XOX = DT_7seg[Z_NUM_t];
			SEG_XXO = DT_7seg[Z_NUM_E];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_SMARTCHECK:
			if(gu8_SmartCheck_Percent == 0)
			{
				SEG_XXO = DT_7seg[0];
			}
			else if(gu8_SmartCheck_Percent == 100)
			{
				SEG_OXX = DT_7seg[Z_NUM_1];
				SEG_XOX = DT_7seg[Z_NUM_0];
				SEG_XXO = DT_7seg[Z_NUM_0];
			}
			else
			{
				SEG_XOX = DT_7seg[gu8_SmartCheck_Percent/10];
				SEG_XXO = DT_7seg[gu8_SmartCheck_Percent%10];
			}
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_WIFI_CON:
			if(gu8_Wifi_Pairing_State == WIFI_PAIRING_STEP1_25_PERCENT)
            {
				SEG_XOX = DT_7seg[Z_NUM_2];
				SEG_XXO = DT_7seg[Z_NUM_5];
            }
            else if(gu8_Wifi_Pairing_State == WIFI_PAIRING_STEP2_50_PERCENT)
            {
				SEG_XOX = DT_7seg[Z_NUM_5];
				SEG_XXO = DT_7seg[Z_NUM_0];
            }
            else if(gu8_Wifi_Pairing_State == WIFI_PAIRING_STEP3_75_PERCENT)
            {
				SEG_XOX = DT_7seg[Z_NUM_7];
				SEG_XXO = DT_7seg[Z_NUM_5];
            }
            else if(gu8_Wifi_Pairing_State == WIFI_PAIRING_STEP_FINISH)
            {
				SEG_OXX = DT_7seg[Z_NUM_1];
				SEG_XOX = DT_7seg[Z_NUM_0];
				SEG_XXO = DT_7seg[Z_NUM_0];
            }
            else if(gu8_Wifi_Pairing_State == WIFI_PAIRING_STEP_ERROR)
            {
            	gu8_WifiError = GetWifiStatusValue(WIFI_STATUS_ERROR);

				SEG_OXX = DT_7seg[Z_NUM_A];
				SEG_XOX = DT_7seg[Z_NUM_P];
				SEG_XXO = DT_7seg[gu8_WifiError % 10];
            }
            else
            {

            }
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_MYSET:
			if (gu16_CupSize_My >= 100)
			{
				SEG_OXX = DT_7seg[(gu16_CupSize_My/100)%10];
			}
			if (gu16_CupSize_My >= 10)
			{
				SEG_XOX = DT_7seg[(gu16_CupSize_My/10)%10];
			}
			SEG_XXO = DT_7seg[Z_NUM_0];
#ifndef _FRONT_LED_UP_
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_DIMM;
#else
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
#endif
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_ML:								//		ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
#ifdef _FOR_REPEAT_EFF_ENDURANCE_TEST_
			if (gu16_TimerMoveDisplay == 0)
			{
				gu16_TimerMoveDisplay = Z_TimerMoveDisplay_forTest;
			}

			if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*13))
			{
				SEG_XXO = DT_7seg[Z_NUM_t];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*12))
			{
				SEG_XOX = DT_7seg[Z_NUM_t];
				SEG_XXO = DT_7seg[Z_NUM_E];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*11))
			{
				SEG_OXX = DT_7seg[Z_NUM_t];
				SEG_XOX = DT_7seg[Z_NUM_E];
				SEG_XXO = DT_7seg[Z_NUM_S];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*10))
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_S];
				SEG_XXO = DT_7seg[Z_NUM_t];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*9))
			{
				SEG_OXX = DT_7seg[Z_NUM_S];
				SEG_XOX = DT_7seg[Z_NUM_t];
				SEG_XXO = DT_7seg[Z_NUM_BAR];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*8))
			{
				SEG_OXX = DT_7seg[Z_NUM_t];
				SEG_XOX = DT_7seg[Z_NUM_BAR];
				SEG_XXO = DT_7seg[Z_NUM_r];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*7))
			{
				SEG_OXX = DT_7seg[Z_NUM_BAR];
				SEG_XOX = DT_7seg[Z_NUM_r];
				SEG_XXO = DT_7seg[Z_NUM_E];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*6))
			{
				SEG_OXX = DT_7seg[Z_NUM_r];
				SEG_XOX = DT_7seg[Z_NUM_E];
				SEG_XXO = DT_7seg[Z_NUM_P];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*5))
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_P];
				SEG_XXO = DT_7seg[Z_NUM_E];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*4))
			{
				SEG_OXX = DT_7seg[Z_NUM_P];
				SEG_XOX = DT_7seg[Z_NUM_E];
				SEG_XXO = DT_7seg[Z_NUM_A];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*3))
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_A];
				SEG_XXO = DT_7seg[Z_NUM_t];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*2))
			{
				SEG_OXX = DT_7seg[Z_NUM_A];
				SEG_XOX = DT_7seg[Z_NUM_t];
			}
			else if (gu16_TimerMoveDisplay > ((Z_TimerMoveDisplay_forTest/14)*1))
			{
				SEG_OXX = DT_7seg[Z_NUM_t];
			}
			else
			{

			}
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			return;
#endif
#ifdef _COLD_TEST_DEGREE_DISPLAY_
			if (gu8_Timer_TEM_Volt_Display != 0)
			{
				SEG_XOX = DT_7seg[gu8_PSM_TEM_Volt / 10];
				SEG_XXO = DT_7seg[gu8_PSM_TEM_Volt % 10];
			}
			else
			{
				if (gu8_Timer_SEG_TH == 0)				//			THï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Å¸ï¿½Ì¸ï¿½
				{
					gu8_Timer_SEG_TH = Z_Timer_SEG_TH;
					if (gu8_Counter_SEG_TH == 2)		//			THï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ä«ï¿½ï¿½ï¿½Í¿ï¿½ ï¿½ï¿½ï¿½ï¿½
					{
						gu8_Counter_SEG_TH = 0;
					}
					else
					{
						gu8_Counter_SEG_TH = 2;
					}
				}

				if (gu8_Timer_SEG_TH >= 30)				//			4ï¿½ï¿½ ï¿½ï¿½ 1ï¿½Ê´ï¿½ THï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
				{
					switch (gu8_Counter_SEG_TH)
					{
						case 0:
							SEG_OXX = DT_7seg[Z_NUM_C];
							SEG_XOX = DT_7seg[Z_NUM_o];
							SEG_XXO = DT_7seg[Z_NUM_L];
							break;
						case 2:
							SEG_OXX = DT_7seg[Z_NUM_O];
							SEG_XOX = DT_7seg[Z_NUM_u];
							SEG_XXO = DT_7seg[Z_NUM_t];
							break;
						default:
							break;
					}
				}
				else								//			4ï¿½ï¿½ ï¿½ï¿½ 3ï¿½Ê´ï¿½ THï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
				{
					mu8_OPENSHORT_Error = TH_Open_Short_Check(TH_DataArray[gu8_Counter_SEG_TH]->TH_ADC_AVERAGE);
					if (mu8_OPENSHORT_Error == 0)			//	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿???????
					{
						if (gu8_TimerSEG_TH_Limit == 0)		//
						{
							gu8_TimerSEG_TH_Limit = Z_TimerSEG_TH_Limit;
							mi16_Seg_buf_forSEGTH =	TH_DataArray[gu8_Counter_SEG_TH]->DEGREE;
						}

						if (mi16_Seg_buf_forSEGTH < 0)
						{
							SEG_OXX = DT_7seg[Z_NUM_BAR];
						}
						else if (mi16_Seg_buf_forSEGTH >= 100)
						{
							SEG_OXX = DT_7seg[(mi16_Seg_buf_forSEGTH / 100) % 10];
						}

						if (abs(mi16_Seg_buf_forSEGTH) >= 10)
						{
							SEG_XOX = DT_7seg[abs(mi16_Seg_buf_forSEGTH) / 10 % 10];
						}
						SEG_XXO = DT_7seg[abs(mi16_Seg_buf_forSEGTH) % 10];
#ifndef _FRONT_LED_UP_
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
#else
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
#endif
					}
					else									//	OPEN or SHORT
					{
						SEG_OXX = DT_7seg[Z_NUM_BAR];
						SEG_XOX = DT_7seg[Z_NUM_BAR];
						SEG_XXO = DT_7seg[Z_NUM_BAR];
					}
				}
			}
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
#else
			if (gu8_TimerOverHeatDisplay != 0)
			{
				SEG_OXX = DT_7seg[Z_NUM_H];
				SEG_XOX = DT_7seg[Z_NUM_o];
				SEG_XXO = DT_7seg[Z_NUM_t];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
#ifdef _HOT_TEST_
			else if (gu8_TimerHotTest_DegreeDisplay != 0)
			{
				if (gu16_HotOut_Degree_Ave >= 100)
				{
//					SEG_OXX = DT_7seg[(gu16_HotOut_Degree_Ave / 100) % 10];
					SEG_OXX = DT_7seg[(gu16_HotOut_Degree_Ave / 100)];
				}
				if (gu16_HotOut_Degree_Ave >= 10)
				{
					SEG_XOX = DT_7seg[(gu16_HotOut_Degree_Ave / 10) % 10];
				}
				SEG_XXO = DT_7seg[gu16_HotOut_Degree_Ave % 10];
#ifndef _FRONT_LED_UP_
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
#else
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
#endif
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
#else
			else if (gu8_TimerWifiErrorDisplay != 0)
			{
				SEG_OXX = DT_7seg[Z_NUM_A];
				SEG_XOX = DT_7seg[Z_NUM_P];
				SEG_XXO = DT_7seg[gu8_WifiError % 10];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if ((gu8_WaterSelect == HOT_WATER) && (F_HotWater_DegreeDisplay == SET) && (gu8_TimerHotTest_DegreeDisplay != 0))	//	ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ ï¿½ï¿½Õ¿Âµï¿??????? Ç¥ï¿½ï¿½
			{
				if (gu16_HotOut_Degree_Ave >= 1000)
				{
					SEG_OXX = DT_7seg[(gu16_HotOut_Degree_Ave / 1000) % 10];
				}
				if (gu16_HotOut_Degree_Ave >= 100)
				{
					SEG_XOX = DT_7seg[(gu16_HotOut_Degree_Ave / 100) % 10];
				}
				SEG_XXO = DT_7seg[(gu16_HotOut_Degree_Ave / 10) % 10];
#ifndef _FRONT_LED_UP_
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
#else
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
#endif
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
#endif
			else if (gu8_TimerMySetFilker != 0)
			{
				if (gu16_CupSize_My >= 100)
				{
					SEG_OXX = DT_7seg[(gu16_CupSize_My / 100) % 10];
				}
				if (gu16_CupSize_My >= 10)
				{
					SEG_XOX = DT_7seg[(gu16_CupSize_My / 10) % 10];
				}
				SEG_XXO = DT_7seg[gu16_CupSize_My % 10];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F;
			}
			else if (gu8_TimerEffluentAmount_Display != 0)	//		Å¸ï¿½Ì¸ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½
			{
				if(gu16_Effluent_Amount_SegDisplay >= 1000)
				{
					SEG_XOX = DT_7seg[Z_NUM_1];
					SEG_XXO = DT_7seg[Z_NUM_L];	//
				}			
				else if (gu16_Effluent_Amount_SegDisplay >= 100)
				{
					SEG_OXX = DT_7seg[(gu16_Effluent_Amount_SegDisplay/100)%10];	//
					SEG_XOX = DT_7seg[(gu16_Effluent_Amount_SegDisplay/10)%10];
					SEG_XXO = DT_7seg[Z_NUM_0];
					DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;					
				}
				else if (gu16_Effluent_Amount_SegDisplay >= 10)
				{
					SEG_XOX = DT_7seg[(gu16_Effluent_Amount_SegDisplay/10)%10];
					SEG_XXO = DT_7seg[Z_NUM_0];
					DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
				}				
				else
				{
					
				}
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else
			{
				if ((gu8_WaterSelect == HOT_WATER) && (F_HotDegreeDisplay == SET))
				{
					if (F_FirstHotEffluent == SET)
					{
#ifndef _HOT_TEMP_4STEP_
						if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80)
						{
							SEG_XOX = DT_7seg[Z_NUM_8];
							SEG_XXO = DT_7seg[Z_NUM_5];
						}
						else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR70_JP70)
						{
							SEG_XOX = DT_7seg[Z_NUM_7];
							SEG_XXO = DT_7seg[Z_NUM_0];
						}
						else
						{
							SEG_XOX = DT_7seg[Z_NUM_4];
							SEG_XXO = DT_7seg[Z_NUM_5];
						}
#else
						if (gu8_ModelType_forNational == MODEL_KOREA)
						{
							if (gu8_HotTempSetup == HOT_TEMP_SETUP_MY_HOT_TEMP)
							{
								if(gu8_My_HotTemp == 1)
								{
									SEG_XOX = DT_7seg[Z_NUM_4];
									SEG_XXO = DT_7seg[Z_NUM_5];
								}
								else if(gu8_My_HotTemp == 2)
								{
									SEG_XOX = DT_7seg[Z_NUM_5];
									SEG_XXO = DT_7seg[Z_NUM_0];
								}
								else if(gu8_My_HotTemp == 3)
								{
									SEG_XOX = DT_7seg[Z_NUM_5];
									SEG_XXO = DT_7seg[Z_NUM_5];
								}
								else if(gu8_My_HotTemp == 4)
								{
									SEG_XOX = DT_7seg[Z_NUM_6];
									SEG_XXO = DT_7seg[Z_NUM_0];
								}
								else if(gu8_My_HotTemp == 5)
								{
									SEG_XOX = DT_7seg[Z_NUM_6];
									SEG_XXO = DT_7seg[Z_NUM_5];
								}
								else if(gu8_My_HotTemp == 6)
								{
									SEG_XOX = DT_7seg[Z_NUM_7];
									SEG_XXO = DT_7seg[Z_NUM_0];
								}
								else if(gu8_My_HotTemp == 7)
								{
									SEG_XOX = DT_7seg[Z_NUM_7];
									SEG_XXO = DT_7seg[Z_NUM_5];
								}
								else if(gu8_My_HotTemp == 8)
								{
									SEG_XOX = DT_7seg[Z_NUM_8];
									SEG_XXO = DT_7seg[Z_NUM_0];
								}
								else if(gu8_My_HotTemp == 9)
								{
									SEG_XOX = DT_7seg[Z_NUM_8];
									SEG_XXO = DT_7seg[Z_NUM_5];
								}
								else if(gu8_My_HotTemp == 10)
								{
									SEG_XOX = DT_7seg[Z_NUM_9];
									SEG_XXO = DT_7seg[Z_NUM_0];
								}
								else if(gu8_My_HotTemp == 11)
								{
									SEG_XOX = DT_7seg[Z_NUM_9];
									SEG_XXO = DT_7seg[Z_NUM_0];
								}
								else if(gu8_My_HotTemp == 12)
								{
									SEG_XOX = DT_7seg[Z_NUM_9];
									SEG_XXO = DT_7seg[Z_NUM_5];
								}								
								else if(gu8_My_HotTemp == 13)
								{
									SEG_OXX = DT_7seg[Z_NUM_1];
									SEG_XOX = DT_7seg[Z_NUM_0];
									SEG_XXO = DT_7seg[Z_NUM_0];									
								}		
								else
								{
									//	ï¿½ï¿½ï¿½ï¿½Ã³ï¿½ï¿½ï¿½ï¿½...ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Úµå¿¡ï¿½ï¿½..
								}																																																																																						
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR100_JP90)
							{
								SEG_OXX = DT_7seg[Z_NUM_1];
								SEG_XOX = DT_7seg[Z_NUM_0];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__95)
							{
								SEG_XOX = DT_7seg[Z_NUM_9];
								SEG_XXO = DT_7seg[Z_NUM_5];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__90)
							{
								SEG_XOX = DT_7seg[Z_NUM_9];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80)
							{
								SEG_XOX = DT_7seg[Z_NUM_8];
								SEG_XXO = DT_7seg[Z_NUM_5];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__80)
							{
								SEG_XOX = DT_7seg[Z_NUM_8];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__75)
							{
								SEG_XOX = DT_7seg[Z_NUM_7];
								SEG_XXO = DT_7seg[Z_NUM_5];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR70_JP70)
							{
								SEG_XOX = DT_7seg[Z_NUM_7];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__65)
							{
								SEG_XOX = DT_7seg[Z_NUM_6];
								SEG_XXO = DT_7seg[Z_NUM_5];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__60)
							{
								SEG_XOX = DT_7seg[Z_NUM_6];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__55)
							{
								SEG_XOX = DT_7seg[Z_NUM_5];
								SEG_XXO = DT_7seg[Z_NUM_5];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__50)
							{
								SEG_XOX = DT_7seg[Z_NUM_5];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else
							{
								SEG_XOX = DT_7seg[Z_NUM_4];
								SEG_XXO = DT_7seg[Z_NUM_5];
							}
						}
						else							//	ï¿½Ïºï¿½ï¿½ï¿½
						{
							if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR100_JP90)
							{
								SEG_XOX = DT_7seg[Z_NUM_9];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else if (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80)
							{
								SEG_XOX = DT_7seg[Z_NUM_8];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else
							{
								SEG_XOX = DT_7seg[Z_NUM_7];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
						}
					}
					else
					{
						SEG_XOX = DT_7seg[Z_NUM_BAR];
						SEG_XXO = DT_7seg[Z_NUM_BAR];
					}
#endif
					DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
#ifndef _FRONT_LED_UP_
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
#else
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
#endif
				}
				else
				{
					if (gu8_TimerSleepMode != 0)
					{
						#if 0
						if (gu16_CupSize == CUPSIZE_HALFCUP)
						{
							SEG_OXX = DT_7seg[Z_NUM_1];
							SEG_XOX = DT_7seg[Z_NUM_2];
							SEG_XXO = DT_7seg[Z_NUM_0];
#ifndef _FRONT_LED_UP_
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_DIMM;
#else
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
#endif
						}
						else if (gu16_CupSize == CUPSIZE_1CUP)
						{
							if (gu8_ModelType_forNational == MODEL_KOREA)
							{
								SEG_OXX = DT_7seg[Z_NUM_2];
								SEG_XOX = DT_7seg[Z_NUM_5];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else
							{
								SEG_OXX = DT_7seg[Z_NUM_1];
								SEG_XOX = DT_7seg[Z_NUM_8];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
#ifndef _FRONT_LED_UP_
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_DIMM;
#else
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
#endif
						}
						else if (gu16_CupSize == CUPSIZE_2CUP)
						{
							if (gu8_ModelType_forNational == MODEL_KOREA)
							{
								SEG_OXX = DT_7seg[Z_NUM_5];
								SEG_XOX = DT_7seg[Z_NUM_0];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
							else
							{
								SEG_OXX = DT_7seg[Z_NUM_3];
								SEG_XOX = DT_7seg[Z_NUM_0];
								SEG_XXO = DT_7seg[Z_NUM_0];
							}
#ifndef _FRONT_LED_UP_
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_DIMM;
#else
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
#endif
						}
						else if (gu16_CupSize == CUPSIZE_ONE_BOTTLE)
						{
							SEG_XOX = DT_7seg[Z_NUM_1];
							SEG_XXO = DT_7seg[Z_NUM_L];
						}
						else if (gu16_CupSize == CUPSIZE_CONTINUE)    //			ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
						{
							SEG_OXX = (U8)(DT_7seg[Z_NUM_SEG_a] | DT_7seg[Z_NUM_SEG_d] | DT_7seg[Z_NUM_SEG_e] | DT_7seg[Z_NUM_SEG_f]);
							SEG_XOX = (U8)(DT_7seg[Z_NUM_SEG_a] | DT_7seg[Z_NUM_SEG_d]);
							SEG_XXO = (U8)(DT_7seg[Z_NUM_SEG_a] | DT_7seg[Z_NUM_SEG_b] | DT_7seg[Z_NUM_SEG_c] | DT_7seg[Z_NUM_SEG_d]);
						}
						else if (gu16_CupSize == CUPSIZE_MY)
						{
							if (gu16_CupSize_My >= 100)
							{
								SEG_OXX = DT_7seg[(gu16_CupSize_My / 100) % 10];
							}
							if (gu16_CupSize_My >= 10)
							{
								SEG_XOX = DT_7seg[(gu16_CupSize_My / 10) % 10];
							}
							SEG_XXO = DT_7seg[gu16_CupSize_My % 10];
#ifndef _FRONT_LED_UP_
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_DIMM;
#else
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
#endif
						}
						else
						{

						}
#ifdef _AFTER_LPP_IMDCHANGE_
						if (gu8_TimerDefaultCupSize_Set_LEDFlic != 0)
						{
							DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F;
							DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
						}
						else
						{
#endif
							DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
#ifdef _AFTER_LPP_IMDCHANGE_
						}
#endif					
						#endif

						if (gu16_CupSize == CUPSIZE_ONE_BOTTLE)
						{
							SEG_OXX = LED_OFF;
							SEG_XOX = DT_7seg[Z_NUM_1];
							SEG_XXO = DT_7seg[Z_NUM_L];
						}
						else if ((gu16_CupSize == CUPSIZE_CONTINUE)    //			ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
						&& (gu8_CupIndex == CUPSIZE_FIVE))			//	ÄÅ»çÀÌÁî 170ml¶û ¿¬¼ÓÀÌ¶û °°±â ¶§¹®¿¡ index Á¶°Ç°É¾îÁà¾ßÇÔ(¿¬¼ÓÀº ¹«Á¶°Ç 4¹øÂ°ÀÓ)
						{
							SEG_OXX = (U8)(DT_7seg[Z_NUM_SEG_a] | DT_7seg[Z_NUM_SEG_d] | DT_7seg[Z_NUM_SEG_e] | DT_7seg[Z_NUM_SEG_f]);
							SEG_XOX = (U8)(DT_7seg[Z_NUM_SEG_a] | DT_7seg[Z_NUM_SEG_d]);
							SEG_XXO = (U8)(DT_7seg[Z_NUM_SEG_a] | DT_7seg[Z_NUM_SEG_b] | DT_7seg[Z_NUM_SEG_c] | DT_7seg[Z_NUM_SEG_d]);
						}
						else if ((gu16_CupSize == CUPSIZE_CONTINUE)      //009
						&& (gu8_F_Continue_Effluent_Animation == SET))   //009
						{                                                //009
							// ¿¬¼ÓÃßÃâ ¾Ö´Ï¸ÞÀÌ¼Ç Ç¥½Ã (600-653ÁÙ°ú µ¿ÀÏÇÑ ·ÎÁ÷)	//009
							if (gu8_TimerContSeg == 0)					//@009
							{											//@009
								gu8_TimerContSeg = Z_TimerContSeg;		//@009
								gu8_CounterContSeg++;					//@009
								if (gu8_CounterContSeg >= 20)			//@009
								{										//@009
									gu8_CounterContSeg = 0;				//@009
								}										//@009
							}											//@009
							SEG_OXX = DT_Cont_OXX[gu8_CounterContSeg];	//@009
							SEG_XOX = DT_Cont_XOX[gu8_CounterContSeg];	//@009
							SEG_XXO = DT_Cont_XXO[gu8_CounterContSeg];	//@009
						}                                               //009
						else
						{
							if (gu16_CupSize >= 100)
							{
								SEG_OXX = DT_7seg[(gu16_CupSize / 100) % 10];
							}
							if (gu16_CupSize >= 10)
							{
								SEG_XOX = DT_7seg[(gu16_CupSize / 10) % 10];
							}
							SEG_XXO = DT_7seg[gu16_CupSize % 10];			
							DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;				
						}

						DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;						
					}
				}
			}
#endif
			break;
		case SEG_FL_FLIC:						//		ï¿½Ê±ï¿½ï¿½Ã·ï¿½ï¿½ï¿½ ï¿½Ê¿ï¿½ Ç¥ï¿½ï¿½
			SEG_XOX = DT_7seg[Z_NUM_F];
			SEG_XXO = DT_7seg[Z_NUM_L];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			break;
		case SEG_COLDTIME:							//		ï¿½Ã°ï¿½ï¿½Ã°ï¿½ï¿½ï¿½ï¿½ï¿½
//#ifdef _FOR_DEVELOP_
			if (gu16_Cooling_TargetDegree >= 10)							
			{                                                               
				SEG_XOX = DT_7seg[(gu16_Cooling_TargetDegree / 10) % 10];   
			}                                                               
			SEG_XXO = DT_7seg[gu16_Cooling_TargetDegree % 10];              
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;            

//			if ((gu16_ColdTimeData/60) >= 100)
//			{
//				SEG_OXX = DT_7seg[((gu16_ColdTimeData/60) / 100) % 10];
//			}
//			if ((gu16_ColdTimeData/60) >= 10)
//			{
//				SEG_XOX = DT_7seg[((gu16_ColdTimeData/60) / 10) % 10];
//			}
//			SEG_XXO = DT_7seg[(gu16_ColdTimeData/60) % 10];
//			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
//#endif
			break;
		case SEG_TH:								//		THï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½							
			if (gu8_TimerDisplayEcoMode != 0)                               
			{                                                               
				if (F_CoolingEcoMode_Disable == SET)                        
				{                                                           
					SEG_XOX = DT_7seg[Z_NUM_d];                             
					SEG_XXO = DT_7seg[Z_NUM_I];                             
				}                                                           
				else                                                        
				{                                                           
					SEG_XOX = DT_7seg[Z_NUM_E];                             
					SEG_XXO = DT_7seg[Z_NUM_n];                             
				}                                                           
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;    
			}                                                               
			else if (gu8_TimerDisplayCoolingChange != 0)                    
			{                                                               
				if (F_Cooling_Up == SET)                                    
				{                                                           
					SEG_XOX = DT_7seg[Z_NUM_U];                             
					SEG_XXO = DT_7seg[Z_NUM_P];                             
				}                                                           
				else                                                        
				{                                                           
					SEG_XOX = DT_7seg[Z_NUM_d];                             
					SEG_XXO = DT_7seg[Z_NUM_o];                             
				}                                                           
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;    
			}                                                               
			else if (gu8_TimerDisplayFanChange != 0)                        
			{                                                               
				if (F_FAN_NoiseClear == SET)                                
				{                                                           
					SEG_XOX = DT_7seg[Z_NUM_1];                             
					SEG_XXO = DT_7seg[Z_NUM_8];                             
				}                                                           
				else                                                        
				{                                                           
					SEG_XOX = DT_7seg[Z_NUM_2];                             
					SEG_XXO = DT_7seg[Z_NUM_1];                             
				}                                                           
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;    
			}                                                               
			else if(gu8_Timer_Display_Moving_Durability != 0)
			{
				if(gu8_F_Moving_Durability == SET)
				{
					SEG_XOX = DT_7seg[Z_NUM_O];                             
					SEG_XXO = DT_7seg[Z_NUM_n];
				}
				else
				{
					SEG_OXX = DT_7seg[Z_NUM_O];
					SEG_XOX = DT_7seg[Z_NUM_F];                             
					SEG_XXO = DT_7seg[Z_NUM_F];
				}
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;				
			}
			else if(gu8_Timer_Repeat_Eff_display != 0)
			{
				if(Mode_Repeat_Eff_Mode_forMP == 1)
				{
					SEG_XOX = DT_7seg[Z_NUM_1];                             
					SEG_XXO = DT_7seg[Z_NUM_1];
				}
				else if(Mode_Repeat_Eff_Mode_forMP == 2)
				{
					SEG_XOX = DT_7seg[Z_NUM_2];                             
					SEG_XXO = DT_7seg[Z_NUM_2];
				}
				else
				{
					SEG_XOX = DT_7seg[Z_NUM_0];                             
					SEG_XXO = DT_7seg[Z_NUM_0];
				}		
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;				
			}
			else                                                            
			{																
				if (gu8_Timer_SEG_TH == 0)				//			THï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Å¸ï¿½Ì¸ï¿½
				{
					gu8_Timer_SEG_TH = Z_Timer_SEG_TH;
					if (++gu8_Counter_SEG_TH >= 6)		//			THï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ä«ï¿½ï¿½ï¿½Í¿ï¿½ ï¿½ï¿½ï¿½ï¿½
					{
						gu8_Counter_SEG_TH = 0;
					}
				}

				if (gu8_Timer_SEG_TH >= 30)				//			4ï¿½ï¿½ ï¿½ï¿½ 1ï¿½Ê´ï¿½ THï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
				{
					switch (gu8_Counter_SEG_TH)
					{
						case 0:
							SEG_OXX = DT_7seg[Z_NUM_C];
							SEG_XOX = DT_7seg[Z_NUM_o];
							SEG_XXO = DT_7seg[Z_NUM_L];
							break;
						case 1:
							SEG_OXX = DT_7seg[Z_NUM_S];
							SEG_XOX = DT_7seg[Z_NUM_I];
							SEG_XXO = DT_7seg[Z_NUM_n];
							break;
						case 2:
							SEG_OXX = DT_7seg[Z_NUM_O];
							SEG_XOX = DT_7seg[Z_NUM_u];
							SEG_XXO = DT_7seg[Z_NUM_t];
							break;
						case 3:
							SEG_OXX = DT_7seg[Z_NUM_H];
							SEG_XOX = DT_7seg[Z_NUM_I];
							SEG_XXO = DT_7seg[Z_NUM_n];
							break;
						case 4:
							SEG_OXX = DT_7seg[Z_NUM_H];
							SEG_XOX = DT_7seg[Z_NUM_u];
							SEG_XXO = DT_7seg[Z_NUM_t];
							break;
						case 5:
							SEG_OXX = DT_7seg[Z_NUM_H];
							SEG_XOX = DT_7seg[Z_NUM_E];
							SEG_XXO = DT_7seg[Z_NUM_A];
							break;
						default:
							break;
					}
				}
				else									//			4ï¿½ï¿½ ï¿½ï¿½ 3ï¿½Ê´ï¿½ THï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
				{
					mu8_OPENSHORT_Error = TH_Open_Short_Check(TH_DataArray[gu8_Counter_SEG_TH]->TH_ADC_AVERAGE);
					if (mu8_OPENSHORT_Error == 0)			//	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿???????
					{
						if (gu8_TimerSEG_TH_Limit == 0)		//
						{
							gu8_TimerSEG_TH_Limit = Z_TimerSEG_TH_Limit;
							mi16_Seg_buf_forSEGTH = TH_DataArray[gu8_Counter_SEG_TH]->DEGREE;
						}

						if (mi16_Seg_buf_forSEGTH < 0)
						{
							SEG_OXX = DT_7seg[Z_NUM_BAR];
						}
						else if (mi16_Seg_buf_forSEGTH >= 100)
						{
							SEG_OXX = DT_7seg[(mi16_Seg_buf_forSEGTH / 100) % 10];
						}

						if (abs(mi16_Seg_buf_forSEGTH) >= 10)
						{
							SEG_XOX = DT_7seg[(abs(mi16_Seg_buf_forSEGTH) / 10) % 10];
						}
						SEG_XXO = DT_7seg[abs(mi16_Seg_buf_forSEGTH) % 10];
#ifndef _FRONT_LED_UP_
						DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
#else
						DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
#endif
					}
					else								//	OPEN or SHORT
					{
						SEG_OXX = DT_7seg[Z_NUM_BAR];
						SEG_XOX = DT_7seg[Z_NUM_BAR];
						SEG_XXO = DT_7seg[Z_NUM_BAR];
					}
				}
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			break;
		case SEG_MONITOR:							//		ï¿½ï¿½ï¿½ï¿½ È½ï¿½ï¿½ ï¿½ï¿½ ï¿½ï¿½ï¿½â·® Ç¥ï¿½ï¿½
			if (gu8_Timer_SEG_MONITOR == 0)			//			Å¸ï¿½Ì¸ï¿½
			{
				gu8_Timer_SEG_MONITOR = Z_Timer_SEG_MONITOR;
				if (++gu8_Counter_SEG_MONITOR >= 3)	//			ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ Ä«ï¿½ï¿½ï¿½Í¿ï¿½ ï¿½ï¿½ï¿½ï¿½
				{
					gu8_Counter_SEG_MONITOR = 0;
				}
			}

			if (gu8_Timer_SEG_MONITOR >= 60)		//			7ï¿½ï¿½ ï¿½ï¿½ 1ï¿½Ê´ï¿½ ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ Ç¥ï¿½ï¿½
			{
				switch (gu8_Counter_SEG_MONITOR)
				{
					case 1:
						SEG_OXX = DT_7seg[Z_NUM_C];
						SEG_XOX = DT_7seg[Z_NUM_o];
						SEG_XXO = DT_7seg[Z_NUM_L];
						break;
					case 2:
						SEG_OXX = DT_7seg[Z_NUM_H];
						SEG_XOX = DT_7seg[Z_NUM_o];
						SEG_XXO = DT_7seg[Z_NUM_t];
						break;
					case 0:
						SEG_OXX = DT_7seg[Z_NUM_A];
						SEG_XOX = DT_7seg[Z_NUM_b];
						SEG_XXO = DT_7seg[Z_NUM_E];
						break;
					default:
						break;
				}
			}
			else if (gu8_Timer_SEG_MONITOR >= 30)	//			7ï¿½ï¿½ ï¿½ï¿½ 3~6ï¿½Ê´ï¿½ ï¿½ï¿½ï¿½ï¿½ È½ï¿½ï¿½
			{
				if (gu16_Effluent_Count[gu8_Counter_SEG_MONITOR] >= 100)
				{
					SEG_OXX = DT_7seg[(gu16_Effluent_Count[gu8_Counter_SEG_MONITOR] / 100) % 10];
				}
				if (gu16_Effluent_Count[gu8_Counter_SEG_MONITOR] >= 10)
				{
					SEG_XOX = DT_7seg[(gu16_Effluent_Count[gu8_Counter_SEG_MONITOR] / 10) % 10];
				}
				SEG_XXO = DT_7seg[gu16_Effluent_Count[gu8_Counter_SEG_MONITOR] % 10];
			}
			else									//		0~2ï¿½Ê´ï¿½ ï¿½ï¿½ï¿½â·®. 1L ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
			{
				if (gu16_Effluent_Amount[gu8_Counter_SEG_MONITOR] >= 100)
				{
					SEG_OXX = DT_7seg[(gu16_Effluent_Amount[gu8_Counter_SEG_MONITOR] / 100) % 10];
				}
				if (gu16_Effluent_Amount[gu8_Counter_SEG_MONITOR] >= 10)
				{
					SEG_XOX = DT_7seg[(gu16_Effluent_Amount[gu8_Counter_SEG_MONITOR] / 10) % 10];
				}
				SEG_XXO = DT_7seg[gu16_Effluent_Amount[gu8_Counter_SEG_MONITOR] % 10];
			}
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_FRONTTEST:
			/*	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½	*/
//			if (PSM5 == CLEAR)
//			{
//				SEG_OXX = DT_7seg[Z_NUM_E];
//				SEG_XOX = DT_7seg[Z_NUM_4];
//				SEG_XXO = DT_7seg[Z_NUM_4];
//			}
//			else
//			{
//				SEG_OXX = DT_7seg[Z_NUM_C];
//				SEG_XOX = DT_7seg[Z_NUM_H];
//				SEG_XXO = DT_7seg[Z_NUM_P];
//			}
//			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
//			return;
			/*	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½	*/
			if (F_FrontTest_EffluentButton == SET)
			{
				if (gu16_Timer_FrontTest_Seg != 0)
				{
					if (Z_Timer_FrontTest_Seg >= gu16_Timer_FrontTest_Seg)
					{
						mu16_temp = Z_Timer_FrontTest_Seg - gu16_Timer_FrontTest_Seg;
					}
					mu16_FrontTest = mu16_temp / (Z_Timer_FrontTest_Seg/24);
					if (mu16_FrontTest < 8)
					{
						SEG_OXX = DT_FrontTest[mu16_FrontTest];
						SEG_XOX = DT_7seg[Z_NUM_8];
						SEG_XXO = DT_7seg[Z_NUM_8];
					}

					if ((mu16_FrontTest >= 8) && (mu16_FrontTest < 16))
					{
						SEG_XOX = DT_FrontTest[(mu16_FrontTest-8)];
						SEG_XXO = DT_7seg[Z_NUM_8];
					}

					if (mu16_FrontTest >= 16)
					{
						SEG_XXO = DT_FrontTest[(mu16_FrontTest-16)];
					}
				}
				else
				{
					if (gu8_ModelType_forCHP == MODEL_CHP)
					{
						SEG_OXX = DT_7seg[Z_NUM_C];
						SEG_XOX = DT_7seg[Z_NUM_H];
						SEG_XXO = DT_7seg[Z_NUM_P];
					}
					else
					{
						SEG_OXX = DT_7seg[Z_NUM_C];
						SEG_XOX = DT_7seg[Z_NUM_P];
					}
				}
			}
			else
			{
				SEG_OXX = DT_7seg[Z_NUM_8];
				SEG_XOX = DT_7seg[Z_NUM_8];
				SEG_XXO = DT_7seg[Z_NUM_8];
			}
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if (gu16_TimerFCT_Incomplete_Display != 0)	
				{											
					if (F_LineFrontTest_Amount_Complete == CLEAR)	
					{										
						SEG_OXX = DT_7seg[Z_NUM_b];       	
						SEG_XOX = DT_7seg[Z_NUM_t];         
						SEG_XXO = DT_7seg[Z_NUM_n];         
					}										
					else if (F_LineFrontTest_Hot_Complete == CLEAR)	
					{										
						if (gu8_ModelType_forCHP == MODEL_CHP)
						{									
							SEG_OXX = DT_7seg[Z_NUM_H];     
							SEG_XOX = DT_7seg[Z_NUM_o];     
							SEG_XXO = DT_7seg[Z_NUM_t];     
						}									
						else								
						{									
							SEG_OXX = DT_7seg[Z_NUM_b];     
							SEG_XOX = DT_7seg[Z_NUM_t];     
							SEG_XXO = DT_7seg[Z_NUM_n];     
						}									
					}										
					else if (F_LineFrontTest_Cold_Complete == CLEAR)	
					{										
						SEG_OXX = DT_7seg[Z_NUM_C];       	
						SEG_XOX = DT_7seg[Z_NUM_o];         
						SEG_XXO = DT_7seg[Z_NUM_L];         
					}										
					else if (F_LineFrontTest_Pure_Complete == CLEAR)	
					{										
						SEG_OXX = DT_7seg[Z_NUM_P];       	
						SEG_XOX = DT_7seg[Z_NUM_u];         
						SEG_XXO = DT_7seg[Z_NUM_r];         
					}										
					else if ((REED_SW_COVER_Ready == CLEAR) || (INPUT_REED_SW_COVER == CLEAR))	
					{							
						#if 0
						SEG_OXX = DT_7seg[Z_NUM_t];       	
						SEG_XOX = DT_7seg[Z_NUM_o];         
						SEG_XXO = DT_7seg[Z_NUM_P];         
						#endif
						SEG_OXX = DT_7seg[Z_NUM_F];       	
						SEG_XOX = DT_7seg[Z_NUM_C];         
						SEG_XXO = DT_7seg[Z_NUM_r]; 						
					}										
					else if ((REED_SW_WATERFLOW_Ready == CLEAR) || (INPUT_REED_SW_FAUCET == CLEAR))	
					{										
						SEG_OXX = DT_7seg[Z_NUM_F];       	
						SEG_XOX = DT_7seg[Z_NUM_U];        
						SEG_XXO = DT_7seg[Z_NUM_t];         
					}										
					else if ((REED_SW_FILTER_Ready == CLEAR) || (INPUT_REED_SW_FILTER == CLEAR))	
					{										
						SEG_OXX = DT_7seg[Z_NUM_F];       	
						SEG_XOX = DT_7seg[Z_NUM_I];         
						SEG_XXO = DT_7seg[Z_NUM_L];         
					}										
					else if ((F_WIFI_Pairing_forLineTest == CLEAR) && (gu16_TimerFCT_Incomplete_Display_forPASECO != 0))	
					{										
						SEG_OXX = DT_7seg[Z_NUM_I];       	
						SEG_XOX = DT_7seg[Z_NUM_F];         
						SEG_XXO = DT_7seg[Z_NUM_I];         
					}									
					else if ((gu16_Pure_FlowDecide_Hz_forLineAuto == 0)	|| (gu16_Hot_FlowDecide_Hz_forLineAuto == 0) || (gu16_Cold_FlowDecide_Hz_forLineAuto == 0))
					{										
						SEG_OXX = DT_7seg[Z_NUM_F];       	
						SEG_XOX = DT_7seg[Z_NUM_L];         
						SEG_XXO = DT_7seg[Z_NUM_o];         
					}									
					else if ((F_LineFrontTest_1stNos_VV_Complete == CLEAR) && (gu16_TimerFCT_Incomplete_Display_forPASECO != 0))	
					{										
						SEG_OXX = DT_7seg[Z_NUM_n];       	
						SEG_XOX = DT_7seg[Z_NUM_o];         
						SEG_XXO = DT_7seg[Z_NUM_S];         
					}
					else if(gu8_F_LineAuto_Faucet_DownReed == CLEAR)
					{
						SEG_OXX = DT_7seg[Z_NUM_F];       	
						SEG_XOX = DT_7seg[Z_NUM_d];         
						SEG_XXO = DT_7seg[Z_NUM_r]; 
					}		
					else if(gu8_F_LineAuto_Faucet_UpReed == CLEAR)
					{
						SEG_OXX = DT_7seg[Z_NUM_F];       	
						SEG_XOX = DT_7seg[Z_NUM_U];         
						SEG_XXO = DT_7seg[Z_NUM_r]; 					
					}
					else if(gu8_F_LineAuto_Faucet_MicroSW == CLEAR)
					{
						SEG_OXX = DT_7seg[Z_NUM_c];       	
						SEG_XOX = DT_7seg[Z_NUM_BAR];         
						SEG_XXO = DT_7seg[Z_NUM_t];
					}																		
					else									
					{                                       
                                                            
					}                                       
					DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;	  
					return;									
				}											
				else if (gu8_TimerFrontTest_1stNosDisplay != 0)	
				{											
					if (F_LineFrontTest_1stNos_VV == SET)   
					{                                       
						SEG_OXX = DT_7seg[Z_NUM_BAR];       
						SEG_XOX = DT_7seg[Z_NUM_C];         
						SEG_XXO = DT_7seg[Z_NUM_L];         
					}                                       
					else                                    
					{                                       
						SEG_OXX = DT_7seg[Z_NUM_BAR];       
						SEG_XOX = DT_7seg[Z_NUM_O];         
						SEG_XXO = DT_7seg[Z_NUM_P];         
					}                                       
				}                                           
				else if (F_LineFrontTest_Effluent_Oper == CLEAR)
				{
					SEG_OXX = DT_7seg[Z_NUM_8];
					SEG_XOX = DT_7seg[Z_NUM_8];
					SEG_XXO = DT_7seg[Z_NUM_8];
				}
				else
				{
//					mu16_Seg_buf = gu16_FlowDecide_Hz / 10;
					if (gu8_TimerLineTest_SegUpdate == 0)
					{
						gu8_TimerLineTest_SegUpdate = Z_TimerLineTest_SegUpdate;
						if (gu8_ModelType_forNational == MODEL_KOREA)
						{
							gu16_LineTest_Seg = gu16_FlowDecide_Hz / 10;
						}
						else						//	ï¿½Ïºï¿½ï¿½ï¿½
						{
							gu16_LineTest_Seg = gu16_FlowDecide_Hz / 10 / 2;	//	ï¿½Ïºï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ì¹Ç·ï¿½ ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ Hzï¿½ï¿½ ï¿½Ô·ÂµÇ¾ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½2
						}
					}

					if (gu16_LineTest_Seg > 999)
					{
						gu16_LineTest_Seg = 999;
					}

					if (gu16_LineTest_Seg >= 100)
					{
						SEG_OXX = DT_7seg[(gu16_LineTest_Seg / 100) % 10];
					}
					if (gu16_LineTest_Seg >= 10)
					{
						SEG_XOX = DT_7seg[(gu16_LineTest_Seg / 10) % 10];
					}
					SEG_XXO = DT_7seg[gu16_LineTest_Seg % 10];
				}
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else
			{
				//  ÀÚµ¿È­°Ë»ç¸ðµå ¿Ï·á ÈÄ, ÆÄ¿ì¼Â ÆÁ ¹Ì°¨Áö ½Ã ÀüÃ¼ Á¡¸ê / °¨Áö ½Ã ¼Òµî
				if(F_LineTest_Complete == SET)
				{
					if(INPUT_REED_SW_FAUCET == SET)	
					{
						
					}
					else
					{
						SEG_OXX = DT_7seg[Z_NUM_8];
						SEG_XOX = DT_7seg[Z_NUM_8];
						SEG_XXO = DT_7seg[Z_NUM_8];
						DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
					}
				}
				else
				{
					if (gu8_ModelType_forNational == MODEL_KOREA)
					{
						SEG_OXX = DT_7seg[Z_NUM_C];
						SEG_XOX = DT_7seg[Z_NUM_O];
						SEG_XXO = DT_7seg[Z_NUM_r];
					}
					else								//	ï¿½Ïºï¿½ï¿½ï¿½
					{
						SEG_OXX = DT_7seg[Z_NUM_J];
						SEG_XOX = DT_7seg[Z_NUM_P];
						SEG_XXO = DT_7seg[Z_NUM_n];					
					}
					DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
				}
			}
			break;
		case SEG_PBATEST:
			if (gu8_TimerFCTSet != 0)				//			ï¿½×½ï¿½Æ®ï¿½ï¿½ï¿???????1,2 ï¿½ï¿½È¯ Ç¥ï¿½ï¿½ Å¸ï¿½Ì¸ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿???????
			{
				if (F_TestMode_PBA_2 == SET)		//				ï¿½×½ï¿½Æ®ï¿½ï¿½ï¿???????2
				{
					SEG_OXX = DT_7seg[Z_NUM_t];
					SEG_XOX = DT_7seg[Z_NUM_E];
					SEG_XXO = DT_7seg[Z_NUM_2];
				}
				else								//				ï¿½×½ï¿½Æ®ï¿½ï¿½ï¿???????1
				{
					SEG_OXX = DT_7seg[Z_NUM_t];
					SEG_XOX = DT_7seg[Z_NUM_E];
					SEG_XXO = DT_7seg[Z_NUM_1];
				}
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else if (gu8_TimerPBATest_HotLoadDisplay != 0)
			{
				SEG_OXX = DT_7seg[Z_NUM_H];
				SEG_XOX = DT_7seg[Z_NUM_o];
				SEG_XXO = DT_7seg[gu8_PBATest_HotLoad];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else if (gu8_TimerPBATest_ColdLoadDisplay != 0)
			{
				SEG_OXX = DT_7seg[Z_NUM_C];
				SEG_XOX = DT_7seg[Z_NUM_o];
				SEG_XXO = DT_7seg[gu8_PBATest_ColdLoad];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else if (gu8_TimerPBATest_PureLoadDisplay != 0)
			{
				SEG_OXX = DT_7seg[Z_NUM_P];
				SEG_XOX = DT_7seg[Z_NUM_u];
				SEG_XXO = DT_7seg[gu8_PBATest_PureLoad];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else if (gu8_ErrorCode != 0)
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[(gu8_ErrorCode & 0xf0) >> 4];
				SEG_XXO = DT_7seg[(gu8_ErrorCode & 0x0f)];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if (gu8_TimerPBATest_FanDisplay != 0)
			{
				SEG_OXX = DT_7seg[Z_NUM_F];
				SEG_XOX = DT_7seg[Z_NUM_A];
				SEG_XXO = DT_7seg[gu8_PBATest_FanTest];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else if (F_PBATest_FanFeedBack_Error == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_F];
				SEG_XOX = DT_7seg[Z_NUM_A];
				SEG_XXO = DT_7seg[Z_NUM_n];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if (F_HeaterFeedBack_Error == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_H];
				SEG_XOX = DT_7seg[Z_NUM_E];
				SEG_XXO = DT_7seg[Z_NUM_A];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if (F_TEMFeedBack_Error == SET)
			{
				SEG_XOX = DT_7seg[Z_NUM_t];
				SEG_XXO = DT_7seg[Z_NUM_E];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if (F_24VFeedBack_Error == SET)
			{
				SEG_XOX = DT_7seg[Z_NUM_2];
				SEG_XXO = DT_7seg[Z_NUM_4];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if (INPUT_REED_SW_COVER == SET)
			{
				SEG_XXO = DT_7seg[Z_NUM_2];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if (INPUT_REED_SW_FILTER == SET)
			{
				SEG_XXO = DT_7seg[Z_NUM_3];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if(INPUT_REED_SW_FAUCET_UP == SET)
			{
				SEG_XXO = DT_7seg[Z_NUM_4];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if(INPUT_REED_SW_FAUCET_DOWN == SET)
			{
				SEG_XXO = DT_7seg[Z_NUM_5];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
			else if(INPUT_MICRO_SW_FAUCET == SET)
			{
				SEG_XXO = DT_7seg[Z_NUM_6];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}		
			else if (INPUT_REED_SW_FAUCET == SET)
			{
				SEG_XXO = DT_7seg[Z_NUM_7];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			}
//			else if ((gu16_FlowDecide_Hz >= 200) && (gu16_FlowDecide_Hz <= 1000))
//			{
//				SEG_OXX = DT_7seg[Z_NUM_F];
//				SEG_XOX = DT_7seg[Z_NUM_L];
//				SEG_XXO = DT_7seg[Z_NUM_O];
//				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
//			}
			break;
		case SEG_LINETEST2:
			if(F_Err25_HeatSinkTH == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_2];
				SEG_XXO = DT_7seg[Z_NUM_5];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;				
			}
			else if(F_Err43_OutDoorAirTH == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_4];
				SEG_XXO = DT_7seg[Z_NUM_3];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;				
			}
			else if(F_Err44_ColdTH == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_4];
				SEG_XXO = DT_7seg[Z_NUM_4];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;				
			}
			else if(F_Err46_HotInTH == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_4];
				SEG_XXO = DT_7seg[Z_NUM_6];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;				
			}
			else if(F_Err47_HotOutTH == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_4];
				SEG_XXO = DT_7seg[Z_NUM_7];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;				
			}
			else if(F_Err48_HeaterTH == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_E];
				SEG_XOX = DT_7seg[Z_NUM_4];
				SEG_XXO = DT_7seg[Z_NUM_8];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;				
			}											
			else if (F_LineTest2_HeaterResult_NG == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_BAR];
				SEG_XOX = DT_7seg[Z_NUM_BAR];
				SEG_XXO = DT_7seg[Z_NUM_BAR];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else if (F_LineTest2_HeaterResult_OK == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_O];
				SEG_XOX = DT_7seg[Z_NUM_O];
				SEG_XXO = DT_7seg[Z_NUM_O];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			else
			{
				SEG_OXX = DT_7seg[Z_NUM_t];
				SEG_XOX = DT_7seg[Z_NUM_E];
				SEG_XXO = DT_7seg[Z_NUM_2];
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			}
			break;
//		case SEG_COLDTANK:
//			SEG_OXX = DT_7seg[Z_NUM_t];
//			SEG_XOX = DT_7seg[Z_NUM_A];
//			SEG_XXO = DT_7seg[Z_NUM_n];
//			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
//			break;
		case SEG_MANAGE:
			if (F_SelfService == SET)
			{
				SEG_OXX = DT_7seg[Z_NUM_S];
				SEG_XOX = DT_7seg[Z_NUM_E];
			}
			else
			{
				SEG_OXX = DT_7seg[Z_NUM_C];
				SEG_XOX = DT_7seg[Z_NUM_O];
			}
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
			break;
		case SEG_AD_FEEDBACK:
			
			// Å¸ÀÌ¸Ó°¡ 0ÀÌ µÇ¸é »óÅÂ ÀüÈ¯
			if (gu8_Timer_AdFeedback_Loading != 0)
			{
				if(gu8_Timer_AdFeedback_Loading >= 20)
				{
					SEG_OXX = DT_7seg[Z_NUM_BAR];
				}
				else if(gu8_Timer_AdFeedback_Loading >= 10)
				{
					SEG_OXX = DT_7seg[Z_NUM_BAR];
					SEG_XOX = DT_7seg[Z_NUM_BAR];
				}
				else
				{
					// ÄÑÁü
					SEG_OXX = DT_7seg[Z_NUM_BAR];
					SEG_XOX = DT_7seg[Z_NUM_BAR];
					SEG_XXO = DT_7seg[Z_NUM_BAR];
				}
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;

				gu8_Timer_Smps_Feedback_Display = Z_TIMER_SMPS_FEEDBACK_DISPLAY;
			}
			else
			{
				#ifdef SMPS_VOLTAGE_AND_TEM_CURRENT_DISPLAY
				// 1ÃÊ ÁÖ±â·Î »óÅÂ ÀüÈ¯ (0 ¡æ 1 ¡æ 2 ¡æ 3 ¡æ 0)
				if(gu8_Timer_Smps_Feedback_Display == 0)
				{
					gu8_Timer_Smps_Feedback_Display = Z_TIMER_SMPS_FEEDBACK_DISPLAY;

					mu8_AdFeedback_State++;
					if (mu8_AdFeedback_State >= 4)
					{
						mu8_AdFeedback_State = 0;
					}
					
				}
				else
				{

				}

				// »óÅÂ¿¡ µû¶ó Ç¥½Ã
				switch (mu8_AdFeedback_State)
				{
					case 0:  // VOL ÅØ½ºÆ® Ç¥½Ã
						SEG_OXX = DT_7seg[Z_NUM_U];  // V (V°¡ ¾øÀ¸¸é ´Ù¸¥ ¹®ÀÚ »ç¿ë)
						SEG_XOX = DT_7seg[Z_NUM_O];  // O
						SEG_XXO = DT_7seg[Z_NUM_L];  // L
						break;
						
					case 1:  // VOL °ª Ç¥½Ã

						mu16_VolValue = calculate_smps_voltage_feedback(ADC_RESULT_VOLTAGE_FB);  // VOL °ª
						mu8_Thousands = (U8)((mu16_VolValue / 1000) % 10);
						mu8_Hundreds = (U8)((mu16_VolValue / 100) % 10);
						mu8_Tens = (U8)((mu16_VolValue / 10) % 10);
						
						if (mu16_VolValue >= 1000)
						{
							SEG_OXX = DT_7seg[mu8_Thousands];
						}
						else
						{
							SEG_OXX = DT_7seg[Z_NUM_X];  // ºóÄ­
						}
						
						if (mu16_VolValue >= 100)
						{
							SEG_XOX = DT_7seg[mu8_Hundreds];
						}
						else
						{
							SEG_XOX = DT_7seg[Z_NUM_X];  // ºóÄ­
						}
						
						if (mu16_VolValue >= 10)
						{
							SEG_XXO = DT_7seg[mu8_Tens];
						}
						else
						{
							SEG_XXO = DT_7seg[Z_NUM_X];  // ºóÄ­
						}
						break;
						
					case 2:  // TEM ÅØ½ºÆ® Ç¥½Ã
						SEG_OXX = DT_7seg[Z_NUM_t];  // T
						SEG_XOX = DT_7seg[Z_NUM_E];  // E
						SEG_XXO = DT_7seg[Z_NUM_n];  // M (n ´ë½Å ´Ù¸¥ ¹®ÀÚ »ç¿ë °¡´É)
						break;
						
					case 3:  // TEM °ª Ç¥½Ã

						mu16_TemValue = calculate_tem_current(ADC_RESULT_TEM_FB);

						mu8_Thousands = (U8)((mu16_TemValue / 1000) % 10);
						mu8_Hundreds = (U8)((mu16_TemValue / 100) % 10);
						mu8_Tens = (U8)((mu16_TemValue / 10) % 10);
						
						if (mu16_TemValue >= 1000)
						{
							SEG_OXX = DT_7seg[mu8_Thousands];
						}
						else
						{
							SEG_OXX = DT_7seg[Z_NUM_X];  // ºóÄ­
						}
						
						if (mu16_TemValue >= 100)
						{
							SEG_XOX = DT_7seg[mu8_Hundreds];
						}
						else
						{
							SEG_XOX = DT_7seg[Z_NUM_X];  // ºóÄ­
						}
						
						if (mu16_TemValue >= 10)
						{
							SEG_XXO = DT_7seg[mu8_Tens];
						}
						else
						{
							SEG_XXO = DT_7seg[Z_NUM_X];  // ºóÄ­
						}
						break;
						
					default:
						break;
				}
				
				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
					break;
				default:
					break;
				#else
				
				// MIN/MAX ¹üÀ§ È®ÀÎ (¡¾10%)
				// VOL °ª ¹üÀ§ È®ÀÎ
				if (check_smps_voltage_range(gu16_ad_feedback_mode_smps_voltage_Result) != 0)
				{
					SEG_XXO = DT_7seg[Z_NUM_1];
				}					
				// TEM °ª ¹üÀ§ È®ÀÎ
				else if (check_tem_current_range(gu16_ad_feedback_mode_tem_mA_Result) != 0)
				{
					SEG_XXO = DT_7seg[Z_NUM_2];
				}
				else 
				{
					SEG_XXO = DT_7seg[Z_NUM_0];
				}

				DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_ON;
				#endif
			}
		}

	if ((gu8_SegData_Before[0].byte != gu8_SegData[0].byte)
		|| (gu8_SegData_Before[1].byte != gu8_SegData[1].byte)
		|| (gu8_SegData_Before[2].byte != gu8_SegData[2].byte))
	{
		F_CommunicationCMD = SET;
	}

	gu8_SegData_Before[0].byte = gu8_SegData[0].byte;
	gu8_SegData_Before[1].byte = gu8_SegData[1].byte;
	gu8_SegData_Before[2].byte = gu8_SegData[2].byte;



	/********ÃßÃâ ½Å·Ú¼º³»±¸¼º ÇÁ·Î±×·¥*******/
	#ifdef _FOR_HOTWATER_1CUP_EFF_30s_DELAY_
	if(gu8_F_EffluentDurabilityProgram == SET)
	{
		SEG_OXX = DT_7seg[Z_NUM_H];
		SEG_XOX = DT_7seg[Z_NUM_O];
		SEG_XXO = DT_7seg[Z_NUM_t];		
	}
	#endif
	#ifdef	_FOR_COLD_PURE_EFF_10s_REPEAT_
	if(gu8_F_EffluentDurabilityProgram == SET)
	{
		SEG_OXX = DT_7seg[Z_NUM_C];
		SEG_XOX = DT_7seg[Z_NUM_O];
		SEG_XXO = DT_7seg[Z_NUM_L];		
	}
	#endif
	/*************************************/	
}

/// @brief
/// @param    void
/// @return   void
static void LED_PURE(void)
{
	switch (DisplayControl_Data[Z_LED_PURE].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
		case LED_EFF:
			if (gu8_WaterSelect == PURE_WATER)
			{
				DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_OFF;
			}
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_PureButton_Counter < 1)
			{
				DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if (F_LineFrontTest_Pure_Select == SET)
				{
					DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_OFF;
				}
			}
			break;
		case LED_ALL_LOCK:
			if (gu8_ModelType_forCHP == MODEL_CHP)
			{
				if (gu8_TimerAllLockDisplay != 0)
				{
					DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FADE_F;
				}
				else
				{
					DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_ON;
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_OFF;
			}
			break;
		case LED_PBATEST:
			if (F_TestMode_PBA_2 == SET)
			{
				DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_OFF;
			}
			else
			{
				if (F_EEPROM_CommunicationError == SET)
				{
					DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FADE_F;
				}
				else
				{
					DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_OFF;		
				}
			}
			break;
		case LED_STEMODE:
			if ((gu16_TimerKITMode > (Z_TimerKITMode-30)) || (gu16_TimerKITMode < 30))
			{
				DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FADE_F_S;
			}
			break;
		case LED_TOPCOVER:
			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_OFF;
			break;
		case LED_LINETEST2:
			if (F_LineTest2_Valve == SET)
			{
				DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_OFF;
			}
			break;
		case LED_WIFI_READY:											
			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_DIMM;		
			break;														
		default:
			// DisplayControl_Data[Z_LED_PURE].Display_CMD = DisplayControl_Data[Z_LED_PURE].Operation_CMD;
			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_OFF;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_AMOUNT(void)
{
	switch (DisplayControl_Data[Z_LED_AMOUNT].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
			if (gu8_TimerCupSelect != 0)
			{
				DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_ON;
			}
			else
			{
				if(gu8_TimerSleepMode == 0)
				{
					DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_OFF;
				}
			}
			break;
		case LED_EFF:
			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_OFF;
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_AmountButton_Counter < 1)
			{
				DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if (F_LineFrontTest_AMount_Select == SET)
				{
					DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_OFF;
				}
			}
			break;
		case LED_PBATEST:
			if (F_TestMode_PBA_2 == SET)
			{
				DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_DIMM;
			}
			else
			{
				if ((gi16_OutDoorAirSensor.DEGREE >= Z_TEMP15) && (gi16_OutDoorAirSensor.DEGREE <= Z_TEMP35))
				{
					DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_ON;
				}
			}
			break;
		case LED_SOUND:
			if (gu8_TimerSoundChange != 0)
			{
				DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_OFF;
			}
			break;
		case LED_TOPCOVER:
			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_OFF;
			break;
		case LED_LINETEST2:
			if(F_LineTest2_FaucetMoving == SET)
			{
				DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_ON;
			}
			break;
		default:
			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = DisplayControl_Data[Z_LED_AMOUNT].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_COLD(void)
{
	switch (DisplayControl_Data[Z_LED_COLD].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
		case LED_EFF:
			if (gu8_WaterSelect == COLD_WATER)
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_OFF;
			}
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_ColdButton_Counter < 1)
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if (F_LineFrontTest_Cold_Select == SET)
				{
					DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_OFF;
				}
			}
			else
			{
				if (gu8_ModelType_forCHP == MODEL_CP)
				{
					DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_ON;
				}
			}
			break;
		case LED_PBATEST:
			if (F_TestMode_PBA_2 == SET)
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_DIMM;
			}
			else
			{
				if ((gi16_ColdSensor.DEGREE >= Z_TEMP3) && (gi16_ColdSensor.DEGREE <= Z_TEMP9))
				{
					DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_OFF;
				}
			}
			break;
		case LED_STEMODE:
			if ((gu16_TimerKITMode <= (Z_TimerKITMode-30)) && (gu16_TimerKITMode >= 30))
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_FADE_F_S;
			}
			break;
		case LED_TOPCOVER:
			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_OFF;
			break;
		case LED_LINETEST2:
			if (F_LineTest2_Cooling == SET)
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_OFF;
			}
			break;
		case LED_OFF_DISP:
			if (gu8_TimerOFF_Flic != 0)
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_FADE_F;
			}
			else
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_ON;
			}
			break;
		case LED_FLU_READY:
			#if 0
			if ((F_FilterChange_Detect == SET) || (F_FaucetChange_Detect == SET))
			#endif
			if (F_FilterChange_Detect == SET)			//	À¯·ÎÆÄ¿ì¼ÂÀº ÇÃ·¯½Ì ¾øÀ½.
			{
				DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_DIMM;
			}
			break;
		case LED_WIFI_READY:											
			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_DIMM;		
			break;														
		default:
			// DisplayControl_Data[Z_LED_COLD].Display_CMD = DisplayControl_Data[Z_LED_COLD].Operation_CMD;
			DisplayControl_Data[Z_LED_COLD].Display_CMD	= LED_OFF;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_HOT(void)
{
	switch (DisplayControl_Data[Z_LED_HOT].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
			if (gu8_TimerHotLock_Display != 0)
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F;
			}
			else if (gu8_WaterSelect == HOT_WATER)
			{
				if (gu8_HotStep == Z_HotStep_35)
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
				}
				else if ((gu8_HotStep >= Z_HotStep_2F) && (gu8_HotStep < Z_HotStep_35) && (gu8_HotStep != Z_HotStep_32))
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F;
				}
				else
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
				}
			}
			else
			{
				if (gu8_ModelType_forNational == MODEL_JAPAN)
				{
					if (F_HotLock == CLEAR)
					{
						DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F_S;	//	ï¿½Â¼ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï´Ù´ï¿½ Ç¥ï¿½ï¿½
					}
					else
					{
						DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_DIMM;
					}
				}
				else
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_OFF;
				}
			}
			break;
		case LED_EFF:
			if (gu8_WaterSelect == HOT_WATER)
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_OFF;
			}
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_HotButton_Counter < 1)
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if (F_LineFrontTest_Hot_Select == SET)
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_OFF;
				}
			}
			else
			{
				if (gu8_ModelType_forCHP == MODEL_CHP)
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
				}
			}
			break;
		case LED_PBATEST:
			if (F_TestMode_PBA_2 == SET)
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_DIMM;
			}
			else
			{
				if ((gi16_HotInSensor.DEGREE >= Z_TEMP17) && (gi16_HotInSensor.DEGREE <= Z_TEMP23))
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
				}
				else if ((gi16_HotOutSensor.DEGREE >= Z_TEMP77) && (gi16_HotOutSensor.DEGREE <= Z_TEMP80))
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
				}
				else if ((gi16_HeaterSensor.DEGREE >= Z_TEMP77) && (gi16_HeaterSensor.DEGREE <= Z_TEMP80))
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_OFF;
				}
			}
			break;
		case LED_ALL_LOCK:
			if (gu8_TimerAllLockDisplay != 0)
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F;
			}
			else
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
			}
			break;
		case LED_SOUND:
			if (gu8_TimerSoundChange != 0)
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_OFF;
			}
			break;
		case LED_TOPCOVER:
			DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_OFF;
			break;
		case LED_LINETEST2:
			if (F_LineTest2_Heater == SET)
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_OFF;
			}
			break;
		default:
			DisplayControl_Data[Z_LED_HOT].Display_CMD = DisplayControl_Data[Z_LED_HOT].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_HOTBAR(void)
{
	switch (DisplayControl_Data[Z_LED_HOT_BAR_1].Operation_CMD)
	{
		case LED_BOOT:
			DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_FADE_F;									
			break;
		case LED_STATUS:
			if(gu8_WaterSelect == HOT_WATER)
			{
				if(F_FirstHotEffluent == SET)			//	Ã¹ï¿½Ü¿Ï·ï¿½ï¿½Î°ï¿½ï¿??????? Ç¥ï¿½ï¿½..
				{
					if (gu8_hot_water_select_index == 0)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_DIMM;		
					}
					else if (gu8_hot_water_select_index == 1)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_DIMM;	
					}
					else if (gu8_hot_water_select_index == 2)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_DIMM;	
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_DIMM;
					}
					else if (gu8_hot_water_select_index == 3)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_ON;	
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_DIMM;
					}
					else if (gu8_hot_water_select_index == 4)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_ON;	
					}
					else
					{

					}
					
					//	È°¼ºÈ­ ¾ÈµÈ³ðÀº off...
					if(gu8_select_hot_temp_total_count == 1)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_OFF;
						DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_OFF;
						DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_OFF;
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_OFF;	
					}
					else if(gu8_select_hot_temp_total_count == 2)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_OFF;
						DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_OFF;
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_OFF;	
					}
					else if(gu8_select_hot_temp_total_count == 3)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_OFF;
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_OFF;	
					}
					else if(gu8_select_hot_temp_total_count == 4)
					{
						DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_OFF;	
					}			
					else
					{

					}																
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_OFF;					
			}						
			break;	
		
		case LED_FRONTTEST:
			if (gu8_FrontTest_HotButton_Counter < 3)
			{
				DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;	
			}
			else if (gu8_FrontTest_HotButton_Counter < 4)
			{
				DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;	
			}	
			else if (gu8_FrontTest_HotButton_Counter < 5)
			{
				DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;	
			}
			else if (gu8_FrontTest_HotButton_Counter < 6)
			{
				DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;	
			}
			else if (gu8_FrontTest_HotButton_Counter < 7)
			{

				DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;	
			}
			else if (gu8_FrontTest_HotButton_Counter < 8)
			{

			}	
			else
			{

			}													
			break;

		case LED_PBATEST:
			if ((gu16_FlowDecide_Hz >= 200) && (gu16_FlowDecide_Hz <= 1000))
			{
				DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;					
			}
			break;

		case LED_LINETEST:

			if(F_TestMode_LineAuto == CLEAR)
			{
				if(F_LineFrontTest_Hot_Select == 1)
				{
					DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;
				}
			}

			break;
		case LED_LINETEST2:
			#if 0
			if(F_LineTest2_FaucetMoving == SET)
			{
				if(gu8_F_LineAuto_Faucet_DownReed == SET)
				{
					DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_FADE_F;				
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_OFF;				
			}
			#endif
			break;		
		default:
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_EFFLUENT(void)
{
	switch (DisplayControl_Data[Z_LED_EFFLUENT].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_FADE_F;
			break;
		case LED_DIMM:
			if ((gu8_OperationStep_hi == 0x10) || (gu8_OperationStep_hi == 0x20)	//	ï¿½ï¿½ï¿???????/ï¿½ï¿½ï¿½ï¿½/ï¿½ï¿½ï¿½ï¿½/UV ï¿½ï¿½ï¿½ï¿½
			|| (gu8_OperationStep_hi == 0x30) || (gu8_OperationStep_hi == 0x40))
			{
				if (F_EffluentLED_OFF == CLEAR)
				{
					DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_DIMM;
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_DIMM;
			}
			break;
		case LED_ON:
			if ((gu8_OperationStep_hi == 0x10) || (gu8_OperationStep_hi == 0x20)	//	ï¿½ï¿½ï¿???????/ï¿½ï¿½ï¿½ï¿½/ï¿½ï¿½ï¿½ï¿½/UV ï¿½ï¿½ï¿½ï¿½
			|| (gu8_OperationStep_hi == 0x30) || (gu8_OperationStep_hi == 0x40))
			{
				if (F_EffluentLED_OFF == CLEAR)
				{
					DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_ON;
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_ON;
			}
			break;
		case LED_EFF:
			if (gu8_HotStep == Z_HotStep_02)
			{
				DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_FADE_F_S;
			}
			else
			{
				DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_ON;
			}
			break;
		case LED_TOPCOVER:
    		// ÃßÃâ ¹öÆ° LED Á¦¾î
			if (F_ColdEffStep_B0_Request == CLEAR)
			{
				DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_FADE_F;  // Á¡¸ê
			}
			else
			{
				DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_OFF;  // ¼Òµî
			}		
			break;
		case LED_FRONTTEST:
			if (F_FrontTest_EffluentButton == CLEAR)
			{
				DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_ON;
			}
			break;
		case LED_PBATEST:
			DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_DIMM;
			break;
		case LED_LINETEST:
			if(F_TestMode_LineAuto == CLEAR)
			{
				if (F_LineFrontTest_Effluent_Oper == SET)
				{
					//@010 DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_FADE_F;	//@010
				}
				else
				{
					//@010 DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_OFF;
					DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_ON;		//@010
				}
			}
			else if(gu8_FaucetMoving_Step == Z_FAUCET_MOVING_LINE_TEST_2)    // @014
			{                                                                // @014
				DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_ON;		//@014
			}                                                                 //@014
			else                                                              //@014
			{	                                                              //@014
			}                                                                 //@014
			break;
		default:
			DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = DisplayControl_Data[Z_LED_EFFLUENT].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_CUP(void)
{
	U8 mu8_i = 0;

	switch (DisplayControl_Data[Z_LED_2CUP].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_FADE_F_S;
//			DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_FADE_F_S;
//			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FADE_F_S;
//			DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_FLIC;
//			DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_FLIC;
//			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FLIC;
//			DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FLIC;
//			break;
		case LED_EFF:
//			if (gu8_HotStep == Z_HotStep_02)
			if ((gu8_WaterSelect == HOT_WATER) && (F_FirstHotEffluent == CLEAR))
			{
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
			}
			else
			{
				#if 0
				switch (gu8_CupIndex)
				{
					case CUPSIZE_ONE:
						DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;																								
						break;
					case CUPSIZE_TWO:
						DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;	
						break;
					case CUPSIZE_THREE:
						DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;
						break;
					case CUPSIZE_FOUR:
						DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;				
						break;				
					case CUPSIZE_FIVE:
#ifndef _AFTER_LPP_IMDCHANGE_
						if (gu8_ModelType_forNational == MODEL_JAPAN)
						{
							DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;
						}
#else
						DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
						DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;
#endif
						break;
					default:
						break;
				}
				#endif
				for (mu8_i = 0; mu8_i < (CUPSIZE_FIVE + 1); mu8_i++)
				{
					if(gu8_Cup_size_Array[mu8_i].enable == 0)
					{
						DisplayControl_Data[Z_LED_HALFCUP - mu8_i].Display_CMD = LED_OFF;
					}
					else
					{
						if(gu8_CupIndex == mu8_i)
						{
							DisplayControl_Data[Z_LED_HALFCUP - mu8_i].Display_CMD = LED_ON;
						}
						else
						{
							DisplayControl_Data[Z_LED_HALFCUP - mu8_i].Display_CMD = LED_DIMM;
						}
					}
				}
			}
			break;
		case LED_STATUS:
#ifndef _AFTER_LPP_IMDCHANGE_
			if (gu8_TimerMySetFilker != 0)
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F;
			}
			else
#endif
			if (gu8_TimerDefaultCupSize_Set_LEDFlic != 0)
			{
				switch (gu8_CupIndex)
				{
					case CUPSIZE_ONE:
						DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FADE_F;
						break;
					case CUPSIZE_TWO:
						DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_FADE_F;
						break;
					case CUPSIZE_THREE:
						DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_FADE_F;
						break;
					case CUPSIZE_FOUR:	
						DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_FADE_F;									
						break;
#ifndef _AFTER_LPP_IMDCHANGE_
					case CUPSIZE_MY:
						DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F;
						break;
#endif
					default:
						break;
				}
			}			
			else if (gu8_TimerCupSize_LEDFlic_forJAPAN_Limit != 0)
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;				
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FADE_F;
			}
			else if(gu8_F_Moving_Durability == SET)
			{
				if(gu8_Timer_Faucet_Set_Mode_Display >= 100)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;				
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
				}
				else if(gu8_Timer_Faucet_Set_Mode_Display >= 80)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
				}
				else if(gu8_Timer_Faucet_Set_Mode_Display >= 60)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;				
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
				}
				else if(gu8_Timer_Faucet_Set_Mode_Display >= 40)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;					
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
				}
				else if(gu8_Timer_Faucet_Set_Mode_Display >= 20)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;				
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
				}
				else
				{

				}
				
				if(gu8_Timer_Faucet_Set_Mode_Display == 0)
				{
					gu8_Timer_Faucet_Set_Mode_Display = 120;
				}				
			}
			else 
			{
				if ((gu8_WaterSelect == HOT_WATER) && (F_HotDegreeDisplay == SET) && (F_FirstHotEffluent == CLEAR))
				{
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
				}
				else if (gu8_TimerSleepMode != 0)
				{
					for (mu8_i = CUPSIZE_ONE; mu8_i <= CUPSIZE_FIVE; mu8_i++)
					{
						// gu16_Setting_Amount_Value[i] ???? 0?? ????
						if(gu8_Cup_size_Array[mu8_i].enable == 0)
						{
							DisplayControl_Data[Z_LED_HALFCUP - mu8_i].Display_CMD = LED_OFF;
						}
						else
						{
							if(gu8_CupIndex == mu8_i)
							{
								DisplayControl_Data[Z_LED_HALFCUP - mu8_i].Display_CMD = LED_ON;
							}
							else
							{
								DisplayControl_Data[Z_LED_HALFCUP - mu8_i].Display_CMD = LED_DIMM;
							}
						}
					}

					#if 0
					switch (gu8_CupIndex)
					{
						case CUPSIZE_ONE:
							DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;						
							DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
							DisplayControl_Data[Z_LED_CON].Display_CMD =	LED_DIMM;
							break;
						case CUPSIZE_TWO:
							DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;						
							DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
							DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_CON].Display_CMD =	LED_DIMM;
							break;
						case CUPSIZE_THREE:
							DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;						
							DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
							DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;
							break;
						case CUPSIZE_FOUR:	
							DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;												
							DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;	
							DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;												
							break;
						case CUPSIZE_FIVE:
							DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;
							break;
						case CUPSIZE_MY:
							DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
							DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;
							break;
						default:
							break;
					}
					#endif
				}
			}
			break;
		case LED_COLDTANK:
				if (gu8_TimerColdTankClearDisplay == 0)
				{
					gu8_TimerColdTankClearDisplay = Z_TimerColdTankClearDisplay;
				}

				if (gu8_TimerColdTankClearDisplay > ((Z_TimerColdTankClearDisplay / 4) * 3))
				{
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
				}
				else if (gu8_TimerColdTankClearDisplay > ((Z_TimerColdTankClearDisplay / 4) * 2))
				{
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
				}
				else if (gu8_TimerColdTankClearDisplay > ((Z_TimerColdTankClearDisplay / 4) * 1))
				{
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
				}
				// else if (gu8_TimerColdTankClearDisplay > ((Z_TimerColdTankClearDisplay / 5) * 1))
				else				
				{
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;
				}
				// else
				// {
				// 	DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
				// 	DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
				// 	DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
				// 	DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;
				// }
			break;

		case LED_BOOT:
			DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_FADE_F;		
			DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F;
			break;

		case LED_FAUCET_MODE:
			if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_AUTO_LEVEL)
			{
				if(gu8_Timer_Faucet_Set_Mode_Display >= 100)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;				
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
				}
				else if(gu8_Timer_Faucet_Set_Mode_Display >= 80)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
				}
				else if(gu8_Timer_Faucet_Set_Mode_Display >= 60)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;				
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
				}
				else if(gu8_Timer_Faucet_Set_Mode_Display >= 40)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;					
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
				}
				else if(gu8_Timer_Faucet_Set_Mode_Display >= 20)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;				
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
				}
				else
				{

				}
				
				if(gu8_Timer_Faucet_Set_Mode_Display == 0)
				{
					gu8_Timer_Faucet_Set_Mode_Display = 120;
				}

			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_1_LEVEL)
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;				
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_2_LEVEL)
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_3_LEVEL)
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;				
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_4_LEVEL)
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;					
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;		
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
			}
			else if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_5_LEVEL)
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;				
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_DIMM;		
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
			}
			else
			{

			}			
			break;

//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_DIMM;
//			DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_DIMM;
//			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_DIMM;
//			DisplayControl_Data[Z_LED_CON].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			break;
		case LED_FRONTTEST:
			if(gu8_FrontTest_AmountButton_Counter < 3)
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;						
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
			}
			else if(gu8_FrontTest_AmountButton_Counter < 4)
			{
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;						
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
			}	
			else if(gu8_FrontTest_AmountButton_Counter < 5)
			{		
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
			}
			else if(gu8_FrontTest_AmountButton_Counter < 6)
			{
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
			}	
			else if(gu8_FrontTest_AmountButton_Counter < 7)
			{
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
			}
			else if(gu8_FrontTest_AmountButton_Counter < 8)
			{
				
			}	
			else
			{
				
			}												
			break;
		case LED_PBATEST:
			if ((gi16_HotInSensor.DEGREE >= Z_TEMP17) && (gi16_HotInSensor.DEGREE <= Z_TEMP23))
			{
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
			}
			if ((gi16_HotOutSensor.DEGREE >= Z_TEMP77) && (gi16_HotOutSensor.DEGREE <= Z_TEMP83))
			{
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
			}
			if ((gi16_HeaterSensor.DEGREE >= Z_TEMP77) && (gi16_HeaterSensor.DEGREE <= Z_TEMP83))
			{
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
			}
			if ((gi16_HeatSinkSensor.DEGREE >= Z_TEMP47) && (gi16_HeatSinkSensor.DEGREE <= Z_TEMP53))
			{
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if(INPUT_REED_SW_COVER == CLEAR)
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F;
				}			
				else
				{
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;
				}

				if(F_LineFrontTest_AMount_Select == 1)
				{
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;						
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
				}
			}
			else
			{

			}
			break;
		case LED_LINETEST2:
			if(F_LineTest2_FaucetMoving == SET)
			{
				if(gu8_F_LineAuto_Faucet_UpReed == SET)
				{
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_ON;						
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_FADE_F;						
					DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F;				
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_OFF;						
				DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_CON].Display_CMD = LED_OFF;
			}
			break;
		default:
			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = DisplayControl_Data[Z_LED_HALFCUP].Operation_CMD;
			DisplayControl_Data[Z_LED_1CUP].Display_CMD = DisplayControl_Data[Z_LED_1CUP].Operation_CMD;
			DisplayControl_Data[Z_LED_2CUP].Display_CMD = DisplayControl_Data[Z_LED_2CUP].Operation_CMD;
			DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = DisplayControl_Data[Z_LED_2CUP].Operation_CMD;
			DisplayControl_Data[Z_LED_CON].Display_CMD = DisplayControl_Data[Z_LED_CON].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_COLD_TEMP(void)
{
	switch (DisplayControl_Data[Z_LED_COLD_BLUE].Operation_CMD)
	{
		case LED_OFF:
			break;
		case LED_FADE_F:
			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_FADE_F;
			break;
		case LED_FADE_F_S:
			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_FADE_F_S;
//			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_FADE_F_S;
			break;
		case LED_FLIC:
			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_FLIC;
//			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_FLIC;
			break;
		case LED_STATUS:
		case LED_EFF:
			if (F_ColdOff == CLEAR)
			{
				if ((F_Err25_HeatSinkTH == SET) || (F_Err44_ColdTH == SET) || (F_Err29_TEM_OverDrive1 == SET) || (F_Err29_TEM_OverDrive2 == SET))		//	ï¿½Ü¼ï¿½ï¿½Ü¶ï¿½ï¿½ï¿½ ï¿½Ö´ï¿½ ï¿½ï¿½ï¿??????? or TEM ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ö´ï¿½ ï¿½ï¿½ï¿???????
				{
					DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_FADE_F;
				}
				else
				{
					if (gi16_ColdSensor.DEGREE > RAPID_COMPLETE_DEGREE)
					{
						gu8_TimerColdTempDisplay_forBlue = Z_TimerColdTempDisplay;
					}

					if (gi16_ColdSensor.DEGREE < Z_TEMP10)
					{
						gu8_TimerColdTempDisplay_forWhite = Z_TimerColdTempDisplay;
					}

					switch (F_ColdTemp_Display)
					{
						case 0:							//	WHITE
						default:
							if (gu8_TimerColdTempDisplay_forBlue == 0)
							{
								F_ColdTemp_Display = 1;
							}

//							if (gu8_WaterSelect == COLD_WATER)
//							{
								DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_ON;
//							}
//							else
//							{
//								DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD =	LED_DIMM;
//							}
							break;
						case 1:							//	BLUE
							if (gu8_TimerColdTempDisplay_forWhite == 0)
							{
								F_ColdTemp_Display = 0;
							}

//							if (gu8_WaterSelect == COLD_WATER)
//							{
								DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_ON;
//							}
//							else
//							{
//								DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_DIMM;
//							}
							break;
					}
				}
			}
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_DIMM;
//			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_ON;
//			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_ColdButton_Counter < 2)
			{
				DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_ON;
			}
			else if (gu8_FrontTest_ColdButton_Counter < 3)
			{
				DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			#if 0
			if (F_TestMode_LineAuto == CLEAR)
			{
				if ((F_LineFrontTest_Cold_Select == SET) && (F_LineFrontTest_Effluent_Oper == SET))
				{
					DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_ON;
				}
			}
			#endif
			break;
		case LED_LINETEST2:
			if (F_LineTest2_Cooling == SET)
			{
				if (F_LineTest2_CoolingResult_OK == SET)
				{
					DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_ON;
				}
				else
				{
					if (gu8_TimerLineTest2_Cooling != 0)
					{
						DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_ON;
					}
					else
					{
						DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_FADE_F;
					}
				}
			}
			break;
		default:
			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = DisplayControl_Data[Z_LED_COLD_WHITE].Operation_CMD;
			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = DisplayControl_Data[Z_LED_COLD_BLUE].Operation_CMD;
			break;
	}	
}

/// @brief
/// @param    void
/// @return   void
static void LED_FAUCET(void)
{
	switch (DisplayControl_Data[Z_LED_FAUCET].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
#ifndef _AFTER_LPP_IMDCHANGE_
			if ((F_FilterChange_Display == SET) || (F_FaucetChange_Display == SET))
			{
				DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_ON;
			}
#else	
			//	ÆÄ¿ì¼Â ÆÁ....ºüÁ³À»¶§ Á¡¸ê »ç¾ç Ãß°¡
			//@022 if(gu8_TimerReedSWCheck_forFaucetTip == 0)
			if((gu8_TimerReedSWCheck_forFaucetTip == 0)
			&& (gu8_WaterSelect == HOT_WATER)                                    //@022 ¿Â¼öÀÏ¶§¸¸
			&& (gu8_F_FaucetTip_Undetected_Display_Done == CLEAR)                 //@022 1È¸¸¸
			&& (F_FirstHotEffluent  == SET))                                  //@022
			{
				if((gu8_OperationStep == Z_OperationStep_11)                      //@017
				|| (gu8_OperationStep == Z_OperationStep_50))                     //@017
				{                                                                 //@017
					DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F;   
				}                                                                 //@017
				else                                                              //@017
				{                                                                 //@017
					DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_OFF;       //@017
				}                                                                 //@017
			}
			// if (F_FaucetChange_Display == SET)			//	ï¿½ï¿½ï¿½ï¿½ ifï¿½ï¿½ Ã³ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ÏºÎ·ï¿½ else if Ã³ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
			else if (F_FaucetChange_Display == SET)
			{
//				DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F;
				#if 0
				if (gu8_TimerChangeDisplay != 0)
				{
					DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F_S2;
				}
				#endif
				DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_ON;
			}
			else
			{

			}
#endif
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_DIMM;
//			break;
//		case LED_DIMM_LOW:
//			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_DIMM_LOW;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_ColdButton_Counter < 8)
			{
				DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if (INPUT_REED_SW_FAUCET == SET)
				{
					DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F;
				}
			}
			break;
		case LED_TOPCOVER:
			if (INPUT_REED_SW_FAUCET == CLEAR)
			{
				DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F;
			}
			else
			{
				DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_ON;
			}
			break;
		default:
			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = DisplayControl_Data[Z_LED_FAUCET].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_WIFI(void)
{
	U8 mu8_WifiDisp = 0;

	switch (DisplayControl_Data[Z_LED_WIFI].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
			mu8_WifiDisp = GetWifiStatusValue(WIFI_STATUS_DISP);
			switch (mu8_WifiDisp)
			{
				case WIFI_DISP_OFF:
					break;
				case WIFI_DISP_APMODE:
				case WIFI_DISP_AP_START:
				case WIFI_DISP_AP_STEP0:
				case WIFI_DISP_AP_STEP1:
				case WIFI_DISP_AP_STEP2:
				case WIFI_DISP_AP_STEP3:
					if(gu16_Timer_Pairing_Display_check != 0)
					{
						DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_APMODE;
					}
					else
					{
						if(gu8_Timer_Wifi_Pairing_Display_AfterEff != 0)
						{
							DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_APMODE;
						}
					}
					break;
				case WIFI_DISP_BLE_START:
				case WIFI_DISP_BLE_STEP0:
				case WIFI_DISP_BLE_STEP1:
				case WIFI_DISP_BLE_STEP2:
				case WIFI_DISP_BLE_STEP3:
					if(gu16_Timer_Pairing_Display_check != 0)
					{
						DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_APMODE;
					}
					else
					{
						if(gu8_Timer_Wifi_Pairing_Display_AfterEff != 0)
						{
							DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_APMODE;
						}
					}
					break;
				case WIFI_DISP_CONNECT:
					if ((gu8_OperationStep == Z_OperationStep_10) && (gu8_TimerSleepMode == 0))
					{
						//	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿??????? 1ï¿½Ã°ï¿½ ï¿½ï¿½ï¿??????? ï¿½Ã´ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
					}
					else
					{
						DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_ON;
					}
					break;
				default:
					DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_FADE_F;
					break;
			}
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_AmountButton_Counter < 2)
			{
				DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
		case LED_PBATEST:
			if (gu8_ModelType_forNational == MODEL_KOREA)
			{
				mu8_WifiDisp = GetWifiStatusValue(WIFI_STATUS_TEST);
				if (mu8_WifiDisp == SET)
				{
					DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_ON;
					F_WIFI_Pairing_forLineTest = SET;
				}
				else
				{
					DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_FADE_F;
				}
			}
			else									//	ï¿½Ïºï¿½ï¿½ï¿½ï¿½ï¿½ % LED ï¿½ï¿½ï¿½ï¿½
			{
				DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_ON;
			}
			break;
		case LED_FOTA:
			if (gu8_TimerFOTA_Display == 0)
			{
				if (F_FOTA_Display_forWIFI_LED_ONOFF == CLEAR)
				{
					F_FOTA_Display_forWIFI_LED_ONOFF = SET;
					gu8_TimerFOTA_Display = Z_TimerFOTA_Display;
				}
				else
				{
					F_FOTA_Display_forWIFI_LED_ONOFF = CLEAR;
					gu8_TimerFOTA_Display = Z_TimerFOTA_Display - 20;
				}
			}
			if (F_FOTA_Display_forWIFI_LED_ONOFF == SET)
			{
				DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_ON;
			}
			break;
		case LED_forSEG:
			//	SEG Data Ã³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ã³ï¿½ï¿½ï¿½ï¿½
			break;
		default:
			DisplayControl_Data[Z_LED_WIFI].Display_CMD = DisplayControl_Data[Z_LED_WIFI].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_FILTER_CHANGE(void)
{
	switch (DisplayControl_Data[Z_LED_FILTER_CHANGE].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
#ifdef _AFTER_LPP_IMDCHANGE_

			if (F_FilterChange_Display == SET)	//	ï¿½ï¿½ï¿½ï¿½ ifï¿½ï¿½ Ã³ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ÏºÎ·ï¿½ else if Ã³ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
			{
				#if 0
				if (gu8_TimerChangeDisplay != 0)
				{
					DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_FADE_F_S2;
				}
				#endif
				DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_ON;
			}
#endif
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_DIMM;
//			break;
//		case LED_DIMM_LOW:
//			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_DIMM_LOW;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_ColdButton_Counter < 7)
			{
				DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if (INPUT_REED_SW_FILTER == SET)
				{
					DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_FADE_F;
				}
			}
			break;
		case LED_TOPCOVER:
			if (INPUT_REED_SW_FILTER == CLEAR)
			{
				DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_FADE_F;
			}
			else
			{
				DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_ON;
			}
			break;
		default:
			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = DisplayControl_Data[Z_LED_FILTER_CHANGE].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_ML(void)
{
	switch (DisplayControl_Data[Z_LED_mL].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
			break;
		case LED_forSEG:
			//	SEG Data Ã³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ã³ï¿½ï¿½ï¿½ï¿½
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_mL].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_ColdButton_Counter < 4)
			{
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if(gu8_F_LineAuto_Faucet_MicroSW == SET)
				{
					DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;	
				}
				else
				{
					DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F;
				}
			}
			break;
		case LED_PBATEST:
			DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F;
			break;
		case LED_LINETEST2:

			if(F_LineTest2_FaucetMoving == SET)
			{
				if(gu8_F_LineAuto_Faucet_DownReed == SET)
				{
					DisplayControl_Data[Z_LED_mL].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F;				
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_mL].Display_CMD = LED_OFF;		
			}
			break;			
		default:
			DisplayControl_Data[Z_LED_mL].Display_CMD = DisplayControl_Data[Z_LED_mL].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_DEGREE(void)
{
	switch (DisplayControl_Data[Z_LED_DEGREE].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_FLIC;
//			break;
		case LED_STATUS:
			break;
		case LED_forSEG:
			//	SEG Data Ã³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ Ã³ï¿½ï¿½ï¿½ï¿½
			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_ColdButton_Counter < 6)
			{
				DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
			}
			break;
		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if(gu8_F_LineAuto_Faucet_MicroSW == SET)
				{
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;	
				}
				else
				{
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_FADE_F;
				}
			}
			break;
		case LED_PBATEST:
			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_FADE_F;
			break;
		case LED_LINETEST2:

			if(F_LineTest2_FaucetMoving == SET)
			{
				if(gu8_F_LineAuto_Faucet_DownReed == SET)
				{
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_FADE_F;				
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_OFF;		
			}
			break;			
		default:
			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = DisplayControl_Data[Z_LED_DEGREE].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_UV(void)
{
	U8 mu8_TotalPercent = 0;
	U8 mu8_UV_Step_Current = 0;

	switch (DisplayControl_Data[Z_LED_UV1].Operation_CMD)
	{
//		case LED_OFF:
//			break;
//		case LED_FADE_F:
//			DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FADE_F;
//			break;
//		case LED_FADE_F_S:
//			DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FADE_F_S;
//			DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FADE_F_S;
//			DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FADE_F_S;
//			DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FADE_F_S;
//			DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FADE_F_S;
//			break;
//		case LED_FLIC:
//			DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FLIC;
//			DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FLIC;
//			DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FLIC;
//			DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FLIC;
//			DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FLIC;
//			break;
		case LED_BOOT:
			DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_FADE_F;
			break;
//		case LED_DIMM:
//			DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_DIMM;
//			DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_DIMM;
//			DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_DIMM;
//			DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_DIMM;
//			DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_DIMM;
//			break;
//		case LED_ON:
//			DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//			DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//			DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
//			DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
//			DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
//			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_PureButton_Counter < 2)
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;				
			}
			else if (gu8_FrontTest_PureButton_Counter < 3)
			{
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;	
			}
			else if (gu8_FrontTest_PureButton_Counter < 4)
			{
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;	
			}
			else if (gu8_FrontTest_PureButton_Counter < 5)
			{
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;
			}
			else if (gu8_FrontTest_PureButton_Counter < 6)
			{
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;
			}
			else if (gu8_FrontTest_PureButton_Counter < 7)
			{
				DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;
			}
			else if (gu8_FrontTest_PureButton_Counter < 8)
			{
				DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;
			}
			else if (gu8_FrontTest_PureButton_Counter < 9)
			{
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;
			}
			else if (gu8_FrontTest_PureButton_Counter < 10)
			{
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;
			}
			else if (gu8_FrontTest_PureButton_Counter < 11)
			{
			}			
			else
			{

			}												
			break;
		case LED_FLU:
//			if (gu8_TimerFlushingDisplay == 0)
//			{
//				gu8_TimerFlushingDisplay = Z_TimerFlushingDisplay;
//			}
//
//			if (gu8_TimerFlushingDisplay > ((Z_TimerFlushingDisplay/8)*7))
//			{
//				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//			}
//			else if (gu8_TimerFlushingDisplay > ((Z_TimerFlushingDisplay/8)*6))
//			{
//				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//			}
//			else if (gu8_TimerFlushingDisplay > ((Z_TimerFlushingDisplay/8)*5))
//			{
//				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
//			}
//			else if (gu8_TimerFlushingDisplay > ((Z_TimerFlushingDisplay/8)*4))
//			{
//				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
//			}
//			else if (gu8_TimerFlushingDisplay > ((Z_TimerFlushingDisplay/8)*3))
//			{
//				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
//				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
//			}
//			else
//			{
//
//			}
			break;

		#if 0		//	UVï¿½ï¿½ï¿½ï¿½
		case LED_UVCARE1:
			if (gu16_TimerUV_Oper > ((Z_TimerUV_Oper/5)*4))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
			}
			else if (gu16_TimerUV_Oper > ((Z_TimerUV_Oper/5)*3))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
			}
			else if (gu16_TimerUV_Oper > ((Z_TimerUV_Oper/5)*2))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
			}
			else if (gu16_TimerUV_Oper > ((Z_TimerUV_Oper/5)*1))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			break;
		case LED_UVCARE2:
			if (gu16_TimerUV_Oper > ((Z_TimerUV_Oper_15min / 5) * 4))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
			}
			else if (gu16_TimerUV_Oper > ((Z_TimerUV_Oper_15min / 5) * 3))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
			}
			else if (gu16_TimerUV_Oper > ((Z_TimerUV_Oper_15min / 5) * 2))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
			}
			else if (gu16_TimerUV_Oper > ((Z_TimerUV_Oper_15min / 5) * 1))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
			}
			else
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			break;
		#endif

		case LED_STATUS:

			if(((gu8_OperationStep == Z_OperationStep_50) && ((gu8_WaterSelect == PURE_WATER) || (gu8_WaterSelect == COLD_WATER)))
			|| (gu16_TimerUV_Oper != 0))
			{
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;

				if (gu8_Timer_UV_Display == 0)
				{
					gu8_Timer_UV_Display = Z_TimerUVDisplay;
				}

				if (gu8_Timer_UV_Display > ((Z_TimerUVDisplay/7)*6))
				{
					if(gu8_F_UV_Display ==  CLEAR)
					{
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					}
					else
					{
						DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					}
				}
				else if (gu8_Timer_UV_Display > ((Z_TimerUVDisplay/7)*5))
				{
					if(gu8_F_UV_Display == CLEAR)
					{
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					}
					else
					{
						DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_DIMM_LOW;	
						DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;					
					}
				}
				else if (gu8_Timer_UV_Display > ((Z_TimerUVDisplay/7)*4))
				{
					if(gu8_F_UV_Display == CLEAR)
					{					
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
					}
					else
					{
						DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_DIMM_LOW;
						DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;						
					}
				}
				else if (gu8_Timer_UV_Display > ((Z_TimerUVDisplay/7)*3))
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
				}
				else if (gu8_Timer_UV_Display > ((Z_TimerUVDisplay/7)*2))
				{
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
				}
				else if (gu8_Timer_UV_Display > ((Z_TimerUVDisplay/7)*1))
				{
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;					
				}
				else
				{
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_DIMM_LOW;
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_DIMM_LOW;
					gu8_F_UV_Display = SET;
				}
			}
//			if (gu8_HotStep == Z_HotStep_02)
//			{
//				if (gu8_TimerFirstHotDisplay == 0)
//				{
//					gu8_TimerFirstHotDisplay = Z_TimerFirstHotDisplay;
//				}
//
//				if (gu8_TimerFirstHotDisplay > ((Z_TimerFirstHotDisplay/8)*7))
//				{
//					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//				}
//				else if (gu8_TimerFirstHotDisplay > ((Z_TimerFirstHotDisplay/8)*6))
//				{
//					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//				}
//				else if (gu8_TimerFirstHotDisplay > ((Z_TimerFirstHotDisplay/8)*5))
//				{
//					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
//				}
//				else if (gu8_TimerFirstHotDisplay > ((Z_TimerFirstHotDisplay/8)*4))
//				{
//					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
//				}
//				else if (gu8_TimerFirstHotDisplay > ((Z_TimerFirstHotDisplay/8)*3))
//				{
//					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
//				}
//				else if (gu8_TimerFirstHotDisplay > ((Z_TimerFirstHotDisplay/8)*2))
//				{
//					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
//					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
//				}
//				else
//				{
//
//				}
//			}
			break;
		case LED_SMART:
			if (gu16_TimerSmartCheckDisplay == 0)
			{
				gu16_TimerSmartCheckDisplay = Z_TimerSmartCheckDisplay;
			}

			if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*24))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*23))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*22))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*21))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*20))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*19))
			{
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*18))
			{
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*17))
			{
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*16))
			{
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*15))
			{

			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*14))
			{

			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*13))
			{

			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*12))
			{
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*11))
			{
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*10))
			{
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*9))
			{
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*8))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*7))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*6))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*5))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*4))
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*3))
			{

			}
			else if (gu16_TimerSmartCheckDisplay > ((Z_TimerSmartCheckDisplay/25)*2))
			{

			}
			else
			{

			}
			break;
		case LED_LINETEST:
			#if 0
			if (F_TestMode_LineAuto == CLEAR)
			{
				if (INPUT_REED_SW_FAUCET == CLEAR)
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FADE_F;
				}
				else
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				}
			}	
			#endif

			if(F_TestMode_LineAuto == CLEAR)
			{
				if((gu8_F_LineAuto_Faucet_DownReed == CLEAR)
				|| (gu8_F_LineAuto_Faucet_UpReed == CLEAR))
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_FADE_F;					
				}
				else
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;					

				}
			}
			else
			{

			}		
			break;
		case LED_PBATEST:
			#if 0
			if ((gu16_FlowDecide_Hz >= 200) && (gu16_FlowDecide_Hz <= 1000))
			{
				if (gu8_TimerFlowSensorTestDisplay == 0)
				{
					gu8_TimerFlowSensorTestDisplay = Z_TimerFlowSensorTestDisplay;
				}

				if (gu8_TimerFlowSensorTestDisplay > ((Z_TimerFlowSensorTestDisplay/8)*7))
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
				}
				else if (gu8_TimerFlowSensorTestDisplay > ((Z_TimerFlowSensorTestDisplay/8)*6))
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
				}
				else if (gu8_TimerFlowSensorTestDisplay > ((Z_TimerFlowSensorTestDisplay/8)*5))
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
				}
				else if (gu8_TimerFlowSensorTestDisplay > ((Z_TimerFlowSensorTestDisplay/8)*4))
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
				}
				else if (gu8_TimerFlowSensorTestDisplay > ((Z_TimerFlowSensorTestDisplay/8)*3))
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				}
				else if (gu8_TimerFlowSensorTestDisplay > ((Z_TimerFlowSensorTestDisplay/8)*2))
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
				}
				else
				{

				}
			}
			else
			{
				gu8_TimerFlowSensorTestDisplay = Z_TimerFlowSensorTestDisplay;
			}
			#endif

			if(gu8_PBATest_UV == SET)
			{
				if(gu8_PBATest_UV_FB_Error == SET)
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_FADE_F;
				}
				else
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;				
				}
			}
		
			break;
		case LED_VOLUME:
			if (gu8_Sound_Type > 1)
			{
				switch (gu8_VoiceVolumeLevel)
				{
					case 0:
					default:
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
						break;
					case 1:
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
						break;
					case 2:
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;
						break;
					case 3:
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;					
						DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
						break;
					case 4:
						DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;					
						DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
						DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;												
						break;
				}
			}
			break;
		case LED_LINETEST2:
			if(F_LineTest2_FaucetMoving == SET)
			{
				if(gu8_F_LineAuto_Faucet_MicroSW == SET)
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_ON;					
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_ON;
					DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_ON;	
				}
				else
				{
					DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_FADE_F;					
					DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_FADE_F;
					DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_FADE_F;	
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_OFF;					
				DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_OFF;
				DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_OFF;					
			}
			break;			
		default:
			DisplayControl_Data[Z_LED_UV1].Display_CMD = DisplayControl_Data[Z_LED_UV1].Operation_CMD;
			DisplayControl_Data[Z_LED_UV2].Display_CMD = DisplayControl_Data[Z_LED_UV2].Operation_CMD;
			DisplayControl_Data[Z_LED_UV3].Display_CMD = DisplayControl_Data[Z_LED_UV3].Operation_CMD;
			DisplayControl_Data[Z_LED_UV4].Display_CMD = DisplayControl_Data[Z_LED_UV4].Operation_CMD;
			DisplayControl_Data[Z_LED_UV5].Display_CMD = DisplayControl_Data[Z_LED_UV5].Operation_CMD;
			break;
	}
}

/// @brief
/// @param    void
/// @return   void
static void LED_HOTLOCK(void)
{
	switch (DisplayControl_Data[Z_LED_HOTLOCK].Operation_CMD)
	{
//			case LED_OFF:
//				break;
//			case LED_FADE_F:
//				DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_FADE_F;
//				break;
//			case LED_FADE_F_S:
//				DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_FADE_F_S;
//				break;
//			case LED_FLIC:
//				DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_FLIC;
//				break;
			case LED_STATUS:
				if (gu8_ModelType_forCHP == MODEL_CHP)
				{
					if (gu8_TimerHotLock_Display != 0)
					{
						DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_FADE_F;
					}
					else if (F_HotLock == SET)
					{
						DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_ON;
					}
				}
				break;
			case LED_BOOT:
				DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_FADE_F;
				break;
//			case LED_DIMM:
//				DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_DIMM;
//				break;
//			case LED_ON:
//				DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_ON;
//				break;
			case LED_FRONTTEST:
				if (gu8_FrontTest_HotButton_Counter < 2)
				{
					DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_ON;
				}
				break;
			case LED_LINETEST:
				if (F_TestMode_LineAuto == CLEAR)
				{
					if (F_LineFrontTest_Hot_Select == SET)
					{
						DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_ON;
					}
				}
				else
				{
				}
				break;
			case LED_ALL_LOCK:
				if (gu8_TimerAllLockDisplay != 0)
				{
					DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_FADE_F;
				}
				else
				{
					DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_ON;
				}
				break;
			default:
				DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = DisplayControl_Data[Z_LED_HOTLOCK].Operation_CMD;
				break;
	}



	#ifdef _FOR_RELIABILITY_CONDENSATION_PROGRAM_
		//	½Å·Ú¼º °á·Î ÇÁ·Î±×·¥
		if(gu8_F_gu16_reliability_test == SET)
		{
			DisplayControl_Data[Z_LED_UV1].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV2].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV3].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV4].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV5].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV6].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV7].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV8].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_UV9].Display_CMD = LED_FADE_F;
		}
	#endif
}

/// @brief
/// @param    void
/// @return   void
static void LED_PERCENT(void)
{
	switch (DisplayControl_Data[Z_LED_PERCENT].Operation_CMD)
	{
		case LED_BOOT:
			DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_FADE_F;
			break;
		case LED_FRONTTEST:
			if (gu8_FrontTest_ColdButton_Counter < 5)
			{
				DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_ON;
			}
			break;
		case LED_ON:
			DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_ON;
			break;

		case LED_LINETEST:
			if (F_TestMode_LineAuto == CLEAR)
			{
				if(gu8_F_LineAuto_Faucet_MicroSW == SET)
				{
					DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_ON;	
				}
				else
				{
					DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_FADE_F;
				}
			}
			break;

		case LED_LINETEST2:

			if(F_LineTest2_FaucetMoving == SET)
			{
				if(gu8_F_LineAuto_Faucet_DownReed == SET)
				{
					DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_ON;
				}
				else
				{
					DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_FADE_F;				
				}
			}
			else
			{
				DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_OFF;		
			}
			break;

		case LED_STATUS:
			if(gu8_Wifi_Pairing_State != WIFI_PAIRING_STEP_ERROR)					//	¿¡·¯ ¹ß»ý ¾ÈÇÑ°æ¿ì¿¡¸¸ %Ç¥½Ã
			{
				DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_ON;
			}
			break;

		default:
			break;
	}
}
