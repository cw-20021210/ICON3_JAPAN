/// @file     input.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    입력 처리 file
#define INPUT_C
#include "include/_include.h"


/// @brief    디지털 입력 초기화
/// @param    void
/// @return   void
void Input_Initialize(void)
{

}

/// @brief    디지털 입력 제어
/// @param    void
/// @return   void
void InputControl(void)
{
	BYTE_BIT mu8_inputdata;
	BYTE_BIT mu8_inputdata2;
	BYTE_BIT mu8_inputdata3;

	mu8_inputdata.byte = 0x00;
	mu8_inputdata2.byte = 0x00;
	mu8_inputdata3.byte = 0x00;

	if (F_10ms_for_InputDigital ==  SET)			//	10ms 주기
	{
		F_10ms_for_InputDigital = CLEAR;

		/*	터치 처리	*/
		mu8_inputdata.Bit.b0 = !P_KEY_HOT;
		mu8_inputdata.Bit.b1 = !P_KEY_COLD;
		mu8_inputdata.Bit.b2 = !P_KEY_PURE;
		mu8_inputdata.Bit.b3 = !P_KEY_AMOUNT;
//		mu8_inputdata.Bit.b4 = !P_KEY_EFFLUENT;

		ThreeMatchModule(&gu8_DigitalInput, mu8_inputdata.byte);	//	디지털 입력 3회 일치 모듈

		/*	모델 기종 처리	*/
		mu8_inputdata2.Bit.b0 = P_MODEL;

		ThreeMatchModule(&gu8_DigitalInput2, mu8_inputdata2.byte);	//	디지털 입력 3회 일치 모듈

		mu8_inputdata.byte = 0x00;

		/*	버튼 처리	*/
		mu8_inputdata3.Bit.b0 = !P_KEY_EFFLUENT;

		ThreeMatchModule(&gu8_DigitalInput3, mu8_inputdata3.byte);	//	디지털 입력 3회 일치 모듈
	}
}

/// @brief    3회 일치 모듈
/// @param    void
/// @return   void
void ThreeMatchModule(ITTI3* p, U8 data)
{
	p->Third = p->Second;
	p->Second = p->First;
	p->First = data;

	p->OnEdge.byte = (U8) ((~p->Level.byte) & (p->First) & (p->Second) & (p->Third));
	p->OffEdge.byte = (U8) ((p->Level.byte) & (~p->First) & (~p->Second) & (~p->Third));
	p->Level.byte = (U8) (((p->First | p->Second | p->Third) & p->Level.byte) | p->OnEdge.byte);
}
