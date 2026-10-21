
/*******************************************************************************
&Description :
    A1010 ~ A101x
    Function Table

&History : ssg@coway.com 2024.10.04 update

*******************************************************************************/

#include "WIFI_A101x_FunctionList.h"

/******************************************************************************/
/***** User Header ************************************************************/
/******************************************************************************/
// #include "include/_type_define.h"
// #include "_fix_ram.h"
// #include "cold.h"
/******************************************************************************/
/***** User Function **********************************************************/
/******************************************************************************/
#include "include/_type_define.h"
#include "operation.h"
#include "hot.h"
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
#include "faucet_moving.h"
/******************************************************************************/
/***** Table ******************************************************************/
/******************************************************************************/
/* Event List */
U16 WifiFuncEventPreVal[USER_DATA_MAX_SIZE] = {0};

static const WifiTxFuncEventList_T WifiFuncEventList[] = 
{   /*  API ID                                      DATA_TYPE                                 PreVal(Initial)                         EnventForm     */
    {   WIFI_FUNC_0002_COLD_SEL,                TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0003_HOT_LOCK_SEL,            TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },   
    {   WIFI_FUNC_0005_LOCK_SEL,                TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },   
    // {   WIFI_FUNC_0006_MUTE_SEL,                TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    // {   WIFI_FUNC_0008_ICE_SEL,                 TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_000A_COLD_TEMP,               TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    {   WIFI_FUNC_000B_WATER_SEL,               TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    {   WIFI_FUNC_000D_WATER_OUTQUANTITY,       TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },   // 0 -> ??
    {   WIFI_FUNC_001A_HOT_INTEMP,              TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },   
    {   WIFI_FUNC_001B_HOT_MEANTEMP,            TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },   
    {   WIFI_FUNC_001C_HOT_SELTEMP,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },   
    {   WIFI_FUNC_0024_HEART_TIME4,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },   // 0 -> ?? 
    {   WIFI_FUNC_002C_SILVER_CARE,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    // {   WIFI_FUNC_0030_ICE_MAKETIME,            TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },   // 0 -> ??
    {   WIFI_FUNC_0031_VOICE_SEL,               TYPE_A1014,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },   // 0 -> ??    
    // {   WIFI_FUNC_0032_ICELOCK_SEL,             TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0033_VOICE_VOL_SEL,           TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_0035_COVER1_OPEN,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0037_SLEEP_SEL,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    // {   WIFI_FUNC_0039_HOT_SEL,                 TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    // {   WIFI_FUNC_003B_HOT_TEMP_SEL,            TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_003E_WATER_COURSE_STATUS,     TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_003F_WATER_COURSE_RESET,      TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },
    {   WIFI_FUNC_0040_SMART_CHECK_RQST,        TYPE_SMART_DIAGNOSIS_CONTROL,        (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0041_SMART_CHECK_STATUS,      TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0042_SMART_CHECK_PROGRESS,    TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0043_FILTER_STATUS1,          TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_004A_WELCOME_LIGHT,           TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    // {   WIFI_FUNC_0047_WATER_QUANTITY_SEL,      TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    // {   WIFI_FUNC_0049_OUT_BUTTON_LIGHT,        TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
// {   WIFI_FUNC_0049_OUT_BUTTON_LIGHT,        TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_0050_UV_STERILIZE_STATUS,     TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    // {   WIFI_FUNC_0051_QUANTITY_USE_SEL,        TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0053_FILTER_RESET1,           TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    // {   WIFI_FUNC_0059_ICE_ONOFF_SEL,           TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_005C_SMART_CHECK_RESULT,      TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    // {   WIFI_FUNC_005D_UV_ICE_FAUCET_STATUS,    TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    // {   WIFI_FUNC_005E_SLEEP_MODE_SEL,          TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED        },
    // {   WIFI_FUNC_005F_SLEEP_START_HOUR,        TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED        },
    // {   WIFI_FUNC_0060_SLEEP_START_MIN,         TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED        },
    // {   WIFI_FUNC_0061_SLEEP_END_HOUR,          TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED        },
    // {   WIFI_FUNC_0062_SLEEP_END_MIN,           TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED        },
    // {   WIFI_FUNC_0066_DEFAULT_QUANTITY_SEL,    TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    // {   WIFI_FUNC_0077_HOT_TARGET_TEMP_TIME,    TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },   //0 -> ??
    // {   WIFI_FUNC_0078_COLD_TARGET_TEMP_TIME,   TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },   //0 -> ??
    {   WIFI_FUNC_0073_WATER_TEMP_SORT_SEL,         TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
     {   WIFI_FUNC_007F_DEFAULT_TEMP_SET,           TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    // {   WIFI_FUNC_008B_HEATER_STATUS,           TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    // {   WIFI_FUNC_008C_COMP_STATUS,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    // {   WIFI_FUNC_0093_ICEMAKING_STAUTS,        TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    // {   WIFI_FUNC_0095_ICEMAKING_COMPLET_TIME,  TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },   //0 -> ??
    // {   WIFI_FUNC_0096_DEICING_COMPLET_TIME,    TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },   //0 -> ??
    // {   WIFI_FUNC_009B_DRAINTANK_LOW_WLEVEL,    TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    // {   WIFI_FUNC_009C_DRAINTANK_HIGH_WLEVEL,   TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    // {   WIFI_FUNC_00A0_COLD_TANK_TEMP,          TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED        },
    // {   WIFI_FUNC_00A1_HOT_TANK_TEMP,           TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED        },
    {   WIFI_FUNC_00B5_FILTER_FLUSHING,         TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    {   WIFI_FUNC_00CB_WATER_EXTRACT_STATUS,    TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE   },
    // {   WIFI_FUNC_00CC_ICE_EXTRACT_STATUS,      TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    // {   WIFI_FUNC_00CD_SETUP_MODE_STATUS,       TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    {   WIFI_FUNC_0126_FAUCET_EXPOSURE_LEVEL,      TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_0132_START_WATER_QUANTITY_SLOT,  TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE }, 


    {   WIFI_FUNC_00C1_HOTTEMP_USE_SEL0,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00C2_HOTTEMP_USE_SEL1,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00C3_HOTTEMP_USE_SEL2,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00C4_HOTTEMP_USE_SEL3,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00C5_HOTTEMP_USE_SEL4,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00C6_HOTTEMP_USE_SEL5,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00C7_HOTTEMP_USE_SEL6,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00C8_HOTTEMP_USE_SEL7,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00C9_HOTTEMP_USE_SEL8,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00CA_HOTTEMP_USE_SEL9,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00CE_HOTTEMP_USE_SEL10,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_00CF_HOTTEMP_USE_SEL11,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },                                             
    {   WIFI_FUNC_011E_HOT_TEMP_MIN_COUNT,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    {   WIFI_FUNC_0120_HOT_TEMP_MAX_COUNT,            TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    {   WIFI_FUNC_0129_AMOUNT_SLOT1_ENABLE,          TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_012A_AMOUNT_SLOT2_ENABLE,          TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_012B_AMOUNT_SLOT3_ENABLE,          TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_012C_AMOUNT_SLOT4_ENABLE,          TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },     
    {   WIFI_FUNC_0133_START_WATER_QUANTITY_SEL_1,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_0134_START_WATER_QUANTITY_SEL_2,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_0135_START_WATER_QUANTITY_SEL_3,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_0136_START_WATER_QUANTITY_SEL_4,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_013C_START_WATER_QUANTITY_SEL_10,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_0140_FAUCET_UP_REED_SW,           TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_0141_FAUCET_DOWN_REED_SW,         TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_0142_FAUCET_CUP_DETECTION_MICRO_SW, TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },                   
};

static const WifiTxFuncEventList_T WifiFuncEventList_CP[] = 
{   /*  API ID                                      DATA_TYPE                                 PreVal(Initial)                         EnventForm     */
    {   WIFI_FUNC_0002_COLD_SEL,                TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0005_LOCK_SEL,                TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },   
     {   WIFI_FUNC_000A_COLD_TEMP,               TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    {   WIFI_FUNC_000B_WATER_SEL,               TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    {   WIFI_FUNC_000D_WATER_OUTQUANTITY,       TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },   // 0 -> ??
    {   WIFI_FUNC_0024_HEART_TIME4,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },   // 0 -> ?? 
    {   WIFI_FUNC_002C_SILVER_CARE,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    {   WIFI_FUNC_0031_VOICE_SEL,               TYPE_A1014,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },   // 0 -> ??    
    {   WIFI_FUNC_0033_VOICE_VOL_SEL,           TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_0035_COVER1_OPEN,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0037_SLEEP_SEL,             TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_003E_WATER_COURSE_STATUS,     TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_003F_WATER_COURSE_RESET,      TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_OTHER },
    {   WIFI_FUNC_0040_SMART_CHECK_RQST,        TYPE_SMART_DIAGNOSIS_CONTROL,        (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0041_SMART_CHECK_STATUS,      TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0042_SMART_CHECK_PROGRESS,    TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_0043_FILTER_STATUS1,          TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },
    {   WIFI_FUNC_004A_WELCOME_LIGHT,           TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_0050_UV_STERILIZE_STATUS,     TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    {   WIFI_FUNC_0053_FILTER_RESET1,           TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_005C_SMART_CHECK_RESULT,      TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },
    {   WIFI_FUNC_00B5_FILTER_FLUSHING,         TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_ZERO_TO_ONE   },
    {   WIFI_FUNC_00CB_WATER_EXTRACT_STATUS,    TYPE_UNUSED,                         (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE   },
    {   WIFI_FUNC_0126_FAUCET_EXPOSURE_LEVEL,      TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_0132_START_WATER_QUANTITY_SLOT,  TYPE_A1014,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },                                          
    {   WIFI_FUNC_0129_AMOUNT_SLOT1_ENABLE,          TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_012A_AMOUNT_SLOT2_ENABLE,          TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_012B_AMOUNT_SLOT3_ENABLE,          TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_012C_AMOUNT_SLOT4_ENABLE,          TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },     
    {   WIFI_FUNC_0133_START_WATER_QUANTITY_SEL_1,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_0134_START_WATER_QUANTITY_SEL_2,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_0135_START_WATER_QUANTITY_SEL_3,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },    
    {   WIFI_FUNC_0136_START_WATER_QUANTITY_SEL_4,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_013C_START_WATER_QUANTITY_SEL_10,  TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_STATUS_CHANGE },    
    {   WIFI_FUNC_0140_FAUCET_UP_REED_SW,           TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_0141_FAUCET_DOWN_REED_SW,         TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED }, 
    {   WIFI_FUNC_0142_FAUCET_CUP_DETECTION_MICRO_SW, TYPE_UNUSED,                          (U16*)(&WifiFuncEventPreVal),         EVENT_UNUSED },                   
};


#define SZ_FUNC_EVENT_LIST    (sizeof(WifiFuncEventList)/sizeof(WifiTxFuncEventList_T))
#define SZ_FUNC_EVENT_LIST_CP    (sizeof(WifiFuncEventList_CP)/sizeof(WifiTxFuncEventList_T))


void* GetWifiFuncDataEventList ( void )
{
    if (IsUserModelType() == Model_0)
    {
        return WifiFuncEventList;
    }
    else
    {
        return WifiFuncEventList_CP;
    }

}
U16 GetWifiFuncEventListSize ( void )
{
    if (IsUserModelType() == Model_0)
    {
        return SZ_FUNC_EVENT_LIST;
    }
    else
    {
        return SZ_FUNC_EVENT_LIST_CP;
    }
}


/* [User Function Data] Product -> Server */
U16 GetUserSystemFunction ( U16 mu16Func )
{
    U16 mu16Data = 0U;
    U16 buf = 0;


    switch ( mu16Func )
    {
        case WIFI_FUNC_0002_COLD_SEL :       /* ID */
            if(F_ColdOff == CLEAR)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }            
        break;
        case WIFI_FUNC_0003_HOT_LOCK_SEL : 

            if(gu8_ModelType_forCHP == MODEL_CHP)
            {
                if(F_HotLock == SET)
                {
                    mu16Data = 2;
                }
                else
                {
                    mu16Data = 1;
                }
            }

        break;
        case WIFI_FUNC_0005_LOCK_SEL : 
            
            if(F_AllLock == SET)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }

        break;
        case WIFI_FUNC_0006_MUTE_SEL : 
            
        break;
        case WIFI_FUNC_0008_ICE_SEL : 
            
        break;

        case WIFI_FUNC_000A_COLD_TEMP:
			if (F_ColdOff == SET)
			{
				mu16Data = 0;
			}
			else
			{
				if (F_ColdTemp_Display == 0)		//	WHITE
				{
					mu16Data = 1;
				}
				else
				{
					mu16Data = 2;
				}
			}
        break;

        case WIFI_FUNC_000B_WATER_SEL : 
        	switch (gu8_WaterSelect)
        	{
        		case PURE_WATER:
        		default:
        			mu16Data = 1;
        			break;
        		case COLD_WATER:
        			mu16Data = 2;
        			break;
        		case HOT_WATER:
        			mu16Data = 3;
        		    break;
        	}            
        break;
        case WIFI_FUNC_000D_WATER_OUTQUANTITY : 
            if(gu8_F_Effluent_Complete_After == SET)	// ???? ???? ??에만 ?????? ????
            {
                gu8_F_Effluent_Complete_After = CLEAR;
                mu16Data = (U16)((U32)gu16_Effluent_Hz_Amount_forWIFI * gu16_FlowMeter_Standard / 10000);
                mu16Data += 5;
                mu16Data /= 10;							//	1@G @Z8. A&0E
                mu16Data *= 10;	
            						//	1@G @Z8. A&0E
                gu16_Effluent_Hz_Amount_forWIFI = 0;	// ?????? ???? ?? ??????
            }
            else
            {
                mu16Data = 0;	// ???? ??? ?????? 0
            }

            // ???? ???? ??에만 ?????? (???? ?傷〈? ????)
            if((gu8_OperationStep != Z_OperationStep_50) && (gu8_F_Effluent_Complete_After == CLEAR))
            {
                gu16_Effluent_Hz_Amount_forWIFI = 0;	//  
            }          
        break;

        case WIFI_FUNC_001A_HOT_INTEMP:
        	if ((gu8_WaterSelect == HOT_WATER) && (gu8_ModelType_forCHP == MODEL_CHP))
        	{
            	if (gi16_HotInSensor.DEGREE >= 0)
            	{
    				buf = (U16)(gi16_HotInSensor.DEGREE / 10);
    				if (buf > 99)
    				{
    					buf = 99;
    				}
    				mu16Data = buf;
            	}
            	else
            	{
            		mu16Data = 0;
            	}
        	}
        	else
        	{
        		mu16Data = 0;
        	}        
        break;

        case WIFI_FUNC_001B_HOT_MEANTEMP:
        	if ((gu8_WaterSelect == HOT_WATER) && (gu8_ModelType_forCHP == MODEL_CHP))
        	{
        		mu16Data = gu16_HotOut_Degree_Ave/10;
        	}
        	else
        	{
        		mu16Data = 0;
        	}        
        break;
        
        case WIFI_FUNC_001C_HOT_SELTEMP:
        	if ((gu8_WaterSelect == HOT_WATER) && (gu8_ModelType_forCHP == MODEL_CHP))
        	{
        		switch (gu8_HotTempSetup)
        		{
                    case 12:
                        mu16Data = 100;
                    break;
        			case 11:
        				mu16Data = 95;
        				break;

        			case 10:
        				mu16Data = 90;
        				break;

        			case 9:
        				mu16Data = 85;
        				break;

					case 8:
						mu16Data = 80;
						break;

					case 7:
						mu16Data = 75;
						break;

					case 6:
						mu16Data = 70;
						break;

					case 5:
						mu16Data = 65;
						break;

					case 4:
						mu16Data = 60;
						break;

					case 3:
						mu16Data = 55;
						break;

					case 2:
						mu16Data = 50;
						break;

					case 1:
						mu16Data = 45;
						break;

                    default:
                        mu16Data = 45;
                        break;
        		}
        	}
        	else
        	{
        		mu16Data = 0;
        	}        
        break;        
        
        case WIFI_FUNC_0024_HEART_TIME4 : 
        	mu16Data = gu16_HeartServiceTime;
        	if (gu8_OperationStep == Z_OperationStep_10)
        	{
        		gu16_HeartServiceTime = 0;
        	}            
        break;
        case WIFI_FUNC_002C_SILVER_CARE : 
        	if (F_SilverCare_Notice == SET)
        	{
        		mu16Data = 1;
        		F_SilverCare_Notice = CLEAR;
        	}
        	else if (gu16_TimerSilverCare == 0)
        	{
        		mu16Data = 2;
        	}
        	else
        	{
        		mu16Data = 0;
        	}            
        break;
        case WIFI_FUNC_0030_ICE_MAKETIME : 
            
        break;

        case WIFI_FUNC_0031_VOICE_SEL:
            mu16Data = gu8_Sound_Type;
        break;

        case WIFI_FUNC_0032_ICELOCK_SEL : 
        break;

        case WIFI_FUNC_0033_VOICE_VOL_SEL:

            mu16Data = gu8_VoiceVolumeLevel+1;

        break;

        case WIFI_FUNC_0035_COVER1_OPEN : 
            if (INPUT_REED_SW_COVER == SET)
			{
				mu16Data = 0;
			}
			else
			{
				mu16Data = 1;
			}
        break;

        case WIFI_FUNC_0037_SLEEP_SEL:
            mu16Data = F_SleepMode;
            break;
        case WIFI_FUNC_0039_HOT_SEL : 
            
        break;

        case WIFI_FUNC_003E_WATER_COURSE_STATUS:
			if (INPUT_REED_SW_FAUCET == CLEAR)
			{
				mu16Data = 1;
			}
			else
			{
				mu16Data = 0;
			}
        break;

        case WIFI_FUNC_003F_WATER_COURSE_RESET:
			if (F_Faucet_Reset == SET)
			{
				mu16Data = 1;
				F_Faucet_Reset = CLEAR;
			}
        break;

        case WIFI_FUNC_0040_SMART_CHECK_RQST : 
        	if ((gu8_SmartCheckStep & 0xF0) == 0x20)
        	{
        		mu16Data = 1;
        	}
        	else if (F_SmartCheck_Complete_2 == SET)
        	{
        		mu16Data = 1;
        		F_SmartCheck_Complete_2 = CLEAR;
        	}
        	else
        	{
        		mu16Data = 0;
        	}            
        break;
        case WIFI_FUNC_0041_SMART_CHECK_STATUS : 
			if (F_SmartCheck_Start == SET)
			{
				mu16Data = 1;
				F_SmartCheck_Start = CLEAR;
			}
			else if ((gu8_SmartCheckStep & 0xF0) == 0x20)
			{
				mu16Data = 2;
			}
			else if (F_SmartCheck_Complete == SET)
			{
				mu16Data = 3;
				F_SmartCheck_Complete = CLEAR;
			}
			else if (F_SmartCheck_Stop == SET)
			{
				mu16Data = 4;
				F_SmartCheck_Stop = CLEAR;
			}
			else if ((F_SmartCheck_Prohibit == SET) || (gu8_OperationStep == Z_OperationStep_03) || (gu8_OperationStep == Z_OperationStep_04) || (gu8_OperationStep == Z_OperationStep_05)
		        	|| (gu8_OperationStep == Z_OperationStep_50) || (gu8_OperationStep_hi == 0x50))
			{
				mu16Data = 5;
				F_SmartCheck_Prohibit = CLEAR;
			}
			else
			{
				mu16Data = 0;
			}            
        break;
        case WIFI_FUNC_0042_SMART_CHECK_PROGRESS : 
        	mu16Data = (U16)gu8_SmartCheck_Percent;
        	gu8_SmartCheck_Percent = 0;            
        break;
        
        case WIFI_FUNC_0043_FILTER_STATUS1:
        	if (INPUT_REED_SW_FILTER == CLEAR)
        	{
        		mu16Data = 1;
        	}
        	else
        	{
        		mu16Data = 0;
        	}            
        break;
        case WIFI_FUNC_0047_WATER_QUANTITY_SEL : 
            
        break;
        case WIFI_FUNC_0049_OUT_BUTTON_LIGHT : 
            
        break;
        
        case WIFI_FUNC_004A_WELCOME_LIGHT:
            if(gu8_F_WelcomeLed_Enable == SET)
            {
        		mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
            break;

        case WIFI_FUNC_0050_UV_STERILIZE_STATUS : 
            #if 0
            if(P_UV == 1)
            #endif
            if(gu16_TimerUV_Oper != 0)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
        break;
        case WIFI_FUNC_0051_QUANTITY_USE_SEL : 
            
        break;

        case WIFI_FUNC_0053_FILTER_RESET1:
			if (F_Filter_Reset == SET)
			{
				mu16Data = 1;
				F_Filter_Reset = CLEAR;
			}            
            break;
        case WIFI_FUNC_0059_ICE_ONOFF_SEL : 
            
        break;
        case WIFI_FUNC_005C_SMART_CHECK_RESULT : 
            
        break;
        case WIFI_FUNC_005D_UV_ICE_FAUCET_STATUS : 
            
        break;
        case WIFI_FUNC_005E_SLEEP_MODE_SEL : 
            
        break;
        case WIFI_FUNC_005F_SLEEP_START_HOUR : 
            
        break;
        case WIFI_FUNC_0060_SLEEP_START_MIN : 
            
        break;
        case WIFI_FUNC_0061_SLEEP_END_HOUR : 
            
        break;
        case WIFI_FUNC_0062_SLEEP_END_MIN : 
            
        break;
        case WIFI_FUNC_0066_DEFAULT_QUANTITY_SEL : 
            
        break;

        case WIFI_FUNC_0073_WATER_TEMP_SORT_SEL:
            if(gu8_f_hot_temp_sorting == Z_HOT_TEMP_ASCENDING)
            {
                mu16Data = 0;
            }
            else
            {
                mu16Data = 1;
            }
        break;

        case WIFI_FUNC_0077_HOT_TARGET_TEMP_TIME : 
            
        break;
        case WIFI_FUNC_0078_COLD_TARGET_TEMP_TIME : 
            
        break;

        case WIFI_FUNC_007F_DEFAULT_TEMP_SET:

            if(selected_hot_temp[gu8_DefaultHotTempSetup] == 1)
            {
                mu16Data = 45;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 2)
            {
                mu16Data = 50;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 3)
            {
                mu16Data = 55;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 4)
            {
                mu16Data = 60;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 5)
            {
                mu16Data = 65;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 6)
            {
                mu16Data = 70;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 7)
            {
                mu16Data = 75;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 8)
            {
                mu16Data = 80;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 9)
            {
                mu16Data = 85;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 10)
            {
                mu16Data = 90;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 11)
            {
                mu16Data = 95;
            }
            else if(selected_hot_temp[gu8_DefaultHotTempSetup] == 12)
            {
                mu16Data = 100;
            }
            else
            {
                mu16Data = 45;
            }

        break;

        case WIFI_FUNC_008B_HEATER_STATUS : 
            
        break;
        case WIFI_FUNC_008C_COMP_STATUS : 
            
        break;
        case WIFI_FUNC_0093_ICEMAKING_STAUTS : 
            
        break;
        case WIFI_FUNC_0095_ICEMAKING_COMPLET_TIME : 
            
        break;
        case WIFI_FUNC_0096_DEICING_COMPLET_TIME : 
            
        break;
        case WIFI_FUNC_009B_DRAINTANK_LOW_WLEVEL : 
            
        break;
        case WIFI_FUNC_009C_DRAINTANK_HIGH_WLEVEL : 
            
        break;
        case WIFI_FUNC_00A0_COLD_TANK_TEMP : 
            
        break;
        case WIFI_FUNC_00A1_HOT_TANK_TEMP : 
            
        break;
        case WIFI_FUNC_00B5_FILTER_FLUSHING : 
            
        	if(gu8_FlushingProgress_forWifi == Z_FLUSHING_PROGRESS_ON_FOR_WIFI)
        	{
        		mu16Data = (U16)(gu8_FlushingProgress_forWifi);
        		gu8_FlushingProgress_forWifi = Z_FLUSHING_PROGRESS_GOING_FOR_WIFI;
        	}
			else if(gu8_FlushingProgress_forWifi == Z_FLUSHING_PROGRESS_GOING_FOR_WIFI)
			{
				mu16Data = (U16)(gu8_FlushingProgress_forWifi);
			}
        	else if(gu8_FlushingProgress_forWifi == Z_FLUSHING_PROGRESS_DONE_FOR_WIFI)
        	{
        		mu16Data = (U16)gu8_FlushingProgress_forWifi;
        		gu8_FlushingProgress_forWifi = 0;
        	}
        	else
        	{
        		mu16Data = 0;
        	}

        break;
        case WIFI_FUNC_00CB_WATER_EXTRACT_STATUS : 
            if(gu8_OperationStep == Z_OperationStep_50)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;
        case WIFI_FUNC_00CC_ICE_EXTRACT_STATUS : 
            
        break;
        case WIFI_FUNC_00CD_SETUP_MODE_STATUS : 
            
        break;

        case WIFI_FUNC_00C1_HOTTEMP_USE_SEL0:

            if(gu8_hot_temp_data_for_wifi.Bit.b0 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;

        case WIFI_FUNC_00C2_HOTTEMP_USE_SEL1:

            if(gu8_hot_temp_data_for_wifi.Bit.b1 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }


        break;

        case WIFI_FUNC_00C3_HOTTEMP_USE_SEL2:

            if(gu8_hot_temp_data_for_wifi.Bit.b2 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }


        break;

        case WIFI_FUNC_00C4_HOTTEMP_USE_SEL3:

            if(gu8_hot_temp_data_for_wifi.Bit.b3 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;

        case WIFI_FUNC_00C5_HOTTEMP_USE_SEL4:

            if(gu8_hot_temp_data_for_wifi.Bit.b4 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;

        case WIFI_FUNC_00C6_HOTTEMP_USE_SEL5:

            if(gu8_hot_temp_data_for_wifi.Bit.b5 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;        
        case WIFI_FUNC_00C7_HOTTEMP_USE_SEL6:

            if(gu8_hot_temp_data_for_wifi.Bit.b6 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;

        case WIFI_FUNC_00C8_HOTTEMP_USE_SEL7:
            if(gu8_hot_temp_data_for_wifi.Bit.b7 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }
        break;

        case WIFI_FUNC_00C9_HOTTEMP_USE_SEL8:
            if(gu8_hot_temp_data_for_wifi.Bit.b8 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;

        case WIFI_FUNC_00CA_HOTTEMP_USE_SEL9:

            if(gu8_hot_temp_data_for_wifi.Bit.b9 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;

        case WIFI_FUNC_00CE_HOTTEMP_USE_SEL10:
            if(gu8_hot_temp_data_for_wifi.Bit.b10 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }

        break;

        case WIFI_FUNC_00CF_HOTTEMP_USE_SEL11:
            if(gu8_hot_temp_data_for_wifi.Bit.b11 == SET)
            {
                mu16Data = 1U;
            }
            else
            {
                mu16Data = 0U;
            }            

        break;

        case WIFI_FUNC_011E_HOT_TEMP_MIN_COUNT:
            mu16Data = (U16)1;
        break;

        case WIFI_FUNC_0120_HOT_TEMP_MAX_COUNT:
            mu16Data = (U16)5;
        break;

        case WIFI_FUNC_0126_FAUCET_EXPOSURE_LEVEL:
            mu16Data = (U16)(gu8_FaucetMoving_Set_Level - 1);
        break;

        case WIFI_FUNC_0129_AMOUNT_SLOT1_ENABLE:
            if(gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_ONE].enable == 1)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
        break;

        case WIFI_FUNC_012A_AMOUNT_SLOT2_ENABLE:
            if(gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_TWO].enable == 1)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
        break;

        case WIFI_FUNC_012B_AMOUNT_SLOT3_ENABLE:
            if(gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_THREE].enable == 1)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
        break;

        case WIFI_FUNC_012C_AMOUNT_SLOT4_ENABLE:
            if(gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_FOUR].enable == 1)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
        break;

        case WIFI_FUNC_0132_START_WATER_QUANTITY_SLOT:
        mu16Data = (U16)(gu8_DefaultCupSize + 1);
        break;

        case WIFI_FUNC_0133_START_WATER_QUANTITY_SEL_1:
        
            mu16Data = ((U16)gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_ONE].amount_volume) * 10;

        break;

        case WIFI_FUNC_0134_START_WATER_QUANTITY_SEL_2:
        
            mu16Data = ((U16)gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_TWO].amount_volume) * 10;

        break;

        case WIFI_FUNC_0135_START_WATER_QUANTITY_SEL_3:
        
            mu16Data = ((U16)gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_THREE].amount_volume) * 10;

        break;

        case WIFI_FUNC_0136_START_WATER_QUANTITY_SEL_4:
        
            mu16Data = ((U16)gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_FOUR].amount_volume) * 10;

        break;

        case WIFI_FUNC_013C_START_WATER_QUANTITY_SEL_10:

            if(gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_CONTINUE].enable != 0)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }

        break;


        case WIFI_FUNC_0140_FAUCET_UP_REED_SW:
            
            if(INPUT_REED_SW_FAUCET_UP == SET)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
            break;
        
        case WIFI_FUNC_0141_FAUCET_DOWN_REED_SW:
            if(INPUT_REED_SW_FAUCET_DOWN == SET)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
            break;
        
        case WIFI_FUNC_0142_FAUCET_CUP_DETECTION_MICRO_SW:
            if(INPUT_MICRO_SW_FAUCET == SET)
            {
                mu16Data = 1;
            }
            else
            {
                mu16Data = 0;
            }
            break;
        
        default:
            mu16Data = 0U;
        break;
    }
    return mu16Data;
}


/* [Set User Function Data] App Control(Server) -> Product */
void SetUserSystemFunction ( U16 mu16Func, U16 mData )
{
    switch ( mu16Func )
    {
        case WIFI_FUNC_0002_COLD_SEL :
            if (mData == ON) // 1 : 3C<vON
            {
                F_ColdOff = CLEAR;
        		Ini_OperationStep_15();
        		Play_Voice(VOICE_COLD_ON_SETTING);
            }
            else // 0 : OFF
            {
            	F_ColdOff = SET;

                if(gu8_WaterSelect != HOT_WATER)
                {
                    Ini_OperationStep_18();
                    gu8_WaterSelect = PURE_WATER;
                    gu8_DefaultWaterSelect = PURE_WATER;
                }    
                else
                {
                    //  온수 선택된 상태에선 유지..
                }
        		Play_Voice(VOICE_COLD_OFF_SETTING);
            }
        break;
        case WIFI_FUNC_0003_HOT_LOCK_SEL :
            if (mData == 2)
            {
                // F_HotLock = SET;
                Hot_Lock_Setting();
                Play_Voice(VOICE_HOT_LOCK_SETTING);
            }
            else
            {
                F_HotLock = CLEAR;
                Play_Voice(VOICE_HOT_LOCK_CLEAR);
            }
        break;
        case WIFI_FUNC_0005_LOCK_SEL :
            if (mData == 1)
            {
                F_AllLock = SET;
        		Play_Voice(VOICE_ALL_LOCK_SETTING_A);
            }
            else
            {
            	F_AllLock = CLEAR;
                Play_Voice(VOICE_ALL_LOCK_CLEAR);
            }
        break;
        case WIFI_FUNC_0006_MUTE_SEL :

        break;
        case WIFI_FUNC_0008_ICE_SEL :

        case WIFI_FUNC_0031_VOICE_SEL:
            if(mData == 1)
            {
                gu8_Sound_Type = SOUND_TYPE_1;  
                Play_Voice(VOICE_SETTING_SILENT);
            }
            else if(mData == 2)
            {
                gu8_Sound_Type = SOUND_TYPE_2;    
                Play_Voice(VOICE_SETTING_MELODY);              
            }
            else if(mData == 3)
            {
                gu8_Sound_Type = SOUND_TYPE_3;      
                Play_Voice(VOICE_SETTING_VOICE);          
            }
            else
            {

            }

        break;

        break;
        case WIFI_FUNC_0032_ICELOCK_SEL :
        break;

        case WIFI_FUNC_0033_VOICE_VOL_SEL:
        	if ((mData >= 1) && (mData <= 5))
        	{
        		gu8_VoiceVolumeLevel = (U8)(mData-1);
        		Play_Voice(VOICE_BEEP_ON);
        	}        
        break;
        case WIFI_FUNC_0037_SLEEP_SEL:
        	if (mData <= 1)
        	{
				F_SleepMode = (U8)mData;
				F_SleepMode_Display = SET;
				Ini_OperationStep_17();
				if (F_SleepMode == SET)
				{
					Play_Voice(VOICE_BEEP_ON);
				}
				else
				{
					Play_Voice(VOICE_BEEP_OFF);
				}
        	}
        	break;
        case WIFI_FUNC_0039_HOT_SEL :

        break;

        case WIFI_FUNC_0040_SMART_CHECK_RQST :
            if ((gu8_OperationStep == Z_OperationStep_03) || (gu8_OperationStep == Z_OperationStep_04) || (gu8_OperationStep == Z_OperationStep_05)
            	|| (gu8_OperationStep == Z_OperationStep_50) || (gu8_OperationStep_hi == 0x50))
        	{
        		F_SmartCheck_Prohibit = SET;
        	}
        	else
        	{
        		F_SmartCheck = (U8)mData;					//
        	}
        break;
        case WIFI_FUNC_0047_WATER_QUANTITY_SEL :

        break;
        case WIFI_FUNC_0049_OUT_BUTTON_LIGHT :

        break;

        case WIFI_FUNC_004A_WELCOME_LIGHT:
            if(mData == 0)
            {
                gu8_F_WelcomeLed_Enable = 0;
                Play_Voice(VOICE_BEEP_OFF);
            }
            else if(mData == 1)
            {
                gu8_F_WelcomeLed_Enable = 1;
                gu8_Timer_WelcomeLed_On = 60;				//	WELCOME LED ON
                Play_Voice(VOICE_BEEP_ON);
            }
            else
            {

            }        
            break;
        case WIFI_FUNC_0051_QUANTITY_USE_SEL :

        break;
        case WIFI_FUNC_0059_ICE_ONOFF_SEL :

        break;
        case WIFI_FUNC_005C_SMART_CHECK_RESULT :
        	if (mData == CLEAR)						//	?????
        	{
        		Play_Voice(VOICE_SMART_CHECK_OK);
        	}
        	else									//	NG
        	{
        		Play_Voice(VOICE_SMART_CHECK_ERROR);
        	}
        break;
        case WIFI_FUNC_005E_SLEEP_MODE_SEL :

        break;
        case WIFI_FUNC_005F_SLEEP_START_HOUR :

        break;
        case WIFI_FUNC_0060_SLEEP_START_MIN :

        break;
        case WIFI_FUNC_0061_SLEEP_END_HOUR :

        break;
        case WIFI_FUNC_0062_SLEEP_END_MIN :

        break;
        case WIFI_FUNC_0066_DEFAULT_QUANTITY_SEL :

        break;

        case WIFI_FUNC_0073_WATER_TEMP_SORT_SEL:

            if (mData == 0)						//	????????
        	{
        		gu8_f_hot_temp_sorting = Z_HOT_TEMP_ASCENDING;
        	}
        	else									//	????????
        	{
        		gu8_f_hot_temp_sorting = Z_HOT_TEMP_DESCENDING;
        	}

            Play_Voice(VOICE_BEEP_ON);        

        break;

        case WIFI_FUNC_007F_DEFAULT_TEMP_SET:

            // gu8_hot_temp_default_data_for_wifi = (U8)mData;

            if(mData == 45)
            {
                gu8_hot_temp_default_data_for_wifi = 1;
            }
            else if(mData == 50)
            {
                gu8_hot_temp_default_data_for_wifi = 2;
            }
            else if(mData == 55)
            {
                gu8_hot_temp_default_data_for_wifi = 3;
            }
            else if(mData == 60)
            {
                gu8_hot_temp_default_data_for_wifi = 4;
            }
            else if(mData == 65)
            {
                gu8_hot_temp_default_data_for_wifi = 5;
            }
            else if(mData == 70)
            {
                gu8_hot_temp_default_data_for_wifi = 6;
            }
            else if(mData == 75)
            {
                gu8_hot_temp_default_data_for_wifi = 7;
            }
            else if(mData == 80)
            {
                gu8_hot_temp_default_data_for_wifi = 8;
            }
            else if(mData == 85)
            {
                gu8_hot_temp_default_data_for_wifi = 9;
            }
            else if(mData == 90)
            {
                gu8_hot_temp_default_data_for_wifi = 10;
            }
            else if(mData == 95)
            {
                gu8_hot_temp_default_data_for_wifi = 11;
            }                                                                                    
            else if(mData == 100)
            {
                gu8_hot_temp_default_data_for_wifi = 12;
            }  
            else
            {
                gu8_hot_temp_default_data_for_wifi = 1;
            }
            HotTemp_Setting();
            return_default_hot_temp_setup();
            Play_Voice(VOICE_BEEP_ON);
        break;
        
        case WIFI_FUNC_00C1_HOTTEMP_USE_SEL0:

            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b0 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b0 = CLEAR;
            }

        break;

        case WIFI_FUNC_00C2_HOTTEMP_USE_SEL1:
            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b1 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b1 = CLEAR;
            }
        break;

        case WIFI_FUNC_00C3_HOTTEMP_USE_SEL2:
            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b2 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b2 = CLEAR;
            }

        break;

        case WIFI_FUNC_00C4_HOTTEMP_USE_SEL3:

            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b3 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b3 = CLEAR;
            }

        break;

        case WIFI_FUNC_00C5_HOTTEMP_USE_SEL4:

            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b4 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b4 = CLEAR;
            }

        break;

        case WIFI_FUNC_00C6_HOTTEMP_USE_SEL5:

            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b5 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b5 = CLEAR;
            }

        break;        
        case WIFI_FUNC_00C7_HOTTEMP_USE_SEL6:
            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b6 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b6 = CLEAR;
            }
        
        break;

        case WIFI_FUNC_00C8_HOTTEMP_USE_SEL7:
             if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b7 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b7 = CLEAR;
            }

        break;

        case WIFI_FUNC_00C9_HOTTEMP_USE_SEL8:

            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b8 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b8 = CLEAR;
            }
        break;

        case WIFI_FUNC_00CA_HOTTEMP_USE_SEL9:

            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b9 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b9 = CLEAR;
            }

        break;

        case WIFI_FUNC_00CE_HOTTEMP_USE_SEL10:

            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b10 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b10 = CLEAR;
            }

        break;

        case WIFI_FUNC_00CF_HOTTEMP_USE_SEL11:

            if(mData == 1)
            {
                gu8_hot_temp_data_for_wifi.Bit.b11 = SET;
            }    
            else
            {
                gu8_hot_temp_data_for_wifi.Bit.b11 = CLEAR;
            }

            HotTemp_Setting();
            Update_CurrentHotTemp_If_Disabled();

            Play_Voice(VOICE_BEEP_ON);

        break;

        case WIFI_FUNC_0126_FAUCET_EXPOSURE_LEVEL:

            // if((gu8_FaucetMoving_Set_Level - 1) != (U8)mData)
            // {
            // gu8_F_Faucet_Level_ForWifi = SET;
            // }             

            if((gu8_FaucetMoving_Set_Level - 1) < (U8)mData)
            {
                gu8_F_FaucetMoving_Set_Level_Way = 0;
                gu8_F_Faucet_Level_ForWifi = SET;
            }
            else
            {
                gu8_F_FaucetMoving_Set_Level_Way = 1;
                gu8_F_Faucet_Level_ForWifi = SET;
            }

            if(mData == 0)
            {
                gu8_FaucetMoving_Set_Level = Z_FAUCET_MOVING_AUTO_LEVEL;
                Play_Voice(VOICE_BEEP_ON);                
            }
            else if(mData == 1)
            {
                gu8_FaucetMoving_Set_Level = Z_FAUCET_MOVING_FIX_1_LEVEL;
                Play_Voice(VOICE_BEEP_ON);
            }
            else if(mData == 2)
            {
                gu8_FaucetMoving_Set_Level = Z_FAUCET_MOVING_FIX_2_LEVEL;
                Play_Voice(VOICE_BEEP_ON);
            }
            else if(mData == 3)
            {
                gu8_FaucetMoving_Set_Level = Z_FAUCET_MOVING_FIX_3_LEVEL;
                Play_Voice(VOICE_BEEP_ON);
            }
            else if(mData == 4)
            {
                gu8_FaucetMoving_Set_Level = Z_FAUCET_MOVING_FIX_4_LEVEL;
                Play_Voice(VOICE_BEEP_ON);
            }
            else if(mData == 5)
            {
                gu8_FaucetMoving_Set_Level = Z_FAUCET_MOVING_FIX_5_LEVEL;
                Play_Voice(VOICE_BEEP_ON);
            }      
            else
            {

            }                 
    
        break;
      
        case WIFI_FUNC_0129_AMOUNT_SLOT1_ENABLE:
            if(mData == 1)
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_ONE].enable = 1;
            }
            else
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_ONE].enable = 0;
            }
        break;
        case WIFI_FUNC_012A_AMOUNT_SLOT2_ENABLE:
            if(mData == 1)
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_TWO].enable = 1;
            }
            else
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_TWO].enable = 0;
            }
        break;
        case WIFI_FUNC_012B_AMOUNT_SLOT3_ENABLE:
            if(mData == 1)
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_THREE].enable = 1;
            }
            else
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_THREE].enable = 0;
            }
        break;
        case WIFI_FUNC_012C_AMOUNT_SLOT4_ENABLE:
            if(mData == 1)
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_FOUR].enable = 1;
            }
            else
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_FOUR].enable = 0;
            }
            Update_CurrentCupSize_If_Disabled();
            Update_DefaultCupSize_If_Disabled();
        break;

        case WIFI_FUNC_0132_START_WATER_QUANTITY_SLOT:
            gu8_DefaultCupSize = (U8)mData - 1;
            Update_DefaultCupSize_If_Disabled();
            Play_Voice(VOICE_BEEP_ON); 
        break;

        case WIFI_FUNC_0133_START_WATER_QUANTITY_SEL_1:            
            gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_ONE].amount_volume = (U8)(mData / 10);
        break;

        case WIFI_FUNC_0134_START_WATER_QUANTITY_SEL_2:
            gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_TWO].amount_volume = (U8)(mData / 10);
        break;

        case WIFI_FUNC_0135_START_WATER_QUANTITY_SEL_3:
            gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_THREE].amount_volume = (U8)(mData / 10);
        break;

        case WIFI_FUNC_0136_START_WATER_QUANTITY_SEL_4:
            gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_FOUR].amount_volume = (U8)(mData / 10);                       
        break;        

        case WIFI_FUNC_013C_START_WATER_QUANTITY_SEL_10:
            if(mData == 1)
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_CONTINUE].enable = 1;
            }
            else
            {
                gu8_Cup_size_Array[Z_CUP_SIZE_ARRAY_CONTINUE].enable = 0;
            }

            Update_CurrentCupSize_If_Disabled();

            Play_Voice(VOICE_BEEP_ON); 
        break;

        default:
        break;
    }
}

/* User Data Clear (Called when wifi is not connected) */
void ClearUserSystemDataA1010 ( void )
{
    
}