/// @file     eeprom.c
/// @date     2019.07.10
/// @author   PSM
/// @brief    EEPROM ���� ���� file
#define EEPROM_C
#include "include/_include.h"

void EEPROM_Control_00(void);       	//	���� �� AA,55 ������ Ȯ��
void EEPROM_Control_10(void);			//	������ ALL �ʱ�ȭ Write
void EEPROM_Control_20(void);			//	������ ALL Read
void EEPROM_Control_30(void);			//	Checksum Ȯ��
void EEPROM_Control_40(void);			//	�Ϲ� ����

void Ini_EEPROM_Control_00(void);       //	���� �� AA,55 ������ Ȯ��
void Ini_EEPROM_Control_10(void);		//	������ ALL �ʱ�ȭ Write
void Ini_EEPROM_Control_20(void);		//	������ ALL Read
void Ini_EEPROM_Control_30(void);		//	Checksum Ȯ��
void Ini_EEPROM_Control_40(void);		//	�Ϲ� ����

static void EEPROM_Control_NoSet(U8 data);

void EEPROM_Write_00(void);				//	�ʱ�ȭ
void EEPROM_Write_10(void);				//	���?
void EEPROM_Write_20(void);				//	Write ����
void EEPROM_Write_21(void);				//	Write ����
void EEPROM_Write_22(void);				//	Write/Address �۽� (Write Confrim-1)
void EEPROM_Write_23(void);				//	Read CMD �۽� (Write Confrim-2)
void EEPROM_Write_24(void);				//	Read ���� ���?
void EEPROM_Write_30(void);				//	Checksum Write

void Ini_EEPROM_Write_00(void);			//	�ʱ�ȭ
void Ini_EEPROM_Write_10(void);			//	���?
void Ini_EEPROM_Write_20(void);			//	Write ����
void Ini_EEPROM_Write_21(void);			//	Write ����
void Ini_EEPROM_Write_22(void);			//	Write/Address �۽� (Write Confrim-1)
void Ini_EEPROM_Write_23(void);			//	Read CMD �۽� (Write Confrim-2)
void Ini_EEPROM_Write_24(void);			//	Read ���� ���?
void Ini_EEPROM_Write_30(void);			//	Checksum Write

static void EEPROM_Write_NoSet(U8 data);

void EEPROM_Read_00(void);     			//	�ʱ�ȭ
void EEPROM_Read_10(void);				//	���?
void EEPROM_Read_20(void);				//	Write/Address �۽�
void EEPROM_Read_21(void);				//	Read CMD �۽�
void EEPROM_Read_22(void);				//	Read ���� ���?

void Ini_EEPROM_Read_00(void);      	//	�ʱ�ȭ
void Ini_EEPROM_Read_10(void);			//	���?
void Ini_EEPROM_Read_20(void);			//	Write/Address �۽�
void Ini_EEPROM_Read_21(void);			//	Read CMD �۽�
void Ini_EEPROM_Read_22(void);			//	Read ���� ���?

static void EEPROM_Read_NoSet(U8 data);

EEPROM_StepTable EEPROM_Control_Table[Z_EEPROM_Control_Num_Max] =
{
	//	���� No				Step Func.
	{ Z_EEPROM_Control_00,	EEPROM_Control_00 },	//	���� �� AA,55 ������ Ȯ��
	{ Z_EEPROM_Control_10,	EEPROM_Control_10 },	//	������ ALL �ʱ�ȭ Write
	{ Z_EEPROM_Control_20,	EEPROM_Control_20 },	//	������ ALL Read
	{ Z_EEPROM_Control_30,	EEPROM_Control_30 },	//	Checksum Ȯ��
	{ Z_EEPROM_Control_40,	EEPROM_Control_40 },	//	�Ϲ� ����
};

EEPROM_StepTable EEPROM_Write_Table[Z_EEPROM_Write_Num_Max] =
{
	//	���� No				Step Func.
	{ Z_EEPROM_Write_00,	EEPROM_Write_00 },		//	�ʱ�ȭ
	{ Z_EEPROM_Write_10,	EEPROM_Write_10 },		//	���?
	{ Z_EEPROM_Write_20,	EEPROM_Write_20 },		//	Write ����
	{ Z_EEPROM_Write_21,	EEPROM_Write_21 },		//	Write ����
	{ Z_EEPROM_Write_22,	EEPROM_Write_22 },     	//	Write/Address �۽�
	{ Z_EEPROM_Write_23,	EEPROM_Write_23 },     	//	Read CMD �۽� (Write Confirm)
	{ Z_EEPROM_Write_24,	EEPROM_Write_24 },     	//	Read ���� ���?
	{ Z_EEPROM_Write_30,	EEPROM_Write_30 },		//	Checksum Write
};

EEPROM_StepTable EEPROM_Read_Table[Z_EEPROM_Read_Num_Max] =
{
	//	���� No				Step Func.
	{ Z_EEPROM_Read_00,		EEPROM_Read_00 },     	//	�ʱ�ȭ
	{ Z_EEPROM_Read_10,		EEPROM_Read_10 },     	//	���?
	{ Z_EEPROM_Read_20,		EEPROM_Read_20 },     	//	Write/Address �۽�
	{ Z_EEPROM_Read_21,		EEPROM_Read_21 },     	//	Read CMD �۽�
	{ Z_EEPROM_Read_22,		EEPROM_Read_22 },     	//	Read ���� ���?
};

/* �� 16bit dat HIGH, LOW�� Read�� �� ������ ������ �ִ� �۾� �������?. void EEPROM_Control_30(void) �Լ� ���� */
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
	{EEPROM_ADDR_HOT_POWER_LEVEL,					EEPROM_DEFAULT_HOT_POWER_LEVEL,				0,				0,				0,				&gu8_Heater__PowerLevel_forEEPROM,						0,					0,		0x02},      //@035 ���� ���� ����
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

/// @brief	  EEPROM ���? �ʱ�ȭ
/// @param    void
/// @return   void
void EEPROM_Initialize(void)
{
	Ini_EEPROM_Control_00();
	Ini_EEPROM_Write_00();
	Ini_EEPROM_Read_00();
}

/// @brief    EEPROM ó�� (Main Loop)
/// @param    void
/// @return   void
void EEPROM_Control(void)
{
	if ((gu8_EEPROM_ControlNum < Z_EEPROM_Control_Num_Max) && (gu8_EEPROM_WriteNum < Z_EEPROM_Write_Num_Max) && (gu8_EEPROM_ReadNum < Z_EEPROM_Read_Num_Max))	//	���� ���? ������ ���?
	{
		(EEPROM_Control_Table[gu8_EEPROM_ControlNum].exe)();	//	�ش� ���� �Լ� ����
		(EEPROM_Write_Table[gu8_EEPROM_WriteNum].exe)();		//	�ش� ���� �Լ� ����
		(EEPROM_Read_Table[gu8_EEPROM_ReadNum].exe)();			//	�ش� ���� �Լ� ����
	}
	else
	{
		SafetyLoop();
	}
}

/// @brief    EEPROM �ʱ�ȭ (������A,B ��ȿ�� üũ)
/// @param    void
/// @return   void
void EEPROM_Control_00(void)
{
	static U8 reTry = CLEAR;

	if ((EEPROM_Data_Table[Z_EEPROM_ADDR_FIRST_A].read_flag == CLEAR) && (EEPROM_Data_Table[Z_EEPROM_ADDR_FIRST_B].read_flag == CLEAR)) //	������ �б� ���� ��
	{
		if ((gu8_EEPROM_Data_First_A == EEPROM_FIRST_A) && (gu8_EEPROM_Data_First_B == EEPROM_FIRST_B))		//	������ ������ OK�� ���?
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

/// @brief    EEPROM ������ ALL �ʱ�ȭ
/// @param    void
/// @return   void
void EEPROM_Control_10(void)
{
	U8 i = 0;
	U8 flag = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)		//	�ܿ� Write ������ Ȯ��
	{
		if (EEPROM_Data_Table[i].write_flag == SET)		//		�ܿ� Write�� �ִ� ���?
		{
			flag = SET;									//			flag set
			break;
		}


	}

	if (flag == CLEAR)								//	�ܿ� Write �����Ͱ� ���� ���?
	{
		Ini_EEPROM_Control_30();					//		checksum Ȯ��
	}

}
void Ini_EEPROM_Control_10(void)
{
	U8 i = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)	//	�� ���� write set
	{
		EEPROM_Data_Table[i].write_flag = SET;
		if ((i == Z_EEPROM_ADDR_HOTLOCK) && (gu8_ModelType_forNational == MODEL_JAPAN))
		{
			*EEPROM_Data_Table[i].data = SET;		//		�¼� ���? ����
		}
		else if ((i == Z_EEPROM_ADDR_SELFSERVICE) && (gu8_ModelType_forNational == MODEL_JAPAN))
		{
			*EEPROM_Data_Table[i].data = SET;		//		�ڰ����� ����
		}
		else if ((i == Z_EEPROM_ADDR_DEFAULT_HOTTEMP) && (gu8_ModelType_forNational == MODEL_JAPAN))
		{
			*EEPROM_Data_Table[i].data = HOT_TEMP_SETUP_KOR70_JP70;		//		70�� ����
		}
		else
		{
			*EEPROM_Data_Table[i].data = EEPROM_Data_Table[i].init_data;	//		�ʱⰪ���� set
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

	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)	//	�ܿ� read ���� Ȯ��
	{
		if (EEPROM_Data_Table[i].read_flag == SET)	//		�ܿ� read�� �ִ� ���?
		{
			flag = SET;								//			flag set
			break;
		}
	}

	if (flag == CLEAR)								//	�ܿ�	read�� ���� ���?
	{
		Ini_EEPROM_Control_30();					//		checksum Ȯ��
	}
}
void Ini_EEPROM_Control_20(void)
{
	U8 i = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)	//	�� ���� read set
	{
		EEPROM_Data_Table[i].read_flag = SET;
	}

	EEPROM_Control_NoSet(Z_EEPROM_Control_Num_20);
}

/// @brief    EEPROM Checksum Ȯ��
/// @param    void
/// @return   void
void EEPROM_Control_30(void)
{
	U8 i = 0;
	U16 checksum_data = 0;
	U16 eeprom_checksum_data = 0;
	static U8 recheck = 0;

	for (i = 0 ; i < Z_EEPROM_ADDR_CHECKSUM_HIGH ; i++)	//	checksum ���� �� �ּұ��� sum
	{
		checksum_data += *EEPROM_Data_Table[i].data;
	}

	//	EEPROM �ּ� ���� ���� sum���� ��
	//	eeprom_checksum_data = ((*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_HIGH].data) << 8) | *EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_LOW].data;
		eeprom_checksum_data = ((U16)(*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_HIGH].data) << 8) | (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_LOW].data;
	//	eeprom_checksum_data = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_HIGH].data) << 8) | (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_LOW].data;

	if (checksum_data == eeprom_checksum_data)		//	���� �������� ���?
	{
		Ini_EEPROM_Control_40();					//		�Ϲ� ����

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
		if (recheck == SET)		//		1ȸ�� all re wirte �Ǵ�
		{
			Ini_EEPROM_Control_40();				//			1ȸ �� ���� �Ϲ� ����
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

/// @brief    EEPROM �Ϲ� ���� (������ ���� ��  Write)
/// @param    void
/// @return   void
void EEPROM_Control_40(void)
{
	U8 i = 0;
	U16 buf = 0;

	//	My�뷮 2����Ʈ Write üũ
	buf = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CUPSIZE_MY_HIGH].data << 8) & 0xFF00U);
	buf |= (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_CUPSIZE_MY_LOW].data & 0x00FFU;
	if (gu16_CupSize_My != buf)
	{
		gu8_CupSize_My_High = (U8)((gu16_CupSize_My >> 8) & 0xFFU);
		gu8_CupSize_My_Low = (U8)(gu16_CupSize_My & 0xFFU);
	}

	//	���� �����? 2����Ʈ Write üũ
	buf = (((U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Filter_HIGH].data << 8) & 0xFF00U);
	buf |= (U16)*EEPROM_Data_Table[Z_EEPROM_ADDR_USEDAY_forCNT_Filter_LOW].data & 0x00FFU;
	if (gu16_DayCount_forFilter != buf)
	{
		gu8_UseDay_forCNT_Filter_High = (U8)((gu16_DayCount_forFilter >> 8) & 0xFFU);
		gu8_UseDay_forCNT_Filter_Low = (U8)(gu16_DayCount_forFilter & 0xFFU);
	}

	//	���θ��? �����? 2����Ʈ Write üũ
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

	for (i = 0 ; i < Z_EEPROM_ADDR_CHECKSUM_HIGH ; i++)	//	checksum �ּ� ������
	{
		if (*EEPROM_Data_Table[i].data == EEPROM_Data_Table[i].eeprom_data)	//	���� �����Ϳ� ���� �����? EEPROM���� ���� ���? (�ٸ����? Ÿ�̸Ӹ� ���? Write����)
		{
			EEPROM_Data_Table[i].write_timer = Z_EEPROM_Write_Timer_Delay;
		}

		if (EEPROM_Data_Table[i].write_timer == 0)	//		write Ÿ�̸� �����? ���?
		{
			if (F_TestMode.byte == 0x00)			//		�׽�Ʈ ���? �ƴѰ��?
			{
				EEPROM_Data_Table[i].write_flag = SET;	//			write flag set
			}
		}
	}

	if (F_EEPROM_Forced_Initialize == SET)			//	EEPROM ���� �ʱ�ȭ �� ���?
	{
		F_EEPROM_Forced_Initialize = CLEAR;			//		flag clear
		Ini_EEPROM_Control_10();					//		EEPROM all clear
	}
}
void Ini_EEPROM_Control_40(void)
{
	F_FirstEEPROM_Read = SET;						//	���� �б� �Ϸ� flag
	EEPROM_Control_NoSet(Z_EEPROM_Control_Num_40);
}

/// @brief    EEPROM ó�� Step
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
	gu8_EEPROM_ControlNum = data; 								/*	�Ϸ� ��ȣ set*/

	gu8_EEPROM_Control = DT_EEPROM_ControlNumber[gu8_EEPROM_ControlNum];	/*	���� mode No. set*/
}

/// @brief    EEPROM Write �ʱ�ȭ
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

/// @brief    EEPROM Write Flag Ȯ��
/// @param    void
/// @return   void
void EEPROM_Write_10(void)
{
	U8 i = 0;

	if (gu8_EEPROM_Read <= Z_EEPROM_Read_10)
	{
		for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)
		{
			if (EEPROM_Data_Table[i].write_flag == SET)	//	write ���ð� �ִ� ���?
			{
				gu8_EEPROM_OperNum = i;					//		�ش� �ּ� �ѹ��� ����
				gu8_TxBuf[0] = (U8)(EEPROM_Data_Table[i].address & 0xFF);	//		�ּ��Է�
				gu8_TxBuf[1] = *EEPROM_Data_Table[i].data;		//		������ �Է�
				EEPROM_Data_Table[i].eeprom_data = *EEPROM_Data_Table[i].data;	//		EEPROM ������ �Է�
				Ini_EEPROM_Write_20();					//		write ����
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

/// @brief    EEPROM Write ����
/// @param    void
/// @return   void
void EEPROM_Write_20(void)
{
	if (gu8_TimerEEPROM_Write_Delay == 0)			//	50ms
	{
		R_IICA0_Master_Send(_A0_IICA0_MASTERADDRESS, gu8_TxBuf, 2, 0);		//		���? ����
		Ini_EEPROM_Write_21();						//		������ ����
	}
}
void Ini_EEPROM_Write_20(void)
{
	gu8_TimerEEPROM_Write_Delay = Z_TimerEEPROM_Write_Delay;
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_20);
}

/// @brief    EEPROM Write ���� Ȯ��
/// @param    void
/// @return   void
void EEPROM_Write_21(void)
{
	U8 i = 0;
	U8 flag = CLEAR;

	if (0U == IICBSY0)								//	busy ����
	{
		Ini_EEPROM_Write_22();						//		write confirm
	}
	else if (gu8_TimerEEPROM_Limit == 0)			//	����Ʈ Ÿ�̸�
	{
		Ini_EEPROM_Write_10();						//		��⽺��?
		F_EEPROM_CommunicationError = SET;			//		���� flag set
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

/// @brief    Write/Address �۽� (Write Confirm)
/// @param    void
/// @return   void
void EEPROM_Write_22(void)
{
	if (gu8_TimerEEPROM_Write_Delay == 0)			//	���? Ÿ�̸� ���? ��
	{
		R_IICA0_Master_Send(_A0_IICA0_MASTERADDRESS, gu8_TxBuf, 1, 0);	//	�ּ� ������ �۽�
		Ini_EEPROM_Write_23();
	}
}
void Ini_EEPROM_Write_22(void)
{
	gu8_TimerEEPROM_Write_Delay = Z_TimerEEPROM_Write_Delay;
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_22);
}

/// @brief    Read CMD �۽� (Write Confirm)
/// @param    void
/// @return   void
void EEPROM_Write_23(void)
{
	U8 i = 0;
	U8 flag = 0;

	if (0U == IICBSY0)								//	busy üũ
	{
		R_IICA0_Master_Receive(_A0_IICA0_MASTERADDRESS, &gu8_RxBuf, 1, 0);	//		������ �б�
		Ini_EEPROM_Write_24();
	}
	else if (gu8_TimerEEPROM_Limit == 0)			//	����Ʈ Ÿ�̸�
	{
		Ini_EEPROM_Write_10();						//		���? ����
		F_EEPROM_CommunicationError = SET;			//		���� flag set
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

/// @brief    Read ���� ���?
/// @param    void
/// @return   void
void EEPROM_Write_24(void)
{
	U8 i = 0;
	U8 flag = 0;
	static U8 flag_reWrite = 0;

	if (0U == IICBSY0)								//	busy üũ
	{
		EEPROM_Data_Table[gu8_EEPROM_OperNum].write_flag = CLEAR;	//		write flag clear
		if (gu8_RxBuf == EEPROM_Data_Table[gu8_EEPROM_OperNum].eeprom_data)	//		���� �����Ϳ� ���� �����Ͱ� ������ ���?
		{
			flag_reWrite = CLEAR;
			for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)		//		�ܿ� write Ȯ��
			{
				if (EEPROM_Data_Table[i].write_flag == SET)
				{
					flag = SET;
					break;
				}
			}

			if (flag == SET)						//		�ܿ� write�� �ִ� ���?
			{
				Ini_EEPROM_Write_10();				//			���? ����
			}
			else									//		�ܿ� write�� ���� ���?
			{
				if (F_Checksum_Write == CLEAR)		//			Checksum write ���� ���� ���?
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
		else										//		���� �����Ϳ� ���� �����Ͱ� ���� ���� ���� ���?
		{
			if (flag_reWrite == CLEAR)				//			re-Write ���� ���� ���?
			{
				EEPROM_Data_Table[gu8_EEPROM_OperNum].write_flag =  SET; 	//	re-Write �õ� 1ȸ
				flag_reWrite = SET;					//				re-Write ���� set
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
	else if (gu8_TimerEEPROM_Limit == 0)			//	����Ʈ Ÿ�̸�
	{
		Ini_EEPROM_Write_10();						//		���? ����
		F_EEPROM_CommunicationError = SET;			//		���� �÷��� set
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

	for (i = 0 ; i < Z_EEPROM_ADDR_CHECKSUM_HIGH ; i++)	//	Checksum �ּ� ������ ������ sum
	{
		checksum_data += *EEPROM_Data_Table[i].data;
	}

	gu8_EEPROM_Data_Checksum_High = (U8)((checksum_data >> 8) & 0xFF);	//	2����Ʈ High 1����Ʈ ����
	gu8_EEPROM_Data_Checksum_Low = (U8)(checksum_data & 0xFF);	//	2����Ʈ Low 2����Ʈ ����

	EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_HIGH].write_flag = SET;	//	High write set
	EEPROM_Data_Table[Z_EEPROM_ADDR_CHECKSUM_LOW].write_flag = SET;		//	Low write set

	Ini_EEPROM_Write_10();
}
void Ini_EEPROM_Write_30(void)
{
	F_Checksum_Write = SET;							//	chekcsum Write flag set
	EEPROM_Write_NoSet(Z_EEPROM_Write_Num_30);
}

/// @brief    EEPROM Write ����
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
	gu8_EEPROM_WriteNum = data; 								/*	�Ϸ� ��ȣ set*/

	gu8_EEPROM_Write = DT_EEPROM_WriteNumber[gu8_EEPROM_WriteNum];	/*	���� mode No. set*/
}

/// @brief    EEPROM �б� �ʱ�ȭ
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

/// @brief    EEPROM �б� ���?
/// @param    void
/// @return   void
void EEPROM_Read_10(void)
{
	U8 i = 0;

	if (gu8_EEPROM_Write <= Z_EEPROM_Write_10)
	{
		for (i = 0 ; i < Z_EEPROM_ADDR_Data_Max ; i++)
		{
			if (EEPROM_Data_Table[i].read_flag == SET)	//		�б� �䱸�� �ִ� ���?
			{
				gu8_EEPROM_OperNum = i;					//		�ּ� �ѹ��� ����
				gu8_TxBuf[0] = (U8)(EEPROM_Data_Table[i].address & 0xFF);	//		�ּ� ������ set
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

/// @brief    EEPROM �б� Addr �۽�
/// @param    void
/// @return   void
void EEPROM_Read_20(void)
{
	Ini_EEPROM_Read_21();
	R_IICA0_Master_Send(_A0_IICA0_MASTERADDRESS, gu8_TxBuf, 1, 0);	//		�б� �ּ� �۽�
}
void Ini_EEPROM_Read_20(void)
{
	EEPROM_Read_NoSet(Z_EEPROM_Read_Num_20);
}

/// @brief    EEPROM �б� Read CMD �۽�
/// @param    void
/// @return   void
void EEPROM_Read_21(void)
{
	if (0U == IICBSY0)								//	busy üũ
	{
		Ini_EEPROM_Read_22();
		R_IICA0_Master_Receive(_A0_IICA0_MASTERADDRESS, &gu8_RxBuf, 1, 0);	//	Read CMD �۽�
	}
}
void Ini_EEPROM_Read_21(void)
{
	EEPROM_Read_NoSet(Z_EEPROM_Read_Num_21);
}

/// @brief    EEPROM �б� �Ϸ� ���?
/// @param    void
/// @return   void
void EEPROM_Read_22(void)
{
	if (0U == IICBSY0)								//	busy check
	{
		if ((gu8_RxBuf >= EEPROM_Data_Table[gu8_EEPROM_OperNum].data_valid_check_lower) && (gu8_RxBuf <= EEPROM_Data_Table[gu8_EEPROM_OperNum].data_valid_check_upper))	//	���� ������ ��ȿ�� üũ
		{
			*EEPROM_Data_Table[gu8_EEPROM_OperNum].data = gu8_RxBuf;	//	������ ����
			EEPROM_Data_Table[gu8_EEPROM_OperNum].eeprom_data = *EEPROM_Data_Table[gu8_EEPROM_OperNum].data;	//	������ ����

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
		else										//		��ȿ�� NG�� ���?
		{
			if ((gu8_EEPROM_OperNum != Z_EEPROM_ADDR_FIRST_A) && (gu8_EEPROM_OperNum != Z_EEPROM_ADDR_FIRST_B))		//	������ �����Ͱ� �ƴ� ���?
			{
				*EEPROM_Data_Table[gu8_EEPROM_OperNum].data = EEPROM_Data_Table[gu8_EEPROM_OperNum].init_data;	//	�ʱⰪ ����
				EEPROM_Data_Table[gu8_EEPROM_OperNum].eeprom_data = *EEPROM_Data_Table[gu8_EEPROM_OperNum].data;	//	�ʱⰪ ����
			}
		}
		EEPROM_Data_Table[gu8_EEPROM_OperNum].read_flag = CLEAR;	//		Read flag clear
		Ini_EEPROM_Read_10();
	}
	else if (gu8_TimerEEPROM_Limit == 0)			//	����Ʈ Ÿ�̸�
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
/// @brief    EEPROM Read ����
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
	gu8_EEPROM_ReadNum = data; 								/*	�Ϸ� ��ȣ set*/

	gu8_EEPROM_Read = DT_EEPROM_ReadNumber[gu8_EEPROM_ReadNum];	/*	���� mode No. set*/
}
