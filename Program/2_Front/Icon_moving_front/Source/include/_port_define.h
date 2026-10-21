#ifndef _PORT_DEFINE_H_
#define _PORT_DEFINE_H_

//*************************
//*    PORT DEFINITION    *
//*************************
//	Matrix
#define P_LED_SOURCE1		(P1.7)
#define P_LED_SOURCE2		(P1.2)
#define P_LED_SOURCE3		(P1.0)
#define P_LED_SOURCE4		(P10.1)
#define P_LED_SOURCE5		(P1.1)
#define P_LED_SOURCE6		(P1.5)
#define P_LED_SOURCE7		(P1.6)

#define P_LED_SINK1  		(P5.7)
#define P_LED_SINK2  		(P5.6)
#define P_LED_SINK3  		(P5.5)

//	LED
#define P_LED_EFFLUENT		(P7.6)

#define P_LED_PURE			(P4.5)
#define P_LED_HOT			(P4.6)
#define P_LED_HOTLOCK		(P4.7)
#define P_LED_COLD_BLUE		(P4.2)
#define P_LED_COLD_WHITE	(P4.3)
#define P_LED_COLD			(P4.4)

#define P_LED_AMOUNT		(P4.1)

#define P_LED_HALFCUP       (P6.5)
#define P_LED_1CUP		    (P6.6)
#define P_LED_2CUP			(P6.7)
#define P_LED_1BOTTLE       (P7.7)
#define P_LED_INFINITY      (P14.3)
#define P_LED_mL			(P14.2)


#define P_LED_TEMP1         (P13.0)
#define P_LED_TEMP2         (P10.2)
#define P_LED_TEMP3         (P0.0)
#define P_LED_TEMP4         (P14.5)
#define P_LED_TEMP5         (P14.4)
#define P_LED_DEGREE		(P14.0)

#define P_LED_PERCENT       (P14.1)


#define P_LED_FILTER_CHANGE	(P11.1)
#define P_LED_FAUCET		(P11.0)


#define P_LED_UV_LEFT_1    (P8.5)
#define P_LED_UV_LEFT_2    (P8.4)
#define P_LED_UV_LEFT_3    (P8.6)
#define P_LED_UV_CENTER_1   (P8.7)
#define P_LED_UV_CENTER_2   (P3.0)
#define P_LED_UV_CENTER_3   (P8.3)
#define P_LED_UV_RIGHT_1    (P8.2)
#define P_LED_UV_RIGHT_2    (P8.1)
#define P_LED_UV_RIGHT_3    (P8.0)



#define P_LED_WIFI			(P14.6)


//	INPUT
#define P_KEY_HOT			(P12.1)
#define P_KEY_PURE			(P12.2)
#define P_KEY_COLD			(P13.7)
#define P_KEY_AMOUNT		(P12.4)
#define P_KEY_EFFLUENT		(P3.1)

#define P_MODEL				(P2.1)

//	OUTPUT
#define P_UV1				(P13.0)

//	Main Communication
#define P_TxD				(P1.3)
#define P_RxD				(P1.4)



//  음성
//	Voice
#define P_VOICE_RESET		(P0.1)
#define P_VOICE_CSB			(P0.2)
#define P_VOICE_DATA		(P0.3)
#define P_VOICE_CLK			(P0.4)





#endif
