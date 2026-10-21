    
/*******************************************************************************
&Description :
    A1080 ~ A108x
    A1090 ~ A109x
    Part Table

&History : ssg@coway.com 2024.10.04 update

*******************************************************************************/

/******************************************************************************/
/***** Header *****************************************************************/
/******************************************************************************/
#include "WIFI_A108x_A109x_PartList.h"

/******************************************************************************/
/***** User Header ************************************************************/
/******************************************************************************/
#include "include/_type_define.h"
#include "operation.h"
#include "eeprom.h"
#include "pure.h"
#include "adc.h"
#include "cold.h"
#include "display.h"
#include "input.h"
#include "_fix_ram.h"
#include "timer.h"
#include "_port_define.h"
#include "Voice_NXD1005.h"
#include "smartcheck.h"
#include "error.h"
/******************************************************************************/
/***** User Function **********************************************************/
/******************************************************************************/

/******************************************************************************/
/***** Table ******************************************************************/
/******************************************************************************/
/* Protocol List */
static const WifiNormalList_T WifiPartProtocolList[] =
{   /*  API ID        */
    {   WIFI_PART_0001_VALVE_NOS,               TYPE_UNSIGNED   },
    {   WIFI_PART_0002_VALVE_HOT_OUT,           TYPE_UNSIGNED   },
    {   WIFI_PART_0003_VALVE_PURE_OUT,          TYPE_UNSIGNED   },
    {   WIFI_PART_0004_VALVE_COLD_OUT,          TYPE_UNSIGNED   },
    {   WIFI_PART_0009_VALVE_HOT_IN,            TYPE_UNSIGNED   },
    {   WIFI_PART_000C_VALVE_COLD_IN,           TYPE_UNSIGNED   },
    {   WIFI_PART_0202_COLD_TEM,                TYPE_UNSIGNED   },
    {   WIFI_PART_0203_COLD_TEM_TEMP,                TYPE_UNSIGNED   },
    {   WIFI_PART_0204_COLD_FAN,                TYPE_UNSIGNED   },
    {   WIFI_PART_0206_COLD_TEMP_1,                TYPE_UNSIGNED   },
    {   WIFI_PART_0208_COLD_ROOM_TEMP,                TYPE_UNSIGNED   },

    {   WIFI_PART_0302_HOT_INSTANT_HEATER_1,                TYPE_UNSIGNED   },
    {   WIFI_PART_0303_HOT_INSTANT_HEATER_2,                TYPE_UNSIGNED   },
    {   WIFI_PART_0304_HOT_FLOW_MOTOR,                TYPE_UNSIGNED   },
    {   WIFI_PART_0305_HOT_TEMP_IN,                TYPE_UNSIGNED   },
    {   WIFI_PART_0306_HOT_TEMP_OUT,                TYPE_UNSIGNED   },
    {   WIFI_PART_0307_HOT_HEATER_TEMP,                TYPE_UNSIGNED   },

    {   WIFI_PART_0402_SENSOR_LEAK,                TYPE_UNSIGNED   },
    {   WIFI_PART_0403_SENSOR_FLOW,                TYPE_UNSIGNED   },
    {   WIFI_PART_0405_SENSOR_FILTER_REED,                TYPE_UNSIGNED   },
    {   WIFI_PART_0406_SENSOR_FILTER_SW_1,                TYPE_UNSIGNED   },
    {   WIFI_PART_040B_SENSOR_WATER_COURSE_REED,                TYPE_UNSIGNED   },
	{   WIFI_PART_0418_FAUCET_MOTOR,                TYPE_UNSIGNED   },
	// {   WIFI_PART_0419_FAUCET_DOWN_REED_SW,                TYPE_UNSIGNED   },
	{   WIFI_PART_041A_FAUCET_CUP_DETECTION_MICRO_SW,                TYPE_UNSIGNED   },
	{   WIFI_PART_041B_SMPS_VOLTAGE,                TYPE_UNSIGNED   },
	{   WIFI_PART_041D_CUP_MICRO_SW_LONG_DETECTION,                TYPE_UNSIGNED   },
    {   WIFI_PART_0501_STER_UV_FAUCET,                TYPE_UNSIGNED   },
    // {   WIFI_PART_0703_FAUCET_MOTOR,                TYPE_UNSIGNED   },

    // {   WIFI_PART_0206_COLD_TEMP_1,             TYPE_UNSIGNED   },
    // {   WIFI_PART_0208_COLD_ROOM_TEMP,          TYPE_UNSIGNED   },
    // {   WIFI_PART_020B_COLD_TARGET_TEMP_TIME,   TYPE_UNSIGNED   },

    // {   WIFI_PART_0301_HOT_TEMP,                TYPE_UNSIGNED   },
    // {   WIFI_PART_0308_HOT_TARGET_TEMP_TIME,    TYPE_UNSIGNED   },

    // {   WIFI_PART_0402_SENSOR_LEAK,             TYPE_UNSIGNED   },
    // {   WIFI_PART_0409_SENSOR_TANK_REED,        TYPE_UNSIGNED   },

    // {   WIFI_PART_0501_STER_UV_FAUCET,          TYPE_UNSIGNED   },
    // {   WIFI_PART_0502_STER_UV_FAUCET_ICE,      TYPE_UNSIGNED   },
    // {   WIFI_PART_0503_STER_UV_ICE_TANK1,       TYPE_UNSIGNED   },

    // {   WIFI_PART_0800_ICE_PURE_TEMP,           TYPE_UNSIGNED   },
    // {   WIFI_PART_0801_ICE_FULL_SENSOR,         TYPE_UNSIGNED   },
    // {   WIFI_PART_0802_ICE_SWING_BAR,           TYPE_UNSIGNED   },
    // {   WIFI_PART_0805_ICE_TRAY_SENSING_SW,     TYPE_UNSIGNED   },
    // {   WIFI_PART_0807_ICE_DOOR_STEPMOTOR,      TYPE_UNSIGNED   },
    // {   WIFI_PART_0808_ICE_COURSE_CHANGE_VV,    TYPE_UNSIGNED   },
    // {   WIFI_PART_080A_ICE_DRAIN_PUMP,          TYPE_UNSIGNED   },
    // {   WIFI_PART_080E_ICE_DRAIN_ERROR_E60,     TYPE_UNSIGNED   },
    // {   WIFI_PART_080F_ICE_TRAY_ERROR_E61,      TYPE_UNSIGNED   },
    // {   WIFI_PART_0810_ICE_TRAY_ERROR_E62,      TYPE_UNSIGNED   },
    // {   WIFI_PART_0811_ICE_TRAY_ERROR_E63,      TYPE_UNSIGNED   }
};


static const WifiNormalList_T WifiPartProtocolList_CP[] =
{   /*  API ID        */
    {   WIFI_PART_0001_VALVE_NOS,               TYPE_UNSIGNED   },
    {   WIFI_PART_0003_VALVE_PURE_OUT,          TYPE_UNSIGNED   },
    {   WIFI_PART_0004_VALVE_COLD_OUT,          TYPE_UNSIGNED   },
    {   WIFI_PART_000C_VALVE_COLD_IN,           TYPE_UNSIGNED   },
    {   WIFI_PART_0202_COLD_TEM,                TYPE_UNSIGNED   },
    {   WIFI_PART_0203_COLD_TEM_TEMP,                TYPE_UNSIGNED   },
    {   WIFI_PART_0204_COLD_FAN,                TYPE_UNSIGNED   },
    {   WIFI_PART_0206_COLD_TEMP_1,                TYPE_UNSIGNED   },
    {   WIFI_PART_0208_COLD_ROOM_TEMP,                TYPE_UNSIGNED   },
    {   WIFI_PART_0402_SENSOR_LEAK,                TYPE_UNSIGNED   },
    {   WIFI_PART_0403_SENSOR_FLOW,                TYPE_UNSIGNED   },
    {   WIFI_PART_0405_SENSOR_FILTER_REED,                TYPE_UNSIGNED   },
    {   WIFI_PART_0406_SENSOR_FILTER_SW_1,                TYPE_UNSIGNED   },
    {   WIFI_PART_040B_SENSOR_WATER_COURSE_REED,                TYPE_UNSIGNED   },
	{   WIFI_PART_0418_FAUCET_MOTOR,                TYPE_UNSIGNED   },
	{   WIFI_PART_041A_FAUCET_CUP_DETECTION_MICRO_SW,                TYPE_UNSIGNED   },
	{   WIFI_PART_041B_SMPS_VOLTAGE,                TYPE_UNSIGNED   },
	{   WIFI_PART_041D_CUP_MICRO_SW_LONG_DETECTION,                TYPE_UNSIGNED   },
    {   WIFI_PART_0501_STER_UV_FAUCET,                TYPE_UNSIGNED   },
};



#define SZ_PART_EVENT_LIST    (sizeof(WifiPartProtocolList)/sizeof(WifiNormalList_T))
#define SZ_PART_EVENT_LIST_CP    (sizeof(WifiPartProtocolList_CP)/sizeof(WifiNormalList_T))

void* GetWifiPartDataEventList ( void )
{
    if (IsUserModelType() == Model_0)
    {
        return WifiPartProtocolList;
    }
    else
    {
		return WifiPartProtocolList_CP;
    }
}

U16 GetWifiPartEventListSize ( void )
{
    if (IsUserModelType() == Model_0)
    {
        return SZ_PART_EVENT_LIST;
    }
    else
    {
		return SZ_PART_EVENT_LIST_CP;
    }
}

/* [User Part Data] Product -> Server */
U16 GetUserSystemPart ( U16 mu16Part )
{
    U16 mu16Data = 9999U;
    U8 mu8_OPENSHORT_Error = 0;
	U16 mu16_min = 0;
	U16 mu16_max = 0;
	U16 mu16_TemValue = 0;
	U16 mu16_SMPS_Voltage_Value = 0;
	U8 mu8_i = 0;
	
    switch ( mu16Part )
    {
    	case WIFI_PART_0001_VALVE_NOS:
    		mu16Data = gu16_SmartCheck_Result_1stNos_VV_mA;
    		gu16_SmartCheck_Result_1stNos_VV_mA = 0xFFFFU;
    		break;
    	case WIFI_PART_0002_VALVE_HOT_OUT:
    		if (gu8_ModelType_forCHP == MODEL_CHP)
    		{
    			mu16Data = gu16_SmartCheck_Result_HotOut_VV_mA;
    		}
    		else
    		{
    			mu16Data = 0xFFFFU;
    		}
    		gu16_SmartCheck_Result_HotOut_VV_mA = 0xFFFFU;
    		break;
    	case WIFI_PART_0003_VALVE_PURE_OUT:
    		mu16Data = gu16_SmartCheck_Result_Pure_VV_mA;
    		gu16_SmartCheck_Result_Pure_VV_mA = 0xFFFFU;
    		break;
    	case WIFI_PART_0004_VALVE_COLD_OUT:
    		mu16Data = gu16_SmartCheck_Result_ColdOut_VV_mA;
    		gu16_SmartCheck_Result_ColdOut_VV_mA = 0xFFFFU;
    		break;
    	case WIFI_PART_0009_VALVE_HOT_IN:
    		if (gu8_ModelType_forCHP == MODEL_CHP)
    		{
    			mu16Data = gu16_SmartCheck_Result_HotIn_VV_mA;
    		}
    		else
    		{
    			mu16Data = 0xFFFFU;
    		}
    		gu16_SmartCheck_Result_HotIn_VV_mA = 0xFFFFU;
    		break;
    	case WIFI_PART_000C_VALVE_COLD_IN:
    		mu16Data = gu16_SmartCheck_Result_ColdIn_VV_mA;
    		gu16_SmartCheck_Result_ColdIn_VV_mA = 0xFFFFU;
    		break;
    	case WIFI_PART_0202_COLD_TEM:
			
			if(gu8_F_SmartCheck_Tem_Check == SET)
			{
				mu16Data = gu16_SmartCheck_Result_TEM_mA;
				gu16_SmartCheck_Result_TEM_mA = 0xFFFFU;
			}
			else
			{
				mu16Data = calculate_tem_current(ADC_RESULT_TEM_FB);
			}

    		break;
    	case WIFI_PART_0203_COLD_TEM_TEMP:
    		mu8_OPENSHORT_Error = TH_Open_Short_Check(gi16_HeatSinkSensor.TH_ADC_AVERAGE);     //	OPEN SHORT C<E)
    		if (mu8_OPENSHORT_Error != 0)
    		{
    			mu16Data = 0x00ffU;
    		}
    		else if (gi16_HeatSinkSensor.DEGREE >= 0)
    		{
    			mu16Data = gi16_HeatSinkSensor.DEGREE / 10;
    		}
    		else
    		{
    			mu16Data = 0;
    		}
    		break;
    	case WIFI_PART_0204_COLD_FAN:
    		mu16Data = gu16_SmartCheck_Result_Fan_mA;
    		gu16_SmartCheck_Result_Fan_mA = 0xFFFFU;
    		break;
    	case WIFI_PART_0206_COLD_TEMP_1:
    		mu8_OPENSHORT_Error = TH_Open_Short_Check(gi16_ColdSensor.TH_ADC_AVERAGE);     //	OPEN SHORT C<E)
    		if (mu8_OPENSHORT_Error != 0)
    		{
    			mu16Data = 0x00ffU;
    		}
    		else if (gi16_ColdSensor.DEGREE >= 0)
    		{
    			mu16Data = gi16_ColdSensor.DEGREE / 10;
    		}
    		else
    		{
    			mu16Data = 0;
    		}
    		break;
    	case WIFI_PART_0208_COLD_ROOM_TEMP:
    		mu8_OPENSHORT_Error = TH_Open_Short_Check(gi16_OutDoorAirSensor.TH_ADC_AVERAGE);     //	OPEN SHORT C<E)
    		if (mu8_OPENSHORT_Error != 0)
    		{
    			mu16Data = 0x00ffU;
    		}
    		else if (gi16_OutDoorAirSensor.DEGREE >= 0)
    		{
    			mu16Data = gi16_OutDoorAirSensor.DEGREE / 10;
    		}
    		else
    		{
    			mu16Data = 0;
    		}
    		break;
    	case WIFI_PART_0302_HOT_INSTANT_HEATER_1:
			if(F_SmartCheck_Data == SET)										//@004
			{	                                                                //@004
				mu16Data = gu16_SmartCheck_Result_HeaterRelay_ADC;		        //@004
			}                                                                   //@004
			else if(gu8_F_HeaterRelayFirst_Check == SET)
			{
    			mu16Data = gu16_SmartCheck_Result_HeaterRelay_ADC / 2;
			}
			else
			{
				mu16Data = 0xFFFFU;
			}
    		// gu16_SmartCheck_Result_HeaterRelay_ADC = 0xFFFFU;
    		break;
    	case WIFI_PART_0303_HOT_INSTANT_HEATER_2:

			if(F_SmartCheck_Data == SET)										//@004
			{	                                                                //@004
				mu16Data = gu16_SmartCheck_Result_HeaterTriac_ADC;		        //@004
			}                                                                   //@004
			else if(gu8_F_HeaterTriacFirst_Check == SET)
			{
    			mu16Data = gu16_SmartCheck_Result_HeaterTriac_ADC / 2;
			}
			else
			{
				mu16Data = 0xFFFFU;;
			}
    		// gu16_SmartCheck_Result_HeaterTriac_ADC = 0xFFFFU;
    	    break;
    	case WIFI_PART_0304_HOT_FLOW_MOTOR:
    		mu16Data = gu16_SmartCheck_Result_SteppingMotor_mA;
    		gu16_SmartCheck_Result_SteppingMotor_mA = 0xFFFFU;
    		break;
    	case WIFI_PART_0305_HOT_TEMP_IN:
    		mu8_OPENSHORT_Error = TH_Open_Short_Check(gi16_HotInSensor.TH_ADC_AVERAGE);     //	OPEN SHORT C<E)
    		if (mu8_OPENSHORT_Error != 0)
    		{
    			mu16Data = 0x00ffU;
    		}
    		else if (gi16_HotInSensor.DEGREE >= 0)
    		{
    			mu16Data = gi16_HotInSensor.DEGREE / 10;
    		}
    		else
    		{
    			mu16Data = 0;
    		}
    		break;
    	case WIFI_PART_0306_HOT_TEMP_OUT:
    		mu8_OPENSHORT_Error = TH_Open_Short_Check(gi16_HotOutSensor.TH_ADC_AVERAGE);     //	OPEN SHORT C<E)
    		if (mu8_OPENSHORT_Error != 0)
    		{
    			mu16Data = 0x00ffU;
    		}
    		else if (gi16_HotOutSensor.DEGREE >= 0)
    		{
    			mu16Data = gi16_HotOutSensor.DEGREE / 10;
    		}
    		else
    		{
    			mu16Data = 0;
    		}
    		break;
    	case WIFI_PART_0307_HOT_HEATER_TEMP:
    		mu8_OPENSHORT_Error = TH_Open_Short_Check(gi16_HeaterSensor.TH_ADC_AVERAGE);     //	OPEN SHORT C<E)
    		if (mu8_OPENSHORT_Error != 0)
    		{
    			mu16Data = 0x00ffU;
    		}
    		else if (gi16_HeaterSensor.DEGREE >= 0)
    		{
    			mu16Data = gi16_HeaterSensor.DEGREE / 10;
    		}
    		else
    		{
    			mu16Data = 0;
    		}
    		break;
    	case WIFI_PART_0402_SENSOR_LEAK:
    		if (ADC_RESULT_LEAKSENSOR > Z_LeakSensor_Error)	//	4)<v0(Av =C
    		{
    			mu16Data = 1;
    		}
    		else
    		{
    			mu16Data = 0;
    		}
    		break;
    	case WIFI_PART_0403_SENSOR_FLOW:
    		mu16Data = gu16_SmartCheck_Result_FlowMeter;
    		gu16_SmartCheck_Result_FlowMeter = 0xFFFFU;
    		break;
    	case WIFI_PART_0405_SENSOR_FILTER_REED:
    		mu16Data = !INPUT_REED_SW_COVER;
    		break;
    	case WIFI_PART_0406_SENSOR_FILTER_SW_1:
    		mu16Data = !INPUT_REED_SW_FILTER;
    		break;
    	case WIFI_PART_040B_SENSOR_WATER_COURSE_REED:
    		mu16Data = !INPUT_REED_SW_FAUCET;
    		break;

		case WIFI_PART_0418_FAUCET_MOTOR:
			if(gu16_SmartCheck_Result_Faucet_ReedDetected == 2)
			{
				mu16Data = 0;
			}
			else if(gu16_SmartCheck_Result_Faucet_ReedDetected < 2)
			{
				mu16Data = 1;
			}
			else
			{
				mu16Data = gu16_SmartCheck_Result_Faucet_ReedDetected;
			}
			gu16_SmartCheck_Result_Faucet_ReedDetected = 0xFFFFU;

			break;
		
		case WIFI_PART_041A_FAUCET_CUP_DETECTION_MICRO_SW:
			if(gu16_SmartCheck_Result_CupDetection_MicroSW == 0)
			{
				mu16Data = 1;
			}
			else if(gu16_SmartCheck_Result_CupDetection_MicroSW == 1)
			{
				mu16Data = 0;
			}
			else 
			{
				mu16Data = gu16_SmartCheck_Result_CupDetection_MicroSW;
			}
			gu16_SmartCheck_Result_CupDetection_MicroSW = 0xFFFFU;
			break;
		
		case WIFI_PART_041B_SMPS_VOLTAGE:


			//@004 if(F_SmartCheck_Complete_2 == SET)
			if(F_SmartCheck_Data == SET)		//@004
			{
				mu16_TemValue = gu16_SmartCheck_Result_TEM__mA_for_Wifi_041B;
				gu16_SmartCheck_Result_TEM__mA_for_Wifi_041B = 0xFFFFU;

				mu16_SMPS_Voltage_Value = gu16_SmartCheck_Result_SMPS_Voltage_Feedback;
				gu16_SmartCheck_Result_SMPS_Voltage_Feedback = 0xFFFFU;				
			}
			// else if(gu8_f_ad_feedback_mode == SET)
			// {
			// 	mu16_TemValue = gu16_ad_feedback_mode_tem_mA_Result;
			// 	mu16_SMPS_Voltage_Value = gu16_ad_feedback_mode_smps_voltage_Result;
			// }
			else
			{		
				mu16_TemValue = gu16_TEM_mA_Result;		
				mu16_SMPS_Voltage_Value = gu16_SMPS_Voltage_Feedback_Result;	

				if(gu8_F_AlwaysDiagnosis_forWifi == CLEAR)
				{
					mu8_i = SET;
				}
			}

			if(mu8_i == 0)
			{
				if((F_ColdOff == SET)
				//@004 && (F_SmartCheck_Complete_2 != SET))
				&& (F_SmartCheck_Data != SET))		//@004
				{
					mu16Data = 0xFFFFU;
				}
				else
				{
					if (check_smps_voltage_range(mu16_SMPS_Voltage_Value) != 0)
					{
						mu16Data = 1;
					}					
					// TEM 값 범위 확인
					else if (check_tem_current_range(mu16_TemValue) != 0)
					{
						mu16Data = 2;
					}
					else 
					{
						mu16Data = 0;
					}						
				}			
			}
			else
			{
				mu16Data = 0xFFFFU;
			}
	

			gu8_F_SmartCheck_Tem_Check = CLEAR;

			break;
		case WIFI_PART_041D_CUP_MICRO_SW_LONG_DETECTION:
			if(gu8_F_MicroSW_LongDetection_1h == SET)
			{
				mu16Data = 1;
			}
			else
			{
				mu16Data = 0;
			}
			break;
    	case WIFI_PART_0501_STER_UV_FAUCET:
			//@004 if(F_SmartCheck_Complete_2 == SET)
			if(F_SmartCheck_Data == SET)		//@004
			{
				F_SmartCheck_Data = CLEAR;		//@004
				mu16Data = gu16_SmartCheck_Result_UV_mA;
				gu16_SmartCheck_Result_UV_mA = 0xFFFFU;
			}
			else 
			{		
				if(gu8_F_UV_First_On == SET)
				{
					mu16Data = gu16_UV_mA_Result;
				}
				else
				{
					mu16Data = 0xFFFFU;
				}
			}
    		break;

		// case WIFI_PART_0703_FAUCET_MOTOR:	
		// 	if(gu16_SmartCheck_Result_Faucet_ReedDetected == 2)
		// 	{
		// 		mu16Data = 0;
		// 	}
		// 	else if(gu16_SmartCheck_Result_Faucet_ReedDetected < 2)
		// 	{
		// 		mu16Data = 1;
		// 	}
		// 	else
		// 	{
		// 		mu16Data = gu16_SmartCheck_Result_Faucet_ReedDetected;
		// 	}
		// 	gu16_SmartCheck_Result_Faucet_ReedDetected = 0xFFFFU;

		// 	break;
        default:
        	mu16Data = 0xFFFFU;
        	break;
    }

    return mu16Data;
}

/* [A1091] [Diagnosis Result]  Server -> Product */
/* SetWifiSendStatus( TX_DATA, WIFI_TX_RQST_INFO_DRR );  A2010.0029 DiagnosisResultRequest  */ 
void SetUserSystemDiagnosis ( U16 mu16DR, I16 mData ) // [1]: Error 있음, [-100] : 이상1
{
	#define DiagnosisError 	 (1)
	#define DiagnosisAbnormal1 (-100)
	#define DiagnosisAbnormal2 (-200)

	switch ( mu16DR )
    {
		// case 0x0001:
		// 	if (mData == DiagnosisError)
		// 	{

		// 	}
        // 	else if (mData == DiagnosisAbnormal1)
		// 	{

		// 	}
		// 	break;


		default:

        break;
	}
}