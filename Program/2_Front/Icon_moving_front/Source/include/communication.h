/// @file   communication.h
/// @date   2021.01.12
/// @author PSM
/// @brief  통신 처리 file

#ifdef COMMUNICATION_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_COMMUNICATION()	{	/*	1ms 타이머 감산		*/	\
										TDEC(gu16_TimerRecWait);		\
										TDEC(gu16_TimerTraWait);		\
										TDEC(gu8_TimerTrahalt);		\
										TDEC(gu8_TimerRecInt_Check);	\
									}
#define	TDEC_10ms_COMMUNICATION()	{	/*	10ms 타이머 감산		*/	\
										TDEC(gu8_TimerError_Time);		\
									}
#define	TDEC_100ms_COMMUNICATION()	{	/*	100ms 타이머 감산		*/	\
										TDEC(gu8_TimerTraWait_TimeShort);	\
									}
#define	TDEC_1s_COMMUNICATION()		{	/*	1s 타이머 감산			*/	\
									}
#define	TDEC_10s_COMMUNICATION()	{	/*	10s 타이머 감산		*/	\
									}
#define	TDEC_1min_COMMUNICATION()	{	/*	1min 타이머 감산		*/	\
									}
#define	TDEC_10min_COMMUNICATION()	{	/*	10min 타이머 감산		*/	\
									}
#define	TDEC_1h_COMMUNICATION()		{	/*	1h 타이머 감산			*/	\
									}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
//#define Z_DataLen				(43)				/* 	Packet data  */
#define Z_DataLen_Tx			(15)				/* 	Packet data  */
#define Z_DataLen_Rx			(55)				/* 	Packet data  */
#define Z_TimerError_Time		(200)				/* 	통신 미수신 에러 */
#define Z_TimerRecInt_Check		(30)				//	Rec. Interrupt 30ms check

#define Z_TimerRecWait			(20)				/* 	수신대기 Timer 20ms */
#define Z_TimerTraWait			(200)				/* 	송신대기 Timer ? ms */
#define Z_TimerTraWait_Short	(50)				/* 	송신대기 Timer ? ms */
#define Z_TimerTrahalt			(200)				//	Tx 정지체크 Timer 50ms

#define Z_STX					(0x02)
#define Z_ETX					(0x03)
#define Z_Front_Address			(0xF1)

#define Z_NormalData			(0x11)				//	통상 데이터

//#define Z_TimerTraWait_TimeShort	(50)				//	<5s/100ms>

/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN U8 gu8_TimerError_Time;							/* 	2초 미수신 타이머 */
EXTERN BYTE_BIT gu8_UartState;							//	통신상태 변수
	#define	f_Rec_End			(gu8_UartState.Bit.b1)	//	수신 끝
	#define	f_Rec_Start			(gu8_UartState.Bit.b2)	//	수신 시작
	#define	f_Tra_DataMake		(gu8_UartState.Bit.b3)	//	송신 데이터 생성
	#define	f_Tra_Start			(gu8_UartState.Bit.b4)	//	송신 시작

EXTERN U8 gu8_CounterRecvCount;							/* 	수신 데이터 길이 카운터	*/
EXTERN U8 gu8_CounterTraDataCount;						/* 	송신 데이터 카운터		*/
EXTERN U16 gu8_Buffer_RecCrc;							/* 	수신CRC DATA 		*/
EXTERN U16 gu8_Buffer_TraCrc;							/* 	송신CRC DATA 		*/
//EXTERN BYTE_BIT	gu8_Buffer_MCU_RecData[Z_DataLen+2];	/* 	수신 데이터 버퍼	*/
//EXTERN BYTE_BIT	gu8_Buffer_MCU_TraData[Z_DataLen+2];	/* 	송신 데이터 버퍼	*/
//EXTERN BYTE_BIT	gu8_Buffer_MCU_TraData_Backup[Z_DataLen];	/* 	송신 데이터 버퍼	*/
EXTERN BYTE_BIT	gu8_Buffer_MCU_RecData[Z_DataLen_Rx+2];	/* 	수신 데이터 버퍼	*/
EXTERN BYTE_BIT	gu8_Buffer_MCU_TraData[Z_DataLen_Tx+2];	/* 	송신 데이터 버퍼	*/
EXTERN BYTE_BIT	gu8_Buffer_MCU_TraData_Backup[Z_DataLen_Tx];	/* 	송신 데이터 버퍼	*/

EXTERN U8 gu8_ErrorHistory[5];
EXTERN U8 gu8_Ecode_ErrHistory;

EXTERN U16 gu16_TimerRecWait;							/* 	수신 대기 타이머	*/
EXTERN U16 gu16_TimerTraWait;							/* 	송신 대기 타이머	*/

EXTERN U8 gu8_TimerTraWait_TimeShort;					//	<?s/100ms> ※ 기존 300~500ms 할 경우, 단 키를 계속 눌르면 LEVEL이 clear되지 않아 메인에서 롱키를 확정함 그리하여 조작 중에는 시간을 빠르게 전송

EXTERN U8 gu8_TimerTrahalt;								//	Tx 체크
EXTERN U8 gu8_TimerRecInt_Check;						//	Rx 체크

EXTERN U8 gu8_CounterRXDError;
EXTERN U8 F_Communication_Error;
EXTERN U8 F_FirstCommunication;

EXTERN U8 gu8_Main_OperationStep;

EXTERN U8 gu8_Main_SEGMENT_CMD;
EXTERN U8 gu8_Main_SEGMENT_OXX;
EXTERN U8 gu8_Main_SEGMENT_XOX;
EXTERN U8 gu8_Main_SEGMENT_XXO;
EXTERN U8 gu8_Main_LED_EFFLUENT;
EXTERN U8 gu8_Main_LED_mL;
EXTERN U8 gu8_Main_LED_FILTER_CHANGE;
EXTERN U8 gu8_Main_LED_FAUCET;
EXTERN U8 gu8_Main_LED_CON;
EXTERN U8 gu8_Main_LED_1Bottle;
EXTERN U8 gu8_Main_LED_2CUP;
EXTERN U8 gu8_Main_LED_1CUP;
EXTERN U8 gu8_Main_LED_HALFCUP;
EXTERN U8 gu8_Main_LED_DEGREE;
EXTERN U8 gu8_Main_LED_AMOUNT;
EXTERN U8 gu8_Main_LED_COLD_BLUE;
EXTERN U8 gu8_Main_LED_COLD_WHITE;
EXTERN U8 gu8_Main_LED_COLD;
EXTERN U8 gu8_Main_LED_PURE;
EXTERN U8 gu8_Main_LED_HOT;
EXTERN U8 gu8_Main_LED_HOTLOCK;
EXTERN U8 gu8_Main_LED_WIFI;
EXTERN U8 gu8_Main_LED_UV1;
EXTERN U8 gu8_Main_LED_UV2;
EXTERN U8 gu8_Main_LED_UV3;
EXTERN U8 gu8_Main_LED_UV4;
EXTERN U8 gu8_Main_LED_UV5;
EXTERN U8 gu8_Main_LED_UV6;
EXTERN U8 gu8_Main_LED_UV7;
EXTERN U8 gu8_Main_LED_UV8;
EXTERN U8 gu8_Main_LED_UV9;
EXTERN U8 gu8_Main_Hot_TempBar_5;
EXTERN U8 gu8_Main_Hot_TempBar_4;
EXTERN U8 gu8_Main_Hot_TempBar_3;
EXTERN U8 gu8_Main_Hot_TempBar_2;
EXTERN U8 gu8_Main_Hot_TempBar_1;
EXTERN U8 gu8_Main_Percent;


EXTERN U16 gu16_Main_ProgramVer;

EXTERN U8 gu8_Main_Tx_Start;
EXTERN U8 gu8_F_MainTransmitting;


EXTERN U8 gu8_testttt;

//EXTERN U8 F_TestMode;

EXTERN U16 gu16_test_1111;
EXTERN U16 gu16_test_2222;
EXTERN U16 gu16_test_3333;
EXTERN U32 gu32_test_commu_count;
EXTERN U32 gu32_test_refresh_count;
EXTERN U16 gu16_test_ddd;
EXTERN U16 gu16_test_deed;
EXTERN U16 gu16_test_de;
EXTERN U32 gu32_test_comeeemu_count;
EXTERN U32 gu32_test_refreseah_count;
EXTERN U32 gu32_test_txcount;
EXTERN U32 gu32_test_rxcount;

EXTERN U32 gu32_test_tx_halt;
/*===========================================================================*/
/*		CRC TABLE						     								 */
/*===========================================================================*/
EXTERN const U16 crc_table1[256]
#ifdef	GLOBAL_VARIABLE_DEFINE
= {
	0x0000U,0x1021U,0x2042U,0x3063U,0x4084U,0x50a5U,0x60c6U,0x70e7U,
	0x8108U,0x9129U,0xa14aU,0xb16bU,0xc18cU,0xd1adU,0xe1ceU,0xf1efU,
	0x1231U,0x0210U,0x3273U,0x2252U,0x52b5U,0x4294U,0x72f7U,0x62d6U,
	0x9339U,0x8318U,0xb37bU,0xa35aU,0xd3bdU,0xc39cU,0xf3ffU,0xe3deU,
	0x2462U,0x3443U,0x0420U,0x1401U,0x64e6U,0x74c7U,0x44a4U,0x5485U,
	0xa56aU,0xb54bU,0x8528U,0x9509U,0xe5eeU,0xf5cfU,0xc5acU,0xd58dU,
	0x3653U,0x2672U,0x1611U,0x0630U,0x76d7U,0x66f6U,0x5695U,0x46b4U,
	0xb75bU,0xa77aU,0x9719U,0x8738U,0xf7dfU,0xe7feU,0xd79dU,0xc7bcU,
	0x48c4U,0x58e5U,0x6886U,0x78a7U,0x0840U,0x1861U,0x2802U,0x3823U,
	0xc9ccU,0xd9edU,0xe98eU,0xf9afU,0x8948U,0x9969U,0xa90aU,0xb92bU,
	0x5af5U,0x4ad4U,0x7ab7U,0x6a96U,0x1a71U,0x0a50U,0x3a33U,0x2a12U,
	0xdbfdU,0xcbdcU,0xfbbfU,0xeb9eU,0x9b79U,0x8b58U,0xbb3bU,0xab1aU,
	0x6ca6U,0x7c87U,0x4ce4U,0x5cc5U,0x2c22U,0x3c03U,0x0c60U,0x1c41U,
	0xedaeU,0xfd8fU,0xcdecU,0xddcdU,0xad2aU,0xbd0bU,0x8d68U,0x9d49U,
	0x7e97U,0x6eb6U,0x5ed5U,0x4ef4U,0x3e13U,0x2e32U,0x1e51U,0x0e70U,
	0xff9fU,0xefbeU,0xdfddU,0xcffcU,0xbf1bU,0xaf3aU,0x9f59U,0x8f78U,
	0x9188U,0x81a9U,0xb1caU,0xa1ebU,0xd10cU,0xc12dU,0xf14eU,0xe16fU,
	0x1080U,0x00a1U,0x30c2U,0x20e3U,0x5004U,0x4025U,0x7046U,0x6067U,
	0x83b9U,0x9398U,0xa3fbU,0xb3daU,0xc33dU,0xd31cU,0xe37fU,0xf35eU,
	0x02b1U,0x1290U,0x22f3U,0x32d2U,0x4235U,0x5214U,0x6277U,0x7256U,
	0xb5eaU,0xa5cbU,0x95a8U,0x8589U,0xf56eU,0xe54fU,0xd52cU,0xc50dU,
	0x34e2U,0x24c3U,0x14a0U,0x0481U,0x7466U,0x6447U,0x5424U,0x4405U,
	0xa7dbU,0xb7faU,0x8799U,0x97b8U,0xe75fU,0xf77eU,0xc71dU,0xd73cU,
	0x26d3U,0x36f2U,0x0691U,0x16b0U,0x6657U,0x7676U,0x4615U,0x5634U,
	0xd94cU,0xc96dU,0xf90eU,0xe92fU,0x99c8U,0x89e9U,0xb98aU,0xa9abU,
	0x5844U,0x4865U,0x7806U,0x6827U,0x18c0U,0x08e1U,0x3882U,0x28a3U,
	0xcb7dU,0xdb5cU,0xeb3fU,0xfb1eU,0x8bf9U,0x9bd8U,0xabbbU,0xbb9aU,
	0x4a75U,0x5a54U,0x6a37U,0x7a16U,0x0af1U,0x1ad0U,0x2ab3U,0x3a92U,
	0xfd2eU,0xed0fU,0xdd6cU,0xcd4dU,0xbdaaU,0xad8bU,0x9de8U,0x8dc9U,
	0x7c26U,0x6c07U,0x5c64U,0x4c45U,0x3ca2U,0x2c83U,0x1ce0U,0x0cc1U,
	0xef1fU,0xff3eU,0xcf5dU,0xdf7cU,0xaf9bU,0xbfbaU,0x8fd9U,0x9ff8U,
	0x6e17U,0x7e36U,0x4e55U,0x5e74U,0x2e93U,0x3eb2U,0x0ed1U,0x1ef0U
}
#endif
;

/*==============================================================================
 function Definition
 ==============================================================================*/
void Communication_Initialize(void);
void CommunicationControl(void);

void UartInitial(void);							//	통신초기화
void UartReceive(U8 recdata);					//	Rx처리 함수 (인터럽트 내)
void UartControl(void);							//	통신처리 함수
void TXControl(void);							//	Tx처리함수
void RXControl(void);							//	Rx처리함수
void TraCrcCheck(void);							//	Tx CRC 체크
void Data_Parsing(void);						//	수신데이터 분석
U8 Crc_Check(void);								//	CRC 체크
void SendData(void);							//	일반 송신데이터 생성
void Uart_SFR_Refresh(void);					//	통신관련 SFR refresh
void IntUartTx(void);							//	Tx interrupt
void IntUartRx(void);							//	Rx interrupt

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================
