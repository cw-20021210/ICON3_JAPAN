/// @file   input.h
/// @date   2019.07.10
/// @author PSM
/// @brief  ?엯?젰 泥섎━ file

#ifdef INPUT_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_INPUT()		{	/*	1ms ????씠癒? 媛먯궛			*/	\
								}
#define	TDEC_10ms_INPUT()		{	/*	10ms ????씠癒? 媛먯궛		*/	\
								}
#define	TDEC_100ms_INPUT()		{	/*	100ms ????씠癒? 媛먯궛		*/	\
									TDEC(gu8_Timer_InputMicroSW_ForcedFaucetUp);	\
									TDEC(gu8_Timer_FaucetTip_Reed_Undetected);	\
									TDEC(gu8_Timer_FaucetTip_Reed_Detected);	\
									TDEC(gu8_Timer_MicroSW_Release_Check);	\
								}
#define	TDEC_1s_INPUT()			{	/*	1s ????씠癒? 媛먯궛			*/	\
									TDEC(gu16_Timer_MicroSW_LongDetection);	\
								}
#define	TDEC_10s_INPUT()		{	/*	10s ????씠癒? 媛먯궛			*/	\
								}
#define	TDEC_1min_INPUT()		{	/*	1min ????씠癒? 媛먯궛		*/	\
								}
#define	TDEC_10min_INPUT()		{	/*	10min ????씠癒? 媛먯궛		*/	\
								}
#define	TDEC_1h_INPUT()			{	/*	1h ????씠癒? 媛먯궛			*/	\
								}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
#define Z_TIMER_MICROSW_LONG_DETECTION		(6000)
#define Z_TIMER_MICROSW_RELEASE_CHECK		(20)

/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN ITTI3 gu8_DigitalInput;
	#define INPUT_REED_SW_COVER			(gu8_DigitalInput.Level.Bit.b0)
	#define INPUT_REED_SW_FILTER		(gu8_DigitalInput.Level.Bit.b1)
	#define INPUT_REED_SW_FAUCET		(gu8_DigitalInput.Level.Bit.b2)
	#define INPUT_MODEL_NATIONAL		(gu8_DigitalInput.Level.Bit.b3)			//	?엫?떆...
	#define INPUT_MICRO_SW_FAUCET		(gu8_DigitalInput.Level.Bit.b4)
	#define INPUT_REED_SW_FAUCET_UP		(gu8_DigitalInput.Level.Bit.b5)
	#define INPUT_REED_SW_FAUCET_DOWN   (gu8_DigitalInput.Level.Bit.b6)


EXTERN U8 INPUT_REED_SW_COVER_Before;
EXTERN U8 INPUT_REED_SW_FILTER_Before;
EXTERN U8 INPUT_REED_SW_FAUCET_Before;

EXTERN U8 gu8_Timer_InputMicroSW_ForcedFaucetUp;
EXTERN U8 gu8_F_InputMicroSW_ForcedFaucetUp;
EXTERN U8 gu8_F_FirstInputMicroSW_ForcedFaucetUp;		//@001

// ?똻 由щ뱶?뒪?쐞移? 誘멸컧吏? 愿??젴 蹂??닔
EXTERN U8 gu8_Timer_FaucetTip_Reed_Undetected;  // ?똻 由щ뱶?뒪?쐞移? 誘멸컧吏? ?솗?씤 ????씠癒? (1珥? = 10 * 100ms)
EXTERN U8 gu8_F_FaucetTip_Reed_Undetected;  // ?똻 由щ뱶?뒪?쐞移? 誘멸컧吏? ?뵆?옒洹?

// ?똻 由щ뱶?뒪?쐞移? 媛먯?? 愿??젴 蹂??닔
EXTERN U8 gu8_Timer_FaucetTip_Reed_Detected;  // ?똻 由щ뱶?뒪?쐞移? 媛먯?? ?솗?씤 ????씠癒? (2珥? = 20 * 100ms)
EXTERN U8 gu8_F_FaucetTip_Reed_Detected;  // ?똻 由щ뱶?뒪?쐞移? 媛먯?? ?뵆?옒洹?

// ?뙆?슦?뀑 媛먯?? ?긽?깭 異붿쟻 蹂??닔 (媛먯?? -> 誘멸컧吏? -> 媛먯?? ?뙣?꽩 媛먯???슜)
EXTERN U8 gu8_F_Faucet_Detected_Before;  // ?씠?쟾 ?뙆?슦?뀑 媛먯?? ?긽?깭
EXTERN U8 gu8_F_Faucet_Was_Undetected;  // ?뙆?슦?뀑?씠 誘멸컧吏? ?긽?깭????뒗吏? ?뵆?옒洹?

// 마이크로 스위치 10분 지속 감지 관련 변수
EXTERN U16 gu16_Timer_MicroSW_LongDetection;        // 10분 = 60000 (1초 단위)
EXTERN U8 gu8_F_MicroSW_LongDetection_1h;        // 10분 지속 감지 플래그
EXTERN U8 gu8_Timer_MicroSW_Release_Check;          // 2초 해제 확인 타이머 (100ms 단위)


//	TEST 肄붾뱶
EXTERN U8 gu8_F_Test_Input_ForcedControl;
EXTERN U8 INPUT_REED_SW_COVER_Test;
EXTERN U8 INPUT_REED_SW_FILTER_Test;
EXTERN U8 INPUT_REED_SW_WATERFLOW_Test;
/*==============================================================================
 function Definition
 ==============================================================================*/
void Input_Initialize(void);
void InputControl(void);
void Model_Decide(void);
void CP_CHP_Decide(void);

void OneMatchModule(ITTI1* p, U8 data);
void ThreeMatchModule(ITTI3* p, U8 data);

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================

