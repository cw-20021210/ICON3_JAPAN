/// @file   main.h
/// @date   2019.07.10
/// @author PSM
/// @brief  메인루프 처리 관련 헤더 file

#ifdef MAIN_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif

/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_MAIN()			{	/*	1ms 타이머 감산			*/	\
								}
#define	TDEC_10ms_MAIN()		{	/*	10ms 타이머 감산		*/	\
									TDEC(gu8_TimerHWWait);		\
								}
#define	TDEC_100ms_MAIN()		{	/*	100ms 타이머 감산		*/	\
									TDEC(gu8_TimerBootDisplay);	\
									TDEC(gu8_TimerVersionDisplay);	\
								}
#define	TDEC_1s_MAIN()			{	/*	1s 타이머 감산			*/	\
								}
#define	TDEC_10s_MAIN()			{	/*	10s 타이머 감산			*/	\
								}
#define	TDEC_1min_MAIN()		{	/*	1min 타이머 감산		*/	\
								}
#define	TDEC_10min_MAIN()		{	/*	10min 타이머 감산		*/	\
								}
#define	TDEC_1h_MAIN()			{	/*	1h 타이머 감산			*/	\
								}

/*==============================================================================
 Constant Definition
 ==============================================================================*/
// 프로그램 버전 표시
// 1) 첫번째 자리 : 	1 - 양산 적용
//                  0 - 양산 외
// 2) 두번째 자리 : 	1 - DPP
//                  2 - LPP
//					0 - 양산
// 3) 세번째 자리 : 		미정의
// 4) 네번째 자리 : 버전 표시 
//                  0 ~ 16  (16이상이면 0 부터 재시작) 
// #define PROGRAM_VERSION_NO      (0x1001)			//
// #define PROGRAM_VERSION_NO      (0x0201)			//	LPP
// #define PROGRAM_VERSION_NO      (0x0202)			//	LPP 최종 버젼 V0.2.0.2
#define PROGRAM_VERSION_NO      (0x1001)			//	양산 시작 V1.0.0.1

#define Z_TimerHWWait			(50)				//	하드웨어 안정화 대기 시간	<100ms/10ms>

#define Z_TimerBootDisplay		(20)

/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN U8 gu8_TimerHWWait;							//	하드웨어 안정화 시간	<100ms/100ms>

EXTERN U8 gu8_TimerBootDisplay;
EXTERN U8 gu8_TimerVersionDisplay;

/*==============================================================================
 function Definition
 ==============================================================================*/
void MainLoop(void);
void RamClear(void);


//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================
