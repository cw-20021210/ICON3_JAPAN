/// @file     operation.c
/// @date
/// @author   PSM
/// @brief
#define OPERATION_C
#include "include/_include.h"

static void Ini_OperationStep_00(void);     //	부팅
static void Ini_OperationStep_01(void);     //	초기화 표시
static void Ini_OperationStep_02(void);     //	통신 불가 표시
static void Ini_OperationStep_10(void);     //	by 메인 지시에 의한 표시
static void Ini_OperationStep_D0(void);     //	FOTA

static void OperationStep_00(void);
static void OperationStep_01(void);
static void OperationStep_02(void);
static void OperationStep_10(void);
static void OperationStep_D0(void);

static void OperationStepNoSet(U8 data);

Operation_StepTable Operation_Step[Z_OperationStepNum_Max] =
{
	//	스텝 No			 	디스플레이	지시		Step Func.
	{ Z_OperationStep_00,	CMD_BY_MAIN,	OperationStep_00 },     	//	부팅
	{ Z_OperationStep_01, 	CMD_BY_MAIN,	OperationStep_01 },     	//	초기화 표시
	{ Z_OperationStep_02, 	CMD_COMM_ER,	OperationStep_02 },     	//	통신 불가 표시
	{ Z_OperationStep_10, 	CMD_BY_MAIN,	OperationStep_10 },     	//	by 메인 지시에 의한 표시
	{ Z_OperationStep_D0, 	CMD_FOTA,		OperationStep_D0 },     	//	FOTA 중 표시
};

/// @brief
/// @param    void
/// @return   void
void Operation_Initialize(void)
{
	Ini_OperationStep_00();
}

/// @brief
/// @param    void
/// @return   void
void Operation(void)
{
	if (gu8_OperationStepNum < Z_OperationStepNum_Max)	//	스텝 허용 범위 이내
	{
		(Operation_Step[gu8_OperationStepNum].exe)();	//		해당 스텝 함수 실행

		DisplayControl_Data[Z_SEGMENT].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_EFFLUENT].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_mL].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_FILTER_CHANGE].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_FAUCET].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_CON].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_1BOTTLE].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;		
		DisplayControl_Data[Z_LED_2CUP].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_1CUP].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_HALFCUP].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_DEGREE].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_AMOUNT].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_COLD_BLUE].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_COLD_WHITE].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_COLD].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_PURE].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_HOT].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_HOTLOCK].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_WIFI].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV1].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV2].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV3].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV4].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV5].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV6].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV7].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV8].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_UV9].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;		
		DisplayControl_Data[Z_LED_HOT_BAR_5].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;		
		DisplayControl_Data[Z_LED_HOT_BAR_4].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;			
		DisplayControl_Data[Z_LED_HOT_BAR_3].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;			
		DisplayControl_Data[Z_LED_HOT_BAR_2].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;			
		DisplayControl_Data[Z_LED_HOT_BAR_1].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;
		DisplayControl_Data[Z_LED_PERCENT].Operation_CMD = Operation_Step[gu8_OperationStepNum].Display_CMD;											

	}
	else											//	스텝 허용범위 외
	{
		SafetyLoop();								//		안전정지 루프
	}
}

/// @brief    초기 전원 인가 부팅 표시
/// @param    void
/// @return   void
static void OperationStep_00(void)
{
	if (gu8_TimerBootDisplay == 0)
	{
		Ini_OperationStep_01();
	}
}
static void Ini_OperationStep_00(void)
{
	gu8_TimerBootDisplay = Z_TimerBootDisplay;
	OperationStepNoSet(Z_OperationStepNum_00);
}

/// @brief    버전 표시
/// @param    void
/// @return   void
static void OperationStep_01(void)
{
	if ((gu8_TimerVersionDisplay == 0) && (F_FirstCommunication == SET))	//	0~2초 : 점멸 2회 / 2~3초 : 버전 표시
	{
		Ini_OperationStep_10();
	}
	else if (F_Communication_Error == SET)
	{
		Ini_OperationStep_02();
	}
}
static void Ini_OperationStep_01(void)
{
	OperationStepNoSet(Z_OperationStepNum_01);
}

/// @brief    통신 에러
/// @param    void
/// @return   void
static void OperationStep_02(void)
{
	if (F_Communication_Error == CLEAR)
	{
		Ini_OperationStep_00();
	}
}
static void Ini_OperationStep_02(void)
{
	OperationStepNoSet(Z_OperationStepNum_02);
}

/// @brief
/// @param    void
/// @return   void
static void OperationStep_10(void)
{
	if (F_FOTA_Display == SET)
	{
		Ini_OperationStep_D0();
	}
	else if (F_Communication_Error == SET)
	{
		Ini_OperationStep_02();
	}
	else
	{

	}
}
static void Ini_OperationStep_10(void)
{
	OperationStepNoSet(Z_OperationStepNum_10);
}

/// @brief
/// @param    void
/// @return   void
static void OperationStep_D0(void)
{
	if (F_FOTA_Display == CLEAR)
	{
		Ini_OperationStep_10();
	}
	else if (gu16_TimerOper_1s == 0)
	{
		F_FOTA_Display = CLEAR;
		Ini_OperationStep_10();
	}
	else
	{

	}
}
static void Ini_OperationStep_D0(void)
{
	gu16_TimerOper_1s = Z_Timer1s_Oper_180s;
	gu8_TimerFOTA_Display = Z_TimerFOTA_Display;
	F_FOTA_Display_forWIFI_LED_ONOFF = SET;
	OperationStepNoSet(Z_OperationStepNum_D0);
}

/// @brief    운전스텝 설정
/// @param    void
/// @return   void
static void OperationStepNoSet(U8 data)
{
	static const U8 DT_OperationNumber[] =
	{
		Z_OperationStep_00,
		Z_OperationStep_01,
		Z_OperationStep_02,
		Z_OperationStep_10,
	};
	/************************************************/
	gu8_OperationStepNum = data; /*	일련 번호 set*/

	F_CommunicationCMD = SET;

	gu8_OperationStep = DT_OperationNumber[gu8_OperationStepNum]; /*	상태 mode No. set*/
}
