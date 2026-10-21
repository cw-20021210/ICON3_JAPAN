/// @file   watermeter.h
/// @date   2019.07.10
/// @author PSM
/// @brief  占쏙옙占쏙옙占쏙옙占쏙옙 처占쏙옙 占쏙옙占쏙옙 占쏙옙占? file

#ifdef FLOWMETER_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_FLOWMETER()	{	/*	1ms 타占싱몌옙 占쏙옙占쏙옙			*/	\
								}
#define	TDEC_10ms_FLOWMETER()	{	/*	10ms 타占싱몌옙 占쏙옙占쏙옙		*/	\
									TDEC(gu8_Timer_FlowSafety);	\
								}
#define	TDEC_100ms_FLOWMETER()	{	/*	100ms 타占싱몌옙 占쏙옙占쏙옙		*/	\
									TDEC(gu16_TimerEffluent);	\
								}
#define	TDEC_1s_FLOWMETER()		{	/*	1s 타占싱몌옙 占쏙옙占쏙옙			*/	\
								}
#define	TDEC_10s_FLOWMETER()	{	/*	10s 타占싱몌옙 占쏙옙占쏙옙			*/	\
								}
#define	TDEC_1min_FLOWMETER()	{	/*	1min 타占싱몌옙 占쏙옙占쏙옙		*/	\
									TDEC(gu8_TimerColdEff_FirstCup);	\
								}
#define	TDEC_10min_FLOWMETER()	{	/*	10min 타占싱몌옙 占쏙옙占쏙옙		*/	\
								}
#define	TDEC_1h_FLOWMETER()		{	/*	1h 타占싱몌옙 占쏙옙占쏙옙			*/	\
								}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
#define Z_HOLESENSOR_NUM			(4)				//	8Pulse by 1Roatation (占쏙옙占쏙옙占쏙옙 4Pulse)


#define Z_FlowMeter_Revise			(90)			//(占십깍옙占시뤄옙占쏙옙 占쏙옙占썩량 占쏙옙占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙)	커占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占? 占쏙옙占쏙옙占쏙옙
#define Z_Effluent_VolumeBoost_Percent	(105)		//@039 Hz종료 ml보정(100=없음). 표시는 CupSize(120/250/500/1000) 유지
#define Z_FlowMeter_Standard_KOR	(2165+Z_FlowMeter_Revise)		//	占쌕븝옙치 占쏙옙占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙 1LPM=46.5Hz => 1/46.5/60s
#define Z_FlowMeter_Standard_forHotWater_KOR	(2252+Z_FlowMeter_Revise)			//	占쌕븝옙치 占쏙옙占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙	0.5LPM=22.5Hz => 0.5/22.5/60s. 占쏙옙占쏙옙占쏙옙 占쌕몌옙 占쏙옙占쏙옙占싶띰옙 占쏙옙占쏙옙占싹울옙 3703


#define Z_FlowMeter_Revise_JP		(30)			//	커占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占? 占쏙옙占쏙옙占쏙옙
//#define Z_FlowMeter_Revise_JP		(90)			//	커占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占? 占쏙옙占쏙옙占쏙옙
#define Z_FlowMeter_Standard_JP		(1984)			//	占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙
#define Z_FlowMeter_Standard_forHotWater_JP	(2272)	//	占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙

//#ifdef _FOR_JAPAN_90DEGREE_CONTINUE
//#define Z_FlowMeter_Standard_forHotWater_forJapan	(5568+Z_FlowMeter_Revise)			//
//#else
//#define Z_FlowMeter_Standard_forHotWater_forJapan	(4461+Z_FlowMeter_Revise)			//	占쌕븝옙치 占쏙옙占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙	0.25=10.5Hz => 0.25/10.5/60s
//#endif
//#endif

//#define Z_TimerFlushing				(3000)			//	<5min/100ms>

#define Z_TimerColdEff_FirstCup		(30)			//	占시쇽옙 30占쏙옙 占쌍깍옙 첫占쏙옙 <30min/1min>

/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN volatile U8 F_FlowCheck;						//	占쏙옙占쏙옙占쏙옙占? (타占싱몌옙 占쏙옙占? 占쏙옙占?)
EXTERN U8 gu8_Timer_FlowSafety;						//	占쏙옙占쏙옙 占쏙옙占쏙옙타占싱몌옙 (占쏙옙占쏙옙占시곤옙 占싱삼옙 占쏙옙占쏙옙占쏙옙 占쏙옙 클占쏙옙占쏙옙 처占쏙옙)
EXTERN volatile U16 gu16_FlowMeterTCR_Now;			//	TCR 占쏙옙占쏙옙치
EXTERN U16 gu16_FlowMeterTCR_Before;				//	TCR 占쏙옙占쏙옙치
EXTERN U32 gu32_FlowMeterTCR_Sum;					//	TCR 占쌌삼옙 占쏙옙占쏙옙占쏙옙
EXTERN U8 gu8_Counter_FlowMeterTCR;					//	TCR 占쏙옙占쏙옙 카占쏙옙占쏙옙
EXTERN U16 gu16_FlowMeterTCR_Array[Z_HOLESENSOR_NUM];		//	TCR 占쏙옙占쏙옙 占썼열
EXTERN U16 gu16_FlowDecide;							//	TCR 占쏙옙占?
EXTERN U16 gu16_Spec_FlowMeter;

EXTERN U8 gu8_TimerColdEff_FirstCup;				//	占시쇽옙 30占쏙옙 占쌍깍옙 첫占쏙옙 <30min/1min>

EXTERN U8 gu8_FlowMeter_NumMax;


/*==============================================================================
 function Definition
 ==============================================================================*/
void FlowMeter_Initialize(void);
void FlowMeter_INT(void);
void FlowMeter_Decide(void);
void Effluent_Hz_Decide(void);
void FlowAmount_ForMonitor(void);

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================

