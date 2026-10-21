/// @file     description_mode.c
/// @date     2025.01.XX
/// @author   
/// @brief    Description Mode 처리 file
#define DESCRIPTION_MODE_C
#include "include/_include.h"

static void DescriptionMode_Common(void);
static void DescriptionMode_Water_Cup_SelectTimer(U8* address);

//	전역 변수 정의
// U8 gu8_F_Start_DescriptionMode;
// U8 gu8_DescriptionModeStep;
// U8 gu8_DescriptionModeStepNum;
// U16 gu16_TimerDescriptionMode_100ms;
// U16 gu16_TimerDescriptionMode_MoveDisplay;
// U16 gu16_TimerDescriptionMode_20s;

Operation_StepTable DescriptionMode_Step[Z_DescriptionModeStepNum_Max] =
{
	//	스텝 No			 	Segment			추출LED			온수LED			정수LED			냉수LED			용량LED			온수잠금LED		CUP LED			냉수온도LED		WIFI LED		파우셋 LED		필터 교체 LED		mL LED			℃ LED			PERCENT LED      UV LED			HOT BAR			Step Func.
	{ Z_DescriptionModeStep_10, 	SEG_ML,			LED_ON, 		LED_STATUS, 	LED_STATUS, 	LED_STATUS, 	LED_STATUS, 	LED_STATUS, 	LED_STATUS, 	LED_STATUS, 	LED_STATUS,		LED_STATUS,		LED_STATUS,		LED_forSEG, 	LED_forSEG, 	LED_OFF,		LED_OFF,		LED_STATUS,		DescriptionModeStep_10},
	{ Z_DescriptionModeStep_15, 	SEG_ON_FLIC,	LED_ON, 		LED_STATUS, 	LED_STATUS, 	LED_FADE_F, 	LED_STATUS, 	LED_STATUS, 	LED_OFF, 		LED_FADE_F,	 	LED_STATUS,		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_OFF,		LED_OFF,		DescriptionModeStep_15},
	{ Z_DescriptionModeStep_16, 	SEG_OFF_DISP,	LED_ON, 		LED_STATUS, 	LED_STATUS, 	LED_OFF_DISP, 	LED_STATUS, 	LED_STATUS, 	LED_OFF, 		LED_OFF, 		LED_STATUS,		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_OFF,		LED_OFF,		DescriptionModeStep_16},
	{ Z_DescriptionModeStep_17, 	SEG_ONOFF_MOVE,	LED_ON, 		LED_STATUS, 	LED_STATUS, 	LED_STATUS, 	LED_STATUS, 	LED_STATUS, 	LED_OFF, 		LED_STATUS, 	LED_STATUS,		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_OFF,		LED_OFF,		DescriptionModeStep_17},
	{ Z_DescriptionModeStep_18, 	SEG_OFF_FLIC,	LED_ON, 		LED_STATUS, 	LED_STATUS, 	LED_FADE_F, 	LED_STATUS, 	LED_STATUS, 	LED_OFF, 		LED_OFF, 		LED_STATUS,		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_OFF,		LED_OFF,		DescriptionModeStep_18},
	{ Z_DescriptionModeStep_20, 	SEG_OFF,		LED_DIMM, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_OFF,		LED_OFF,		DescriptionModeStep_20},
	{ Z_DescriptionModeStep_40, 	SEG_OFF,		LED_DIMM, 		LED_ALL_LOCK, 	LED_ALL_LOCK,	LED_DIMM, 		LED_OFF, 		LED_ALL_LOCK,	LED_OFF, 		LED_STATUS, 	LED_STATUS,		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_OFF,		LED_OFF,		DescriptionModeStep_40},
	{ Z_DescriptionModeStep_41, 	SEG_SOUND,		LED_OFF, 		LED_SOUND, 		LED_DIMM,		LED_DIMM, 		LED_SOUND, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_STATUS,		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_VOLUME,		LED_OFF,		DescriptionModeStep_41},
	{ Z_DescriptionModeStep_43, 	SEG_MOVING,		LED_OFF, 		LED_ON, 		LED_OFF, 		LED_OFF, 		LED_ON, 		LED_OFF, 		LED_FAUCET_MODE, LED_OFF, 		LED_OFF,		LED_OFF,		LED_OFF,		LED_OFF, 		LED_OFF, 		LED_OFF,		LED_OFF,		LED_OFF,		DescriptionModeStep_43},
};

/// @brief    Description Mode 초기화
/// @param    void
/// @return   void
void DescriptionMode_Initialize(void)
{
	return_default_cup();					//	용량을 default로 복귀
	gu8_DescriptionModeStep = Z_DescriptionModeStep_10;
	gu8_DescriptionModeStepNum = Z_DescriptionModeStepNum_10;
	gu16_TimerDescriptionMode_100ms = 0;
	gu16_TimerDescriptionMode_MoveDisplay = 0;
	gu16_TimerDescriptionMode_20s = 0;
}

/// @brief    Description Mode 제어
/// @param    void
/// @return   void
void Description__Mode(void)
{
	/**************************************************************************
	 * Description Mode 종료 조건 (아래 조건 중 하나라도 만족 시 종료)
	 * 1. 에러 발생 시 (gu8_ErrorCode != 0)
	 * 2. 프론트 커버가 열렸을 때 (INPUT_REED_SW_COVER == CLEAR)
	 * 3. operation.c에서 B0 스텝으로 이동했을 때 (gu8_OperationStep == Z_OperationStep_B0)
	 * 4. 20초 동안 shortkey 입력이 없을 때 (gu16_TimerDescriptionMode_20s == 0)
	 **************************************************************************/

	//	operation.c 03 스텝 이상 10 스텝 미만 and 초기 플러싱 안 끝났을 때 KEY_STE_KITMODE_LONG으로 description flag on/off
	if ((gu8_OperationStep >= Z_OperationStep_03) && (gu8_OperationStep < Z_OperationStep_10) 
		&& ((F_FirstFlushing == CLEAR) || (F_Heater_Fill == CLEAR) || (F_ColdTank_Fill == CLEAR)))
	{
		if (KEY_STE_KITMODE_LONG == SET)
		{
			gu8_F_Start_DescriptionMode ^= 1;
			if (gu8_F_Start_DescriptionMode == SET)
			{
				// Description mode 시작 시 초기화, 20초 타이머 설정 및 설정음 출력
				DescriptionMode_Initialize();
				gu16_TimerDescriptionMode_20s = Z_TimerDescriptionMode_100ms_20s;
				Play_Voice(VOICE_BEEP_ON);
			}
			else
			{
				// Description mode 종료 시 초기화 및 해제음 출력
				DescriptionMode_Initialize();
				Play_Voice(VOICE_BEEP_OFF);
			}
		}
	}
	else
	{
		// 플러싱 완료 후 일반 모드(10 스텝 이상)로 전환 시 description mode 초기화
		if (gu8_F_Start_DescriptionMode == SET)
		{
			gu8_F_Start_DescriptionMode = CLEAR;
			DescriptionMode_Initialize();
		}
	}
	
    //  설명모드 시작
	if (gu8_F_Start_DescriptionMode == CLEAR)
    {
        return;
    }

	/*	1. 에러 발생 시 description mode 종료
	 *	조건: gu8_ErrorCode != 0
	 */
	if (gu8_ErrorCode != 0)
	{
		gu8_F_Start_DescriptionMode = CLEAR;	//	description mode 종료
		DescriptionMode_Initialize();			//	초기화
		return;
	}
	
	/*	2. 프론트 커버 열림 시 또는 B0 스텝으로 이동했을 때 description mode 종료
	 *	조건: INPUT_REED_SW_COVER == CLEAR 또는 gu8_OperationStep == Z_OperationStep_B0
	 */
	if ((INPUT_REED_SW_COVER == CLEAR) || (gu8_OperationStep == Z_OperationStep_B0))
	{
		gu8_F_Start_DescriptionMode = CLEAR;	//	description mode 종료
		DescriptionMode_Initialize();			//	초기화
		return;
	}

	/*	3. 20초 타이머 체크 및 shortkey/longkey 입력 처리
	 *	조건: gu8_Key_Short.byte != 0x00 (shortkey 입력이 들어오면) 또는 gu32_LongKeyArray.LONG != 0x0000U (longkey 입력이 들어오면)
	 */
	if ((gu8_Key_Short.byte != 0x00) || (gu32_LongKeyArray.LONG != 0x0000U))	//	shortkey 또는 longkey 입력이 들어오면
	{
		gu16_TimerDescriptionMode_20s = Z_TimerDescriptionMode_100ms_20s;	//	20초 타이머 리셋
	}
	
	/*	4. 20초 경과 시 description mode 종료
	 *	조건: gu16_TimerDescriptionMode_20s == 0 (20초 경과 시)
	 */
	if (gu16_TimerDescriptionMode_20s == 0)	//	20초 경과 시
	{
		gu8_F_Start_DescriptionMode = CLEAR;	//	description mode 종료
		DescriptionMode_Initialize();			//	초기화
		return;
	}

	if (gu8_DescriptionModeStepNum < Z_DescriptionModeStepNum_Max)	//	스텝 허용 범위 이내
	{
		(DescriptionMode_Step[gu8_DescriptionModeStepNum].exe)();	//		해당 스텝 함수 실행

		DisplayControl_Data[Z_SEGMENT].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].SEGMENT;
		DisplayControl_Data[Z_LED_EFFLUENT].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].EFFLUENT;
		DisplayControl_Data[Z_LED_HOT].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].HOT_LED;
		DisplayControl_Data[Z_LED_PURE].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].PURE_LED;
		DisplayControl_Data[Z_LED_COLD].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].COLD_LED;
		DisplayControl_Data[Z_LED_AMOUNT].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].AMOUNT_LED;
		DisplayControl_Data[Z_LED_HOTLOCK].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].HOT_LOCK;
		DisplayControl_Data[Z_LED_COLD_BLUE].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].COLD_TEMP_LED;
		DisplayControl_Data[Z_LED_COLD_WHITE].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].COLD_TEMP_LED;
		DisplayControl_Data[Z_LED_2CUP].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].CUP_LED;
		DisplayControl_Data[Z_LED_1CUP].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].CUP_LED;
		DisplayControl_Data[Z_LED_CON].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].CUP_LED;
		DisplayControl_Data[Z_LED_HALFCUP].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].CUP_LED;
		DisplayControl_Data[Z_LED_WIFI].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].WIFI_LED;
		DisplayControl_Data[Z_LED_FILTER_CHANGE].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].FILTER_CLEAN_LED;
		DisplayControl_Data[Z_LED_FAUCET].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].CHANGE_ALRAM_LED;
		DisplayControl_Data[Z_LED_mL].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].ML_LED;
		DisplayControl_Data[Z_LED_DEGREE].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].DEGREE_LED;
		DisplayControl_Data[Z_LED_PERCENT].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].PERCENT;	
		DisplayControl_Data[Z_LED_UV1].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;
		DisplayControl_Data[Z_LED_UV2].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;
		DisplayControl_Data[Z_LED_UV3].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;
		DisplayControl_Data[Z_LED_UV4].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;
		DisplayControl_Data[Z_LED_UV5].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;
		DisplayControl_Data[Z_LED_UV6].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;
		DisplayControl_Data[Z_LED_UV7].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;
		DisplayControl_Data[Z_LED_UV8].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;
		DisplayControl_Data[Z_LED_UV9].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].UV_LED;		

		DisplayControl_Data[Z_LED_HOT_BAR_1].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].HOT_BAR_LED;	
		DisplayControl_Data[Z_LED_HOT_BAR_2].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].HOT_BAR_LED;	
		DisplayControl_Data[Z_LED_HOT_BAR_3].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].HOT_BAR_LED;	
		DisplayControl_Data[Z_LED_HOT_BAR_4].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].HOT_BAR_LED;	
		DisplayControl_Data[Z_LED_HOT_BAR_5].Operation_CMD = DescriptionMode_Step[gu8_DescriptionModeStepNum].HOT_BAR_LED;	
	}
}

/// @brief    대기
/// @param    void
/// @return   void
void DescriptionModeStep_10(void)
{
	DescriptionMode_Common();
}
void Ini_DescriptionModeStep_10(void)
{
	F_First_Set = SET;
	F_KITMode = CLEAR;
	DescriptionMode_Water_Cup_SelectTimer(&gu8_TimerWaterSelect);
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_10);
}

/// @brief    ON 표시
/// @param    void
/// @return   void
void DescriptionModeStep_15(void)
{
	if (gu16_TimerDescriptionMode_100ms == 0)
	{
		Ini_DescriptionModeStep_10();
	}
	else if (gu8_Key_Short.byte != 0x00)
	{
		Ini_DescriptionModeStep_10();
	}
	else
	{

	}
}
void Ini_DescriptionModeStep_15(void)
{
	gu16_TimerDescriptionMode_100ms = Z_TimerDescriptionMode_100ms_2s;
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_15);
}

/// @brief    냉수 OFF 표시
/// @param    void
/// @return   void
void DescriptionModeStep_16(void)
{
	DescriptionMode_Common();

	if (gu16_TimerDescriptionMode_100ms == 0)
	{
		gu8_WaterSelect = PURE_WATER;
		Ini_DescriptionModeStep_10();
	}
	else if (gu8_Key_Short.byte != 0x00)
	{
		if (gu8_DescriptionModeStep == Z_DescriptionModeStep_16)
		{
			if (KEY_COLDWATER_SHORT == SET)
			{
				Ini_DescriptionModeStep_16();
			}
			else
			{
				Ini_DescriptionModeStep_10();
			}
		}
	}
}
void Ini_DescriptionModeStep_16(void)
{
	gu8_TimerOFF_Flic = Z_TimerOFF_Flic;
	gu16_TimerDescriptionMode_100ms = Z_TimerDescriptionMode_100ms_7s;
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_16);
}

/// @brief    파우셋 ON/OFF 설정 표시
/// @param    void
/// @return   void
void DescriptionModeStep_17(void)
{
	if (gu16_TimerDescriptionMode_MoveDisplay == 0)
	{
		F_SleepMode_Display = CLEAR;
		F_ColdOff_Display = CLEAR;
		Ini_DescriptionModeStep_10();
	}
	else
	{

	}
}
void Ini_DescriptionModeStep_17(void)
{
	gu16_TimerDescriptionMode_MoveDisplay = Z_TimerMoveDisplay;
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_17);
}

/// @brief    OFF 표시
/// @param    void
/// @return   void
void DescriptionModeStep_18(void)
{
	if (gu16_TimerDescriptionMode_100ms == 0)
	{
		Ini_DescriptionModeStep_10();
	}
	else if (gu8_Key_Short.byte != 0x00)
	{
		Ini_DescriptionModeStep_10();
	}
	else
	{

	}
}
void Ini_DescriptionModeStep_18(void)
{
	gu16_TimerDescriptionMode_100ms = Z_TimerDescriptionMode_100ms_2s;
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_18);
}

/// @brief    슬립모드
/// @param    void
/// @return   void
void DescriptionModeStep_20(void)
{
	if (gu8_Key_Short.byte != 0x00U)
	{
		gu8_TimerSleepMode = Z_TimerSleepMode;
		Ini_DescriptionModeStep_10();
		Play_Voice(VOICE_BEEP_SELECT);
	}
	#if 0		//	UV관리
	else if (gu8_TimerUV_6h == 0)
	{
		Ini_DescriptionModeStep_31();
	}
	#endif
	else
	{

	}
}
void Ini_DescriptionModeStep_20(void)
{
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_20);
}

/// @brief    전체 잠금
/// @param    void
/// @return   void
void DescriptionModeStep_40(void)
{
    if (((gu8_ModelType_forCHP == MODEL_CHP) && (KEY_ALL_LOCK_LONG == SET))
			|| ((gu8_ModelType_forCHP == MODEL_CP) && (KEY_HOTWATER_LONG == SET)))
	{
		F_VeryLongKey_Rejection = SET;
		F_AllLock = CLEAR;
		Play_Voice(VOICE_ALL_LOCK_CLEAR);
		Ini_DescriptionModeStep_10();
	}
	else if (gu8_Key_Short.byte != 0x00)
	{
		gu8_TimerAllLockDisplay = Z_TimerAllLockDisplay;
		if (gu8_ModelType_forCHP == MODEL_CHP)
		{
			Play_Voice(VOICE_ALL_LOCK_ICON22);
		}
		else
		{
			Play_Voice(VOICE_ALL_LOCK_CHECK_CP);
		}
	}
	else if (F_AllLock == CLEAR)
	{
		Ini_DescriptionModeStep_10();
	}
	#if 0		//	UV관리
	else if (gu8_TimerUV_6h == 0)
	{
		Ini_DescriptionModeStep_31();
	}
	#endif
	else
	{

	}
}
void Ini_DescriptionModeStep_40(void)
{
	gu8_WaterSelect = PURE_WATER;
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_40);
}

/// @brief    사운드 타입
/// @param    void
/// @return   void
void DescriptionModeStep_41(void)
{
	if ((gu8_Key_Short.byte != 0) || (gu8_DigitalInput_Key1.Level.byte != 0))
	{
		gu16_TimerDescriptionMode_100ms = Z_TimerDescriptionMode_100ms_7s;
	}

	if (gu16_TimerDescriptionMode_100ms == 0)
	{
		Play_Voice(VOICE_BEEP_ON);
		Ini_DescriptionModeStep_10();
	}
	else if (KEY_SOUND_TYPE_LONG == SET)
	{
		if (gu8_Sound_Type == 1)
		{
			gu8_Sound_Type = 3;
		}
		else
		{
			gu8_Sound_Type--;
		}

		switch (gu8_Sound_Type)
		{
			case 1:
			default:
				Play_Voice(VOICE_SETTING_SILENT);
				break;
			case 2:
				Play_Voice(VOICE_SETTING_MELODY);
				break;
			case 3:
				Play_Voice(VOICE_SETTING_VOICE);
				break;
		}
	}
	else if (KEY_HOTWATER_SHORT == SET)
	{
		if (gu8_Sound_Type > 1)
		{
			if (gu8_VoiceVolumeLevel > 0)
			{
				gu8_VoiceVolumeLevel--;
			}
			Play_Voice(VOICE_BEEP_SELECT);
			gu8_TimerSoundChange = Z_TimerSoundChange;
		}
	}
	else if (KEY_AMOUNT_SHORT == SET)
	{
		if (gu8_Sound_Type > 1)
		{
			if (gu8_VoiceVolumeLevel < 4)
			{
				gu8_VoiceVolumeLevel++;
			}
			Play_Voice(VOICE_BEEP_SELECT);
			gu8_TimerSoundChange = Z_TimerSoundChange;
		}
	}
	else if (KEY_EFFLUENT_SHORT == SET)
	{
		Play_Voice(VOICE_BEEP_WARNING);
		Ini_DescriptionModeStep_10();
	}
	else if (gu8_Key_Short.byte != 0x00)
	{
		Play_Voice(VOICE_BEEP_WARNING);
	}
	else
	{

	}
}
void Ini_DescriptionModeStep_41(void)
{
	gu16_TimerDescriptionMode_100ms = Z_TimerDescriptionMode_100ms_7s;
	if (gu8_Sound_Type == 1)
	{
		gu8_Sound_Type = 3;
	}
	else
	{
		gu8_Sound_Type--;
	}
	switch (gu8_Sound_Type)
	{
		case 1:
		default:
			Play_Voice(VOICE_SETTING_SILENT);
			break;
		case 2:
			Play_Voice(VOICE_SETTING_MELODY);
			break;
		case 3:
			Play_Voice(VOICE_SETTING_VOICE);
			break;
	}
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_41);
}

/// @brief    파우셋 ON/OFF
/// @param    void
/// @return   void
void DescriptionModeStep_43(void)
{
	if(gu8_Timer_Moving_OnOff_Display == 0)
	{
		if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_AUTO_LEVEL)
		{
			Play_Voice(VOICE_FAUCET_SET_AUTO_MOVING);
		}
		else
		{
			Play_Voice(VOICE_FAUCET_MOVING_POSITION_FIXED);
		}

		Ini_DescriptionModeStep_10();		
	}
	else if(KEY_HOTWATER_SHORT == SET)
	{
		gu8_F_FaucetMoving_Set_Level_Way = 1;

		if(gu16_FaucetMovingPulse == 0)
		{
			if(--gu8_FaucetMoving_Set_Level < Z_FAUCET_MOVING_AUTO_LEVEL)
			{
				gu8_FaucetMoving_Set_Level = Z_FAUCET_MOVING_FIX_5_LEVEL;
			}

			gu8_Timer_Moving_OnOff_Display = 70;	
			Play_Voice(VOICE_BEEP_SELECT);		
		}
		else
		{
			Play_Voice(VOICE_BEEP_WARNING);
		}	
	}
	else if(KEY_AMOUNT_SHORT == SET)
	{
		gu8_F_FaucetMoving_Set_Level_Way = 0;

		if(gu16_FaucetMovingPulse == 0)
		{
			if(++gu8_FaucetMoving_Set_Level > Z_FAUCET_MOVING_FIX_5_LEVEL)
			{
				gu8_FaucetMoving_Set_Level = Z_FAUCET_MOVING_AUTO_LEVEL;
			}
			
			gu8_Timer_Moving_OnOff_Display = 70;
			Play_Voice(VOICE_BEEP_SELECT);		
		}
		else
		{
			Play_Voice(VOICE_BEEP_WARNING);			
		}			
	}	
	else
	{

	}
}
void Ini_DescriptionModeStep_43(void)
{
	gu8_Timer_Faucet_Set_Mode_Display = 120;
	Play_Voice(VOICE_ENTER_FAUCET_MOVING_SET_MODE);
	gu8_Timer_Moving_OnOff_Display = 70;
	DescriptionModeStepNoSet(Z_DescriptionModeStepNum_43);
}

/// @brief    Description Mode Step No Set
/// @param    data - Step Number
/// @return   void
void DescriptionModeStepNoSet(U8 data)
{
	static const U8 DT_DescriptionModeNumber[]
	= {
		Z_DescriptionModeStep_10,
		Z_DescriptionModeStep_15,
		Z_DescriptionModeStep_16,
		Z_DescriptionModeStep_17,
		Z_DescriptionModeStep_18,
		Z_DescriptionModeStep_20,
		Z_DescriptionModeStep_40,
		Z_DescriptionModeStep_41,
		Z_DescriptionModeStep_43,
	};
	/************************************************/
	gu8_DescriptionModeStepNum = data; /*	스텝 번호 set*/

	if (data < (sizeof(DT_DescriptionModeNumber) / sizeof(DT_DescriptionModeNumber[0])))
	{
		gu8_DescriptionModeStep = DT_DescriptionModeNumber[data]; /*	Description Mode No. set*/
	}
	else
	{
		gu8_DescriptionModeStep = Z_DescriptionModeStep_10; /*	범위 초과 시 기본값 */
	}
}

/// @brief    Description Mode Common
/// @param    void
/// @return   void
static void DescriptionMode_Common(void)
{
    if (F_AllLock == SET)						//	전체잠금이 켜진 경우
	{
		Ini_DescriptionModeStep_40();
	}
	else if ((F_SleepMode == SET) && (gu8_TimerSleepMode == 0))
	{
		Ini_DescriptionModeStep_20();
	}
	else if (KEY_SLEEPMODE_LONG == SET)
	{
		F_SleepMode ^= 1;
		F_SleepMode_Display = SET;
		Ini_DescriptionModeStep_17();
		if (F_SleepMode == SET)
		{
			Play_Voice(VOICE_BEEP_ON);
		}
		else
		{
			Play_Voice(VOICE_BEEP_OFF);
		}
	}
	else if (KEY_SOUND_TYPE_LONG == SET)
	{
		Ini_DescriptionModeStep_41();
	}
	else if(KEY_MOVING_SET_MODE_PBA_TEST == SET)
	{
		Ini_DescriptionModeStep_43();
	}
	else if (KEY_COLDWATER_SHORT == SET)		//	냉수버튼
	{
		F_HotDegreeDisplay = CLEAR;
		if (F_ColdOff == SET)					//		냉수 OFF인 경우
		{
			Ini_DescriptionModeStep_16();				//			OFF표시
			Play_Voice(VOICE_COLD_OFF_CHECK);
		}
		else									//		냉각 ON
		{
			gu8_DefaultWaterSelect = COLD_WATER;
			Play_Voice(VOICE_BEEP_SELECT);
		}
		gu8_WaterSelect = COLD_WATER;
		DescriptionMode_Water_Cup_SelectTimer(&gu8_TimerWaterSelect);    //			물선택 타이머 set
	}
	else if ((KEY_COLDWATER_VERYLONG == SET)
	&& (F_ColdOff == CLEAR))					//	ON -> OFF 7초
	{
		F_ColdOff ^= 1;
		if (F_ColdOff == CLEAR)
		{
			Ini_DescriptionModeStep_15();
			Play_Voice(VOICE_COLD_ON_SETTING);
		}
		else
		{
			Ini_DescriptionModeStep_18();
			gu8_WaterSelect = PURE_WATER;
			gu8_DefaultWaterSelect = PURE_WATER;
			Play_Voice(VOICE_COLD_OFF_SETTING);
		}
	}	
	else if ((KEY_COLDWATER_LONG == SET)
	&& (F_ColdOff == SET))					//	OFF -> ON 3초
	{
		F_ColdOff ^= 1;
		if (F_ColdOff == CLEAR)
		{
			Ini_DescriptionModeStep_15();
			Play_Voice(VOICE_COLD_ON_SETTING);
		}
		else
		{
			Ini_DescriptionModeStep_18();
			gu8_WaterSelect = PURE_WATER;
			gu8_DefaultWaterSelect = PURE_WATER;
			Play_Voice(VOICE_COLD_OFF_SETTING);
		}
	}
	else if (KEY_HOTWATER_SHORT == SET)
	{
		if (gu8_ModelType_forCHP == MODEL_CHP)
		{
			if (F_HotLock == SET)
			{
				gu8_TimerHotLock_Display = Z_TimerHotLock_Display;
				Play_Voice(VOICE_HOT_LOCK_CHECK);
			}
			else
			{
				if (F_OverHeatError == CLEAR)
				{
					if (gu8_WaterSelect == HOT_WATER)
					{
						if (F_FirstHotEffluent == SET)
						{
#ifndef _HOT_TEMP_4STEP_
							if (++gu8_HotTempSetup > HOT_TEMP_SETUP_KOR45_JPX)
							{
								gu8_HotTempSetup = HOT_TEMP_SETUP_KOR85_JP80;
							}
#else
							if (F_HotDegreeDisplay == CLEAR)
							{
								F_HotDegreeDisplay = SET;
							}
							else
							{
								if (F_HotWater_100Degree == SET)
								{
									if(gu8_f_hot_temp_sorting == Z_HOT_TEMP_ASCENDING)				//	오름 차순		
									{
										gu8_hot_water_select_index++;

										if(gu8_hot_water_select_index > (gu8_select_hot_temp_total_count - 1))		//	최대 갯수
										{
											gu8_hot_water_select_index = 0;
										}

										gu8_HotTempSetup = selected_hot_temp[gu8_hot_water_select_index];
									}
									else																//	내림차순
									{
										if(gu8_hot_water_select_index != 0)
										{
											gu8_hot_water_select_index--;
										}	
										else
										{
											gu8_hot_water_select_index = gu8_select_hot_temp_total_count - 1;
										}

										gu8_HotTempSetup = selected_hot_temp[gu8_hot_water_select_index];
									}
								}
								else
								{
									if (gu8_HotTempSetup > HOT_TEMP_SETUP_KOR45_JPX)
									{
										gu8_HotTempSetup--;
									}
									else
									{
										gu8_HotTempSetup = HOT_TEMP_SETUP_KOR85_JP80;
									}
								}
							}
#endif
							Play_Voice(VOICE_BEEP_SELECT);
						}
						else									//	온수 선택 중에 and 첫잔 미완료 상태에서 온수버튼 누를 경우
						{
#ifndef _KOREA_NEW_VOICE_
							Play_Voice(VOICE_BEEP_WARNING);
#else
							Play_Voice(VOICE_HOTWATER_FIRST);	//
#endif
						}
					}
					else
					{
						gu8_WaterSelect = HOT_WATER;
						F_HotDegreeDisplay = SET;
						return_default_hot_temp_setup();
						Play_Voice(VOICE_BEEP_SELECT);
					}
					DescriptionMode_Water_Cup_SelectTimer(&gu8_TimerWaterSelect);
				}
				else
				{
					gu8_TimerOverHeatDisplay = Z_TimerOverHeatDisplay;
					Play_Voice(VOICE_BEEP_WARNING);
				}
				gu8_TimerHotTest_DegreeDisplay = 0;
			}
		}
		else
		{
			Play_Voice(VOICE_BEEP_SELECT);
		}
	}
	else if ((gu8_ModelType_forCHP == MODEL_CHP) && (KEY_HOTWATER_LONG == SET))
	{
		F_HotLock ^= 1;
		if (F_HotLock == CLEAR)					//			온수 잠금상태가 아니면
		{
			gu8_WaterSelect = HOT_WATER;
			F_HotDegreeDisplay = SET;
			Play_Voice(VOICE_HOT_LOCK_CLEAR);
		}
		else
		{
			gu8_WaterSelect = PURE_WATER;
			Play_Voice(VOICE_HOT_LOCK_SETTING);
		}
		DescriptionMode_Water_Cup_SelectTimer(&gu8_TimerWaterSelect);    //			물선택 타이머 set
	}
	else if (KEY_PUREWATER_SHORT == SET)
	{
		F_HotDegreeDisplay = CLEAR;
		gu8_WaterSelect = PURE_WATER;
		gu8_DefaultWaterSelect = PURE_WATER;
		DescriptionMode_Water_Cup_SelectTimer(&gu8_TimerWaterSelect);
		Play_Voice(VOICE_BEEP_SELECT);
	}
	else if (KEY_AMOUNT_SHORT == SET)
	{
		U8 search_ok = 0;
		U8 mu8_i = 0;
		
		gu8_TimerDefaultCupSize_Set_LEDFlic = 0;	//		디폴트설정 점멸타이머 clear

		if (gu8_TimerSleepMode == 0)
		{
			Play_Voice(VOICE_BEEP_SELECT);
		}
		else
		{
			if ((gu8_WaterSelect == HOT_WATER) && (F_FirstHotEffluent == CLEAR))
			{
				gu16_CupSize = CUPSIZE_HALFCUP;
				Play_Voice(VOICE_BEEP_WARNING);
			}
			else
			{
				if (gu8_ModelType_forNational == MODEL_KOREA)
				{
					if ((gu8_WaterSelect == HOT_WATER) && (F_HotDegreeDisplay == SET))
					{
						F_HotDegreeDisplay = CLEAR;
					}
					else
					{	
						for(mu8_i = 0; mu8_i < CUPSIZE_FIVE; mu8_i++)  // 최대 5번만 검색
						{
							if (++gu8_CupIndex > CUPSIZE_FIVE)
							{
								gu8_CupIndex = CUPSIZE_ONE;
							}
							
							if(gu8_Cup_size_Array[gu8_CupIndex].enable == 1)
							{
								search_ok = 1;
								break;
							}
						}

						if(search_ok == 0)
						{
							gu8_CupIndex = 0;
						}

						
						if(gu8_CupIndex != CUPSIZE_FIVE)		//	연속 아니면..
						{
							gu16_CupSize = (U16)gu8_Cup_size_Array[gu8_CupIndex].amount_volume * 10;		//	x 10
						}
						else
						{
							gu16_CupSize = CUPSIZE_CONTINUE;			//	연속은 0xAA로...
						}

						gu8_F_CupSize_FineAdjust = SET;
					}
					Play_Voice(VOICE_BEEP_SELECT);
				}
				else										//	일본향
				{
					gu8_TimerCupSize_LEDFlic_forJAPAN_Limit = 0;
					if ((gu8_WaterSelect == HOT_WATER) && (F_HotDegreeDisplay == SET))
					{
						F_HotDegreeDisplay = CLEAR;
					}
					else
					{
						if (F_CupSize_MySet == CLEAR)
						{
							if (++gu16_CupSize > CUPSIZE_CONTINUE)
							{
								gu16_CupSize = CUPSIZE_HALFCUP;
							}
						}
						else
						{
							if (++gu16_CupSize > CUPSIZE_MY)
							{
								gu16_CupSize = CUPSIZE_HALFCUP;
							}
						}
					}
					Play_Voice(VOICE_BEEP_SELECT);
				}
			}
		}
		
		DescriptionMode_Water_Cup_SelectTimer(&gu8_TimerCupSelect);
	}
	else if (KEY_AMOUNT_LONG == SET)
	{
		if (gu16_CupSize != CUPSIZE_CONTINUE)
		{
			gu8_DefaultCupSize = gu8_CupIndex;
			gu8_TimerDefaultCupSize_Set_LEDFlic = Z_TimerDefaultCupSize_Set_LEDFlic;	//		물양 설정 점멸
			gu8_TimerCupSelect = Z_TimerCupSelect;    //		물양 설정 시 7-Seg 점등을 위하여 타이머 set
			Play_Voice(VOICE_BEEP_ON);
		}
		else
		{
			Play_Voice(VOICE_BEEP_WARNING);
		}
	}
	else if (((gu8_ModelType_forCHP == MODEL_CHP) && (KEY_ALL_LOCK_LONG == SET))		//@008 
			|| ((gu8_ModelType_forCHP == MODEL_CP) && (KEY_HOTWATER_LONG == SET)))		//@008 
	{																					//@008 
		F_VeryLongKey_Rejection = SET;													//@008 
		F_AllLock = SET;																//@008 
		Play_Voice(VOICE_ALL_LOCK_SETTING_A);                        //@008
		Ini_DescriptionModeStep_40();                                                   //@008
	}	                                                                                //@008
	else if (KEY_WIFI_ONOFF_LONG == SET)
	{
		if (gu8_ModelType_forNational == MODEL_KOREA)
		{
			WifiKey(WIFI_KEY_ONOFF);
		}
		else
		{
			Play_Voice(VOICE_BEEP_WARNING);
		}
	}
	#if 0  //@008
	else if (KEY_WIFI_AP_PAIRING_LONG == SET)
	{
		if (gu8_ModelType_forNational == MODEL_KOREA)
		{
			WifiKey(WIFI_KEY_AP);
			gu8_WifiError = GetWifiStatusValue(WIFI_STATUS_ERROR);
			if (gu8_WifiError != 0)
			{
				gu8_TimerWifiErrorDisplay = Z_TimerWifiErrorDisplay;
			}
		}
		else
		{
			Play_Voice(VOICE_BEEP_WARNING);
		}
	}
	else if(GetWifiStatusValue(WIFI_STATUS_BLE_CERT) == SET)
	{
		if (KEY_PUREWATER_LONG == SET)
		{
			WifiKey(WIFI_KEY_BLE);
		}
	}
	else if (KEY_PUREWATER_LONG == SET)
	{
		if (gu8_ModelType_forNational == MODEL_KOREA)
		{
			WifiKey(WIFI_KEY_BLE);
			gu8_WifiError = GetWifiStatusValue(WIFI_STATUS_ERROR);
			if (gu8_WifiError != 0)
			{
				gu8_TimerWifiErrorDisplay = Z_TimerWifiErrorDisplay;
			}
		}
		else
		{
			Play_Voice(VOICE_BEEP_WARNING);
		}
	}
	#endif
	else if (KEY_EFFLUENT_SHORT == SET)
	{
		Play_Voice(VOICE_BEEP_WARNING);
	}
	else
	{

	}
}

/// @brief    물/컵 선택 타이머
/// @param    address - 타이머 주소
/// @return   void
static void DescriptionMode_Water_Cup_SelectTimer(U8* address)
{
	if (address == &gu8_TimerWaterSelect)			//	물 선택 타이머인 경우
	{
		gu8_TimerWaterSelect = Z_TimerWaterSelect;	//		물 선택 타이머 set
		if (gu8_TimerCupSelect != 0)				//		컵 선택이 7초 남아있는 경우
		{
			gu8_TimerCupSelect = Z_TimerCupSelect;	//			7초 reset
		}
	}
	else											//	컵 선택 타이머인 경우
	{
		gu8_TimerCupSelect = Z_TimerCupSelect;		//		컵 선택 타이머 set
		if (gu8_TimerWaterSelect != 0)				//		물 선택이 7초 남아있는 경우
		{
			gu8_TimerWaterSelect = Z_TimerWaterSelect;	//			7초 reset
		}
	}
}

