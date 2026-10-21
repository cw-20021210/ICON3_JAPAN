/// @file     timer.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    타이머 인터럽트 처리 file
#define TIMER_C
#include "include/_include.h"


/// @brief    Base Interval Timer(500us Timer Interrupt)
/// @param    void
/// @return   void
void Timer_Initialize(void)
{
	gu8_Counter_1msTimerCheck = 0xFF; 				/*	1ms timer interrupt check counter clr */
}

/// @brief    Base Interval Timer
/// @param    void
/// @return   void
void Timer_Base_Timer(void)
{
	static U16 count = 0;
	static U8 count_1ms = 0;

	EI();											//	다중인터럽트 허용

	if (++gu8_DisplayPWM_Count_1ms > Z_DisplayPWM)							//
	{
		gu8_DisplayPWM_Count_1ms = 1;
	}

	if((gu8_Main_SEGMENT_CMD != LED_ON) || (gu8_OperationStep == Z_OperationStep_02 )){
		Seg_Control();									//	SEG 제어 (200us 주기)		/*Fade 점멸 동작시 SEG 떨림 현상 발생 이에 따라 조건에 따라 SEG 제어 주기를 달리하여 해당 문제점 해결함.*/
	}

	DisplayOut();
	FadeProcess();	

	if (++count_1ms >= (Z_DisplayPWM/10))
	{
		if((gu8_Main_SEGMENT_CMD == LED_ON) && (gu8_OperationStep != Z_OperationStep_02 )){
			Seg_Control();								//	SEG 제어 (1ms 주기)		/*Fade 점멸 동작시 SEG 떨림 현상 발생 이에 따라 조건에 따라 SEG 제어 주기를 달리하여 해당 문제점 해결함.*/
		}
		count_1ms = 0;

		DisplayControl();								//	표시제어

		Time1ms(); 										/*	1ms TIMER 감산			*/

		gu8_Counter10ms++; 								/*	10ms COUNTER +1			*/
		if (gu8_Counter10ms >= 10)						/*	10ms 경과한 경우		*/
		{
			F_10ms_for_InputDigital = SET;
			gu8_Counter10ms = 0; 						/*		10ms COUTNER CLR	*/
			Time10ms(); 								/*		10ms TIMER 감산		*/
			gu8_Counter100ms++; 						/*		100ms COUNTER +1	*/
			if (gu8_Counter100ms >= 10)					/*		100ms 경과한 경우	*/
			{
				gu8_Counter100ms = 0; 					/*			100ms COUNTER CLR*/
				gu8_FlagTime100ms = 1; 					/*			100ms 경과 FLAG SET*/
			}
		}
		gu8_Counter_1msTimerCheck = 0xFF; 				/*	1ms timer interrupt check counter clr */

		gu8_Counter_MainLoopCheck--;

		if (gu8_Counter_MainLoopCheck == 0)				//	메인 체크 카운터 reset되지 않는 경우
		{
			SafetyLoop();
		}
	}
}

/// @brief    Timer 처리
/// @param    void
/// @return   void
void Timer_Process(void)
{
	static U8 mu8_Counter1s; 						/*	1s COUNTER 				*/
	static U8 mu8_Counter10s; 						/*	10s COUNTER				*/
	static U8 mu8_Counter1min; 						/*	1min COUNTER			*/
	static U8 mu8_Counter10min; 					/*	10min COUNTER			*/
	static U8 mu8_Counter1h; 						/*	1h COUNTER				*/
	/********************************************/
	if (gu8_FlagTime100ms == 1)						/*	100ms 경과 FLAG SET인 경우	*/
	{
		gu8_FlagTime100ms = 0; 						/*		100ms 경과 FLAG CLR		*/
		Time100ms(); 								/*		100ms TIMER 감산		*/

		mu8_Counter1s++; 							/*		1s COUNTER +1			*/
		if (mu8_Counter1s >= 10)					/*		1s 경과한 경우			*/
		{
			mu8_Counter1s = 0; 						/*			1s COUNTER CLR		*/
			gu8_FlagTime1000ms = 1; 				/*			1s 경과 FLAG SET	*/
			Time1s(); 								/*			1s TIMER 감산		*/

			mu8_Counter10s++; 						/*			10s COUNTER +1		*/
			if (mu8_Counter10s >= 10)
			{ 										/*			10s 경과한 경우		*/
				mu8_Counter10s = 0; 				/*				10s COUNTER CLR	*/
				Time10s(); 							/*				10s TIMER 감산	*/

				mu8_Counter1min++; 					/*				1min COUNTER +1	*/
				if (mu8_Counter1min >= 6)			/*				1min 경과한 경우			*/
				{
					mu8_Counter1min = 0; 			/*					1min COUNTER CLR		*/
					Time1min(); 					/*					1min TIMER 감산			*/

					mu8_Counter10min++; 			/*					10min COUNTER +1		*/
					if (mu8_Counter10min >= 10)		/*					10min 경과한 경우		*/
					{
						mu8_Counter10min = 0; 		/*						10min COUNTER CLR	*/
						Time10min(); 				/*						10min TIMER 감산	*/

						mu8_Counter1h++; 			/*						1h COUNTER +1		*/
						if (mu8_Counter1h >= 6)		/*						1h 경과한 경우		*/
						{
							mu8_Counter1h = 0; 		/*							1h COUNTER CLR	*/
							Time1h(); 				/*							1h TIMER 감산	*/
						}
					}
				}
			}
		}
	}
}

/// @brief    1ms 처리
/// @param    void
/// @return   void
void Time1ms(void)
{
	U8 i;
//	static U8 mu8_Timer11ms;
//	/********************************************/
//	if (mu8_Timer11ms == 0)							/*	DIGITAL 입력 TIMER UP인 경우	*/
//	{
//		mu8_Timer11ms = ZT_11ms; 					/*		DIGITAL 입력 TIMER SET		*/
//	}
//	else											/*	상기 이외						*/
//	{
//		mu8_Timer11ms--; 							/*		TIMER 감산					*/
//	}
	/*------------------------------------------*/

	F_1ms_for_InputDigital = SET;

	TDEC_1ms_DISPLAY();
	TDEC_1ms_MAIN();
	TDEC_1ms_SAFETY();
	TDEC_1ms_TIMER();
	TDEC_1ms_OPERATION();
	TDEC_1ms_INPUT();
	TDEC_1ms_KEYCONTROL();
	TDEC_1ms_COMMUNICATION();
	TDEC_1ms_OUTPUT();

	for (i = 0 ; i < DisplayNum_Max ; i++)
	{
		TDEC(DisplayControl_Data[i].Fade_Timer);
	}
}

/// @brief    10ms 처리
/// @param    void
/// @return   void
void Time10ms(void)								//
{												//
	/********************************************/
	TDEC_10ms_DISPLAY();
	TDEC_10ms_MAIN();
	TDEC_10ms_SAFETY();
	TDEC_10ms_TIMER();
	TDEC_10ms_OPERATION();
	TDEC_10ms_INPUT();
	TDEC_10ms_KEYCONTROL();
	TDEC_10ms_COMMUNICATION();
	TDEC_10ms_OUTPUT();
}

/// @brief    100ms 처리
/// @param    void
/// @return   void
void Time100ms(void)							//
{												//
	/********************************************/
	TDEC_100ms_DISPLAY();
	TDEC_100ms_MAIN();
	TDEC_100ms_SAFETY();
	TDEC_100ms_TIMER();
	TDEC_100ms_OPERATION();
	TDEC_100ms_INPUT();
	TDEC_100ms_KEYCONTROL();
	TDEC_100ms_COMMUNICATION();
	TDEC_100ms_OUTPUT();
}

/// @brief    1sec 처리
/// @param    void
/// @return   void
void Time1s(void)
{
	/********************************************/
	TDEC_1s_DISPLAY();
	TDEC_1s_MAIN();
	TDEC_1s_SAFETY();
	TDEC_1s_TIMER();
	TDEC_1s_OPERATION();
	TDEC_1s_INPUT();
	TDEC_1s_KEYCONTROL();
	TDEC_1s_COMMUNICATION();
	TDEC_1s_OUTPUT();
}

/// @brief    10sec 처리
/// @param    void
/// @return   void
void Time10s(void)								//
{												//
	/********************************************/
	TDEC_10s_DISPLAY();
	TDEC_10s_MAIN();
	TDEC_10s_SAFETY();
	TDEC_10s_TIMER();
	TDEC_10s_OPERATION();
	TDEC_10s_INPUT();
	TDEC_10s_KEYCONTROL();
	TDEC_10s_COMMUNICATION();
	TDEC_10s_OUTPUT();
}												//

/// @brief    1min 처리
/// @param    void
/// @return   void
void Time1min(void)								//
{												//
	/********************************************/
	TDEC_1min_DISPLAY();
	TDEC_1min_MAIN();
	TDEC_1min_SAFETY();
	TDEC_1min_TIMER();
	TDEC_1min_OPERATION();
	TDEC_1min_INPUT();
	TDEC_1min_KEYCONTROL();
	TDEC_1min_COMMUNICATION();
	TDEC_1min_OUTPUT();
}

/// @brief    10min 처리
/// @param    void
/// @return   void
void Time10min(void)							//
{												//
	/********************************************/
	TDEC_10min_DISPLAY();
	TDEC_10min_MAIN();
	TDEC_10min_SAFETY();
	TDEC_10min_TIMER();
	TDEC_10min_OPERATION();
	TDEC_10min_INPUT();
	TDEC_10min_KEYCONTROL();
	TDEC_10min_COMMUNICATION();
	TDEC_10min_OUTPUT();
}

/// @brief    1h 처리
/// @param    void
/// @return   void
void Time1h(void)								//
{												//
	/********************************************/
	TDEC_1h_DISPLAY();
	TDEC_1h_MAIN();
	TDEC_1h_SAFETY();
	TDEC_1h_TIMER();
	TDEC_1h_OPERATION();
	TDEC_1h_INPUT();
	TDEC_1h_KEYCONTROL();
	TDEC_1h_COMMUNICATION();
	TDEC_1h_OUTPUT();
}
