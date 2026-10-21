/// @file     moving.c
/// @date     2025.07.03
/// @author   LJH
/// @brief    Faucet moving
#include "include/_user_define.h"
#define _FAUCET_MOVING_
#define _FAUCET_MOVING_SPEED_	3

#include "include/_include.h"

static void faucet_Normal_Mode(void);
static void faucet_Durability_Mode(void);

static void faucet_Level_Set_Mode(void);
static void faucet_Level_Select(void);

static U16 faucet_Level_To_Pulse(U8 mu8_level);
static U16 faucet_Setting_Mode_Pulse_Compare(void);

static void faucet_up_for_front_cover(void);

static void func_faucet_initial(void);
static void func_faucet__initial_set_level(void);
static void func_faucet__initial_set_level_Complete(void);
static void func_faucet_moving_wait(void);
static void func_faucet_moving_down(void);
static void func_faucet_moving__downComplete(void);
static void func_wait_for_effluent_complete(void);
static void func_wait_for_faucet_moving_down(void);
static void func_faucet_moving_up(void);
static void func_faucet_moving__upComplete(void);
static void func_faucet_moving_LineAuto(void);

static void func_faucet_add_pulse_after_InputUpReed(void);
static void func_faucet_add_pulse_after_InputDownReed(void);
static void func_faucet_decel_mode_activate(void);		//	감속 모드 활성화

static void func_faucet_moving_LineTest2(void);			//	메인라인 단축 검사모드
static void func_LineAuto_CupMicroSW_PatternCheck(void);	// @023 컵 마이크로스위치 미감지→감지→미감지 패턴 체크
static void func_faucet_moving_SmartCheck(void);		//	스마트체크 파우셋 테스트
static void smartcheck_add_pulse_after_InputUpReed(void);
static void smartcheck_add_pulse_after_InputDownReed(void);
static void smartcheck_initial(void);
static void func_faucet_reed_undetected_move_up(void);	//	리드스위치 미감지 시 최상단 이동
static void func_faucet_reed_undetected_wait_tip(void);	//	리드스위치 미감지 시 팁 리드스위치 감지 대기

CI8 au8FaucetStep_Open[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };	//	OPEN 스텝 루틴
CI8 au8FaucetStep_Close[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };	//	CLOSE 스텝 루틴

// 설정 모드에서의 이전 방향 저장 (백래시 보정용)
static U8 gu8_Prev_Setting_Direction = 0;

/// @brief    파우셋 무빙 관련 초기화
/// @param    void
/// @return   void
void FaucetMoving_Initialize(void)
{
	gu8_F_FaucetMoving_Initialize = SET;

	// 전원 인가 시 현재 위치 초기화 (리드스위치 감지 전까지는 0)
	gu16_Faucet_Current_Location = 0;

	gu8_F_ResetAccel_ForAddPulse = CLEAR;  // 추가 펄스 가속 초기화 플래그 초기화

	F_SmartCheck_UpReed_Detected = CLEAR;  // 상승 리드스위치 감지 이력 플래그

	gu8_F_Skip_First_ReedUndet_MoveUp = SET; // @025 부팅 후 설정레벨 도착 뒤 첫 이탈만 최상단 스킵
}

/// @brief    파우셋 무빙 제어
/// @param    void
/// @return   void
void FaucetMoving_Control(void)
{
	if(gu8_F_Moving_Durability == SET)			//	파우셋 내구성 모드
	{
		faucet_Durability_Mode();
	}		
	// else if((gu8_OperationStep == Z_OperationStep_43) 
	// || (gu8_F_Faucet_Level_ForWifi == SET)
	// || ((gu8_F_Start_DescriptionMode == SET) && (gu8_DescriptionModeStep == Z_DescriptionModeStep_43)))
	// {
	// 	faucet_Level_Set_Mode();
	// }
    // else if(gu8_F_InputMicroSW_ForcedFaucetUp == SET)
    // {
    //     faucet_up_for_front_cover();            
    // } 	
	else
	{		
		faucet_Normal_Mode();		
	}
	
}

/// @brief    @018 팁 리드 감지/미감지 전환만 검사 (상태 변화 시에만 1/2 반환)
/// @return   @018 F_FAUCET_REED_EDGE_NONE / F_FAUCET_REED_EDGE_TO_UNDETECTED / F_FAUCET_REED_EDGE_TO_DETECTED
static U8 func_faucet_reed_edge_check(void)
{
	static U8 mu8_state_before = SET;
	U8 now_undetected;
	U8 now_detected;
	U8 ret;

	now_undetected = gu8_F_FaucetTip_Reed_Undetected;
	now_detected   = gu8_F_FaucetTip_Reed_Detected;
	ret = F_FAUCET_REED_EDGE_NONE;

	if(now_undetected == SET)
	{
		if(mu8_state_before == SET)
			ret = F_FAUCET_REED_EDGE_TO_UNDETECTED;
		mu8_state_before = CLEAR;
	}
	else
	{
		if(mu8_state_before == CLEAR)
			ret = F_FAUCET_REED_EDGE_TO_DETECTED;
		mu8_state_before = SET;
	}
	return ret;
}

/// @brief    파우셋 무빙 normal 모드
/// @param    void
/// @return   void
static void faucet_Normal_Mode(void)
{
	U8 edge = 0; //@018

	// 파우셋 팁 리드스위치 미감지 체크 (모든 단계에서, 모터 정지 상태일 때)
	// 단, 초기화 단계와 미감지 이동 단계는 제외
	if((gu8_FaucetMoving_Step != Z_FAUCET_REED_UNDETECTED_MOVE_UP)
	&& (gu8_FaucetMoving_Step != Z_FAUCET_REED_UNDETECTED_WAIT_TIP)
	&& (gu8_FaucetMoving_Step != Z_FAUCET_MOVING_INITIAL)
	&& (gu8_FaucetMoving_Step != Z_FAUCET_MOVING__INITIAL_SET_LEVEL)
	&& (gu8_FaucetMoving_Step != Z_FAUCET_MOVING__INITIAL_SET_LEVEL_COMPLETE)
	&& (gu8_FaucetMoving_Step != Z_FAUCET_LEVEL_SETTING)
	&& (gu16_FaucetMovingPulse == 0)  // 모터 정지 상태일 때만
	&& (gu8_OperationStep != Z_OperationStep_90))  // 검사모드때는 보지말자..
	{
		edge = func_faucet_reed_edge_check();  		//@018

		// 팁 리드스위치 미감지 플래그 확인 (input.c에서 1초 딜레이 후 설정)
		//@018 if(gu8_F_FaucetTip_Reed_Undetected == SET)
		if((edge == F_FAUCET_REED_EDGE_TO_UNDETECTED) || (edge == F_FAUCET_REED_EDGE_TO_DETECTED))  //@018 감지->미감지 or 미감지->감지: 동일하게 최상단 
		{
			if(gu8_F_Came_From_Wait_Tip_To_Level == SET)   //@018 
			{          												//@018
				gu8_F_Came_From_Wait_Tip_To_Level = CLEAR; //@018
			}														//@018
			else if((edge == F_FAUCET_REED_EDGE_TO_UNDETECTED)                      //@025 부팅 후 설정레벨 직후 첫 이탈은 최상단 이동 생략
			     && (gu8_F_Skip_First_ReedUndet_MoveUp == SET))                      //@025
			{                                                                       //@025
				gu8_F_Skip_First_ReedUndet_MoveUp = CLEAR;                          //@025                                                                //@025
			}                                                                       //@025
			//	한번 실행한 이력 있으면 하지말도록..(무한 출력줌..)
			else if(gu8_FaucetMoving_Set_Level_Backup != CLEAR)
			{
				// 현재 레벨 백업 (원래 위치로 복귀하기 위해)
				gu8_FaucetMoving_Set_Level_Backup = CLEAR;
				// 최상단으로 이동 (원점 재설정)
				FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);
				gu8_FaucetMoving_Step = Z_FAUCET_REED_UNDETECTED_MOVE_UP;
				gu8_F_FaucetTip_Reed_Undetected = CLEAR;  // 플래그 리셋
				gu8_F_Faucet_Fast_Return_for_Reed_Detected = SET;			//	올라갈때 감속 안하기 위함..
				return;				
			}		
		}
		else
		{
			//	이 구문 없으면....해제 -> 감지 -> 해제인경우 다시 실행안됨..
			if(gu8_F_Faucet_Level_ForWifi == CLEAR)
			{
				gu8_FaucetMoving_Set_Level_Backup = gu8_FaucetMoving_Set_Level; 
			}

			gu8_F_Came_From_Wait_Tip_To_Level = CLEAR;   // @018 전환 없으면 플래그 정리
		}
	}
	else
	{
		#if 0
		// 다른 스텝이거나 모터 동작 중이면 플래그 리셋
		gu8_F_FaucetTip_Reed_Undetected = CLEAR;
		#endif
	}
    
	if(gu8_OperationStep == Z_OperationStep_80)							//@029
	{																	//@029
		if(gu8_FaucetMoving_Step != Z_FAUCET_MOVING_SMARTCHECK)         //@029
		{
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING_SMARTCHECK;         //@029
		}		
	}

	switch(gu8_FaucetMoving_Step)
	{
		case Z_FAUCET_MOVING_INITIAL:
		
			func_faucet_initial();

			break;

		case Z_FAUCET_MOVING__INITIAL_SET_LEVEL:

			func_faucet__initial_set_level();

			break;
		
		case Z_FAUCET_MOVING__INITIAL_SET_LEVEL_COMPLETE:

			func_faucet__initial_set_level_Complete();

			break;

		case Z_FAUCET_MOVING_WAIT:

			func_faucet_moving_wait();

			break;

		case Z_FAUCET_MOVING_DOWN:

			func_faucet_moving_down();

			break;

		case Z_FAUCET_MOVING__DOWN_COMPLETE:

			func_faucet_moving__downComplete();

			break;

		case Z_WAIT_FOR_EFFLUENT_COMPLETE:

			func_wait_for_effluent_complete();

			break;

		case Z_WAIT_FOR_FAUCET_MOVING_DOWN:

			func_wait_for_faucet_moving_down();

			break;

		case Z_FAUCET_MOVING_UP:

			func_faucet_moving_up();

			break;

		case Z_FAUCET_MOVING__UP_COMPLETE:

			func_faucet_moving__upComplete();

			break;

		case Z_FAUCET_MOVING_LINE_AUTO:

			func_faucet_moving_LineAuto();
			
			break;

		case Z_FAUCET_MOVING_LINE_TEST_2:

			func_faucet_moving_LineTest2();

			break;

		case Z_FAUCET_MOVING_SMARTCHECK:

			func_faucet_moving_SmartCheck();

			break;
		case Z_FAUCET_LEVEL_SETTING:
			faucet_Level_Set_Mode();

			if((gu8_OperationStep != Z_OperationStep_43) 
			&& (gu8_F_Faucet_Level_ForWifi != SET)
		 	&& (gu8_DescriptionModeStep != Z_DescriptionModeStep_43))//@008
			{
				gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;
			}

			break;

		case Z_FILTER_CHANGE_MODE:

			faucet_up_for_front_cover();	
			

			break;

		case Z_FAUCET_REED_UNDETECTED_MOVE_UP:

			func_faucet_reed_undetected_move_up();

			break;

		case Z_FAUCET_REED_UNDETECTED_WAIT_TIP:

			func_faucet_reed_undetected_wait_tip();

			// 파우셋 팁 미감지 -> 감지 시, 감속 안주기 위함. flag clear
			if(gu8_F_Faucet_Fast_Return_for_Reed_Detected == SET)
			{
				gu8_F_Faucet_Fast_Return_for_Reed_Detected = CLEAR;
			}

			break;

		default:
			break;
	}   
}

/// @brief    전원인가 후, 파우셋 초기화
/// @param    void
/// @return   void
static void func_faucet_initial(void)
{
	if(INPUT_REED_SW_FAUCET_UP == SET)					//	UP 리드스위치 감지?
	{	
		func_faucet_add_pulse_after_InputUpReed();
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING__INITIAL_SET_LEVEL;
	}
	else
	{		
		if(gu16_FaucetMovingPulse == 0)
		{
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING__INITIAL_SET_LEVEL;
		}
	}
}

/// @brief    전원인가 후, 설정된 파우셋 단계로
/// @param    void
/// @return   void
static void func_faucet__initial_set_level(void)
{
	//	auto가 아니면..해당 위치로...
	if(gu16_FaucetMovingPulse == 0)
	{
		if(gu8_FaucetMoving_Set_Level > Z_FAUCET_MOVING_FIX_1_LEVEL)
		{
			faucet_Level_Select();
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING__INITIAL_SET_LEVEL_COMPLETE;
		}
		else
		{
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;
		}
	}
}

/// @brief    파우셋 무빙 대기
/// @param    void
/// @return   void
static void func_faucet__initial_set_level_Complete(void)
{
	static U8 mu8_initial_complete = 0;

	if(INPUT_REED_SW_FAUCET_DOWN == SET)			//	파우셋 DOWN 리드스위치 감지 후, 추가 펄스(조립에 따라 편차 있기 때문에 전체 펄스만큼 더주기.)
	{
		func_faucet_add_pulse_after_InputDownReed();
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;
	}
	else
	{	//	리드스위치 끝까지 감지 안되면 그냥 완료 치기..
		if(gu16_FaucetMovingPulse == 0)
		{
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;
		}
		else
		{

		}
	}

	if(gu8_FaucetMoving_Step == Z_FAUCET_MOVING_WAIT)
	{
		if(gu8_F_Came_From_Wait_Tip_To_Level == SET)   //@025 WAIT_TIP에서 복귀한 경우 첫 이탈 스킵 비활성
		{                                               //@025
			gu8_F_Skip_First_ReedUndet_MoveUp = CLEAR;  //@025
		}                                               //@025
		gu8_FaucetMoving_Set_Level_Backup = gu8_FaucetMoving_Set_Level;  // 초기화 완료 시 동기화

		if(gu8_OperationStep == Z_OperationStep_11)   // @019 이전위치 이동완료 후 추출시작
		{                                             // @019 이전위치 이동완료 후 추출시작
			gu8_F_Finish_Faucet_Down = SET;          // @019 이전위치 이동완료 후 추출시작
		}                                            // @019 이전위치 이동완료 후 추출시작
	}
}

/// @brief    파우셋 무빙 대기
/// @param    void
/// @return   void
static void func_faucet_moving_wait(void)
{

	//	파우셋 무빙 시작..
	if(gu8_OperationStep == Z_OperationStep_11)	
	#if 0
	if((gu8_OperationStep == Z_OperationStep_11) || (gu8_OperationStep == Z_OperationStep_50))
	#endif
	{
		if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_AUTO_LEVEL)			//	Auto인경우만 동작..
		{
			FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_STEP_ZERO_BACK);
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING_DOWN;
		}
	}
	#if 0
	else if((F_TestMode_LineFront == SET) || (F_LineTest2_FaucetMoving == SET)) 	//	라인검사 or 공장 단축검사모드
	#endif
	//	라인검사 or 공장 단축검사모드
	//	라인검사, 공장 단축검사모드 분리
	//	용량키 입력시에만 파우셋 검사 동작하도록 적용...
	else if((gu8_OperationStep == Z_OperationStep_90) && (F_TestMode_LineFront == SET) && (F_LineFrontTest_AMount_Select == SET))		
	{
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_LINE_AUTO;
	}
	else if(gu8_OperationStep == Z_OperationStep_93)
	{
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_LINE_TEST_2;
	}
	else if(gu8_OperationStep == Z_OperationStep_80)
	{
		if(gu8_FaucetMoving_Step != Z_FAUCET_MOVING_SMARTCHECK)
		{
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING_SMARTCHECK;
		}		
	}
	else if((gu8_OperationStep == Z_OperationStep_43) 
	|| (gu8_F_Faucet_Level_ForWifi == SET)
	|| ((gu8_F_Start_DescriptionMode == SET) && (gu8_DescriptionModeStep == Z_DescriptionModeStep_43)))
	{	
		gu8_FaucetMoving_Step = Z_FAUCET_LEVEL_SETTING;
	}
	else if(gu8_F_InputMicroSW_ForcedFaucetUp == SET)
	{
		gu8_F_InputMicroSW_ForcedFaucetUp = CLEAR;				// @001
		gu8_FaucetMoving_Step = Z_FILTER_CHANGE_MODE;
	}	
	else 
	{
		
	}
	
	gu16_Faucet_Current_Location = 0;
}

/// @brief    파우셋 무빙 다운
/// @param    void
/// @return   void
static void func_faucet_moving_down(void)
{
	U16 mu16_buff = 0;

	if(gu8_OperationStep == Z_OperationStep_11)	
	#if 0
	if((gu8_OperationStep == Z_OperationStep_11) || (gu8_OperationStep == Z_OperationStep_50))
	#endif
	{
		if(INPUT_MICRO_SW_FAUCET == SET)            		//	마이크로 스위치 감지 후, 추가 펄스...(컵 낀다)
		{			
			FaucetControl_StepMove(FAUCET_STEP_MOTOR_MICRO_SW_DETECTION, FAUCET_MICO_SW_INPUT_DETECTION_STEP);
			gu8_FaucetMoving_AccelStage = 0;
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING__DOWN_COMPLETE;
		}
		else
		{
			if(INPUT_REED_SW_FAUCET_DOWN == SET)			//	파우셋 DOWN 리드스위치 감지 후, 추가 펄스(조립에 따라 편차 있기 때문에 전체 펄스만큼 더주기.)
			{
				// 마이크로스위치 감지 시 감속 모드 활성화
				// func_faucet_decel_mode_activate();
				func_faucet_add_pulse_after_InputDownReed();
				gu8_FaucetMoving_Step = Z_FAUCET_MOVING__DOWN_COMPLETE;
			}
			else
			{	//	리드스위치 끝까지 감지 안되면 그냥 완료 치기..
				if(gu16_FaucetMovingPulse == 0)
				{
					gu8_FaucetMoving_Step = Z_FAUCET_MOVING__DOWN_COMPLETE;
				}
				else
				{

				}
			}
		}
	}
	else
	{
		//	내러오는중에....추출 눌러서 취소....
		FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);	//	너무 짧으면 안올라감...더 줘야할듯		
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_UP;
	}
}

/// @brief    파우셋 무빙 다운 완료
/// @param    void
/// @return   void
static void func_faucet_moving__downComplete(void)
{
	//	해당스텝은 추출완료 전, 무빙파우셋 움직이는 step이므로 11step 조건 추가...(안전사양)	
	if(gu8_OperationStep ==Z_OperationStep_11)
	#if 0
	if((gu8_OperationStep == Z_OperationStep_11) || (gu8_OperationStep == Z_OperationStep_50))
	#endif
	{
		if(gu16_FaucetMovingPulse == 0)
		{
			gu8_F_Finish_Faucet_Down = SET;
			gu8_F_MicroSW_LateDetection = CLEAR;
			gu8_FaucetMoving_Step = Z_WAIT_FOR_EFFLUENT_COMPLETE;
		}
		else if((INPUT_MICRO_SW_FAUCET == SET) && (gu8_F_MicroSW_LateDetection == CLEAR))            		//	마이크로 스위치 감지 후, 추가 펄스...(컵 낀다)
		{
			gu8_F_MicroSW_LateDetection = SET;		
			FaucetControl_StepMove(FAUCET_STEP_MOTOR_MICRO_SW_DETECTION, FAUCET_MICO_SW_INPUT_DETECTION_STEP);
			gu8_FaucetMoving_AccelStage = 0;
		}	
		else
		{

		}
	}
	else
	{
		//	내러오는중에....추출 눌러서 취소....
		FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);	//	너무 짧으면 안올라감...더 줘야할듯		
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_UP;		
	}
}

/// @brief    추출 완료 대기
/// @param    void
/// @return   void
static void func_wait_for_effluent_complete(void)
{
	if(gu8_OperationStep == Z_OperationStep_50)
	{
		// gu8_Timer_FaucetDown_WaitingTime = 60;			
		// gu8_Timer_FaucetDown_WaitingTime = 30;				
		gu8_Timer_FaucetDown_WaitingTime = Z_FAUCET_DOWN_WAITING_TIME;				
	}
	else if(gu8_OperationStep == Z_OperationStep_11)
	{
		//	pulse 출력안끝날수 있으니, 11step에서는 대기..
	}
	else
	{
		//	펄스끝날때까지 대기
		if(gu16_FaucetMovingPulse == 0)
		{
			gu8_FaucetMoving_Step = Z_WAIT_FOR_FAUCET_MOVING_DOWN;
		}
	}
}

/// @brief    파우셋 down 상태로 대기
/// @param    void
/// @return   void
static void func_wait_for_faucet_moving_down(void)
{
	if(gu8_FaucetMoving_Set_Level == SET)
	{
		if(gu8_Timer_FaucetDown_WaitingTime == 0)			//	대기 타이머 경과 ...무빙업 시작..
		{
			gu8_F_Finish_Faucet_Down = CLEAR;					//	finish close...
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING_UP;

			//	만약 UP이 감지되어있으면...출력 안줘도됨.
			if(INPUT_REED_SW_FAUCET_UP == CLEAR)
			{
				FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);	
			}			
		}
		// else if((gu8_OperationStep == Z_OperationStep_11) || (gu8_OperationStep == Z_OperationStep_50))
		else if(gu8_OperationStep == Z_OperationStep_11)
		{
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING__DOWN_COMPLETE;
		}
		else
		{

		}
		
		if(gu8_Key_Short.byte != 0x00)
		{
			gu8_Timer_FaucetDown_WaitingTime = Z_FAUCET_DOWN_WAITING_TIME;
		}
	}
	else
	{
		//	파우셋 off -> 현재 위치에서 대기 
		// 	파우셋 off -> on 후, 10초 뒤 상승
		gu8_Timer_FaucetDown_WaitingTime = Z_FAUCET_DOWN_WAITING_TIME;
	}
}

/// @brief    파우셋 up 진행
/// @param    void
/// @return   void
static void func_faucet_moving_up(void)
{
	if(INPUT_REED_SW_FAUCET_UP == SET)					//	UP 리드스위치 감지?
	{
		func_faucet_add_pulse_after_InputUpReed();
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING__UP_COMPLETE;
	}
	else
	{		
		if(gu8_OperationStep == Z_OperationStep_11)	
		#if 0
		if((gu8_OperationStep == Z_OperationStep_11) || (gu8_OperationStep == Z_OperationStep_50))
		#endif
		{
			//	올라가는중에 추출버튼 입력하면...다시 내려와야함..
			FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_STEP_ZERO_BACK);
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING_DOWN;
		}
		else if(gu16_FaucetMovingPulse == 0)		//	리드감지 안되고...
		{
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING__UP_COMPLETE;
		}
		else
		{

		}
	}
}

/// @brief    파우셋 up 완료
/// @param    void
/// @return   void
static void func_faucet_moving__upComplete(void)
{
	if((gu16_FaucetMovingPulse == 0)
	& (gu8_OperationStep != Z_OperationStep_50))
	{
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;
	}
}

/// @brief    파우셋 팁 리드스위치 미감지 시 최상단 이동
/// @param    void
/// @return   void
static void func_faucet_reed_undetected_move_up(void)
{
	// UP 리드스위치 감지 확인 (펄스 출력 중에도 체크)
	if(INPUT_REED_SW_FAUCET_UP == SET)
	{
		// 원점 잡기를 위해 추가 펄스 출력
		func_faucet_add_pulse_after_InputUpReed();
		
		#if 0
		// 추가 펄스 출력 후 팁 리드스위치 감지 대기 스텝으로 이동
		gu8_FaucetMoving_Step = Z_FAUCET_REED_UNDETECTED_WAIT_TIP;
		#endif
		// 필터 교체 모드면 필터 교체 모드로 복귀
		if(gu8_F_InputMicroSW_ForcedFaucetUp == SET)
		{
			gu8_FaucetMoving_Step = Z_FILTER_CHANGE_MODE;
			gu8_Step_Faucet_Up_forFrontCover_Open = 1;
		}
		else
		{
			gu8_FaucetMoving_Step = Z_FAUCET_REED_UNDETECTED_WAIT_TIP;
		}	
	}
	else
	{
		// UP 리드스위치 미감지 상태
		// 펄스 출력 완료 후 팁 리드스위치 감지 대기 스텝으로 이동
		if(gu16_FaucetMovingPulse == 0)
		{
			#if 0
			// 팁 리드스위치 감지 대기 스텝으로 이동 (리드 고장 시 대기하기 위해)
			gu8_FaucetMoving_Step = Z_FAUCET_REED_UNDETECTED_WAIT_TIP;
			#endif
			// 필터 교체 모드면 필터 교체 모드로 복귀
			if(gu8_F_InputMicroSW_ForcedFaucetUp == SET)
			{
				gu8_FaucetMoving_Step = Z_FILTER_CHANGE_MODE;
				gu8_Step_Faucet_Up_forFrontCover_Open = 1;
			}
			else
			{
				gu8_FaucetMoving_Step = Z_FAUCET_REED_UNDETECTED_WAIT_TIP;
			}
		}
	}
}

/// @brief    파우셋 팁 리드스위치 미감지 시 팁 리드스위치 감지 대기
/// @param    void
/// @return   void
static void func_faucet_reed_undetected_wait_tip(void)
{
	// 팁 리드스위치 감지 플래그 확인 (input.c에서 2초 딜레이 후 설정)
	// @018 if(gu8_F_FaucetTip_Reed_Detected == SET)
	if((gu8_F_FaucetTip_Reed_Detected == SET) 
	|| (gu8_OperationStep == Z_OperationStep_11)                  //@018 추출하면..원래 위치로 
	|| (gu8_OperationStep == Z_OperationStep_50))                 //@018 추출하면..원래 위치로
	{
		if(gu8_F_FaucetTip_Reed_Detected == SET)		//@018 미감지 -> 최상단이동 -> 감지 할때 두번 왔다갓다 함.
		{                                               //@018 미감지 -> 최상단이동 -> 감지 할때 두번 왔다갓다 함.
			gu8_F_Came_From_Wait_Tip_To_Level = SET;   //@018 미감지 -> 최상단이동 -> 감지 할때 두번 왔다갓다 함.
		}                                              //@018 미감지 -> 최상단이동 -> 감지 할때 두번 왔다갓다 함.

		// 팁 리드스위치 감지되면 원래 레벨로 복귀
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING__INITIAL_SET_LEVEL;
		gu8_F_FaucetTip_Reed_Detected = CLEAR;  // 플래그 리셋
		gu8_FaucetMoving_Set_Level_Backup = CLEAR;			//	이거 클리어 안하면.....5단계 제외하고 원위치로 안감.

		gu8_F_Faucet_Fast_Return_for_Reed_Detected = SET;
	}
	else if(gu8_F_InputMicroSW_ForcedFaucetUp == SET)
	{
		gu8_FaucetMoving_Step = Z_FILTER_CHANGE_MODE;
		gu8_Step_Faucet_Up_forFrontCover_Open = 0;
	}	
	else if(gu8_OperationStep == Z_OperationStep_90)
	{
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;
	}
	else if(gu8_OperationStep == Z_OperationStep_93)
	{
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;
	}
	else if(gu8_OperationStep == Z_OperationStep_43)   // @020
	{                                               // @020
		gu8_FaucetMoving_Step = Z_FAUCET_LEVEL_SETTING; // @020
	}                                               // @020	
	else 
	{
	
	}
	// 팁 리드스위치 미감지면 계속 대기 (아무 동작 안함)
}

/// @brief    파우셋 설정 모드
/// @param    void
/// @return   void
static void faucet_Level_Set_Mode(void)
{
	switch(gu8_Faucet_Level_Set_Step)
	{
		//	원점으로 올라올수있도록...
		case Z_FAUCET_SET_MODE_WAIT:					

			if((gu8_FaucetMoving_Set_Level_Backup != gu8_FaucetMoving_Set_Level)
			|| (gu8_F_Faucet_Level_ForWifi == SET))
			{	
				faucet_Level_Select();		

				if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_5_LEVEL)
				{
					gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_FULL_DOWN;
				}
				else if((gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_AUTO_LEVEL)
				|| (gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_1_LEVEL))
				{
					gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_FULL_UP;
				}
				else
				{
					gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_SETTING;
				}
			}

			break;

		case Z_FAUCET_SET_MODE_FULL_UP:		//	다 올라갔는지 확인..
			if(INPUT_REED_SW_FAUCET_UP == SET)					//	UP 리드스위치 감지?
			{
				// AUTO -> 1단계 변경 시에만 추가 펄스 스킵
				// (백업 변수는 아직 업데이트 전이므로 이전 레벨을 확인 가능)
				if(((gu8_FaucetMoving_Set_Level_Backup == Z_FAUCET_MOVING_FIX_1_LEVEL)
				&& (gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_AUTO_LEVEL))
				|| ((gu8_FaucetMoving_Set_Level_Backup == Z_FAUCET_MOVING_AUTO_LEVEL)
				&& (gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_1_LEVEL)))
				{
					gu16_FaucetMovingPulse = 0;
				}
				else
				{
					func_faucet_add_pulse_after_InputUpReed();
				}

				gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_SETTING;				
			}
			else if(gu16_FaucetMovingPulse == 0)	//	리드스위치 끝까지 감지 안되면 펄스 0일 때 완료
			{
				gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_SETTING;
			}
			break;
			
		case Z_FAUCET_SET_MODE_FULL_DOWN:
			if(INPUT_REED_SW_FAUCET_DOWN == SET)			//	파우셋 DOWN 리드스위치 감지 후, 추가 펄스(조립에 따라 편차 있기 때문에 전체 펄스만큼 더주기.)
			{
				func_faucet_add_pulse_after_InputDownReed();
				gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_SETTING;
			}
			else if(gu16_FaucetMovingPulse == 0)	//	리드스위치 끝까지 감지 안되면 펄스 0일 때 완료
			{
				gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_SETTING;
			}
			break;

		case Z_FAUCET_SET_MODE_SETTING:		//	파우셋 설정 대기

			// 파우셋 이동이 완료되면 백업 변수 업데이트 후 WAIT 상태로 복귀
			if(gu16_FaucetMovingPulse == 0)
			{
				gu8_FaucetMoving_Set_Level_Backup = gu8_FaucetMoving_Set_Level;
				gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_WAIT;
				
				if(gu8_F_Faucet_Level_ForWifi == SET)
				{
					gu8_F_Faucet_Level_ForWifi = CLEAR;					
				}
			}	
			
			/* @026 */
			if((gu8_OperationStep != Z_OperationStep_43)           //@026
			&& (gu8_F_Faucet_Level_ForWifi != SET)                 //@026
		 	&& (gu8_DescriptionModeStep != Z_DescriptionModeStep_43))//@026
			{														//@026
				gu8_FaucetMoving_Step = Z_FAUCET_REED_UNDETECTED_MOVE_UP;  //@026
			}			
			break;		

		default:

			break;		
	}

	// gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;			//	설정하고 처음으로 갈수있도록..
}

/// @brief    파우셋 모드 선택...(초기화랑 같이 쓰기위해 함수분리)
/// @param    void
/// @return   void
static void faucet_Level_Select(void)
{
	U16 mu16_level_pulse = 0;
	U8 mu8_direction = 0;

	#if 0
	if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_AUTO_LEVEL)
	{
		FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);		
		gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_FULL_UP;			
	}
	else if((gu8_FaucetMoving_Set_Level >= Z_FAUCET_MOVING_FIX_1_LEVEL)
		 && (gu8_FaucetMoving_Set_Level <= Z_FAUCET_MOVING_FIX_5_LEVEL))
	{
		mu16_level_pulse = faucet_Setting_Mode_Pulse_Compare();
		
		// FIX_5_LEVEL은 항상 OPEN 방향, 나머지는 설정된 방향 사용
		if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_5_LEVEL)
		{
			mu8_direction = FAUCET_STEP_MOTER_OPEN;
			gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_FULL_DOWN;
		}
		else
		{
			mu8_direction = gu8_F_FaucetMoving_Set_Level_Way;
			gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_SETTING;
		}
		
		FaucetControl_StepMove(mu8_direction, mu16_level_pulse);
	}
	#endif

		
	// FIX_5_LEVEL은 항상 OPEN 방향, 나머지는 설정된 방향 사용
	if(gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_5_LEVEL)
	{
		mu8_direction = FAUCET_STEP_MOTER_OPEN;
		// gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_FULL_DOWN;
		FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_STEP_ZERO_BACK);
		gu8_Prev_Setting_Direction = mu8_direction;  // 현재 방향 저장
	}
	else if((gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_AUTO_LEVEL)
	|| (gu8_FaucetMoving_Set_Level == Z_FAUCET_MOVING_FIX_1_LEVEL))
	{
		mu8_direction = FAUCET_STEP_MOTER_CLOSE;
		// gu8_Faucet_Level_Set_Step = Z_FAUCET_SET_MODE_FULL_UP;
		FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);
		gu8_Prev_Setting_Direction = mu8_direction;  // 현재 방향 저장
	}
	else
	{
		mu8_direction = gu8_F_FaucetMoving_Set_Level_Way;
		mu16_level_pulse = faucet_Setting_Mode_Pulse_Compare();
		
		// 백래시 보정: 설정 모드에서 방향 전환 시에만 보정치 추가
		if ((gu8_Prev_Setting_Direction != mu8_direction) && (mu8_direction == FAUCET_STEP_MOTER_CLOSE))
		{
			// OPEN -> CLOSE 전환 시에만 보정치 추가
			mu16_level_pulse += Z_FAUCET_BACKLASH_COMPENSATION;
		}
		
		gu8_Prev_Setting_Direction = mu8_direction;  // 현재 방향 저장
		FaucetControl_StepMove(mu8_direction, mu16_level_pulse);
	}
		

	gu8_F_FaucetMoving_Set_Level_Way = 0;
}

/// @brief    레벨 값을 펄스 값으로 변환
/// @param    mu8_level 레벨 값 (Z_FAUCET_MOVING_FIX_X_LEVEL)
/// @return   해당 레벨의 펄스 값
static U16 faucet_Level_To_Pulse(U8 mu8_level)
{
	U16 mu16_pulse = 0;

	switch(mu8_level)
	{
		case Z_FAUCET_MOVING_AUTO_LEVEL:
			mu16_pulse = 0;
			break;
		case Z_FAUCET_MOVING_FIX_1_LEVEL:
			mu16_pulse = Z_FAUCET_MOVING_FIX_1_LEVEL_PULSE;
			break;
		case Z_FAUCET_MOVING_FIX_2_LEVEL:
			mu16_pulse = Z_FAUCET_MOVING_FIX_2_LEVEL_PULSE;
			break;
		case Z_FAUCET_MOVING_FIX_3_LEVEL:
			mu16_pulse = Z_FAUCET_MOVING_FIX_3_LEVEL_PULSE;
			break;
		case Z_FAUCET_MOVING_FIX_4_LEVEL:
			mu16_pulse = Z_FAUCET_MOVING_FIX_4_LEVEL_PULSE;
			break;
		case Z_FAUCET_MOVING_FIX_5_LEVEL:
			mu16_pulse = Z_FAUCET_MOVING_FIX_5_LEVEL_PULSE;
			break;
		default:
			mu16_pulse = 0;
			break;
	}

	return (mu16_pulse);
}

/// @brief    파우셋 위치 셋팅 시, 백업 레벨과 현재 레벨의 차이만큼 펄스 계산
/// @param    void
/// @return   레벨 차이에 해당하는 펄스 값
static U16 faucet_Setting_Mode_Pulse_Compare(void)
{
	U16 mu16_ret_pulse = 0;
	U16 mu16_backup_pulse = 0;
	U16 mu16_current_pulse = 0;

	//	백업 레벨과 현재 레벨을 펄스로 변환
	mu16_backup_pulse = faucet_Level_To_Pulse(gu8_FaucetMoving_Set_Level_Backup);
	mu16_current_pulse = faucet_Level_To_Pulse(gu8_FaucetMoving_Set_Level);

	//	레벨 차이에 해당하는 펄스 차이 계산
	if(mu16_current_pulse > mu16_backup_pulse)
	{
		mu16_ret_pulse = mu16_current_pulse - mu16_backup_pulse;
	}
	else if(mu16_current_pulse < mu16_backup_pulse)
	{
		mu16_ret_pulse = mu16_backup_pulse - mu16_current_pulse;
	}
	else
	{
		mu16_ret_pulse = 0;
	}

	return (mu16_ret_pulse);
}


/// @brief    파우셋 up 완료
/// @param    void
/// @return   void
static void func_faucet_moving_LineAuto(void)
{
	switch(gu8_FaucetMoving_LineAutoStep)
	{
		case 0:
			gu8_LineAuto_CupMicroSW_Step = 0;				// @023 패턴 초기화
			FaucetStepMotor_ZeroBack_Open();
			gu8_FaucetMoving_LineAutoStep++;
			break;

		case 1:
			
			if(INPUT_REED_SW_FAUCET_DOWN == SET)
			{
				gu8_F_LineAuto_Faucet_DownReed = SET;
			}
			else
			{

			}

			if(gu8_F_LineAuto_Faucet_DownReed == SET)
			{
				func_faucet_add_pulse_after_InputDownReed();
				gu8_FaucetMoving_LineAutoStep++;
			}
			break;

		case 2:
			if(gu16_FaucetMovingPulse != 0)
			{
				gu8_Timer_LineAuto_Faucet_DownReed = 10;
			}
			else
			{
				if((gu8_Timer_LineAuto_Faucet_DownReed == 0)
				&& (gu8_F_LineAuto_Faucet_MicroSW == SET)
				&& (gu8_F_LineAuto_Faucet_DownReed == SET))
				{
					FaucetStepMotor_ZeroBack_Close();
					gu8_FaucetMoving_LineAutoStep++;
				}
			}	
			break;

		case 3:

			if(INPUT_REED_SW_FAUCET_UP == SET)
			{
				gu8_F_LineAuto_Faucet_UpReed = SET;
				func_faucet_add_pulse_after_InputUpReed();
				gu8_FaucetMoving_LineAutoStep++;
			}
			else
			{

			}

			break;

		case 4://	완료 커맨드 받으면 바로 최상단으로 이동...파우셋 지그 뺄때 내려왔으니끼ㅏ.
			if((F_LineTest_Complete == SET) && (INPUT_REED_SW_FAUCET == CLEAR))
			{
				FaucetStepMotor_ZeroBack_Close();
				gu8_FaucetMoving_LineAutoStep++;
			}
			break;
		
		case 5:	
			if(INPUT_REED_SW_FAUCET_UP == SET)
			{
				func_faucet_add_pulse_after_InputUpReed();
				gu8_FaucetMoving_LineAutoStep++;
			}
			else if(gu16_FaucetMovingPulse == 0)        //@014
			{                                           //@014
				gu8_FaucetMoving_LineAutoStep++;        //@014
			}                                           //@014
			else                                        //@014
			{                                           //@014
			}                                           //@014
			break;
		case 6:
			gu8_FaucetMoving_Step = Z_FAUCET_MOVING_LINE_TEST_2;  //@014
			gu8_FaucetMoving_LineAutoStep = CLEAR;                 //@014		
			break;
		default:
			break;
	}


    func_LineAuto_CupMicroSW_PatternCheck();    //@023

	if(gu8_OperationStep == Z_OperationStep_93)
	{
		gu8_FaucetMoving_Step = Z_FAUCET_MOVING_LINE_TEST_2;
	}
}

/// @brief    @023 컵 마이크로스위치 미감지→감지→미감지 패턴 체크 (case 1, 2 공통)
/// @param    void
/// @return   void
static void func_LineAuto_CupMicroSW_PatternCheck(void)
{
	if(INPUT_MICRO_SW_FAUCET == CLEAR)
	{
		if(gu8_LineAuto_CupMicroSW_Step == 0)
		{
			gu8_LineAuto_CupMicroSW_Step = 1;			// @023 미감지 확인
		}
		else if(gu8_LineAuto_CupMicroSW_Step == 2)
		{
			gu8_LineAuto_CupMicroSW_Step = 3;			// @023 패턴 완성
			gu8_F_LineAuto_Faucet_MicroSW = SET;		// @023
		}
	}
	else
	{
		if(gu8_LineAuto_CupMicroSW_Step == 1)
		{
			gu8_LineAuto_CupMicroSW_Step = 2;			// @023 감지 확인
		}
	}
}

/// @brief    라인 단축 검사모드
/// @param    void
/// @return   void
static void func_faucet_moving_LineTest2(void)
{
	if(gu8_OperationStep == Z_OperationStep_90)     //@014
	{                                               //@014
		if(KEY_EFFLUENT_SHORT == SET)               //@014
		{                                           //@014
			F_LineTest2_FaucetMoving = SET;         //@014
			gu8_FaucetMoving_LineAutoStep = CLEAR;  //@014
			gu8_F_LineAuto_Faucet_DownReed = CLEAR;			//@014
			gu8_F_LineAuto_Faucet_UpReed = CLEAR;			//@014
			gu8_F_LineAuto_Faucet_MicroSW = CLEAR;			//@014			
			gu8_LineAuto_CupMicroSW_Step = 0;					// @022 패턴 초기화			
		}                                           //@014
	}                                               //@014

	if(F_LineTest2_FaucetMoving == SET)
	{
		switch(gu8_FaucetMoving_LineAutoStep)
		{
			case 0:

				FaucetStepMotor_ZeroBack_Open();
				gu8_FaucetMoving_LineAutoStep++;
				break;

			case 1:
				func_LineAuto_CupMicroSW_PatternCheck();	// @023 미감지→감지→미감지 패턴 체크

				if(INPUT_REED_SW_FAUCET_DOWN == SET)
				{
					func_faucet_add_pulse_after_InputDownReed();
					gu8_F_LineAuto_Faucet_DownReed = SET;
					gu8_FaucetMoving_LineAutoStep++;
				}
				else
				{

				}
				break;

			case 2:
				func_LineAuto_CupMicroSW_PatternCheck();	// @023 미감지→감지→미감지 패턴 체크

				if(gu16_FaucetMovingPulse != 0)
				{
					gu8_Timer_LineAuto_Faucet_DownReed = 20;
				}
				else
				{
					if((gu8_Timer_LineAuto_Faucet_DownReed == 0)
					&& (gu8_F_LineAuto_Faucet_MicroSW == SET)
					&& (gu8_F_LineAuto_Faucet_DownReed == SET))
					{
						FaucetStepMotor_ZeroBack_Close();
						gu8_FaucetMoving_LineAutoStep++;
					}
				}		
				break;
			case 3:

				if(INPUT_REED_SW_FAUCET_UP == SET)
				{
					func_faucet_add_pulse_after_InputUpReed();
					gu8_F_LineAuto_Faucet_UpReed = SET;
					gu8_FaucetMoving_LineAutoStep++;
				}
				else if(gu16_FaucetMovingPulse == 0)        //@012
				{                                           //@012
					gu8_FaucetMoving_LineAutoStep++;        //@012
				}
				else
				{
				}

				break;

			case 4:                                             //@012

				break;                                          //@012

			default:
				break;
		}
	}
}

/// @brief    파우셋 내구성 모드
/// @param    void
/// @return   void
static void faucet_up_for_front_cover(void)
{
	switch(gu8_Step_Faucet_Up_forFrontCover_Open)
	{
		case 0:			//	full close
			gu8_Step_Faucet_Up_forFrontCover_Open++;
			FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);
			Play_Voice(VOICE_START_FILTER_CHANGE_MODE);
			break;
		case 1:			//	close 대기
			if(INPUT_REED_SW_FAUCET_UP == SET)					//	UP 리드스위치 감지?
			{
				func_faucet_add_pulse_after_InputUpReed();
				gu8_Step_Faucet_Up_forFrontCover_Open++;
				gu8_Timer_Faucet_Up_forFrontCover_Open = Z_FAUCET_UP_FOR_FRONT_COVER_OPEN;
			}
			else
			{	//	리드스위치 끝까지 감지 안되면 그냥 완료 치기..
				if(gu16_FaucetMovingPulse == 0)
				{
					gu8_Step_Faucet_Up_forFrontCover_Open++;
					gu8_Timer_Faucet_Up_forFrontCover_Open = Z_FAUCET_UP_FOR_FRONT_COVER_OPEN;
				}
				else
				{

				}
			}			
			break;
		case 2:				//	filter cover 닫힘 대기.

			if((gu8_OperationStep < Z_OperationStep_10)			//	플러싱 중이면...계속 유지
			|| (gu8_OperationStep == Z_OperationStep_B0)
			|| (gu8_Key_Short.byte != 0x00))
			{
				gu8_Timer_Faucet_Up_forFrontCover_Open = Z_FAUCET_UP_FOR_FRONT_COVER_OPEN;				
			}
			else if(gu8_Timer_Faucet_Up_forFrontCover_Open == 0)	//	30초 경과 후, 원래 자리로..
			{
				gu8_F_InputMicroSW_ForcedFaucetUp = CLEAR;
				gu8_Step_Faucet_Up_forFrontCover_Open = 0;
				gu8_FaucetMoving_Set_Level_Backup = CLEAR;
				#if 0
				faucet_Level_Select();
				gu8_Step_Faucet_Up_forFrontCover_Open = 4;
				#endif
				gu8_FaucetMoving_Step = Z_FAUCET_MOVING__INITIAL_SET_LEVEL;

				//	파우셋 제자리 찾아가고 음성 한번 내 기위함...
				if((gu8_F_ReedSWCheck_forFaucetTip_Voice == SET)
				&& (gu8_F_FaucetTip_Reed_Undetected == SET))
				{
					gu8_F_ReedSWCheck_forFaucetTip_Voice = CLEAR;
				}				
			}
			else
			{
				
			}
			
			break;

		#if 0
		case 4:
			if(gu16_FaucetMovingPulse == 0)
			{
				gu8_Step_Faucet_Up_forFrontCover_Open = 0;
				gu8_FaucetMoving_Step = Z_FAUCET_MOVING_WAIT;
			}
			else
			{

			}
			break;
		#endif
		default:
			break;
	}
}


/// @brief    파우셋 내구성 모드
/// @param    void
/// @return   void
static void faucet_Durability_Mode(void)
{
	switch(gu8_faucet_durability_step)
	{
		case 0:
			if(gu8_timer_faucet_durability == 0)
			{
				FaucetStepMotor_ZeroBack_Open();
				gu8_timer_faucet_durability = 30;
				gu8_faucet_durability_step = 1;
			}			
			break;
		case 1:
			if(gu8_timer_faucet_durability == 0)
			{
				FaucetStepMotor_ZeroBack_Close();
				gu8_timer_faucet_durability = 30;
				gu8_faucet_durability_step = 0;
			}		
			break;
		default:
			break;
	}
}


/// @brief    Step Motor 
/// @param    void
/// @return   void
static void func_faucet_add_pulse_after_InputUpReed(void)
{
	#if 0
	if(gu16_FaucetMovingPulse != 0)				//	리드스위치 감지 후, 펄스가 남아있으면....그만큼 펄스 더 주기..(완전히 내려오기 위함..)
	{
		// 감속 모드 사용 안함
		
		FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_INPUT_UP_REED_SW_DETECTION_ADD_PULSE);
	}
	else
	{
	}
	#endif

	gu8_F_ResetAccel_ForAddPulse = SET;  // 플래그 설정
	FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_INPUT_UP_REED_SW_DETECTION_ADD_PULSE);
}


static void func_faucet_add_pulse_after_InputDownReed(void)
{
	#if 0
	if(gu16_FaucetMovingPulse != 0)				//	리드스위치 감지 후, 펄스가 남아있으면....그만큼 펄스 더 주기..(완전히 내려오기 위함..)
	{
		// 감속 모드 사용 안함
		
		if(gu16_FaucetMovingPulse > FAUCET_INPUT_DOWN_REED_SW_DETECTION_ADD_PULSE)
		{
			FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, gu16_FaucetMovingPulse);		//	남은 펄스가 너무많으면 오차 발생하여, 일정값이상인경우 그냥 끄,ㅌ까지 내림
		}
		else
		{
			FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_INPUT_DOWN_REED_SW_DETECTION_ADD_PULSE);
		}
	}
	else
	{

	}
	#endif

	gu8_F_ResetAccel_ForAddPulse = SET;  // 플래그 설정
	FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_INPUT_DOWN_REED_SW_DETECTION_ADD_PULSE);
}

/// @brief    마이크로스위치 감지 시 감속 모드 활성화
/// @param    void
/// @return   void
static void func_faucet_decel_mode_activate(void)
{
	gu8_FaucetMoving_DecelMode = SET;
	gu8_FaucetMoving_DecelStage = 0;
	gu16_FaucetMoving_DecelCount = 0;
}

/// @brief    Step Motor 
/// @param    void
/// @return   void
void FaucetControl_StepMove(U8 mu8OpenClose, U16 mu16Pulse)
{
	// if (gu8_Stepping_ZeroBack == 0)					//	스텝초기화 flag clear인 경우
	// {
	// 	gu8_FaucetStepMotorWay = mu8OpenClose;				//		스테핑모터 방향
	// 	gu16_FaucetMovingPulse = mu16Pulse;			//		스텝 치
	// 	gu8_FaucetMoving_Pps_Control = 0;							//		PPS 세팅
	// 	gu8_FaucetMoving_Cycle = 0;							//		스텝 루틴 초기화
	// }
	// else											//	스테핑모터 초기화 중인 경우
	// {
	// 	// gu8_StepMotorWay_Backup = mu8OpenClose;		//		데이터 back up (초기화 완료 후 이동)
	// 	// gu16_StepMovingPulse_Backup = mu16Pulse;	//		데이터 back up (초기화 완료 후 이동)
	// }
    gu8_FaucetStepMotorWay = mu8OpenClose;				//		스테핑모터 방향
    gu16_FaucetMovingPulse = mu16Pulse;			//		스텝 치
    gu8_FaucetMoving_Pps_Control = 0;							//		PPS 세팅
    gu8_FaucetMoving_Cycle = 0;							//		스텝 루틴 초기화
    
    if (gu8_F_ResetAccel_ForAddPulse == CLEAR)  // 추가 펄스인 경우에만 가속 단계 초기화
    {
        gu8_FaucetMoving_AccelStage = 0;						//		가속 단계 초기화
        gu16_FaucetMoving_AccelCount = 0;						//		가속 카운터 초기화
    }
	else
	{
		gu8_F_ResetAccel_ForAddPulse = CLEAR;  // 플래그 클리어
	}
}

/// @brief    Step Motor 위치 변경(Move) 함수(1ms)
/// @param    void
/// @return   void
void FaucetStepMotorMove(void)
{
	// if ((gu8_Stepping_ZeroBack == 0) && (gu16_StepMovingPulse_Backup != 0))	//	스테핑모터 초기화 완료 후 back up 데이터 있을 경우
	// {
	// 	gu8_StepMotorWay = gu8_StepMotorWay_Backup;             //		스테핑모터 방향
	// 	gu16_StepMovingPulse = gu16_StepMovingPulse_Backup;   //		스텝 치
	// 	gu8_StepMotorWay_Backup = 0;                           //
	// 	gu16_StepMovingPulse_Backup = 0;                      //
	// }
	if((F_TestMode_PBA == SET) && (F_PBATest_FaucetMoving == SET))
	{
		F_PBATest_FaucetMoving = CLEAR;

		if(F_PBATest_FaucetStepmotorWay == 0)
		{
			FaucetStepMotor_ZeroBack_Open();
		}
		else if(F_PBATest_FaucetStepmotorWay == 1)
		{
			FaucetStepMotor_ZeroBack_Close();
		}
		else
		{

		}
	}
	else
	{
		if (gu16_FaucetMovingPulse != 0)					//      Step Motor의 이동값이 있는 경우
		{
			#if (_FAUCET_MOVING_SPEED_ == 1)
			if (gu8_FaucetStepMotorWay == FAUCET_STEP_MOTER_OPEN)  // 내려갈 때
			{
				// 리드스위치 감지 시 감속 (800 -> 500 PPS)
				if(INPUT_REED_SW_FAUCET_DOWN == SET)
				{
					// 리드스위치 감지 시 느린 속도 (500 PPS)
					gu8_FaucetMoving_Move_PPS = 20;   // 500 PPS (20회 호출당 1스텝)
					gu8_FaucetMoving_AccelStage = 0;   // 가속 단계 초기화
					gu16_FaucetMoving_AccelCount = 0;  // 가속 카운터 초기화
				}
				else
				{
					// 가속 구간 (500 -> 800 PPS)
					if (gu8_FaucetMoving_AccelStage == 0)   // 가속 구간 (0단계: 500 PPS)
					{
						// 10ms마다 가속 단계 증가
						if (++gu16_FaucetMoving_AccelCount >= FAUCET_ACCEL_10MS_COUNT)
						{
							gu16_FaucetMoving_AccelCount = 0;
							gu8_FaucetMoving_AccelStage++;   // 다음 가속 단계로 (800 PPS)
						}
						
						// 500 PPS (20회 호출당 1스텝) - 기동
						gu8_FaucetMoving_Move_PPS = 20;
					}
					else  // 가속 완료 후 정상 속도
					{
						gu8_FaucetMoving_Move_PPS = 13;   // 800 PPS (약 13회 호출당 1스텝)
					}
				}
			}
			else if (gu8_FaucetStepMotorWay == FAUCET_STEP_MOTOR_MICRO_SW_DETECTION)  // 마이크로 스위치 감지 시 (CLOSE 동작)
			{
				// 가속 구간 (500 -> 800 PPS)
				if (gu8_FaucetMoving_AccelStage == 0)   // 가속 구간 (0단계: 500 PPS)
				{
					// 10ms마다 가속 단계 증가
					if (++gu16_FaucetMoving_AccelCount >= FAUCET_ACCEL_10MS_COUNT)
					{
						gu16_FaucetMoving_AccelCount = 0;
						gu8_FaucetMoving_AccelStage++;   // 다음 가속 단계로 (800 PPS)
					}
					
					// 500 PPS (20회 호출당 1스텝) - 기동
					gu8_FaucetMoving_Move_PPS = 20;
				}
				else  // 가속 완료 후 정상 속도
				{
					gu8_FaucetMoving_Move_PPS = 13;   // 800 PPS (약 13회 호출당 1스텝)
				}
			}
			else  // 올라갈 때 (일반 CLOSE)
			{
				// 남은 펄스 또는 현재 위치를 기준으로 감속 모드 자동 활성화
				if ((((gu16_FaucetMovingPulse <= 900) || (gu16_Faucet_Current_Location <= 500)) && (gu8_FaucetMoving_DecelMode == CLEAR))
				&& (gu8_OperationStep >= Z_OperationStepNum_10)
				&& (gu8_OperationStep <= Z_OperationStepNum_43)
				&& (gu8_F_Faucet_Level_ForWifi == CLEAR)
				&& (gu8_F_Faucet_Fast_Return_for_Reed_Detected == CLEAR))
				{
					func_faucet_decel_mode_activate();
				}
				
				if (gu8_FaucetMoving_DecelMode == SET)  // 감속 모드
				{
					if (gu8_FaucetMoving_DecelStage < FAUCET_DECEL_STAGE_MAX)   // 감속 구간 (0~3단계)
					{
						// 10ms마다 감속 단계 증가
						if (++gu16_FaucetMoving_DecelCount >= FAUCET_DECEL_20MS_COUNT)
						{
							gu16_FaucetMoving_DecelCount = 0;
							gu8_FaucetMoving_DecelStage++;   // 다음 감속 단계로
						}

						// 감속 단계별 PPS 설정 (850 -> 600 -> 500 -> 400 PPS)
						switch(gu8_FaucetMoving_DecelStage)
						{
							case 0:  // 850 PPS (12회 호출당 1스텝) - 초기
								gu8_FaucetMoving_Move_PPS = 11;
								break;
							case 1:  // 600 PPS (17회 호출당 1스텝) - 감속 1단계
								gu8_FaucetMoving_Move_PPS = 12;
								break;
							case 2:  // 500 PPS (20회 호출당 1스텝) - 감속 2단계
								gu8_FaucetMoving_Move_PPS = 13;
								break;
							case 3:  // 400 PPS (25회 호출당 1스텝) - 감속 3단계
								gu8_FaucetMoving_Move_PPS = 14;
								break;
							default:
								gu8_FaucetMoving_Move_PPS = 15;  // 최종 속도
								break;
						}
					}
					else  // 감속 완료 후 최종 속도
					{
						gu8_FaucetMoving_Move_PPS = 20;   // 400 PPS (25회 호출당 1스텝)
					}
				}
				else
				{
					if (gu8_FaucetMoving_AccelStage == 0)   // 가속 구간 (0단계: 500 PPS)
					{
						// 10ms마다 가속 단계 증가
						if (++gu16_FaucetMoving_AccelCount >= FAUCET_ACCEL_10MS_COUNT)
						{
							gu16_FaucetMoving_AccelCount = 0;
							gu8_FaucetMoving_AccelStage++;   // 다음 가속 단계로 (1000 PPS)
						}
						
						// 500 PPS (20회 호출당 1스텝) - 기동
						gu8_FaucetMoving_Move_PPS = 20;
					}
					else  // 가속 완료 후 정상 속도
					{
						gu8_FaucetMoving_Move_PPS = 10;   // 1000 PPS (10회 호출당 1스텝)
					}
				}
			}				
			#elif (_FAUCET_MOVING_SPEED_ == 2)
			// 남은 펄스 또는 현재 위치를 기준으로 감속 모드 자동 활성화
			if (((gu16_FaucetMovingPulse <= 900) || (gu16_Faucet_Current_Location <= 900)) && (gu8_FaucetMoving_DecelMode == CLEAR))
			{
				func_faucet_decel_mode_activate();
			}
			
			// 감속 모드 체크
			if (gu8_FaucetMoving_DecelMode == SET)  // 감속 모드
			{
				if (gu8_FaucetMoving_DecelStage < FAUCET_DECEL_STAGE_MAX)   // 감속 구간 (0~3단계)
				{
					// 100ms마다 감속 단계 증가
					if (++gu16_FaucetMoving_DecelCount >= FAUCET_DECEL_10MS_COUNT)
					{
						gu16_FaucetMoving_DecelCount = 0;
						gu8_FaucetMoving_DecelStage++;   // 다음 감속 단계로
					}

					// 감속 단계별 PPS 설정 (1000 -> 700 -> 500 -> 400 PPS)
					switch(gu8_FaucetMoving_DecelStage)
					{
						case 0:  // 1000 PPS (10회 호출당 1스텝) - 초기
							gu8_FaucetMoving_Move_PPS = 10;
							break;
						case 1:  // 700 PPS (14회 호출당 1스텝) - 감속 1단계
							gu8_FaucetMoving_Move_PPS = 14;
							break;
						case 2:  // 500 PPS (20회 호출당 1스텝) - 감속 2단계
							gu8_FaucetMoving_Move_PPS = 20;
							break;
						case 3:  // 400 PPS (25회 호출당 1스텝) - 감속 3단계
							gu8_FaucetMoving_Move_PPS = 25;
							break;
						default:
							gu8_FaucetMoving_Move_PPS = 25;  // 최종 속도
							break;
					}
				}
				else  // 감속 완료 후 최종 속도
				{
					gu8_FaucetMoving_Move_PPS = 25;   // 400 PPS (25회 호출당 1스텝)
				}
			}
			else  // 가속/정상 모드
			{
				if (gu8_FaucetStepMotorWay == FAUCET_STEP_MOTER_OPEN)  // 내려갈 때
				{
					if (gu8_FaucetMoving_AccelStage < FAUCET_ACCEL_OPEN_STAGE_MAX)   // 가속 구간 (0~2단계)
					{
						// 100ms마다 가속 단계 증가
						if (++gu16_FaucetMoving_AccelCount >= FAUCET_ACCEL_10MS_COUNT)
						{
							gu16_FaucetMoving_AccelCount = 0;
							gu8_FaucetMoving_AccelStage++;   // 다음 가속 단계로
						}

						// 가속 단계별 PPS 설정 (내려갈 때: 500 -> 700 -> 1000 PPS)
						switch(gu8_FaucetMoving_AccelStage)
						{
							case 0:  // 500 PPS (20회 호출당 1스텝) - 기동
								gu8_FaucetMoving_Move_PPS = 20;
								break;
							case 1:  // 700 PPS (14회 호출당 1스텝) - 가속 1단계
								gu8_FaucetMoving_Move_PPS = 14;
								break;
							case 2:  // 1000 PPS (10회 호출당 1스텝) - 가속 2단계
								gu8_FaucetMoving_Move_PPS = 10;
								break;
							default:
								gu8_FaucetMoving_Move_PPS = 10;  // 최대 속도
								break;
						}
					}
					else  // 가속 완료 후 정상 속도
					{
						gu8_FaucetMoving_Move_PPS = 10;   // 1000 PPS (10회 호출당 1스텝)
					}
				}
				else  // 올라갈 때
				{
					if (gu8_FaucetMoving_AccelStage < FAUCET_ACCEL_OPEN_STAGE_MAX)   // 가속 구간 (0~1단계)
					{
						// 100ms마다 가속 단계 증가
						if (++gu16_FaucetMoving_AccelCount >= FAUCET_ACCEL_10MS_COUNT)
						{
							gu16_FaucetMoving_AccelCount = 0;
							gu8_FaucetMoving_AccelStage++;   // 다음 가속 단계로
						}

						// 가속 단계별 PPS 설정 (올라갈 때)
						switch(gu8_FaucetMoving_AccelStage)
						{
							case 0:  // 500 PPS (20회 호출당 1스텝) - 기동
								gu8_FaucetMoving_Move_PPS = 20;
								break;
							case 1:  // 1000 PPS (10회 호출당 1스텝) - 구동
								gu8_FaucetMoving_Move_PPS = 10;
								break;
							default:
								gu8_FaucetMoving_Move_PPS = 10;  // 최대 속도
								break;
						}
					}
					else  // 가속 완료 후 정상 속도
					{
						gu8_FaucetMoving_Move_PPS = 10;   // 1000 PPS (10회 호출당 1스텝)
					}
				}
			}

			#else
			// 내려갈 때: 500 -> 1000 PPS (감속 없음)
			// 올라갈 때: 500 -> 1000 -> 714 -> 500 -> 400 (감속 있음, 900 펄스 이하에서 감속 시작)
			// 마이크로 스위치 감지 시: 500 -> 1000 PPS (감속 없음, CLOSE 동작)
			
			if (gu8_FaucetStepMotorWay == FAUCET_STEP_MOTER_OPEN)  // 내려갈 때
			{
				// 리드스위치 감지 시 천천히 내려가기 (1000 -> 500 PPS)
				if(INPUT_REED_SW_FAUCET_DOWN == SET)
				{
					// 리드스위치 감지 시 느린 속도 (500 PPS)
					gu8_FaucetMoving_Move_PPS = 20;   // 500 PPS (20회 호출당 1스텝)
					gu8_FaucetMoving_AccelStage = 0;   //@007 가속 단계 초기화
					gu16_FaucetMoving_AccelCount = 0;  //@007 가속 카운터 초기화
				}
				else
				{
					// 가속 구간 (500 -> 1000 PPS)
					if (gu8_FaucetMoving_AccelStage == 0)   // 가속 구간 (0단계: 500 PPS)
					{
						// 10ms마다 가속 단계 증가
						if (++gu16_FaucetMoving_AccelCount >= FAUCET_ACCEL_10MS_COUNT)
						{
							gu16_FaucetMoving_AccelCount = 0;
							gu8_FaucetMoving_AccelStage++;   // 다음 가속 단계로 (1000 PPS)
						}
						
						// 500 PPS (20회 호출당 1스텝) - 기동
						gu8_FaucetMoving_Move_PPS = 20;
					}
					else  // 가속 완료 후 정상 속도
					{
						//@007 gu8_FaucetMoving_Move_PPS = 10;   // 1000 PPS (10회 호출당 1스텝)
						gu8_FaucetMoving_Move_PPS = 13;   //@007 800 PPS (약 13회 호출당 1스텝)
					}
				}
			}
			else if (gu8_FaucetStepMotorWay == FAUCET_STEP_MOTOR_MICRO_SW_DETECTION)  // 마이크로 스위치 감지 시 (CLOSE 동작, 감속 없음)
			{
				// 가속 구간 (500 -> 1000 PPS)
				if (gu8_FaucetMoving_AccelStage == 0)   // 가속 구간 (0단계: 500 PPS)
				{
					// 10ms마다 가속 단계 증가
					if (++gu16_FaucetMoving_AccelCount >= FAUCET_ACCEL_10MS_COUNT)
					{
						gu16_FaucetMoving_AccelCount = 0;
						gu8_FaucetMoving_AccelStage++;   // 다음 가속 단계로 (1000 PPS)
					}
					
					// 500 PPS (20회 호출당 1스텝) - 기동
					gu8_FaucetMoving_Move_PPS = 20;
				}
				else  // 가속 완료 후 정상 속도
				{
					gu8_FaucetMoving_Move_PPS = 10;   // 1000 PPS (10회 호출당 1스텝)
				}
			}
			else  // 올라갈 때 (일반 CLOSE)
			{
				// 남은 펄스 또는 현재 위치를 기준으로 감속 모드 자동 활성화
				if ((((gu16_FaucetMovingPulse <= 900) || (gu16_Faucet_Current_Location <= 500)) && (gu8_FaucetMoving_DecelMode == CLEAR))
				&& (gu8_OperationStep >= Z_OperationStepNum_10)
				&& (gu8_OperationStep <= Z_OperationStepNum_43)
				&& (gu8_F_Faucet_Level_ForWifi == CLEAR)
				&& (gu8_F_Faucet_Fast_Return_for_Reed_Detected == CLEAR))
				{
					func_faucet_decel_mode_activate();
				}
				
				if (gu8_FaucetMoving_DecelMode == SET)  // 감속 모드
				{
					if (gu8_FaucetMoving_DecelStage < FAUCET_DECEL_STAGE_MAX)   // 감속 구간 (0~3단계)
					{
						// 10ms마다 감속 단계 증가
						if (++gu16_FaucetMoving_DecelCount >= FAUCET_DECEL_20MS_COUNT)
						{
							gu16_FaucetMoving_DecelCount = 0;
							gu8_FaucetMoving_DecelStage++;   // 다음 감속 단계로
						}

						// 감속 단계별 PPS 설정 (850 -> 600 -> 500 -> 400 PPS)
						switch(gu8_FaucetMoving_DecelStage)
						{
							case 0:  // 850 PPS (12회 호출당 1스텝) - 초기
								gu8_FaucetMoving_Move_PPS = 11;
								break;
							case 1:  // 600 PPS (17회 호출당 1스텝) - 감속 1단계
								gu8_FaucetMoving_Move_PPS = 12;
								break;
							case 2:  // 500 PPS (20회 호출당 1스텝) - 감속 2단계
								gu8_FaucetMoving_Move_PPS = 13;
								break;
							case 3:  // 400 PPS (25회 호출당 1스텝) - 감속 3단계
								gu8_FaucetMoving_Move_PPS = 14;
								break;
							default:
								gu8_FaucetMoving_Move_PPS = 15;  // 최종 속도
								break;
						}
					}
					else  // 감속 완료 후 최종 속도
					{
						gu8_FaucetMoving_Move_PPS = 20;   // 400 PPS (25회 호출당 1스텝)
					}
				}
				else
				{
					if (gu8_FaucetMoving_AccelStage == 0)   // 가속 구간 (0단계: 500 PPS)
					{
						// 10ms마다 가속 단계 증가
						if (++gu16_FaucetMoving_AccelCount >= FAUCET_ACCEL_10MS_COUNT)
						{
							gu16_FaucetMoving_AccelCount = 0;
							gu8_FaucetMoving_AccelStage++;   // 다음 가속 단계로 (1000 PPS)
						}
						
						// 500 PPS (20회 호출당 1스텝) - 기동
						gu8_FaucetMoving_Move_PPS = 20;
					}
					else  // 가속 완료 후 정상 속도
					{
						gu8_FaucetMoving_Move_PPS = 10;   // 1000 PPS (10회 호출당 1스텝)
					}
				}
			}
			
			#endif

			if (++gu8_Count_FaucetMoving_Move_PPS >= gu8_FaucetMoving_Move_PPS)			//		PPS 성립 시
			{
				gu8_Count_FaucetMoving_Move_PPS = 0;							//			카운트 초기화

				gu16_FaucetMovingPulse--;					//			움직일 스텝 감소
				FaucetStepMotor_Control();    				//			스테핑모터 제어

				if (++gu8_FaucetMoving_Cycle >= 8)				//			8 Cycle 루틴 초과인 경우
				{
					gu8_FaucetMoving_Cycle = 0;					//				루틴카운터 초기화
				}
			}

			gu16_Backup_FaucetMovingPulse = gu16_FaucetMovingPulse;			//	백업...내러오는 도중 취소하면...그만큼 올라가기 위함.			
		}
		else											// 	Step Motor의 이동값이 없는 경우
		{
			gu16_FaucetMovingPulse = 0;					//		데이터 초기화
			gu8_FaucetMoving_Pps_Control = 0;							//		데이터 초기화
			// gu8_FaucetMoving_Cycle = 0;							//		데이터 초기화
			gu8_FaucetMoving_AccelStage = 0;						//		가속 단계 초기화
			gu16_FaucetMoving_AccelCount = 0;						//		가속 카운터 초기화
			gu8_FaucetMoving_DecelMode = 0;						//		감속 모드 초기화
			gu8_FaucetMoving_DecelStage = 0;						//		감속 단계 초기화
			gu16_FaucetMoving_DecelCount = 0;						//		감속 카운터 초기화
			gu8_FaucetStepMotorWay = FAUCET_STEP_MOTER_OPEN;			//		OPEN으로 셋팅

			FaucetStepMotor_Stop();							//		스텝제어 정지 (여자 OFF)
		}
	}
}


/// @brief    Step Motor 제어 함수
/// @param    void
/// @return   void
void FaucetStepMotor_Control(void)
{
	U8 mu8FaucetStep_Order = 0;

	if (gu8_FaucetMoving_ZeroBack == 1)				//		OPEN 초기화 지시 있는 경우
	{
		gu8_FaucetMoving_ZeroBack = 0;				//			Flag Clear
	}
	else if (gu8_FaucetMoving_ZeroBack == 2)          //		CLOSE 초기화 지시 있는 경우
	{
		gu8_FaucetMoving_ZeroBack = 0;                //			Flag Clear
	}
	else
	{
	}


	if (gu8_FaucetStepMotorWay == FAUCET_STEP_MOTER_CLOSE)		//	CLOSE 지시 인 경우
	{
		mu8FaucetStep_Order = au8FaucetStep_Close[gu8_FaucetMoving_Cycle];	//		CLOSE 루틴
	}
	else if(gu8_FaucetStepMotorWay == FAUCET_STEP_MOTOR_MICRO_SW_DETECTION)		//	마이크로 스위치 감지 지시 인 경우
	{
		mu8FaucetStep_Order = au8FaucetStep_Close[gu8_FaucetMoving_Cycle];	//		CLOSE 루틴
	}	
	else											//	OPEN 지시
	{
		mu8FaucetStep_Order = au8FaucetStep_Open[gu8_FaucetMoving_Cycle];	//		OPEN 루틴
	}


	// 현재 위치 업데이트 (한 사이클 완료 시: gu8_FaucetMoving_Cycle이 7일 때, 다음 호출에서 0으로 리셋됨)
	
	if (gu8_FaucetStepMotorWay == FAUCET_STEP_MOTER_OPEN)
	{
		// OPEN 방향 위치 증가 (내려감)
		gu16_Faucet_Current_Location++;
	}
	else if ((gu8_FaucetStepMotorWay == FAUCET_STEP_MOTER_CLOSE) || (gu8_FaucetStepMotorWay == FAUCET_STEP_MOTOR_MICRO_SW_DETECTION))
	{
		// CLOSE 방향 위치 감소 (올라감)
		if(gu16_Faucet_Current_Location > 0)
		{
			gu16_Faucet_Current_Location--;
		}
	}

	switch (mu8FaucetStep_Order)
	{
		case 1:
			P_FAUCET_STEPMOTOR1 = 0;
			P_FAUCET_STEPMOTOR2 = 0;
			P_FAUCET_STEPMOTOR3 = 0;
			P_FAUCET_STEPMOTOR4 = 1;
			break;
		case 2:
			P_FAUCET_STEPMOTOR1 = 1;
			P_FAUCET_STEPMOTOR2 = 0;
			P_FAUCET_STEPMOTOR3 = 0;
			P_FAUCET_STEPMOTOR4 = 1;
			break;
		case 3:
			P_FAUCET_STEPMOTOR1 = 1;
			P_FAUCET_STEPMOTOR2 = 0;
			P_FAUCET_STEPMOTOR3 = 0;
			P_FAUCET_STEPMOTOR4 = 0;
			break;
		case 4:
			P_FAUCET_STEPMOTOR1 = 1;
			P_FAUCET_STEPMOTOR2 = 1;
			P_FAUCET_STEPMOTOR3 = 0;
			P_FAUCET_STEPMOTOR4 = 0;
			break;
		case 5:
			P_FAUCET_STEPMOTOR1 = 0;
			P_FAUCET_STEPMOTOR2 = 1;
			P_FAUCET_STEPMOTOR3 = 0;
			P_FAUCET_STEPMOTOR4 = 0;
			break;
		case 6:
			P_FAUCET_STEPMOTOR1 = 0;
			P_FAUCET_STEPMOTOR2 = 1;
			P_FAUCET_STEPMOTOR3 = 1;
			P_FAUCET_STEPMOTOR4 = 0;
			break;
		case 7:
			P_FAUCET_STEPMOTOR1 = 0;
			P_FAUCET_STEPMOTOR2 = 0;
			P_FAUCET_STEPMOTOR3 = 1;
			P_FAUCET_STEPMOTOR4 = 0;
			break;
		case 8:
			P_FAUCET_STEPMOTOR1 = 0;
			P_FAUCET_STEPMOTOR2 = 0;
			P_FAUCET_STEPMOTOR3 = 1;
			P_FAUCET_STEPMOTOR4 = 1;
			break;
		default:
			P_FAUCET_STEPMOTOR1 = 0;
			P_FAUCET_STEPMOTOR2 = 0;
			P_FAUCET_STEPMOTOR3 = 0;
			P_FAUCET_STEPMOTOR4 = 0;
			break;
	}
}



/// @brief    Tray Step Motor Stop Function
/// @param    void
/// @return   void
void FaucetStepMotor_Stop(void)
{
    P_FAUCET_STEPMOTOR1 = 0;
    P_FAUCET_STEPMOTOR2 = 0;
    P_FAUCET_STEPMOTOR3 = 0;
    P_FAUCET_STEPMOTOR4 = 0;
}


/// @brief    Step Motor Open Position Zero Back
/// @param    void
/// @return   void
void FaucetStepMotor_ZeroBack_Open(void)
{
	FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_STEP_ZERO_BACK);
	gu8_FaucetMoving_ZeroBack = 1;
}

/// @brief    Step Motor Close Position Zero Back
/// @param    void
/// @return   void
void FaucetStepMotor_ZeroBack_Close(void)
{
	FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);
	gu8_FaucetMoving_ZeroBack = 2;
}

/// @brief    스마트체크 파우셋 무빙 테스트
/// @param    void
/// @return   void
static void func_faucet_moving_SmartCheck(void)
{
	static U8 mu8_flag_pulse;
	
	switch(gu8_SmartCheck_Faucet_Moving_Step)
	{
		case 0:  // 초기화 및 최상단으로 올리기		
			
			F_SmartCheck_Faucet_Complete = CLEAR;

			if(gu8_FaucetMoving_Set_Level > Z_FAUCET_MOVING_FIX_1_LEVEL)
			{
				// 최상단까지 올리기
				FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);
				gu8_SmartCheck_Faucet_Moving_Step = 1;  // 최상단 도달 대기
			}
			else
			{
				gu8_SmartCheck_Faucet_Moving_Step = 2;
			}

			break;
			
		case 1:  // 최상단 도달 대기 (UP 리드스위치 감지 + 추가 펄스)
			// UP 리드스위치 감지됨 (추가 펄스가 진행 중이 아닐 때만)
			if(INPUT_REED_SW_FAUCET_UP == SET)
			{
				smartcheck_add_pulse_after_InputUpReed();  // 추가 펄스 처리
				// 최상단 도달 완료, CMD 지시 대기 단계로 이동
				gu8_SmartCheck_Faucet_Moving_Step = 2;
				F_SmartCheck_UpReed_Detected = SET;  // 감지 이력 저장
			}
			else if(gu16_FaucetMovingPulse == 0)  // 펄스 완료됨
			{
				// 최상단 도달 완료, CMD 지시 대기 단계로 이동
				gu8_SmartCheck_Faucet_Moving_Step = 2;
			}
			else
			{

			}
			break;
			
		case 2:  // F_SmartCheck_FaucetMoving_CMD 지시 대기
			// CMD 지시가 SET일 때까지 대기
			if((F_SmartCheck_FaucetMoving_CMD == SET) && (gu16_FaucetMovingPulse == 0))
			{
				// 지시 확인됨, 하강 시작
				F_SmartCheck_FaucetMoving_CMD = CLEAR;
				gu8_SmartCheck_Faucet_Moving_Step = 3;
				FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_STEP_ZERO_BACK);
			}
			
			if(INPUT_REED_SW_FAUCET_UP == SET)
			{
				gu16_SmartCheck_Result_Faucet_ReedDetected = 1;  // 감지 이력 저장
			}

			break;
			
		case 3: 
			// 하강 시작
			// 마이크로 스위치 감지됨 (하강 중 감지 시 바로 상승)
			if(INPUT_MICRO_SW_FAUCET == SET)
			{
				gu16_SmartCheck_Result_CupDetection_MicroSW = SET;
				// 마이크로 스위치 감지되면 바로 상승
				// FaucetControl_StepMove(FAUCET_STEP_MOTOR_MICRO_SW_DETECTION, FAUCET_MICO_SW_INPUT_DETECTION_STEP);
				FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);
				gu8_SmartCheck_Faucet_Moving_Step = 4;  // 상승 중 단계로
			}
			else
			{
				if(INPUT_REED_SW_FAUCET_DOWN == SET)
				{
					gu16_SmartCheck_Result_CupDetection_MicroSW = CLEAR;
					smartcheck_add_pulse_after_InputDownReed();  // 추가 펄스 처리
					gu8_SmartCheck_Faucet_Moving_Step = 4;
					mu8_flag_pulse = 0;
				}
				else if(gu16_FaucetMovingPulse == 0)  // 펄스 완료됐는데 리드스위치 안잡힘
				{
					gu16_SmartCheck_Result_CupDetection_MicroSW = CLEAR;
					gu8_SmartCheck_Faucet_Moving_Step = 4;  // 다음 단계로	
					mu8_flag_pulse = 0;
				}
				else
				{

				}
			}

			if(INPUT_REED_SW_FAUCET_UP == CLEAR)
			{
				gu16_SmartCheck_Result_Faucet_ReedDetected = 2;  // 감지 이력 초기화
			}

			gu8_Timer_SmartCheck_Faucet_Moving = 5;		
			
			
			break;
			
		case 4:  // 상승 준비

			if (gu8_Timer_SmartCheck_Faucet_Moving == 0)
			{
				FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_STEP_ZERO_BACK);
				gu8_SmartCheck_Faucet_Moving_Step = 5;
			}		
			break;
			
		case 5:  // 상승 중 - UP 리드스위치 대기
			// UP 리드스위치 감지됨
			if(INPUT_REED_SW_FAUCET_UP == SET)
			{
				smartcheck_add_pulse_after_InputUpReed();  // 추가 펄스 처리
				// 상승 성공 표시
				gu8_SmartCheck_Faucet_Moving_Step = 6;  // 완료
			}
			else if(gu16_FaucetMovingPulse == 0)  // 펄스 완료됐는데 리드스위치 안잡힘
			{
				gu8_SmartCheck_Faucet_Moving_Step = 6;
			}
			else
			{
				
			}
			break;
			
		case 6:  // 완료
		default:
		
			F_SmartCheck_Faucet_Complete = SET;

			if((gu16_FaucetMovingPulse == 0)
			&& (gu8_OperationStep != Z_OperationStep_80))
			{
				gu8_FaucetMoving_Step = Z_FAUCET_MOVING__INITIAL_SET_LEVEL;
				gu8_SmartCheck_Faucet_Moving_Step = 0;
			}

			break;
	}

	// if((F_SmartCheck_FaucetMoving_CMD == CLEAR)
	// && (gu8_OperationStep != Z_OperationStep_80))
	// {
	// 	smartcheck_initial();
	// }
}

/// @brief    SmartCheck UP 리드스위치 감지 후 추가 펄스
/// @param    void
/// @return   void
static void smartcheck_add_pulse_after_InputUpReed(void)
{
	#if 0
	if(gu16_FaucetMovingPulse != 0)		// 남은 펄스가 있으면
	{
		if(gu16_FaucetMovingPulse > FAUCET_INPUT_UP_REED_SW_DETECTION_ADD_PULSE)
		{
			// 남은 펄스만큼 더 상승
			FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, gu16_FaucetMovingPulse);
		}
		else
		{
			// 고정값만큼 더 상승
			FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_INPUT_UP_REED_SW_DETECTION_ADD_PULSE);
		}	
	}
	#endif		

	gu8_F_ResetAccel_ForAddPulse = SET;  // 플래그 설정
	FaucetControl_StepMove(FAUCET_STEP_MOTER_CLOSE, FAUCET_INPUT_UP_REED_SW_DETECTION_ADD_PULSE);
}

/// @brief    SmartCheck DOWN 리드스위치 감지 후 추가 펄스
/// @param    void
/// @return   void
static void smartcheck_add_pulse_after_InputDownReed(void)
{
	#if 0
	if(gu16_FaucetMovingPulse != 0)		// 남은 펄스가 있으면
	{
		if(gu16_FaucetMovingPulse > FAUCET_INPUT_DOWN_REED_SW_DETECTION_ADD_PULSE)
		{
			// 남은 펄스가 너무많으면 오차 발생하여, 일정값이상인경우 그냥 끝까지 내림
			FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_INPUT_DOWN_REED_SW_DETECTION_ADD_PULSE);
		}
		else
		{
			// 남은 펄스만큼 더 하강
			FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, gu16_FaucetMovingPulse);
		}
	}
	#endif
	gu8_F_ResetAccel_ForAddPulse = SET;  // 플래그 설정
	FaucetControl_StepMove(FAUCET_STEP_MOTER_OPEN, FAUCET_INPUT_DOWN_REED_SW_DETECTION_ADD_PULSE);
}

/// @brief    SmartCheck initial
/// @param    void
/// @return   void
static void smartcheck_initial(void)
{
	gu8_SmartCheck_Faucet_Moving_Step = 0;
	gu8_FaucetMoving_Step = Z_FAUCET_MOVING_INITIAL;  // 대기 상태로
}
