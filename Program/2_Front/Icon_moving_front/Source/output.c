/// @file     output.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    출력 처리 file
#define OUTPUT_C
#include "include/_include.h"


static void OutputNotUsePort(void);

/// @brief    출력처리 초기화
/// @param    voidu
/// @return   void
void Output_Initialize(void)
{

}

/// @brief    출력 처리
/// @param    void
/// @return   void
void OutputControl(void)
{
	/************************************************/
	/*---------------------------------*/
	/*	전 부하의 출력 처리				   */
	/*---------------------------------*/

	/*---------------------------------*/
	/*	미사용 PORT 출력 처리			   */
	/*---------------------------------*/
	OutputNotUsePort(); 							//	미사용 포트 출력
}

/// @brief    미사용 포트 처리
/// @param    void
/// @return   void
static void OutputNotUsePort(void)
{
	/************************************************/
//	P0.0 = 0;
//	P0.4 = 0;
//	P13.0 = 0;
//	P15.1 = 0;
//	P6.2 = 0;
//	P4.2 = 0;
}
