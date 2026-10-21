
/*******************************************************************************
&Description :
    A1020 ~ A102x
    Sensor Table

&History : ssg@coway.com 2024.10.04 update

*******************************************************************************/


#include "WIFI_A102x_SensorList.h"

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
/******************************************************************************/
/***** User Function **********************************************************/
/******************************************************************************/

/******************************************************************************/
/***** Table ******************************************************************/
/******************************************************************************/
/* Protocol List */
static const WifiNormalList_T WifiSensorProtocolList[] =
{   /*  API ID                          Data Type     */
    {   WIFI_SENSOR_0001_COLD_TEMP,    TYPE_SIGNED      },
    // {   WIFI_SENSOR_0002_HOT_TEMP,     TYPE_SIGNED      },
    // {   WIFI_SENSOR_0003_WATER_TEMP,   TYPE_SIGNED      },
    {   WIFI_SENSOR_0004_OUT_TEMP,     TYPE_SIGNED      },
    {   WIFI_SENSOR_000E_WATT_DATA,    TYPE_SENSOR_WATT },
    // {   WIFI_SENSOR_000F_COMP_DATA,    TYPE_UNSIGNED    },
    {   WIFI_SENSOR_0010_TEM_TEMP,    TYPE_SIGNED    },
    // {   WIFI_SENSOR_0014_HEATER_DATA,  TYPE_UNSIGNED    },
};

#define SZ_SENSOR_EVENT_LIST    (sizeof(WifiSensorProtocolList)/sizeof(WifiNormalList_T))

void* GetWifiSensorDataEventList ( void )
{
    if (IsUserModelType() == Model_0)
    {
        return WifiSensorProtocolList;
    }
    else
    {
        return WifiSensorProtocolList;
    }
}

U16 GetWifiSensorEventListSize ( void )
{
    if (IsUserModelType() == Model_0)
    {
        return SZ_SENSOR_EVENT_LIST;
    }
    else
    {
        return SZ_SENSOR_EVENT_LIST;
    }
}

/* [User Sensor Data] Product -> Server */
I16 GetUserSystemSensor ( U16 mu16Sen )
{
    I16 mi16Data = 0;

    switch ( mu16Sen )
    {
        case WIFI_SENSOR_0001_COLD_TEMP : //  -127 ~ 127
        	mi16Data = gi16_ColdSensor.DEGREE / 10;
			if (mi16Data > 127)
			{
				mi16Data = 127;
			}
			else if (mi16Data < -127)
			{
				mi16Data = -127;
			}
			else
			{

			}
        break;

        case WIFI_SENSOR_0004_OUT_TEMP : //  -127 ~ 127
        	mi16Data = gi16_OutDoorAirSensor.DEGREE / 10;
			if (mi16Data > 127)
			{
				mi16Data = 127;
			}
			else if (mi16Data < -127)
			{
				mi16Data = -127;
			}
			else
			{

			}
        break;

        case WIFI_SENSOR_000E_WATT_DATA : // 0.01~250.00 (ex -> 1.78 = 178)
        	mi16Data = (U16)gu32_Watt_per_Min_Result;				//	[1/100Wh] (!X 1009h<v7N ?C7A>_ 1@S. 100 !f 1Wh)
        	gu32_Watt_per_Min_Result = 0;
            if ( mi16Data >= 3000U )
            {
                mi16Data = 3000U;
            }
        break;

        case WIFI_SENSOR_0010_TEM_TEMP:	//  -127 ~ 127
        	mi16Data = gi16_HeatSinkSensor.DEGREE / 10;
			if (mi16Data > 127)
			{
				mi16Data = 127;
			}
			else if (mi16Data < -127)
			{
				mi16Data = -127;
			}
			else
			{

			}
        	break;
        default:
          mi16Data = 0;
        break;
    }
    return mi16Data;
}

/* User Data Clear (Called when wifi is not connected) */
void ClearUserSystemDataA1020 ( void )
{

}