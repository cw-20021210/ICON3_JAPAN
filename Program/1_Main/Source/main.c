/// @file     main.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    Main 처리 file
#define MAIN_C
#define FIX_RAM_C
#include "include/_include.h"


#ifdef _FOR_HEATER_ENDURANCE_TEST_
static void Heater_Endurance_Test(void);
#endif

static void Self_ChangeDisplay(void);

/// @brief    메인 루프
/// @param    void
/// @return   void
void MainLoop(void)
{
	DI();
	PIOR = 0x00U;
    R_CGC_Get_ResetSource();
    R_CGC_Create();
    R_PORT_Create();
    R_SAU0_Create();
    R_SAU1_Create();
    R_IICA0_Create();
    R_ADC_Create();
    R_TAU0_Create();
    R_TAU1_Create();
    R_WDT_Create();

    IAWCTL = 0x00U;
	EI();
	
	RamClear();										//	변수초기화
 
	R_WDT_Restart();								//	WDT Reset

	Timer_Start();									//	Timer Func. Start
	R_UART1_Start();								//	UART1 Start
	R_UART2_Start();								//	UART1 Start
	R_UART3_Start();								//	UART1 Start
//	R_INTC2_Start();
	R_ADC_Set_OperationOn();						//	ADC Set
	R_ADC_Start();									//	ADC Start
	R_WDT_Restart();								//	WDT Reset

	WifiControlProcess(WIFI_TIME_INI);

	gu8_TimerHWWait = Z_TimerHWWait;				//	하드웨어 안정화 타임

	while (gu8_TimerHWWait != 0)					//	하드웨어 안정화 대기
	{
		R_WDT_Restart();							//		WDT Reset

		Timer_Process();							//		Timer 처리

		InputControl();								//		Digital Input 처리

		EEPROM_Control();
	}

	Model_Decide();									//	기종 확정
	CP_CHP_Decide();								//	CP/CHP 확정

	StepMotor_ZeroBack_Open();						//	스테핑모터 초기화
	FaucetStepMotor_ZeroBack_Close();				//	파우셋 스테핑모터 초기화

	WifiControlProcess(WIFI_TIME_SET);

	gu8_TimerPBATest_Join = Z_TimerPBATest_Join;

	
	while (1)										//	Main Loop
	{
		R_WDT_Restart();							//		WDT Reset

		Timer_Process();							//		Timer 처리

		//	입력
		FlowMeter_Decide();							//		유량 처리

		HeaterFullCurrent_Decide();					//		히터 전력 감지

		Temperature_Change();						//		온도 변환

		InputControl();								//		Digital Input 처리

		Effluent_Degree_Average();

		KeyDecide(&gu8_DigitalInput_Key1);			//		키 입력 처리

		Get_WattCheck();							//		전류 체크

#ifdef _FOR_DEVELOP_
	if (gu8_ModelType_forNational_Test != 0)		//
	{
		gu8_ModelType_forNational = gu8_ModelType_forNational_Test;
	}
#endif

#ifdef _FOR_HEATER_ENDURANCE_TEST_					//		히터 내구 테스트
		Heater_Endurance_Test();
#endif
		//	처리
		ErrorCheck();								//		Error Check

		Operation();								//		운전스텝
		Description__Mode();						//		설명모드

		PureControl();								//		정수스텝

		ColdControl();								//		냉각스텝

		HotControl();								//		온수스텝

		PBAControl();								//		FCT 테스트 스텝

		FlowAmount_ForMonitor();					//		유량 누적

		gu8_Key_Short.byte = 0x00;

		//	출력
		if (gu8_ModelType_forCHP == MODEL_CHP)		//		온수모델만 Step Motor 제어
		{
			FlowControl();
		}
		OutputControl();							//		Digital Output 처리

		DisplayControl();							//		Display

		SmartCheckControl();						//		자가진단

		Self_ChangeDisplay();						//		자가관리 표시

		//	안전처리
		Safety();									//		안전처리

		//	통신처리
	    SerialControl();							//		시리얼 통신

	    EEPROM_Control();							//		EEPROM

	    CommunicationControl();						//		프론트 통신

	    LineAutoTestControl();						//		공장 검사

	    WifiControlProcess(WIFI_TIME_WHILE);

		FaucetMoving_Control();


		// gu16_Setting_Amount_Value[0] = 120;
		// gu16_Setting_Amount_Value[1] = 250;
		// gu16_Setting_Amount_Value[2] = 500;
		// gu16_Setting_Amount_Value[3] = 1;
		// gu16_Setting_Amount_Value[4] = 1;
	}
}

/// @brief    RAM Clear
/// @param    void
/// @return   void
void RamClear(void)
{
	ADC_Initialize();
	Cold_Initialize();
	Display_Initialize();
	EEPROM_Initialize();
	Pure_Initialize();
	Error_Initialize();
	Hot_Initialize();
	Input_Initialize();
	KeyControl_Initialize();
	Operation_Initialize();
	Output_Initialize();
	Safety_Initialize();
	Command_Initialize();
	Serial_Initialize();
	StepMotor_Initialize();
	Timer_Initialize();
	FlowMeter_Initialize();
	PBA_Initialize();
	LineAutoTest_Initialize();
	Communication_Initialize();
	SmartCheck_Initialize();
	FaucetMoving_Initialize();
	DescriptionMode_Initialize();

#ifdef _WIFI_
	InitializeWifiControl();
	Initialize_UART();
#endif
}


#ifdef _FOR_HEATER_ENDURANCE_TEST_
static void Heater_Endurance_Test(void)
{
//	if ((KEY_EFFLUENT_SHORT == SET) && (gu8_WaterSelect == HOT_WATER))
//	{
//		F_Heater_Endurance_Test_Start ^= 1;
//		gu8_TimerHeaterEndurance_Test_30min = 30;
//	}
//
//	if ((F_Heater_Endurance_Test_Start == SET) && (gu8_TimerHeaterEndurance_Test_30min == 0))
//	{
//		KEY_EFFLUENT_SHORT = SET;
//		gu8_TimerHeaterEndurance_Test_30min = 30;
//	}
//
//	if ((gu8_ErrorCode == 0) && (gu8_WaterSelect == HOT_WATER) && (F_FirstHotEffluent == SET) && (KEY_EFFLUENT_SHORT == SET))
//	{
//		F_Heater_Endurance_Test ^= 1;
//		if (F_Heater_Endurance_Test == 1)
//		{
//			gu16_CupSize = CUPSIZE_HALFCUP;
//			gu8_HotTempSetup = HOT_TEMP_SETUP_KOR100_JP90;
////			Play_Voice(VOICE_EFFLUENT_START);
//			gu8_TimerHeaterEndurance_Test = 60;
//		}
//		else
//		{
////			Play_Voice(VOICE_EFFLUENT_COMPLETE);
//			StepMotor_ZeroBack_Open();
//		}
//	}
//
//	if ((F_Heater_Endurance_Test == 1) && (gu8_TimerHeaterEndurance_Test == 0))
//	{
//		gu8_TimerHeaterEndurance_Test = 60;
//	}
//
//	if (gu16_FlowDecide_W < 20)						//	물없으면 타이머 초기화
//	{
//		gu8_TimerHeaterEndurance_Test = 60;
//	}

	if ((gu8_ErrorCode == 0) && (gu8_WaterSelect == HOT_WATER) && (gu8_OperationStep == Z_OperationStep_10) && (F_FirstHotEffluent == SET) && (KEY_EFFLUENT_SHORT == SET))
	{
		F_Heater_Endurance_Test ^= 1;
		if (F_Heater_Endurance_Test == 1)
		{
			gu8_DefaultWaterSelect = HOT_WATER;
			gu16_CupSize = CUPSIZE_CONTINUE;
			gu8_DefaultCupSize = CUPSIZE_FIVE;
			gu8_HotTempSetup = HOT_TEMP_SETUP_KOR100_JP90;
			gu8_TimerHeaterEndurance_Test = 60;
		}
		else
		{
			StepMotor_ZeroBack_Open();
		}
	}

	if (F_Heater_Endurance_Test == SET)
	{
		if ((gu8_OperationStep == Z_OperationStep_50) && (gu8_WaterSelect == HOT_WATER))
		{
			gu8_TimerHeaterEndurance_Test = 60;
		}


		if ((gu8_OperationStep == Z_OperationStep_10) && (gu8_WaterSelect != HOT_WATER) && (gu8_TimerHeaterEndurance_Test == 4))
		{
			KEY_HOTWATER_SHORT = SET;
		}

		if ((gu8_OperationStep == Z_OperationStep_10) && (gu8_TimerHeaterEndurance_Test == 0))
		{
			gu8_WaterSelect = HOT_WATER;
			gu8_DefaultWaterSelect = HOT_WATER;
			gu8_HotTempSetup = HOT_TEMP_SETUP_KOR100_JP90;
			gu16_CupSize = CUPSIZE_CONTINUE;
			gu8_DefaultCupSize = CUPSIZE_FIVE;
			KEY_EFFLUENT_SHORT = SET;
		}
	}
}
#endif

/// @brief    자가관리 표시
/// @param    void
/// @return   void
static void Self_ChangeDisplay(void)
{
	//	필터
	//	필터 마진 삭제(구 버젼의 경우, 배송일정으로 인해 30일 마진을 주었음.)
	#if 0
	if (gu16_DayCount_forFilter >= (180+30))
	#endif
	if (gu16_DayCount_forFilter >= 180)
	{
		if (F_SelfService == SET)
		{
			F_FilterChange_Display = SET;
		}
		else
		{
			F_FilterChange_Display = CLEAR;
		}
	}
	else
	{
		F_FilterChange_Display = CLEAR;
	}

	//	파우셋
	#if 0
	//	필터 마진 삭제(구 버젼의 경우, 배송일정으로 인해 30일 마진을 주었음.)
	if (gu16_DayCount_forFaucet >= (365+30))
	#endif
	if (gu16_DayCount_forFaucet >= 365)
	{
		if (F_SelfService == SET)
		{
			F_FaucetChange_Display = SET;
		}
		else
		{
			F_FaucetChange_Display = CLEAR;
		}
	}
	else
	{
		F_FaucetChange_Display = CLEAR;
	}
}
