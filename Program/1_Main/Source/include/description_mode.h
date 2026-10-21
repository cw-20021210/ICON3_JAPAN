/// @file   description_mode.h
/// @date   2025.01.XX
/// @author 
/// @brief  Description Mode 관련 헤더 file

#ifndef _DESCRIPTION_MODE_H_
#define _DESCRIPTION_MODE_H_

#include "_type_define.h"

#ifdef DESCRIPTION_MODE_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
	#define 	GLOBAL_VARIABLE_DEFINE extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_DESCRIPTION_MODE()	{	/*	1ms 타이머 감산			*/	\
								}
#define	TDEC_10ms_DESCRIPTION_MODE()	{	/*	10ms 타이머 감산		*/	\
								}
#define	TDEC_100ms_DESCRIPTION_MODE()	{	/*	100ms 타이머 감산		*/	\
									TDEC(gu16_TimerDescriptionMode_100ms);		\
									TDEC(gu16_TimerDescriptionMode_20s);		\
								}
#define	TDEC_1s_DESCRIPTION_MODE()		{	/*	1s 타이머 감산			*/	\
								}
#define	TDEC_10s_DESCRIPTION_MODE()	{	/*	10s 타이머 감산			*/	\
								}
#define	TDEC_1min_DESCRIPTION_MODE()	{	/*	1min 타이머 감산		*/	\
								}
#define	TDEC_10min_DESCRIPTION_MODE()	{	/*	10min 타이머 감산		*/	\
								}
#define	TDEC_1h_DESCRIPTION_MODE()		{	/*	1h 타이머 감산			*/	\
								}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
#define Z_DescriptionModeStep_10			(0x10)          //	대기
#define Z_DescriptionModeStep_15			(0x15)          //	ON 표시
#define Z_DescriptionModeStep_16			(0x16)          //	냉수 OFF 표시
#define Z_DescriptionModeStep_17			(0x17)          //	파우셋 ON/OFF 설정 표시
#define Z_DescriptionModeStep_18			(0x18)          //	OFF 표시
#define Z_DescriptionModeStep_20			(0x20)          //	슬립모드
#define Z_DescriptionModeStep_40			(0x40)          //	전체 잠금
#define Z_DescriptionModeStep_41			(0x41)          //	사운드 타입
#define Z_DescriptionModeStep_43			(0x43)          //	파우셋 ON/OFF

enum {
	Z_DescriptionModeStepNum_10,
	Z_DescriptionModeStepNum_15,
	Z_DescriptionModeStepNum_16,
	Z_DescriptionModeStepNum_17,
	Z_DescriptionModeStepNum_18,
	Z_DescriptionModeStepNum_20,
	Z_DescriptionModeStepNum_40,
	Z_DescriptionModeStepNum_41,
	Z_DescriptionModeStepNum_43,
	Z_DescriptionModeStepNum_Max
};

#define Z_TimerDescriptionMode_100ms_2s	(20)			//	<2s/100ms>
#define Z_TimerDescriptionMode_100ms_7s	(70)			//	<7s/100ms>
#define Z_TimerDescriptionMode_100ms_20s	(200)			//	<20s/100ms>

/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN U8 gu8_F_Start_DescriptionMode;

EXTERN U8 gu8_DescriptionModeStep;
EXTERN U8 gu8_DescriptionModeStepNum;
EXTERN U16 gu16_TimerDescriptionMode_100ms;
EXTERN U16 gu16_TimerDescriptionMode_MoveDisplay;
EXTERN U16 gu16_TimerDescriptionMode_20s;

GLOBAL_VARIABLE_DEFINE Operation_StepTable DescriptionMode_Step[Z_DescriptionModeStepNum_Max];

/*==============================================================================
 function Definition
 ==============================================================================*/
EXTERN void DescriptionMode_Initialize(void);
EXTERN void Description__Mode(void);

EXTERN void DescriptionModeStep_10(void);
EXTERN void DescriptionModeStep_15(void);
EXTERN void DescriptionModeStep_16(void);
EXTERN void DescriptionModeStep_17(void);
EXTERN void DescriptionModeStep_18(void);
EXTERN void DescriptionModeStep_20(void);
EXTERN void DescriptionModeStep_40(void);
EXTERN void DescriptionModeStep_41(void);
EXTERN void DescriptionModeStep_43(void);

EXTERN void Ini_DescriptionModeStep_10(void);
EXTERN void Ini_DescriptionModeStep_15(void);
EXTERN void Ini_DescriptionModeStep_16(void);
EXTERN void Ini_DescriptionModeStep_17(void);
EXTERN void Ini_DescriptionModeStep_18(void);
EXTERN void Ini_DescriptionModeStep_20(void);
EXTERN void Ini_DescriptionModeStep_40(void);
EXTERN void Ini_DescriptionModeStep_41(void);
EXTERN void Ini_DescriptionModeStep_43(void);

EXTERN void DescriptionModeStepNoSet(U8 data);

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================
#endif

