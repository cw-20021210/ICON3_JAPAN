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

/// @brief    통신처리 초기화
/// @param    void
/// @return   void
void Communication_Initialize(void)
{
	SERIAL_TX2EN();									//	TX Enable
	SERIAL_RX2EN();									//	RX Enable
	gu8_TimerError_Time = Z_TimerError_Time; 		/*	Communication error 2sec timer set */
	gu8_TimerRecInt_Check = Z_TimerRecInt_Check;    //	Rec. interrupot 30ms check
}

/// @brief    통신처리 제어
/// @param    void
/// @return   void
void CommunicationControl(void)
{
	TXControl();									//	TX control
	RXControl();									//	RX control
}

/// @brief
/// @param    void
/// @return   void
__interrupt void IntUartRx(void)
{
	U8 recdata;
	U16 work;

	/****************************************************/
	gu8_TimerRecInt_Check = Z_TimerRecInt_Check;					//	30ms check

	if ((SSR11 & 0x0007) != 0)
	{ /*	Status register check */
		work = RXD2; /*	Buffer set data register */
		SIR11 = 0x0007; /*	error flag clr */
		Uart_SFR_Refresh(); /*	SFR refresh */
		gu32_test_refresh_count++;
		return;
	}

	work = RXD2; /*	Save RX data	 */
	recdata = (U8) (work & 0x00FF); /*	Set lower 8bit data  */

	UartReceive(recdata); /*	Receive process */
}

/// @brief
/// @param    void
/// @return   void
__interrupt void IntUartTx(void)
{
	/************************************************/
	if ((SSR10 & 0x0046) != 0x00)					//	Processing TX
	{
		return;										//		return
	}

	if (gu8_CounterTraDataCount < Z_DataLen_Tx)		//	Incomplete TX
	{
		TXD2 = gu8_Buffer_MCU_TraData[gu8_CounterTraDataCount].byte;    //		TX
		gu8_CounterTraDataCount++;					//		Increase counter
	}
	else
	{
		gu8_F_MainTransmitting = CLEAR;
	}
}

/// @brief
/// @param    void
/// @return   void
void UartReceive(U8 recdata)
{
	U8 mu8_test = 0;
	/****************************************************/
	if (f_Rec_End == 1)								//	Over than RX data length
	{
		f_Rec_End = 0;								//		RX complete flag set
		gu8_CounterRecvCount = 0;					//		Counter clear
		Uart_SFR_Refresh();							//		SFR refresh
		return;
	}

	if(gu8_CounterRecvCount == 0)
	{
		if(recdata != 0x02)
		{
			gu8_CounterRecvCount = 0;
			return;
		}
		else
		{
			mu8_test++;
		}
	}

	gu8_Buffer_MCU_RecData[gu8_CounterRecvCount].byte = recdata;     //	Set data buffer

	gu8_CounterRecvCount++;							// 	Increase counter
	if (gu8_CounterRecvCount > (Z_DataLen_Rx - 1))		// 	End data length
	{
		f_Rec_End = 1;								//		RX complete flag set
	}
}

/// @brief
/// @param    void
/// @return   void
void TXControl(void)
{
	U8 i;
	U8 F_TraOnce = 0;

	if((gu8_Main_Tx_Start == SET) && (gu8_F_MainTransmitting == CLEAR))
	{												//	TX data set flag & 100ms delay
		gu32_test_txcount++;

		gu8_Main_Tx_Start = CLEAR;
		gu8_F_MainTransmitting = SET;

		gu8_testttt = CLEAR;
		for (i = 0 ; i < Z_DataLen_Tx ; i++)
		{											//		버퍼 클리어
			gu8_Buffer_MCU_TraData[i].byte = 0x00;	//			버퍼 초기화
		} 

		SendData();						//			TX data set

		gu16_TimerTraWait = Z_TimerTraWait;			//		timer set
		gu8_CounterTraDataCount = 0;				//		TX counter clear
		f_Tra_DataMake = 0;							//		TX data set flag clear
		f_Tra_Start = 1;							//		TX start flag set
		gu8_TimerTrahalt = Z_TimerTrahalt;			//		TX timer 50ms set

		TXD2 = gu8_Buffer_MCU_TraData[0].byte;		//		TX first data transmission
		gu8_CounterTraDataCount++;					//		Increase counter

		// if ((gu8_CounterTraDataCount >= Z_DataLen_Tx) && ((SSR10 & 0x0040) != 0x0040))
		// {
		// 	f_Tra_Start = 0;							//		Clear start flag

		// 	// for (i = 0 ; i < Z_DataLen_Tx ; i++)
		// 	// {
		// 	// 	gu8_Buffer_MCU_TraData_Backup[i] = gu8_Buffer_MCU_TraData[i];
		// 	// }
		// }
	}

	#if 0
	if ((f_Tra_Start == 1) && (gu8_TimerTrahalt <= 0))	//	TX processing & TX error
	{
		gu32_test_tx_halt++;
		gu8_CounterTraDataCount = 0;				//		Counter clear
		gu8_Buffer_TraCrc = 0;						//		CRC buffer clear
		f_Tra_Start = 0;							//		Clear start flag
		gu8_TimerTrahalt = Z_TimerTrahalt;			//		TX timer 50ms set
		Uart_SFR_Refresh();							//		SFR refresh
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

	#if 0
	if ((gu8_CounterRecvCount >= 1) && (gu8_TimerRecInt_Check == 0))
	{    //	수신 중 RX interrupt 30ms check
		gu8_CounterRecvCount = 0;								//		Count clear
		gu8_TimerRecInt_Check = Z_TimerRecInt_Check;	//		Rec. interrupot 30ms check
	}
	#endif

	if (f_Rec_End == 1)
	{								//	Complete RX
		f_Rec_End = 0;							//		RX complete flag clear				
		gu8_CounterRecvCount = 0;								//		Counter clear

		gu32_test_rxcount++;
		gu8_Buffer_RecCrc = 0;									//		CRC buffer clear

		for (i = 0 ; i < (Z_DataLen_Rx - 2) ; i++)
		{			//		CRC calculation (D1~D14)
			work = (U8) (((U16) (gu8_Buffer_RecCrc >> 8) ^ gu8_Buffer_MCU_RecData[i].byte) & 0x00ffU);
			gu8_Buffer_RecCrc = (gu8_Buffer_RecCrc << 8) ^ crc_table1[work];	//			CRC buffer set
		}

		result = Crc_Check();							//		CRC check	

		if (result == 1)
		{												// 		CRC OK
			gu8_Main_Tx_Start = SET;		
			F_Communication_Error = CLEAR;
			F_FirstCommunication = SET;
			gu8_CounterRXDError = 0;
			gu8_TimerError_Time = Z_TimerError_Time;	//		RX error timer set
			Data_Parsing(); 							//			RX data parsing
		}
		else
		{												//		CRC NG
			Uart_SFR_Refresh();							//			SFR refresh
		}

	}

	if (gu8_TimerError_Time == 0)
	{													//	RX 2s error
		gu8_CounterRecvCount = 0;						//		Counter clear
		gu8_CounterRXDError++;
		Uart_SFR_Refresh();								//		SFR refresh

		gu8_TimerError_Time = Z_TimerError_Time;		//		RX error timer set
	}

	if (gu8_CounterRXDError >= 5)
	{
		gu8_CounterRXDError = 5;
		F_Communication_Error = SET;
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
	work1 = ((U16) gu8_Buffer_MCU_RecData[(Z_DataLen_Rx - 2)].byte & 0x00FF);
	work2 = ((U16) gu8_Buffer_MCU_RecData[(Z_DataLen_Rx - 1)].byte & 0x00FF) << 8;

	if (gu8_Buffer_RecCrc == (work1 | work2))
	{				//	CRC OK
		ret = 1;
	}
	else
	{										//	CRC NG
		ret = 0;
	}
	return (ret);
}

/// @brief
/// @param    void
/// @return   void
void Data_Parsing(void)
{
	U16 mu16_buff = 0;

	/****************************************************/
	gu8_Main_OperationStep = gu8_Buffer_MCU_RecData[3].byte;			//	운전상태

	gu8_Main_SEGMENT_CMD = gu8_Buffer_MCU_RecData[4].byte;
	gu8_Main_SEGMENT_OXX = gu8_Buffer_MCU_RecData[5].byte;
	gu8_Main_SEGMENT_XOX = gu8_Buffer_MCU_RecData[6].byte;
	gu8_Main_SEGMENT_XXO = gu8_Buffer_MCU_RecData[7].byte;
	gu8_Main_LED_EFFLUENT = gu8_Buffer_MCU_RecData[8].byte;
	gu8_Main_LED_mL = gu8_Buffer_MCU_RecData[9].byte;
	gu8_Main_LED_FILTER_CHANGE = gu8_Buffer_MCU_RecData[10].byte;
	gu8_Main_LED_FAUCET = gu8_Buffer_MCU_RecData[11].byte;
	gu8_Main_LED_CON = gu8_Buffer_MCU_RecData[12].byte;
	gu8_Main_LED_1Bottle = gu8_Buffer_MCU_RecData[13].byte;
	gu8_Main_LED_2CUP = gu8_Buffer_MCU_RecData[14].byte;
	gu8_Main_LED_1CUP = gu8_Buffer_MCU_RecData[15].byte;
	gu8_Main_LED_HALFCUP = gu8_Buffer_MCU_RecData[16].byte;
	gu8_Main_LED_DEGREE = gu8_Buffer_MCU_RecData[17].byte;
	gu8_Main_LED_AMOUNT = gu8_Buffer_MCU_RecData[18].byte;
	gu8_Main_LED_COLD_BLUE = gu8_Buffer_MCU_RecData[19].byte;
	gu8_Main_LED_COLD_WHITE = gu8_Buffer_MCU_RecData[20].byte;
	gu8_Main_LED_COLD = gu8_Buffer_MCU_RecData[21].byte;
	gu8_Main_LED_PURE = gu8_Buffer_MCU_RecData[22].byte;
	gu8_Main_LED_HOT = gu8_Buffer_MCU_RecData[23].byte;
	gu8_Main_LED_HOTLOCK = gu8_Buffer_MCU_RecData[24].byte;
	gu8_Main_LED_WIFI = gu8_Buffer_MCU_RecData[25].byte;
	gu8_Main_LED_UV1 = gu8_Buffer_MCU_RecData[26].byte;
	gu8_Main_LED_UV2 = gu8_Buffer_MCU_RecData[27].byte;
	gu8_Main_LED_UV3 = gu8_Buffer_MCU_RecData[28].byte;
	gu8_Main_LED_UV4 = gu8_Buffer_MCU_RecData[29].byte;
	gu8_Main_LED_UV5 = gu8_Buffer_MCU_RecData[30].byte;
	gu8_Main_LED_UV6 = gu8_Buffer_MCU_RecData[31].byte;
	gu8_Main_LED_UV7 = gu8_Buffer_MCU_RecData[32].byte;
	gu8_Main_LED_UV8 = gu8_Buffer_MCU_RecData[33].byte;
	gu8_Main_LED_UV9 = gu8_Buffer_MCU_RecData[34].byte;								
	gu8_Main_Hot_TempBar_5 = gu8_Buffer_MCU_RecData[35].byte;
	gu8_Main_Hot_TempBar_4 = gu8_Buffer_MCU_RecData[36].byte;
	gu8_Main_Hot_TempBar_3 = gu8_Buffer_MCU_RecData[37].byte;
	gu8_Main_Hot_TempBar_2 = gu8_Buffer_MCU_RecData[38].byte;
	gu8_Main_Hot_TempBar_1 = gu8_Buffer_MCU_RecData[39].byte;		
	gu8_Main_Percent = gu8_Buffer_MCU_RecData[40].byte;


	gu8_F_Voice_Play_ForCommu = gu8_Buffer_MCU_RecData[41].byte;

    gu16_Voice_Address_ForCommu = (U16)gu8_Buffer_MCU_RecData[42].byte;
	mu16_buff = (U16)gu8_Buffer_MCU_RecData[43].byte * 256;
	gu16_Voice_Address_ForCommu += mu16_buff;

	gu8_Voice_VolumeLevel_ForCommu = gu8_Buffer_MCU_RecData[44].byte;

	if((gu8_F_Voice_Play_ForCommu == SET) && (gu16_Voice_Address_ForCommu > 0))
	{
		gu8_VoiceVolumeLevel = gu8_Voice_VolumeLevel_ForCommu;
		Play_Voice(gu16_Voice_Address_ForCommu);
		gu8_F_Voice_Play_ForCommu = 0;

		gu32_Count_VoiceTest++;
	}


	F_FOTA_Display = gu8_Buffer_MCU_RecData[45].Bit.b0;

	gu8_Fade_Select = gu8_Buffer_MCU_RecData[46].byte;
	gu8_ON_DimmingPercent = gu8_Buffer_MCU_RecData[47].byte;
	gu8_DimmingPercent = gu8_Buffer_MCU_RecData[48].byte;
	gu8_DimmingPercent_Low = gu8_Buffer_MCU_RecData[49].byte;

	gu16_Main_ProgramVer = (U16)gu8_Buffer_MCU_RecData[50].byte;
	gu16_Main_ProgramVer |= (U16)(gu8_Buffer_MCU_RecData[51].byte << 8);
}

/// @brief
/// @param    void
/// @return   void
void SendData(void)
{
	/************************************************/
	gu8_Buffer_TraCrc = 0;										//	CRC clear

	gu8_Buffer_MCU_TraData[0].byte = Z_STX;
	gu8_Buffer_MCU_TraData[1].byte = Z_Front_Address;
	gu8_Buffer_MCU_TraData[2].byte = Z_NormalData;
	gu8_Buffer_MCU_TraData[3].byte = gu8_OperationStep;

#ifdef _FORCED_CHP_
	gu8_Buffer_MCU_TraData[4].Bit.b0 = SET;
#else
#ifdef _FORCED_CP_
	gu8_Buffer_MCU_TraData[4].Bit.b0 = CLEAR;
#else

	MODEL_DECIDE = 1;			//	★★
	gu8_Buffer_MCU_TraData[4].Bit.b0 = MODEL_DECIDE;
#endif
#endif
	gu8_Buffer_MCU_TraData[5].Bit.b0 = KEY_HOTWATER_SHORT;
	gu8_Buffer_MCU_TraData[5].Bit.b1 = KEY_PUREWATER_SHORT;
	gu8_Buffer_MCU_TraData[5].Bit.b2 = KEY_COLDWATER_SHORT;
	gu8_Buffer_MCU_TraData[5].Bit.b3 = KEY_AMOUNT_SHORT;
	gu8_Buffer_MCU_TraData[5].Bit.b4 = KEY_EFFLUENT_SHORT;

	gu8_Buffer_MCU_TraData[6].Bit.b0 = KEY_HOTWATER_LEVEL;
	gu8_Buffer_MCU_TraData[6].Bit.b1 = KEY_COLDWATER_LEVEL;
	gu8_Buffer_MCU_TraData[6].Bit.b2 = KEY_PUREWATER_LEVEL;
	gu8_Buffer_MCU_TraData[6].Bit.b3 = KEY_AMOUNT_LEVEL;
	gu8_Buffer_MCU_TraData[6].Bit.b4 = KEY_EFFLUENT_LEVEL;

	//	음성 ack
	gu8_Buffer_MCU_TraData[7].byte = gu8_F_Voice_Play_ForCommu;

	gu8_Buffer_MCU_TraData[8].byte = 0;
	gu8_Buffer_MCU_TraData[9].byte = 0;

	gu8_Buffer_MCU_TraData[10].byte = (U8)(PROGRAM_VERSION_NO & 0xFFU);
	gu8_Buffer_MCU_TraData[11].byte = (U8)((PROGRAM_VERSION_NO >> 8) & 0xFFU);

	gu8_Buffer_MCU_TraData[12].byte = Z_ETX;
	TraCrcCheck();									//	D1~D14 CRC calculation
	gu8_Buffer_MCU_TraData[13].byte = (U8)(gu8_Buffer_TraCrc & 0x00FFU);    //	CRC1 set
	gu8_Buffer_MCU_TraData[14].byte = (U8)((gu8_Buffer_TraCrc & 0xFF00U) >> 8);

	f_Tra_DataMake = 1;								//	Complete TX data set

	gu16_ShortKeyArray.WORD = 0x0000U;				//	데이터 CLEAR
}

/// @brief
/// @param    void
/// @return   void
void TraCrcCheck(void)
{
	U16 i;
	U16 work;
	//******	CRC data set (D1-D14)	******//
	for (i = 0 ; i < (Z_DataLen_Tx - 2) ; i++)
	{
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

	SERIAL_TX2EN();								//		TX enable
	SERIAL_RX2EN();								//		TX enable
}
