#ifndef _PORT_DEFINE_H_
#define _PORT_DEFINE_H_

//*************************
//*    PORT DEFINITION    *
//*************************

// EEPROM
#define P_EEPROM_SCL			(P6.0)    			//	I2C CLK - EEPROM, RTC
#define P_EEPROM_SDA			(P6.1)    			//	I2C DAT - EEPROM, RTC
#define P_EEPROM_SCL_PIN_MODE	(PM6.0)   			//	I2C CLK Port IO Mode Select Register
#define P_EEPROM_SDA_PIN_MODE	(PM6.1)   			//	I2C DAT Port IO Mode Select Register

//	Valve
#define P_NOS_V             (P5.1)  				//	NOS 밸브 (HIGH:Close / Low:Open (Normal Open))
#define P_FEED_COLD_IN_V    (P5.3)  				//
#define P_FEED_COLD_OUT_V   (P5.0)  				//
#define P_FEED_HOTOUT_V    	(P3.0)  				//	온수 추출 피드 밸브 (LOW:온수 추출 OFF / HIGH:온수 추출)
#define P_FEED_HOTIN_V      (P0.5)  				//	온수 입수 피드 밸브
#define P_FEED_PURE_V       (P5.2)  				//	정수 피드 밸브

//	Stepping Motor
#define P_STEPMOTOR1		(P0.6)
#define P_STEPMOTOR2		(P7.0)
#define P_STEPMOTOR3		(P7.1)
#define P_STEPMOTOR4		(P7.2)

//	Heater5
#define P_HEATER_RELAY	    (P4.3) 					//	Heater 2
#define P_HEATER_TRIAC		(P4.2) 					//	Heater 1
#define P_HEATER_PWM_TDR	(TDR04)

//	Cooler
#define P_TEM_PWM 			(P3.1)  				//	TEM PWM (TO07)
#define P_TEM_PWM_TDR		(TDR03)
#define P_TEM_12V_ONOFF     (P7.3)
#define P_TEM_24V_ONOFF         (P7.5)
#define P_STANDBY_ONOFF     (P7.4)



#define P_FAN_18V			(P1.1)					//	18V 21V 둘다 ON하면 18V
#define P_FAN_21V			(P1.0)
#ifndef _FAN_CIRCUIT_CHANGE_
#define P_FAN_ONOFF			(P8.0)
#endif
#define P_STANDBY			(P7.4)              

//	Sensor
#define P_REED_SW_COVER		    (P12.3)     
#define P_REED_SW_FILTER	    (P13.7)     
#define P_REED_SW_WATERFLOW	    (P14.7)

#define P_MICRO_SWITCH_FAUCET   (P12.4)
#define P_REED_SW_FAUCET_UP     (P12.2)
#define P_REED_SW_FAUCET_DOWN   (P12.1)



//	Output
#define P_LEAKSENSOR_OFF	(P7.6)  				//	Leakage Sensor
#define P_COLDSENSOR_ON		(P6.2)

//	etc.
#define P_FLOWMETER_TDR		(TDR12)
#define P_BUZZER			(P10.2)

#define P_FCT_Rx			(P14.3)
#define P_FCT_Tx			(P14.4)

#define P_FAUCET_STEPMOTOR1 (P5.4)
#define P_FAUCET_STEPMOTOR2 (P5.5)
#define P_FAUCET_STEPMOTOR3 (P1.7)
#define P_FAUCET_STEPMOTOR4 (P1.6)


#define P_UV        (P11.0)

#define P_WELCOME_LED       (P14.6)

// #define P_MODEL_TYPE_1              (P4.4)
// #define P_MODEL_TYPE_2              (P4.5)


#define P_CHP_0_CP_1                    (P4.1)

    

#endif
