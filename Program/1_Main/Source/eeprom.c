/// @file     eeprom.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    EEPROM 占쏙옙占쏙옙 占쏙옙占쏙옙 file
#define EEPROM_C
#include "include/_include.h"

void EEPROM_Control_00(void);       	//	占쏙옙占쏙옙 占쏙옙 AA,55 占쏙옙占쏙옙占쏙옙 확占쏙옙
void EEPROM_Control_10(void);			//	占쏙옙占쏙옙占쏙옙 ALL 占십깍옙화 Write
void EEPROM_Control_20(void);			//	占쏙옙占쏙옙占쏙옙 ALL Read
void EEPROM_Control_30(void);			//	Checksum 확占쏙옙
void EEPROM_Control_40(void);			//	占싹뱄옙 占쏙옙占쏙옙

void Ini_EEPROM_Control_00(void);       //	占쏙옙占쏙옙 占쏙옙 AA,55 占쏙옙占쏙옙占쏙옙 확占쏙옙
void Ini_EEPROM_Control_10(void);		//	占쏙옙占쏙옙占쏙옙 ALL 占십깍옙화 Write
void Ini_EEPROM_Control_20(void);		//	占쏙옙占쏙옙占쏙옙 ALL Read
void Ini_EEPROM_Control_30(void);		//	Checksum 확占쏙옙
void Ini_EEPROM_Control_40(void);		//	占싹뱄옙 占쏙옙占쏙옙

static void EEPROM_Control_NoSet(U8 data);

void EEPROM_Write_00(void);				//	占십깍옙화
void EEPROM_Write_10(void);				//	占쏙옙占?
void EEPROM_Write_20(void);				//	Write 占쏙옙占쏙옙
void EEPROM_Write_21(void);				//	Write 占쏙옙占쏙옙
void EEPROM_Write_22(void);				//	Write/Address 占쌜쏙옙 (Write Confrim-1)
void EEPROM_Write_23(void);				//	Read CMD 占쌜쏙옙 (Write Confrim-2)
void EEPROM_Write_24(void);				//	Read 占쏙옙占쏙옙 占쏙옙占?
void EEPROM_Write_30(void);				//	Checksum Write

void Ini_EEPROM_Write_00(void);			//	占십깍옙화
void Ini_EEPROM_Write_10(void);			//	占쏙옙占?
void Ini_EEPROM_Write_20(void);			//	Write 占쏙옙占쏙옙
void Ini_EEPROM_Write_21(void);			//	Write 占쏙옙占쏙옙
void Ini_EEPROM_Write_22(void);			//	Write/Address 占쌜쏙옙 (Write Confrim-1)
void Ini_EEPROM_Write_23(void);			//	Read CMD 占쌜쏙옙 (Write Confrim-2)
void Ini_EEPROM_Write_24(void);			//	Read 占쏙옙占쏙옙 占쏙옙占?
void Ini_EEPROM_Write_30(void);			//	Checksum Write

static void EEPROM_Write_NoSet(U8 data);

void EEPROM_Read_00(void);     			//	占십깍옙화
void EEPROM_Read_10(void);				//	占쏙옙占?
void EEPROM_Read_20(void);				//	Write/Address 占쌜쏙옙
void EEPROM_Read_21(void);				//	Read CMD 占쌜쏙옙
void EEPROM_Read_22(void);				//	Read 占쏙옙占쏙옙 占쏙옙占?

void Ini_EEPROM_Read_00(void);      	//	占십깍옙화
void Ini_EEPROM_Read_10(void);			//	占쏙옙占?
void Ini_EEPROM_Read_20(void);			//	Write/Address 占쌜쏙옙
void Ini_EEPROM_Read_21(void);			//	Read CMD 占쌜쏙옙
void Ini_EEPROM_Read_22(void);			//	Read 占쏙옙占쏙옙 占쏙옙占?

static void EEPROM_Read_NoSet(U8 data);

EEPROM_StepTable EEPROM_Control_Table[Z_EEPROM_Control_Num_Max] =
{
	//	占쏙옙占쏙옙 No				Step Func.
	{ Z_EEPROM_Control_00,	EEPROM_Control_00 },	//	占쏙옙占쏙옙 占쏙옙 AA,55 占쏙옙占쏙옙占쏙옙 확占쏙옙
	{ Z_EEPROM_Control_10,	EEPROM_Control_10 },	//	占쏙옙占쏙옙占쏙옙 ALL 占십깍옙화 Write
	{ Z_EEPROM_Control_20,	EEPROM_Control_20 },	//	占쏙옙占쏙옙占쏙옙 ALL Read
	{ Z_EEPROM_Control_30,	EEPROM_Control_30 },	//	Checksum 확占쏙옙
	{ Z_EEPROM_Control_40,	EEPROM_Control_40 },	//	占싹뱄옙 占쏙옙占쏙옙
};

EEPROM_StepTable EEPROM_Write_Table[Z_EEPROM_Write_Num_Max] =
{
	//	占쏙옙占쏙옙 No				Step Func.
	{ Z_EEPROM_Write_00,	EEPROM_Write_00 },		//	占십깍옙화
	{ Z_EEPROM_Write_10,	EEPROM_Write_10 },		//	占쏙옙占?
	{ Z_EEPROM_Write_20,	EEPROM_Write_20 },		//	Write 占쏙옙占쏙옙
	{ Z_EEPROM_Write_21,	EEPROM_Write_21 },		//	Write 占쏙옙占쏙옙
	{ Z_EEPROM_Write_22,	EEPROM_Write_22 },     	//	Write/Address 占쌜쏙옙
	{ Z_EEPROM_Write_23,	EEPROM_Write_23 },     	//	Read CMD 占쌜쏙옙 (Write Confirm)
	{ Z_EEPROM_Write_24,	EEPROM_Write_24 },     	//	Read 占쏙옙占쏙옙 占쏙옙占?
	{ Z_EEPROM_Write_30,	EEPROM_Write_30 },		//	Checksum Write
};

EEPROM_StepTable EEPROM_Read_Table[Z_EEPROM_Read_Num_Max] =
{
	//	占쏙옙占쏙옙 No				Step Func.
	{ Z_EEPROM_Read_00,		EEPROM_Read_00 },     	//	占십깍옙화
	{ Z_EEPROM_Read_10,		EEPROM_Read_10 },     	//	占쏙옙占?
	{ Z_EEPROM_Read_20,		EEPROM_Read_20 },     	//	Write/Address 占쌜쏙옙
	{ Z_EEPROM_Read_21,		EEPROM_Read_21 },     	//	Read CMD 占쌜쏙옙
	{ Z_EEPROM_Read_22,		EEPROM_Read_22 },     	//	Read 占쏙옙占쏙옙 占쏙옙占?
};

/* 占쏙옙 16bit dat HIGH, LOW占쏙옙 Read占쏙옙 占쏙옙 占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙 占쌍댐옙 占쌜억옙 占쏙옙占쏙옙占쏙옙占?. void EEPROM_Control_30(void) 占쌉쇽옙 占쏙옙占쏙옙 */
EEPROM_Data EEPROM_Data_Table[Z_EEPROM_ADDR_Data_Max] =
{	//EEPROM Adr.									//Default Data							//EEPROM Data	//Write Flag	//Read Flag		//Real Data									//Write Delay Time	//Data Valid Check
	{EEPROM_ADDR_FIRST_A,							EEPROM_FIRST_A,								0,				0,				0,				&gu8_EEPROM_Data_First_A,					0,					0xAA,	0xAA},
	{EEPROM_ADDR_COLDONOFF,							EEPROM_DEFAULT_COLDONOFF,					0,				0,				0,				&F_ColdOff,									0,					0,		1},
	{EEPROM_ADDR_SLEEPMODE,							EEPROM_DEFAULT_SLEEPMODE,					0,				0,				0,				&F_SleepMode,								0,					0,		1},
	{EEPROM_ADDR_HOTLOCK,							EERPOM_DEFAULT_HOTLOCK,						0,				0,				0,				&F_HotLock,									0,					0,		1},
	{EERPOM_ADDR_CUPSIZE,							EERPOM_DEFAULT_CUPSIZE,						0,				0,				0,				&gu8_DefaultCupSize,						0,					0,		4},
	{EEPROM_ADDR_HOTWATER_100DEGREE,				EERPOM_DEFAULT_HOTWATER_100DEGREE,			0,				0,				0,				&F_HotWater_100Degree,						0,					0,		1},
	{EEPROM_ADDR_ALLLOCK,							EEPROM_DEFAULT_ALLLOCK,						0,				0,				0,				&F_AllLock,									0,					0,		1},
	{EEPROM_ADDR_CUPSIZE_MYSET,						0,											0,				0,				0,				&F_CupSize_MySet,							0,					0,		1},
	{EEPROM_ADDR_FLUSHING_STATUS,					EEPROM_DEFAULT_FLUSHING_STATUS,				0,				0,				0,				&F_FirstFlushing,							0,					0,		1},
	{EEPROM_ADDR_HEATER_FILL,						EEPROM_DEFAULT_HEATER_FILL,					0,				0,				0,				&F_Heater_Fill,								0,					0,		1},
	{EEPROM_ADDR_COLDTANK_FILL,						EEPROM_DEFAULT_COLDTANK_FILL,			0,				0,				0,				&F_ColdTank_Fill,							0,					0,		1},
	{EEPROM_ADDR_CUPSIZE_MY_HIGH,					EEPROM_DEFAULT_CUPSIZE_MY_HIGH,				0,				0,				0,				&gu8_CupSize_My_High,						0,					0,		0xFF},
	{EEPROM_ADDR_CUPSIZE_MY_LOW,					EEPROM_DEFAULT_CUPSIZE_MY_LOW,				0,				0,				0,				&gu8_CupSize_My_Low,						0,					0,		0xFF},
	{EEPROM_ADDR_ERROR_HISTORY_1,					0,											0,				0,				0,				&gu8_ErrorHistory[0],						0,					0,		0xFF},
	{EEPROM_ADDR_ERROR_HISTORY_2,					0,											0,				0,				0,				&gu8_ErrorHistory[1],						0,					0,		0xFF},
	{EEPROM_ADDR_ERROR_HISTORY_3,					0,											0,				0,				0,				&gu8_ErrorHistory[2],						0,					0,		0xFF},
	{EEPROM_ADDR_ERROR_HISTORY_4,					0,											0,				0,				0,				&gu8_ErrorHistory[3],						0,					0,		0xFF},
	{EEPROM_ADDR_ERROR_HISTORY_5,					0,											0,				0,				0,				&gu8_ErrorHistory[4],						0,					0,		0xFF},
	{EEPROM_ADDR_WIFI__POWER,						0,											0,				0,				0,				&gu8_WifiPower,								0,					0,		0xFF},
	{EEPROM_ADDR_FIRST__PAIRING,					0,											0,				0,				0,				&gu8_FirstPairing,							0,					0,		0xFF},
	{EEPROM_ADDR_FOTA__MODULE,						0,											0,				0,				0,				&gu8_FOTA_Module,							0,					0,		0xFF},
	{EEPROM_ADDR_FOTA__MCU,						0,											0,				0,				0,				&gu8_FOTA_MCU,								0,					0,		0xFF},
	{EEPROM_ADDR_USEDAY_forCNT_Filter_HIGH,		0,											0,				0,				0,				&gu8_UseDay_forCNT_Filter_High,				0,					0,		0xFF},
	{EEPROM_ADDR_USEDAY_forCNT_Filter_LOW,			0,											0,				0,				0,				&gu8_UseDay_forCNT_Filter_Low,				0,					0,		0xFF},
	{EEPROM_ADDR_USEDAY_forCNT_Faucet_HIGH,		0,											0,				0,				0,				&gu8_UseDay_forCNT_Faucet_High,				0,					0,		0xFF},
	{EEPROM_ADDR_USEDAY_forCNT_Faucet_LOW,			0,											0,				0,				0,				&gu8_UseDay_forCNT_Faucet_Low,				0,					0,		0xFF},
	{EEPROM_ADDR_EFFLUENT_LED_OFF,					0,											0,				0,				0,				&F_EffluentLED_OFF,							0,					0,		1},
	{EEPROM_ADDR_DEFAULT_HOTTEMP,					EEPROM_DEFAULT_HOTTEMP,						0,				0,				0,				&gu8_DefaultHotTempSetup,					0,					0,		0xFF},
	{EEPROM_ADDR_FOTA,								0,											0,				0,				0,				&F_FOTA_Setup,								0,					0,		1},
	{EEPROM_ADDR_SELFSERVICE,						0,											0,				0,				0,				&F_SelfService,								0,					0,		1},
	{EEPROM_ADDR_FIRST_SET,						0,											0,				0,				0,				&F_First_Set,								0,					0,		1},
	{EEPROM_ADDR_COOLING_UP,						0,											0,				0,				0,				&F_Cooling_Up,								0,					0,		1},
	{EEPROM_ADDR_SOUND_TYPE,						EEPROM_DEFAULT_SOUND_TYPE,					0,				0,				0,				&gu8_Sound_Type,							0,					1,		3},
	{EEPROM_ADDR_VOLUME,							EEPROM_DEFAULT_VOLUME,						0,				0,				0,				&gu8_VoiceVolumeLevel,						0,					0,		4},
	{EEPROM_ADDR_FAN_NOISECLEAR,					0,											0,				0,				0,				&F_FAN_NoiseClear,							0,					0,		1},
	{EEPROM_ADDR_HOT_DEGREEDISPLAY,				0,											0,				0,				0,				&F_HotWater_DegreeDisplay,					0,					0,		1},
	{EEPROM_ADDR_WELCOME_LIGHT_ENABLE,				EEPROM_DEFAULT_WELCOME_LIGHT_ENABLE,		0,				0,				0,				&gu8_F_WelcomeLed_Enable,					0,					0,		1},
	{EEPROM_ADDR_SPARE2,							0,											0,				0,				0,				&gu8_eerpom_null_value_2,					0,					0,		0xFF},
	{EEPROM_ADDR_COOLING_TARGET,					EEPROM_DEFAULT_COOLING_TARGET,				0,				0,				0,				&gu8_Cooling_TargetDegree_forEEPROM,		0,					0,		0xFF},
	{EEPROM_ADDR_COOLING_PID,						EEPROM_DEFAULT_COOLING_PI,					0,				0,				0,				&F_Cooling_PID,								0,					0,		1},
	{EEPROM_ADDR_ECOMODE_DISABLE,					0,											0,				0,				0,				&F_CoolingEcoMode_Disable,					0,					0,		1},
	{EEPROM_ADDR_MOVING_ENABLE,					EEPROM_DEFAULT_MOVING_LEVEL,				0,				0,				0,				&gu8_FaucetMoving_Set_Level,				0,					0,		6},
	{EEPROM_ADDR_CUPSIZE_ARRAY_ONE_AMOUNT,			EEPROM_DEFAULT_CUPSIZE_ARRAY_ONE,			0,				0,				0,				&gu8_Cup_size_Array[0].amount_volume,		0,					0,		100},
	{EEPROM_ADDR_CUPSIZE_ARRAY_TWO_AMOUNT,			EEPROM_DEFAULT_CUPSIZE_ARRAY_TWO,			0,				0,				0,				&gu8_Cup_size_Array[1].amount_volume,		0,					0,		100},
	{EEPROM_ADDR_CUPSIZE_ARRAY_THREE_AMOUNT,		EEPROM_DEFAULT_CUPSIZE_ARRAY_THREE,			0,				0,				0,				&gu8_Cup_size_Array[2].amount_volume,		0,					0,		100},
	{EEPROM_ADDR_CUPSIZE_ARRAY_FOUR_AMOUNT,		EEPROM_DEFAULT_CUPSIZE_ARRAY_FOUR,			0,				0,				0,				&gu8_Cup_size_Array[3].amount_volume,		0,					0,		100},
	{EEPROM_ADDR_CUPSIZE_ARRAY_FIVE_AMOUNT,		EEPROM_DEFAULT_CUPSIZE_ARRAY_FIVE,			0,				0,				0,				&gu8_Cup_size_Array[4].amount_volume,		0,					0,		0xFF},
	{EEPROM_ADDR_CUPSIZE_ARRAY_ONE_ENABLE,			EEPROM_DEFAULT_CUPSIZE_ARRAY_ONE_ENABLE,	0,				0,				0,				&gu8_Cup_size_Array[0].enable,				0,					0,		1},
	{EEPROM_ADDR_CUPSIZE_ARRAY_TWO_ENABLE,			EEPROM_DEFAULT_CUPSIZE_ARRAY_TWO_ENABLE,	0,				0,				0,				&gu8_Cup_size_Array[1].enable,				0,					0,		1},
	{EEPROM_ADDR_CUPSIZE_ARRAY_THREE_ENABLE,		EEPROM_DEFAULT_CUPSIZE_ARRAY_THREE_ENABLE,	0,				0,				0,				&gu8_Cup_size_Array[2].enable,				0,					0,		1},
	{EEPROM_ADDR_CUPSIZE_ARRAY_FOUR_ENABLE,		EEPROM_DEFAULT_CUPSIZE_ARRAY_FOUR_ENABLE,	0,				0,				0,				&gu8_Cup_size_Array[3].enable,				0,					0,		1},
	{EEPROM_ADDR_CUPSIZE_ARRAY_FIVE_ENABLE,		EEPROM_DEFAULT_CUPSIZE_ARRAY_FIVE_ENABLE,	0,				0,				0,				&gu8_Cup_size_Array[4].enable,				0,					0,		1},
	{EEPROM_ADDR_HOT_TEMP_DATA_HIGH,				EEPROM_DEFAULT_HOT_TEMP_DATA_HIGH,			0,				0,				0,				&gu8_hot_temp_data_for_wifi.byte[1],		0,					0,		0xFF},
	{EEPROM_ADDR_HOT_TEMP_DATA_LOW,				EEPROM_DEFAULT_HOT_TEMP_DATA_LOW,			0,				0,				0,				&gu8_hot_temp_data_for_wifi.byte[0],		0,					0,		0xFF},
	{EEPROM_ADDR_HOT_TEMP_SORTING,					EEPROM_DEFAULT_HOT_TEMP_SORTING,			0,				0,				0,				&gu8_f_hot_temp_sorting,					0,					0,		1},
//@035	{EEPROM_ADDR_BLANK_AREA_1,						0,											0,				0,				0,				&gu8_eerpom_blank_area_1,					0,					0,		0xFF},
	{EEPROM_ADDR_HOT_POWER_LEVEL,					EEPROM_DEFAULT_HOT_POWER_LEVEL,				0,				0,				0,				&gu8_Heater__PowerLevel_forEEPROM,						0,					0,		0x02},      //@035 히터 전력 레벨
	//@036	{EEPROM_ADDR_BLANK_AREA_2,						0,											0,				0,				0,				&gu8_eerpom_blank_area_2,					0,					0,		0xFF},
	{EEPROM_ADDR_HEATER_FULL_WATT_HIGH,			EEPROM_DEFAULT_HEATER_FULL_WATT_HIGH,		0,				0,				0,				&gu16_HeaterFull_WATT_forEEPROM.byte[1],	0,					0,		0xFF},			//@036
	//@036	{EEPROM_ADDR_BLANK_AREA_3,						0,											0,				0,				0,				&gu8_eerpom_blank_area_3,					0,					0,		0xFF},
	{EEPROM_ADDR_HEATER_FULL_WATT_LOW,				EEPROM_DEFAULT_HEATER_FULL_WATT_LOW,		0,				0,				0,				&gu16_HeaterFull_WATT_forEEPROM.byte[0],	0,					0,		0xFF},			//@036
	//@037	{EEPROM_ADDR_BLANK_AREA_4,						0,											0,				0,				0,				&gu8_eerpom_blank_area_4,					0,					0,		0xFF},
	{EEPROM_ADDR_STEP_BEFORE_EFF_HIGH,				EEPROM_DEFAULT_STEP_BEFORE_EFF_HIGH,		0,				0,				0,				&gu16_StepCount_BeforeEff_forEEPROM.byte[1],	0,					0,		0xFF},			//@037
	//@037	{EEPROM_ADDR_BLANK_AREA_5,						0,											0,				0,				0,				&gu8_eerpom_blank_area_5,					0,					0,		0xFF},
	{EEPROM_ADDR_STEP_BEFORE_EFF_LOW,				EEPROM_DEFAULT_STEP_BEFORE_EFF_LOW,			0,				0,				0,				&gu16_StepCount_BeforeEff_forEEPROM.byte[0],	0,					0,		0xFF},			//@037
	//@037	{EEPROM_ADDR_BLANK_AREA_6,						0,											0,				0,				0,				&gu8_eerpom_blank_area_6,					0,					0,		0xFF},
	{EEPROM_ADDR_FLOW_BEFORE_EFF,					EEPROM_DEFAULT_FLOW_BEFORE_EFF,				0,				0,				0,				&gu8_FlowDecide_W_BeforeEff_forEEPROM,		0,					0,		0xFF},			//@037
	//@037	{EEPROM_ADDR_BLANK_AREA_7,						0,											0,				0,				0,				&gu8_eerpom_blank_area_7,					0,					0,		0xFF},
	{EEPROM_ADDR_HOT_EFF_MAX,						EEPROM_DEFAULT_HOT_EFF_MAX,					0,				0,				0,				&gu8_FlowDecide_W_HotEffMax_forEEPROM,		0,					0,		0xFF},			//@037
	{EEPROM_ADDR_BLANK_AREA_8,						0,											0,				0,				0,				&gu8_eerpom_blank_area_8,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_9,						0,											0,				0,				0,				&gu8_eerpom_blank_area_9,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_10,					0,											0,				0,				0,				&gu8_eerpom_blank_area_10,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_11,					0,											0,				0,				0,				&gu8_eerpom_blank_area_11,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_12,					0,											0,				0,				0,				&gu8_eerpom_blank_area_12,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_13,					0,											0,				0,				0,				&gu8_eerpom_blank_area_13,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_14,					0,											0,				0,				0,				&gu8_eerpom_blank_area_14,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_15,					0,											0,				0,				0,				&gu8_eerpom_blank_area_15,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_16,					0,											0,				0,				0,				&gu8_eerpom_blank_area_16,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_17,					0,											0,				0,				0,				&gu8_eerpom_blank_area_17,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_18,					0,											0,				0,				0,				&gu8_eerpom_blank_area_18,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_19,					0,											0,				0,				0,				&gu8_eerpom_blank_area_19,					0,					0,		0xFF},
	{EEPROM_ADDR_BLANK_AREA_20,					0,											0,				0,				0,				&gu8_eerpom_blank_area_20,					0,					0,		0xFF},
	{EEPROM_ADDR_CHECKSUM_HIGH,					0,											0,				0,				0,				&gu8_EEPROM_Data_Checksum_High,				0,					0,		0xFF},
	{EEPROM_ADDR_CHECKSUM_LOW,						0,											0,				0,				0,				&gu8_EEPROM_Data_Checksum_Low,				0,					0,		0xFF},
	{EEPROM_ADDR_FIRST_B,							EEPROM_FIRST_B,								0,				0,				0,				&gu8_EEPROM_Data_First_B,					0,					0x55,	0x55},
};

#define Z_TimerEEPROM_Write_Delay	(50)		//	50ms

/// @brief	  EEPROM 占쏙옙占? 占십깍옙화
/// @param    void
/// @return   void
void EEPROM_Initialize(void)
{
	Ini_EEPROM_Control_00();
	Ini_EEPROM_Write_00();
	Ini_EEPROM_Read_00();
}

/// @brief    EEPROM 처占쏙옙 (Main Loop)
/// @param    void
/// @return   void
void EEPROM_Control(void)
{
	if ((gu8_EEPROM_ControlNum < Z_EEPROM_Control_Num_Max) && (gu8_EEPROM_WriteNum < Z_EEPROM_Write_Num_Max) && (gu8_EEPROM_ReadNum < Z_EEPROM_Read_Num_Max))	//	占쏙옙占쏙옙 占쏙옙占? 占쏙옙占쏙옙占쏙옙 占쏙옙占?
	{
		(EEPROM_Control_Table[gu8_EEPROM_ControlNum].exe)();	//	占쌔댐옙 占쏙옙占쏙옙 占쌉쇽옙 占쏙옙占쏙옙
		(EEPROM_Write_Table[gu8_EEPROM_WriteNum].exe)();		//	占쌔댐옙 占쏙옙占쏙옙 占쌉쇽옙 占쏙옙占쏙옙
		(EEPROM_Read_Table[gu8_EEPROM_ReadNum].exe)();			//	占쌔댐옙 占쏙옙占쏙옙 占쌉쇽옙 占쏙옙占쏙옙
	}
	else
	{
		SafetyLoop();
	}
}

/// @brief    EEPROM 占십깍옙화 (占쏙옙占쏙옙占쏙옙A,B 占쏙옙효占쏙옙 체크)
/// @param    void
/// @return   void
void EEPROM_Control_00(void)
{
	static U8 reTry = CLEAR;

	if ((EEPROM_Data_Table[Z_EEPROM_ADDR_FIRST_A].read_flag == CLEAR) && (EEPROM_Data_Table[Z_EEPROM_ADDR_FIRST_B].read_flag == CLEAR)) //	占쏙옙占쏙옙占쏙옙 占싻깍옙 占쏙옙占쏙옙 占쏙옙
	{
		if ((gu8_EEPROM_Data_First_A == EEPROM_FIRST_A) && (gu8_EEPROM_Data_First_B == EEPROM_FIRST_B))		//	占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙 OK占쏙옙 占쏙옙占?
		{
			F_EEPROM_IniRead = SET;
			Ini_EEPROM_Control_20();				//	Data ALL Read
		}
		else
		{
			if (reTry == CLEAR)
			{
				reTry = SET;
				Ini_EEPROM_Control_00();
			}
			else
			{
				Ini_EEPROM_Control_10();				//	Data ALL Clear
			}
		}
	}
}
void Ini_EEPROM_Control_00(void)
{
	EEPROM_Data_Table[Z_EEPROM_ADDR_FIRST_A].read_flag = SET;
	EEPROM_Data_Table[Z_EEPROM_ADDR_FIRST_B].read_flag = SET;
	EEPROM_Control_NoSet(Z_EEPROM_Control_Num_00);
}

/// @brief    EEPROM 占쏙옙占쏙옙占쏙옙 ALL 占십깍옙화
/// @param    void
/// @return   void
void EEPROM_Control_10(void)
{
	U8 i = 0;
	U8 flag = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)		//	占쌤울옙 Write 占쏙옙占쏙옙占쏙옙 확占쏙옙
	{
		if (EEPROM_Data_Table[i].write_flag == SET)		//		占쌤울옙 Write占쏙옙 占쌍댐옙 占쏙옙占?
		{
			flag = SET;									//			flag set
			break;
		}


	}

	if (flag == CLEAR)								//	占쌤울옙 Write 占쏙옙占쏙옙占싶곤옙 占쏙옙占쏙옙 占쏙옙占?
	{
		Ini_EEPROM_Control_30();					//		checksum 확占쏙옙
	}

}
void Ini_EEPROM_Control_10(void)
{
	U8 i = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)	//	占쏙옙 占쏙옙占쏙옙 write set
	{
		EEPROM_Data_Table[i].write_flag = SET;
		if ((i == Z_EEPROM_ADDR_HOTLOCK) && (gu8_ModelType_forNational == MODEL_JAPAN))
		{
			*EEPROM_Data_Table[i].data = SET;		//		占승쇽옙 占쏙옙占? 占쏙옙占쏙옙
		}
		else if ((i == Z_EEPROM_ADDR_SELFSERVICE) && (gu8_ModelType_forNational == MODEL_JAPAN))
		{
			*EEPROM_Data_Table[i].data = SET;		//		占쌘곤옙占쏙옙占쏙옙 占쏙옙占쏙옙
		}
		else if ((i == Z_EEPROM_ADDR_DEFAULT_HOTTEMP) && (gu8_ModelType_forNational == MODEL_JAPAN))
		{
			*EEPROM_Data_Table[i].data = HOT_TEMP_SETUP_KOR70_JP70;		//		70占쏙옙 占쏙옙占쏙옙
		}
		else
		{
			*EEPROM_Data_Table[i].data = EEPROM_Data_Table[i].init_data;	//		占십기값占쏙옙占쏙옙 set
		}
	}

	EEPROM_Control_NoSet(Z_EEPROM_Control_Num_10);
}

/// @brief    EEPROM ALL Read
/// @param    void
/// @return   void
void EEPROM_Control_20(void)
{
	U8 i = 0;
	U8 flag = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)	//	占쌤울옙 read 占쏙옙占쏙옙 확占쏙옙
	{
		if (EEPROM_Data_Table[i].read_flag == SET)	//		占쌤울옙 read占쏙옙 占쌍댐옙 占쏙옙占?
		{
			flag = SET;								//			flag set
			break;
		}
	}

	if (flag == CLEAR)								//	占쌤울옙	read占쏙옙 占쏙옙占쏙옙 占쏙옙占?
	{
		Ini_EEPROM_Control_30();					//		checksum 확占쏙옙
	}
}
void Ini_EEPROM_Control_20(void)
{
	U8 i = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)	//	占쏙옙 占쏙옙占쏙옙 read set
	{
		EEPROM_Data_Table[i].read_flag = SET;
	}

	EEPROM_Control_NoSet(Z_EEPROM_Control_Num_20);
}

/// @brief    EEPROM Checksum 확占쏙옙
/// @param    void
/// @return   void
void EEPROM_Control_30(void)
{
	U8 i = 0;
	U16 checksum_data = 0;
	U16 eeprom_checksum_data = 0;
	static U8 recheck = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_CHECKSUM_HIGH ; i++)	//	checksum 占쏙옙占쏙옙 占쏙옙 占쌍소깍옙占쏙옙 sum
	{
		checksum_data += *EEPROM_Data_Table[i].data;
	}

	//	EEPROM 占쌍쇽옙 占쏙옙占쏙옙 占쏙옙占쏙옙 sum占쏙옙占쏙옙 占쏙옙
	//	eeprom_checksum_data = ((*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_HIGH].data) << 8) | *EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_LOW].data;
		eeprom_checksum_data = ((U16)(*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_HIGH].data) << 8) | (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_LOW].data;
	//	eeprom_checksum_data = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_HIGH].data) << 8) | (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_LOW].data;

	if (checksum_data == eeprom_checksum_data)		//	占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙占쏙옙 占쏙옙占?
	{
		Ini_EEPROM_Control_40();					//		占싹뱄옙 占쏙옙占쏙옙

		gu16_CupSize_My = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CUPSIZE_MY_HIGH].data << 8) & 0xFF00U);
		gu16_CupSize_My |= (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CUPSIZE_MY_LOW].data & 0x00FFU;

		gu16_DayCount_forFilter = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Filter_HIGH].data << 8) & 0xFF00U);
		gu16_DayCount_forFilter |= (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Filter_LOW].data & 0x00FFU;

		gu16_DayCount_forFaucet = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Faucet_HIGH].data << 8) & 0xFF00U);
		gu16_DayCount_forFaucet |= (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Faucet_LOW].data & 0x00FFU;

		gu16_Cooling_TargetDegree = (U16)gu8_Cooling_TargetDegree_forEEPROM;	
	}
	else
	{
		if (recheck == SET)		//		1회占쏙옙 all re wirte 占실댐옙
		{
			Ini_EEPROM_Control_40();				//			1회 占쏙옙 占쏙옙占쏙옙 占싹뱄옙 占쏙옙占쏙옙
		}
		else
		{
			recheck = SET;
			if (F_EEPROM_IniRead == SET)
			{
				Ini_EEPROM_Control_20();				//	Data ALL Read
			}
			else
			{
				Ini_EEPROM_Control_10();				//	Data ALL Clear
			}
		}
	}
}
void Ini_EEPROM_Control_30(void)
{
	EEPROM_Control_NoSet(Z_EEPROM_Control_Num_30);
}

/// @brief    EEPROM 占싹뱄옙 占쏙옙占쏙옙 (占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙  Write)
/// @param    void
/// @return   void
void EEPROM_Control_40(void)
{
	U8 i = 0;
	U16 buf = 0;

	//	My占쎈량 2占쏙옙占쏙옙트 Write 체크
	buf = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CUPSIZE_MY_HIGH].data << 8) & 0xFF00U);
	buf |= (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CUPSIZE_MY_LOW].data & 0x00FFU;
	if (gu16_CupSize_My != buf)
	{
		gu8_CupSize_My_High = (U8)((gu16_CupSize_My >> 8) & 0xFFU);
		gu8_CupSize_My_Low = (U8)(gu16_CupSize_My & 0xFFU);
	}

	//	占쏙옙占쏙옙 占쏙옙占쏙옙占? 2占쏙옙占쏙옙트 Write 체크
	buf = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Filter_HIGH].data << 8) & 0xFF00U);
	buf |= (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Filter_LOW].data & 0x00FFU;
	if (gu16_DayCount_forFilter != buf)
	{
		gu8_UseDay_forCNT_Filter_High = (U8)((gu16_DayCount_forFilter >> 8) & 0xFFU);
		gu8_UseDay_forCNT_Filter_Low = (U8)(gu16_DayCount_forFilter & 0xFFU);
	}

	//	占쏙옙占싸몌옙占? 占쏙옙占쏙옙占? 2占쏙옙占쏙옙트 Write 체크
	buf = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Faucet_HIGH].data << 8) & 0xFF00U);
	buf |= (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Faucet_LOW].data & 0x00FFU;
	if (gu16_DayCount_forFaucet != buf)
	{
		gu8_UseDay_forCNT_Faucet_High = (U8)((gu16_DayCount_forFaucet >> 8) & 0xFFU);
		gu8_UseDay_forCNT_Faucet_Low = (U8)(gu16_DayCount_forFaucet & 0xFFU);
	}

	if (gu8_Cooling_TargetDegree_forEEPROM != (U8)gu16_Cooling_TargetDegree)	
	{                                                                           
		gu8_Cooling_TargetDegree_forEEPROM = (U8)gu16_Cooling_TargetDegree;     
	}                                                                           

	for (i = 0 ; i < Z_EEPROM_ADDR_CHECKSUM_HIGH ; i++)	//	checksum 占쌍쇽옙 占쏙옙占쏙옙占쏙옙
	{
		if (*EEPROM_Data_Table[i].data == EEPROM_Data_Table[i].eeprom_data)	//	占쏙옙占쏙옙 占쏙옙占쏙옙占싶울옙 占쏙옙占쏙옙 占쏙옙占쏙옙占? EEPROM占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙占? (占쌕몌옙占쏙옙占? 타占싱머몌옙 占쏙옙占? Write占쏙옙占쏙옙)
		{
			EEPROM_Data_Table[i].write_timer = Z_EEPROM_Write_Timer_Delay;
		}

		if (EEPROM_Data_Table[i].write_timer == 0)	//		write 타占싱몌옙 占쏙옙占쏙옙占? 占쏙옙占?
		{
			if (F_TestMode.byte == 0x00)			//		占쌓쏙옙트 占쏙옙弱? 占싣닌곤옙占?
			{
				EEPROM_Data_Table[i].write_flag = SET;	//			write flag set
			}
		}
	}

	if (F_EEPROM_Forced_Initialize == SET)			//	EEPROM 占쏙옙占쏙옙 占십깍옙화 占쏙옙 占쏙옙占?
	{
		F_EEPROM_Forced_Initialize = CLEAR;			//		flag clear
		Ini_EEPROM_Control_10();					//		EEPROM all clear
	}
}
void Ini_EEPROM_Control_40(void)
{
	F_FirstEEPROM_Read = SET;						//	占쏙옙占쏙옙 占싻깍옙 占싹뤄옙 flag
	EEPROM_Control_NoSet(Z_EEPROM_Control_Num_40);
}

/// @brief    EEPROM 처占쏙옙 Step
/// @param    void
/// @return   void
static void EEPROM_Control_NoSet(U8 data)
{
	static const U8 DT_EEPROM_ControlNumber[] =
	{
		Z_EEPROM_Control_00,
		Z_EEPROM_Control_10,
		Z_EEPROM_Control_20,
		Z_EEPROM_Control_30,
		Z_EEPROM_Control_40,
	};
	/************************************************/
	gu8_EEPROM_ControlNum = data; 								/*	占싹뤄옙 占쏙옙호 set*/

	gu8_EEPROM_Control = DT_EEPROM_ControlNumber[gu8_EEPROM_ControlNum];	/*	占쏙옙占쏙옙 mode No. set*/
}

/// @brief    EEPROM Write 占십깍옙화
/// @param    void
/// @return   void
void EEPROM_Write_00(void)
{
	Ini_EEPROM_Write_10();
}
void Ini_EEPROM_Write_00(void)
{
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_00);
}

/// @brief    EEPROM Write Flag 확占쏙옙
/// @param    void
/// @return   void
void EEPROM_Write_10(void)
{
	U8 i = 0;

	if (gu8_EEPROM_Read <= Z_EEPROM_Read_10)
	{
		for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)
		{
			if (EEPROM_Data_Table[i].write_flag == SET)	//	write 占쏙옙占시곤옙 占쌍댐옙 占쏙옙占?
			{
				gu8_EEPROM_OperNum = i;					//		占쌔댐옙 占쌍쇽옙 占싼뱄옙占쏙옙 占쏙옙占쏙옙
				gu8_TxBuf[0] = (U8)(EEPROM_Data_Table[i].address & 0xFF);	//		占쌍쇽옙占쌉뤄옙
				gu8_TxBuf[1] = *EEPROM_Data_Table[i].data;		//		占쏙옙占쏙옙占쏙옙 占쌉뤄옙
				EEPROM_Data_Table[i].eeprom_data = *EEPROM_Data_Table[i].data;	//		EEPROM 占쏙옙占쏙옙占쏙옙 占쌉뤄옙
				Ini_EEPROM_Write_20();					//		write 占쏙옙占쏙옙
				break;
			}
		}
	}
}
void Ini_EEPROM_Write_10(void)
{
	gu8_EEPROM_OperNum = 0;
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_10);
}

/// @brief    EEPROM Write 占쏙옙占쏙옙
/// @param    void
/// @return   void
void EEPROM_Write_20(void)
{
	if (gu8_TimerEEPROM_Write_Delay == 0)			//	50ms
	{
		R_IICA0_Master_Send(_A0_IICA0_MASTERADDRESS, gu8_TxBuf, 2, 0);		//		占쏙옙占? 占쏙옙占쏙옙
		Ini_EEPROM_Write_21();						//		占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙
	}
}
void Ini_EEPROM_Write_20(void)
{
	gu8_TimerEEPROM_Write_Delay = Z_TimerEEPROM_Write_Delay;
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_20);
}

/// @brief    EEPROM Write 占쏙옙占쏙옙 확占쏙옙
/// @param    void
/// @return   void
void EEPROM_Write_21(void)
{
	U8 i = 0;
	U8 flag = CLEAR;

	if (0U == IICBSY0)								//	busy 占쏙옙占쏙옙
	{
		Ini_EEPROM_Write_22();						//		write confirm
	}
	else if (gu8_TimerEEPROM_Limit == 0)			//	占쏙옙占쏙옙트 타占싱몌옙
	{
		Ini_EEPROM_Write_10();						//		占쏙옙蒐븝옙占?
		F_EEPROM_CommunicationError = SET;			//		占쏙옙占쏙옙 flag set
	}
	else
	{

	}
}
void Ini_EEPROM_Write_21(void)
{
	gu8_TimerEEPROM_Limit = Z_TimerEEPROM_Limit;
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_21);
}

/// @brief    Write/Address 占쌜쏙옙 (Write Confirm)
/// @param    void
/// @return   void
void EEPROM_Write_22(void)
{
	if (gu8_TimerEEPROM_Write_Delay == 0)			//	占쏙옙占? 타占싱몌옙 占쏙옙占? 占쏙옙
	{
		R_IICA0_Master_Send(_A0_IICA0_MASTERADDRESS, gu8_TxBuf, 1, 0);	//	占쌍쇽옙 占쏙옙占쏙옙占쏙옙 占쌜쏙옙
		Ini_EEPROM_Write_23();
	}
}
void Ini_EEPROM_Write_22(void)
{
	gu8_TimerEEPROM_Write_Delay = Z_TimerEEPROM_Write_Delay;
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_22);
}

/// @brief    Read CMD 占쌜쏙옙 (Write Confirm)
/// @param    void
/// @return   void
void EEPROM_Write_23(void)
{
	U8 i = 0;
	U8 flag = 0;

	if (0U == IICBSY0)								//	busy 체크
	{
		R_IICA0_Master_Receive(_A0_IICA0_MASTERADDRESS, &gu8_RxBuf, 1, 0);	//		占쏙옙占쏙옙占쏙옙 占싻깍옙
		Ini_EEPROM_Write_24();
	}
	else if (gu8_TimerEEPROM_Limit == 0)			//	占쏙옙占쏙옙트 타占싱몌옙
	{
		Ini_EEPROM_Write_10();						//		占쏙옙占? 占쏙옙占쏙옙
		F_EEPROM_CommunicationError = SET;			//		占쏙옙占쏙옙 flag set
	}
	else
	{

	}
}
void Ini_EEPROM_Write_23(void)
{
	gu8_TimerEEPROM_Limit = Z_TimerEEPROM_Limit;
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_23);
}

/// @brief    Read 占쏙옙占쏙옙 占쏙옙占?
/// @param    void
/// @return   void
void EEPROM_Write_24(void)
{
	U8 i = 0;
	U8 flag = 0;
	static U8 flag_reWrite = 0;

	if (0U == IICBSY0)								//	busy 체크
	{
		EEPROM_Data_Table[gu8_EEPROM_OperNum].write_flag = CLEAR;	//		write flag clear
		if (gu8_RxBuf == EEPROM_Data_Table[gu8_EEPROM_OperNum].eeprom_data)	//		占쏙옙占쏙옙 占쏙옙占쏙옙占싶울옙 占쏙옙占쏙옙 占쏙옙占쏙옙占싶곤옙 占쏙옙占쏙옙占쏙옙 占쏙옙占?
		{
			flag_reWrite = CLEAR;
			for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)		//		占쌤울옙 write 확占쏙옙
			{
				if (EEPROM_Data_Table[i].write_flag == SET)
				{
					flag = SET;
					break;
				}
			}

			if (flag == SET)						//		占쌤울옙 write占쏙옙 占쌍댐옙 占쏙옙占?
			{
				Ini_EEPROM_Write_10();				//			占쏙옙占? 占쏙옙占쏙옙
			}
			else									//		占쌤울옙 write占쏙옙 占쏙옙占쏙옙 占쏙옙占?
			{
				if (F_Checksum_Write == CLEAR)		//			Checksum write 占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙占?
				{
					Ini_EEPROM_Write_30();			//				Checksum write
				}
				else
				{
					F_Checksum_Write = CLEAR;		//			Checksum write clear
					Ini_EEPROM_Write_10();			//
				}
			}
		}
		else										//		占쏙옙占쏙옙 占쏙옙占쏙옙占싶울옙 占쏙옙占쏙옙 占쏙옙占쏙옙占싶곤옙 占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙占?
		{
			if (flag_reWrite == CLEAR)				//			re-Write 占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙占?
			{
				EEPROM_Data_Table[gu8_EEPROM_OperNum].write_flag =  SET; 	//	re-Write 占시듸옙 1회
				flag_reWrite = SET;					//				re-Write 占쏙옙占쏙옙 set
			}
			else
			{
				if (gu8_EEPROM_OperNum == (Z_EEPROM_ADDR_Data_Max-1))
				{
					F_EEPROM_CommunicationError = SET;
				}
				flag_reWrite = CLEAR;
			}
			Ini_EEPROM_Write_10();
		}
	}
	else if (gu8_TimerEEPROM_Limit == 0)			//	占쏙옙占쏙옙트 타占싱몌옙
	{
		Ini_EEPROM_Write_10();						//		占쏙옙占? 占쏙옙占쏙옙
		F_EEPROM_CommunicationError = SET;			//		占쏙옙占쏙옙 占시뤄옙占쏙옙 set
	}
	else
	{

	}
}
void Ini_EEPROM_Write_24(void)
{
	gu8_TimerEEPROM_Limit = Z_TimerEEPROM_Limit;
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_24);
	R_IICA0_Master_Receive(_A0_IICA0_MASTERADDRESS, &gu8_RxBuf, 1, 0);
}

/// @brief    Checksum Write
/// @param    void
/// @return   void
void EEPROM_Write_30(void)
{
	U8 i = 0;
	U16 checksum_data = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_CHECKSUM_HIGH ; i++)	//	Checksum 占쌍쇽옙 占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙 sum
	{
		checksum_data += *EEPROM_Data_Table[i].data;
	}

	gu8_EEPROM_Data_Checksum_High = (U8)((checksum_data >> 8) & 0xFF);	//	2占쏙옙占쏙옙트 High 1占쏙옙占쏙옙트 占쏙옙占쏙옙
	gu8_EEPROM_Data_Checksum_Low = (U8)(checksum_data & 0xFF);	//	2占쏙옙占쏙옙트 Low 2占쏙옙占쏙옙트 占쏙옙占쏙옙

	EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_HIGH].write_flag = SET;	//	High write set
	EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_LOW].write_flag = SET;		//	Low write set

	Ini_EEPROM_Write_10();
}
void Ini_EEPROM_Write_30(void)
{
	F_Checksum_Write = SET;							//	chekcsum Write flag set
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_30);
}

/// @brief    EEPROM Write 占쏙옙占쏙옙
/// @param    void
/// @return   void
static void EEPROM_Write_NoSet(U8 data)
{
	static const U8 DT_EEPROM_WriteNumber[] =
	{
		Z_EEPROM_Write_00,
		Z_EEPROM_Write_10,
		Z_EEPROM_Write_20,
		Z_EEPROM_Write_21,
		Z_EEPROM_Write_22,
		Z_EEPROM_Write_23,
		Z_EEPROM_Write_24,
		Z_EEPROM_Write_30,
	};
	/************************************************/
	gu8_EEPROM_WriteNum = data; 								/*	占싹뤄옙 占쏙옙호 set*/

	gu8_EEPROM_Write = DT_EEPROM_WriteNumber[gu8_EEPROM_WriteNum];	/*	占쏙옙占쏙옙 mode No. set*/
}

/// @brief    EEPROM 占싻깍옙 占십깍옙화
/// @param    void
/// @return   void
void EEPROM_Read_00(void)
{
	Ini_EEPROM_Read_10();
}
void Ini_EEPROM_Read_00(void)
{
	EEPROM_Read_NoSet(Z_EEPROM_Read_Num_00);
}

/// @brief    EEPROM 占싻깍옙 占쏙옙占?
/// @param    void
/// @return   void
void EEPROM_Read_10(void)
{
	U8 i = 0;

	if (gu8_EEPROM_Write <= Z_EEPROM_Write_10)
	{
		for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)
		{
			if (EEPROM_Data_Table[i].read_flag == SET)	//		占싻깍옙 占썰구占쏙옙 占쌍댐옙 占쏙옙占?
			{
				gu8_EEPROM_OperNum = i;					//		占쌍쇽옙 占싼뱄옙占쏙옙 占쏙옙占쏙옙
				gu8_TxBuf[0] = (U8)(EEPROM_Data_Table[i].address & 0xFF);	//		占쌍쇽옙 占쏙옙占쏙옙占쏙옙 set
				Ini_EEPROM_Read_20();
				break;
			}
		}
	}
}
void Ini_EEPROM_Read_10(void)
{
	U8 i = 0;
	gu8_EEPROM_OperNum = 0;

//	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max; i++)
//	{
//		EEPROM_Data_Table[i].read_flag = CLEAR;
//	}
	EEPROM_Read_NoSet(Z_EEPROM_Read_Num_10);
}

/// @brief    EEPROM 占싻깍옙 Addr 占쌜쏙옙
/// @param    void
/// @return   void
void EEPROM_Read_20(void)
{
	Ini_EEPROM_Read_21();
	R_IICA0_Master_Send(_A0_IICA0_MASTERADDRESS, gu8_TxBuf, 1, 0);	//		占싻깍옙 占쌍쇽옙 占쌜쏙옙
}
void Ini_EEPROM_Read_20(void)
{
	EEPROM_Read_NoSet(Z_EEPROM_Read_Num_20);
}

/// @brief    EEPROM 占싻깍옙 Read CMD 占쌜쏙옙
/// @param    void
/// @return   void
void EEPROM_Read_21(void)
{
	if (0U == IICBSY0)								//	busy 체크
	{
		Ini_EEPROM_Read_22();
		R_IICA0_Master_Receive(_A0_IICA0_MASTERADDRESS, &gu8_RxBuf, 1, 0);	//	Read CMD 占쌜쏙옙
	}
}
void Ini_EEPROM_Read_21(void)
{
	EEPROM_Read_NoSet(Z_EEPROM_Read_Num_21);
}

/// @brief    EEPROM 占싻깍옙 占싹뤄옙 占쏙옙占?
/// @param    void
/// @return   void
void EEPROM_Read_22(void)
{
	if (0U == IICBSY0)								//	busy check
	{
		if ((gu8_RxBuf >= EEPROM_Data_Table[gu8_EEPROM_OperNum].data_valid_check_lower) && (gu8_RxBuf <= EEPROM_Data_Table[gu8_EEPROM_OperNum].data_valid_check_upper))	//	占쏙옙占쏙옙 占쏙옙占쏙옙占쏙옙 占쏙옙효占쏙옙 체크
		{
			*EEPROM_Data_Table[gu8_EEPROM_OperNum].data = gu8_RxBuf;	//	占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙
			EEPROM_Data_Table[gu8_EEPROM_OperNum].eeprom_data = *EEPROM_Data_Table[gu8_EEPROM_OperNum].data;	//	占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙

//			if (EEPROM_Data_Table[gu8_EEPROM_OperNum].address == EEPROM_ADDR_FILTERMODULE1_AMOUNT_USED_HIGH)
//			{
//				gu16_Effluent_1L_FilterModule1 |= (((U16)*EEPROM_Data_Table[gu8_EEPROM_OperNum].data << 8) & 0xFF00U);
//			}
//			else if (EEPROM_Data_Table[gu8_EEPROM_OperNum].address == EEPROM_ADDR_FILTERMODULE1_AMOUNT_USED_LOW)
//			{
//				gu16_Effluent_1L_FilterModule1 |= (U16)*EEPROM_Data_Table[gu8_EEPROM_OperNum].data & 0x00FFU;
//			}
//			else if (EEPROM_Data_Table[gu8_EEPROM_OperNum].address == EEPROM_ADDR_FILTERMODULE2_AMOUNT_USED_HIGH)
//			{
//				gu16_Effluent_1L_FilterModule2 |= (((U16)*EEPROM_Data_Table[gu8_EEPROM_OperNum].data << 8) & 0xFF00U);
//			}
//			else if (EEPROM_Data_Table[gu8_EEPROM_OperNum].address == EEPROM_ADDR_FILTERMODULE2_AMOUNT_USED_LOW)
//			{
//				gu16_Effluent_1L_FilterModule2 |= (U16)*EEPROM_Data_Table[gu8_EEPROM_OperNum].data & 0x00FFU;
//			}
//			else
//			{
//
//			}
		}
		else										//		占쏙옙효占쏙옙 NG占쏙옙 占쏙옙占?
		{
			if ((gu8_EEPROM_OperNum != Z_EEPROM_ADDR_FIRST_A) && (gu8_EEPROM_OperNum != Z_EEPROM_ADDR_FIRST_B))		//	占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙占싶곤옙 占싣댐옙 占쏙옙占?
			{
				*EEPROM_Data_Table[gu8_EEPROM_OperNum].data = EEPROM_Data_Table[gu8_EEPROM_OperNum].init_data;	//	占십기값 占쏙옙占쏙옙
				EEPROM_Data_Table[gu8_EEPROM_OperNum].eeprom_data = *EEPROM_Data_Table[gu8_EEPROM_OperNum].data;	//	占십기값 占쏙옙占쏙옙
			}
		}
		EEPROM_Data_Table[gu8_EEPROM_OperNum].read_flag = CLEAR;	//		Read flag clear
		Ini_EEPROM_Read_10();
	}
	else if (gu8_TimerEEPROM_Limit == 0)			//	占쏙옙占쏙옙트 타占싱몌옙
	{
		Ini_EEPROM_Read_10();
		F_EEPROM_CommunicationError = SET;
	}
	else
	{

	}
}
void Ini_EEPROM_Read_22(void)
{
	gu8_TimerEEPROM_Limit = Z_TimerEEPROM_Limit;
	EEPROM_Read_NoSet(Z_EEPROM_Read_Num_22);
}
/// @brief    EEPROM Read 占쏙옙占쏙옙
/// @param    void
/// @return   void
static void EEPROM_Read_NoSet(U8 data)
{
	static const U8 DT_EEPROM_ReadNumber[] =
	{
		Z_EEPROM_Read_00,
		Z_EEPROM_Read_10,
		Z_EEPROM_Read_20,
		Z_EEPROM_Read_21,
		Z_EEPROM_Read_22,
	};
	/************************************************/
	gu8_EEPROM_ReadNum = data; 								/*	占싹뤄옙 占쏙옙호 set*/

	gu8_EEPROM_Read = DT_EEPROM_ReadNumber[gu8_EEPROM_ReadNum];	/*	占쏙옙占쏙옙 mode No. set*/
}
