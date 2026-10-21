/// @file   watermeter.h
/// @date   2019.07.10
/// @author PSM
/// @brief  유량센서 처리 관련 헤더 file

#ifdef OPERATION_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_OPERATION()	{	/*	1ms 타이머 감산		*/	\
								}
#define	TDEC_10ms_OPERATION()	{	/*	10ms 타이머 감산		*/	\
								}
#define	TDEC_100ms_OPERATION()	{	/*	100ms 타이머 감산		*/	\
								}
#define	TDEC_1s_OPERATION()		{	/*	1s 타이머 감산			*/	\
									TDEC(gu16_TimerOper_1s);	\
								}
#define	TDEC_10s_OPERATION()	{	/*	10s 타이머 감산		*/	\
								}
#define	TDEC_1min_OPERATION()	{	/*	1min 타이머 감산		*/	\
								}
#define	TDEC_10min_OPERATION()	{	/*	10min 타이머 감산		*/	\
								}
#define	TDEC_1h_OPERATION()		{	/*	1h 타이머 감산			*/	\
								}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
enum {
	Z_OperationStepNum_00,
	Z_OperationStepNum_01,
	Z_OperationStepNum_02,
	Z_OperationStepNum_10,
	Z_OperationStepNum_D0,
	Z_OperationStepNum_Max
};

#define Z_OperationStep_00			(0x00)
#define Z_OperationStep_01			(0x01)
#define Z_OperationStep_02			(0x02)
#define Z_OperationStep_10			(0x10)
#define Z_OperationStep_D0			(0xD0)

#define Z_Timer100ms_Oper_1s		(10)
#define Z_Timer100ms_Oper_2s		(20)
#define Z_Timer100ms_Oper_3s		(30)
#define Z_Timer100ms_Oper_10s		(100)
#define Z_Timer1s_Oper_4min			(240)
#define Z_Timer1s_Oper_30s			(30)
#define Z_Timer1s_Oper_60s			(60)
#define Z_Timer1s_Oper_180s			(180)

#define CMD_BOOT				(0)
#define CMD_VER					(1)
#define CMD_COMM_ER				(2)
#define CMD_BY_MAIN				(3)
#define CMD_FOTA				(4)

/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN U8 gu8_OperationStepNum;

EXTERN U16 gu16_TimerOper_1s;						//	<?s/1s>

/*==============================================================================
 function Definition
 ==============================================================================*/
void Operation_Initialize(void);
void Operation(void);

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================
