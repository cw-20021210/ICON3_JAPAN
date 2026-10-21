/// @file   input.h
/// @date   2019.07.10
/// @author PSM
/// @brief  입력 처리 file

#ifdef INPUT_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_INPUT()		{	/*	1ms 타이머 감산			*/	\
								}
#define	TDEC_10ms_INPUT()		{	/*	10ms 타이머 감산		*/	\
									TDEC(gu8_Timer_ProhibitSW);	\
									TDEC(gu8_Timer_ShortSW);	\
								}
#define	TDEC_100ms_INPUT()		{	/*	100ms 타이머 감산		*/	\
									TDEC(gu8_Timer_LongSW);	\
								}
#define	TDEC_1s_INPUT()			{	/*	1s 타이머 감산			*/	\
								}
#define	TDEC_10s_INPUT()		{	/*	10s 타이머 감산			*/	\
								}
#define	TDEC_1min_INPUT()		{	/*	1min 타이머 감산		*/	\
								}
#define	TDEC_10min_INPUT()		{	/*	10min 타이머 감산		*/	\
								}
#define	TDEC_1h_INPUT()			{	/*	1h 타이머 감산			*/	\
								}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
//#define Z_Timer_LongSW		(30)
//#define Z_Timer_ShortSW		(10)

//#define Z_TimerKeyProhibit	(10)
/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN ITTI3 gu8_DigitalInput;						//	디지털 입력 데이터
	#define KEY_HOTWATER_LEVEL			(gu8_DigitalInput.Level.Bit.b0)
	#define KEY_HOTWATER_LOW_EDGE		(gu8_DigitalInput.OffEdge.Bit.b0)
	#define KEY_HOTWATER_HIGH_EDGE		(gu8_DigitalInput.OnEdge.Bit.b0)

	#define KEY_COLDWATER_LEVEL			(gu8_DigitalInput.Level.Bit.b1)
	#define KEY_COLDWATER_LOW_EDGE		(gu8_DigitalInput.OffEdge.Bit.b1)
	#define KEY_COLDWATER_HIGH_EDGE		(gu8_DigitalInput.OnEdge.Bit.b1)

	#define KEY_PUREWATER_LEVEL			(gu8_DigitalInput.Level.Bit.b2)
	#define KEY_PUREWATER_LOW_EDGE		(gu8_DigitalInput.OffEdge.Bit.b2)
	#define KEY_PUREWATER_HIGH_EDGE		(gu8_DigitalInput.OnEdge.Bit.b2)

	#define KEY_AMOUNT_LEVEL			(gu8_DigitalInput.Level.Bit.b3)
	#define KEY_AMOUNT_LOW_EDGE			(gu8_DigitalInput.OffEdge.Bit.b3)
	#define KEY_AMOUNT_HIGH_EDGE		(gu8_DigitalInput.OnEdge.Bit.b3)

EXTERN ITTI3 gu8_DigitalInput2;						//	디지털 입력 데이터
	#define MODEL_DECIDE				(gu8_DigitalInput2.Level.Bit.b0)

EXTERN ITTI3 gu8_DigitalInput3;						//	디지털 입력 데이터
	#define KEY_EFFLUENT_LEVEL			(gu8_DigitalInput3.Level.Bit.b0)
	#define KEY_EFFLUENT_LOW_EDGE		(gu8_DigitalInput3.OffEdge.Bit.b0)
	#define KEY_EFFLUENT_HIGH_EDGE		(gu8_DigitalInput3.OnEdge.Bit.b0)

EXTERN U8 gu8_Timer_LongSW;				//	<3s/100ms>
EXTERN U8 gu8_Timer_ShortSW;			//	<100ms/10ms>
EXTERN U8 gu8_Timer_ProhibitSW;			//	<200ms/10ms>

//EXTERN U8 F_SW_Long;
//EXTERN U8 F_SW_Short;

EXTERN U8 gu8_KeyOnBreak;

/*==============================================================================
 function Definition
 ==============================================================================*/
void Input_Initialize(void);
void InputControl(void);
void ThreeMatchModule(ITTI3* p, U8 data);

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================

