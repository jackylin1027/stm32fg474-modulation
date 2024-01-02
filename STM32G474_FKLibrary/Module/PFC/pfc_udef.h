#ifndef PFC_UDEF_H
#define PFC_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_udef.h
//
//! @author 	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Here define all API
//
//**********************************************************************************************************************
#define PFC_TAG_ASCII                    "FINE-TEK"
#define PFC_DESCRIPTOR_ASCII             "EB5-ADMITTANCE"
#define PFC_MESSAGE_ASCII                "RF ADMITTANCE LEVEL SENSOR      "
#define PFC_LONG_ASCII                   "Taipei County,Taiwan,R.O.C.      "
#define PFC_UNIVERAL_PASSWORD            2123
#define PFC_MAX_SENSOR                   30
#define PFC_ADC_LENGTH                   100
#define PFC_AUTOSET_DATA_NUM             500


enum PFC_1MS_TIMER_CNT
{
    PFC_1ST_TIMER_CNT,
    PFC_2ND_TIMER_CNT,
    PFC_3RD_TIMER_CNT,
    PFC_4TH_TIMER_CNT,
    PFC_TOTAL_TIMER_CNT,
};

#define PFC_GET_1ST_TIMER_CNT                   gs_pfc_timer[PFC_1ST_TIMER_CNT].cnt
#define PFC_1ST_TIMER_ENABLE()                  (gs_pfc_timer[PFC_1ST_TIMER_CNT].sw=1,gs_pfc_timer[PFC_1ST_TIMER_CNT].cnt=0)
#define PFC_1ST_TIMER_DISABLE()                 (gs_pfc_timer[PFC_1ST_TIMER_CNT].sw=0,gs_pfc_timer[PFC_1ST_TIMER_CNT].cnt=0)
#define PFC_1ST_TIMER_RESET()                   (gs_pfc_timer[PFC_1ST_TIMER_CNT].cnt=0)


#define PFC_TIMER_3MS                   3
#define PFC_TIMER_10MS                  10
#define PFC_TIMER_20MS                  20
#define PFC_TIMER_50MS                  50
#define PFC_TIMER_100MS                 100
#define PFC_TIMER_200MS                 200
#define PFC_TIMER_250MS                 250
#define PFC_TIMER_500MS                 500
#define PFC_TIMER_1000MS                1000
#define PFC_TIMER_2000MS                2000
#define PFC_TIMER_5000MS                5000
#define PFC_UNIT_MSEC2SEC               1000
#define PFC_BCD_VOLUME_MASK             0xFFFFFFFFFFFF0000
#define PFC_BCD_VOLUME_DOT_MASK         0xFFFF
#define PFC_BCD_VOLUME_SHIFT            16
#define PFC_BCD_VOLUME_OFFSET_UNIT      4
#define PFC_DOT_NUM_REF                 5
#define PFC_EPH_BELOW_DN40_DOT          0x05
#define PFC_EPH_ABOVE_DN40_DOT          0x04
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
enum PFC_CHANNEL
{
  PFC_1ST_DEVICE,
  PFC_2ND_DEVICE,
  PFC_3RD_DEVICE,
  PFC_4TH_DEVICE,
  PFC_5TH_DEVICE,
  PFC_6TH_DEVICE,
  PFC_7TH_DEVICE,
  PFC_8TH_DEVICE,
  PFC_DEVICE_TOTAL,
  PFC_DEVICE_NULL,
};

enum PFC_ERROR_FLAG_TABLE	
{
  PFC_FREQUENCY_TRACKING_ERROR,
  PFC_OVER_MEASURE_RANGE_ERROR,
  PFC_PROBE_CONNECTOR_ERROR,
  PFC_PROBE_END_CHK_ERROR,
  PFC_DC_VALUE_CALCULATE_ERROR,
  PFC_LCM_CONNECT_ERROR,
  PFC_NO_FEEDBACK_SIGNAL_WARNING,
  PFC_TEMPERATURE_WARNING,
  PFC_RELIABILITY_WARNING,
  PFC_INTERFACE_THIN_WARNING,
  PFC_ERROR_FLAG_TOTAL,		
};
//=====================================================================
//================= specificate definetion below =======================
//=====================================================================

//***************************************************************
//   STRUCT AUTO ID                                              
//   This is the auto id data                                    
//===============================================================
#define PFC_PRODUCT_TYPE                        gs_pfc_auto_id.product_type
#define PFC_PRODUCT_NUMBER                      gs_pfc_auto_id.product_number
#define PFC_PRODUCT_VERSION                     gs_pfc_auto_id.product_version
#define PFC_ONE_WIRE_RESET                      gs_pfc_vars.setting_flag.one_wire_reset
#define PFC_IDSELECTOR_RESET_FLAG               gs_pfc_vars.setting_flag.id_selector_reset
#define PFC_SAVE_CALIBRATION_SETTING            gs_pfc_vars.setting_flag.save_calibration_setting
#define PFC_LOAD_DEFAULT_SETTING                gs_pfc_vars.setting_flag.load_default_setting
#define	PFC_SAVE_SYSTEM_VAR_TO_EEPROM           gs_pfc_vars.setting_flag.save_system_var_to_eeprom
#define	PFC_LOAD_FIRMWARE_SETTING	        gs_pfc_vars.setting_flag.load_firmware_setting
#define PFC_3_DOT_5_MA                          gs_pfc_vars.current_setting.dac_3_dot_5_ma
#define PFC_4_MA                                gs_pfc_vars.current_setting.dac_4_ma
#define PFC_12_MA                               gs_pfc_vars.current_setting.dac_12_ma
#define PFC_20_MA                               gs_pfc_vars.current_setting.dac_20_ma
#define PFC_22_MA                               gs_pfc_vars.current_setting.dac_22_ma
#define PFC_4MA_OFFSET                          gs_pfc_vars.current_setting.dac_4_ma_offset
#define PFC_20MA_OFFSET                         gs_pfc_vars.current_setting.dac_20_ma_offset
#define PFC_CURRENT_LOCK                        gs_pfc_vars.current_setting.current_lock
#define PFC_CURRENT_LOCK_VALUE                  gs_pfc_vars.current_setting.current_lock_value
#define PFC_CURRENT_NOW                         gs_pfc_vars.current_setting.current_now
#define PFC_CURRENT_MA                          gs_pfc_vars.current_setting.current_ma
#define PFC_CURRENT_OFFSET_VLAUE                gs_pfc_vars.current_setting.current_offset_value        
//================== STRUCT COMMUNICATION SETTING ==================
#define PFC_USE_MODBUS                          gs_pfc_vars.communcation_setting.modbus
#define PFC_USE_HART                            gs_pfc_vars.communcation_setting.hart
#define PFC_USE_PROFIBUS                        gs_pfc_vars.communcation_setting.profibus
#define PFC_USE_ZIGBEE                          gs_pfc_vars.communcation_setting.zigbee
#define PFC_USE_HART_WIRELESS                   gs_pfc_vars.communcation_setting.hart_wireless
//================== STRUCT CALANDAR STATUS    ==================
#define PFC_SEC                                 gs_pfc_status.calendar.second
#define PFC_MIN                                 gs_pfc_status.calendar.minute
#define PFC_HOUR                                gs_pfc_status.calendar.hour
#define PFC_DAY                                 gs_pfc_status.calendar.day
#define PFC_MONTH                               gs_pfc_status.calendar.month
#define PFC_YEAR                                gs_pfc_status.calendar.year   // start from 1900
//================== STRUCT MODBUS SETTING    ==================
#define PFC_MODBUS_ID                           gs_pfc_vars.modbus_setting.modbus_id
#define PFC_MODBUS_BAUDRATE                     gs_pfc_vars.modbus_setting.modbus_baudrate
#define PFC_MODBUS_BTIS                         gs_pfc_vars.modbus_setting.modbus_bits
#define PFC_MODBUS_STOP_BITS                    gs_pfc_vars.modbus_setting.modbus_stop_bits
#define PFC_MODBUS_PARITY                       gs_pfc_vars.modbus_setting.modbus_parity
#define PFC_MODBUS_MODE                         gs_pfc_vars.modbus_setting.modbus_mode
//================== STRUCT HART SETTING    ==================
#define PFC_HART_PRIMARY_VALUE_UNIT             gs_pfc_vars.hart.primary_value_unit
#define PFC_HART_POLLING_ADDRESS                gs_pfc_vars.hart.polling_address
#define PFC_HART_PRIMARY_COUNT                  gs_pfc_vars.hart.primary_count
#define PFC_HART_SECONDARY_COUNT                gs_pfc_vars.hart.secondary_count
#define PFC_HART_PRIMARY_FLAG                   gs_pfc_vars.hart.primary_flag
#define PFC_HART_SECONDARY_FLAG                 gs_pfc_vars.hart.secondary_flag
#define PFC_HART_TAG                            gs_pfc_vars.hart.tag
#define PFC_HART_DESCRIPTOR                     gs_pfc_vars.hart.descriptor
#define PFC_HART_MESSAGE                        gs_pfc_vars.hart.message
#define PFC_HART_LONG_TAG                       gs_pfc_vars.hart.long_tag
#define PFC_HART_DAMP_TIME                      gs_pfc_vars.hart.damp_time
#define PFC_HART_ASSEMBLY_NUMBER                gs_pfc_vars.hart.final_assembly_number
#define PFC_HART_LOOP_CURRENT_MODE              gs_pfc_vars.hart.loop_current_mode
//================== STRUCT PFC STATUS ==================
#define PFC_DISPLAY_VALUE1                      gs_pfc_status.display_value1
#define PFC_DISPLAY_VALUE2                      gs_pfc_status.display_value2
#define PFC_DISPLAY_VALUE3                      gs_pfc_status.display_value3
#define PFC_DISPLAY_VALUE4                      gs_pfc_status.display_value4
//===================== STRUCT PFC INFO =======================
#define	PFC_FIRMWARE_VERSION		        gs_pfc_vars.firmware_version[0]             //���骩��    
#define	PFC_HARDWARE_VERSION	                gs_pfc_vars.hardware_version[0]             //�w�骩��    
#define	PFC_PRODUCT_SERIAL		        gs_pfc_vars.product_serial[0]               //���~�Ǹ�    
#define PFC_PRODUCT_NAME                        gs_pfc_vars.product_Name[0]                 //���~order code(����), �w�g�䴩36 bytes ������
#define PFC_PRODUCT_DATE                        gs_pfc_vars.product_date[0]                 //�Ͳ����
#define PFC_SF_PRODUCT_SERIAL                   gs_pfc_vars.sf_product_serial[0]            //�b���~���~�Ǹ�
#define PFC_SF_PRODUCT_DATE                     gs_pfc_vars.sf_product_date[0]              //�b���~�Ͳ���� 
#define PFC_LANGUAGE                            gs_pfc_vars.language
//===== �u�{�Ҧ��Ѽ� =====
#define PFC_FACTORY_PARAMETER                   gs_pfc_factory.parameter                        //�u�{�Ҧ��U�Ͷի�����ADC��    
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "..\Inc\main.h"
#include "c_src\pfc_init.h"
#include "c_src\pfc_glb_vars.h"
#include "c_src\pfc_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief The Product Function Control Initial API
#define	PFC_INIT_API()                          pfc_init()
//! @brief The Main Loop Task of PFC
#define PFC_MAIN_LOOP_API()                     pfc_loop()
//! @brief Set up a Convert detect event flag
#define PFC_SET_CONVERT_TASK_API()              gs_pfc_status.convert_flag=1
//! @brief Clear a Convert detect event flag
#define PFC_CLR_CONVERT_TASK_API()              gs_pfc_status.convert_flag=0
//! @brief The Convert detect task for pfc
#define PFC_CONVERT_TASK_CHK_API()              gs_pfc_status.convert_flag
//! @brief Set up a Measure detect event flag
#define PFC_SET_MEASURE_TASK_API()              gs_pfc_status.measure_flag=1
//! @brief Clear a Measure detect event flag
#define PFC_CLR_MEASURE_TASK_API()              gs_pfc_status.measure_flag=0
//! @brief The Measure detect task for pfc
#define PFC_MEASURE_TASK_CHK_API()              gs_pfc_status.measure_flag
//! @brief Set up a key detect event flag
#define PFC_SET_KEY_TASK_API()                  gs_pfc_status.key_task=1
//! @brief Clear a key detect event flag
#define PFC_CLR_KEY_TASK_API()                  gs_pfc_status.key_task=0
//! @brief The Key detect task for pfc
#define PFC_KEY_TASK_CHK_API()                  gs_pfc_status.key_task
//! @brief Set up a UI action event flag
#define PFC_SET_UIF_TASK_API()                  gs_pfc_status.uif_task=1
//! @brief Clear a UI action event flag
#define PFC_CLR_UIF_TASK_API()                  gs_pfc_status.uif_task=0
//! @brief The task of LED Action
#define PFC_UIF_TASK_CHK_API()                  gs_pfc_status.uif_task
//! @brief Set up a LED action event flag
#define PFC_SET_LED_TASK_API()                  gs_pfc_status.led_task=1
//! @brief Clear a LED action event flag
#define PFC_CLR_LED_TASK_API()                  gs_pfc_status.led_task=0
//! @brief The task of UI for display screen
#define PFC_LED_TASK_CHK_API()                  gs_pfc_status.led_task
//! @brief Set up a device output action event flag
#define PFC_SET_DEVICE_OUTPUT_TASK_API()        gs_pfc_status.device_output_task=1
//! @brief Clear a device output action event flag
#define PFC_CLR_DEVICE_OUTPUT_TASK_API()        gs_pfc_status.device_output_task=0
//! @brief The task of device output for display screen
#define PFC_DEVICE_OUTPUT_TASK_CHK_API()        gs_pfc_status.device_output_task


//! @brief The API for setting system variable by index
#define PFC_GET_SYS_VARS_API(index)             index
//! @brief The API for setting system variable by index
#define PFC_SET_SYS_VARS_API(index,value)       index=value
//! @brief The API for counting the zero-checksum for a memory
#define PFC_MAKE_EEPROM_ZERO_CHECKSUM_API()     pfc_make_zero_checksum((UINT16*)&gs_pfc_vars,sizeof(gs_pfc_vars))
//! @brief The API for counting the zero-checksum for a memory
#define PFC_MAKE_FACTORY_EEPROM_ZERO_CHECKSUM_API()     pfc_make_zero_checksum((UINT16*)&gs_pfc_factory,sizeof(gs_pfc_factory))
//! @brief The API for restoring the system variable back to eeprom
#define PFC_RESTORE_EEPROM_API(block)           pfc_restore_eeprom(block)
//! @brief The API for loading default setting
#define PFC_LOAD_DEFAULT_API()			pfc_glb_vars_load_default()
//! @brief The API for setting current lock value
#define PFC_LOCK_CURRENT_VALUE_API(value)       PFC_CURRENT_LOCK_VALUE=value;PFC_CURRENT_LOCK=1;PFC_HART_LOOP_CURRENT_MODE=0
//! @brief The API for setting current lock
#define PFC_LOCK_CURRENT_API()                  PFC_CURRENT_LOCK=1;PFC_HART_LOOP_CURRENT_MODE=0
//! @brief The API for unsetting current lock
#define PFC_UNLOCK_CURRENT_API()                PFC_CURRENT_LOCK=0;PFC_HART_LOOP_CURRENT_MODE=1
//! @brief The API for counting time && date
#define PFC_ADD_SECOND_API()                    pfc_add_sec()
//=====================================================================
//================= specificate Parameter below =======================
//=====================================================================
#define PFC_OPERATION_MODE_CHK()                PFC_OPERATION_MODE
#define PFC_SET_OPERATION_MODE(mode)            PFC_OPERATION_MODE=mode
//! @brief Set up auto distribution task event flag
#define PFC_SET_DISTRIBUTION_HALT_API()         gs_pfc_status.distribution_task=PFC_DISTRIBUT_HALT    
//! @brief Clean auto distribution task event flag
#define PFC_CLR_DISTRIBUTION_TASK_API()         gs_pfc_status.distribution_task=PFC_DISTRIBUT_STOP
//! @brief Check auto distribution task event flag
#define PFC_DISTRIBUTION_TASK_CHK_API()         gs_pfc_status.distribution_task
//! @brief Set up auto distribution task activate flag
#define PFC_SET_WRITE_DISTRIBUT_FLAG()          gs_pfc_status.write_distribut_flag=1
//! @brief Set up auto distribution task activate flag
#define PFC_CLR_WRITE_DISTRIBUT_FLAG()          gs_pfc_status.write_distribut_flag=0
//! @brief Set up auto distribution task activate flag
#define PFC_WRITE_DISTRIBUT_CHK_FLAG()          gs_pfc_status.write_distribut_flag
//! @brief The API for get displaying dot position
#define PFC_GET_DISPLAY_DOT_POSITION()          pfc_get_display_dot_position()
//! @brief The API for change display channel with manual activity
#define PFC_MANUAL_CHANGE_CHANNEL_TASK_API()    pfc_manual_change_channel_task()      
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief The API for restore User data
#define PFC_RESTORE_USER_DATA_API()             FK_WRITE_USER_DATA_API((UINT32*)&gs_pfc_vars,sizeof(gs_pfc_vars))
//! @brief The API for restore Factory data
#define PFC_RESTORE_FACTORY_DATA_API()          FK_WRITE_FACTORY_DATA_API((UINT32*)&gs_pfc_factory,sizeof(gs_pfc_factory))
//! @brief The API for readint out User data
#define PFC_READ_USER_DATA_API()                FK_READ_USER_DATA_API((UINT32*)&gs_pfc_vars,sizeof(gs_pfc_vars))
//! @brief The API for readint out User data
#define PFC_READ_FACTORY_DATA_API()             FK_READ_FACTORY_DATA_API((UINT32*)&gs_pfc_factory,sizeof(gs_pfc_factory))
//! @brief The API for entering stop mode
#define PFC_ENTER_STOP_MODE_API()               FK_ENTER_STOP_MODE_API()
//! @brief The API for enabling watch dog
#define PFC_WATCHDOG_ENABLE_API()               FK_IWATCHDOG_ENABLE_API()
//! @brief The API for reloading watch dog
#define PFC_RELOAD_WATCHDOG_API()               FK_RELOAD_IWATCHDOG_API()
//! @brief The API for setting loop power current by mA unit
#define PFC_SET_LOOP_POWER_MA_API(mA)           AD5421_SET_CURRENT_IN_MA_API(mA)
//! @brief The API for setting loop power current by DAC unit
#define PFC_SET_LOOP_POWER_DAC_API(dac)         AD5421_SET_CURRENT_IN_DAC_API(dac)
//! @brief The API for packing ASCII string into binary data
#define PFC_PACK_ASCII_API(str,var_addr,len)    HART_ASCII_PACK_STRING_API(str,var_addr,len)
//! @brief The API for packing ISO string into binary data
#define PFC_PACK_ISO_API(str,var_addr)          HART_ISO_PACK_STRING_API(str,var_addr)
//! @brief The API for Key Task
#define PFC_KEY_TASK_API()                      KEY_TASK_API()
//! @brief The API for Led Task
#define PFC_LED_TASK_API()                      LED_TASK_API()
//! @brief The API for setting loop current
#define PFC_SET_LOOP_CURRENT_IN_DAC_API(dac)    AD5421_SET_CURRENT_IN_DAC_API(AD5421_CHANNEL_1,dac,PFC_USE_HART) 
//! @brief The API for checking HART is busy or not
#define PFC_HART_CHK_BUSY_API()                 0
//! @brief The API for 1ms timer count
#define PFC_SET_1MS_TIMER_API()                 FK_SET_MS_TIMER_INTERRUPT3_FUNC_CONTINUE_API(FK_1MS_SET,pfc_1ms_interrupt_func)
#define PFC_DAC1_SET_VALUE_API(val)             FK_DAC1_SET_VALUE_API(&fk_dac,val)
#define PFC_DAC2_SET_VALUE_API(val)             FK_DAC2_SET_VALUE_API(&fk_dac,val)
//! @brief The API for setting lcm contrast
#define PFC_SET_LCD_CONTRAST_API(value)         UIF_SET_LCD_CONTRAST_API(value)
#define PFC_ERROR_FLAG_SET_API(bitmsk)          FN_ERROR_FLAG_SET_API(&gb_pfc_error_flg_tbl[0],bitmsk)
#define PFC_ERROR_FLAG_CLR_API(bitmsk)          FN_ERROR_FLAG_CLR_API(&gb_pfc_error_flg_tbl[0],bitmsk)
#define PFC_ERROR_FLAG_CHK_API(bitmsk)          FN_ERROR_FLAG_CHK_API(&gb_pfc_error_flg_tbl[0],bitmsk)
//=====================================================================
//================= specificate Parameter below =======================
//=====================================================================
#define PFC_EPH_COMM_TRANSMITTER_PROCESS_TIMEOUT(ms)            EPH_COMM_TRANSMITTER_PROCESS_TIMEOUT(ms)
#define PFC_EPH_COMM_READ_REGISTER_API()                        EPH_COMM_READ_REGISTER_API()
#define PFC_EPH_COMM_RECEIVE_PARSING_API()                      EPH_COMM_RECEIVE_PARSING_API()
#define PFC_COMM_EPH_DEVICE_PTR                                 gb_eph_comm_device_ptr
#define PFC_SET_MODBUS_MASTER_REPLAY_FLAG(flag)                 gb_modbus_master_replay_flag=flag
#define PFC_MODBUS_MASTER_REPLAY_CHK_FLAG()                     gb_modbus_master_replay_flag
#define PFC_MANUAL_CHANGE_CHANNEL_RESET_TIMEOUT_TIMER_API(ms)   HBTC_SET_TIMER_API(HBTC_PFC_MANUAL_CHANGE_CHANNEL_TIMER,ms,pfc_manual_change_channel_timeout_isr)
#define PFC_SHOW_CHANNEL_RESET_TIMEOUT_TIMER_API(ms)            HBTC_SET_TIMER_API(HBTC_PFC_SHOW_CHANNEL_TIMER,ms,pfc_show_channel_timeout_isr)
//! @brief The API for screen 7segment used basic timer
#define PFC_SSD_IO_SCREEN_TASK()                                SSD_IO_SCREEN_TASK()
#define PFC_LED_SET_ACTIVITY(index,behavior,delay)              led_set_activity(index,behavior,delay)
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
#define PFC_SET_LED_ON(m_pin)                   TCA9539_SET_PIN_LOW_API(m_pin,0x01,0xE8)
#define PFC_SET_LED_OFF(m_pin)                  TCA9539_SET_PIN_HIGH_API(m_pin,0x01,0xE8)
#define PFC_TCA9539_SET_PORT1_LOW_API(m_pin)    TCA9539_SET_PIN_LOW_API(m_pin,0x01,0xE8)
#define PFC_TCA9539_SET_PORT1_HIGH_API(m_pin)   TCA9539_SET_PIN_HIGH_API(m_pin,0x01,0xE8)
#define PFC_LED_TASK()                          pfc_led_task()
#define PFC_TCA9539_SET_PORT0_LOW_API(m_pin)    TCA9539_SET_PIN_LOW_API(m_pin,0x00,0xE8)
#define PFC_TCA9539_SET_PORT0_HIGH_API(m_pin)   TCA9539_SET_PIN_HIGH_API(m_pin,0x00,0xE8)
#define PFC_USING_PORT_LED_ON()                 pfc_using_port_led_on()
//! @brief The tca9539 Function Control Initial API
#define	PFC_TCA9539_INIT_API()                  TCA9539_INIT_API()
//! @brief ST7565 graphic lcm driver module initial API
#define	PFC_ST7565_INIT_API()                   ST7565_INIT_API()

void pfc_loop(void);
#endif		// PFC_UDEF_H 
