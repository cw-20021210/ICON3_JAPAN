/// @file   keycontrol.h
/// @date   2019.07.10
/// @author PSM
/// @brief  키 입력 처리 관련 헤더 file

#ifdef KEYCONTROL_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_KEYCONTROL()	{	/*	1ms 타이머 감산			*/	\
									TDEC(gu8_TimerEffluentKey);	\
									TDEC(gu8_TimerKeyProhibit);	\
								}
#define	TDEC_10ms_KEYCONTROL()	{	/*	10ms 타이머 감산		*/	\
									TDEC(gu16_TimerKeyDecide);	\
								}
#define	TDEC_100ms_KEYCONTROL()	{	/*	100ms 타이머 감산		*/	\
									TDEC(gu8_TimerKeyOnBreak);	\
								}
#define	TDEC_1s_KEYCONTROL()	{	/*	1s 타이머 감산			*/	\
								}
#define	TDEC_10s_KEYCONTROL()	{	/*	10s 타이머 감산		*/	\
								}
#define	TDEC_1min_KEYCONTROL()	{	/*	1min 타이머 감산		*/	\
								}
#define	TDEC_10min_KEYCONTROL()	{	/*	10min 타이머 감산		*/	\
								}
#define	TDEC_1h_KEYCONTROL()	{	/*	1h 타이머 감산			*/	\
								}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
#define Z_TimerKeyProhibit	(50)					//	<50ms/1ms>
#define Z_TimerEffluentKey	(50)					//	<50ms/1ms>

/*==============================================================================
 Variable Definition
 ==============================================================================*/
 EXTERN U8 gu8_KeyControlStep;						//	Key 제어 스텝

EXTERN WORD_BIT gu16_ShortKeyArray;					//	단키 확정
	#define KEY_HOTWATER_SHORT			(gu16_ShortKeyArray.BIT.b0)
	#define KEY_COLDWATER_SHORT			(gu16_ShortKeyArray.BIT.b1)
	#define KEY_PUREWATER_SHORT			(gu16_ShortKeyArray.BIT.b2)
	#define KEY_AMOUNT_SHORT			(gu16_ShortKeyArray.BIT.b3)
	#define KEY_EFFLUENT_SHORT			(gu16_ShortKeyArray.BIT.b4)
//	#define KEY_SILENT_SHORT			(gu16_ShortKeyArray.BIT.b6)
//	#define KEY_FRONT_TEST_SHORT		(gu16_ShortKeyArray.BIT.b7)
//	#define KEY_NORMAL_TEST_SHORT		(gu16_ShortKeyArray.BIT.b8)
//	#define KEY_PBA_TEST_SHORT			(gu16_ShortKeyArray.BIT.b9)
//	#define KEY_EEPROM_CLEAR_SHORT		(gu16_ShortKeyArray.BIT.b10)
//	#define KEY_ERROR_HISTORY_SHORT		(gu16_ShortKeyArray.BIT.b11)
//	#define KEY_ERROR_HIS_CLEAR_SHORT	(gu16_ShortKeyArray.BIT.b12)
//	#define KEY_ALTITUDE_MODE_SHORT		(gu16_ShortKeyArray.BIT.b13)
//	#define KEY_HOTTANK_CLEAR_SHORT		(gu16_ShortKeyArray.BIT.b14)

//EXTERN WORD_BIT gu16_LongKeyArray;					//	롱키 확정
//	#define KEY_HOTWATER_LONG			(gu16_LongKeyArray.BIT.b0)
//	#define KEY_COLDWATER_LONG			(gu16_LongKeyArray.BIT.b1)
//	#define KEY_PUREWATER_LONG			(gu16_LongKeyArray.BIT.b2)
//	#define KEY_AMOUNT_LONG				(gu16_LongKeyArray.BIT.b3)
//	#define KEY_HOTLOCK_LONG			(gu16_LongKeyArray.BIT.b4)
//	#define KEY_ECONOMY_LONG			(gu16_LongKeyArray.BIT.b5)
//	#define KEY_SILENT_LONG				(gu16_LongKeyArray.BIT.b6)
//	#define KEY_FRONT_TEST_LONG			(gu16_LongKeyArray.BIT.b7)
//	#define KEY_NORMAL_TEST_LONG		(gu16_LongKeyArray.BIT.b8)
//	#define KEY_PBA_TEST_LONG			(gu16_LongKeyArray.BIT.b9)
//	#define KEY_EEPROM_CLEAR_LONG		(gu16_LongKeyArray.BIT.b10)
//	#define KEY_ERROR_HISTORY_LONG		(gu16_LongKeyArray.BIT.b11)
//	#define KEY_ERROR_HIS_CLEAR_LONG	(gu16_LongKeyArray.BIT.b12)
//	#define KEY_ALTITUDE_MODE_LONG		(gu16_LongKeyArray.BIT.b13)
//	#define KEY_HOTTANK_CLEAR_LONG		(gu16_LongKeyArray.BIT.b14)
//
//EXTERN WORD_BIT gu16_VeryLongKeyArray;				//	베리롱키 확정
////	#define KEY_HOTWATER_VERYLONG			(gu16_VeryLongKeyArray.BIT.b0)
////	#define KEY_COLDWATER_VERYLONG			(gu16_VeryLongKeyArray.BIT.b1)
////	#define KEY_PUREWATER_VERYLONG			(gu16_VeryLongKeyArray.BIT.b2)
////	#define KEY_AMOUNT_VERYLONG				(gu16_VeryLongKeyArray.BIT.b3)
////	#define KEY_HOTLOCK_VERYLONG			(gu16_VeryLongKeyArray.BIT.b4)
////	#define KEY_ECONOMY_VERYLONG			(gu16_VeryLongKeyArray.BIT.b5)
////	#define KEY_SILENT_VERYLONG				(gu16_VeryLongKeyArray.BIT.b6)
////	#define KEY_FRONT_TEST_VERYLONG			(gu16_VeryLongKeyArray.BIT.b7)
////	#define KEY_NORMAL_TEST_VERYLONG		(gu16_VeryLongKeyArray.BIT.b8)
////	#define KEY_PBA_TEST_VERYLONG			(gu16_VeryLongKeyArray.BIT.b9)
////	#define KEY_EEPROM_CLEAR_VERYLONG		(gu16_VeryLongKeyArray.BIT.b10)
////	#define KEY_ERROR_HISTORY_VERYLONG		(gu16_VeryLongKeyArray.BIT.b11)
////	#define KEY_ERROR_HIS_CLEAR_VERYLONG	(gu16_VeryLongKeyArray.BIT.b12)
////	#define KEY_ALTITUDE_MODE_VERYLONG		(gu16_VeryLongKeyArray.BIT.b13)
////	#define KEY_HOTTANK_CLEAR_VERYLONG		(gu16_VeryLongKeyArray.BIT.b14)
//
//EXTERN WORD_BIT gu16_FCTLongKeyArray;				//	테스트모드 롱키 확정
////	#define KEY_HOTWATER_FCTLONG			(gu16_FCTLongKeyArray.BIT.b0)
////	#define KEY_COLDWATER_FCTLONG			(gu16_FCTLongKeyArray.BIT.b1)
////	#define KEY_PUREWATER_FCTLONG			(gu16_FCTLongKeyArray.BIT.b2)
////	#define KEY_AMOUNT_FCTLONG				(gu16_FCTLongKeyArray.BIT.b3)
////	#define KEY_HOTLOCK_FCTLONG				(gu16_FCTLongKeyArray.BIT.b4)
////	#define KEY_ECONOMY_FCTLONG				(gu16_FCTLongKeyArray.BIT.b5)
////	#define KEY_SILENT_FCTLONG				(gu16_FCTLongKeyArray.BIT.b6)
////	#define KEY_FRONT_TEST_FCTLONG			(gu16_FCTLongKeyArray.BIT.b7)
////	#define KEY_NORMAL_TEST_FCTLONG			(gu16_FCTLongKeyArray.BIT.b8)
////	#define KEY_PBA_TEST_FCTLONG			(gu16_FCTLongKeyArray.BIT.b9)
////	#define KEY_EEPROM_CLEAR_FCTLONG		(gu16_FCTLongKeyArray.BIT.b10)
////	#define KEY_ERROR_HISTORY_FCTLONG		(gu16_FCTLongKeyArray.BIT.b11)
////	#define KEY_ERROR_HIS_CLEAR_FCTLONG		(gu16_FCTLongKeyArray.BIT.b12)
////	#define KEY_ALTITUDE_MODE_FCTLONG		(gu16_FCTLongKeyArray.BIT.b13)
////	#define KEY_HOTTANK_CLEAR_FCTLONG		(gu16_FCTLongKeyArray.BIT.b14)
EXTERN U16 gu16_TimerKeyDecide;						//	키 확정 타이머
EXTERN U8 gu8_TimerKeyProhibit;						//	키 입력 금지 타이머
//EXTERN U8 gu8_EffluentKey_OnBreak;
EXTERN U8 gu8_TimerKeyOnBreak;						//	키 온고장 확정 타이머
EXTERN U8 F_VeryLongKey_Rejection;					//	Long key가 Active하고 Very Long key가 한번 더 동작되는 것을 방지하는 플래그
EXTERN U8 F_ShortKeyProhibit;						//	단키 중복
EXTERN U8 gu8_TimerEffluentKey;						//	<?ms/1ms>

/*==============================================================================
 function Definition
 ==============================================================================*/
void KeyControl_Initialize(void);
void KeyControl(void);
void KeyDecide(ITTI3* p);
void EffluentKey_Decide(void);
void Delay_Nop(U8 mu8_count);
void SegAllOff(void);
void ComAllOff(void);
void SegDataClear(void);

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================

