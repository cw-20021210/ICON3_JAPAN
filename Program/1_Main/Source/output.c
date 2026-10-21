/// @file     output.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    출력 처리 file
#include "include/_user_define.h"
#define OUTPUT_C
#include "include/_include.h"

static void Output_PureValve(void);
static void Output_NosValve(void);
static void Output_HotInValve(void);
static void Output_HotOutValve(void);
static void Output_ColdInValve(void);
static void Output_ColdOutValve(void);
static void Output_Heater(void);
static void Output_TEM(void);
static void Output_FAN(void);
static void Output_ColdSensor_ONOFF(void);
static void Output_LeakSensor(void);
static void Output_FCT_TxRx(void);
static void Output_UV(void);
static void Output_Power(void);
static void Output_Welcome_LED(void);

static void OutputNotUsePort(void);

#ifdef _DPP_FLOWMETER_
#define Z_HeaterOFF_Hz		(100)					//	100Hz(약10cc) [1Hz]
#else
//#define Z_HeaterOFF_Hz		(20)					//	20Hz(약8cc) [1Hz]
#define Z_HeaterOFF_Hz		(35)					//	35(약14cc) [1Hz]
#endif

#define TEM_PWM_FULL_TDR    ((_0C7F_TAU_TDR03_VALUE+1) - (_0C7F_TAU_TDR03_VALUE+1)) //  반전 출력
#define TEM_PWM_OFF_TDR     ((_0C7F_TAU_TDR03_VALUE+1))     //  반전 출력
//#define TEM_PWM_RMS_CAL       ((_DABF_TAU_TDR02_VALUE+1) / 240 * 8 / 10)
//#define TEM_PWM_RMS_CAL       (106)       //  ((_DABF_TAU_TDR02_VALUE+1) / 240 * 8 / 10)
#define Z_HEATER_PWM_TDR_HIGH_TEMP  (3199U)    //@030  90°C 이상 설정 시 히터 PWM 최대 TDR 제한값


TEM_Voltage_Data TEM_Voltage_DataTable[Z_TEM_Voltage_Data_Max] =    //  파워넷 SMPS
{
		{	12, 0	},
		{	11, 530	},
		{	10,	1010	},
		{	9, 	1485	},
		{	8, 	1980	},
		{	7, 	2435	},
		{	6, 	2900	},
		{	5, 	3200	},
};

/// @brief    출력처리 초기화
/// @param    void
/// @return   void
void Output_Initialize(void)
{
	F_ColdSensor_OFF = CLEAR;
	gu16_TimerColdSensor_ON = Z_TimerColdSensor_ON_Init;
	gu8_TimerBoot_After1s = Z_TimerBoot_After1s;
	gu8_TimerStanbyOn_After1s = Z_TimerStanbyOn_After1s;

	gu8_F_UV_First_On = CLEAR;
}

/// @brief    출력 처리
/// @param    void
/// @return   void
void OutputControl(void)
{
	/************************************************/
	/*---------------------------------*/
	/*	전 부하의 출력 처리				   */
	/*---------------------------------*/
	#ifndef _FOR_DEVLOP_NO_LOAD_OUTPUT_
	Output_PureValve();								//	정수 피드밸브
	Output_NosValve();								//	노스밸브
	Output_ColdInValve();							//	냉수입수 피드밸브
	Output_ColdOutValve();							//	냉수출수 피드밸브

	if ((gu8_ModelType_forCHP == MODEL_CHP) || (F_TestMode_PBA == SET))	//	온수모델인 경우 or PBA테스트모드인 경우
	{
		Output_HotInValve();						//		온수입수 피드밸브
		Output_HotOutValve();						//		온수출수 피드/노스밸브
		#ifndef _FOR_DEVELOP_NO_HOT_LOAD_OUTPUT_
		Output_Heater();							//		히터 RELAY/TRIAC
		#endif
	}
	// TDR04 = 0xDABFU;
	Output_TEM();									//	열전모듈
	Output_FAN();									//	FAN
	Output_LeakSensor();
	Output_FCT_TxRx();
	Output_UV();
	Output_Power();
	#endif
	
	Output_ColdSensor_ONOFF();


	Output_Welcome_LED();
	/*---------------------------------*/
	/*	미사용 PORT 출력 처리			   */
	/*---------------------------------*/
	OutputNotUsePort(); 							//	미사용 포트 출력
}

/// @brief    미사용 포트 처리
/// @param    void
/// @return   void
static void OutputNotUsePort(void)
{
	/************************************************/

}

/// @brief    정수밸브
/// @param    void
/// @return   void
static void Output_PureValve(void)
{
	#ifdef _COLD_TEST_
	if (gu8_Timer_RAPID_OUT != 0)
	{
		gu8_PureValve_CMD = VALVE_ON;
	}
	#endif
#ifdef _FRONT_JIG_PROGRAM_
//	if ((gu8_FRONT_JIG_Complete & 0b00011111) == 0b00011111)
	if ((gu8_FrontTest_HotButton_Counter >= 6)
		&& (gu8_FrontTest_PureButton_Counter >= 8)
		&& (gu8_FrontTest_ColdButton_Counter >= 6)
		&& (gu8_FrontTest_AmountButton_Counter >= 2)
		&& (F_FrontTest_EffluentButton == SET))
	{
		P_FEED_PURE_V = ON;
	}
	else
	{
		P_FEED_PURE_V = OFF;
	}
	return;
#endif
	if (F_TestMode_PBA == SET)
	{
		if (gu8_PBATest_PureLoad == 2)
		{
			P_FEED_PURE_V = ON;
		}
		else
		{
			P_FEED_PURE_V = OFF;
		}
	}
	else if (F_TestMode_LineTest2 == SET)
	{
		if (F_LineTest2_Purge == SET)
		{
			P_FEED_PURE_V = ON;
		}
		else
		{
			P_FEED_PURE_V = OFF;
		}
	}
	else if (F_TestMode_LineAuto == SET)
	{
		if (F_LineTest_Pure_VV == SET)
		{
			P_FEED_PURE_V = ON;
		}
		else
		{
			P_FEED_PURE_V = OFF;
		}
	}
	else if (F_TestMode_LineFront == SET)
	{
		if ((F_LineFrontTest_Effluent_Oper == SET) && (F_LineFrontTest_Pure_Select == SET))
		{
			P_FEED_PURE_V = ON;
		}
		else
		{
			P_FEED_PURE_V = OFF;
		}
	}
	else
	{
		if ((gu8_SmartCheckStep & 0xF0) == 0x20)
		{
			if (F_SmartCheck_Pure_VV == SET)
			{
				P_FEED_PURE_V = ON;
			}
			else
			{
				P_FEED_PURE_V = OFF;
			}
		}
		else
		{
			if ((gu8_OperationStep == Z_OperationStep_F0) && ((gu16_TimerKITMode > (Z_TimerKITMode-30)) || (gu16_TimerKITMode < 30)))
			{
				gu8_PureValve_CMD = VALVE_ON;
			}

			if (gu8_PureValve_CMD == VALVE_ON)
			{
				P_FEED_PURE_V = ON;
			}
			else
			{
				P_FEED_PURE_V = OFF;
			}
		}
	}
}

/// @brief    NOS밸브
/// @param    void
/// @return   void
static void Output_NosValve(void)
{
	if (F_TestMode_PBA == SET)
	{
		if (gu8_PBATest_PureLoad == 1)
		{
			P_NOS_V = N_OFF;
		}
		else
		{
			P_NOS_V = N_ON;
		}
	}
	else if (F_TestMode_LineTest2 == SET)
	{
		if(F_LineTest2_Valve == SET)
		{
			P_NOS_V = N_ON;
		}
		else
		{
			P_NOS_V = N_OFF;
		}		
	}
	else if (F_TestMode_LineAuto == SET)
	{
		if (F_LineTest_1stNos_VV == SET)
		{
			P_NOS_V = N_OFF;
		}
		else
		{
			P_NOS_V = N_ON;
		}
	}
	else if (F_TestMode_LineFront == SET)
	{
		if (F_LineFrontTest_1stNos_VV == SET)	
		{                                       
			P_NOS_V = N_OFF;                    
		}                                       
		else                                   
		{                                       
			P_NOS_V = N_ON;                     
		}                                       
	}
	else
	{
		if ((gu8_SmartCheckStep & 0xF0) == 0x20)
		{
			if ((F_SmartCheck_1stNos_VV == SET) || (INPUT_REED_SW_FILTER == CLEAR))	//
			{
				P_NOS_V = N_OFF;
			}
			else
			{
				P_NOS_V = N_ON;
			}
		}
		else
		{
			if ((gu8_ErrorCode == Z_Ecode01)
				|| (gu8_ErrorCode == Z_Ecode02)
				// || ((gu8_OperationStep != Z_OperationStep_F0) && ((INPUT_REED_SW_FILTER == CLEAR) || (INPUT_REED_SW_COVER == CLEAR)
				|| ((gu8_OperationStep != Z_OperationStep_F0) && ((INPUT_REED_SW_FILTER == CLEAR) || (INPUT_REED_SW_COVER == CLEAR)))
				|| (gu8_OperationStep == Z_OperationStep_B0))
			{
				P_NOS_V = N_OFF;
			}
			else
			{
				P_NOS_V = N_ON;
			}
		}
	}
}

/// @brief    온수입수 밸브
/// @param    void
/// @return   void
static void Output_HotInValve(void)
{
	if (F_TestMode_PBA == SET)
	{
		if (gu8_PBATest_HotLoad == 1)
		{
			P_FEED_HOTIN_V = ON;
		}
		else
		{
			P_FEED_HOTIN_V = OFF;
		}
	}
	else if (F_TestMode_LineTest2 == SET)
	{
		#if 0
		if ((F_LineTest2_Valve == SET) || (F_LineTest2_Purge == SET))
		#endif
		if (F_LineTest2_Purge == SET)
		{
			P_FEED_HOTIN_V = ON;
		}
		else
		{
			P_FEED_HOTIN_V = OFF;
		}
	}
	else if (F_TestMode_LineAuto == SET)
	{
		if (F_LineTest_HotIn_VV == SET)
		{
			P_FEED_HOTIN_V = ON;
		}
		else
		{
			P_FEED_HOTIN_V = OFF;
		}
	}
	else if (F_TestMode_LineFront == SET)
	{
		if ((F_LineFrontTest_Effluent_Oper == SET) && (F_LineFrontTest_Hot_Select == SET))
		{
			P_FEED_HOTIN_V = ON;
		}
		else
		{
			P_FEED_HOTIN_V = OFF;
		}
	}
	else
	{
		if ((gu8_SmartCheckStep & 0xF0) == 0x20)
		{
			if (F_SmartCheck_HotIn_VV == SET)
			{
				P_FEED_HOTIN_V = ON;
			}
			else
			{
				P_FEED_HOTIN_V = OFF;
			}
		}
		else
		{
			if (gu8_HotInValve_CMD == VALVE_ON)
			{
				P_FEED_HOTIN_V = ON;
			}
			else
			{
				P_FEED_HOTIN_V = OFF;
			}
		}
	}
}

/// @brief    온수출수 FEED/NOS 밸브
/// @param    void
/// @return   void
static void Output_HotOutValve(void)
{
	if (F_TestMode_PBA == SET)
	{
		if (gu8_PBATest_HotLoad == 2)
		{
			P_FEED_HOTOUT_V = ON;
		}
		else
		{
			P_FEED_HOTOUT_V = OFF;
		}
	}
	else if (F_TestMode_LineTest2 == SET)
	{
		#if 0
		if (F_LineTest2_Purge == SET)
		#endif
		if ((F_LineTest2_Valve == SET) || (F_LineTest2_Purge == SET))
		{
			P_FEED_HOTOUT_V = ON;
		}
		else
		{
			P_FEED_HOTOUT_V = OFF;
		}
	}
	else if (F_TestMode_LineAuto == SET)
	{
		if (F_LineTest_HotOut_VV == SET)
		{
			P_FEED_HOTOUT_V = ON;
		}
		else
		{
			P_FEED_HOTOUT_V = OFF;
		}
	}
	else if (F_TestMode_LineFront == SET)
	{
		if ((F_LineFrontTest_Effluent_Oper == SET) && (F_LineFrontTest_Hot_Select == SET))
		{
			P_FEED_HOTOUT_V = ON;
		}
		else if (F_LineFrontTest_Hot_Complete == SET)
		{
			P_FEED_HOTOUT_V = ON;
		}
		else
		{
			P_FEED_HOTOUT_V = OFF;
		}
	}
	else
	{
		if ((gu8_SmartCheckStep & 0xF0) == 0x20)
		{
			if (F_SmartCheck_HotOut_VV == SET)
			{
				P_FEED_HOTOUT_V = ON;
			}
			else
			{
				P_FEED_HOTOUT_V = OFF;
			}
		}
		else
		{
			if (gu8_HotOutValve_CMD == VALVE_ON)		//		출수 지시인 경우
			{
				P_FEED_HOTOUT_V = ON;
			}
			else
			{
				P_FEED_HOTOUT_V = OFF;
			}
		}
	}
}

/// @brief    냉수출수 밸브
/// @param    void
/// @return   void
static void Output_ColdOutValve(void)
{
	if (F_TestMode_PBA == SET)
	{
		if (gu8_PBATest_ColdLoad == 2)
		{
			P_FEED_COLD_OUT_V = ON;
		}
		else
		{
			P_FEED_COLD_OUT_V = OFF;
		}
	}
	else if (F_TestMode_LineTest2 == SET)
	{
		if((F_LineTest2_Purge == SET) || (F_LineTest2_Valve == SET))
		{
			P_FEED_COLD_OUT_V = ON;
		}
		else
		{
			P_FEED_COLD_OUT_V = OFF;
		}
	}
	else if (F_TestMode_LineAuto == SET)
	{
		if (F_LineTest_ColdOut_VV == SET)
		{
			P_FEED_COLD_OUT_V = ON;
		}
		else
		{
			P_FEED_COLD_OUT_V = OFF;
		}
	}
	else if (F_TestMode_LineFront == SET)
	{
		if ((F_LineFrontTest_Effluent_Oper == SET) && (F_LineFrontTest_Cold_Select == SET))
		{
			P_FEED_COLD_OUT_V = ON;
		}
		else if (F_LineFrontTest_Cold_Complete == SET)
		{
			P_FEED_COLD_OUT_V = ON;
		}
		else
		{
			P_FEED_COLD_OUT_V = OFF;
		}
	}
	else
	{
		if ((gu8_SmartCheckStep & 0xF0) == 0x20)
		{
			if (F_SmartCheck_ColdOut_VV == SET)
			{
				P_FEED_COLD_OUT_V = ON;
			}
			else
			{
				P_FEED_COLD_OUT_V = OFF;
			}
		}
		else
		{
			if ((gu8_OperationStep == Z_OperationStep_F0) && ((gu16_TimerKITMode <= (Z_TimerKITMode-30)) && (gu16_TimerKITMode >= 30)))
			{
				gu8_Cold_Out_Valve_CMD = VALVE_ON;
			}

			if (gu8_Cold_Out_Valve_CMD == VALVE_B0)
			{
				if (gu8_TimerPressureClear_ColdVV_Delay == 0)
				{
					if (gu8_TimerPressureClear_ColdVV != 0)
					{
						P_FEED_COLD_OUT_V = ON;
					}
					else
					{
						P_FEED_COLD_OUT_V = OFF;
					}
				}
				else
				{
					P_FEED_COLD_OUT_V = OFF;
				}
			}
			else if (gu8_Cold_Out_Valve_CMD == VALVE_ON)
			{
				P_FEED_COLD_OUT_V = ON;
			}
			else
			{
				P_FEED_COLD_OUT_V = OFF;
			}
		}
	}
}

/// @brief    냉수입수 밸브
/// @param    void
/// @return   void
static void Output_ColdInValve(void)
{
	if (F_TestMode_PBA == SET)
	{
		if (gu8_PBATest_ColdLoad == 1)
		{
			P_FEED_COLD_IN_V = ON;
		}
		else
		{
			P_FEED_COLD_IN_V = OFF;
		}
	}
	else if (F_TestMode_LineTest2 == SET)
	{
		#if 0
		if ((F_LineTest2_Valve == SET) || (F_LineTest2_Purge == SET))
		#endif
		if (F_LineTest2_Purge == SET)
		{
			P_FEED_COLD_IN_V = ON;
		}
		else
		{
			P_FEED_COLD_IN_V = OFF;
		}
	}
	else if (F_TestMode_LineAuto == SET)
	{
		if (F_LineTest_ColdIn_VV == SET)
		{
			P_FEED_COLD_IN_V = ON;
		}
		else
		{
			P_FEED_COLD_IN_V = OFF;
		}
	}
	else if (F_TestMode_LineFront == SET)
	{
		if ((F_LineFrontTest_Effluent_Oper == SET) && (F_LineFrontTest_Cold_Select == SET))
		{
			P_FEED_COLD_IN_V = ON;
		}
		else
		{
			P_FEED_COLD_IN_V = OFF;
		}
	}
	else
	{
		if ((gu8_SmartCheckStep & 0xF0) == 0x20)
		{
			if (F_SmartCheck_ColdIn_VV == SET)
			{
				P_FEED_COLD_IN_V = ON;
			}
			else
			{
				P_FEED_COLD_IN_V = OFF;
			}
		}
		else
		{
			if ((gu8_OperationStep == Z_OperationStep_F0) && ((gu16_TimerKITMode <= (Z_TimerKITMode-30)) && (gu16_TimerKITMode >= 30)))
			{
				gu8_Cold_In_Valve_CMD = VALVE_ON;
			}

			if (gu8_Cold_In_Valve_CMD == VALVE_B0)
			{
				if (gu8_TimerPressureClear_ColdVV_Delay == 0)
				{
					if (gu8_TimerPressureClear_ColdVV != 0)
					{
						P_FEED_COLD_IN_V = ON;
					}
					else
					{
						P_FEED_COLD_IN_V = OFF;
					}
				}
				else
				{
					P_FEED_COLD_IN_V = OFF;
				}
			}
			else if (gu8_Cold_In_Valve_CMD == VALVE_ON)
			{
				P_FEED_COLD_IN_V = ON;
			}
			else
			{
				P_FEED_COLD_IN_V = OFF;
			}
		}
	}
}

/// @brief    히터
/// @param    void
/// @return   void
static void Output_Heater(void)
{
//	U16 mu16_HeaterPWM_TDR = 0;
	U16 mu16_Heater_work1 = 0;
	U16 mu16_Heater_work2 = 0;
	U16 mu16_Buf1 = 0;
	U8 mu8_OPENSHORT_Error1 = 0;
	U8 mu8_OPENSHORT_Error2 = 0;
	U16 HeaterOff_Time = 0;
	I16 HeaterOff_Buf = 0;
	I16 mi16_Buf1, mi16_Buf2 = 0;
	//@041 U16 mu16_HeaterPWM_MaxTDR = (gu8_HotTempSetup >= HOT_TEMP_SETUP_KOR__90) ? (U16)Z_HEATER_PWM_TDR_HIGH_TEMP : (U16)_DABF_TAU_TDR02_VALUE;	//@030	90°C 이상: 3199, 미만: _DABF_TAU_TDR02_VALUE
	U16 mu16_HeaterPWM_MaxTDR = (gu8_HotTempSetup >= HOT_TEMP_SETUP_KOR__80) ? (U16)Z_HEATER_PWM_TDR_HIGH_TEMP : (U16)_DABF_TAU_TDR02_VALUE;	//@041	70°C 이상: 3199, 미만: _DABF_TAU_TDR02_VALUE

#ifdef _HEATER_OFF_
	P_HEATER_RELAY = OFF;
	P_HEATER_TRIAC = OFF;
	P_HEATER_PWM_TDR = 0x0000U;
	return;
#endif

#ifdef _FOR_WQA_
	P_HEATER_RELAY = OFF;
	P_HEATER_TRIAC = OFF;
	P_HEATER_PWM_TDR = 0x0000U;
	return;
#endif

	mu8_OPENSHORT_Error1 = TH_Open_Short_Check(gi16_HotOutSensor.TH_ADC_AVERAGE);	//	온수출수TH 단선단락 체크
	mu8_OPENSHORT_Error2 = TH_Open_Short_Check(gi16_HeaterSensor.TH_ADC_AVERAGE);	//	히터TH 단선단락 체크
#ifdef _FOR_HEATER_ENDURANCE_TEST_
//	if ((F_Heater_Endurance_Test == SET) && (gu8_TimerHeaterEndurance_Test >= 30) && (gu8_HotStep == Z_HotStep_35))
//	{
//		P_HEATER_RELAY = OFF;
//		P_HEATER_TRIAC = OFF;
//		P_HEATER_PWM_TDR = 0x0000U;
//		return;
//	}
	if ((F_Heater_Endurance_Test == SET) && (gu16_TimerEffluent < 600) && (gu8_HotStep == Z_HotStep_35))
	{
		P_HEATER_RELAY = OFF;
		P_HEATER_TRIAC = OFF;
		P_HEATER_PWM_TDR = 0x0000U;
		return;
	}
#endif
	if ((gu8_SmartCheckStep & 0xF0) == 0x20)
	{
		if (F_SmartCheck_HeaterRelay == SET)
		{
			P_HEATER_RELAY = ON;
		}
		else
		{
			P_HEATER_RELAY = OFF;
		}

		if (F_SmartCheck_HeaterTriac == SET)
		{
			P_HEATER_TRIAC = ON;
			P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
		}
		else
		{
			P_HEATER_TRIAC = OFF;
			P_HEATER_PWM_TDR = 0x0000U;
		}
	}
	else if ((mu8_OPENSHORT_Error1 != 0) || (mu8_OPENSHORT_Error2 != 0))	//	단선단락 시
	{
		P_HEATER_RELAY = OFF;
		P_HEATER_TRIAC = OFF;
		P_HEATER_PWM_TDR = 0x0000U;
	}
	else if ((gi16_HeaterSensor.DEGREE >= Z_TEMP103)
		&& ((gu8_HotStep == Z_HotStep_33) || (gu8_HotStep == Z_HotStep_34)
		|| ((gu8_HotStep == Z_HotStep_35) && (gu16_FlowDecide_W < 10) && (gu8_TimerFlowCheck_AfterEff != 0))))	//	온수 추출 중 플로우체크 타이머 경과 되지 않았을 때
	{
		P_HEATER_RELAY = OFF;
		P_HEATER_TRIAC = OFF;
		P_HEATER_PWM_TDR = 0x0000U;
	}
	else
	{
		if ((gu8_HotStep != Z_HotStep_32) &&(gu8_HotStep != Z_HotStep_33) && (gu8_HotStep != Z_HotStep_34) && (gu8_HotStep != Z_HotStep_37)		//cbr_test 2025-10-21
			&& ((gu8_HotStep & 0xF0) == 0x30) && (gu16_FlowDecide_W < 10) && (gu8_TimerFlowCheck_AfterEff == 0))	//	온수 추출 시퀀스 중 예열스텝을 제외하고 유량이 0.1LPM 미만이면 히터 정지
		{
			P_HEATER_RELAY = OFF;
			P_HEATER_TRIAC = OFF;
			P_HEATER_PWM_TDR = 0x0000U;
		}
		else
		{
			// if(gi16_HotInSensor.DEGREE >= Z_TEMP27)		//2026-01-08 16:27:08
			// {
			// 	HeaterOff_Buf = (((I16)Z_TEMP25 - gi16_HotInSensor.DEGREE)/2);
			// }
			// else
			// {
			// 	HeaterOff_Buf = (((I16)Z_TEMP25 - gi16_HotInSensor.DEGREE)/5);
			// }
			HeaterOff_Buf = (((I16)Z_TEMP25 - gi16_HotInSensor.DEGREE)/5);
			if (HeaterOff_Buf <= Z_HeaterOFF_Hz)
			{
				gu16_HeaterOff_Hz = (U16)Z_HeaterOFF_Hz - HeaterOff_Buf;
			}
			else
			{
				gu16_HeaterOff_Hz = 0;
			}
//			gu16_HeaterOff_Hz = Z_HeaterOFF_Hz - (((I16)Z_TEMP25 - gi16_HotInSensor.DEGREE)/5);
			HeaterOff_Time = 20;					//	2초 <1/10s>

//			/*	잠열 제거 히터 OFF 조건	*/
#ifdef _HOT_TEMP_4STEP_
            if ((gu8_ModelType_forNational == MODEL_KOREA)
            && (gu8_HotStep == Z_HotStep_35) && ((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80) || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__95)
                    || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__90) ||(gu8_HotTempSetup == HOT_TEMP_SETUP_KOR100_JP90)))
#else
			if ((gu8_ModelType_forNational == MODEL_KOREA)
			&& (gu8_HotStep == Z_HotStep_35) && (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR100_JP90))
#endif
			{
				// #if 0
				if (gu16_CupSize == CUPSIZE_CONTINUE)	//	연속 추출 시 마지막 3초 잠열제거 시작
				// #endif
				// if(gu8_Cup_size_Array[gu8_CupIndex].amount_volume == CUPSIZE_CONTINUE)
				{
					if (gu16_TimerEffluent <= HeaterOff_Time)
					{
						if (gu16_TimerEffluent < (HeaterOff_Time/3))	//220405
						{
							F_LatentHeat_Clear = SET;
						}
						gu8_HeaterRelay_CMD = HEATER_OFF;
						gu8_HeaterTriac_CMD = HEATER_OFF;
					}
				}
				else
				{
					if (gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_HIGH)
					{
						F_LatentHeat_Clear = CLEAR;
						if (gu16_Effluent_Hz <= gu16_HeaterOff_Hz)				//2025-12-30
						{
							gu8_HeaterRelay_CMD = HEATER_OFF;
							gu8_HeaterTriac_CMD = HEATER_OFF;
						}
					}
					else
					{
						if (gu16_Effluent_Hz <= gu16_HeaterOff_Hz)	//	잠열제거 시작 유량 체크
						{
							if((gu16_Effluent_Hz < (gu16_HeaterOff_Hz/3))	//220405
							|| (gu16_Effluent_Hz <= 5))						//2025-12-29
							{
								F_LatentHeat_Clear = SET;
							}
							gu8_HeaterRelay_CMD = HEATER_OFF;
							gu8_HeaterTriac_CMD = HEATER_OFF;
						}
					}
				}
			}
			/*	릴레이	*/
			if (F_TestMode_PBA == SET)
			{
				if ((gu8_PBATest_HotLoad == 3) && (gu8_TimerPBATest_HeaterRelay != 0))
				{
					P_HEATER_RELAY = ON;
				}
				else
				{
					P_HEATER_RELAY = OFF;
				}
			}
			else if (F_TestMode_LineTest2 == SET)
			{
				if (gu8_TimerLineTest2_Heater != 0)
				{
					P_HEATER_RELAY = ON;
				}
				else
				{
					P_HEATER_RELAY = OFF;
				}
			}
			else if (F_TestMode_LineFront == SET)
			{
//				if ((gu8_TimerLineTest_Heater != 0) && (gu8_TimerLineTest_Heater > ((Z_TimerLineTest_Heater/2)+50)))
				if (gu8_TimerLineTest_Heater != 0)
				{
					P_HEATER_RELAY = ON;
				}
				else
				{
					P_HEATER_RELAY = OFF;
				}
			}
			else
			{
				switch (gu8_HeaterRelay_CMD)
				{
					case HEATER_OFF:
					default:
						P_HEATER_RELAY = OFF;
						break;
					case HEATER_FIRST:
						if (gu8_TimerFirstHot_HeaterSensing != 0)
						{
							P_HEATER_RELAY = ON;
						}
						else
						{
							P_HEATER_RELAY = OFF;
						}
						break;
					case HEATER_ON:
						if (gu16_HeaterRELAY_WATT > 200)		//		히터 RELAY WATT가 200W 이상인 경우
						{
							mu16_Buf1 = gu16_HeaterRELAY_WATT - 200;	//
							if (gu16_HeaterWATT > gu16_HeaterRELAY_WATT)
							{
								F_HeaterPWM_SingleControl = CLEAR;
							}
						}
#ifndef _HEATER_CURRENT_CHECK_
#ifdef _EFF_Continue_Heater_OFF
                        if(F_Eff_Continue_Heater_Off == SET){
                            P_HEATER_RELAY = OFF;                           //  히터 Relay Off
                            P_HEATER_TRIAC = OFF;                           //  히터 트리악 Off
                            P_HEATER_PWM_TDR = 0x0000U;                     //  히터 트리악 PWM Off
                            return;
                        }

#endif
						if ((F_HeaterPWM_SingleControl == SET)
						|| ((gu8_HotStep == Z_HotStep_35) && (gu16_HeaterWATT <= mu16_Buf1)) 	//		온수 추출 중 필요 WATT가 X보다 낮은 경우
						|| (F_MilkEff_MoreHot == SET))	//		분유 추출 시작 시 내열이 높은 경우
						{
							F_HeaterPWM_SingleControl = SET;	//			PWM Single Control 제어 설정
							P_HEATER_RELAY = OFF;				//			히터 RELAY OFF
						}
						else
						{	//cbr 2025-11-21 유량 경계값이면 릴레이 on/off반복 불량
							// if ((gu8_HotStep == Z_HotStep_35) && (gu8_TimerHeaterSafety_AfterEff == 0)
							// && (gu16_FlowDecide_W < (gu16_FlowTarget_W*2/3))	//	유량이 적은 경우 		
							// && (gu8_HotTempSetup != HOT_TEMP_SETUP_KOR45_JPX)	//cbr_test 2025-11-18
							// && (gu8_HotTempSetup != HOT_TEMP_SETUP_KOR__50)		//cbr_test 2025-11-18
							// && (gu8_HotTempSetup != HOT_TEMP_SETUP_KOR__55)		//cbr_test 2025-11-18
							// && (gu8_HotTempSetup != HOT_TEMP_SETUP_KOR__80)		//cbr_test 2025-11-18
							// && (gu8_HotTempSetup != HOT_TEMP_SETUP_KOR__65))	//cbr_test 2025-11-19
							// {
							// 	mi16_Buf1 = gu16_FlowTarget_W - gu16_FlowDecide_W;
							// 	if ((gi16_HotOutSensor.DEGREE > (Z_TEMP100-mi16_Buf1)) || (gi16_HeaterSensor.DEGREE > (Z_TEMP100-mi16_Buf1)))
							// 	{
							// 		P_HEATER_RELAY = OFF;				//			히터 RELAY OFF
							// 	}
							// 	else if ((gi16_HotOutSensor.DEGREE <= (Z_TEMP100-mi16_Buf1-Z_TEMP2)) && (gi16_HeaterSensor.DEGREE <= (Z_TEMP100-mi16_Buf1-Z_TEMP2)))
							// 	{
							// 		P_HEATER_RELAY = ON;
							// 	}
							// 	else
							// 	{
							// 		//	히스테리시스
							// 	}
							// }
							// else
							// {	//cbr_test 2025-09-16
								if(((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR45_JPX)
								|| (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__50))
								// && (gi16_HotInSensor.DEGREE > Z_TEMP15))			//cbr_test 2025-11-26 10도 조건 온도미달	//2026-01-05
								&& ((gu16_FlowDecide_W_HotEffMax < (gu16_FlowTarget_W*2))
								|| (gi16_HotInSensor.DEGREE > Z_TEMP15)
								|| (gu8_Heater_PowerLevel != Z_HEATER_POWER_LEVEL_LOW)))
								{
									if ((gi16_HotOutSensor.DEGREE > Z_TEMP50) || (gi16_HeaterSensor.DEGREE > Z_TEMP53))
									{
										P_HEATER_RELAY = OFF;				//			45도 설정용 릴레이 OFF
									}
									else if ((gi16_HotOutSensor.DEGREE <= Z_TEMP45) && (gi16_HeaterSensor.DEGREE <= Z_TEMP46))
									{
										P_HEATER_RELAY = ON;				//			45도 설정용 릴레이 ON
									}
									else
									{
										//	히스테리시스
									}
								}
								else if((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR70_JP70)
									&& ((gi16_HotInSensor.DEGREE <= Z_TEMP15)
									|| ((gi16_HotInSensor.DEGREE > Z_TEMP15)
									&& (gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_HIGH))))	//고전력 릴레이만 상시 on 시(1776w) 트라이악 제어 불가로 온도 과열 -> 릴레이 제어 필요
								{
									if ((gi16_HotOutSensor.DEGREE > Z_TEMP92) || (gi16_HeaterSensor.DEGREE > Z_TEMP93))
									{
										P_HEATER_RELAY = OFF;
									}
									else if ((gi16_HotOutSensor.DEGREE <= Z_TEMP80) && (gi16_HeaterSensor.DEGREE <= Z_TEMP85))
									{
										P_HEATER_RELAY = ON;
									}
									else
									{
										//	히스테리시스
									}
								}
								else if((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__65)				//65도 예열 후 릴레이만 켜도 과열 -> 릴레이 off 필요
									&& (gi16_HotInSensor.DEGREE > Z_TEMP25))
								{
									if ((gi16_HotOutSensor.DEGREE > Z_TEMP85) || (gi16_HeaterSensor.DEGREE > Z_TEMP88))
									{
										P_HEATER_RELAY = OFF;
									}
									else if ((gi16_HotOutSensor.DEGREE <= Z_TEMP78) && (gi16_HeaterSensor.DEGREE <= Z_TEMP80))
									{
										P_HEATER_RELAY = ON;
									}
									else
									{
										//	히스테리시스
									}
								}
								else  // 다른 온도 설정
								{
									if ((gi16_HotOutSensor.DEGREE > Z_TEMP103_5) || (gi16_HeaterSensor.DEGREE > Z_TEMP105))		//cbr_test 2025-09-15
									{
										P_HEATER_RELAY = OFF;				//			히터 RELAY OFF
									}
									else if ((gi16_HotOutSensor.DEGREE <= Z_TEMP100) && (gi16_HeaterSensor.DEGREE <= Z_TEMP103))	//cbr_test 2025-09-15
									{
										P_HEATER_RELAY = ON;				//			히터 RELAY
									}
									else
									{
										//	히스테리시스
									}
								}
							// }
						}
#else
						P_HEATER_RELAY = ON;
#endif
						break;
				}
			}
#ifdef _FOR_DEVELOP_
			if ((gu8_HotStep == Z_HotStep_35) && (P_HEATER_RELAY == OFF))
			{
				gu8_Counter_HeaterOFF++;
			}
#endif

			/*	TRIAC	*/
			if (F_TestMode_PBA == SET)
			{
				if ((gu8_PBATest_HotLoad == 4) && (gu8_TimerPBATest_HeaterTriac != 0))
				{
					P_HEATER_TRIAC = ON;
					P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
				}
				else
				{
					P_HEATER_TRIAC = OFF;
					P_HEATER_PWM_TDR = 0x0000;			//			TDR CLEAR
				}
			}
			else if (F_TestMode_LineTest2 == SET)
			{
				if (gu8_TimerLineTest2_Heater != 0)
				{
					P_HEATER_TRIAC = ON;
					P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
				}
				else
				{
					P_HEATER_TRIAC = OFF;
					P_HEATER_PWM_TDR = 0x0000;			//			TDR CLEAR
				}
			}
			else if (F_TestMode_LineFront == SET)
			{
//				if ((gu8_TimerLineTest_Heater != 0) && (gu8_TimerLineTest_Heater <= ((Z_TimerLineTest_Heater/2)-50)))
				if (gu8_TimerLineTest_Heater != 0)
				{
					P_HEATER_TRIAC = ON;
					P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
				}
				else
				{
					P_HEATER_TRIAC = OFF;
					P_HEATER_PWM_TDR = 0x0000;		//			TDR CLEAR
				}
			}
			else
			{
				switch (gu8_HeaterTriac_CMD)		//	히터 PWM 지시
				{
					case HEATER_OFF:				//		OFF 지시
					default:
						P_HEATER_PWM_TDR = 0x0000;	//			TDR CLEAR
						P_HEATER_TRIAC = OFF;		//			PORT OFF (Default)
						break;
					case HEATER_FIRST:
						if (gu8_TimerFirstHot_HeaterSensing != 0)
						{
							P_HEATER_TRIAC = ON;
						}
						else
						{
							P_HEATER_TRIAC = OFF;
							P_HEATER_PWM_TDR = 0x0000;		//			TDR CLEAR
						}
						break;
					case HEATER_ON:							//		100% ON 지시
						P_HEATER_TRIAC = ON;
						//@030 P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
						P_HEATER_PWM_TDR = (mu16_HeaterPWM_MaxTDR+1);	//@030
#ifdef _EFF_Continue_Heater_OFF
                        if(F_Eff_Continue_Heater_Off == SET){
                            P_HEATER_RELAY = OFF;                           //  히터 Relay Off
                            P_HEATER_TRIAC = OFF;                           //  히터 트리악 Off
                            P_HEATER_PWM_TDR = 0x0000U;                     //  히터 트리악 PWM Off
                            return;
                        }

#endif
						break;
					case HEATER_PRE:
#ifdef _EFF_Continue_Heater_OFF
                        if(F_Eff_Continue_Heater_Off == SET){
                            P_HEATER_RELAY = OFF;                           //  히터 Relay Off
                            P_HEATER_TRIAC = OFF;                           //  히터 트리악 Off
                            P_HEATER_PWM_TDR = 0x0000U;                     //  히터 트리악 PWM Off
                            return;
                        }
#endif
						if (gu8_ModelType_forNational == MODEL_KOREA)
						{
							if (F_2ndHot_Effluent_HeaterDown == SET)	//	두번째잔 히터 예열 약하게
							{
								P_HEATER_TRIAC = OFF;
								if ((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR100_JP90) || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__95) || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__90)
								|| ((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80) && (gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_HIGH)))
								{
									if (F_LatentHeat_Clear == SET)		//	잠열제거 한 경우
									{
										//cbr_test 2025-09-17 저전력 시료 과함
										if(gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_LOW)
										{//2026-01-05
											//@030 P_HEATER_PWM_TDR = (U16)((U32)((_DABF_TAU_TDR02_VALUE+1)/10) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);
											P_HEATER_PWM_TDR = (U16)((U32)((mu16_HeaterPWM_MaxTDR+1)/10) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);   //@030
										}
										else
										{
											//@030 P_HEATER_PWM_TDR = (U16)((U32)((_DABF_TAU_TDR02_VALUE+1)/4) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);
											P_HEATER_PWM_TDR = (U16)((U32)((mu16_HeaterPWM_MaxTDR+1)/4) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);     //@030
										}
									}
									else
									{
										if((gi16_HotInSensor.DEGREE >= Z_TEMP25)
										&& (gu8_Heater_PowerLevel != Z_HEATER_POWER_LEVEL_LOW))
										{
											//@030 P_HEATER_PWM_TDR = (U16)((U32)((_DABF_TAU_TDR02_VALUE+1)/50) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);	//2025-12-30
											P_HEATER_PWM_TDR = (U16)((U32)((mu16_HeaterPWM_MaxTDR+1)/50) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);	//@030
										}
										else
										{
											//@030 P_HEATER_PWM_TDR = (U16)((U32)((_DABF_TAU_TDR02_VALUE+1)/10) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);
											P_HEATER_PWM_TDR = (U16)((U32)((mu16_HeaterPWM_MaxTDR+1)/10) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);    //@030
										}
									}
								}
								else
								{
									//@030 P_HEATER_PWM_TDR = (U16)((U32)((_DABF_TAU_TDR02_VALUE+1)/4) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);
									P_HEATER_PWM_TDR = (U16)((U32)((mu16_HeaterPWM_MaxTDR+1)/4) * HEATER_FULL_WATT_KOR / gu16_HeaterFull_WATT);    //@030
								}
							}
							else
							{
								P_HEATER_TRIAC = ON;								//2025-12-30
								//@030 P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE + 1);
								P_HEATER_PWM_TDR = (mu16_HeaterPWM_MaxTDR + 1);     //@030
							}
						}
						else
						{
							P_HEATER_TRIAC = ON;
							//@030P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
							P_HEATER_PWM_TDR = (mu16_HeaterPWM_MaxTDR+1);           //@030
						}
						break;
					case HEATER_PWM:				//		PWM 지시
#ifndef _HEATER_CURRENT_CHECK_
#ifdef _EFF_Continue_Heater_OFF
                        if(F_Eff_Continue_Heater_Off == SET){
                            P_HEATER_RELAY = OFF;                           //  히터 Relay Off
                            P_HEATER_TRIAC = OFF;                           //  히터 트리악 Off
                            P_HEATER_PWM_TDR = 0x0000U;                     //  히터 트리악 PWM Off
                            return;
                        }

#endif
						P_HEATER_TRIAC = OFF;		//			PORT OFF (Default)

						if (gu16_HeaterFull_WATT >= gu16_HeaterRELAY_WATT)	//		히터 최대전력치가 RELAY보다 큰 경우 (안전처리)
						{
							mu16_Heater_work1 = gu16_HeaterFull_WATT - gu16_HeaterRELAY_WATT;	//			RELAY WATT수만큼 빼줌 (PWM 최대 WATT 취득)
						}

						if ((F_HeaterPWM_SingleControl == SET))	//	Single Control 제어거나 분유 and 예열 또는 추출 중인 경우
						{
							mu16_Heater_work2 = gu16_HeaterWATT;	//		필요 WATT 취득
							if ((gu16_HeaterFull_WATT >= gu16_HeaterRELAY_WATT) && (mu16_Heater_work2 >= (gu16_HeaterFull_WATT - gu16_HeaterRELAY_WATT)))	//		히터 최대전력치-RELAY 전력치를 최대치로 설정 (RELAY를 OFF하니)
							{
								mu16_Heater_work2 = gu16_HeaterFull_WATT - gu16_HeaterRELAY_WATT;	//	PWM 필요 전력치 취득
							}
//							else
//							{
//								mu16_Heater_work2 = gu16_HeaterFull_WATT;
//							}
						}
						else								//		상기 외
						{
							if (gu16_HeaterWATT >= gu16_HeaterRELAY_WATT)	//			히터필요 WATT가 RELAY WATT보다 큰 경우 (안전처리)
							{
								mu16_Heater_work2 = gu16_HeaterWATT - gu16_HeaterRELAY_WATT;	//	PWM 필요 전력치
							}
						}

						mi16_Buf1 = (I16)Z_TEMP20 - gi16_HotInSensor.DEGREE;
						mi16_Buf2 = (I16)gu16_FlowDecide_W - (I16)70;
						mi16_Buf2 *= 2;

						gu16_HotOut_ClearMilkHot = Z_TEMP60 + mi16_Buf1 + mi16_Buf2;    //  기준온도 + 입수온도 보정 + 유량 보정

						if ((F_MilkEff_MoreHot == SET) && (gu8_TimerHeaterControl_AfterEff == 0))
						{
							if (gu16_HotOut_Degree_Ave > gu16_HotOut_ClearMilkHot)
							{
								mu16_Heater_work2 = 0;
							}
							else
							{
								F_MilkEff_MoreHot = CLEAR;
							}
                        }
                        else
                        {
                        	// F_MilkEff_MoreHot = CLEAR;
                        }

						if ((gu8_TimerHeaterSafety_AfterEff == 0)
						&& (gu16_FlowDecide_W < (gu16_FlowTarget_W*10/11)))	//	유량이 목표유량만큼 안나오는 경우
						{
							if((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR100_JP90)
							|| (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__95)
							|| (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__90)
							|| ((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80) && (gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_HIGH))	//cbr_test 2025-09-26 198v 30도 과열
							// || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80)	//cbr_test 2025-09-25 242v 30도 미달
							)
							{
								mi16_Buf1 = gu16_FlowTarget_W - gu16_FlowDecide_W;
								if ((gi16_HotOutSensor.DEGREE > (Z_TEMP95-mi16_Buf1)) || (gi16_HeaterSensor.DEGREE > (Z_TEMP95-mi16_Buf1)))
								{
									if((gi16_HotInSensor.DEGREE > Z_TEMP25))
									{
										if(gu16_FlowDecide_W < gu16_FlowTarget_W - 10)
										{
											mu16_Heater_work2 = mu16_Heater_work2 / 100;		//cbr_test 2025-09-25
											// mu16_Heater_work2 = mu16_Heater_work2 / 10;		//test 2025-11-21
										}
										else
										{
											mu16_Heater_work2 = mu16_Heater_work2 / 30;
											// mu16_Heater_work2 = mu16_Heater_work2 / 3;		//test 2025-11-21
										}
									}
									else if(gi16_HotInSensor.DEGREE > Z_TEMP15)		//cbr_test 2025-10-01
									{
										if(gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_HIGH)
										{
											// mu16_Heater_work2 = mu16_Heater_work2 / 100;
											mu16_Heater_work2 = mu16_Heater_work2 / 50;		//2026-01-08 15:39:29
										}
										else
										{
											mu16_Heater_work2 = mu16_Heater_work2 / 4;
										}
									}
									else
									{
										if(gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_HIGH)
										{
											// mu16_Heater_work2 = mu16_Heater_work2 / 30;		//cbr_test 2025-11-28
											mu16_Heater_work2 = mu16_Heater_work2 / 20;		//cbr_test 2025-11-28
										}
										else
										{
											mu16_Heater_work2 = mu16_Heater_work2 / 4;		//cbr_test 2025-09-17
										}
									}
								}
								else if ((gi16_HotOutSensor.DEGREE <= (Z_TEMP95-mi16_Buf1-Z_TEMP2)) && (gi16_HeaterSensor.DEGREE <= (Z_TEMP95-mi16_Buf1-Z_TEMP2)))
								{
									//	감소 없음. 정상 출력
								}
								else
								{
									// mu16_Heater_work2 = mu16_Heater_work2 / 3;	//	(히스테리 시스 없음)
									// mu16_Heater_work2 = mu16_Heater_work2 / 4;		//cbr_test 2025-09-17		
									if(gi16_HotInSensor.DEGREE > Z_TEMP25)
									{
										if(gu16_FlowDecide_W < gu16_FlowTarget_W - 10)
										{
											mu16_Heater_work2 = mu16_Heater_work2 / 100;		//cbr_test 2025-09-25
										}
										else
										{
											mu16_Heater_work2 = mu16_Heater_work2 / 30;
										}
									}
									else
									{
										if(gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_HIGH)
										{
											if(gu16_FlowDecide_W < gu16_FlowTarget_W - 10)
											{
												mu16_Heater_work2 = mu16_Heater_work2 / 100;		//cbr_test 2025-12-03
											}
											else
											{
												mu16_Heater_work2 = mu16_Heater_work2 / 20;		//cbr_test 2025-11-28
											}
										}
										else
										{
											mu16_Heater_work2 = mu16_Heater_work2 / 4;		//cbr_test 2025-09-17		
										}
									}
								}
							}
							//cbr_test 2025-09-18
							else
							{
								if((gu16_FlowDecide_W >= (gu16_FlowTarget_W*4/5))
								||((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR45_JPX)
								&& (gi16_HotInSensor.DEGREE > Z_TEMP25)
								&& (gu8_Heater_PowerLevel == Z_HEATER_POWER_LEVEL_HIGH)))
								{
									if ((gi16_HotOutSensor.DEGREE > (gu16_TargetDegree-Z_TEMP0)) || (gi16_HeaterSensor.DEGREE > (gu16_TargetDegree-Z_TEMP0)))
									{
										// mu16_Heater_work2 = mu16_Heater_work2 / 3;	//
										mu16_Heater_work2 = mu16_Heater_work2 / 10;		//cbr_test 2025-09-17
									}
									else if ((gi16_HotOutSensor.DEGREE <= (gu16_TargetDegree-Z_TEMP5)) && (gi16_HeaterSensor.DEGREE <= (gu16_TargetDegree-Z_TEMP5)))
									{
										//	감소 없음. 정상 출력
									}
									else
									{
										mu16_Heater_work2 = mu16_Heater_work2 / 10;	//	(히스테리 시스 없음)
									}
								}
								else
								{
									if ((gi16_HotOutSensor.DEGREE > (gu16_TargetDegree-Z_TEMP0)) || (gi16_HeaterSensor.DEGREE > (gu16_TargetDegree-Z_TEMP0)))
									{
										// mu16_Heater_work2 = mu16_Heater_work2 / 3;	//
										mu16_Heater_work2 = mu16_Heater_work2 / 50;		//cbr_test 2025-09-17
									}
									else if ((gi16_HotOutSensor.DEGREE <= (gu16_TargetDegree-Z_TEMP5)) && (gi16_HeaterSensor.DEGREE <= (gu16_TargetDegree-Z_TEMP5)))
									{
										//	감소 없음. 정상 출력
									}
									else
									{
										mu16_Heater_work2 = mu16_Heater_work2 / 50;	//	(히스테리 시스 없음)
									}
								}
							}
						}

						if ((F_2ndHot_Effluent == CLEAR) && (gu8_TimerHeaterControl_AfterEff != 0))
						{
							P_HEATER_PWM_TDR = 0;	
						}
						else
						{
							if (((gu8_ModelType_forNational == MODEL_KOREA)
                                && ((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR100_JP90) || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__95) || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__90))
                                && (gu8_TimerHeaterSafety_AfterEff != 0))	//추출 0.7초 pwm최대치 절반
                                && ((gi16_HotInSensor.DEGREE <= Z_TEMP25)					//cbr_test 2025-11-25
								&& (gu8_Heater_PowerLevel != Z_HEATER_POWER_LEVEL_HIGH)))	//cbr_test 2025-11-25
							{
								//@030 P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1) / 2;
								P_HEATER_PWM_TDR = (mu16_HeaterPWM_MaxTDR+1) / 2;           //@030
							}
							else
							{
								/*	필요 TDR 연산 : 최대TDR / 히터필요전력치 * 히터PWM최대전력치			*/
								//@030 gu16_HeaterPWM_TDR = (U16)(((((((U32)_DABF_TAU_TDR02_VALUE+1) * 10) / mu16_Heater_work1) + 1) * mu16_Heater_work2) / 10);
								gu16_HeaterPWM_TDR = (U16)(((((((U32)mu16_HeaterPWM_MaxTDR+1) * 10) / mu16_Heater_work1) + 1) * mu16_Heater_work2) / 10);      //@030
								if ((F_Flow_Rapidly_Decrease == SET)) 		//	급 유량감소
								// || ((gu8_ModelType_forNational == MODEL_KOREA) && ((gi16_HotOutSensor.DEGREE >= Z_TEMP101)	|| (gi16_HeaterSensor.DEGREE >= Z_TEMP102))))     //	온수출수 또는 히터TH가 기준온도 이상인 경우 (과열 안전 차단)
								{
									P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 4 / 6);	//
								}
                                else if (((gu8_ModelType_forNational == MODEL_KOREA)
                                && ((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR100_JP90) || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__95) || (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__90))
                                && (gu8_TimerFlowControl_AfterEff != 0))	//고온수 추출 후 0.3초(0.7초는 절반) or 과열 시, 필요TDR 제한
								|| ((gu8_ModelType_forNational == MODEL_KOREA) && ((gi16_HotOutSensor.DEGREE >= Z_TEMP97) || (gi16_HeaterSensor.DEGREE >= Z_TEMP97))))     //	온수출수 또는 히터TH가 기준온도 이상인 경우 (과열 안전 차단)
								{
									if ((gi16_HotOutSensor.DEGREE >= Z_TEMP101) || (gi16_HeaterSensor.DEGREE >= Z_TEMP101))
									{
										P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 0 / 10);		//0%
									}
									else if ((gi16_HotOutSensor.DEGREE >= Z_TEMP100) || (gi16_HeaterSensor.DEGREE >= Z_TEMP100))
									{
										P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 1 / 50);		//2026-01-05 19:32:05
									}
									else if ((gi16_HotOutSensor.DEGREE >= Z_TEMP99) || (gi16_HeaterSensor.DEGREE >= Z_TEMP99))
									{
										P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 1 / 50);		//2026-01-05 19:32:42
									}
									else if ((gi16_HotOutSensor.DEGREE >= Z_TEMP98_5) || (gi16_HeaterSensor.DEGREE >= Z_TEMP98_5))
									{
										P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 1 / 20);		//2026-01-05 19:33:03
									} //2025-12-26
									else
									{
										P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 3 / 10);		//cbr_test 2025-09-24
									}
								}
								//cbr_test 2025-09-17 예열4초 & 추출 4초 동안 들어와서 스팀 
								// else if (gu8_TimerHeaterLimit != 0)
								// {
								// 	P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 4 / 7);	//57%
								// }
								else						//	일반제어
								{
#ifdef _FOR_DEVELOP_
									if (gu16_HeaterPWM_TDR_Test != 0) gu16_HeaterPWM_TDR = gu16_HeaterPWM_TDR_Test;
#endif
                                    //@030 if (gu16_HeaterPWM_TDR > (_DABF_TAU_TDR02_VALUE+1))
									if (gu16_HeaterPWM_TDR > (mu16_HeaterPWM_MaxTDR+1))    //@030
									{
										//@030 P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
										P_HEATER_PWM_TDR = (mu16_HeaterPWM_MaxTDR+1);     //@030
									}
									else if (gu16_HeaterPWM_TDR == 0)
									{
										P_HEATER_PWM_TDR = 0x0000;
									}
									else
									{
                                    	if(gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__75){
                                    		if(gi16_HotInSensor.DEGREE <= Z_TEMP15){
												//@030 P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
                                    			P_HEATER_PWM_TDR = (mu16_HeaterPWM_MaxTDR+1);     //@030
                                    		}
                                    		else if(gi16_HotInSensor.DEGREE >= Z_TEMP25){
                                    			if(F_Heater_Decrease == SET){
                                    				P_HEATER_PWM_TDR = (U16)((U32)(gu16_HeaterPWM_TDR+1) * 4 / 10);
                                    			}
                                    			else{
                                    				P_HEATER_PWM_TDR = gu16_HeaterPWM_TDR+1;
                                    			}
                                    		}
                                    		else{
                                    			P_HEATER_PWM_TDR = gu16_HeaterPWM_TDR+1;
                                    		}
                                    	}
                                    	else if(gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__60){
                                			if((F_Heater_Decrease == SET)
											|| ((gi16_HotOutSensor.DEGREE >= gu16_TargetDegree+Z_TEMP8) || (gi16_HeaterSensor.DEGREE >= gu16_TargetDegree+Z_TEMP8)))
											{
//@cjh241217                              		P_HEATER_PWM_TDR = (U16)((U32)(gu16_HeaterPWM_TDR+1) * 4 / 10);
                                				P_HEATER_PWM_TDR = (U16)((U32)(gu16_HeaterPWM_TDR+1) * 7 / 20);		//@cjh241217
                                			}
                                			else{
                                				P_HEATER_PWM_TDR = gu16_HeaterPWM_TDR+1;
                                			}
                                    	}
                                       	else if(gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__50)
										{
											if((gi16_HotOutSensor.DEGREE >= gu16_TargetDegree+Z_TEMP10) || (gi16_HeaterSensor.DEGREE >= gu16_TargetDegree+Z_TEMP10))
											{
												P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 3 / 10);		//30%
											}
											else
											{
												P_HEATER_PWM_TDR = gu16_HeaterPWM_TDR+1;
											}
                                       	}
										else if(gu8_HotTempSetup == HOT_TEMP_SETUP_KOR45_JPX)
										{
											if ((gi16_HotOutSensor.DEGREE >= Z_TEMP50) || (gi16_HeaterSensor.DEGREE >= Z_TEMP50))		//cbr_test 2025-09-15
											{
												if(((gi16_HotInSensor.DEGREE > Z_TEMP25) && (gu16_HeaterFull_WATT >= 2500))
												|| ((gi16_HotInSensor.DEGREE > Z_TEMP15) && (gu16_HeaterFull_WATT >= 3300)))
												{
													P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 2 / 10);		//0%
												}
												else
												{
													P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 2 / 10);		//20%
												}
											}
											else if((gi16_HotOutSensor.DEGREE >= gu16_TargetDegree) || (gi16_HeaterSensor.DEGREE >= gu16_TargetDegree))
											{
												P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 5 / 10);		//50%
											}
											else
											{
												P_HEATER_PWM_TDR = gu16_HeaterPWM_TDR+1;
											}
										}
										else if((gu8_HotTempSetup == HOT_TEMP_SETUP_KOR85_JP80)
											|| (gu8_HotTempSetup == HOT_TEMP_SETUP_KOR__80))
										{
											if ((gi16_HotOutSensor.DEGREE >= (Z_TEMP92))
											&& (gi16_HeaterSensor.DEGREE >= (Z_TEMP94)))		//cbr_test 2025-10-01
											{
												P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 1 / 10);		//10%
											}
											else if ((gi16_HotOutSensor.DEGREE >= (gu16_TargetDegree+Z_TEMP5))		//cbr_test 2025-09-29
											|| (gi16_HeaterSensor.DEGREE >= (gu16_TargetDegree+Z_TEMP7)))		//cbr_test 2025-09-29
											{
												P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 2 / 10);		//20%
											}
											else if ((gi16_HotOutSensor.DEGREE >= (gu16_TargetDegree-Z_TEMP0))
											|| (gi16_HeaterSensor.DEGREE >= (gu16_TargetDegree+Z_TEMP2)))		//cbr_test 2025-09-29
											{
												P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 4 / 10);		//40%
											}
											else
											{
												P_HEATER_PWM_TDR = gu16_HeaterPWM_TDR+1;		//cbr_test 2025-09-15
											}
										}
                                    	else
										{
											if ((gi16_HotOutSensor.DEGREE >= (gu16_TargetDegree-Z_TEMP3))
											&& (gi16_HeaterSensor.DEGREE >= (gu16_TargetDegree-Z_TEMP3)))		//cbr_test 2025-09-22
											{
												P_HEATER_PWM_TDR = (U16)((U32)gu16_HeaterPWM_TDR * 3 / 10);		//30%
											}
											else
											{
												P_HEATER_PWM_TDR = gu16_HeaterPWM_TDR+1;		//cbr_test 2025-09-15
											}
                                    	}
									}
								}
							}
						}
#else
								P_HEATER_TRIAC = ON;
								P_HEATER_PWM_TDR = (_DABF_TAU_TDR02_VALUE+1);
#endif
						break;
				}
			}
		}
	}
}

/// @brief    TEM 제어
/// @param    void
/// @return   void
static void Output_TEM(void)
{
	U8 i = 0;
	U16 TEM_TDR_Data = 0;
	U16 TEM_TDR_Data_Bojung = 0;					

	if (F_TestMode_PBA == SET)
	{
		if (gu8_PBATest_ColdLoad == 3)
		{
            P_TEM_24V_ONOFF = OFF;
            P_TEM_12V_ONOFF = ON;
            P_TEM_PWM_TDR = TEM_PWM_FULL_TDR;
		}
		else if (gu8_PBATest_ColdLoad == 4)
		{
            P_TEM_24V_ONOFF = ON;
            P_TEM_12V_ONOFF = OFF;
            P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
		}
		else
		{
            P_TEM_24V_ONOFF = OFF;
            P_TEM_12V_ONOFF = OFF;
            P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
		}
	}
	else if (F_TestMode_LineTest2 == SET)
	{
		if (gu8_TimerLineTest2_Cooling != 0)
		{
            P_TEM_24V_ONOFF = ON;
            P_TEM_12V_ONOFF = OFF;
            P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
		}
		else									
		{                                       
            P_TEM_24V_ONOFF = OFF;
            P_TEM_12V_ONOFF = OFF;
            P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
		}                                       
	}
	else if (F_TestMode_LineAuto == SET)
	{
		if (F_LineTest_TEM == SET)
		{
            P_TEM_24V_ONOFF = ON;
            P_TEM_12V_ONOFF = OFF;
            P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
		}
		else
		{
            P_TEM_24V_ONOFF = OFF;
            P_TEM_12V_ONOFF = OFF;
            P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
		}
	}
	else if (F_TestMode_LineFront == SET)
	{
        P_TEM_24V_ONOFF = OFF;
        P_TEM_12V_ONOFF = OFF;
        P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
	}
	else if(gu8_f_ad_feedback_mode == SET)
	{
		if(gu8_Timer_Forced_TemOutput != 0)
		{
			P_TEM_PWM_TDR = TEM_PWM_FULL_TDR;
			P_TEM_24V_ONOFF = ON;
			P_TEM_12V_ONOFF = OFF;
		}
		else 
		{
			P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
			P_TEM_24V_ONOFF = OFF;
			P_TEM_12V_ONOFF = OFF;
		}
	}
	else
	{
		if ((gu8_SmartCheckStep & 0xF0) == 0x20)
		{
			if (F_SmartCheck_TEM == SET)
			{
				P_TEM_PWM_TDR = TEM_PWM_FULL_TDR;
				P_TEM_24V_ONOFF = ON;
				P_TEM_12V_ONOFF = OFF;
			}
			else
			{
				P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
				P_TEM_24V_ONOFF = OFF;
				P_TEM_12V_ONOFF = OFF;
			}
		}
		else
		{
            switch (gu8_TEM_PWM_CMD)
            {
                case TEM_PWM_OFF:
                default:
                    gu16_TEM_Voltage = 0;
                    break;
                case TEM_PWM_RAPID:
                    /*  12℃이상 : 24v 출력
                     *  6℃ 이상 ~ 12℃ 미만 : 12V출력
                     *  외기온도센서 에러 : 12℃ 이상 ~ 30℃미만 조건으로 출력
                     */

					#if 0
                    //  야간모드인경우는 약모드 들어가기 위해 FLAG 봐야함
                    if(F_ColdTemp == COLD_TEMP_HIGH)
                    {
                        //  외기온도센서 아닌경우,
                        if(F_Err43_OutDoorAirTH == CLEAR)
                        {
                            if (gi16_OutDoorAirSensor.DEGREE >= Z_TEMP12)
                            {
                            	gu16_TEM_Voltage = Z_Cooling_Voltage_24V;
                            }
                            else
                            {
                            	gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
                            }
                        }
                        else
                        {
                            //  외기온도센서인경우, 24v 고정.
                            gu16_TEM_Voltage = Z_Cooling_Voltage_24V;
                        }
                    }
                    else        /***************냉수 약모드*******************/
                    {
                        //  외기온도센서 아닌경우,
                        if(F_Err43_OutDoorAirTH == CLEAR)
                        {
                            if (gi16_OutDoorAirSensor.DEGREE >= Z_TEMP12)
                            {
                            	gu16_TEM_Voltage = Z_Cooling_Voltage_24V;
                            }
                            else
                            {
                            	gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
                            }
                        }
                        else
                        {
                            //  외기온도센서인경우, 24v 고정.
                            gu16_TEM_Voltage = Z_Cooling_Voltage_24V;
                        }
                    }
					#endif
					//  외기온도센서 아닌경우,
					if(F_Err43_OutDoorAirTH == CLEAR)
					{
						if (gi16_OutDoorAirSensor.DEGREE >= Z_TEMP12)
						{
							gu16_TEM_Voltage = Z_Cooling_Voltage_24V;
						}
						else
						{
							gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
						}
					}
					else
					{
						//  외기온도센서인경우, 24v 고정.
						gu16_TEM_Voltage = Z_Cooling_Voltage_24V;
					}					

                    //	급속모드 진입 후, 5분간은 12v 출력
                    if(gu16_Timer_CoolingRapid_12V != 0)
                    {
                    	gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
                    }

                    //  Voltage에 따른, TDR 값 세팅.
                    for (i = 0 ; i < Z_TEM_Voltage_Data_Max ; i++)
                    {
                        if (gu16_TEM_Voltage == TEM_Voltage_DataTable[i].TEM_Volt)
                        {
                            TEM_TDR_Data = TEM_Voltage_DataTable[i].TEM_TDR;
                            break;
                        }
                    }
                    break;
                case TEM_PWM_RETAIN:                //  유지모드

					#if 0
                    //  냉수 강모드
                    //  야간모드인경우는 약모드 들어가기 위해 FLAG 봐야함
                    if(F_ColdTemp == COLD_TEMP_HIGH) 
                    {
                        if(gi16_ColdSensor.DEGREE >= Z_TEMP5)
						{
                            gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
                        }
                        else
                        {
                            gu16_TEM_Voltage = Z_Cooling_Voltage_5V;
                        }
                    }   
                    else        //  냉수 약모드
                    {
                        if(gi16_ColdSensor.DEGREE >= Z_TEMP10_5)
						{
                            gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
                        }
                        else
                        {
                            gu16_TEM_Voltage = Z_Cooling_Voltage_5V;
                        }
                    }
					#endif
					if(gi16_ColdSensor.DEGREE >= Z_TEMP5)
					{
						gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
					}
					else
					{
						gu16_TEM_Voltage = Z_Cooling_Voltage_5V;
					}					

                    //  Voltage에 따른, TDR 값 세팅.
                    for (i = 0 ; i < Z_TEM_Voltage_Data_Max ; i++)
                    {
                        if (gu16_TEM_Voltage == TEM_Voltage_DataTable[i].TEM_Volt)
                        {
                            TEM_TDR_Data = TEM_Voltage_DataTable[i].TEM_TDR;
                            break;
                        }
                    }
                    break;
                case TEM_PWM_ECOMODE:
                    if (gi16_ColdSensor.DEGREE >= Z_TEMP11)
                    {
                        gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
                    }
					else if(gi16_ColdSensor.DEGREE >= Z_TEMP7)
					{
						gu16_TEM_Voltage = Z_Cooling_Voltage_9V;
					}
                    else
                    {
                        gu16_TEM_Voltage = Z_Cooling_Voltage_6V;
                    }

                    //  Voltage에 따른, TDR 값 세팅.
                    for (i = 0 ; i < Z_TEM_Voltage_Data_Max ; i++)
                    {
                        if (gu16_TEM_Voltage == TEM_Voltage_DataTable[i].TEM_Volt)
                        {
                            TEM_TDR_Data = TEM_Voltage_DataTable[i].TEM_TDR;
                            break;
                        }
                    }
                    break;
                case TEM_PWM_ECO_9V:
					#if 0
					if (gi16_ColdSensor.DEGREE >= Z_TEMP9)
                    {
                        gu16_TEM_Voltage = Z_Cooling_Voltage_12V;
                    }
                    else
                    {
                        gu16_TEM_Voltage = Z_Cooling_Voltage_5V;
                    }
					#endif
					gu16_TEM_Voltage = Z_Cooling_Voltage_9V;

                    if (F_Cooling_Up == SET)            //  특수모드 냉각성능 Up
                    {
                        gu16_TEM_Voltage += Z_CoolingUp_Volatage;
                    }

                    for (i = 0 ; i < Z_TEM_Voltage_Data_Max ; i++)
                    {
                        if (gu16_TEM_Voltage == TEM_Voltage_DataTable[i].TEM_Volt)
                        {
                            TEM_TDR_Data = TEM_Voltage_DataTable[i].TEM_TDR;
                            break;
                        }
                    }
                    break;
                case TEM_PWM_MIN:
                    gu16_TEM_Voltage = TEM_Voltage_DataTable[(Z_TEM_Voltage_Data_Max-1)].TEM_Volt;
                    TEM_TDR_Data = TEM_Voltage_DataTable[(Z_TEM_Voltage_Data_Max-1)].TEM_TDR;
                    break;
            }

    //    	  gu16_TEM_Voltage =  gu16_TEM_Voltage_Test;

            /*  1) 24V → 5 ~ 12V PWM 출력 전환
            *  2) 5 ~ 12V ~ 24V 출력 전환
            *    → 상기 2가지 조건에서 일 경우, 최소 1ms 출력 딜레이 필요(전장회로개발팀 확인)
            */
            //  출력 값 최소 1분 유지.
            if((gu8_CoolingStep >= Z_CoolingStep_20) && (gu8_CoolingStep <= Z_CoolingStep_24))
            {
                if(gu16_TEM_Voltage != gu16_TEM_Voltage_Backup)
                {
                    if(gu8_Timer_TEM_Voltage_Retain == 0)
                    {
                        gu8_Timer_TEM_Voltage_Retain = 60;
                    }
                    else
                    {
                        gu16_TEM_Voltage = gu16_TEM_Voltage_Backup;
                        TEM_TDR_Data = gu16_TEM_TDR_Data_Backup;
                    }
                }

                gu16_TEM_Voltage_Backup = gu16_TEM_Voltage;                     //  출력 전압 값 backup
                gu16_TEM_TDR_Data_Backup = TEM_TDR_Data;
            }
            else
            {
                gu8_Timer_TEM_Voltage_Retain = 0;

                gu16_TEM_Voltage_Backup = 0;
                gu16_TEM_TDR_Data_Backup = 0;
            }
            //  Voltage에 따른, 열전모듈 출력
            /*  1) 24V 출력 :
            *       - TEM ON/OFF 포트 : ON
            *       - TEM 12V ON/OFF 포트 : OFF
            *  2) 5 ~ 12V PWM :
            *
            *
            */
            if(gu16_TEM_Voltage == Z_Cooling_Voltage_24V)
            {
                P_TEM_24V_ONOFF = ON;

                if(gu8_Timer_TEM_12V_OffDelay == 0)
                {
                    P_TEM_12V_ONOFF = OFF;
                }
                P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
                gu8_Timer_TEM_24V_OffDelay = 100;
            }
            else if((gu16_TEM_Voltage >= Z_Cooling_Voltage_5V) && (gu16_TEM_Voltage <= Z_Cooling_Voltage_12V))
            {
                P_TEM_12V_ONOFF = ON;
                P_TEM_PWM_TDR = TEM_TDR_Data;
                if(gu8_Timer_TEM_24V_OffDelay == 0)
                {
                    P_TEM_24V_ONOFF = OFF;
                }
                else
                {
                    P_TEM_24V_ONOFF = ON;
                }

                gu8_Timer_TEM_12V_OffDelay = 100;
            }
            else
            {
                P_TEM_24V_ONOFF = OFF;
                P_TEM_12V_ONOFF = OFF;
                P_TEM_PWM_TDR = TEM_PWM_OFF_TDR;
                gu16_TEM_Voltage = 0;
            }
		}
	}
}

/// @brief    누수센서 Pulse 출력 (1ms 주기)
/// @param    void
/// @return   void
static void Output_LeakSensor(void)
{
	if (F_TestMode_PBA == SET)
	{
		if (F_PBATest_LeakSensorOFF == SET)
		{
			P_LEAKSENSOR_OFF = HIGH;
		}
		else
		{
			P_LEAKSENSOR_OFF = LOW;
		}
	}
	else
	{
		P_LEAKSENSOR_OFF = LOW;
	}
//	if (gu8_LeakSensor_CMD == ON)
//	{
//		P_LEAKSENSOR_ONOFF = ON;
//	}
//	else
//	{
//		P_LEAKSENSOR_ONOFF = OFF;
//	}
//	P_LEAKSENSOR_ONOFF ^= 1;						//	1ms 마다 반전 출력 (※ 스케일링?)
}


/// @brief    FAN 제어
/// @param    void
/// @return   void
static void Output_FAN(void)
{
    U8 mu8_temp = 0;
    static U8 flag_PL_Prevent = CLEAR;  //  SMPS FET 쇼트로 인한 TEM과열 방지를 위해 Fan 가동 플래그 220929

    if (F_TestMode_PBA == SET)
    {
        switch (gu8_PBATest_FanTest)
        {
            case 0:
            default:
                P_FAN_18V = OFF;
                P_FAN_21V = OFF;
#ifndef _FAN_CIRCUIT_CHANGE_
                P_FAN_ONOFF = OFF;
#endif
                break;
            case 1:
                P_FAN_18V = OFF;
                P_FAN_21V = ON;
#ifndef _FAN_CIRCUIT_CHANGE_
                P_FAN_ONOFF = ON;
#endif
                break;
            case 2:
                P_FAN_18V = ON;
                P_FAN_21V = ON;
#ifndef _FAN_CIRCUIT_CHANGE_
                P_FAN_ONOFF = ON;
#endif
                break;
#ifndef _FAN_CIRCUIT_CHANGE_
            case 3:
                P_FAN_18V = ON;
                P_FAN_21V = ON;
                P_FAN_ONOFF = OFF;
                break;
#endif
        }
    }
    else if (F_TestMode_LineTest2 == SET)
    {
        if (F_LineTest2_CoolingResult_OK == SET)    //  냉각 검사가 완료되면 팬 가동
        {
            P_FAN_18V = OFF;
            P_FAN_21V = ON;
        }
        else
        {
            P_FAN_18V = OFF;
            P_FAN_21V = OFF;
        }
#ifndef _FAN_CIRCUIT_CHANGE_
        P_FAN_ONOFF = OFF;
#endif
    }
    else if (F_TestMode_LineAuto == SET)
    {
        if (F_LineTest_Fan == SET)
        {
#ifndef _FAN_CIRCUIT_CHANGE_
            P_FAN_ONOFF = ON;
#endif
            P_FAN_21V = ON;
        }
        else
        {
#ifndef _FAN_CIRCUIT_CHANGE_
            P_FAN_ONOFF = OFF;
#endif
            P_FAN_21V = OFF;
        }
    }
    else if (F_TestMode_LineFront == SET)
    {
#ifndef _FAN_CIRCUIT_CHANGE_
        P_FAN_ONOFF = ON;
#endif
        P_FAN_21V = ON;
//      P_FAN_18V = OFF;
    }
    else
    {
        if ((gu8_SmartCheckStep & 0xF0) == 0x20)
        {
            if (F_SmartCheck_Fan == SET)
            {
#ifndef _FAN_CIRCUIT_CHANGE_
                P_FAN_ONOFF = ON;
#endif
                P_FAN_18V = OFF;
                P_FAN_21V = ON;
            }
            else
            {
#ifndef _FAN_CIRCUIT_CHANGE_
                P_FAN_ONOFF = OFF;
#endif
                P_FAN_18V = OFF;
                P_FAN_21V = OFF;
            }
        }
        else
        {
            switch (gu8_FAN_CMD)
            {
                case FAN_OFF:
                default:
                    if (gi16_HeatSinkSensor.DEGREE > Z_TEMP80)
                    {
                        flag_PL_Prevent = SET;
                    }
                    else if (gi16_HeatSinkSensor.DEGREE <= Z_TEMP60)
                    {
                        flag_PL_Prevent = CLEAR;
                    }
                    else
                    {

                    }

                    if (flag_PL_Prevent == SET)
                    {
                        if (gu8_TimerFanDelay == 0)
                        {
                            P_FAN_18V = OFF;
                            P_FAN_21V = ON;
                        }
                        else
                        {
                            P_FAN_18V = OFF;
                            P_FAN_21V = OFF;
                        }
                    }
                    else
                    {
                        P_FAN_18V = OFF;
                        P_FAN_21V = OFF;
                        gu8_TimerFanDelay = Z_TimerFanDelay;
                    }
                    break;
                case FAN_18V_ON:
                    if (gu8_TimerFanDelay == 0)
                    {
                        if(gu8_CoolingStep == Z_CoolingStep_21)
                        {
							if(gi16_ColdSensor.DEGREE >= Z_TEMP5)
							{
                                P_FAN_18V = ON;
                                P_FAN_21V = ON;
							}
							else
							{
								if(gi16_OutDoorAirSensor.DEGREE >= Z_TEMP20)
								{
									P_FAN_18V = ON;
									P_FAN_21V = ON;
								}
								else
								{
									P_FAN_18V = OFF;
									P_FAN_21V = OFF;
								}
							}
                        }
                        else
                        {
                            P_FAN_18V = ON;
                            P_FAN_21V = ON;                            
                        }
                    }				
                    break;
                case FAN_21V_ON:
                    if (gu8_TimerFanDelay == 0)
                    {
                        if (F_FAN_NoiseClear == SET)    //  특수모드 팬 전압 하강
                        {
                            P_FAN_18V = ON;         //      특수모드 설정 경우 급속모드도 18V로 변경
                            P_FAN_21V = ON;
                        }
                        else
                        {
                            P_FAN_18V = OFF;
                            P_FAN_21V = ON;
                        }
                    }
                    break;
            }
        }
    }
}

/// @brief
/// @param    void
/// @return   void
static void Output_ColdSensor_ONOFF(void)
{
	if ((F_TestMode.byte != 0x00) || (F_Err44_ColdTH == SET) || ((gu8_SmartCheckStep & 0xF0) == 0x20))		//	스마트진단일때도 상시 ON
	{
		F_ColdSensor_OFF = CLEAR;					//		상시 ON
		gu16_TimerColdSensor_ON = Z_TimerColdSensor_ON;
	}

	if ((F_ColdSensor_OFF == CLEAR) && (gu16_TimerColdSensor_ON == 0))	//	ON상태 및 센서ON 타이머 경과 된 경우
	{
		gu16_TimerColdSensor_OFF = Z_TimerColdSensor_OFF;	//		OFF 타이머 set
		F_ColdSensor_OFF = SET;							//		센서 읽기 OFF
	}

	if ((F_ColdSensor_OFF == SET) && (gu16_TimerColdSensor_OFF == 0) && (F_ColdOff == CLEAR))	//	OFF상태 및 센서OFF 타이머 경과 된 경우 및 냉각ON상태만
	{
		gu16_TimerColdSensor_ON = Z_TimerColdSensor_ON;		//		ON 타이머 set
		if (F_TestMode.byte == 0x00)
		{
			gu8_TimerColdSensor_Sensing = Z_TimerColdSensor_Sensing;
		}
		F_ColdSensor_OFF = CLEAR;							//		센서 읽기 ON
	}

	if (F_TestMode_PBA == SET)						//	PBA제조업체 검사모드 인 경우
	{
		if (F_PBATest_ColdSensorOFF == SET)
		{
			P_COLDSENSOR_ON = LOW;
		}
		else
		{
			P_COLDSENSOR_ON = HIGH;
		}
	}
	else											//	일반 모드 or 공장자동화
	{
		if (F_ColdSensor_OFF == CLEAR)				//		센서 읽기 ON 상태인 경우
		{
			P_COLDSENSOR_ON = HIGH;
		}
		else
		{
			P_COLDSENSOR_ON = LOW;
		}
	}
}

/// @brief
/// @param    void
/// @return   void
static void Output_FCT_TxRx(void)
{
	if (F_TestMode_PBA == SET)
	{
		if (P_FCT_Rx == LOW)
		{
			P_FCT_Tx = HIGH;
		}
		else
		{
			P_FCT_Tx = LOW;
		}
	}
}

static void Output_UV(void)
{
	if (F_TestMode_PBA == SET)
    {
		if(gu8_PBATest_UV == SET)
		{
			P_UV = 1;
		}
		else
		{
			P_UV = 0;
		}
	}
	else if(F_TestMode_LineFront == SET)
	{
		if(gu8_Timer_LineTest_UV_FB != 0)
		{
			P_UV = 1;
		}
		else
		{
			P_UV = 0;
		}
	}
	else
	{	
		if ((gu8_SmartCheckStep & 0xF0) == 0x20)
		{
			if (F_SmartCheck_UV == SET)
			{
				P_UV = 1;
			}
			else
			{
				P_UV = 0;
			}
		}
		else if(gu8_OperationStep == Z_OperationStep_50)
		{
			if((gu8_WaterSelect == PURE_WATER) || (gu8_WaterSelect == COLD_WATER))
			{
				P_UV = 1;
				gu8_F_UV_First_On = SET;
			}
			else
			{
				P_UV = 0;
			}
		}
		#ifndef _FOR_DEV_REGULAR_UV_OFF
		else if(gu16_TimerUV_Oper != 0)
		{
			P_UV = 1;
			gu8_F_UV_First_On = SET;
		}
		#endif
		else
		{
			gu8_F_UV_Display = CLEAR;
			gu8_Timer_UV_Display = 140;
			P_UV = 0;
		}
	}
}

/// @brief
/// @param    void
/// @return   void
static void Output_Power(void)
{
	P_STANDBY = 1;
}

/// @brief
/// @param    void
/// @return   void
static void Output_Welcome_LED(void)
{
	if (F_TestMode_PBA == SET)
	{
		if(F_PBATest_FaucetStepmotorWay == 1)
		{
			P_WELCOME_LED = SET;
		}
		else
		{
			P_WELCOME_LED = CLEAR;
		}
	}
	else if(F_TestMode_LineFront == SET)
	{
		if(F_LineFrontTest_Effluent_Oper == SET)
		{
			P_WELCOME_LED = SET;
		}
		else
		{
			P_WELCOME_LED = CLEAR;
		}
	}
	else
	{
		if(gu8_F_WelcomeLed_Enable == SET)
		{
			if(gu8_Timer_WelcomeLed_On != 0)
			{
				P_WELCOME_LED = SET;
			}
			else
			{
				P_WELCOME_LED = CLEAR;
			}
		}
		else
		{
			P_WELCOME_LED = CLEAR;
		}
	}
}