
#include "WIFI_Config.h"

/******************************************************************************/
/***** User Header ************************************************************/
/******************************************************************************/
/* Start user code for include (User heders). */

    // #include "Voice_NXD1005.h"
#include "Voice_NXD1005.h"
#include "include/eeprom.h"
#include "include/_type_define.h"
#include "include/operation.h"
#include "include/_fix_ram.h"
#include "include/display.h"
#include "include/communication.h"
// #include "include/operation.h"
/* End user code.*/


/******************************************************************************/
/***** EEPROM Setting *********************************************************/
/******************************************************************************/
/* User eeprom write settings */
void UserWriteEep ( U16 mu16Addr, U8 mu8Val )
{
    if( mu16Addr == EEPROM_ADDR_WIFI_POWER )
    {
        /* Start user code.*/
        *EEPROM_Data_Table[EEPROM_ADDR_WIFI__POWER].data = mu8Val;
        /* End user code. */
    }
    else if( mu16Addr == EEPROM_ADDR_FIRST_PARING )
    {
        /* Start user code.*/
        *EEPROM_Data_Table[EEPROM_ADDR_FIRST__PAIRING].data = mu8Val;
        /* End user code. */
    }
    else if( mu16Addr == EEPROM_ADDR_FOTA_MODULE )
    {
        /* Start user code.*/
        *EEPROM_Data_Table[EEPROM_ADDR_FOTA__MODULE].data = mu8Val;
        /* End user code. */
    }
    else if( mu16Addr == EEPROM_ADDR_FOTA_MCU )
    {
        /* Start user code.*/
        *EEPROM_Data_Table[EEPROM_ADDR_FOTA__MCU].data = mu8Val;
        /* End user code. */
    }
}

/* User eeprom read settings */
U8 UserReadEep ( U16 mu16Addr )
{
    U8 mu8Data = 0U;

    if( mu16Addr == EEPROM_ADDR_WIFI_POWER )
    {
        /* Start user code.*/
        mu8Data = gu8_WifiPower;
        /* End user code. */
    }
    else if( mu16Addr == EEPROM_ADDR_FIRST_PARING )
    {
        /* Start user code.*/
        mu8Data = gu8_FirstPairing;
        /* End user code. */
    }
    else if( mu16Addr == EEPROM_ADDR_FOTA_MODULE )
    {
        /* Start user code.*/
        mu8Data = gu8_FOTA_Module;
        /* End user code. */
    }
    else if( mu16Addr == EEPROM_ADDR_FOTA_MCU )
    {
        /* Start user code.*/
        mu8Data = F_FOTA_Setup;
        /* End user code. */
    }

    return mu8Data;
}

/* User buzzsound/voice settings */
void UserBuzzSound ( U16 mu16Buzz )
{
    U16 Sound = 0;
    switch( mu16Buzz )
    {
        case WIFI_BUZZER_SELECT :       // 페어링 (선택음 "띵")
            /* Start user code.*/
            // ex) Sound = 1196;
            //Play_Voice(VOICE_196_MELODY_SELECT);
            // Play_Voice(VOICE_196_WIFI_SELECT);
            Play_Voice(VOICE_BEEP_SELECT);
            /* End user code. */
            break;

        case WIFI_BUZZER_AP_CONNECT :   // AP연결 (진입음 "띠리링" / Wi-Fi 연결모드가 활성화 되었습니다.)
            /* Start user code.*/
            // ex) Sound = 1001;
            // Play_Voice(VOICE_23_INFORM_APP_PAIRING_SUCCESS_WITH_WIFI);
            Play_Voice(VOICE_INFORM_WIFI_MODE_ACTIVATED);
            /* End user code. */
            break;

        case WIFI_BUZZER_BLE_CONNECT :  // AP연결 (진입음 "띠리링" / BLE연결모드가 활성화 되었습니다.)
            /* Start user code.*/
            // ex) Sound = 1001;
            Play_Voice(VOICE_INFORM_BLE_MODE_ACTIVATED);

            /* End user code. */
            break;

        case WIFI_BUZZER_SETUP :        // WIFI ON (설정음 "띵동↗" / 제품의 Wi-Fi가 켜졌습니다.)
            /* Start user code.*/
            // ex) Sound = 1198;
            Play_Voice(VOICE_INFORM_WIFI_ON);

            /* End user code. */
            break;

        case WIFI_BUZZER_SERVER_CONNECT :   // 서버연결 (연결음 "띠리링↗" / 제품과 앱이 성공적으로 연결되었습니다.)
            /* Start user code.*/
            // ex) Sound = 0xFFFF;
            Play_Voice(VOICE_WIFI_COMPLETE_IOCARE);

            /* End user code. */
            break;

        case WIFI_BUZZER_CANCEL :           // WIFI OFF (해제음 "동띵" / 제품의 Wi-Fi가 꺼졌습니다.)
            /* Start user code.*/
            // ex) Sound = 1199;
            Play_Voice(VOICE_INFORM_WIFI_OFF);

            /* End user code. */
            break;

        case WIFI_BUZZER_AP_START :         // AP시작음 (설정음 "띵동 ↗")
            /* Start user code.*/
            // ex) Sound = 1198;
            //Play_Voice(VOICE_198_MELODY_SET_ON);
            // Play_Voice(VOICE_198_WIFI_SET_ON);
            Play_Voice(VOICE_BEEP_ON);
            /* End user code. */
            break;

        case WIFI_BUZZER_ERROR :            // 불가음 (에러음 "띵깡띵깡")
            /* Start user code.*/
            // ex) Sound = 1197;
            //Play_Voice(VOICE_197_MELODY_WARNING);
            // Play_Voice(VOICE_197_WIFI_WARNING);
            Play_Voice(VOICE_BEEP_WARNING);
            /* End user code. */
            break;

        case WIFI_BUZZER_WiFi_OFF :         // Wi-Fi 페어링 해제음(동띵) / Wi-Fi 연결 모드가 비활성화 되었습니다.
            /* Start user code.*/
            // ex) Sound = 1199;
            // Play_Voice(VOICE_25_INFORM_WIFI_MODE_DEACTIVATED);
            Play_Voice(VOICE_BEEP_WARNING);
            /* End user code. */
            break;

        case WIFI_BUZZER_BLE_OFF :          // 블루투스 페어링 해제음(동띵) / 블루투스 연결 모드가 비활성화 되었습니다.
            /* Start user code.*/
            // ex) Sound = 1199;
            // Play_Voice(VOICE_21_INFORM_APP_PAIRING_FAIL_WITH_BLE);
            Play_Voice(VOICE_INFORM_BLE_MODE_DEACTIVATED);
            /* End user code. */
            break;

        case WIFI_BUZZER_BLE_CERT :         // (선택음 "띵") / 블루투스 점유인증 활성화 상태 / 제품인증을 진행 중입니다. 앱에서 가이드하는 버튼을 눌러주세요.
            /* Start user code.*/
            // ex) Sound = 1196;
            // Play_Voice(VOICE_29_APPLY_PRODUCT_CERT_OCCUPATION);
            Play_Voice(VOICE_PRESS_BUTTON_ACCORDING_TO_APP_GUIDE);
            /* End user code. */
            break;

        case WIFI_BUZZER_SERVER_FIRST :     // 페어링 완료 후 서버연결 (연결음 "띠리링↗" / 제품과 앱이 성공적으로 연결되었습니다.
            /* Start user code.*/
            // ex) Sound = 0xFFFF;
            // Play_Voice(VOICE_30_INFORM_APP_PAIRING_SUCCESS_WITH_WIFI);
            Play_Voice(VOICE_INFORM_APP_PAIRING_SUCCESS);
            /* End user code. */
            break;

        case WIFI_BUZZER_SMART_CHECK_OK :       // (설정음 "띵동 ↗") / 스마트 진단이 완료 되어 제품을 사용하실 수 있습니다.
            /* Start user code.*/
            // ex) Sound = 1198;
            // Play_Voice(VOICE_17_FINISH_SMART_TESTING_MODE_NO_ERROR);
            Play_Voice(VOICE_SMART_CHECK_OK);

            /* End user code. */
            break;

        case WIFI_BUZZER_SMART_CHECK_ERROR :    // 불가음 (에러음 "띵깡띵깡") / 스마트 진단이 완료 되었습니다.
            /* Start user code.*/
            // ex) Sound = 1197;
            // Play_Voice(VOICE_18_FINISH_SMART_TESTING_MODE_WITH_ERROR);
            Play_Voice(VOICE_SMART_CHECK_ERROR);
            /* End user code. */
            break;

        default :
            break;
    }

    if (Sound != 0xFFFFU)
	{
        /* Start user code.*/

		// Ex) Play_Voice(Sound);

        /* End user code. */     
	}
}

/* Time Setting Option (When using A2010 Time) - Called when time data is received*/
void SetUserSystemTime ( U16 mYear, U16 mMonth, U16 mDate, U16 mHour, U16 mMin, U16 mSec, U16 mDay )
{   /* Start user code.*/



}   /* End user code. */   


/* User FOTA Display Setting */
void SetUserSystemDisplay ( U8 mu8Display )
{
    if ( mu8Display == USER_DISPLAY_FOTA ) // FOTA
    {
        /* Start user code.*/
        F_FOTA_Display = SET;
    	F_FOTA_Setup = SET;
        /* End user code. */  
    }
}

/* Product Status Information Settings */
void SetUserSystemStatusData ( U8 mu8StatusType )
{
    switch ( mu8StatusType ) 
    {
        case USER_MODEL_TYPE:   // 모델 타입 설정
        /*
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. CHP
            SetUserSystemStatus(USER_MODEL_TYPE, 1U);    // e.g. CP
        */

        #if 0
        SetUserSystemStatus(mu8StatusType, 0U); // CHP (Model 0)
        #endif

        if(F_ModelDecide_Complete == SET)
        {
            if(gu8_ModelType_forCHP == MODEL_CHP)
            {
                SetUserSystemStatus(mu8StatusType, 0U); // CHP (Model 0)
            }
            else
            {
                SetUserSystemStatus(mu8StatusType, 1U); // CP (Model 1)

            }
        }
        else 
        {
            SetUserSystemStatus(mu8StatusType, 0U); // CHP (Model 0)
        }
        break;

        case USER_FACTORY_STATUS:       // Wi-Fi 검사모드 진입 설정
        /*             
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. 검사모드 아님 
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. 검사모드 진입 
        */

        break;

        case USER_RX_STATUS:    // 일반제어 불가상태 설정 
        /* 
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. 제어가능
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. 제어불가
        */

/*      e.g.
    
        if ((F_ExtractKeySet == SET)    // 얼음추출 중
            ||(F_WaterOut == SET)       // 물 추출 중
            ||(bit_self_test_start == SET)  // 스마트진단 중
            ||(F_Tank_Cover_Input == CLEAR))    // 탱크커버 열림 중
        {
            SetUserSystemStatus(mu8StatusType, 1U);     // 제어불가
        }
        else
        {
            SetUserSystemStatus(mu8StatusType, 0U);     // 제어가능
        } 

*/
        if((gu8_OperationStep == Z_OperationStep_50)        //  물 추출중   
        || (gu8_OperationStep == Z_OperationStep_11)       //  파우셋 무빙 대기
        || (gu8_OperationStep == Z_OperationStep_80)       //  스마트진단 중
        || ((gu8_OperationStep >= Z_OperationStep_03) && (gu8_OperationStep <= Z_OperationStep_05)) //  플러싱 중.
        || (gu8_OperationStep == Z_OperationStep_B0)       //  커버 열림
        || (gu8_OperationStep == Z_OperationStep_02))
        {
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. 제어불가
        }
        else
        {
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. 제어가능
        }

        break;

        case USER_SMART_POSSIBLE_STATUS:    // 스마트진단 불가상태 설정 
        /* 
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. 진단가능
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. 진단불가
        */
        if((gu8_OperationStep == Z_OperationStep_50)        //  물 추출중
        || (gu8_OperationStep == Z_OperationStep_11))       //  파우셋 무빙 대기
        {
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. 진단불가
        }else
        {
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. 진단가능
        }

        break;

        case USER_FOTA_POSSIBLE_STATUS:     // FOTA 불가 상태 설정 
        /* 
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. FOTA가능
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. FOTA불가
        */
        if((gu8_OperationStep == Z_OperationStep_50)        //  물 추출중
        || (gu8_OperationStep == Z_OperationStep_11)       //  파우셋 무빙 대기
        || ((gu8_OperationStep >= Z_OperationStep_03) && (gu8_OperationStep <= Z_OperationStep_05))) //  플러싱 중.
        {
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. FOTA불가
        }
        else
        {
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. FOTA가능
        }

        break;

        case USER_SMART_SENSING_STATUS:     // 스마트진단 중 상태 설정  
        /* 
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. 일반 상태 (스마트진단 중 상태 아님)
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. 스마트 진단 진행 중
        */
        if(gu8_OperationStep == Z_OperationStep_80)       //  스마트진단 중
        {
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. 스마트진단 진행 중
        }
        else
        {
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. 스마트진단 중 상태 아님
        }

        break;

        case USER_FACTORY_DIRECTFOTA_STATUS:    // 다이렉트 포타 진입 설정
        /* 
            SetUserSystemStatus(mu8StatusType, 0U);       // e.g. 다이렉트 FOTA 모드 아님
            SetUserSystemStatus(mu8StatusType, 1U);       // e.g. 다이렉트 FOTA 모드
        */
        default:

        break;
    }

}