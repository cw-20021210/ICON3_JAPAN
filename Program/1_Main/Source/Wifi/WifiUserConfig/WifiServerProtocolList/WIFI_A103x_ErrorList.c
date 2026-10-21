
/*******************************************************************************
&Description :
    A1030 ~ A103x
    Error Protocol Table

&History : ssg@coway.com 2024.10.04 update

*******************************************************************************/

#include "WIFI_A103x_ErrorList.h"
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
/* Event List */
U16 WifiErrorPreVal[USER_ERROR_DATA_MAX_SIZE] = {0};      // Error Protocol count

static const WifiTxFuncEventList_T WifiErrorProtocolList[] =
{   /*  API ID                                   DATA_TYPE                PreVal(Initial)                         EnventForm     */
    // {   WIFI_ERROR_0001_LOW_LEVEL,              TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_0002_HIGH_LEVEL,             TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_0003_COMPLEX_LEVEL,          TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_0004_FEED_VALVE,             TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },

    {   WIFI_ERROR_0006_HOTIN_TEMP,                 TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_0007_HOTOUT_TEMP,                TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_0008_COLD_TEMP,                  TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_0009_NATURAL_TEMP,               TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_000E_DRAIN_PUMP,             TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },

    {   WIFI_ERROR_0018_TEM_TEMP,                 TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_0019_STOP_WATER,                TYPE_UNUSED,             (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_001A_TEM_OPERATION,                  TYPE_UNUSED,        (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_001B_STOP_HOTWATER,               TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_001D_LEAK_SENSOR,               TYPE_UNUSED,               (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_001E_HOT_OVER,               TYPE_UNUSED,               (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_001F_HEATER_SENSOR,               TYPE_UNUSED,               (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },    
    {   WIFI_ERROR_0038_UV_EXTRACT,                 TYPE_UNUSED,               (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_001D_LEAK_SENSOR,            TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_0020_ROOM_TEMP,              TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_0021_MICRO_SW_DETECT,        TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_0022_MICRO_SW_MOVE,          TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_0026_HOT_TANK_TEMP,          TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_003B_MICRO_SW_MOVE2,         TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    // {   WIFI_ERROR_003C_ROOM_TEMP_OH,           TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
};

static const WifiTxFuncEventList_T WifiErrorProtocolList_CP[] =
{   /*  API ID                                   DATA_TYPE                PreVal(Initial)                         EnventForm     */
    {   WIFI_ERROR_0008_COLD_TEMP,                  TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_0009_NATURAL_TEMP,               TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_0018_TEM_TEMP,                 TYPE_UNUSED,           (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_0019_STOP_WATER,                TYPE_UNUSED,             (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_001A_TEM_OPERATION,                  TYPE_UNUSED,        (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_001D_LEAK_SENSOR,               TYPE_UNUSED,               (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    {   WIFI_ERROR_0038_UV_EXTRACT,                 TYPE_UNUSED,               (U16*)(&WifiErrorPreVal),              EVENT_STATUS_CHANGE },
    
};

#define SZ_ERR_EVENT_LIST    (sizeof(WifiErrorProtocolList)/sizeof(WifiTxFuncEventList_T))
#define SZ_ERR_EVENT_LIST_CP    (sizeof(WifiErrorProtocolList_CP)/sizeof(WifiTxFuncEventList_T))

void* GetWifiErrDataEventList ( void )
{
    if (IsUserModelType() == Model_0)
    {
        return WifiErrorProtocolList;
    }
    else
    {
        return WifiErrorProtocolList_CP;
    }
}

U16 GetWifiErrEventListSize ( void )
{
    if (IsUserModelType() == Model_0)
    {
        return SZ_ERR_EVENT_LIST;
    }
    else
    {
        return SZ_ERR_EVENT_LIST_CP;
    }

}


/* [User Error Data] Product -> Server */
U16 GetUserSystemError ( U16 mu16Err )
{
    U16 mu16Data = 0U;

    switch ( mu16Err ) // 0:Normal / 1:Error
    {
        case WIFI_ERROR_0006_HOTIN_TEMP:
            if(gu8_ModelType_forCHP == MODEL_CHP)
            {
        	    mu16Data = F_Err46_HotInTH;
            }
        	break;

        case WIFI_ERROR_0007_HOTOUT_TEMP:
            if(gu8_ModelType_forCHP == MODEL_CHP)
            {        
        	    mu16Data = F_Err47_HotOutTH;
            }
        	break;

        case WIFI_ERROR_0008_COLD_TEMP :
        	mu16Data = F_Err44_ColdTH;
        break;

        case WIFI_ERROR_0009_NATURAL_TEMP :
        	mu16Data = F_Err43_OutDoorAirTH;
        break;

        case WIFI_ERROR_0018_TEM_TEMP:
        	mu16Data = F_Err25_HeatSinkTH;
        	break;

        case WIFI_ERROR_0019_STOP_WATER :
        	mu16Data = F_Err09_CutWater;
        	break;

        case WIFI_ERROR_001A_TEM_OPERATION:
        	if ((F_Err29_TEM_OverDrive1 == SET) || (F_Err29_TEM_OverDrive2 == SET))
        	{
        		mu16Data = SET;
        	}
        	else
        	{
        		mu16Data = CLEAR;
        	}
        	break;

        case WIFI_ERROR_001B_STOP_HOTWATER:
            if(gu8_ModelType_forCHP == MODEL_CHP)
            {
        	    mu16Data = F_Err08_HotCutWater;
            }
        	break;

        case WIFI_ERROR_001D_LEAK_SENSOR :
        	mu16Data = F_Err01_LeakWater;
        	break;

        case WIFI_ERROR_001E_HOT_OVER:
            if(gu8_ModelType_forCHP == MODEL_CHP)
            {
        	    mu16Data = F_Err40_OverHeat;
            }
        	break;

        case WIFI_ERROR_001F_HEATER_SENSOR:
            if(gu8_ModelType_forCHP == MODEL_CHP)
            {
        	    mu16Data = F_Err48_HeaterTH;
            }
        	break;

        case WIFI_ERROR_0038_UV_EXTRACT:
            mu16Data = F_Err77_FaucetUV;
            break;

        default:
            mu16Data = 0U;
        break;
    }
    return mu16Data;
}