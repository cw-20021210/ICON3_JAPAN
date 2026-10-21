/// @file     input.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    입력 처리 file
#define INPUT_C
#include "include/_include.h"

static void Check_Faucet_Detect_Undetect_Detect(void);  // ?뙆?슦?뀑 媛먯?? -> 誘멸컧吏? -> 媛먯?? ?뙣?꽩 泥댄겕
static void Check_MicroSW_LongDetection(void);

/// @brief    디지털 입력 초기화
/// @param    void
/// @return   void
void Input_Initialize(void)
{
	gu8_Timer_FaucetTip_Reed_Undetected = 20;
	gu8_F_FaucetTip_Reed_Undetected = CLEAR;
	gu8_Timer_FaucetTip_Reed_Detected = 20;
	gu8_F_FaucetTip_Reed_Detected = CLEAR;
	
	// 파우셋 감지 상태 추적 변수 초기화
	gu8_F_Faucet_Detected_Before = CLEAR;
	gu8_F_Faucet_Was_Undetected = CLEAR;

	// 마이크로 스위치 10분 지속 감지 초기화
	gu16_Timer_MicroSW_LongDetection = Z_TIMER_MICROSW_LONG_DETECTION;       // 10분 (10ms * 60000 = 600초)
	gu8_F_MicroSW_LongDetection_1h = CLEAR;
	gu8_Timer_MicroSW_Release_Check = Z_TIMER_MICROSW_RELEASE_CHECK;          // 2초 (10ms * 200 = 2초)	
}

/// @brief    디지털 입력 제어
/// @param    void
/// @return   void
void InputControl(void)
{
	BYTE_BIT mu8_inputdata;
	static U8 mu8_Prev_MicroSW_State = CLEAR;		// 이전 마이크로 스위치 상태 저장 // @001

	if (F_10ms_for_InputDigital ==  SET)			//	10ms 주기
	{
		F_10ms_for_InputDigital = CLEAR;

		mu8_inputdata.Bit.b0 = !P_REED_SW_COVER;
		mu8_inputdata.Bit.b1 = !P_REED_SW_FILTER;
		mu8_inputdata.Bit.b2 = !P_REED_SW_WATERFLOW;
		mu8_inputdata.Bit.b4 = !P_MICRO_SWITCH_FAUCET;
		mu8_inputdata.Bit.b5 = !P_REED_SW_FAUCET_UP;
		mu8_inputdata.Bit.b6 = !P_REED_SW_FAUCET_DOWN;		

		ThreeMatchModule(&gu8_DigitalInput, mu8_inputdata.byte);	//	디지털 입력 3회 일치 모듈

		
		if(gu8_F_Test_Input_ForcedControl == 1)
		{
			INPUT_REED_SW_COVER = INPUT_REED_SW_COVER_Test;
			INPUT_REED_SW_FILTER = INPUT_REED_SW_FILTER_Test;
			INPUT_REED_SW_FAUCET = INPUT_REED_SW_WATERFLOW_Test;
		}
	}
	
	//	파우셋 내러와있으면, 파우셋 간섭으로 필터커버 안열리기때문에 마이크로 스위치 입력으로 강제 상승 제어 추가
	//	auto 가 아닌경우에만 올리기 위해 동작.
	if(gu8_FaucetMoving_Set_Level >= Z_FAUCET_MOVING_FIX_2_LEVEL)
	{
		#if 0 // @001
		if(INPUT_MICRO_SW_FAUCET == SET)
		{
			if(gu8_Timer_InputMicroSW_ForcedFaucetUp == 0)
			{
				if(gu8_F_InputMicroSW_ForcedFaucetUp == CLEAR)
				{
					gu8_F_InputMicroSW_ForcedFaucetUp = SET;				
				}
			}
			else
			{
				// gu8_F_InputMicroSW_ForcedFaucetUp = CLEAR;
			}
		}
		else
		{
			gu8_Timer_InputMicroSW_ForcedFaucetUp = 30;
		}
		#endif
		if(INPUT_MICRO_SW_FAUCET == CLEAR)						// @001
		{														// @001
			// 미감지 상태에서는 타이머 리셋 및 플래그 초기화		// @001
			gu8_Timer_InputMicroSW_ForcedFaucetUp = 30;		// 3초 = 30 * 100ms	// @001
			gu8_F_InputMicroSW_ForcedFaucetUp = CLEAR;			// @001
			mu8_Prev_MicroSW_State = CLEAR;						// @001
			gu8_F_FirstInputMicroSW_ForcedFaucetUp = CLEAR;		// @001
		}														// @001
		else													// @001
		{														// @001									
			// 감지 상태에서 타이머 경과 후 플래그 설정			// @001
			if((gu8_Timer_InputMicroSW_ForcedFaucetUp == 0)			// @001
			&& (gu8_F_FirstInputMicroSW_ForcedFaucetUp == CLEAR))
			{													// @001
				if(gu8_F_InputMicroSW_ForcedFaucetUp == CLEAR)		// @001
				{												// @001
					gu8_F_InputMicroSW_ForcedFaucetUp = SET;		// @001
					gu8_F_FirstInputMicroSW_ForcedFaucetUp = SET;	// @001
				}												// @001
			}													// @001
		}	
	}

	// 팁 리드스위치 미감지 체크 (1초 딜레이)
	if(INPUT_REED_SW_FAUCET == CLEAR)
	{
		// 타이머 경과 후 미감지로 판단
		if(gu8_Timer_FaucetTip_Reed_Undetected == 0)
		{
			// 팁 리드스위치 미감지 플래그 설정
			gu8_F_FaucetTip_Reed_Undetected = SET;
		}
		// 팁 리드스위치 미감지 상태에서는 감지 타이머 리셋
		gu8_Timer_FaucetTip_Reed_Detected = 20;
		gu8_F_FaucetTip_Reed_Detected = CLEAR;
	}
	else
	{
		// 팁 리드스위치가 감지되면 미감지 타이머와 플래그 리셋
		gu8_Timer_FaucetTip_Reed_Undetected = 20;
		gu8_F_FaucetTip_Reed_Undetected = CLEAR;
		
		// 타이머 경과 후 감지로 판단
		if(gu8_Timer_FaucetTip_Reed_Detected == 0)
		{
			// 팁 리드스위치 감지 플래그 설정
			gu8_F_FaucetTip_Reed_Detected = SET;
			gu8_F_FaucetTip_Undetected_Voice_Done = CLEAR;   //@022
			gu8_F_FaucetTip_Undetected_Display_Done = CLEAR; // @022 디스플레이 1회 플래그 리셋
		}
	}
	
	// 파우셋 감지 -> 미감지 -> 감지 패턴 체크
	Check_Faucet_Detect_Undetect_Detect();

	Check_MicroSW_LongDetection();	
}

/// @brief    기종 확정
/// @param    void
/// @return   void
void Model_Decide(void)
{
	gu8_ModelType_forNational = MODEL_KOREA;		//	국내향으로...


	if (gu8_ModelType_forNational == MODEL_JAPAN)	//	일본향
	{
		gu16_HeaterFull_WATT = HEATER_FULL_WATT_JP;		//	히터 최대출력 WATT 초기치 저장
		gu16_HeaterRELAY_WATT = HEATER_RELAY_WATT_JP;

		gu16_FlowMeter_Standard = Z_FlowMeter_Standard_JP;
		gu16_FlowMeter_Standard_forHotWater = Z_FlowMeter_Standard_forHotWater_JP;
		gu16_Spec_FlowMeter = (U16)((U32)166666 / Z_FlowMeter_Standard_JP);	//		유량센서 spec 기준 데이터 처리

		F_HotLock = SET;
	}
	else											//	국내향
	{
		gu16_HeaterFull_WATT = HEATER_FULL_WATT_KOR;	//	히터 최대출력 WATT 초기치 저장
		gu16_HeaterRELAY_WATT = HEATER_RELAY_WATT_KOR;

		gu16_FlowMeter_Standard = Z_FlowMeter_Standard_KOR;
#ifdef _DPP_FLOWMETER_
		gu16_FlowMeter_Standard_forHotWater = Z_FlowMeter_Standard_KOR;
	//	gu16_FlowMeter_Standard_forHotWater_forJapan = Z_FlowMeter_Standard;
#else
		gu16_FlowMeter_Standard_forHotWater = Z_FlowMeter_Standard_forHotWater_KOR;
	//	gu16_FlowMeter_Standard_forHotWater_forJapan = Z_FlowMeter_Standard_forHotWater_forJapan;
#endif
		gu16_Spec_FlowMeter = (U16)((U32)166666 / Z_FlowMeter_Standard_KOR);	//		유량센서 spec 기준 데이터 처리
	}
}

/// @brief    3회 일치 모듈
/// @param    void
/// @return   void
void ThreeMatchModule(ITTI3* p, U8 data)
{
	p->Third = p->Second;
	p->Second = p->First;
	p->First = data;

	p->OnEdge.byte = (U8) ((~p->Level.byte) & (p->First) & (p->Second) & (p->Third));
	p->OffEdge.byte = (U8) ((p->Level.byte) & (~p->First) & (~p->Second) & (~p->Third));
	p->Level.byte = (U8) (((p->First | p->Second | p->Third) & p->Level.byte) | p->OnEdge.byte);
}


/// @brief    1회 일치 모듈
/// @param    void
/// @return   void
void OneMatchModule(ITTI1* p, U8 data)
{
	p->First = data;

	p->OnEdge.byte = (U8) ((~p->Level.byte) & (p->First));
	p->OffEdge.byte = (U8) ((p->Level.byte) & (~p->First));
	p->Level.byte = (U8) (((p->First) & p->Level.byte) | p->OnEdge.byte);
}


/// @brief    CP/CHP 판단
/// @param    void
/// @return   void
void CP_CHP_Decide(void)
{
	if(P_CHP_0_CP_1 == 1)
	{
		gu8_ModelType_forCHP = MODEL_CP;
	}
	else
	{
		gu8_ModelType_forCHP = MODEL_CHP;
	}

	F_ModelDecide_Complete = SET;
}

/// @brief    파우셋 감지 -> 미감지 -> 감지 패턴 체크 및 리셋 데이터 설정
/// @param    void
/// @return   void
/// @detail   파우셋이 감지 -> 미감지 -> 다시 감지되는 패턴을 감지하여
///           파우셋 리셋 데이터를 서버에 올리도록 플래그 설정
static void Check_Faucet_Detect_Undetect_Detect(void)
{
	// 현재 파우셋 감지 상태
	if(INPUT_REED_SW_FAUCET == SET)
	{
		// 감지 상태: 이전에 미감지 상태를 거쳤다가 다시 감지된 경우
		if((gu8_F_Faucet_Detected_Before == CLEAR) && (gu8_F_Faucet_Was_Undetected == SET))
		{
			// Wi-Fi 연결 상태 확인 후 리셋 데이터 설정
			F_Faucet_Reset = SET;
			gu8_F_Faucet_Was_Undetected = CLEAR;
			gu16_DayCount_forFaucet = CLEAR;   // @028
			F_FaucetChange_Display = CLEAR;    // @028

		}
		gu8_F_Faucet_Detected_Before = SET;
	}
	else
	{
		// 미감지 상태: 이전에 감지 상태였다가 미감지로 변경된 경우
		if(gu8_F_Faucet_Detected_Before == SET)
		{
			gu8_F_Faucet_Was_Undetected = SET;
		}
		gu8_F_Faucet_Detected_Before = CLEAR;
	}
}


/// @brief    마이크로 스위치 10분 지속 감지 체크
/// @param    void
/// @return   void
/// @details  마이크로 스위치가 10분 이상 지속 감지되면 플래그 SET
///           2초 연속 해제 감지되면 플래그 CLEAR
static void Check_MicroSW_LongDetection(void)
{
	if(INPUT_MICRO_SW_FAUCET == SET)
	{
		// === 10분 지속 감지 로직 ===
		// 마이크로 스위치가 계속 감지되고 있으면 타이머 감소 (input.h의 TDEC_10ms_INPUT 매크로에서 자동 처리)
		if(gu16_Timer_MicroSW_LongDetection == 0)  // 타이머 완료 (10분 경과)
		{
			if(gu8_F_MicroSW_LongDetection_1h == CLEAR)
			{
				gu8_F_MicroSW_LongDetection_1h = SET;  // 10분 지속 감지 플래그 설정
				
				// TODO: 여기서 필요한 동작 수행 (음성 출력, 에러 설정 등)
				// 예: Play_Voice(VOICE_XXX);
			}
		}
		
		// 마이크로 스위치가 감지되면 해제 타이머 리셋
		gu8_Timer_MicroSW_Release_Check = Z_TIMER_MICROSW_RELEASE_CHECK;  // 2초 리셋
	}
	else  // 마이크로 스위치 미감지
	{
		// === 10분 지속 감지 플래그가 SET 상태일 때만 해제 로직 동작 ===
		if(gu8_F_MicroSW_LongDetection_1h == SET)
		{
			// 2초 연속 미감지 확인 (타이머는 input.h의 TDEC_10ms_INPUT 매크로에서 자동 감소)
			if(gu8_Timer_MicroSW_Release_Check == 0)
			{
				// 2초 연속 미감지 확인되면 플래그와 타이머 모두 리셋
				gu8_F_MicroSW_LongDetection_1h = CLEAR;
				gu16_Timer_MicroSW_LongDetection = Z_TIMER_MICROSW_LONG_DETECTION;  // 10분 타이머 리셋
				gu8_Timer_MicroSW_Release_Check = Z_TIMER_MICROSW_RELEASE_CHECK;     // 2초 타이머 리셋
				
			}
			// else: 아직 2초 안됨, 타이머 계속 감소 (매크로에서 자동 처리)
		}
		else  // 플래그가 CLEAR 상태면 10분 타이머만 리셋
		{
			gu16_Timer_MicroSW_LongDetection = Z_TIMER_MICROSW_LONG_DETECTION;      // 10분 리셋
			gu8_Timer_MicroSW_Release_Check = Z_TIMER_MICROSW_RELEASE_CHECK;         // 2초 리셋
		}
	}
}