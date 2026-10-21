/// @file     communication.c
/// @date     2021.01.12
/// @author   PSM
/// @brief    통신처리 file
/*==========================================================================*/
/*		PRAGMA						   			  							*/
/*==========================================================================*/
#pragma interrupt INTST2 IntUartTx					  	/*	Tx Interrupt	*/
#pragma interrupt INTSR2 IntUartRx					 	/* 	Rx Interrupt	*/

#define COMMUNICATION_C
#include "include/_include.h"

//=============================================================================
//		Macro 정의
//=============================================================================
#define SERIAL_RX2EN()			{SRIF2 = 0;				/*	Int Request Flag Register clear	*/\
								SRMK2 = 0;				/*	Int Mask Register clear			*/\
								SetIORBit(SS1L, 0x02);	/*	RX1 Start						*/}

#define SERIAL_TX2EN()			{STIF2 = 0;				/*	Int Request Flag Register clear	*/\
								STMK2 = 0;				/*	Int Mask Register clear			*/\
								SetIORBit(SOE1L, 0x01);	/*	Enables TX1 output Serial Set	*/\
								SetIORBit(SS1L, 0x01);	/*	TX1 Start						*/}

	U8 F_TraOnce = 0;

/// @brief    통신처리 초기화
/// @param    void
/// @return   void
void Communication_Initialize(void)
{
	SERIAL_TX2EN();									//		TX enable
	SERIAL_RX2EN();									//		RX enable
	gu8_TimerError_Time = Z_TimerError_Time; 		/*	Communication error 2sec timer set */
	gu8_TimerRecInt_Check = Z_TimerRecInt_Check;    //	Rec. interrupot 30ms check
	gu8_TimerDataReceive = Z_TimerDataReceive;		//	RX수신 에러 타이머 10초
}

/// @brief    통신처리 제어
/// @param    void
/// @return   void
void CommunicationControl(void)
{
	TXControl();									//	TX control
	RXControl();									//	RX control
}

/// @brief    통신 Rx 처리
/// @param    void
/// @return   void
__interrupt void IntUartRx(void)
{
	U8 recdata;
	U16 work;

	/****************************************************/
	gu8_TimerRecInt_Check = Z_TimerRecInt_Check;	//	30ms check

	if ((SSR11 & 0x0007) != 0)
	{ 												/*	Status register check */
		work = RXD2; 								/*	Buffer set data register */
		SIR11 = 0x0007; 							/*	error flag clr */
		gu8_CounterRXDError++;
		Uart_SFR_Refresh(); 						/*	SFR refresh */
		return;
	}

	work = RXD2; 									/*	Save RX data	 */
	recdata = (U8) (work & 0x00FF); 				/*	Set lower 8bit data  */

	UartReceive(recdata); 							/*	Receive process */
}

/// @brief    통신 Tx 처리
/// @param    void
/// @return   void
__interrupt void IntUartTx(void)
{
	U8 mu8_Test;

	/************************************************/
	if ((SSR10 & 0x0046) != 0x00)					//	Processing TX
	{
		gu8_CounterTXDError++;
		return;										//		return
	}

#ifndef _FRONT_COMMU_CHANGE_
	if (gu8_CounterTraDataCount < Z_DataLen)		//	Incomplete TX
#else
	if (gu8_CounterTraDataCount < Z_DataLen_Tx)		//	Incomplete TX
#endif
	{
		TXD2 = gu8_Buffer_MCU_TraData[gu8_CounterTraDataCount].byte;     //		TX
		gu8_CounterTraDataCount++;					//		Increase counter
	}
	else
	{
		mu8_Test++;
		F_TraOnce = CLEAR;
	}
}

/// @brief    수신 처리
/// @param    void
/// @return   void
void UartReceive(U8 recdata)
{
	/****************************************************/
	if (f_Rec_End == 1)								//	Over than RX data length
	{
		f_Rec_End = 0;								//		RX complete flag set
		gu8_CounterRecvCount = 0;					//		Counter clear
		Uart_SFR_Refresh();							//		SFR refresh
		return;
	}
	gu8_Buffer_MCU_RecData[gu8_CounterRecvCount].byte = recdata;	//	Set data buffer

	gu8_CounterRecvCount++;							// 	Increase counter
#ifndef _FRONT_COMMU_CHANGE_
	if (gu8_CounterRecvCount > (Z_DataLen - 1))
#else
	if (gu8_CounterRecvCount > (Z_DataLen_Rx - 1))
#endif
	{												// 	End data length
		f_Rec_End = 1;								//		RX complete flag set
	}
}

/// @brief
/// @param    void
/// @return   void
void TXControl(void)
{
	U8 i;
	// U8 F_TraOnce = 0;

	#if 0
	if (F_CommunicationCMD == SET)
	{
		if ((gu8_TimerTraWait_Short == 0) && (f_Tra_Start == 0))
		{
			gu8_TimerTraWait_Short = Z_TimerTraWait_Short;
			F_TraOnce = SET;
			gu8_TimerTraWait = Z_TimerTraWait;				//		timer set
			F_CommunicationCMD = CLEAR;
		}
	}
	#endif

	if ((gu8_TimerTraWait == 0) && (F_TraOnce == CLEAR))
	{													//	TX data set flag
		F_Rx_Complete = 0;								//		수신완료 flag clr
		gu8_TimerTraWait = Z_TimerTraWait;				//		10ms timer set
#ifndef _FRONT_COMMU_CHANGE_
		for (i = 0 ; i < Z_DataLen ; i++)
#else
		for (i = 0 ; i < Z_DataLen_Tx ; i++)
#endif
		{												//		버퍼 클리어
			gu8_Buffer_MCU_TraData[i].byte = 0x00;		//			버퍼 초기화
		}

		Send_Data();									//		송신 data set

		gu8_CounterTraDataCount = 0;					//		TX counter clear
		f_Tra_DataMake = 0;								//		TX data set flag clear
		f_Tra_Start = 1;								//		TX start flag set
		gu8_TimerTrahalt = Z_TimerTrahalt;				//		TX timer 50ms set

		SERIAL_TX2EN();									//		TX enable

		TXD2 = gu8_Buffer_MCU_TraData[0].byte;			//		TX first data transmission
		gu8_CounterTraDataCount++;						//		Increase counter
	}

	#if 0
#ifndef _FRONT_COMMU_CHANGE_
	if ((gu8_CounterTraDataCount >= Z_DataLen) && ((SSR10 & 0x0040) != 0x0040))
#else
	if ((gu8_CounterTraDataCount >= Z_DataLen_Tx) && ((SSR10 & 0x0040) != 0x0040))
#endif
	{
//		SERIAL_TX2DIS();								//		TX disable
		f_Tra_Start = 0;								//		Clear start flag
	}
	#endif

	#if 0
	if ((f_Tra_Start == 1) && (gu8_TimerTrahalt == 0))
	{       											//	TX processing & TX error
		gu8_CounterTraDataCount = 0;					//		Counter clear
		gu8_Buffer_TraCrc = 0;							//		CRC buffer clear
		f_Tra_Start = 0;								//		Clear start flag
		gu8_TimerTrahalt = Z_TimerTrahalt;				//		TX timer 50ms set
		gu8_TimerTraWait = Z_TimerTraWait;				//		TX error timer set
		Uart_SFR_Refresh();								//		SFR refresh
	}
	#endif
}

/// @brief
/// @param    void
/// @return   void
void RXControl(void)
{
	U8 result;
	U8 work;
	U8 i;

	if ((gu8_CounterRecvCount >= 1) && (gu8_TimerRecInt_Check == 0))	//	수신 중 RX interrupt 30ms check
	{
		gu8_CounterRecvCount = 0;						//		Count clear
		gu8_TimerRecInt_Check = Z_TimerRecInt_Check;	//		Rec. interrupot 30ms check
	}

	if (f_Rec_End == 1)									//	Complete RX
	{
		f_Rec_End = 0;									//		RX complete flag clear
		gu8_CounterRecvCount = 0;						//		Counter clear
		gu8_Buffer_RecCrc = 0;							//		CRC buffer clear
//		SERIAL_RX2DIS();								//		RX disable

#ifndef _FRONT_COMMU_CHANGE_
		for (i = 0 ; i < (Z_DataLen - 2) ; i++)			//		CRC calculation (D1~D14)
#else
		for (i = 0 ; i < (Z_DataLen_Rx - 2) ; i++)			//		CRC calculation (D1~D14)
#endif
		{
			work = (U8) (((U16) (gu8_Buffer_RecCrc >> 8) ^ gu8_Buffer_MCU_RecData[i].byte) & 0x00ffU);
			gu8_Buffer_RecCrc = (gu8_Buffer_RecCrc << 8) ^ crc_table1[work];    //			CRC buffer set
		}

		result = Crc_Check();							//		CRC check

		if (result == 1)
		{												// 		CRC OK
			F_Rx_Complete = 1;
			Data_Parsing(); 							//			RX data parsing
			gu8_TimerDataReceive = Z_TimerDataReceive;	//			RX수신 에러 타이머 10초
			F_Rx_Exp = 1;								//			수신 경험
			gu8_CounterRXDError = 0;
			F_Front_Communication_Error = CLEAR;
			gu8_TimerError_Time = Z_TimerError_Time;	//		RX error timer set
		}
		else
		{												//		CRC NG
			Uart_SFR_Refresh();							//			SFR refresh
		}
	}

	if (gu8_TimerError_Time == 0)						//	RX 2s error
	{
		gu8_Key_Short.byte = 0x00;						//		Key data clear
		gu8_DigitalInput_Key1.Level.byte = 0x00;        //		Key data clear
		gu8_DigitalInput_Key1.First = 0x00;             //      Key data clear
		gu8_DigitalInput_Key1.OffEdge.byte = 0x00;      //      Key data clear
		gu8_DigitalInput_Key1.OnEdge.byte = 0x00;       //      Key data clear
//		gu8_DigitalInput_Key2.Level.byte = 0x00;        //      Key data clear
//		gu8_DigitalInput_Key2.First = 0x00;             //      Key data clear
//		gu8_DigitalInput_Key2.OffEdge.byte = 0x00;      //      Key data clear
//		gu8_DigitalInput_Key2.OnEdge.byte = 0x00;       //      Key data clear
		gu8_CounterRecvCount = 0;						//		Counter clear
		Uart_SFR_Refresh();								//		SFR refresh

		gu8_CounterRXDError++;
		gu8_TimerError_Time = Z_TimerError_Time;		//		RX error timer set
	}

	if (gu8_CounterRXDError >= 5)						//	수신 타이머 경과 5회 이상인 경우
	{
		gu8_CounterRXDError = 5;						//		5회 고정

		if(gu8_TimerPBATest_Join != 0)					//	테스트 모드 시간에만 에러 확정..
		{
			F_Front_Communication_Error = SET;				//		에러 플래그 set
		}
	}
}

/// @brief
/// @param    void
/// @return   void
U8 Crc_Check(void)
{
	U16 work1, work2;
	U8 ret;

	//******	CRC buffer set		******//
#ifndef _FRONT_COMMU_CHANGE_
	work1 = ((U16) gu8_Buffer_MCU_RecData[Z_DataLen - 2].byte & 0x00FF);
	work2 = ((U16) gu8_Buffer_MCU_RecData[Z_DataLen - 1].byte & 0x00FF) << 8;
#else
	work1 = ((U16) gu8_Buffer_MCU_RecData[Z_DataLen_Rx - 2].byte & 0x00FF);
	work2 = ((U16) gu8_Buffer_MCU_RecData[Z_DataLen_Rx - 1].byte & 0x00FF) << 8;
#endif

	if (gu8_Buffer_RecCrc == (work1 | work2))
	{												//	CRC OK
		ret = 1;
	}
	else
	{												//	CRC NG
		ret = 0;
	}
	return (ret);
}

/// @brief
/// @param    void
/// @return   void
void Data_Parsing(void)
{
	U8 mu8_voice = 0;

	gu8_Front_OperationStep = gu8_Buffer_MCU_RecData[3].byte;

	KEY_HOTWATER_SHORT = gu8_Buffer_MCU_RecData[5].Bit.b0;
	KEY_PUREWATER_SHORT = gu8_Buffer_MCU_RecData[5].Bit.b1;
	KEY_COLDWATER_SHORT = gu8_Buffer_MCU_RecData[5].Bit.b2;
	KEY_AMOUNT_SHORT = gu8_Buffer_MCU_RecData[5].Bit.b3;
	KEY_EFFLUENT_SHORT = gu8_Buffer_MCU_RecData[5].Bit.b4;

	OneMatchModule(&gu8_DigitalInput_Key1, gu8_Buffer_MCU_RecData[6].byte);


	mu8_voice = gu8_Buffer_MCU_RecData[7].byte;

	if( F_PlayVoice == SET && gu8_play == SET )
    {
        if( mu8_voice == CLEAR )
        {
            F_PlayVoice = CLEAR;
            gu8_play = CLEAR;
        }
        else{}
    }
    else{}


#ifdef _FRONT_COMMU_CHANGE_
	gu16_Front_ProgramVer = (U16)gu8_Buffer_MCU_RecData[10].byte;
	gu16_Front_ProgramVer |= (U16)(gu8_Buffer_MCU_RecData[11].byte << 8);
#else
	gu16_Front_ProgramVer = (U16)gu8_Buffer_MCU_RecData[38].byte;
	gu16_Front_ProgramVer |= (U16)(gu8_Buffer_MCU_RecData[39].byte << 8);
#endif

//	gu8_CommuPacketType = Z_Commu_NormalData;
}

/// @brief
/// @param    void
/// @return   void
void Send_Data(void)
{
	/************************************************/
	U8 mu8_test = 0;

	gu8_Buffer_TraCrc = 0;										//	CRC clear

	gu8_Buffer_MCU_TraData[0].byte = Z_STX;						//	STX
	gu8_Buffer_MCU_TraData[1].byte = Z_Main_Address;			//	메인 Address
	gu8_Buffer_MCU_TraData[2].byte = Z_NormalData;				//	통상데이터
	gu8_Buffer_MCU_TraData[3].byte = gu8_OperationStep;			//	운전상태

	gu8_Buffer_MCU_TraData[4].byte = DisplayControl_Data[Z_SEGMENT].Display_CMD;
	gu8_Buffer_MCU_TraData[5].byte = SEG_OXX;
	gu8_Buffer_MCU_TraData[6].byte = SEG_XOX;
	gu8_Buffer_MCU_TraData[7].byte = SEG_XXO;

	gu8_Buffer_MCU_TraData[8].byte = DisplayControl_Data[Z_LED_EFFLUENT].Display_CMD;
	gu8_Buffer_MCU_TraData[9].byte = DisplayControl_Data[Z_LED_mL].Display_CMD;
	gu8_Buffer_MCU_TraData[10].byte = DisplayControl_Data[Z_LED_FILTER_CHANGE].Display_CMD;
	gu8_Buffer_MCU_TraData[11].byte = DisplayControl_Data[Z_LED_FAUCET].Display_CMD;
	gu8_Buffer_MCU_TraData[12].byte = DisplayControl_Data[Z_LED_CON].Display_CMD;
	gu8_Buffer_MCU_TraData[13].byte = DisplayControl_Data[Z_LED_1BOTTLE].Display_CMD;
	gu8_Buffer_MCU_TraData[14].byte = DisplayControl_Data[Z_LED_2CUP].Display_CMD;
	gu8_Buffer_MCU_TraData[15].byte = DisplayControl_Data[Z_LED_1CUP].Display_CMD;
	gu8_Buffer_MCU_TraData[16].byte = DisplayControl_Data[Z_LED_HALFCUP].Display_CMD;
	gu8_Buffer_MCU_TraData[17].byte = DisplayControl_Data[Z_LED_DEGREE].Display_CMD;
	gu8_Buffer_MCU_TraData[18].byte = DisplayControl_Data[Z_LED_AMOUNT].Display_CMD;
	gu8_Buffer_MCU_TraData[19].byte = DisplayControl_Data[Z_LED_COLD_BLUE].Display_CMD;
	gu8_Buffer_MCU_TraData[20].byte = DisplayControl_Data[Z_LED_COLD_WHITE].Display_CMD;
	gu8_Buffer_MCU_TraData[21].byte = DisplayControl_Data[Z_LED_COLD].Display_CMD;
	gu8_Buffer_MCU_TraData[22].byte = DisplayControl_Data[Z_LED_PURE].Display_CMD;
	gu8_Buffer_MCU_TraData[23].byte = DisplayControl_Data[Z_LED_HOT].Display_CMD;
	gu8_Buffer_MCU_TraData[24].byte = DisplayControl_Data[Z_LED_HOTLOCK].Display_CMD;
	gu8_Buffer_MCU_TraData[25].byte = DisplayControl_Data[Z_LED_WIFI].Display_CMD;
	gu8_Buffer_MCU_TraData[26].byte = DisplayControl_Data[Z_LED_UV1].Display_CMD;
	gu8_Buffer_MCU_TraData[27].byte = DisplayControl_Data[Z_LED_UV2].Display_CMD;
	gu8_Buffer_MCU_TraData[28].byte = DisplayControl_Data[Z_LED_UV3].Display_CMD;
	gu8_Buffer_MCU_TraData[29].byte = DisplayControl_Data[Z_LED_UV4].Display_CMD;
	gu8_Buffer_MCU_TraData[30].byte = DisplayControl_Data[Z_LED_UV5].Display_CMD;
	gu8_Buffer_MCU_TraData[31].byte = DisplayControl_Data[Z_LED_UV6].Display_CMD;
	gu8_Buffer_MCU_TraData[32].byte = DisplayControl_Data[Z_LED_UV7].Display_CMD;
	gu8_Buffer_MCU_TraData[33].byte = DisplayControl_Data[Z_LED_UV8].Display_CMD;
	gu8_Buffer_MCU_TraData[34].byte = DisplayControl_Data[Z_LED_UV9].Display_CMD;	
	gu8_Buffer_MCU_TraData[35].byte = DisplayControl_Data[Z_LED_HOT_BAR_5].Display_CMD;
	gu8_Buffer_MCU_TraData[36].byte = DisplayControl_Data[Z_LED_HOT_BAR_4].Display_CMD;
	gu8_Buffer_MCU_TraData[37].byte = DisplayControl_Data[Z_LED_HOT_BAR_3].Display_CMD;
	gu8_Buffer_MCU_TraData[38].byte = DisplayControl_Data[Z_LED_HOT_BAR_2].Display_CMD;
	gu8_Buffer_MCU_TraData[39].byte = DisplayControl_Data[Z_LED_HOT_BAR_1].Display_CMD;
	gu8_Buffer_MCU_TraData[40].byte = DisplayControl_Data[Z_LED_PERCENT].Display_CMD;

	//	음성	
	if(F_PlayVoice == SET)
	{
		gu8_play = SET;
	}

	gu8_Buffer_MCU_TraData[41].byte = gu8_play;

	gu8_Buffer_MCU_TraData[42].byte = (U8)(gu16_Voice_Address & 0x00FF);
	gu8_Buffer_MCU_TraData[43].byte = (U8)((gu16_Voice_Address >> 8) & 0xFF);

	if (IsCriticalVoice(gu16_Voice_Address) == TRUE)
	{
		gu8_Buffer_MCU_TraData[44].byte = 4;
	}
	else
	{
		gu8_Buffer_MCU_TraData[44].byte = (U8)(gu8_VoiceVolumeLevel & 0xFF);	
	}

	gu8_Buffer_MCU_TraData[45].byte = F_FOTA_Display;

	gu8_Buffer_MCU_TraData[46].byte = gu8_Fade_Select;
	gu8_Buffer_MCU_TraData[47].byte = gu8_ON_DimmingPercent;
	gu8_Buffer_MCU_TraData[48].byte = gu8_DimmingPercent;
	gu8_Buffer_MCU_TraData[49].byte = gu8_DimmingPercent_Low;

	gu8_Buffer_MCU_TraData[50].byte = (U8)(PROGRAM_VERSION_NO & 0xFFU);
	gu8_Buffer_MCU_TraData[51].byte = (U8)((PROGRAM_VERSION_NO >> 8) & 0xFFU);

	gu8_Buffer_MCU_TraData[52].byte = Z_ETX;
	TraCrcCheck();										//	Data CRC calculation
	gu8_Buffer_MCU_TraData[53].byte = (U8) (gu8_Buffer_TraCrc & 0x00FFU);				//	CRC1 set
	gu8_Buffer_MCU_TraData[54].byte = (U8) ((gu8_Buffer_TraCrc & 0xFF00U) >> 8);

	f_Tra_DataMake = 1;									//	Complete TX data set
}

/// @brief
/// @param    void
/// @return   void
void TraCrcCheck(void)
{
	U16 i;
	U16 work;
	//******	CRC data set (D1-D14)	******//
#ifndef _FRONT_COMMU_CHANGE_
	for (i = 0 ; i < (Z_DataLen - 2) ; i++)
#else
	for (i = 0 ; i < (Z_DataLen_Tx - 2) ; i++)
#endif
	{			//	CRC데이터 계산
		work = ((U16) (gu8_Buffer_TraCrc >> 8) ^ gu8_Buffer_MCU_TraData[i].byte) & 0x00ffU;
		gu8_Buffer_TraCrc = (gu8_Buffer_TraCrc << 8) ^ crc_table1[work];
	}
}

/// @brief
/// @param    void
/// @return   void
void Uart_SFR_Refresh(void)
{
	U8 work;
	/****************************************************/
	R_UART2_Stop();
	R_UART2_Create();
	R_UART2_Start();

	SERIAL_TX2EN();									//		TX enable
	SERIAL_RX2EN();									//		RX enable
}
