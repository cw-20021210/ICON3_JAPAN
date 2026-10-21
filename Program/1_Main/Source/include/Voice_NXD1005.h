#ifdef VOICE_H_
	#define 	EXTERN
	#define 	GLOBAL_VARIABLE_DEFINE
#else
	#define 	EXTERN extern
#endif


/*==============================================================================
 Constant Definition
 ==============================================================================*/
//#define VOICE_TYPE_VOICOMM 0x01
#define VOICE_TYPE_VOICELAND 0x01
#define VOICE_TYPE_NEXTLAB 0x00

#define VOICE_VOLUME_LEVEL_MAXIUM 4
#define VOICE_VOLUME_LEVEL_MINIUM 0
#define DEFAULT_VOICE_VOLUME_LEVEL 1

#define SOUND_TYPE_0           0   // Type 0 - Sound Type 1, Beep x
#define SOUND_TYPE_1           1   // Type 1 - Sound Type 1, Beep x (무음)
#define SOUND_TYPE_2           2   // Type 2 - Sound Type 1, Beep O (효과음)
#define SOUND_TYPE_3           3   // Type 3 - Sound Type 2, Beep O (안내모드)

#define MK_COMMAND 0x8000

/*NXD Command*/
#define VOICE_COMMAND_ADDRESS_0 0xE000

// 음성안내
#define VOICE_COMMAND_VOLUME_5  0x0024  /* 36 */        // ▶ NUVOTON Volume 7
#define VOICE_COMMAND_VOLUME_4  0x0027  /* 39 */        // ▶ NUVOTON Volume 6
#define VOICE_COMMAND_VOLUME_3  0x002A  /* 42 */        // ▶ NUVOTON Volume 5
#define VOICE_COMMAND_VOLUME_2  0x0030  /* 48 */        // ▶ NUVOTON Volume 4
#define VOICE_COMMAND_VOLUME_1  0x0036  /* 54 */        // ▶ NUVOTON Volume 3

// 효과음
#define BEEP_COMMAND_VOLUME_5  0x0024  /* 36 */        // ▶ NUVOTON Volume 7
#define BEEP_COMMAND_VOLUME_4  0x0027  /* 39 */        // ▶ NUVOTON Volume 6
#define BEEP_COMMAND_VOLUME_3  0x002A  /* 42 */        // ▶ NUVOTON Volume 5
#define BEEP_COMMAND_VOLUME_2  0x0030  /* 48 */        // ▶ NUVOTON Volume 4
#define BEEP_COMMAND_VOLUME_1  0x0036  /* 54 */        // ▶ NUVOTON Volume 3

//// 음성안내
//#define VOICE_COMMAND_VOLUME_5  0x001F  /* 31 */       // ▶ NUVOTON Volume 9
//#define VOICE_COMMAND_VOLUME_4  0x0021  /* 33 */       // ▶ NUVOTON Volume 8
//#define VOICE_COMMAND_VOLUME_3  0x0024  /* 36 */       // ▶ NUVOTON Volume 7
//#define VOICE_COMMAND_VOLUME_2  0x0027  /* 39 */       // ▶ NUVOTON Volume 6
//#define VOICE_COMMAND_VOLUME_1  0x002A  /* 42 */       // ▶ NUVOTON Volume 5
//
//// 효과음
//#define BEEP_COMMAND_VOLUME_5  0x001F  /* 31 */        // ▶ NUVOTON Volume 9
//#define BEEP_COMMAND_VOLUME_4  0x0024  /* 36 */        // ▶ NUVOTON Volume 7
//#define BEEP_COMMAND_VOLUME_3  0x002A  /* 42 */        // ▶ NUVOTON Volume 5
//#define BEEP_COMMAND_VOLUME_2  0x0030  /* 48 */        // ▶ NUVOTON Volume 4
//#define BEEP_COMMAND_VOLUME_1  0x0036  /* 54 */        // ▶ NUVOTON Volume 3

//// 음성안내
//#define VOICE_COMMAND_VOLUME_5  0x0019  /* -9 dB */       // ▶ NUVOTON Volume 8
//#define VOICE_COMMAND_VOLUME_4  0x0023  /* -12 dB */      // ▶ NUVOTON Volume 7
//#define VOICE_COMMAND_VOLUME_3  0x002D  /* -15 dB */      // ▶ NUVOTON Volume 6
//#define VOICE_COMMAND_VOLUME_2  0x0037  /* -18 dB */      // ▶ NUVOTON Volume 5
//#define VOICE_COMMAND_VOLUME_1  0x0041  /* -18 dB */      // ▶ NUVOTON Volume 4
////#define VOICE_COMMAND_VOLUME_1  0x004B  /* -18 dB */      // ▶ NUVOTON Volume 3
////#define VOICE_COMMAND_VOLUME_1  0x0055  /* -18 dB */      // ▶ NUVOTON Volume 4
//
//// 효과음
//#define BEEP_COMMAND_VOLUME_5  0x0023  /* -12 dB */       // ▶ NUVOTON Volume 7
//#define BEEP_COMMAND_VOLUME_4  0x002D  /* -18 dB */       // ▶ NUVOTON Volume 6
//#define BEEP_COMMAND_VOLUME_3  0x0037  /* -24 dB */       // ▶ NUVOTON Volume 5
//#define BEEP_COMMAND_VOLUME_2  0x0041  /* -30 dB */       // ▶ NUVOTON Volume 4
//#define BEEP_COMMAND_VOLUME_1  0x004B  /* -30 dB */       // ▶ NUVOTON Volume 3
////#define BEEP_COMMAND_VOLUME_1  0x0055  /* -30 dB */       // ▶ NUVOTON Volume 2
////#define BEEP_COMMAND_VOLUME_1  0x005F  /* -30 dB */       // ▶ NUVOTON Volume 1

#define VOICE_COMMAND_VOLUME_INITIAL    0xE121     /* -9 dB */
#define VOICE_COMMAND_VOLUME_MINIUM     0xE100
#define VOICE_COMMAND_VOLUME_MAXIUM     0xE157

#define VOICE_COMMAND_CONTROL2 0xE260 /*operating mode: normal play*/
/*Repeat: 1 time play*/
#define VOICE_COMMAND_STOP 0xE210

#define VOICE_COMMAND_CONTROL3 0xE305 /*Disable, 비동기, 18bit, disable*/

#define VOICE_COMMAND_ADDRESS_256 0xE400
#define VOICE_COMMAND_ADDRESS_512 0xE401

/*NXD Address*/
#define VOICE_START 0x00


//==============================================================
//	음성 리스트
//==============================================================


#define VOICE_CUP_SENSOR_ERROR        		(0x39)      // 컵 감지 센서 이상이 감지되었습니다. 아이오케어 앱가이드를 확인해주시거나 증상이 반복되시면 콜센터에 연락해주세요.

#define VOICE_EW_START                		(0x58)      // 코웨이 살균 시스템으로 유로를 깨끗하고 안전하게 살균 중입니다.

// 추가
#define VOICE_PRE_HEATING             		(0x3F)      // 	(※국내향엔 없음 주의)온수 온도를 맞추고 있습니다. 잠시만 기다려주세요.
#define VOICE_FILTER_OFF			   		(0x8A)      //  (※국내향엔 없음 주의) 필터가 빠졌습니다.
#define VOICE_FILTER_ON			   			(0x8B)      //  (※국내향엔 없음 주의) 필터가 결합되었습니다.
#define VOICE_FLOWFAUCET_OFF		   		(0x8C)      //  (※국내향엔 없음 주의) 유로모듈이 빠졌습니다.
#define VOICE_FLOWFAUCET_ON			   		(0x8D)      //  (※국내향엔 없음 주의) 유로모듈이 결합되었습니다.

/*	icon 2.0 추가	끝		*/



#define VOICE_INSTALL           		  	(211)      // 안녕하세요. 고객님. 코웨이 정수기의 설치를 도와드리겠습니다. 추출 버튼을 누르시면 설치를 시작하겠습니다.
#define VOICE_FLUSHING_START     		  	(212)      // 새 정수기 제품에 깨끗한 물을 제공하기 위해 준비중입니다.
#define VOICE_FLUSHING_COMPLETE  		  	(213)      // 깨끗한 물을 제공하기 위한 준비가 완료되었습니다.
#define VOICE_CHANGE_FILTER           		(214)      //	필터를 교체하셨나요? 교체하셨다면 배수호스를 연결하시거나 약 5리터의 큰그릇을 준비해주세요. 추출버튼을 누르시면 깨끗한 물을 위한 준비 과정이 시작됩니다. 교체하지 않으셨다면 '냉수' 버튼을 눌러 다시 사용하실 수 있습니다.
#define VOICE_FILTER_FLUSHING				(215)		//	교체하신 새 필터로 깨끗한 물을 제공하기 위해 준비 중에 있습니다. 잠시만 기다려 주세요.
#define VOICE_FILTER_FLOWFAUCET_FLUSHING	(216)		//	교체하신 새 필터와 유로파우셋으로 깨끗한 물을 제공하기 위해 준비 중에 있습니다. 잠시만 기다려 주세요.
#define VOICE_CHANGE_FLOWFAUCET           	(217)		//	유로파우셋을 교체하셨나요? 교체하셨다면 추출버튼을 눌러주세요. 교체하지 않으셨다면 '냉수' 버튼을 눌러주세요.
#define VOICE_CHANGE_FILTER_FLOWFAUCET     	(218)		//	필터와 유로파우셋을 교체하셨나요? 교체하셨다면 배수호스를 연결하시거나 약 5리터의 큰그릇을 준비해주세요. 추출버튼을 누르시면 깨끗한 물을 위한 준비 과정이 시작됩니다. 교체하지 않으셨다면 '냉수' 버튼을 눌러 다시 사용하실 수 있습니다.
#define VOICE_ALL_LOCK_SETTING_A      		(219)      // 모든 버튼이 잠겼습니다.
#define VOICE_ALL_LOCK_CLEAR          		(220)      // 모든 버튼을 사용하실 수 있습니다.
#define VOICE_ALL_LOCK_ICON22				(221)		//	모든 버튼이 잠겨있습니다. 온수와 정수 버튼을 동시에 3초 누르시면 모든 기능을 다시 사용하실 수 있습니다.
#define VOICE_ALL_LOCK_CHECK_CP       		(222)      // 모든 버튼이 잠겨있습니다. 전체 잠금 버튼을 3초 누르시면 모든 기능을 다시 사용하실 수 있습니다.
#define VOICE_HOTWATER_FIRST			   	(223)      //  온수 첫 잔은 뜨겁지 않을 수 있습니다. 첫 잔을 버린 후 사용해주세요.
#define VOICE_HOTWATER_EFFLUENT_A   		(224)      // 온수가 뜨거우니 주의하세요.
#define VOICE_HIGH_HOTTEMP_EFFLUENT_1   	(225)      //  고온수가 추출 됩니다. 컵을 추출구에 가까이 해주세요.
#define VOICE_HOT_LOCK_SETTING        		(226)      // 온수 버튼이 잠겼습니다.
#define VOICE_HOT_LOCK_CLEAR          		(227)      // 온수 버튼을 사용하실 수 있습니다.
#define VOICE_HOT_LOCK_CHECK          		(228)      // 온수 버튼이 잠겨있습니다. 온수 버튼을 3초 누르시면 선택하신 온수를 다시 사용하실 수 있습니다.
#define VOICE_COLD_OFF_CHECK          		(229)      // 냉수가 꺼져있습니다. 냉수 버튼을 3초 누르시면 선택하신 냉수를 다시 사용하실 수 있습니다.
#define VOICE_COLD_OFF_SETTING        		(230)      // 냉수 기능이 꺼졌습니다.
#define VOICE_COLD_ON_SETTING         		(231)		//	냉수 기능이 켜졌습니다. 적정 온도 도달까지 시간이 다소 소요됩니다.
#define VOICE_LEAKAGE_ERROR           		(232)      // 누수가 감지되었습니다. 안전을 위해 원수공급밸브를 닫아주세요. 증상이 반복되면 아이오케어앱 가이드에 따라 확인해주시거나 콜센터에 연락해주세요.
#define VOICE_SHORTAGE_ERROR          		(233)      // 물 공급에 이상이 감지되었습니다. 원수공급밸브가 열려 있는지 확인해주세요. 증상이 반복되면 아이오케어앱 가이드에 따라 확인해주시거나 콜센터에 연락해주세요.
#define VOICE_HOT_WATER_ERROR         		(234)      // 온수 기능에 이상이 감지되었습니다. 증상이 반복되면 아이오케어앱 가이드에 따라 확인해주시거나 콜센터에 연락해주세요.
#define VOICE_COLD_WATER_ERROR        		(235)      // 냉수 기능에 이상이 감지되었습니다. 증상이 반복되면 아이오케어앱 가이드에 따라 확인해주시거나 콜센터에 연락해주세요.
#define VOICE_FRONT_COVER_WARNING_B     	(236)      // 제품 전면 커버가 열렸습니다. 안전을 위해 물 공급을 자동으로 차단합니다.
#define VOICE_FRONT_COVER_CHECK         	(237)      // 제품의 커버가 열려있습니다. 커버를 닫아주세요.
#define VOICE_FILTER_CONNECT_CHECK_B  		(238)      // 필터가 올바르게 결합되지 않은 것으로 감지 되었습니다. 다시한번 확인해주세요.
#define VOICE_FLOWFAUCET_CONNECT_CHECK		(239)		//	유로파우셋이 올바르게 결합되지 않은 것으로 감지되었습니다. 제품 커버를 열어 다시 한 번 확인해주세요



#define VOICE_INFORM_WIFI_ON                 (242)                // '제품의 Wi-Fi가 켜졌습니다.'
#define VOICE_INFORM_WIFI_OFF                (243)                // '제품의 Wi-Fi가 꺼졌습니다.' 와이파이를 다시 연결하려면 냉수와 용량버튼을 동시에 3초 눌러주세요
#define VOICE_INFORM_WIFI_MODE_ACTIVATED	 (244)                // 'Wi-Fi 연결 모드가 활성화 되었습니다. '
#define VOICE_WIFI_COMPLETE_IOCARE         	(245)      /* 제품과 앱이 성공적으로 연결 되었습니다. 이제부터 아이오케어 앱을 통해 스마트한 관리를 받으실 수 있습니다..*/
#define VOICE_NEW_VOICE_WIFI_FAIL_A          (246)      /* 제품과 앱의 연결이 실패하였습니다. 인터넷 공유기를 확인해주세요. 문제가 반복되면 콜센터에 연락주세요..*/
#define VOICE_INFORM_BLE_MODE_ACTIVATED      (247)      // '블루투스 연결 모드가 활성화 되었습니다. '
#define VOICE_INFORM_APP_PAIRING_SUCCESS		(248)     // '제품과 앱이 성공적으로 연결되었습니다.' 이제부터 아이오케어 플러스 앱을 통해 스마트한 관리를 받으실 수 있습니다.
#define VOICE_INFORM_BLE_MODE_DEACTIVATED 	(249)             // '블루투스 연결 모드가 비활성화 되었습니다.'
#define VOICE_PRESS_BUTTON_ACCORDING_TO_APP_GUIDE 	(250)          // '"제품 인증을 진행 중입니다. 앱에서 가이드하는 버튼을 눌러 주세요." 
#define VOICE_STERIZATION_START_ICON22		(251)		//	코웨이의 살균수로 유로 살균 서비스를 시작합니다.
#define VOICE_STERIZATION_RINSE_ICON22		(252)		//	유로 헹굼을 시작합니다.
#define VOICE_STERIZATION_END_ICON22		(253)		//	유로 살균 서비스를 완료했습니다.
#define VOICE_SETTING_VOICE           		(254)		// 음성안내 모드입니다.
#define VOICE_SETTING_MELODY          		(255)		// 효과음 모드입니다.
#define VOICE_SETTING_SILENT          		(256)		// 무음 모드입니다.
#define VOICE_SMART_CHECK_START      		(257)   	//  제품의 상태를 파악하기 위해 스마트 진단을 시작합니다.잠시만 기다려주세요.
#define VOICE_SMART_CHECK_OK	      		(258)      //  스마트진단이 완료되어 제품을 사용하실 수 있습니다.
#define VOICE_SMART_CHECK_ERROR       		(259)      // 스마트 진단 결과 이상이 감지되었습니다. 아이오케어 앱을 통해 상세 내용을 확인해주세요.
#define VOICE_MYCUP_SET						(260)		//	고객님의 용량이 설정되었습니다.
#define VOICE_MYTEMP_SET					(261)		//	고객님의 용량이 설정되었습니다.
#define VOICE_SPECIAL_FUNCTION        		(262)      // 특수 모드에 진입하였습니다.
#define VOICE_FAUCET_FLOW_DISCONNECT_FOR_HOT (263)		//	파우셋 유로가 체결되지 않아 안전을 위해 온수를 차단하였습니다. 파우셋 유로를 체결해주세요
//@042 #define VOICE_GUIDE_FAUCET_FLOW_CONNECTION  (264)		//	파우셋 유로가 체결되지 않아 안전을 위해 온수를 차단하였습니다. 파우셋 유로를 체결해주세요
#define VOICE_CHECK_THE_FAUCET_BE_CAREFUL_HOT_WATER__IS_HOT_2 (264)    //@042 안전한 온수 사용을 위해 파우셋 유로가 정확히 체결되었는지 확인해주세요. 온수가 뜨거우니 주의하세요.

#define VOICE_ENTER_FAUCET_MOVING_SET_MODE	(265)		//	파우셋 무빙 설정모드에 진입하였습니다.
#define VOICE_FAUCET_MOVING_POSITION_FIXED	(266)		//	파우셋 위치가 고정되었습니다.
#define VOICE_FAUCET_SET_AUTO_MOVING		(267)		//	파우셋 자동무빙으로 설정되었습니다.
#define VOICE_ADJUSTING_THE_FAUCET_FOR_FILTER_CHANGE	(268)		//	필터 교체를 위해 파우셋을 조정하고 있습니다.
#define VOICE_START_FILTER_CHANGE_MODE	(269)		//	필터교체모드를 시작합니다.
#define VOICE_PLACE_CUP_FOR_RESIDUAL_WATER_REMOVAL	(270)		//	잔수 제거를 위해 추출구에 컵을 놓고 추출 버튼을 눌러주세요.
#define VOICE_RESIDUAL_WATER_REMOVAL_COMPLETE	(271)		//	잔수 제거가 완료 되었습니다. 필터 교체를 진행해 주세요.
#define VOICE_CHECK_THE_FAUCET_BE_CAREFUL_HOT_WATER_IS_HOT (272)    //@034 안전한 온수 사용을 위해 파우셋 유로가 정확히 체결되었는지 확인해주세요. 온수가 뜨거우니 주의하세요.
#define VOICE_CHECK_THE_FAUCET_HOTWATER_EFFLUENT_PLACE_THE_CUP  (273) //@034 안전한 온수사용을 위해 파우셋 유로가 정확히 체결되었는지 확인해주세요. 고온수가 추출됩니다. 컵을 추출구 가까이 놓아주세요.
#define VOICE_CHANGE__FILTER_NO_HOSE            (274)    //@034 필터를 교체하셨나요? 교체하셨다면 약 5리터의 큰 그릇을 준비해주세요. 추출 버튼을 누르시면 깨끗한 물을 위한 준비과정이 시작됩니다. 교체하지 않으셨다면 냉수 버튼을 눌러 다시 사용하실 수 있습니다.
#define VOICE_CHANGE__FILTER_FLOWFAUCET_NO_HOSE (275)    //@034 필터와 파우셋 유로를 교체하셨나요? 교체하셨다면, 약 5리터의 큰 그릇을 준비하세요. 추출버튼을 누르시면 깨끗한 물을 위한 준비과정이 시작됩니다. 교체하지 않으셨다면 냉수버튼을 눌러 다시 사용하실 수 있습니다.

#define VOICE_CONTIUNE_EFFLUENT     		(0x64)      // 연속추출
#define VOICE_EFFLUENT_START        		(0x65)      // 추출음
#define VOICE_EFFLUENT_COMPLETE     		(0x66)      // 추출종료음
#define VOICE_POWER_ON                		(0x67)      // 전원 인가시(플러그인) 당당당당당~~당. 코웨이~~
#define VOICE_BEEP_SELECT             		(0x68)      // 버튼선택음(띵)
#define VOICE_BEEP_WARNING            		(0x69)      // 불가음(띵깡띵깡)
#define VOICE_BEEP_ON                 		(0x6A)      // 설정( 띵동 ↗)
#define VOICE_BEEP_OFF                		(0x6B)      // 해제( 띵동 ↘)


#define VOICE_CLEAN_DUST_FILTER				(0x35)
//==============================================================

#define VOICE_ACTOR            0					// 성우
#define VOICE_CELEB            1					// BTS


/*==============================================================================
 Variable Definition
 ==============================================================================*/
EXTERN U16 COMMAND;

EXTERN U8 gu8_Sound_Type;						// 음성안내 모드 (0,1:무음모드 / 2:효과음모드 / 3:음성안내모드)
//EXTERN U8 gu8SoundTypeAlarm_Time;
EXTERN U8 gu8PlayVoice_Count;
EXTERN U8 gu8_VoiceVolumeLevel;					//	0~4:5단계
EXTERN U8 gu8Voice_Actor;

EXTERN U16 gu16_Voice_Address;
EXTERN U16 gu16VoiceDelay;

//EXTERN U16 VOICE_TEST;

EXTERN U8 F_OneMoreSound;
EXTERN U8 F_Beep_Sound;
EXTERN U8 F_PlayVoice; 								/*Sound Level에 따른 Address 받으면 SET 하여 음성 출력*/
//EXTERN U8 F_Initial_Voice;
 
//EXTERN U8 F_New_Voice;
/*==============================================================================
 function Definition
 ==============================================================================*/
void Initial_Voice(void);
void SetVoiceLevel(U8 mu8Val);
U8 Get_Sound_Type(void);
void Play_Voice(U16 mu16MemoryAddress);
void SEND_SPI_COMMAND(void);
//void Check_Play_A_Voice(void);
void VoiceStop(void);
//void Voice_Coway_Start(void);
void ProcessVoice(void);

U8 IsLevel_0(U16 addr);
U8 IsLevel_1(U16 addr);
U8 IsLevel_2(U16 addr);
U8 IsLevel_3(U16 addr);
U8 IsCriticalVoice(U16 addr);

//=============================================================================
#undef 	EXTERN
#undef 	GLOBAL_VARIABLE_DEFINE
//=============================================================================
