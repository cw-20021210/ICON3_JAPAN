/// @file     main.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    Main 처리 file
#define MAIN_C
#define FIX_RAM_C
#include "include/_include.h"


/// @brief    메인 루프
/// @param    void
/// @return   void
void MainLoop(void)
{
	RamClear();										//	변수초기화

	R_WDT_Restart();								//	WDT Reset

	R_SAU1_Create();
	R_TAU0_Create();	

	R_TAU0_Channel0_Start();						//	1ms Timer Func. Start
	R_UART2_Start();								//	UART1 Start
	R_WDT_Restart();								//	WDT Reset

	gu8_TimerHWWait = Z_TimerHWWait;				//	하드웨어 안정화 타임

	while (gu8_TimerHWWait != 0)					//	하드웨어 안정화 대기
	{
		R_WDT_Restart();							//		WDT Reset

		Timer_Process();							//		Timer 처리

		InputControl();								//		Digital Input 처리
	}

	while (1)										//	Main Loop
	{
		R_WDT_Restart();							//		WDT Reset

		Timer_Process();							//		Timer 처리

		//	입력
		InputControl();								//		Digital Input 처리

		KeyDecide(&gu8_DigitalInput);

		//	처리
		Operation();

		//	출력
		// OutputControl();

		//	통신처리
		CommunicationControl();						//		Main 통신

		//	안전처리
		// Safety();									//		안전처리
		ProcessVoice();
	}
}

/// @brief    RAM Clear
/// @param    void
/// @return   void
void RamClear(void)
{
	Communication_Initialize();
	Display_Initialize();
	Input_Initialize();
	KeyControl_Initialize();
	Operation_Initialize();
	Safety_Initialize();
	Timer_Initialize();
	Output_Initialize();
	Initial_Voice();
}
