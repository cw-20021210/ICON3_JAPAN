/// @file   display.h
/// @date   2019.07.10
/// @author PSM
/// @brief  ǥ�� ���� ���� ���� ���? file

#ifdef DISPLAY_C
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif
	
/*==============================================================================
 Timer Decrease
 ==============================================================================*/
#define	TDEC_1ms_DISPLAY()		{	/*	1ms Ÿ�̸� ����			*/	\
								}
#define	TDEC_10ms_DISPLAY()		{	/*	10ms Ÿ�̸� ����		*/	\
									TDEC(gu8_TimerContSeg); 	\
									TDEC(gu8_TimerSEG_TH_Limit);		\
									TDEC(gu8_TimerSegTest);		\
									TDEC(gu8_TimerFlushingDisplay);	\
									TDEC(gu8_Timer_UV_Display);	\
									TDEC(gu8_TimerColdTankClearDisplay);	\
									TDEC(gu16_TimerSmartCheckDisplay);	\
									TDEC(gu8_TimerFlowSensorTestDisplay);	\
									TDEC(gu8_TimerFlicker);	\
									TDEC(gu8_TimerLineTest_SegUpdate);	\
									TDEC(gu8_Timer_Faucet_Set_Mode_Display);	\
								}
#define	TDEC_100ms_DISPLAY()	{	/*	100ms Ÿ�̸� ����		*/	\
									TDEC(gu8_Timer_SEG_TH);		\
									TDEC(gu8_Timer_SEG_MONITOR);	\
									TDEC(gu8_TimerDefaultCupSize_Set_LEDFlic);	\
									TDEC(gu8_Timer_SEG_ColdTest);	\
									TDEC(gu8_TimerErrorHistory);	\
									TDEC(gu8_TimerColdTempDisplay_forWhite);	\
									TDEC(gu8_TimerColdTempDisplay_forBlue);	\
									TDEC(gu8_Timer_TEM_Volt_Display);	\
									TDEC(gu8_TimerAllLockDisplay);	\
									TDEC(gu8_TimerFOTA_Display);	\
									TDEC(gu8_TimerMySetFilker);		\
									TDEC(gu8_TimerCupSize_LEDFlic_forJAPAN_Limit);	\
									TDEC(gu8_Timer_AdFeedback_Loading);	\
									TDEC(gu8_Timer_Wifi_Pairing_Display_AfterEff);	\
									TDEC(gu8_Timer_Smps_Feedback_Display);	\
								}
#define	TDEC_1s_DISPLAY()		{	/*	1s Ÿ�̸� ����			*/	\
								}
#define	TDEC_10s_DISPLAY()		{	/*	10s Ÿ�̸� ����			*/	\
								}
#define	TDEC_1min_DISPLAY()		{	/*	1min Ÿ�̸� ����		*/	\
								}
#define	TDEC_10min_DISPLAY()	{	/*	10min Ÿ�̸� ����		*/	\
								}
#define	TDEC_1h_DISPLAY()		{	/*	1h Ÿ�̸� ����			*/	\
								}


/*==============================================================================
 Constant Definition
 ==============================================================================*/
EXTERN    const U8 DT_7seg[]							//	7segment
#ifdef    GLOBAL_VARIABLE_DEFINE
= {
	0x3F,	                              				/* '0' 0 011 1111*/
	0x06,	                              				/* '1' 1 000 0110*/
	0x5B,	                              				/* '2' 2 101 1011*/
	0x4F,	                              				/* '3' 3 100 1111*/
	0x66,	                              				/* '4' 4 110 0110*/
	0x6D,	                              				/* '5' 5 110 1101*/
	0x7D,	                              				/* '6' 6 111 1101*/
	0x27,	                              				/* '7' 7 010 0111*/
	0x7F,	                              				/* '8' 8 111 1111*/
	0x6F,	                              				/* '9' 9 110 1111*/
	0x77,	                              				/* 'A' 10 111 0111*/
	0x7C,	                              				/* 'b' 11 111 1100*/
	0x58,                                 				/* 'c' 12 101 1000*/
	0x5E,                                				/* 'd' 13 101 1110*/
	0x79,                                 				/* 'E' 14 111 1001*/
	0x71,	                              				/* 'F' 15 111 0001*/
	0x38,												/* 'L' 16 011 1000*/
	0x5C,								  				/* 'o' 17 101 1100*/
	0x3F,								  				/* 'O' 18 011 1111*/
	0x73,								  				/* 'P' 19 111 0011*/
	0x54,								  				/* 'n' 20 101 0100*/
	0x76,								  				/* 'H' 21 111 0110*/
	0x50,                                               // 'r' 22 101 0000
	0x6D,                                               // 'S' 23 110 1101
	0x78,                                               // 't' 24 111 1000
	0x3E,                                               // 'U' 25 011 1110
	0x80,                                               // 'DOT' 26 �̻��? (Dot ����)
	0x40,                                               // 'BAR' 27 100 0000
	0x00,                                               // 'X' 28
	0x39,                                               // 'C' 29
	0x06,                                               // 'I' 30
	0x1C,                                               // 'u' 31
	0x08,                                               // 'Under BAR' 32
	0x01,                                               // 'Upper BAR' 33
	0x01,                                               // SEG a
	0x02,                                               // SEG b
	0x04,                                               // SEG c
	0x08,                                               // SEG d
	0x10,                                               // SEG e
	0x20,                                               // SEG f
	0x40,                                               // SEG g
	0x1E,                                               // 'J' 001 1110
	0x70,                                               // 'K' 111 0000
}
#endif
;

#define Z_NUM_0   (0)
#define Z_NUM_1   (1)
#define Z_NUM_2   (2)
#define Z_NUM_3   (3)
#define Z_NUM_4   (4)
#define Z_NUM_5   (5)
#define Z_NUM_6   (6)
#define Z_NUM_7   (7)
#define Z_NUM_8   (8)
#define Z_NUM_9   (9)
#define Z_NUM_A   (10)
#define Z_NUM_b   (11)
#define Z_NUM_c   (12)
#define Z_NUM_d   (13)
#define Z_NUM_E   (14)
#define Z_NUM_F   (15)
#define Z_NUM_L   (16)
#define Z_NUM_o   (17)
#define Z_NUM_O   (18)
#define Z_NUM_P   (19)
#define Z_NUM_n   (20)
#define Z_NUM_H   (21)
#define Z_NUM_r   (22)
#define Z_NUM_S   (23)
#define Z_NUM_t   (24)
#define Z_NUM_U   (25)
#define Z_NUM_DOT (26)
#define Z_NUM_BAR (27)
#define Z_NUM_X	  (28)
#define Z_NUM_C	  (29)
#define Z_NUM_I   (30)
#define Z_NUM_u   (31)
#define Z_NUM_UNDER_BAR (32)
#define Z_NUM_UPPER_BAR (33)
#define Z_NUM_SEG_a (34)
#define Z_NUM_SEG_b (35)
#define Z_NUM_SEG_c (36)
#define Z_NUM_SEG_d (37)
#define Z_NUM_SEG_e (38)
#define Z_NUM_SEG_f (39)
#define Z_NUM_SEG_g (40)
#define Z_NUM_J	   (41)
#define Z_NUM_K	   (42)

EXTERN const U8 DT_Cont_OXX[20]						//	7-Segment �������� �Ǵ� �������? Cycle
#ifdef    GLOBAL_VARIABLE_DEFINE
= {
	0b00000000,			//	1
	0b00010000,			//	2
	0b00110000,	        //	3
	0b00110001,	        //	4
	0b00110001,	        //	5
	0b00110001,	        //	6
	0b00110001,	        //	7
	0b00110001,	        //	8
	0b00110001,	        //	9
	0b00110001,	        //	10
	0b00111001,	        //	11
	0b00101001,	        //	12
	0b00001001,	        //	13
	0b00001000,	        //	14
	0b00001000,	        //	15
	0b00001000,	        //	16
	0b00001000,	        //	17
	0b00001000,	        //	18
	0b00001000,	        //	19
	0b00001000,	        //	20
}
#endif
;

EXTERN    const U8 DT_Cont_XOX[20]						//	7-Segment �������� �Ǵ� �������? Cycle
#ifdef    GLOBAL_VARIABLE_DEFINE
= {
	0b00000000,			//	1
	0b00000000,			//	2
	0b00000000,	        //	3
	0b00000000,	        //	4
	0b00000001,	        //	5
	0b00000001,	        //	6
	0b00000001,	        //	7
	0b00000001,	        //	8
	0b00000001,	        //	9
	0b00001001,	        //	10
	0b00001001,	        //	11
	0b00001001,	        //	12
	0b00001001,	        //	13
	0b00001001,	        //	14
	0b00001000,	        //	15
	0b00001000,	        //	16
	0b00001000,	        //	17
	0b00001000,	        //	18
	0b00001000,	        //	19
	0b00000000,	        //	20
}
#endif
;

EXTERN    const U8 DT_Cont_XXO[20]						//	7-Segment �������� �Ǵ� �������? Cycle
#ifdef    GLOBAL_VARIABLE_DEFINE
= {
	0b00000000,			//	1
	0b00000000,			//	2
	0b00000000,	        //	3
	0b00000000,	        //	4
	0b00000000,	        //	5
	0b00000001,	        //	6
	0b00000011,	        //	7
	0b00000111,	        //	8
	0b00001111,	        //	9
	0b00001111,	        //	10
	0b00001111,	        //	11
	0b00001111,	        //	12
	0b00001111,	        //	13
	0b00001111,	        //	14
	0b00001111,	        //	15
	0b00001110,	        //	16
	0b00001100,	        //	17
	0b00001000,	        //	18
	0b00000000,	        //	19
	0b00000000,	        //	20
}
#endif
;

EXTERN    const U8 DT_BOOT_SEG[15]
#ifdef    GLOBAL_VARIABLE_DEFINE
= {
	0b00000000,			//	1
	0b00000001,			//	2
	0b00000011,			//	3
	0b00000111,	        //	4
	0b00001111,	        //	5
	0b00011111,	        //	6
	0b00111111,	        //	7
	0b01111111,	        //	8
	0b00111111,	        //	9
	0b00011111,	        //	10
	0b00001111,	        //	11
	0b00000111,	        //	12
	0b00000011,			//	13
	0b00000001,			//	14
	0b00000000,			//	15
}
#endif
;

EXTERN    const U8 DT_FrontTest[8]						//
#ifdef    GLOBAL_VARIABLE_DEFINE
= {
	0b01111111,			//	1
	0b01111110,			//	2
	0b01111100,	        //	3
	0b01111000,	        //	4
	0b01110000,	        //	5
	0b01100000,	        //	6
	0b01000000,	        //	7
	0b00000000,	        //	8
}
#endif
;

#define Z_TimerContSeg		(20)					//	<200ms/10ms>
#define Z_Timer_SEG_TH		(40)					//	<4s/100ms>
#define Z_Timer_SEG_MONITOR	(70)					//	<7s/100ms>

#define Z_TimerDefaultCupSize_Set_LEDFlic	(20)	//	�� ������ ����Ʈ ���� �� LED���� Ÿ�̸�	<2s/100ms>

#define Z_TimerSEG_TH_Limit		(50)				//	SEG TH Ÿ�̸� <500ms/10ms>

#define Z_TimerSegTest		(10)

#define Z_TimerErrorHistory	(50)					//	<5s/100ms>

#define Z_TimerColdTempDisplay	(30)				//	<3s/100ms>

#define Z_TimerFlushingDisplay	(180)				//	<1800ms/10ms>

#define Z_TimerColdTankClearDisplay		(200)		//	<2000ms/10ms>
#define Z_TimerFlowSensorTestDisplay	(200)		//	<2000ms/10ms>


#define Z_TimerUVDisplay	(250)				//	<7500ms/10ms> - 천천?�� ?��?��

#define Z_TimerSmartCheckDisplay	(325)			//	25*130ms <3250ms/10ms>

#define Z_TimerAllLockDisplay		(20)				//	<2s/100ms>
#define Z_TimerFlicker				(100)				//	<1000ms/10ms>

#define Z_TimerLineTest_SegUpdate	(20)

#define Z_TimerFOTA_Display					(30)	//	<3s/100ms>

#define Z_TimerMySetFilker			(20)			//	<2s/100ms>

#define Z_TimerCupSize_LEDFlic_forJAPAN_Limit	(20)//	<2s/100ms>


enum {
	enum_SEGMENT,
	enum_LED_EFFLUENT,
	enum_LED_mL,
	enum_LED_FILTER_CHANGE,
	enum_LED_FAUCET,
	enum_LEC_CON,
	enum_LED_1BOTTEL,
	enum_LED_2CUP,
	enum_LED_1CUP,
	enum_LED_HALFCUP,
	enum_LED_DEGREE,
	enum_LED_AMOUNT,
	enum_LED_COLD_BLUE,
	enum_LED_COLD_WHITE,
	enum_LED_COLD,
	enum_LED_PURE,
	enum_LED_HOT,
	enum_LED_HOTLOCK,
	enum_LED_WIFI,
	enum_LED_UV1,
	enum_LED_UV2,
	enum_LED_UV3,
	enum_LED_UV4,
	enum_LED_UV5,
	enum_LED_UV6,
	enum_LED_UV7,
	enum_LED_UV8,
	enum_LED_UV9,
	enum_LED_HOT_BAR_5,
	enum_LED_HOT_BAR_4,
	enum_LED_HOT_BAR_3,
	enum_LED_HOT_BAR_2,
	enum_LED_HOT_BAR_1,		
	enum_LED_PERCET,	
	DisplayNum_Max
};

#define Z_SEGMENT			     (0)
#define Z_LED_EFFLUENT		     (1)
#define Z_LED_mL			     (2)
#define Z_LED_FILTER_CHANGE	     (3)
#define Z_LED_FAUCET			 (4)
#define Z_LED_CON		         (5)
#define Z_LED_1BOTTLE	    	 (6)
#define Z_LED_2CUP			     (7)
#define Z_LED_1CUP			     (8)
#define Z_LED_HALFCUP		     (9)
#define Z_LED_DEGREE		     (10)
#define Z_LED_AMOUNT			 (11)
#define Z_LED_COLD_BLUE		 	 (12)
#define Z_LED_COLD_WHITE		 (13)
#define Z_LED_COLD				 (14)
#define Z_LED_PURE				 (15)
#define Z_LED_HOT                (16)
#define Z_LED_HOTLOCK            (17)
#define Z_LED_WIFI               (18)
#define Z_LED_UV1	             (19)
#define Z_LED_UV2	             (20)
#define Z_LED_UV3	             (21)
#define Z_LED_UV4	             (22)
#define Z_LED_UV5	             (23)
#define Z_LED_UV6	             (24)
#define Z_LED_UV7	             (25)
#define Z_LED_UV8	             (26)
#define Z_LED_UV9	             (27)
#define Z_LED_HOT_BAR_5			 (28)
#define Z_LED_HOT_BAR_4			 (29)
#define Z_LED_HOT_BAR_3		     (30)
#define Z_LED_HOT_BAR_2          (31)
#define Z_LED_HOT_BAR_1          (32)
#define Z_LED_PERCENT          	 (33)


#define Z_TIMER_PAIRING_DISPLAY_CHECK		(1800)
#define Z_TIMER_WIFI_PAIRING_DISPLAY_AFTER_EFF		(50)

#define Z_TIMER_SMPS_FEEDBACK_DISPLAY		(20)
#define Z_TIMER_AD_FEEDBACK_DISPLAY		(30)
/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN BYTE_BIT gu8_SegData[3];			//
	#define SEG_XXO			(gu8_SegData[2].byte)
	#define SEG_XOX			(gu8_SegData[1].byte)
	#define SEG_OXX			(gu8_SegData[0].byte)

EXTERN BYTE_BIT gu8_SegData_Before[3];

EXTERN U8 gu8_TimerContSeg;							//	�������� �� Ÿ�̸�
EXTERN U8 gu8_CounterContSeg;						//	�������� �� ī����

EXTERN U8 gu8_LED_COLD_Before;						//	LED �ü��µ� ���� ����. �����׸��ý� ������ ���� �� �� �ֵ���
EXTERN U16 gu16_Effluent_Hz_forSegDisplay;			//	Seg Display �� (% �� mL ǥ�ø� ���Ͽ� �ʱ� ���������� ����)
EXTERN U16 gu16_Effluent_CupLitter;
EXTERN U16 gu16_Effluent_CupLitter_forSegDisplay;
EXTERN U16 gu16_Effluent_Amount_SegDisplay;			//	���� �� ���� ǥ�ø� ����

EXTERN U8 gu8_Counter_SEG_TH;						//	TH������ ǥ�� ī����
EXTERN U8 gu8_Timer_SEG_TH;							//	TH������ ǥ�� Ÿ�̸�

EXTERN U8 gu8_Counter_SEG_ColdTest;					//	�ð��׽�Ʈ ǥ�� ī����
EXTERN U8 gu8_Timer_SEG_ColdTest;					//	�ð��׽�Ʈ ǥ�� Ÿ�̸�

EXTERN U8 gu8_Counter_SEG_MONITOR;					//	�ÿ��� ����Ƚ�� �� ���ⷮ ǥ�� ī����
EXTERN U8 gu8_Timer_SEG_MONITOR;					//	�ÿ��� ����Ƚ�� �� ���ⷮ ǥ�� Ÿ�̸�

EXTERN U8 gu8_TimerDefaultCupSize_Set_LEDFlic;		//	�� ������ ����Ʈ ���� �� LED���� Ÿ�̸�	<2s/100ms>

EXTERN U8 gu8_TimerSEG_TH_Limit;					//	SEG TH ǥ��Ÿ�̸� (TH�����Ͱ� ������ ���ϱ� ������ 500ms ����) <500ms/10ms>

EXTERN U8 gu8_TimerSegTest;							//	�� ����Ʈ �˻��?
EXTERN U8 gu8_CounterSegTest;						//	�� ����Ʈ �˻��?

EXTERN U8 gu8_TimerErrorHistory;					//	���� �̷� Ÿ�̸�
EXTERN U8 gu8_CounterErrorHistory;					//	���� �̷� ī����

EXTERN U8 gu8_Fade_Select;
EXTERN U8 gu8_ON_DimmingPercent;
EXTERN U8 gu8_DimmingPercent;
EXTERN U8 gu8_DimmingPercent_Low;

EXTERN U8 gu8_TimerColdTempDisplay_forBlue;			//	<3s/100ms>
EXTERN U8 gu8_TimerColdTempDisplay_forWhite;		//	<3s/100ms>

EXTERN U8 gu8_TimerFlushingDisplay;					//	<1800ms/10ms>

EXTERN U8 gu8_Timer_UV_Display;					//	<?ms/10ms>
EXTERN U8 gu8_F_UV_Display;

EXTERN U8 gu8_TimerColdTankClearDisplay;			//	<?ms/10ms>
EXTERN U8 gu8_TimerFlowSensorTestDisplay;

EXTERN U16 gu16_TimerSmartCheckDisplay;				//	<?ms/10ms>

EXTERN U8 gu8_TimerAllLockDisplay;					//	<2s/100ms>

EXTERN U8 F_HotDegreeDisplay;						//	LED �� ǥ�� �÷���

EXTERN U8 gu8_TimerFlicker;							//	<?ms/10ms>

EXTERN U8 gu8_TimerLineTest_SegUpdate;
EXTERN U16 gu16_LineTest_Seg;

EXTERN U8 F_ColdTemp_Display;						//	[0:WHITE] [1:BLUE]

EXTERN U8 F_EffluentLED_OFF;						//	���� LED OFF flag

EXTERN U8 gu8_TimerFOTA_Display;					//	<3s/100ms>
EXTERN U8 F_FOTA_Display;
EXTERN U8 F_FOTA_Display_forWIFI_LED_ONOFF;\

EXTERN U8 gu8_TimerMySetFilker;						//	<2s/100ms>

EXTERN U8 gu8_TimerCupSize_LEDFlic_forJAPAN_Limit;	//	<2s/100ms>

EXTERN Display_Control DisplayControl_Data[DisplayNum_Max]
#ifdef    GLOBAL_VARIABLE_DEFINE
= {
	{Z_SEGMENT,			 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_EFFLUENT,		0,	0,	0,	0,	0,	0,	0},
	{Z_LED_mL,			 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_FILTER_CHANGE,	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_FAUCET,			0,	0,	0,	0,	0,	0,	0},
	{Z_LED_CON,		 		0,	0,	0,	0,	0,	0,	0},	
	{Z_LED_1BOTTLE,		 	0,	0,	0,	0,	0,	0,	0},	
	{Z_LED_2CUP,		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_1CUP,	 		0,	0,	0,	0,	0,	0,	0},
	{Z_LED_HALFCUP,			0,	0,	0,	0,	0,	0,	0},
	{Z_LED_DEGREE,		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_AMOUNT,		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_COLD_BLUE,		0,	0,	0,	0,	0,	0,	0},
	{Z_LED_COLD_WHITE,	 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_COLD,			0,	0,	0,	0,	0,	0,	0},
	{Z_LED_PURE,			0,	0,	0,	0,	0,	0,	0},
	{Z_LED_HOT,           	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_HOTLOCK,       	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_WIFI, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV1, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV2, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV3, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV4, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV5, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV6, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV7, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV8, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_UV9, 		 	0,	0,	0,	0,	0,	0,	0},
	{Z_LED_HOT_BAR_5,		0,	0,	0,	0,	0,	0,	0},
	{Z_LED_HOT_BAR_4,		0,	0,	0,	0,	0,	0,	0},
	{Z_LED_HOT_BAR_3,		0,	0,	0,	0,	0,	0,	0},
	{Z_LED_HOT_BAR_2,		0,	0,	0,	0,	0,	0,	0},
	{Z_LED_HOT_BAR_1,		0,	0,	0,	0,	0,	0,	0},
	{Z_LED_PERCENT,			0,	0,	0,	0,	0,	0,	0},		
}
#endif
;


EXTERN U32 gu32_Display_PreHeat_Percent;			//	���� ǥ�� �ۼ�Ʈ Data ��

EXTERN U8 gu8_TimerColdTankClearDisplay;			//	�ü� ��ũ ���? ���� ǥ�� Ÿ�̸�

EXTERN U8 gu8_UV_Step_Before;

EXTERN U8 gu8_Timer_Faucet_Set_Mode_Display;

EXTERN U8 gu8_Timer_AdFeedback_Loading;
EXTERN U8 gu8_Timer_Smps_Feedback_Display;

EXTERN U16 gu16_Timer_Pairing_Display_check;
EXTERN U8 gu8_Timer_Wifi_Pairing_Display_AfterEff;
/*==============================================================================
 function Definition
 ==============================================================================*/
void Display_Initialize(void);
void DisplayControl(void);

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================
