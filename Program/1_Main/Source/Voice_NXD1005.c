/// @file     Voice_NXD1005.c
/// @date     2022.01.02
/// @author   PSM
/// @brief    ?????? ???? file
#define VOICE_H_
#include "include/_include.h"

static U8 SilentMode(U16 vocie_address);
static U8 SoundMode(U16 vocie_address);
static U8 VoiceMode(U16 vocie_address);

//---------------------------------------------------------
//      ?????????? ??(??????,???????,??????)
//---------------------------------------------------------
U8 Get_Sound_Type(void)
{
    return gu8_Sound_Type;
}



void Play_Voice(U16 mu16MemoryAddress)
{
    U8 mu8_S_Type;


	gu16_Voice_Address = mu16MemoryAddress;

	mu8_S_Type = Get_Sound_Type();

	// ?????????? [0] ????????? (???????????? ??????????)
	if (mu8_S_Type == SOUND_TYPE_0)
	{
		if (SilentMode(mu16MemoryAddress) == TRUE)
		{
			F_OneMoreSound = 1;
			F_PlayVoice = 1;
		}
	}
	// ?????????? [1] ???????????
	else if (mu8_S_Type == SOUND_TYPE_1)
	{
		if (SilentMode(mu16MemoryAddress) == TRUE)
		{
			F_PlayVoice = 1;
		}
	}
	// ?????????? [2] ????????????
	else if (mu8_S_Type == SOUND_TYPE_2)
	{
		if (SoundMode(mu16MemoryAddress) == TRUE)
		{
			F_PlayVoice = 1;
		}
	}
	// ?????????? [3] ?????????
	else if (mu8_S_Type == SOUND_TYPE_3)
	{
		if (VoiceMode(mu16MemoryAddress) == TRUE)
		{
			F_PlayVoice = 1;
		}
	}

	if (mu8_S_Type == SOUND_TYPE_0)    //?????? ????? ???????
	{
		if (F_OneMoreSound)
		{
			F_OneMoreSound = 0;
		}
		else
		{
			return;
		}
	}
}



//------------------
// [4] Critical ??????
//------------------
U8 IsCriticalVoice(U16 addr)
{
    switch( addr )
    {
		// ??????????
        case VOICE_POWER_ON:

//        //  ?????? ??????
//        case VOICE_COLD_WATER_ERROR:
//        case VOICE_HOT_WATER_ERROR:
//        case VOICE_SHORTAGE_ERROR:
//        case VOICE_LEAKAGE_ERROR:
//        case VOICE_SMART_CHECK_ERROR:
//
//        // Wifi ??????
//        case VOICE_WIFI_START:
//        case VOICE_WIFI_COMPLETE:
//        case VOICE_WIFI_OFF:
//        case VOICE_WIFI_COMPLETE_IOCARE:
//        case VOICE_WIFI_START_B:
//
//        // ????? ?????
//        case VOICE_VOICE_SETTING_3:
//        case VOICE_VOICE_SETTING_2:
//        case VOICE_VOICE_SETTING_1:
//        case VOICE_SETTING_VOICE:
//        case VOICE_SETTING_MELODY:
//        case VOICE_SETTING_SILENT:

        // ????
        case VOICE_SPECIAL_FUNCTION:
            return TRUE;

        default :
            return FALSE;
    }

    return FALSE;
}


U8 SilentMode(U16 vocie_address)
{
	switch (vocie_address)
	{
		case VOICE_POWER_ON:
		case VOICE_HOT_WATER_ERROR:
		case VOICE_SHORTAGE_ERROR:
		case VOICE_LEAKAGE_ERROR:
		case VOICE_CUP_SENSOR_ERROR:
		case VOICE_WIFI_COMPLETE_IOCARE:
		case VOICE_INFORM_WIFI_ON:
		case VOICE_INFORM_WIFI_OFF:                
		case VOICE_INFORM_WIFI_MODE_ACTIVATED:	    
		case VOICE_INFORM_BLE_MODE_ACTIVATED:      
		case VOICE_INFORM_APP_PAIRING_SUCCESS:		
		case VOICE_INFORM_BLE_MODE_DEACTIVATED: 	
		case VOICE_PRESS_BUTTON_ACCORDING_TO_APP_GUIDE:
		case VOICE_SPECIAL_FUNCTION:
		case VOICE_SETTING_VOICE:
		case VOICE_SETTING_MELODY:
		case VOICE_SETTING_SILENT:
		case VOICE_COLD_WATER_ERROR:
		case VOICE_CLEAN_DUST_FILTER:
		case VOICE_SMART_CHECK_ERROR:
		case VOICE_SMART_CHECK_START:
		case VOICE_SMART_CHECK_OK:
		case VOICE_FRONT_COVER_WARNING_B:
		case VOICE_CHANGE_FLOWFAUCET:
		case VOICE_CHANGE_FILTER_FLOWFAUCET:
		case VOICE_FLOWFAUCET_CONNECT_CHECK:
		case VOICE_FILTER_FLOWFAUCET_FLUSHING:
		case VOICE_STERIZATION_RINSE_ICON22:
		case VOICE_MYCUP_SET:
		case VOICE_MYTEMP_SET:
		case VOICE_CHANGE_FILTER:
		case VOICE_FILTER_CONNECT_CHECK_B:
		case VOICE_FILTER_FLUSHING:
		case VOICE_INSTALL:
		case VOICE_FLUSHING_START:
		case VOICE_FLUSHING_COMPLETE:
		case VOICE_STERIZATION_START_ICON22:
		case VOICE_STERIZATION_END_ICON22:
		case VOICE_FILTER_OFF:
		case VOICE_FILTER_ON:
		case VOICE_FLOWFAUCET_OFF:
		case VOICE_FLOWFAUCET_ON:
		case VOICE_FAUCET_FLOW_DISCONNECT_FOR_HOT:
		//@042 case VOICE_GUIDE_FAUCET_FLOW_CONNECTION:
		case VOICE_START_FILTER_CHANGE_MODE:
		case VOICE_PLACE_CUP_FOR_RESIDUAL_WATER_REMOVAL:
		case VOICE_RESIDUAL_WATER_REMOVAL_COMPLETE:
		case VOICE_CHECK_THE_FAUCET_BE_CAREFUL_HOT_WATER_IS_HOT:             //@033
		case VOICE_CHECK_THE_FAUCET_HOTWATER_EFFLUENT_PLACE_THE_CUP:         //@033
		case VOICE_CHANGE__FILTER_NO_HOSE:                                   //@033
		case VOICE_CHANGE__FILTER_FLOWFAUCET_NO_HOSE:                        //@033
		case VOICE_CHECK_THE_FAUCET_BE_CAREFUL_HOT_WATER__IS_HOT_2:            //@042
			return TRUE;
			break;
		case VOICE_BEEP_SELECT:
		case VOICE_BEEP_WARNING:
		case VOICE_BEEP_ON:
		case VOICE_BEEP_OFF:
		case VOICE_CONTIUNE_EFFLUENT:
		case VOICE_EFFLUENT_START:
		case VOICE_EFFLUENT_COMPLETE:
		case VOICE_EW_START:
		case VOICE_HOT_LOCK_SETTING:
		case VOICE_ALL_LOCK_SETTING_A:
		case VOICE_COLD_ON_SETTING:
		case VOICE_HOT_LOCK_CLEAR:
		case VOICE_ALL_LOCK_CLEAR:
		case VOICE_COLD_OFF_SETTING:
		case VOICE_HOT_LOCK_CHECK:
		case VOICE_COLD_OFF_CHECK:
		case VOICE_ALL_LOCK_CHECK_CP:
		case VOICE_FRONT_COVER_CHECK:
		case VOICE_ALL_LOCK_ICON22:
		case VOICE_PRE_HEATING:
		case VOICE_HOTWATER_EFFLUENT_A:
		case VOICE_HIGH_HOTTEMP_EFFLUENT_1:
		case VOICE_HOTWATER_FIRST:
		case 0xCF:
		case VOICE_ENTER_FAUCET_MOVING_SET_MODE:
		case VOICE_FAUCET_MOVING_POSITION_FIXED:
		case VOICE_FAUCET_SET_AUTO_MOVING:		
		default:
			return FALSE;
			break;
	}
}

U8 SoundMode(U16 vocie_address)
{
	switch (vocie_address)
	{
		/*	???????????	*/
		case VOICE_BEEP_SELECT:
		case VOICE_BEEP_WARNING:
		case VOICE_BEEP_ON:
		case VOICE_BEEP_OFF:
		case VOICE_POWER_ON:
		case VOICE_CONTIUNE_EFFLUENT:
		case VOICE_EFFLUENT_START:
		case VOICE_EFFLUENT_COMPLETE:
		case VOICE_HOT_WATER_ERROR:
		case VOICE_SHORTAGE_ERROR:
		case VOICE_LEAKAGE_ERROR:
		case VOICE_CUP_SENSOR_ERROR:
		case VOICE_WIFI_COMPLETE_IOCARE:
		case VOICE_INFORM_WIFI_ON:
		case VOICE_INFORM_WIFI_OFF:                
		case VOICE_INFORM_WIFI_MODE_ACTIVATED:	 
		case VOICE_INFORM_BLE_MODE_ACTIVATED:      
		case VOICE_INFORM_APP_PAIRING_SUCCESS:		
		case VOICE_INFORM_BLE_MODE_DEACTIVATED: 	
		case VOICE_PRESS_BUTTON_ACCORDING_TO_APP_GUIDE:		
		case VOICE_SPECIAL_FUNCTION:
		case VOICE_SETTING_VOICE:
		case VOICE_SETTING_MELODY:
		case VOICE_SETTING_SILENT:
		case VOICE_COLD_WATER_ERROR:
		case VOICE_CLEAN_DUST_FILTER:
		case VOICE_SMART_CHECK_ERROR:
		case VOICE_CHANGE_FILTER:
		case VOICE_CHANGE_FLOWFAUCET:
		case VOICE_CHANGE_FILTER_FLOWFAUCET:
		case VOICE_FLOWFAUCET_CONNECT_CHECK:
		case VOICE_FILTER_FLOWFAUCET_FLUSHING:
		case VOICE_STERIZATION_RINSE_ICON22:
		case VOICE_MYCUP_SET:
		case VOICE_MYTEMP_SET:
		case VOICE_SMART_CHECK_START:
		case VOICE_SMART_CHECK_OK:
		case VOICE_FILTER_CONNECT_CHECK_B:
		case VOICE_FILTER_FLUSHING:
		case VOICE_INSTALL:
		case VOICE_FLUSHING_START:
		case VOICE_FLUSHING_COMPLETE:
		case VOICE_STERIZATION_START_ICON22:
		case VOICE_STERIZATION_END_ICON22:
		case VOICE_FRONT_COVER_WARNING_B:
		case VOICE_FILTER_OFF:
		case VOICE_FILTER_ON:
		case VOICE_FLOWFAUCET_OFF:
		case VOICE_FLOWFAUCET_ON:
		case VOICE_FAUCET_FLOW_DISCONNECT_FOR_HOT:
		//@042 case VOICE_GUIDE_FAUCET_FLOW_CONNECTION:			
		case VOICE_START_FILTER_CHANGE_MODE:
		case VOICE_PLACE_CUP_FOR_RESIDUAL_WATER_REMOVAL:
		case VOICE_RESIDUAL_WATER_REMOVAL_COMPLETE:
		case VOICE_CHECK_THE_FAUCET_BE_CAREFUL_HOT_WATER_IS_HOT:             //@033
		case VOICE_CHECK_THE_FAUCET_HOTWATER_EFFLUENT_PLACE_THE_CUP:         //@033
		case VOICE_CHANGE__FILTER_NO_HOSE:                                   //@033
		case VOICE_CHANGE__FILTER_FLOWFAUCET_NO_HOSE:                        //@033
		case VOICE_CHECK_THE_FAUCET_BE_CAREFUL_HOT_WATER__IS_HOT_2:            //@042
			return TRUE;
			break;
		case VOICE_EW_START:
		case VOICE_HOT_LOCK_SETTING:
		case VOICE_ALL_LOCK_SETTING_A:
		case VOICE_COLD_ON_SETTING:
		case VOICE_ENTER_FAUCET_MOVING_SET_MODE:
		case VOICE_FAUCET_MOVING_POSITION_FIXED:
		case VOICE_FAUCET_SET_AUTO_MOVING:	
			gu16_Voice_Address = VOICE_BEEP_ON;
			return TRUE;
			break;
		case VOICE_HOT_LOCK_CLEAR:
		case VOICE_ALL_LOCK_CLEAR:
		case VOICE_COLD_OFF_SETTING:
			gu16_Voice_Address = VOICE_BEEP_OFF;
			return TRUE;
			break;
		case VOICE_HOT_LOCK_CHECK:
		case VOICE_COLD_OFF_CHECK:
		case VOICE_ALL_LOCK_CHECK_CP:
		case VOICE_FRONT_COVER_CHECK:
		case VOICE_ALL_LOCK_ICON22:
			gu16_Voice_Address = VOICE_BEEP_WARNING;
			return TRUE;
			break;
		case VOICE_PRE_HEATING:
		case VOICE_HOTWATER_EFFLUENT_A:
		case VOICE_HIGH_HOTTEMP_EFFLUENT_1:
			#if 0
			if (gu16_CupSize == CUPSIZE_CONTINUE)
			#endif
			if(gu8_Cup_size_Array[gu8_CupIndex].amount_volume == CUPSIZE_CONTINUE)			//	???????????
			{
				gu16_Voice_Address = VOICE_CONTIUNE_EFFLUENT;
			}
			else
			{
				gu16_Voice_Address = VOICE_EFFLUENT_START;
			}
			return TRUE;
			break;
		case VOICE_HOTWATER_FIRST:
		case 0xCF:
			if (gu8_OperationStep == Z_OperationStep_50)
			{
				#if 0
				if (gu16_CupSize == CUPSIZE_CONTINUE)
				#endif
				if(gu8_Cup_size_Array[gu8_CupIndex].amount_volume == CUPSIZE_CONTINUE)		//	???????????
				{
					gu16_Voice_Address = VOICE_CONTIUNE_EFFLUENT;
				}
				else
				{
					gu16_Voice_Address = VOICE_EFFLUENT_START;
				}
			}
			else
			{
				gu16_Voice_Address = VOICE_BEEP_WARNING;
			}
			return TRUE;
			break;
		default:
			return FALSE;
			break;
	}
}

U8 VoiceMode(U16 vocie_address)
{
	switch (vocie_address)
	{
		case VOICE_COLD_WATER_ERROR:
		case VOICE_CLEAN_DUST_FILTER:
		case VOICE_HOT_WATER_ERROR:
		case VOICE_SHORTAGE_ERROR:
		case VOICE_LEAKAGE_ERROR:
		case VOICE_CUP_SENSOR_ERROR:
		case VOICE_CHANGE_FILTER:
		case VOICE_FILTER_FLUSHING:
		case VOICE_SMART_CHECK_ERROR:
		case VOICE_PRE_HEATING:
		case VOICE_WIFI_COMPLETE_IOCARE:
		case VOICE_INFORM_WIFI_ON:
		case VOICE_INFORM_WIFI_OFF:                
		case VOICE_INFORM_WIFI_MODE_ACTIVATED:	      
		case VOICE_INFORM_BLE_MODE_ACTIVATED:      
		case VOICE_INFORM_APP_PAIRING_SUCCESS:		
		case VOICE_INFORM_BLE_MODE_DEACTIVATED: 	
		case VOICE_PRESS_BUTTON_ACCORDING_TO_APP_GUIDE:		
		case VOICE_INSTALL:
		case VOICE_FLUSHING_START:
		case VOICE_FLUSHING_COMPLETE:
		case VOICE_HOTWATER_EFFLUENT_A:
		case VOICE_FRONT_COVER_WARNING_B:
		case VOICE_HOT_LOCK_CHECK:
		case VOICE_COLD_OFF_CHECK:
		case VOICE_ALL_LOCK_CHECK_CP:
		case VOICE_EW_START:
		case VOICE_HOT_LOCK_SETTING:
		case VOICE_HOT_LOCK_CLEAR:
		case VOICE_ALL_LOCK_SETTING_A:
		case VOICE_ALL_LOCK_CLEAR:
		case VOICE_SETTING_VOICE:
		case VOICE_SETTING_MELODY:
		case VOICE_SETTING_SILENT:
		case VOICE_COLD_OFF_SETTING:
		case VOICE_COLD_ON_SETTING:
		case VOICE_CONTIUNE_EFFLUENT:
		case VOICE_EFFLUENT_START:
		case VOICE_EFFLUENT_COMPLETE:
		case VOICE_POWER_ON:
		case VOICE_BEEP_SELECT:
		case VOICE_BEEP_WARNING:
		case VOICE_BEEP_ON:
		case VOICE_BEEP_OFF:
		// ????
		case VOICE_FRONT_COVER_CHECK:
		case VOICE_SPECIAL_FUNCTION:
		case VOICE_FILTER_CONNECT_CHECK_B:
		case VOICE_ALL_LOCK_ICON22:
		case VOICE_STERIZATION_START_ICON22:
		case VOICE_STERIZATION_END_ICON22:
		case VOICE_CHANGE_FLOWFAUCET:
		case VOICE_CHANGE_FILTER_FLOWFAUCET:
		case VOICE_FLOWFAUCET_CONNECT_CHECK:
		case VOICE_FILTER_FLOWFAUCET_FLUSHING:
		case VOICE_STERIZATION_RINSE_ICON22:
		case VOICE_MYCUP_SET:
		case VOICE_MYTEMP_SET:
		case VOICE_SMART_CHECK_START:
		case VOICE_SMART_CHECK_OK:
		case VOICE_HIGH_HOTTEMP_EFFLUENT_1:
		case VOICE_HOTWATER_FIRST:
		case VOICE_FILTER_OFF:
		case VOICE_FILTER_ON:
		case VOICE_FLOWFAUCET_OFF:
		case VOICE_FLOWFAUCET_ON:
		case VOICE_FAUCET_FLOW_DISCONNECT_FOR_HOT:
		//@042 case VOICE_GUIDE_FAUCET_FLOW_CONNECTION:		
		case 0xCF:
		case VOICE_ENTER_FAUCET_MOVING_SET_MODE:
		case VOICE_FAUCET_MOVING_POSITION_FIXED:
		case VOICE_FAUCET_SET_AUTO_MOVING:		
		case VOICE_START_FILTER_CHANGE_MODE:
		case VOICE_PLACE_CUP_FOR_RESIDUAL_WATER_REMOVAL:
		case VOICE_RESIDUAL_WATER_REMOVAL_COMPLETE:
		case VOICE_CHECK_THE_FAUCET_BE_CAREFUL_HOT_WATER_IS_HOT:             //@033
		case VOICE_CHECK_THE_FAUCET_HOTWATER_EFFLUENT_PLACE_THE_CUP:         //@033
		case VOICE_CHANGE__FILTER_NO_HOSE:                                   //@033
		case VOICE_CHANGE__FILTER_FLOWFAUCET_NO_HOSE:                        //@033
		case VOICE_CHECK_THE_FAUCET_BE_CAREFUL_HOT_WATER__IS_HOT_2:            //@042
		return TRUE;
		break;
	    default:
		return FALSE;
		break;
	}
}


