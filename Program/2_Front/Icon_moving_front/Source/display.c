/// @file     display.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    ??½? ??¾? °?·? file
#define DISPLAY_C
#include "include/_include.h"

#define Z_Fade_Select			(10)				//	Fade Timer 150ms
#define Z_ON_DimmingPercent		(100)				//	ON Dimming
#define Z_DimmingPercent		(40)				//	¾???°? ON
#define Z_DimmingPercent_Low	(10)				//	´? ¾???°?

static void LED_COLD(void);
static void LED_HOT(void);
static void LED_PURE(void);
static void LED_HOTLOCK(void);
static void LED_AMOUNT(void);
static void LED_WIFI(void);
static void LED_COLD_DEGREE(void);
static void LED_CUP(void);
static void LED_EFFLUENT(void);
static void LED_DEGREE(void);
static void LED_mL(void);
static void LED_FILTER_CHANGE(void);
static void LED_FAUCET(void);
static void LED_UV(void);
static void LED_TEMP_BAR(void);
static void LED_PERCENT(void);


static U8 LED_PWM(U8 led_data);

static void FadeSet(Display_Control *DisplayPnt, U8 PWM_Target, U8 Timer);

/// @brief    ??½?º? ??±??­
/// @param    void
/// @return   void
void Display_Initialize(void)
{
	gu8_Fade_Select = Z_Fade_Select;
	gu8_ON_DimmingPercent = Z_ON_DimmingPercent;
	gu8_DimmingPercent = Z_DimmingPercent;
	gu8_DimmingPercent_Low = Z_DimmingPercent_Low;
}

/// @brief    ??½?º? ??¾?
/// @param    void
/// @return   void
void DisplayControl(void)
{
	U8 i;

	for (i = 0 ; i < DisplayNum_Max ; i++)
	{
		DisplayControl_Data[i].Display_CMD = LED_OFF;
	}

	OperationDisplay();
}

/// @brief    ??½?º? ??¾?
/// @param    void
/// @return   void
void Seg_Control(void)
{
	gu8_ComPortChange++;							//	Com ???¼ ?????? ??°¡

	if (gu8_ComPortChange > Z_SOURCE_NUM)
	{
		gu8_ComPortChange = 1;						//		1·? ??±??­
	}

	SegAllOff();
	Delay_Nop(2);
	ComAllOff();
	Delay_Nop(5);

#ifndef _FRONT_LED_UP_
	switch (gu8_ComPortChange)
	{												//	Com ???¼??????¿¡ ??¶? Com On
		case 1:
			P_LED_SOURCE1 = 0;
			break;
		case 2:
			P_LED_SOURCE2 = 0;
			break;
		case 3:
			P_LED_SOURCE3 = 0;
			break;
		case 4:
			P_LED_SOURCE4 = 0;
			break;
		case 5:
			P_LED_SOURCE5 = 0;
			break;
		case 6:
			P_LED_SOURCE6 = 0;
			break;
		case 7:
			P_LED_SOURCE7 = 0;
			break;
		default:
			NOP();
			break;
	}
#else

	switch (gu8_ComPortChange)
	{												//	Com ???¼??????¿¡ ??¶? Com On
		case 1:
			P_LED_SINK1 = 1;
			P_LED_SINK2 = 0;
			P_LED_SINK3 = 0;
			break;
		case 2:
			P_LED_SINK1 = 0;
			P_LED_SINK2 = 1;
			P_LED_SINK3 = 0;
			break;
		case 3:
			P_LED_SINK1 = 0;
			P_LED_SINK2 = 0;
			P_LED_SINK3 = 1;
			break;
		default:
			NOP();
			break;
	}
#endif
}

/// @brief    ??½? ?????? ??·? ?³¸®
/// @param    void
/// @return   void
void DisplayOut(void)
{
#ifndef _FRONT_LED_UP_
	gu8_NewSegData[0].Bit.b0 = gu8_SegData[0].Bit.b0;
	gu8_NewSegData[1].Bit.b0 = gu8_SegData[0].Bit.b5;
	gu8_NewSegData[2].Bit.b0 = gu8_SegData[0].Bit.b4;
	gu8_NewSegData[3].Bit.b0 = gu8_SegData[0].Bit.b3;
	gu8_NewSegData[4].Bit.b0 = gu8_SegData[0].Bit.b2;
	gu8_NewSegData[5].Bit.b0 = gu8_SegData[0].Bit.b6;
	gu8_NewSegData[6].Bit.b0 = gu8_SegData[0].Bit.b1;

	gu8_NewSegData[0].Bit.b1 = gu8_SegData[1].Bit.b0;
	gu8_NewSegData[1].Bit.b1 = gu8_SegData[1].Bit.b5;
	gu8_NewSegData[2].Bit.b1 = gu8_SegData[1].Bit.b4;
	gu8_NewSegData[3].Bit.b1 = gu8_SegData[1].Bit.b3;
	gu8_NewSegData[4].Bit.b1 = gu8_SegData[1].Bit.b2;
	gu8_NewSegData[5].Bit.b1 = gu8_SegData[1].Bit.b6;
	gu8_NewSegData[6].Bit.b1 = gu8_SegData[1].Bit.b1;

	gu8_NewSegData[0].Bit.b2 = gu8_SegData[2].Bit.b0;
	gu8_NewSegData[1].Bit.b2 = gu8_SegData[2].Bit.b5;
	gu8_NewSegData[2].Bit.b2 = gu8_SegData[2].Bit.b4;
	gu8_NewSegData[3].Bit.b2 = gu8_SegData[2].Bit.b3;
	gu8_NewSegData[4].Bit.b2 = gu8_SegData[2].Bit.b2;
	gu8_NewSegData[5].Bit.b2 = gu8_SegData[2].Bit.b6;
	gu8_NewSegData[6].Bit.b2 = gu8_SegData[2].Bit.b1;
#endif

#ifndef _ALL_ON_
	if (DisplayPWM(DisplayControl_Data[Z_SEGMENT].Fade_PWM) == LED_ON)
	{
#ifndef _FRONT_LED_UP_
		P_LED_SINK3 = gu8_NewSegData[gu8_ComPortChange-1].Bit.b0;
		P_LED_SINK2 = gu8_NewSegData[gu8_ComPortChange-1].Bit.b1;
		P_LED_SINK1 = gu8_NewSegData[gu8_ComPortChange-1].Bit.b2;
#else
		P_LED_SOURCE1 = !gu8_SegData[gu8_ComPortChange-1].Bit.b0;
		P_LED_SOURCE2 = !gu8_SegData[gu8_ComPortChange-1].Bit.b1;
		P_LED_SOURCE3 = !gu8_SegData[gu8_ComPortChange-1].Bit.b2;
		P_LED_SOURCE4 = !gu8_SegData[gu8_ComPortChange-1].Bit.b3;
		P_LED_SOURCE5 = !gu8_SegData[gu8_ComPortChange-1].Bit.b4;
		P_LED_SOURCE6 = !gu8_SegData[gu8_ComPortChange-1].Bit.b5;
		P_LED_SOURCE7 = !gu8_SegData[gu8_ComPortChange-1].Bit.b6;
#endif
	}

	P_LED_EFFLUENT = DisplayPWM(DisplayControl_Data[Z_LED_EFFLUENT].Fade_PWM);
	P_LED_mL = DisplayPWM(DisplayControl_Data[Z_LED_mL].Fade_PWM);
	P_LED_FILTER_CHANGE = DisplayPWM(DisplayControl_Data[Z_LED_FILTER_CHANGE].Fade_PWM);
	P_LED_FAUCET = DisplayPWM(DisplayControl_Data[Z_LED_FAUCET].Fade_PWM);
	P_LED_INFINITY = DisplayPWM(DisplayControl_Data[Z_LED_CON].Fade_PWM);
	P_LED_1BOTTLE = DisplayPWM(DisplayControl_Data[Z_LED_1BOTTLE].Fade_PWM);
	P_LED_2CUP = DisplayPWM(DisplayControl_Data[Z_LED_2CUP].Fade_PWM);
	P_LED_1CUP = DisplayPWM(DisplayControl_Data[Z_LED_1CUP].Fade_PWM);
	P_LED_HALFCUP = DisplayPWM(DisplayControl_Data[Z_LED_HALFCUP].Fade_PWM);
	P_LED_DEGREE = DisplayPWM(DisplayControl_Data[Z_LED_DEGREE].Fade_PWM);
	P_LED_AMOUNT = DisplayPWM(DisplayControl_Data[Z_LED_AMOUNT].Fade_PWM);
	P_LED_COLD_BLUE = DisplayPWM(DisplayControl_Data[Z_LED_COLD_BLUE].Fade_PWM);
	P_LED_COLD_WHITE = DisplayPWM(DisplayControl_Data[Z_LED_COLD_WHITE].Fade_PWM);
	P_LED_COLD = DisplayPWM(DisplayControl_Data[Z_LED_COLD].Fade_PWM);
	P_LED_PURE = DisplayPWM(DisplayControl_Data[Z_LED_PURE].Fade_PWM);
	P_LED_HOT = DisplayPWM(DisplayControl_Data[Z_LED_HOT].Fade_PWM);
	P_LED_HOTLOCK = DisplayPWM(DisplayControl_Data[Z_LED_HOTLOCK].Fade_PWM);
	P_LED_WIFI = DisplayPWM(DisplayControl_Data[Z_LED_WIFI].Fade_PWM);
	P_LED_UV_LEFT_1 = DisplayPWM(DisplayControl_Data[Z_LED_UV1].Fade_PWM);	
	P_LED_UV_LEFT_2 = DisplayPWM(DisplayControl_Data[Z_LED_UV2].Fade_PWM);			
	P_LED_UV_LEFT_3 = DisplayPWM(DisplayControl_Data[Z_LED_UV3].Fade_PWM);	
	P_LED_UV_CENTER_1 = DisplayPWM(DisplayControl_Data[Z_LED_UV4].Fade_PWM);	
	P_LED_UV_CENTER_2 = DisplayPWM(DisplayControl_Data[Z_LED_UV5].Fade_PWM);	
	P_LED_UV_CENTER_3 = DisplayPWM(DisplayControl_Data[Z_LED_UV6].Fade_PWM);	
	P_LED_UV_RIGHT_1 = DisplayPWM(DisplayControl_Data[Z_LED_UV7].Fade_PWM);	
	P_LED_UV_RIGHT_2 = DisplayPWM(DisplayControl_Data[Z_LED_UV8].Fade_PWM);	
	P_LED_UV_RIGHT_3 = DisplayPWM(DisplayControl_Data[Z_LED_UV9].Fade_PWM);									
	P_LED_TEMP5 = DisplayPWM(DisplayControl_Data[Z_LED_HOT_BAR_5].Fade_PWM);	
	P_LED_TEMP4 = DisplayPWM(DisplayControl_Data[Z_LED_HOT_BAR_4].Fade_PWM);	
	P_LED_TEMP3 = DisplayPWM(DisplayControl_Data[Z_LED_HOT_BAR_3].Fade_PWM);	
	P_LED_TEMP2 = DisplayPWM(DisplayControl_Data[Z_LED_HOT_BAR_2].Fade_PWM);	
	P_LED_TEMP1 = DisplayPWM(DisplayControl_Data[Z_LED_HOT_BAR_1].Fade_PWM);	
	P_LED_PERCENT = DisplayPWM(DisplayControl_Data[Z_LED_PERCENT].Fade_PWM);	


#else

#endif

	gu8_PWM_Count++;								//	PWM ??¿?Æ® ??°¡
}

/// @brief    LED
/// @param    void
/// @return   void
U8 DisplayPWM(U8 PWM)
{
	if (PWM > gu8_DisplayPWM_Count_1ms)
	{
		return LED_ON;
	}
	else
	{
		return LED_OFF;
	}
}

/// @brief    ??·¹?? (?ns)
/// @param    void
/// @return   void
void Delay_Nop(U8 mu8_count)
{
	U8 mu8_i = 0;

	for (mu8_i = 0 ; mu8_i < mu8_count ; mu8_i++)
	{
	/****************************************************************************/
		NOP();NOP();NOP();NOP();NOP();			// SEG 반불 현상에 따른 NOP 추가 실시												//
		NOP();NOP();NOP();NOP();NOP();			// -> 3번째 SEG 표시값이 1번째 SEG에 반불로 표시되는 현상이 있었음.							//
		NOP();NOP();NOP();NOP();NOP();			//    Base 대비 디밍처리하는 LED 추가 등으로 인한 타이밍 틀어짐 문제라 보고 있음.				//
		NOP();NOP();NOP();NOP();NOP();			//    이에 따라 SEG와 COM OFF 후, NOP()처리와										//
		NOP();NOP();NOP();NOP();NOP();			//	  OperationDisplay() 함수 위치 변경을 통한 처리지연을 함.							//
		NOP();NOP();NOP();NOP();NOP();			//	  SEG와 COM OFF 후, ON 사이의 처리 지연 시간을 확보함으로서 해당 문제를 해결함.			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
		NOP();NOP();NOP();NOP();NOP();			//																			//
	/****************************************************************************/																//
	}
}

/// @brief    COM OFF
/// @param    void
/// @return   void
void ComAllOff(void)
{
	P_LED_SOURCE1 = 1;								  //
	P_LED_SOURCE2 = 1;                                //
	P_LED_SOURCE3 = 1;                                //
	P_LED_SOURCE4 = 1;                                //
	P_LED_SOURCE5 = 1;                                //
	P_LED_SOURCE6 = 1;                                //
	P_LED_SOURCE7 = 1;                                //
}

/// @brief    Data OFF
/// @param    void
/// @return   void
void SegAllOff(void)
{
	P_LED_SINK1 = 0;								// COM port OFF
	P_LED_SINK2 = 0;								// COM port OFF
	P_LED_SINK3 = 0;								// COM port OFF
}

/// @brief    Data Clear
/// @param    void
/// @return   void
void SegDataClear(void)
{
	U8 mu8_i;

	for (mu8_i = 0 ; mu8_i < 3 ; mu8_i++)	//	Seg ?????? °¹¼?¿¡ ??¶?
	{
		gu8_SegData[mu8_i].byte = 0x00;					//		clr
	}

	for (mu8_i = 0 ; mu8_i < Z_SOURCE_NUM ; mu8_i++)	//	Seg ?????? °¹¼?¿¡ ??¶?
	{
		gu8_NewSegData[mu8_i].byte = 0x00;					//		clr
	}
}

///// @brief    LED
///// @param    void
///// @return   void
//static void LED_ECONOMY(void)
//{
//	switch (DisplayControl_Data[Z_LED_FILTER].Operation_CMD)
//	{
//		case CMD_BOOT:
//			DisplayControl_Data[Z_LED_FILTER].Display_CMD = LED_FADE_F;
//			break;
//		case CMD_VER:
//			break;
//		case CMD_COMM_ER:
//			break;
//		case CMD_BY_MAIN:
//			DisplayControl_Data[Z_LED_FILTER].Display_CMD = gu8_Main_LED_FILTER;
//			break;
//		default:
//			break;
//	}
//}

static void Segment(void)
{
	switch (DisplayControl_Data[Z_LED_AMOUNT].Operation_CMD)
	{
		case CMD_BOOT:
			gu8_SegData[0].byte = DT_7seg[Z_NUM_8];
			gu8_SegData[1].byte = DT_7seg[Z_NUM_8];
			gu8_SegData[2].byte = DT_7seg[Z_NUM_8];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			#if 0
			gu8_SegData[0].byte = DT_7seg[Z_NUM_8];
			gu8_SegData[1].byte = DT_7seg[Z_NUM_8];
			gu8_SegData[2].byte = DT_7seg[Z_NUM_8];
			DisplayControl_Data[Z_SEGMENT].Display_CMD = LED_FADE_F;
			#endif
			break;
		case CMD_BY_MAIN:
//			gu8_SegData[0].byte = DT_7seg[gu8_Main_SEGMENT_OXX];
//			gu8_SegData[1].byte = DT_7seg[gu8_Main_SEGMENT_XOX];
//			gu8_SegData[2].byte = DT_7seg[gu8_Main_SEGMENT_XXO];
			gu8_SegData[0].byte = gu8_Main_SEGMENT_OXX;
			gu8_SegData[1].byte = gu8_Main_SEGMENT_XOX;
			gu8_SegData[2].byte = gu8_Main_SEGMENT_XXO;
			DisplayControl_Data[Z_SEGMENT].Display_CMD = gu8_Main_SEGMENT_CMD;
			break;
		default:
			break;
	}
}

/// @brief    LED
/// @param    void
/// @return   void
static void LED_AMOUNT(void)
{
	switch (DisplayControl_Data[Z_LED_AMOUNT].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
//			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = LED_FADE_F;
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_AMOUNT].Display_CMD = gu8_Main_LED_AMOUNT;
			break;
		default:
			break;
	}
}

/// @brief    LED
/// @param    void
/// @return   void
static void LED_COLD(void)
{
	switch (DisplayControl_Data[Z_LED_COLD].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
		    DisplayControl_Data[Z_LED_COLD].Display_CMD = LED_FADE_F;
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_COLD].Display_CMD = gu8_Main_LED_COLD;
			break;
		default:
			break;
	}
}

/// @brief    LED
/// @param    void
/// @return   void
static void LED_PURE(void)
{
	switch (DisplayControl_Data[Z_LED_PURE].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
		    DisplayControl_Data[Z_LED_PURE].Display_CMD = LED_FADE_F;
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_PURE].Display_CMD = gu8_Main_LED_PURE;
			break;
		default:
			break;
	}
}

/// @brief    LED
/// @param    void
/// @return   void
static void LED_HOT(void)
{
	switch (DisplayControl_Data[Z_LED_HOT].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
		    DisplayControl_Data[Z_LED_HOT].Display_CMD = LED_FADE_F;
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_HOT].Display_CMD = gu8_Main_LED_HOT;
			break;
		default:
			break;
	}
}

/// @brief    LED
/// @param    void
/// @return   void
static void LED_HOTLOCK(void)
{
	switch (DisplayControl_Data[Z_LED_HOTLOCK].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD = gu8_Main_LED_HOTLOCK;
			break;
		default:
			break;
	}
}

/****************************************
* Function Name : 	¿??? Bar LED ?³¸®
* param    		:	void
* return   		:	void
*****************************************/
static void LED_TEMP_BAR(void)
{
	switch (DisplayControl_Data[Z_LED_HOT_BAR_1].Operation_CMD)				//	¿???????º° ¿??? Bar LED ??½?¿¡ ??¶?
	{
		case CMD_COMM_ER:													//	??½? ¿¡·? ????
			DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = LED_OFF;
			DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = LED_OFF;
			DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = LED_OFF;
			DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = LED_OFF;
			DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = LED_OFF;
			break;

		case CMD_BY_MAIN:													//	¸Þ?? ??½? ????
			DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD = gu8_Main_Hot_TempBar_5;
			DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD = gu8_Main_Hot_TempBar_4;
			DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD = gu8_Main_Hot_TempBar_3;
			DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD = gu8_Main_Hot_TempBar_2;
			DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD = gu8_Main_Hot_TempBar_1;
			break;

		default:
			break;
	}
}


/// @brief    LED
/// @param    void
/// @return   void
static void LED_WIFI(void)
{
	switch (DisplayControl_Data[Z_LED_WIFI].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_WIFI].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_WIFI].Display_CMD = gu8_Main_LED_WIFI;
			break;
		case CMD_FOTA:
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
		default:
			break;
	}
}

/// @brief    LED
/// @param    void
/// @return   void
static void LED_COLD_DEGREE(void)
{
	switch (DisplayControl_Data[Z_LED_COLD_BLUE].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD = gu8_Main_LED_COLD_BLUE;
			DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD = gu8_Main_LED_COLD_WHITE;
			break;
		default:
			break;
	}
}

///// @brief    LED
///// @param    void
///// @return   void
//static void LED_CUPSIZE(void)
//{
//	switch (DisplayControl_Data[Z_LED_HALFCUP].Operation_CMD)
//	{
//		case CMD_BOOT:
//			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_FADE_F;
//			DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_FADE_F;
//			break;
//		case CMD_VER:
//			break;
//		case CMD_COMM_ER:
//			break;
//		case CMD_BY_MAIN:
//			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = gu8_Main_LED_0_5L;
//			DisplayControl_Data[Z_LED_1CUP].Display_CMD = gu8_Main_LED_1L;
//			DisplayControl_Data[Z_LED_2CUP].Display_CMD = gu8_Main_LED_CON;
//			break;
//		default:
//			break;
//	}
//}

/// @brief    LED
/// @param    void
/// @return   void
static void LED_CUP(void)
{
	switch (DisplayControl_Data[Z_LED_2CUP].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = LED_FADE_F;			
			DisplayControl_Data[Z_LED_2CUP].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_1CUP].Display_CMD = LED_FADE_F;
			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_CON].Display_CMD = gu8_Main_LED_CON;
			DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD = gu8_Main_LED_1Bottle;			
			DisplayControl_Data[Z_LED_2CUP].Display_CMD = gu8_Main_LED_2CUP;
			DisplayControl_Data[Z_LED_1CUP].Display_CMD = gu8_Main_LED_1CUP;
			DisplayControl_Data[Z_LED_HALFCUP].Display_CMD = gu8_Main_LED_HALFCUP;
			break;
		default:
			break;
	}
}

static void LED_EFFLUENT(void)
{
	switch (DisplayControl_Data[Z_LED_EFFLUENT].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD = gu8_Main_LED_EFFLUENT;
			break;
		default:
			break;
	}
}

static void LED_DEGREE(void)
{
	switch (DisplayControl_Data[Z_LED_DEGREE].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_DEGREE].Display_CMD = gu8_Main_LED_DEGREE;
			break;
		default:
			break;
	}
}

static void LED_mL(void)
{
	switch (DisplayControl_Data[Z_LED_mL].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_mL].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_mL].Display_CMD = gu8_Main_LED_mL;
			break;
		default:
			break;
	}
}

static void LED_FILTER_CHANGE(void)
{
	switch (DisplayControl_Data[Z_LED_FILTER_CHANGE].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD = gu8_Main_LED_FILTER_CHANGE;
			break;
		default:
			break;
	}
}

static void LED_FAUCET(void)
{
	switch (DisplayControl_Data[Z_LED_FAUCET].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_FAUCET].Display_CMD = gu8_Main_LED_FAUCET;
			break;
		default:
			break;
	}
}

static void LED_UV(void)
{
	switch (DisplayControl_Data[Z_LED_UV1].Operation_CMD)
	{
		case CMD_BOOT:
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
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_UV1].Display_CMD = gu8_Main_LED_UV1;
			DisplayControl_Data[Z_LED_UV2].Display_CMD = gu8_Main_LED_UV2;
			DisplayControl_Data[Z_LED_UV3].Display_CMD = gu8_Main_LED_UV3;
			DisplayControl_Data[Z_LED_UV4].Display_CMD = gu8_Main_LED_UV4;
			DisplayControl_Data[Z_LED_UV5].Display_CMD = gu8_Main_LED_UV5;
			DisplayControl_Data[Z_LED_UV6].Display_CMD = gu8_Main_LED_UV6;
			DisplayControl_Data[Z_LED_UV7].Display_CMD = gu8_Main_LED_UV7;
			DisplayControl_Data[Z_LED_UV8].Display_CMD = gu8_Main_LED_UV8;
			DisplayControl_Data[Z_LED_UV9].Display_CMD = gu8_Main_LED_UV9;																												
			break;
		default:
			break;
	}
}

static void LED_PERCENT(void)
{
	switch (DisplayControl_Data[Z_LED_PERCENT].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_PERCENT].Display_CMD = LED_FADE_F;			
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_PERCENT].Display_CMD = gu8_Main_Percent;
			break;
		default:
			break;
	}	
}


static void LED_MY(void)
{
	switch (DisplayControl_Data[Z_LED_CON].Operation_CMD)
	{
		case CMD_BOOT:
			DisplayControl_Data[Z_LED_CON].Display_CMD = LED_FADE_F;
			break;
		case CMD_VER:
			break;
		case CMD_COMM_ER:
			break;
		case CMD_BY_MAIN:
			DisplayControl_Data[Z_LED_CON].Display_CMD = gu8_Main_LED_CON;
			break;
		default:
			break;
	}
}

/// @brief    LED PWM ?¶??
/// @param    void
/// @return   void
static U8 LED_PWM(U8 led_data)
{
	U8 mu8_ret = OFF;

	if (gu8_PWM_Count >= 10)						//	LED PWM ??´? 10ms
	{
		gu8_PWM_Count = 0;							//		PWM ??¿?Æ® clr
	}

	if (led_data == 0)								//	LED OFF?? °æ¿?
	{
		mu8_ret = OFF;								//		OFF ??½?
	}
	else
	{
		if (gu8_PWM_Count < led_data)				//		??½? ¼?¸¸?­ PWM Duty ¼³?¤	(0º??? ½?????¹?·? º????? < )
		{
			mu8_ret = ON;
		}
		else
		{
			mu8_ret = OFF;
		}
	}

	return (mu8_ret);
}

/// @brief    ¿???????¿¡ ??¸? ??½?
/// @param    void
/// @return   void
void OperationDisplay(void)
{
	U8 i, mu8_DimmingPercent, mu8_DimmingPercent_Low, mu8_ON_DimmingPercent = 0;
	static U8 FadeSlow_Direction = 0;

	if (gu8_TimerFlic <= 50)
	{
		gu8_Fade_F_PWM = (U8)(Z_DisplayPWM * (gu8_TimerFlic * 2) / 100);	//	¼­¼­?÷ ²¨??°?
	}
	else
	{
		if (100 >= gu8_TimerFlic)
		{
			gu8_Fade_F_PWM = (U8)(Z_DisplayPWM * ((100 - gu8_TimerFlic) * 2) / 100);		//	¼­¼­?÷ ????°?
		}
	}

	if (gu8_TimerFlic == 0)
	{
		FadeSlow_Direction ^= 1;
	}
	if (FadeSlow_Direction == 1)
	{
		if (100 >= gu8_TimerFlic)
		{
			gu8_Fade_F_PWM_Slow = (U8)(Z_DisplayPWM * (100 - gu8_TimerFlic) / 100);	//	¼­¼­?÷ ????°?
		}
	}
	else
	{
		gu8_Fade_F_PWM_Slow = (U8)(Z_DisplayPWM * (gu8_TimerFlic) / 100);	//	¼­¼­?÷ ²¨??°?
	}

	if (F_LED_Flicker != SET)						//	?¡¸? ??½?°¡ ¾ø´? °æ¿?
	{
		gu8_TimerFlic = 100;						//		?¡¸? ?¸??¸? set
	}
	else											//	?¡¸? ??½?°¡ ??´? °æ¿?
	{
		if (gu8_TimerFlic == 0)						//		?¡¸? ?¸??¸? °æ°? ½?
		{
			gu8_TimerFlic = 100;					//			?¡¸??¸??¸? ??±??­ (1??)
		}
	}

	/*	1.5?? ??±? ?¡¸? ?¸??¸? °?¸®	*/
	if (gu8_TimerFlic_S2 <= 75)
	{
		gu8_Fade_F_PWM_Slow_S2 = (U8)(10 * (gu8_TimerFlic_S2 * 2) / 150);	//	¼­¼­?÷ ²¨??°?
	}
	else
	{
		if (150 >= gu8_TimerFlic_S2)
		{
			gu8_Fade_F_PWM_Slow_S2 = (U8)(10 * ((150 - gu8_TimerFlic_S2) * 2) / 150);	//	¼­¼­?÷ ????°?
		}
	}

	if (F_LED_Flicker_S2 != SET)					//	?¡¸? ??½?°¡ ¾ø´? °æ¿?
	{
		gu8_TimerFlic_S2 = 150;						//		?¡¸? ?¸??¸? set
	}
	else											//	?¡¸? ??½?°¡ ??´? °æ¿?
	{
		if (gu8_TimerFlic_S2 == 0)					//		?¡¸? ?¸??¸? °æ°? ½?
		{
			gu8_TimerFlic_S2 = 150;					//			?¡¸??¸??¸? ??±??­ (1.5??)
		}
	}
	/*	...		*/

	Segment();
	LED_COLD();
	LED_HOT();
	LED_PURE();
	LED_HOTLOCK();
	LED_AMOUNT();
	LED_WIFI();
	LED_COLD_DEGREE();
	LED_CUP();
	LED_EFFLUENT();
	LED_DEGREE();
	LED_mL();
	LED_FILTER_CHANGE();
	LED_FAUCET();
	LED_UV();
	LED_TEMP_BAR();
	LED_PERCENT();

	F_LED_Flicker = CLEAR;
	F_LED_Flicker_S2 = CLEAR;

	mu8_ON_DimmingPercent = (U8)((U16)Z_DisplayPWM * gu8_ON_DimmingPercent / 100);
	mu8_DimmingPercent = (U8)((U16)Z_DisplayPWM * gu8_DimmingPercent / 100);
	mu8_DimmingPercent_Low = (U8)((U16)Z_DisplayPWM * gu8_DimmingPercent_Low / 100);

	for (i = 0 ; i < DisplayNum_Max ; i++)
	{		
		if (DisplayControl_Data[i].Display_CMD == LED_ON)
		{
			if (gu8_Main_OperationStep == 0x10)
			{
				if ((i == Z_LED_HALFCUP) && (DisplayControl_Data[Z_LED_HALFCUP].Display_CMD == LED_ON) && (DisplayControl_Data[Z_LED_1CUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_2CUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_CON].Display_CMD == LED_OFF))
				{
					if ((DisplayControl_Data[Z_LED_1CUP].Fade_PWM > 0) || (DisplayControl_Data[Z_LED_2CUP].Fade_PWM > 0) || (DisplayControl_Data[Z_LED_CON].Fade_PWM > 0))
					{
						FadeSet(&DisplayControl_Data[Z_LED_1CUP], 0, 0);
						FadeSet(&DisplayControl_Data[Z_LED_2CUP], 0, 0);
						FadeSet(&DisplayControl_Data[Z_LED_CON], 0, 0);
					}
				}
				else if ((i == Z_LED_1CUP) && (DisplayControl_Data[Z_LED_HALFCUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_1CUP].Display_CMD == LED_ON) && (DisplayControl_Data[Z_LED_2CUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_CON].Display_CMD == LED_OFF))
				{
					if ((DisplayControl_Data[Z_LED_HALFCUP].Fade_PWM > 0) || (DisplayControl_Data[Z_LED_2CUP].Fade_PWM > 0) || (DisplayControl_Data[Z_LED_CON].Fade_PWM > 0))
					{
						FadeSet(&DisplayControl_Data[Z_LED_HALFCUP], 0, 0);
						FadeSet(&DisplayControl_Data[Z_LED_2CUP], 0, 0);
						FadeSet(&DisplayControl_Data[Z_LED_CON], 0, 0);
					}
				}
				else if ((i == Z_LED_2CUP) && (DisplayControl_Data[Z_LED_HALFCUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_1CUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_2CUP].Display_CMD == LED_ON) && (DisplayControl_Data[Z_LED_CON].Display_CMD == LED_OFF))
				{
					if ((DisplayControl_Data[Z_LED_HALFCUP].Fade_PWM > 0) || (DisplayControl_Data[Z_LED_1CUP].Fade_PWM > 0) || (DisplayControl_Data[Z_LED_CON].Fade_PWM > 0))
					{
						FadeSet(&DisplayControl_Data[Z_LED_HALFCUP], 0, 0);
						FadeSet(&DisplayControl_Data[Z_LED_1CUP], 0, 0);
						FadeSet(&DisplayControl_Data[Z_LED_CON], 0, 0);
					}
				}
				else if ((i == Z_LED_CON) && (DisplayControl_Data[Z_LED_HALFCUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_1CUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_2CUP].Display_CMD == LED_OFF) && (DisplayControl_Data[Z_LED_CON].Display_CMD == LED_ON))
				{
					FadeSet(&DisplayControl_Data[Z_LED_HALFCUP], 0, 0);
					FadeSet(&DisplayControl_Data[Z_LED_1CUP], 0, 0);
					FadeSet(&DisplayControl_Data[Z_LED_2CUP], 0, 0);
				}
				else if (DisplayControl_Data[i].Display_CMD_Before == LED_OFF)
				{
					FadeSet(&DisplayControl_Data[i], Z_DisplayPWM, gu8_Fade_Select);
				}
	//			else if (DisplayControl_Data[i].Display_CMD_Before == LED_DIMM)
				else if ((DisplayControl_Data[i].Display_CMD_Before == LED_DIMM) || (DisplayControl_Data[i].Display_CMD_Before == LED_DIMM_LOW))
				{
					FadeSet(&DisplayControl_Data[i], Z_DisplayPWM, gu8_Fade_Select);
				}
			}
		}
		else if (DisplayControl_Data[i].Display_CMD == LED_OFF)
		{
			/*	¿?±?º??? ¹°¾? ¹???/????/???? LED ?¿½?¿¡ ²¨??°?²? ±¸????±? ?§??
			 * (ex:100%¡æ0%¶? 20%¡æ0%·? ¶³¾???´? ¼???°¡ ´Þ¶?¼­ ´?°? ²¨??´? °??³·³ º¸¿´?½)
			 * ±×·¡¼­ 100%??¸®°¡ 20%±??? ??±?±??? ³ª¸??? 20%LED???º ±?´?¸²
			 * */
			if (gu8_Main_OperationStep == 0x10)
			{
				if (((i == Z_LED_HALFCUP) || (i == Z_LED_1CUP) || (i == Z_LED_2CUP) || (i == Z_LED_CON))
					&& (DisplayControl_Data[Z_LED_HALFCUP].Display_CMD == LED_OFF)
					&& (DisplayControl_Data[Z_LED_1CUP].Display_CMD == LED_OFF)
					&& (DisplayControl_Data[Z_LED_2CUP].Display_CMD == LED_OFF)
					&& (DisplayControl_Data[Z_LED_CON].Display_CMD == LED_OFF))
				{
					if ((DisplayControl_Data[Z_LED_HALFCUP].Fade_PWM < Z_DisplayPWM)
						&& (DisplayControl_Data[Z_LED_1CUP].Fade_PWM < Z_DisplayPWM)
						&& (DisplayControl_Data[Z_LED_2CUP].Fade_PWM != 0)
						&& (DisplayControl_Data[Z_LED_CON].Fade_PWM == 0))			//	MY ¾?¾? ??
					{
						if (DisplayControl_Data[Z_LED_2CUP].Fade_PWM < mu8_DimmingPercent)
						{
							FadeSet(&DisplayControl_Data[i], 0, gu8_Fade_Select);
						}
						else
						{
							DisplayControl_Data[i].Fade_Timer_Target = 10;

							if (i != Z_LED_2CUP)
							{
								FadeSet(&DisplayControl_Data[i], mu8_DimmingPercent, gu8_Fade_Select);
							}
						}
					}
					else if ((DisplayControl_Data[Z_LED_HALFCUP].Fade_PWM < Z_DisplayPWM)
						&& (DisplayControl_Data[Z_LED_1CUP].Fade_PWM < Z_DisplayPWM)
						&& (DisplayControl_Data[Z_LED_2CUP].Fade_PWM < Z_DisplayPWM)
						&& (DisplayControl_Data[Z_LED_CON].Fade_PWM != 0))			//	MY ¾? ¶§
					{

						if (DisplayControl_Data[Z_LED_CON].Fade_PWM < mu8_DimmingPercent)
						{
							FadeSet(&DisplayControl_Data[i], 0, gu8_Fade_Select);
						}
						else
						{
							DisplayControl_Data[i].Fade_Timer_Target = 10;

							if (i != Z_LED_CON)
							{
								FadeSet(&DisplayControl_Data[i], mu8_DimmingPercent, gu8_Fade_Select);
							}
						}
					}
					else
					{

					}
				}
			}			
			/*	¿?±?±???	*/

			if (gu8_Main_OperationStep == 0x92)			//	??·ÐÆ® ??±× ?×½ºÆ®¸ð??
			{
				if (DisplayControl_Data[i].Display_CMD_Before == LED_ON)
				{
					FadeSet(&DisplayControl_Data[i], 0, 5);
				}
//				else if (DisplayControl_Data[i].Display_CMD_Before == LED_DIMM)
				else if ((DisplayControl_Data[i].Display_CMD_Before == LED_DIMM) || (DisplayControl_Data[i].Display_CMD_Before == LED_DIMM_LOW))
				{
					FadeSet(&DisplayControl_Data[i], 0, 5);
				}
			}
			else
			{
				if (DisplayControl_Data[i].Display_CMD_Before == LED_ON)
				{
					if ((i == Z_LED_mL) || (i == Z_LED_DEGREE))
					{
						FadeSet(&DisplayControl_Data[i], 0, 0);
					}
					else
					{
						FadeSet(&DisplayControl_Data[i], 0, gu8_Fade_Select);
					}
				}
//				else if (DisplayControl_Data[i].Display_CMD_Before == LED_DIMM)
				else if ((DisplayControl_Data[i].Display_CMD_Before == LED_DIMM) || (DisplayControl_Data[i].Display_CMD_Before == LED_DIMM_LOW))
				{
					FadeSet(&DisplayControl_Data[i], 0, gu8_Fade_Select);
				}
			}			
		}
		else if (DisplayControl_Data[i].Display_CMD == LED_DIMM)
		{
			if (DisplayControl_Data[i].Display_CMD_Before == LED_ON)
			{
				FadeSet(&DisplayControl_Data[i], mu8_DimmingPercent, gu8_Fade_Select);
			}
			else if (DisplayControl_Data[i].Display_CMD_Before == LED_OFF)
			{
				FadeSet(&DisplayControl_Data[i], mu8_DimmingPercent, gu8_Fade_Select);
			}
		}
		else if (DisplayControl_Data[i].Display_CMD == LED_DIMM_LOW)
		{
			if (DisplayControl_Data[i].Display_CMD_Before == LED_ON)
			{
				FadeSet(&DisplayControl_Data[i], mu8_DimmingPercent_Low, gu8_Fade_Select);
			}
			else if (DisplayControl_Data[i].Display_CMD_Before == LED_OFF)
			{
				FadeSet(&DisplayControl_Data[i], mu8_DimmingPercent_Low, gu8_Fade_Select);
			}
		}
		else
		{

		}		

		if (DisplayControl_Data[i].Fade_Timer_Target == 0)
		{
			switch (DisplayControl_Data[i].Display_CMD)
			{
				case LED_OFF:
					DisplayControl_Data[i].Fade_PWM = 0;
					break;
				case LED_ON:
					if (i == 0)
					{
						DisplayControl_Data[i].Fade_PWM = Z_DisplayPWM;
					}
					else
					{
						DisplayControl_Data[i].Fade_PWM = mu8_ON_DimmingPercent;
					}
					break;
				case LED_DIMM:
					DisplayControl_Data[i].Fade_PWM = mu8_DimmingPercent;
					break;
				case LED_DIMM_LOW:
					DisplayControl_Data[i].Fade_PWM = mu8_DimmingPercent_Low;
					break;
				case LED_FLIC:
					F_LED_Flicker = SET;
					if (gu8_TimerFlic <= 50)
					{
						DisplayControl_Data[i].Fade_PWM = 0;
					}
					else
					{
						DisplayControl_Data[i].Fade_PWM = Z_DisplayPWM;
					}
					break;
				case LED_FADE_F_S:
					F_LED_Flicker = SET;
					DisplayControl_Data[i].Fade_PWM = gu8_Fade_F_PWM_Slow;	//	?????÷ ¼­¼­?÷ ????°?
					break;
				case LED_FADE_F_S2:
					F_LED_Flicker_S2 = SET;
					DisplayControl_Data[i].Fade_PWM = gu8_Fade_F_PWM_Slow_S2;	//	?????÷ ¼­¼­?÷ ????°?
					break;
				case LED_FADE_F:
				case LED_BOOT:
					F_LED_Flicker = SET;
					DisplayControl_Data[i].Fade_PWM = gu8_Fade_F_PWM;		//	¼­¼­?÷ ????°?
					break;
				case LED_APMODE:
					F_LED_Flicker = SET;
					if (gu8_TimerFlic >= 90)
					{
						DisplayControl_Data[i].Fade_PWM = Z_DisplayPWM;
					}
					else if (gu8_TimerFlic >= 80)
					{
						DisplayControl_Data[i].Fade_PWM = 0;
					}
					else if (gu8_TimerFlic >= 70)
					{
						DisplayControl_Data[i].Fade_PWM = Z_DisplayPWM;
					}
					else
					{
						DisplayControl_Data[i].Fade_PWM = 0;
					}
					break;
				default:
					break;
			}
		}

		DisplayControl_Data[i].Display_CMD_Before = DisplayControl_Data[i].Display_CMD;
	}
}

/// @brief    Fade ¼³?¤
/// @param    void
/// @return   void
static void FadeSet(Display_Control *DisplayPnt, U8 PWM_Target, U8 Timer)
{
	if (DisplayPnt->Fade_PWM != PWM_Target)
	{
		DisplayPnt->Fade_PWM_Target = PWM_Target;
		DisplayPnt->Fade_Timer_Target = Timer;
	}
}

/// @brief    Fade ?³¸®
/// @param    void
/// @return   void
void FadeProcess(void)
{
	U8 i;
	for (i = 0 ; i < DisplayNum_Max ; i++)
	{
		if (DisplayControl_Data[i].Fade_Timer_Target != 0)
		{
			if (DisplayControl_Data[i].Fade_PWM != DisplayControl_Data[i].Fade_PWM_Target)
			{
				if (DisplayControl_Data[i].Fade_Timer == 0)
				{
					DisplayControl_Data[i].Fade_Timer = DisplayControl_Data[i].Fade_Timer_Target;
					if (DisplayControl_Data[i].Fade_PWM > DisplayControl_Data[i].Fade_PWM_Target)
					{
						DisplayControl_Data[i].Fade_PWM--;
					}
					else
					{
						DisplayControl_Data[i].Fade_PWM++;
					}
				}
			}
			else
			{
				DisplayControl_Data[i].Fade_Timer_Target = 0;
			}
		}
	}
}
