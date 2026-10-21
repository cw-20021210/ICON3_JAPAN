/// @file   watermeter.h
/// @date   2019.07.10
/// @author PSM
/// @brief  �������� ó�� ���� ���? file

#ifdef FLOWMETER_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_FLOWMETER()	{	/*	1ms Ÿ�̸� ����			*/	\
								}
#define	TDEC_10ms_FLOWMETER()	{	/*	10ms Ÿ�̸� ����		*/	\
									TDEC(gu8_Timer_FlowSafety);	\
								}
#define	TDEC_100ms_FLOWMETER()	{	/*	100ms Ÿ�̸� ����		*/	\
									TDEC(gu16_TimerEffluent);	\
								}
#define	TDEC_1s_FLOWMETER()		{	/*	1s Ÿ�̸� ����			*/	\
								}
#define	TDEC_10s_FLOWMETER()	{	/*	10s Ÿ�̸� ����			*/	\
								}
#define	TDEC_1min_FLOWMETER()	{	/*	1min Ÿ�̸� ����		*/	\
									TDEC(gu8_TimerColdEff_FirstCup);	\
								}
#define	TDEC_10min_FLOWMETER()	{	/*	10min Ÿ�̸� ����		*/	\
								}
#define	TDEC_1h_FLOWMETER()		{	/*	1h Ÿ�̸� ����			*/	\
								}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
#define Z_HOLESENSOR_NUM			(4)				//	8Pulse by 1Roatation (������ 4Pulse)


#define Z_FlowMeter_Revise			(90)			//(�ʱ��÷��� ���ⷮ �������� ����)	Ŀ������ �����? ������
#define Z_Effluent_VolumeBoost_Percent	(105)		//@039 Hz���� ml����(100=����). ǥ�ô� CupSize(120/250/500/1000) ����
#define Z_FlowMeter_Standard_KOR	(2165+Z_FlowMeter_Revise)		//	�ٺ�ġ �������� ���� 1LPM=46.5Hz => 1/46.5/60s
#define Z_FlowMeter_Standard_forHotWater_KOR	(2252+Z_FlowMeter_Revise)			//	�ٺ�ġ �������� ����	0.5LPM=22.5Hz => 0.5/22.5/60s. ������ �ٸ� �����Ͷ� �����Ͽ� 3703


#define Z_FlowMeter_Revise_JP		(30)			//	Ŀ������ �����? ������
//#define Z_FlowMeter_Revise_JP		(90)			//	Ŀ������ �����? ������
#define Z_FlowMeter_Standard_JP		(1984)			//	������ ����
#define Z_FlowMeter_Standard_forHotWater_JP	(2272)	//	������ ����

//#ifdef _FOR_JAPAN_90DEGREE_CONTINUE
//#define Z_FlowMeter_Standard_forHotWater_forJapan	(5568+Z_FlowMeter_Revise)			//
//#else
//#define Z_FlowMeter_Standard_forHotWater_forJapan	(4461+Z_FlowMeter_Revise)			//	�ٺ�ġ �������� ����	0.25=10.5Hz => 0.25/10.5/60s
//#endif
//#endif

//#define Z_TimerFlushing				(3000)			//	<5min/100ms>

#define Z_TimerColdEff_FirstCup		(30)			//	�ü� 30�� �ֱ� ù�� <30min/1min>

/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN volatile U8 F_FlowCheck;						//	�������? (Ÿ�̸� ���? ���?)
EXTERN U8 gu8_Timer_FlowSafety;						//	���� ����Ÿ�̸� (�����ð� �̻� ������ �� Ŭ���� ó��)
EXTERN volatile U16 gu16_FlowMeterTCR_Now;			//	TCR ����ġ
EXTERN U16 gu16_FlowMeterTCR_Before;				//	TCR ����ġ
EXTERN U32 gu32_FlowMeterTCR_Sum;					//	TCR �ջ� ������
EXTERN U8 gu8_Counter_FlowMeterTCR;					//	TCR ���� ī����
EXTERN U16 gu16_FlowMeterTCR_Array[Z_HOLESENSOR_NUM];		//	TCR ���� �迭
EXTERN U16 gu16_FlowDecide;							//	TCR ���?
EXTERN U16 gu16_Spec_FlowMeter;

EXTERN U8 gu8_TimerColdEff_FirstCup;				//	�ü� 30�� �ֱ� ù�� <30min/1min>

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

