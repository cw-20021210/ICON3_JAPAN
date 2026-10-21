/// @file   faucet_moving.h
/// @date   2025.07.03
/// @author LJH
/// @brief  Faucet moving 처占쏙옙

#ifdef _FAUCET_MOVING_
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_FAUCET_MOVING()	{	/*	1ms 타占싱몌옙 占쏙옙占쏙옙			*/	\
									}
#define	TDEC_10ms_FAUCET_MOVING()	{	/*	10ms 타占싱몌옙 占쏙옙占쏙옙		*/	\
									}
#define	TDEC_100ms_FAUCET_MOVING()	{	/*	100ms 타이머 감산		*/	\
										TDEC(gu8_Timer_LineAuto_Faucet_DownReed);	\
										TDEC(gu8_Timer_FaucetDown_WaitingTime);	\
										TDEC(gu8_Timer_Display_Moving_Durability);	\
										TDEC(gu8_Timer_SmartCheck_Faucet_Moving);	\
									}
#define	TDEC_1s_FAUCET_MOVING()		{	/*	1s 타占싱몌옙 占쏙옙占쏙옙			*/	\
										TDEC(gu8_timer_faucet_durability);	\
										TDEC(gu8_Timer_Faucet_Up_forFrontCover_Open);	\
									}
#define	TDEC_10s_FAUCET_MOVING()	{	/*	10s 타占싱몌옙 占쏙옙占쏙옙			*/	\
									}
#define	TDEC_1min_FAUCET_MOVING()	{	/*	1min 타占싱몌옙 占쏙옙占쏙옙		*/	\
									}
#define	TDEC_10min_FAUCET_MOVING()	{	/*	10min 타占싱몌옙 占쏙옙占쏙옙		*/	\
									}
#define	TDEC_1h_FAUCET_MOVING()		{	/*	1h 타占싱몌옙 占쏙옙占쏙옙			*/	\
									}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
#define FAUCET_STEP_MOTER_OPEN   (0)						//	OPEN ??
#define FAUCET_STEP_MOTER_CLOSE  (1)						//	CLOSE ??
#define FAUCET_STEP_MOTOR_MICRO_SW_DETECTION   (2)			//	???? ??? ??

#if 0
#define FAUCET_STEP_ZERO_BACK         (3500)					//	占십깍옙화 占쏙옙
#define FAUCET_MICO_SW_INPUT_DETECTION_STEP 	(700)


#define FAUCET_INPUT_UP_REED_SW_DETECTION_ADD_PULSE	(220)
#define FAUCET_INPUT_DOWN_REED_SW_DETECTION_ADD_PULSE	(400)
#endif

// 속도 이슈로 기어 변경으로 인한, 펄스값 변경
#define FAUCET_STEP_ZERO_BACK         (2000)					//	占십깍옙화 占쏙옙
#define FAUCET_MICO_SW_INPUT_DETECTION_STEP 	(350)


#define FAUCET_INPUT_UP_REED_SW_DETECTION_ADD_PULSE	(100)
#define FAUCET_INPUT_DOWN_REED_SW_DETECTION_ADD_PULSE	(130)


#define Z_Faucet_SteppingMotor_TorqueUp_Count   (5)

// ?? ?? ?? (? 100ms ??)
#define FAUCET_ACCEL_STAGE_0_PPS    (333)   // 333 PPS (30? ??? 1??)
#define FAUCET_ACCEL_STAGE_1_PPS    (400)   // 400 PPS (25? ??? 1??)
#define FAUCET_ACCEL_STAGE_2_PPS    (500)   // 500 PPS (20? ??? 1??)
#define FAUCET_ACCEL_STAGE_3_PPS    (666)   // 666 PPS (15? ??? 1??)
#define FAUCET_ACCEL_STAGE_MAX      (4)     // ?? ?? ?
#define FAUCET_ACCEL_100MS_COUNT    (1000)  // 100ms = 1000 * 100us
#define FAUCET_ACCEL_10MS_COUNT    (100)  // 10ms = 100 * 100us

#define FAUCET_DECEL_50MS_COUNT     (500)   // 50ms = 500 * 100us (?? ??)
#define FAUCET_DECEL_5MS_COUNT      (50)    // 5ms = 50 * 100us (??? ? ??)

// ?? ?? ?? (??????? ?? ?)
#define FAUCET_DECEL_STAGE_0_PPS    (1000)  // 1000 PPS (10? ??? 1??)
#define FAUCET_DECEL_STAGE_1_PPS    (700)   // 700 PPS (14? ??? 1??)
#define FAUCET_DECEL_STAGE_2_PPS    (500)   // 500 PPS (20? ??? 1??)
#define FAUCET_DECEL_STAGE_3_PPS    (400)   // 400 PPS (25? ??? 1??)
#define FAUCET_DECEL_STAGE_MAX      (4)     // ?? ?? ?? (0~3??)
#define FAUCET_DECEL_100MS_COUNT    (1000)  // 100ms = 1000 * 100us
#define FAUCET_DECEL_20MS_COUNT    (200)  // 20ms = 200 * 100us
#define FAUCET_DECEL_10MS_COUNT    (100)  // 10ms = 100 * 100us


// ??? ? ?? ?? ?? (? ???)
#define FAUCET_ACCEL_OPEN_STAGE_0_PPS    (250)   // 250 PPS (40? ??? 1??)
#define FAUCET_ACCEL_OPEN_STAGE_1_PPS    (300)   // 300 PPS (33? ??? 1??)
#define FAUCET_ACCEL_OPEN_STAGE_MAX      (3)     // ??? ? ?? ?? ?? (0~2??: 500->700->1000)
#define FAUCET_ACCEL_OPEN_50MS_COUNT     (500)   // 50ms = 500 * 100us (?? ???)

// ?? ?? (?? ?? ?)
#define FAUCET_MAX_PPS_CLOSE        (833)   // ??? ? ?? ?? (12? ??? 1??, ? 833 PPS)
#define FAUCET_MAX_PPS_OPEN         (1000)  // ??? ? ?? ?? (10? ??? 1??)

#define Z_FAUCET_MOVING_AUTO_LEVEL		(1)
#define Z_FAUCET_MOVING_FIX_1_LEVEL		(2)
#define Z_FAUCET_MOVING_FIX_2_LEVEL		(3)
#define Z_FAUCET_MOVING_FIX_3_LEVEL		(4)
#define Z_FAUCET_MOVING_FIX_4_LEVEL		(5)
#define Z_FAUCET_MOVING_FIX_5_LEVEL		(6)


#define Z_FAUCET_MOVING_FIX_1_LEVEL_PULSE		(0)      // 0% (0 / 1500)
#define Z_FAUCET_MOVING_FIX_2_LEVEL_PULSE		(375)    // 25% (375 / 1500)
#define Z_FAUCET_MOVING_FIX_3_LEVEL_PULSE		(750)    // 50% (750 / 1500)
#define Z_FAUCET_MOVING_FIX_4_LEVEL_PULSE		(1125)   // 75% (1125 / 1500)
#define Z_FAUCET_MOVING_FIX_5_LEVEL_PULSE		(1500)   // 100% (1500 / 1500)

#define Z_FAUCET_BACKLASH_COMPENSATION    (260)  // ??? ??

enum{
	Z_FAUCET_MOVING_INITIAL,
	Z_FAUCET_MOVING__INITIAL_SET_LEVEL,
	Z_FAUCET_MOVING__INITIAL_SET_LEVEL_COMPLETE,
	Z_FAUCET_MOVING_WAIT,
	Z_FAUCET_MOVING_DOWN,
	Z_FAUCET_MOVING__DOWN_COMPLETE,
	Z_WAIT_FOR_EFFLUENT_COMPLETE,
	Z_WAIT_FOR_FAUCET_MOVING_DOWN,
	Z_FAUCET_MOVING_UP,
	Z_FAUCET_MOVING__UP_COMPLETE,
	Z_FAUCET_MOVING_LINE_AUTO,
	Z_FAUCET_MOVING_LINE_TEST_2,
	Z_FAUCET_MOVING_SMARTCHECK,
	Z_FAUCET_LEVEL_SETTING,
	Z_FILTER_CHANGE_MODE,
	Z_FAUCET_REED_UNDETECTED_MOVE_UP,  // 리드스위치 미감지 시 최상단 이동
	Z_FAUCET_REED_UNDETECTED_WAIT_TIP,  // 리드스위치 미감지 시 팁 리드스위치 감지 대기
};



enum{
	Z_FAUCET_SET_MODE_WAIT,
	Z_FAUCET_SET_MODE_FULL_UP,
	Z_FAUCET_SET_MODE_FULL_DOWN,
	Z_FAUCET_SET_MODE_SETTING,
};


#define Z_FAUCET_DOWN_WAITING_TIME			(10)


#define Z_FAUCET_UP_FOR_FRONT_COVER_OPEN		(60)

// 팁 리드 전환 감지 전용 (faucet_moving만 사용)
#define F_FAUCET_REED_EDGE_NONE           0u   // @018
#define F_FAUCET_REED_EDGE_TO_UNDETECTED 1u   // @018감지 -> 미감지
#define F_FAUCET_REED_EDGE_TO_DETECTED   2u   // @018미감지 -> 감지
/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN U8 gu8_FaucetMoving_Step; 

EXTERN U8 gu8_F_FaucetMoving_Initialize;			//	占식울옙占? 占십깍옙화 flag.......1~5占쌤곤옙 占쏙옙占쏙옙占실억옙占쏙옙占쏙옙占쏙옙 占쌔댐옙占쌘몌옙占쏙옙 占쏙옙占쏙옙占쏙옙占쏙옙.
EXTERN U8 gu8_F_FaucetMoving_Set_Init;

EXTERN U8 gu8_FaucetStepMotorWay;
EXTERN U16 gu16_FaucetMovingPulse;
EXTERN U8 gu8_FaucetMoving_Pps_Control;
EXTERN U8 gu8_FaucetMoving_Move_PPS;
EXTERN U8 gu8_Count_FaucetMoving_Move_PPS;
EXTERN U8 gu8_FaucetMoving_Cycle;
EXTERN U8 gu8_FaucetMoving_AccelStage;      // ?? ?? (0~3)
EXTERN U16 gu16_FaucetMoving_AccelCount;    // ?? ??? (100ms ??)
EXTERN U8 gu8_FaucetMoving_DecelMode;       // ?? ?? ??? (0: ??/??, 1: ??)
EXTERN U8 gu8_FaucetMoving_DecelStage;      // ?? ?? (0~4)
EXTERN U16 gu16_FaucetMoving_DecelCount;    // ?? ??? (100ms ??)

EXTERN U8 gu8_FaucetMoving_ZeroBack;

EXTERN U8 gu8_F_ResetAccel_ForAddPulse;  // 추가 펄스 시 가속 단계 초기화 플래그

EXTERN U8 gu8_F_Finish_Faucet_Down;
EXTERN U8 gu8_F_Finish_Faucet_Up;
EXTERN U8 gu8_F_MicroSW_LateDetection;			//	占쌕운리占쏙옙 占쏙옙占쏙옙 占쏙옙, 占쏙옙占쏙옙크占쏙옙 占쏙옙占쏙옙치 占쏙옙占쏙옙占쌀띰옙...pulse 占싹뤄옙 占쏙옙占쏙옙占쏙옙占쏙옙


EXTERN U8 gu8_Timer_FaucetDown_WaitingTime;

EXTERN U16 gu16_Backup_FaucetMovingPulse;
EXTERN U16 gu16_Faucet_Current_Location;


EXTERN U8 gu8_FaucetMoving_Set_Level;
EXTERN U8 gu8_FaucetMoving_Set_Level_Backup;
EXTERN U8 gu8_F_FaucetMoving_Set_Level_Way;
EXTERN U8 gu8_F_Faucet_Fast_Return_for_Reed_Detected;		//	파우셋 팁 미감지 -> 감지 시, 감속 안주기 위함.


EXTERN U8 gu8_Faucet_Level_Set_Step;
EXTERN U8 gu8_F_Faucet_Level_ForWifi;

EXTERN U8 gu8_F_Faucet_LittleDown;


EXTERN U8 gu8_Step_Faucet_Up_forFrontCover_Open;
EXTERN U8 gu8_Timer_Faucet_Up_forFrontCover_Open;

EXTERN U8 gu8_FaucetMoving_LineAutoStep;
EXTERN U8 gu8_F_LineAuto_Faucet_DownReed;
EXTERN U8 gu8_F_LineAuto_Faucet_UpReed;
EXTERN U8 gu8_F_LineAuto_Faucet_MicroSW;
EXTERN U8 gu8_Timer_LineAuto_Faucet_DownReed;

EXTERN U8 gu8_LineAuto_CupMicroSW_Step;    // @022 마이크로스위치 미감지→감지→미감지 패턴 추적



/*********특占쏙옙占쏙옙占?**********/
EXTERN U8 gu8_F_Moving_Durability;
EXTERN U8 gu8_Timer_Display_Moving_Durability;
EXTERN U8 gu8_faucet_durability_step;
EXTERN U8 gu8_timer_faucet_durability;
/**************************/

/*********SmartCheck 占식울옙占? 占쏙옙占쏙옙**********/
EXTERN U8 gu8_SmartCheck_Faucet_Moving_Step;
EXTERN U8 F_SmartCheck_Faucet_CMD;			// SmartCheck 占식울옙占? 占쌓쏙옙트 占쏙옙占쏙옙
EXTERN U8 F_SmartCheck_Faucet_Complete;		// SmartCheck 占식울옙占? 占쌓쏙옙트 占싹뤄옙
EXTERN U8 gu8_Timer_SmartCheck_Faucet_Moving;
EXTERN U8 gu8_F_Fuacet_UpReed_AddPulse_X_afterSmartCheck;

// EXTERN U16 gu16_SmartCheck_Result_FaucetUp_Reed;	// 占식울옙占? UP 占쏙옙占썲스占쏙옙치 占쏙옙占?
// EXTERN U16 gu16_SmartCheck_Result_FaucetDown_Reed;	// 占식울옙占? DOWN 占쏙옙占썲스占쏙옙치 占쏙옙占?
// EXTERN U16 gu16_SmartCheck_Result_MicroSW;			// 占쏙옙占쏙옙크占쏙옙 占쏙옙占쏙옙치 占쏙옙占?
/*******************************************/

EXTERN U8 F_SmartCheck_UpReed_Detected;  // 상승 리드스위치 감지 이력 플래그
EXTERN U8 gu8_F_Came_From_Wait_Tip_To_Level;      //@018  미감지 -> 최상단이동 -> 감지 할때 두번 왔다갓다 함.

EXTERN U8 gu8_F_Skip_First_ReedUndet_MoveUp;   // @025 부팅 후 설정레벨 도착 뒤 첫 이탈만 최상단 스킵
/*==============================================================================
 function Definition
 ==============================================================================*/
EXTERN void FaucetMoving_Initialize(void);

EXTERN void FaucetMoving_Control(void);
EXTERN void FaucetStepMotor_Control(void);

EXTERN void FaucetStepMotorMove(void);

EXTERN void FaucetControl_StepMove(U8 mu8OpenClose, U16 mu16Pulse);
EXTERN void FaucetStepMotor_Stop(void); 

EXTERN void FaucetStepMotor_ZeroBack_Open(void);
EXTERN void FaucetStepMotor_ZeroBack_Close(void);
//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================
