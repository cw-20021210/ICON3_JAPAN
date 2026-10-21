/// @file   input.h
/// @date   2019.07.10
/// @author PSM
/// @brief  ?…? ¥ ì²˜ë¦¬ file

#ifdef INPUT_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_INPUT()		{	/*	1ms ????´ë¨? ê°ì‚°			*/	\
								}
#define	TDEC_10ms_INPUT()		{	/*	10ms ????´ë¨? ê°ì‚°		*/	\
								}
#define	TDEC_100ms_INPUT()		{	/*	100ms ????´ë¨? ê°ì‚°		*/	\
									TDEC(gu8_Timer_InputMicroSW_ForcedFaucetUp);	\
									TDEC(gu8_Timer_FaucetTip_Reed_Undetected);	\
									TDEC(gu8_Timer_FaucetTip_Reed_Detected);	\
									TDEC(gu8_Timer_MicroSW_Release_Check);	\
								}
#define	TDEC_1s_INPUT()			{	/*	1s ????´ë¨? ê°ì‚°			*/	\
									TDEC(gu16_Timer_MicroSW_LongDetection);	\
								}
#define	TDEC_10s_INPUT()		{	/*	10s ????´ë¨? ê°ì‚°			*/	\
								}
#define	TDEC_1min_INPUT()		{	/*	1min ????´ë¨? ê°ì‚°		*/	\
								}
#define	TDEC_10min_INPUT()		{	/*	10min ????´ë¨? ê°ì‚°		*/	\
								}
#define	TDEC_1h_INPUT()			{	/*	1h ????´ë¨? ê°ì‚°			*/	\
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
	#define INPUT_MODEL_NATIONAL		(gu8_DigitalInput.Level.Bit.b3)			//	?„?‹œ...
	#define INPUT_MICRO_SW_FAUCET		(gu8_DigitalInput.Level.Bit.b4)
	#define INPUT_REED_SW_FAUCET_UP		(gu8_DigitalInput.Level.Bit.b5)
	#define INPUT_REED_SW_FAUCET_DOWN   (gu8_DigitalInput.Level.Bit.b6)


EXTERN U8 INPUT_REED_SW_COVER_Before;
EXTERN U8 INPUT_REED_SW_FILTER_Before;
EXTERN U8 INPUT_REED_SW_FAUCET_Before;

EXTERN U8 gu8_Timer_InputMicroSW_ForcedFaucetUp;
EXTERN U8 gu8_F_InputMicroSW_ForcedFaucetUp;
EXTERN U8 gu8_F_FirstInputMicroSW_ForcedFaucetUp;		//@001

// ?Œ ë¦¬ë“œ?Š¤?œ„ì¹? ë¯¸ê°ì§? ê´?? ¨ ë³??ˆ˜
EXTERN U8 gu8_Timer_FaucetTip_Reed_Undetected;  // ?Œ ë¦¬ë“œ?Š¤?œ„ì¹? ë¯¸ê°ì§? ?™•?¸ ????´ë¨? (1ì´? = 10 * 100ms)
EXTERN U8 gu8_F_FaucetTip_Reed_Undetected;  // ?Œ ë¦¬ë“œ?Š¤?œ„ì¹? ë¯¸ê°ì§? ?”Œ?˜ê·?

// ?Œ ë¦¬ë“œ?Š¤?œ„ì¹? ê°ì?? ê´?? ¨ ë³??ˆ˜
EXTERN U8 gu8_Timer_FaucetTip_Reed_Detected;  // ?Œ ë¦¬ë“œ?Š¤?œ„ì¹? ê°ì?? ?™•?¸ ????´ë¨? (2ì´? = 20 * 100ms)
EXTERN U8 gu8_F_FaucetTip_Reed_Detected;  // ?Œ ë¦¬ë“œ?Š¤?œ„ì¹? ê°ì?? ?”Œ?˜ê·?

// ?ŒŒ?š°?…‹ ê°ì?? ?ƒ?ƒœ ì¶”ì  ë³??ˆ˜ (ê°ì?? -> ë¯¸ê°ì§? -> ê°ì?? ?Œ¨?„´ ê°ì???š©)
EXTERN U8 gu8_F_Faucet_Detected_Before;  // ?´? „ ?ŒŒ?š°?…‹ ê°ì?? ?ƒ?ƒœ
EXTERN U8 gu8_F_Faucet_Was_Undetected;  // ?ŒŒ?š°?…‹?´ ë¯¸ê°ì§? ?ƒ?ƒœ????Š”ì§? ?”Œ?˜ê·?

// ¸¶ÀÌÅ©·Î ½ºÀ§Ä¡ 10ºĞ Áö¼Ó °¨Áö °ü·Ã º¯¼ö
EXTERN U16 gu16_Timer_MicroSW_LongDetection;        // 10ºĞ = 60000 (1ÃÊ ´ÜÀ§)
EXTERN U8 gu8_F_MicroSW_LongDetection_1h;        // 10ºĞ Áö¼Ó °¨Áö ÇÃ·¡±×
EXTERN U8 gu8_Timer_MicroSW_Release_Check;          // 2ÃÊ ÇØÁ¦ È®ÀÎ Å¸ÀÌ¸Ó (100ms ´ÜÀ§)


//	TEST ì½”ë“œ
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

