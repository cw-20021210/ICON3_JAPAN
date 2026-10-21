/// @file     Voice_NXD1005.c
/// @date     2022.01.02
/// @author   PSM
/// @brief    음성 처리 file
#define VOICE_H_
#include "include/_include.h"

static U8 SilentMode(U16 vocie_address);
static U8 SoundMode(U16 vocie_address);
static U8 VoiceMode(U16 vocie_address);

//---------------------------------------------------------
//       Voice Volume Address 지정(Next Lab 전용)
//---------------------------------------------------------
U16 gu16VoiceVolumeRegList[] =
	{
		VOICE_COMMAND_VOLUME_1,
		VOICE_COMMAND_VOLUME_2,
		VOICE_COMMAND_VOLUME_3,
		VOICE_COMMAND_VOLUME_4,
		VOICE_COMMAND_VOLUME_5};
U16 gu16BeepVolumeRegList[] =
	{
		BEEP_COMMAND_VOLUME_1,
		BEEP_COMMAND_VOLUME_2,
		BEEP_COMMAND_VOLUME_3,
		BEEP_COMMAND_VOLUME_4,
		BEEP_COMMAND_VOLUME_5};

//---------------------------------------------------------
//       Voice IC  초기화(Next Lab 전용)
//---------------------------------------------------------
void Initial_Voice(void)
{
	//   P_VOICE_RESET = ON;
	Delay(400); // 약25us
	P_VOICE_RESET = LOW;
	
	Delay(60000); // 약25us
	P_VOICE_RESET = HIGH;

	// set E2, E3 control Register
	COMMAND = VOICE_COMMAND_CONTROL2; // set Reg. E2 = 0x60
	SEND_SPI_COMMAND();

	
	COMMAND = VOICE_COMMAND_CONTROL3; // set Reg. E3 = 0x05
	SEND_SPI_COMMAND();
}
//---------------------------------------------------------
//       미  사  용
//---------------------------------------------------------
void SetVoiceLevel(U8 mu8Val)
{
	gu8_Sound_Type = mu8Val;
	if (gu8_Sound_Type == SOUND_TYPE_0)
	{
		F_OneMoreSound = 1; /*절전 해지시 부저음 1회 출력*/
	}
}
//---------------------------------------------------------
//      음성타입 체크(무음,효과음,음성)
//---------------------------------------------------------
U8 Get_Sound_Type(void)
{
	return gu8_Sound_Type;
}

//---------------------------------------------------------
//       Voice 출력 정지(Next Lab 전용)
//---------------------------------------------------------
void VoiceStop(void)
{
	COMMAND = VOICE_COMMAND_STOP;
	SEND_SPI_COMMAND();
}
//---------------------------------------------------------
//       Voice 출력 지시(공용 가능 / STOP만 구분)
//---------------------------------------------------------

void Play_Voice(U16 mu16MemoryAddress)
{
	F_PlayVoice = 1;
	gu16_Voice_Address = mu16MemoryAddress;
	VoiceStop();
}
//---------------------------------------------------------
//       Voice 출력 처리(per 2ms) (Next Lab 전용)
// 효과음/음성안내 구분 -> 출력 볼륨결정
//---------------------------------------------------------
void ProcessVoice(void)
{
	// if (gu16VoiceDelay)
	// {
	// 	gu16VoiceDelay--;
	// 	return;
	// }
	//==================================================
	if(gu8_VoiceTestttt == 1)
	{	
		return;
	}


	// 보이스 출력 지시
	if (F_PlayVoice)
	{
#if 0
		//-------------------------------------------------
		// (1) 출력 볼륨 제어
		//-------------------------------------------------
		if (gu16_Voice_Address == VOICE_CONTIUNE_EFFLUENT
			|| gu16_Voice_Address == VOICE_EFFLUENT_START
			|| gu16_Voice_Address == VOICE_EFFLUENT_COMPLETE
			|| gu16_Voice_Address == VOICE_POWER_ON
			|| gu16_Voice_Address == VOICE_BEEP_SELECT
			|| gu16_Voice_Address == VOICE_BEEP_WARNING
			|| gu16_Voice_Address == VOICE_BEEP_ON
			|| gu16_Voice_Address == VOICE_BEEP_OFF
			|| gu16_Voice_Address == VOICE_BEEP_BAD
			|| gu16_Voice_Address == VOICE_BEEP_ALARM_1
			|| gu16_Voice_Address == VOICE_BEEP_ALARM_2
//			|| gu16_Voice_Address == VOICE_CONTIUNE_EFFLUENT_2
//			|| gu16_Voice_Address == VOICE_CAREMODE_1
//			|| gu16_Voice_Address == VOICE_CAREMODE_2
			)
		{
			F_Beep_Sound = 1;                         // 효과음 판단 (볼륨 크기 구별-> 데시벨)
		}

		gu8PlayVoice_Count--;
		if (!gu8PlayVoice_Count)
		{
			F_PlayVoice = 0;
		}

		/*볼륨 설정*/
		// Critcal 상태인경우에는 볼륨 크게
		if ((IsCriticalVoice(gu16_Voice_Address) == TRUE) || (F_TestMode.byte != 0x00))
		{
			if (F_Beep_Sound)
			{
				COMMAND = 0xE100 + BEEP_COMMAND_VOLUME_5;      // 최대5단
			}
			else
			{
				COMMAND = 0xE100 + VOICE_COMMAND_VOLUME_5;
			}
		}
		// 일반 출력 항목
		else
		{
			if (F_Beep_Sound)
			{
				COMMAND = 0xE100 + gu16BeepVolumeRegList[gu8_VoiceVolumeLevel];
			}
			else
			{
				COMMAND = 0xE100 + gu16VoiceVolumeRegList[gu8_VoiceVolumeLevel];
			}
		}
#endif

		COMMAND = 0xE100 + gu16BeepVolumeRegList[gu8_VoiceVolumeLevel];

		F_PlayVoice = 0;

		Delay(400); // 약25us

		SEND_SPI_COMMAND();
		Delay(400); // 약25us

		//-------------------------------------------------
		// (2) 출력 음성 제어
		//-------------------------------------------------
		// set $E4 register = 00 if address is < 256
		if (gu16_Voice_Address < 256)
		{										 // set phrase group & higher 3 bit address on $E4 register
			COMMAND = VOICE_COMMAND_ADDRESS_256; // phase group=0, high address = 000
			SEND_SPI_COMMAND();
			// set lower 8 bit address on $E0 register
			Delay(400);												// 약25us
			COMMAND = VOICE_COMMAND_ADDRESS_0 + gu16_Voice_Address; // set lower 8 bit address on $E0 register
			SEND_SPI_COMMAND();
		}
		// set $E4 register = 0x01 if address is 256~511
		else if (gu16_Voice_Address < 512)
		{										 // set phrase group & higher 3 bit address on $E4 register
			COMMAND = VOICE_COMMAND_ADDRESS_512; // phrase group = 1, high address = 1
			SEND_SPI_COMMAND();
			// set lower 8 bit address on $E0 register
			Delay(400);														// 약25us
			COMMAND = VOICE_COMMAND_ADDRESS_0 + (gu16_Voice_Address - 256); // set lower 8 bit address on $E0 register
			SEND_SPI_COMMAND();
		}
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		/*..??? (???)..*/
		//set $E4 register = 0x02 if address is 512~767
		else if ( gu16_Voice_Address < 768)
		{                                       //set phrase group & higher 3 bit address on $E4 register
			COMMAND = VOICE_COMMAND_ADDRESS_768; //phrase group = 2, high address = 010
			SEND_SPI_COMMAND();
			//set lower 8 bit address on $E0 register
			Delay(400);   // ??25us
			COMMAND = VOICE_COMMAND_ADDRESS_0 + (gu16_Voice_Address - 512); //set lower 8 bit address on $E0 register
			SEND_SPI_COMMAND();
		}
		//set $E4 register = 0x03 if address is 768~1023
		else if ( gu16_Voice_Address < 1024)
		{                                       //set phrase group & higher 3 bit address on $E4 register
			COMMAND = VOICE_COMMAND_ADDRESS_1024; //phrase group = 3, high address = 011
			SEND_SPI_COMMAND();
			//set lower 8 bit address on $E0 register
			Delay(400);   // ??25us
			COMMAND = VOICE_COMMAND_ADDRESS_0 + (gu16_Voice_Address - 768); //set lower 8 bit address on $E0 register
			SEND_SPI_COMMAND();
		}
		//set $E4 register = 0x04 if address is 1024~1279
		else if ( gu16_Voice_Address < 1280)
		{                                       //set phrase group & higher 3 bit address on $E4 register
			COMMAND = VOICE_COMMAND_ADDRESS_1280; //phrase group = 4, high address = 100
			SEND_SPI_COMMAND();
			//set lower 8 bit address on $E0 register
			Delay(400);   // ??25us
			COMMAND = VOICE_COMMAND_ADDRESS_0 + (gu16_Voice_Address - 1024); //set lower 8 bit address on $E0 register
			SEND_SPI_COMMAND();
		}
		//set $E4 register = 0x05 if address is 1280~1535
		else if ( gu16_Voice_Address < 1536)
		{                                       //set phrase group & higher 3 bit address on $E4 register
			COMMAND = VOICE_COMMAND_ADDRESS_1536; //phrase group = 5, high address = 101
			SEND_SPI_COMMAND();
			//set lower 8 bit address on $E0 register
			Delay(400);   // ??25us
			COMMAND = VOICE_COMMAND_ADDRESS_0 + (gu16_Voice_Address - 1280); //set lower 8 bit address on $E0 register
			SEND_SPI_COMMAND();
		}
		//set $E4 register = 0x06 if address is 1536~1791
		else if ( gu16_Voice_Address < 1792)
		{                                       //set phrase group & higher 3 bit address on $E4 register
			COMMAND = VOICE_COMMAND_ADDRESS_1792; //phrase group = 6, high address = 110
			SEND_SPI_COMMAND();
			//set lower 8 bit address on $E0 register
			Delay(400);   // ??25us
			COMMAND = VOICE_COMMAND_ADDRESS_0 + (gu16_Voice_Address - 1536); //set lower 8 bit address on $E0 register
			SEND_SPI_COMMAND();
		}
		//set $E4 register = 0x07 if address is 1792~2047
		else if ( gu16_Voice_Address < 2048)
		{                                       //set phrase group & higher 3 bit address on $E4 register
			COMMAND = VOICE_COMMAND_ADDRESS_2048; //phrase group = 7, high address = 111
			SEND_SPI_COMMAND();
			//set lower 8 bit address on $E0 register
			Delay(400);   // ??25us
			COMMAND = VOICE_COMMAND_ADDRESS_0 + (gu16_Voice_Address - 1792); //set lower 8 bit address on $E0 register
			SEND_SPI_COMMAND();
		}
		else
		{
		/*..??? ????..*/
		}		
		
	}
	//==================================================
	// 출력 지시 대기
	else
	{
		// gu8PlayVoice_Count = 2;                      // 연속 2번씩 출력 지시
		gu8PlayVoice_Count = 1; // 연속 1번만 출력 지시
	}
	//==================================================
	F_Beep_Sound = 0;

	// update the address for next play in case of SBT or Play_All mode
	// Delay_ms(16); //Audio_Out Delay Time at FS=8KHz
}

/****************************************************************************
				Output One Word Command to the Voice IC (공용가능)
 ***************************************************************************/
void SEND_SPI_COMMAND(void)
{
	int i = 0;

	P_VOICE_CSB = 0; // start SPI

	//   Delay(640);                    // 약40us

	// Delay(16000);                    // 약1ms (X)
	// Delay(20000);                    // 약1.25ms (X)
	Delay(24000); // 약1.5ms
	// Delay(32000);                    // 약2ms

	P_VOICE_CLK = 0; // stand-by status,

	/*16bit 처리*/
	while (i < 16)
	{
		P_VOICE_CLK = 0;

		Delay(160); // 약10us

		if (COMMAND & MK_COMMAND)
		{
			P_VOICE_DATA = 1;
		}
		else
		{
			P_VOICE_DATA = 0;
		}

		COMMAND <<= 1; // shift left

		Delay(160); // 약10us

		P_VOICE_CLK = 1;
		i++;

		if (i == 8)
		{
			Delay(640); // 약40us (1Byte-1byte 패킷구분)
		}
		else
		{
			Delay(320); // 약20us
		}
	}

	P_VOICE_DATA = 0;
	Delay(8); // 0.5us

	P_VOICE_CSB = 1; // stand-by status

	Delay(320); // 20us
}

/// @brief    delay 함수
/// @param    mu8Time : ??
/// @return   void
void Delay(U16 mu8Time)
{
	while (--mu8Time)
	{
		NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();

		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
		// NOP();
	}
}
