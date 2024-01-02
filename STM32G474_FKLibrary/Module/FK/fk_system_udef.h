#ifndef FK_SYSTEM_UDEF_H
#define FK_SYSTEM_UDEF_H
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\Inc\main.h"
#include "c_src\fk_idef.h"
#include "c_src\fk_init.h"
#include "c_src\fk_task.h"
#include "c_src\fk_glb_vars.h" 
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
//! @ At Crystal 8Mhz Max Fequency 72Mhz (STM32F10X_MD)
#define	FK_PLL_MUL_2		    2
#define	FK_PLL_MUL_3		    3
#define	FK_PLL_MUL_4		    4
#define	FK_PLL_MUL_5		    5
#define	FK_PLL_MUL_6		    6
#define	FK_PLL_MUL_7		    7
#define	FK_PLL_MUL_8		    8
#define	FK_PLL_MUL_9		    9
#define	FK_PLL_MUL_10		    10
#define	FK_PLL_MUL_11		    11
#define	FK_PLL_MUL_12		    12
#define	FK_PLL_MUL_13		    13  
#define	FK_PLL_MUL_14		    14
#define	FK_PLL_MUL_15		    15
#define	FK_PLL_MUL_16		    16  
  
#define	FK_PLL_DIV_1			1
#define	FK_PLL_DIV_2			2
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief FK Library Initial Function
#define	FK_INIT_API()					          		fk_init()

//=================================================================================================================//
//! @brief Null Function ( Just Return )
#define 	FK_NULL_FUNC                                              			fk_null

// System Clock
//! @brief We need to reset all clock setting for ensuring everything is ok
#define FK_RESET_CLOCK_SETTING_API()                              		        RCC_DeInit()

//=================================================================================================================//
//! @brief Turn on High Speed External Oscillator
#define FK_TURN_ON_HSE_API()                                      			    RCC_HSEConfig(RCC_HSE_ON);while(RCC_WaitForHSEStartUp()==ERROR)

//=================================================================================================================//
//! @brief Turn on other kinds of oscillator as our High Speed External Oscillator
#define FK_TURN_ON_HSE_AND_PASSBY_API()								            RCC_HSEConfig(RCC_HSE_Bypass);while(RCC_WaitForHSEStartUp()==ERROR)

//=================================================================================================================//
//! @brief Turn off High Speed External Oscillator
#define FK_TURN_OFF_HSE_API()												    RCC_HSEConfig(RCC_HSE_ON+RCC_HSE_Bypass)

//=================================================================================================================//
//! @brief  Adjusts the Internal High Speed oscillator (HSI) calibration value.
//! @param  HSICalibrationValue: specifies the calibration trimming value.
//          This parameter must be a number between 0 and 0x1F.
#define FK_ADJUST_HSI_API(value)                                  			    RCC_AdjustHSICalibrationValue(value&0x1f)

//=================================================================================================================//
//! @brief  Enables or disables the Internal High Speed oscillator (HSI).
//! @note   HSI can not be stopped if it is used directly or through the PLL as system clock.
#define FK_TURN_ON_HSI_API()                                      			    RCC_HSICmd(ENABLE)
#define FK_TURN_OFF_HSI_API()                                     			    RCC_HSICmd(DISABLE)

//=================================================================================================================//
//! @brief Turn on Low Speed External Oscillator
#define FK_TURN_ON_LSE_API()												    RCC_LSEConfig(RCC_LSE_ON)

//=================================================================================================================//
//! @brief Turn on other kinds of oscillator as our Low Speed External Oscillator
#define FK_TURN_ON_LSE_AND_PASSBY_API()								            RCC_LSEConfig(RCC_LSE_Bypass)

//=================================================================================================================//
//! @brief Turn off Low Speed External Oscillator
#define FK_TURN_OFF_LSE_API()												    RCC_LSEConfig(RCC_LSE_ON+RCC_LSE_Bypass)
#define FK_TURN_ON_LSI_API()												    RCC_LSICmd(ENABLE)
#define FK_TURN_OFF_LSI_API()												    RCC_LSICmd(DISABLE)

//=================================================================================================================//
//! @brief  Configures the PLL clock source and multiplication factor.
//! @note   This function must be used only when the PLL is disabled.
//! @param  RCC_PLLSource: specifies the PLL entry clock source.
//!   For @b STM32_Connectivity_line_devices or @b STM32_Value_line_devices,
//!   this parameter can be one of the following values:
//!     @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided by 2 selected as PLL clock entry
//!     @arg RCC_PLLSource_PREDIV1: PREDIV1 clock selected as PLL clock entry
//!   For @b other_STM32_devices, this parameter can be one of the following values:
//!     @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided by 2 selected as PLL clock entry
//!     @arg RCC_PLLSource_HSE_Div1: HSE oscillator clock selected as PLL clock entry
//!     @arg RCC_PLLSource_HSE_Div2: HSE oscillator clock divided by 2 selected as PLL clock entry
//! @param  RCC_PLLMul: specifies the PLL multiplication factor.
//!   For @b STM32_Connectivity_line_devices, this parameter can be RCC_PLLMul_x where x:{[4,9], 6_5}
//!   For @b other_STM32_devices, this parameter can be RCC_PLLMul_x where x:[2,16]
#define FK_ENABLE_PLL_API()													    RCC_PLLCmd(ENABLE);while((RCC->CR&RCC_CR_PLLRDY)==0)
#define FK_DISABLE_PLL_API()													RCC_PLLCmd(DISABLE)

//=================================================================================================================//
//===(Simon Modify 2012-0402)
//#define FK_ENABLE_PLL2_API()												    RCC_PLL2Cmd(ENABLE);while((RCC->CR&RCC_CR_PLL2RDY)==0)
//#define FK_DISABLE_PLL2_API()												    RCC_PLL2Cmd(DISABLE)
//#define FK_ENABLE_PLL3_API()												    RCC_PLL3Cmd(ENABLE);while((RCC->CR&RCC_CR_PLL3RDY)==0)
//#define FK_DISABLE_PLL3_API()												    RCC_PLL3Cmd(DISABLE)
//=================================================================================================================//

//! @brief  Configures the PREDIV1 division factor.
//! @note
//!   - This function must be used only when the PLL is disabled.
//!   - This function applies only to STM32 Connectivity line and Value line
//!     devices.
//! @param  RCC_PREDIV1_Source: specifies the PREDIV1 clock source.
//!   This parameter can be one of the following values:
//!     @arg RCC_PREDIV1_Source_HSE: HSE selected as PREDIV1 clock
//!     @arg RCC_PREDIV1_Source_PLL2: PLL2 selected as PREDIV1 clock
//! @note
//!   For @b STM32_Value_line_devices this parameter is always RCC_PREDIV1_Source_HSE
//! @param  RCC_PREDIV1_Div: specifies the PREDIV1 clock division factor.
//!   This parameter can be RCC_PREDIV1_Divx where x:[1,16]
//  Div: 1 ~ 16
//=================================================================================================================//
//MCU 64 Pin
//=================================================================================================================//
//#if MAIN_USE_64PINS_MCU == 1
//      #define FK_PLL_MUL														FK_PLL_MUL_3
//      #define FK_PLL_DIV														FK_PLL_DIV_1
//      #define FK_PLL_CLOCK													((FK_EXTERNAL_OSC_CLOCK/FK_PLL_DIV)*FK_PLL_MUL)
//      #define FK_SYSTEM_CLOCK												    FK_PLL_CLOCK
//      #define FK_SYSTEM_MS_PRESCALER										    ((FK_PLL_CLOCK/1000))
//   //  mul : 2 ~ 16 - STM32 103 �ܤ֭n mul 2 up 
//  #if  MAIN_USE_HSE == 1
//      #define FK_PREDIV1_CONFIG_API()										    RCC_PREDIV1Config(RCC_PREDIV1_Source_HSE,RCC_PREDIV1_Div1)
//  #endif
//      //  Div: 1 ~ 16
//      #define FK_PREDIV2_CONFIG_API()										    RCC_PREDIV2Config(RCC_PREDIV2_Div1)
//      //  mul : 4 ~ 9 , 6.5 
//      #define FK_PLL_CONFIG_API()											    RCC_PLLConfig(RCC_PLLSource_PREDIV1,RCC_PLLMul_7)
//      //  mul : 8 ~ 14 , 16, 20
//      #define FK_PLL2_CONFIG_API()											RCC_PLL2Config(RCC_PLL2Mul_9)
//      //  mul : 8 ~ 14, 16, 20
//      #define FK_PLL3_CONFIG_API()											RCC_PLL3Config(RCC_PLL3Mul_8)
//#endif
//=================================================================================================================//
//MCU 48 Pin
//=================================================================================================================//
//#if MAIN_USE_48PINS_MCU == 1
		#define FK_PLL_MUL														FK_PLL_MUL_9
		#define FK_PLL_DIV														FK_PLL_DIV_1
#if ((MAIN_USE_HSI ==1) || (MAIN_USE_HSE ==1))&& (MAIN_USE_PLL ==0)  
        #define FK_PLL_CLOCK													FK_EXTERNAL_OSC_CLOCK
#else  
		#define FK_PLL_CLOCK													((FK_EXTERNAL_OSC_CLOCK/FK_PLL_DIV)*FK_PLL_MUL)
#endif
		#define FK_SYSTEM_CLOCK												    FK_PLL_CLOCK
		#define FK_SYSTEM_MS_PRESCALER									        ((FK_PLL_CLOCK/1000))
   
//==================================================================================================================//		      
//  mul : 2 ~ 16 - STM32 103 �ܤ֭n mul 2 up   
//==================================================================================================================//	
#if MAIN_USE_HSE==1 && (MAIN_USE_PLL ==0)         
  		#define FK_SET_SYSCLOCK_SOURCE_API()								    RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);while((RCC->CFGR&(uint32_t)RCC_CFGR_SWS)!=(uint32_t)FK_SYS_CONFIG_HSE)
#endif
//==================================================================================================================//
#if MAIN_USE_HSI == 1 && (MAIN_USE_PLL ==0)  
 		#define FK_SET_SYSCLOCK_SOURCE_API()								    RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);while((RCC->CFGR&(uint32_t)RCC_CFGR_SWS)!=(uint32_t)FK_SYS_CONFIG_HSI)
#endif
//==================================================================================================================// 
#if (MAIN_USE_HSE ==1) && (MAIN_USE_PLL ==1)      	
// With STM32F10X_MD , we just have chooses above as our DIV value : 
// RCC_PLLSource_HSE_Div1 / RCC_PLLSource_HSE_Div2  
#if(FK_PLL_DIV == FK_PLL_DIV_1)  
		#define FK_PLL_CONFIG_API()											    RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9)
#else 
        #define FK_PLL_CONFIG_API()											    RCC_PLLConfig(RCC_PLLSource_HSE_Div2,RCC_PLLMul_9)  
#endif
  		#define FK_SET_SYSCLOCK_SOURCE_API()								    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);while((RCC->CFGR&(uint32_t)RCC_CFGR_SWS)!=(uint32_t)FK_SYS_CONFIG_PLLCLK)
#endif
//==================================================================================================================//
#if (MAIN_USE_HSI ==1) && (MAIN_USE_PLL ==1)   
// With STM32F10X_MD , we just have chooses above as our DIV value : 
// RCC_PLLSource_HSI_Div2
		#define FK_PLL_CONFIG_API()											    RCC_PLLConfig(RCC_PLLSource_HSI_Div2,RCC_PLLMul_9)
 		#define FK_SET_SYSCLOCK_SOURCE_API()								    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);while((RCC->CFGR&(uint32_t)RCC_CFGR_SWS)!=(uint32_t)FK_SYS_CONFIG_PLLCLK)
#endif 

//=================================================================================================================//
//Returns the clock source used as system clock
//=================================================================================================================//
//! @brief  Returns the clock source used as system clock.
//! @param  None
//! @retval The clock source used as system clock. The returned value can
//!   be one of the following:
//!     - 0x00: HSI used as system clock
//!     - 0x04: HSE used as system clock
//!     - 0x08: PLL used as system clock
#define FK_GET_SYSCLOCK_SOURCE_API()										    RCC_GetSYSCLKSource()

//=================================================================================================================//
//Configures the AHB clock (HCLK).
//=================================================================================================================//
//! @brief  Configures the AHB clock (HCLK).
//! @param  RCC_SYSCLK: defines the AHB clock divider. This clock is derived from
//!   the system clock (SYSCLK).
//!   This parameter can be one of the following values:
//!     @arg RCC_SYSCLK_Div1: AHB clock = SYSCLK
//!     @arg RCC_SYSCLK_Div2: AHB clock = SYSCLK/2
//!     @arg RCC_SYSCLK_Div4: AHB clock = SYSCLK/4
//!     @arg RCC_SYSCLK_Div8: AHB clock = SYSCLK/8
//!     @arg RCC_SYSCLK_Div16: AHB clock = SYSCLK/16
//!     @arg RCC_SYSCLK_Div64: AHB clock = SYSCLK/64
//!     @arg RCC_SYSCLK_Div128: AHB clock = SYSCLK/128
//!     @arg RCC_SYSCLK_Div256: AHB clock = SYSCLK/256
//!     @arg RCC_SYSCLK_Div512: AHB clock = SYSCLK/512
#define FK_AHB_CLOCK															(FK_PLL_CLOCK)
#define FK_AHB_SET_CLOCK_API()												    RCC_HCLKConfig(RCC_SYSCLK_Div1)


//=================================================================================================================//
//Configures the Low Speed APB clock (PCLK1)
//=================================================================================================================//
//! @brief  Configures the Low Speed APB clock (PCLK1).
//! @param  RCC_HCLK: defines the APB1 clock divider. This clock is derived from
//!   the AHB clock (HCLK).
//!   This parameter can be one of the following values:
//!     @arg RCC_HCLK_Div1: APB1 clock = HCLK
//!     @arg RCC_HCLK_Div2: APB1 clock = HCLK/2
//!     @arg RCC_HCLK_Div4: APB1 clock = HCLK/4
//!     @arg RCC_HCLK_Div8: APB1 clock = HCLK/8
//!     @arg RCC_HCLK_Div16: APB1 clock = HCLK/16
//!	@brief if APB1 prescaler = 1  TIM Clock (*1) else TIM Clock (x2)

#define FK_APB1_CLOCK															(FK_AHB_CLOCK/1)
#define FK_APB1_MS_PRESCALER												    (FK_APB1_CLOCK/1000)
#define FK_APB1_SET_CLOCK_API()												    RCC_PCLK1Config(RCC_HCLK_Div1)

//=================================================================================================================//
//Configures the High Speed APB clock (PCLK2)
//=================================================================================================================//
//! @brief  Configures the High Speed APB clock (PCLK2).
//! @param  RCC_HCLK: defines the APB2 clock divider. This clock is derived from
//!   the AHB clock (HCLK).
//!   This parameter can be one of the following values:
//!     @arg RCC_HCLK_Div1: APB2 clock = HCLK
//!     @arg RCC_HCLK_Div2: APB2 clock = HCLK/2
//!     @arg RCC_HCLK_Div4: APB2 clock = HCLK/4
//!     @arg RCC_HCLK_Div8: APB2 clock = HCLK/8
//!     @arg RCC_HCLK_Div16: APB2 clock = HCLK/16
//!	@brief if APB1 prescaler = 1  TIM1 Clock (*1) else TIM1 Clock (x2)
  
#define FK_APB2_CLOCK															(FK_AHB_CLOCK/1)
#define FK_APB2_MS_PRESCALER												    (FK_APB2_CLOCK/1000)
#define FK_APB2_SET_CLOCK_API()												    RCC_PCLK2Config(RCC_HCLK_Div1)

//=================================================================================================================//
//Selects the clock source to output on MCO pin
//=================================================================================================================//
//! @brief  Selects the clock source to output on MCO pin.
//! @param  RCC_MCO: specifies the clock source to output.
//!
//!   For @b STM32_Connectivity_line_devices, this parameter can be one of the
//!   following values:
//!     @arg RCC_MCO_NoClock: No clock selected
//!     @arg RCC_MCO_SYSCLK: System clock selected
//!     @arg RCC_MCO_HSI: HSI oscillator clock selected
//!     @arg RCC_MCO_HSE: HSE oscillator clock selected
//!     @arg RCC_MCO_PLLCLK_Div2: PLL clock divided by 2 selected
//!     @arg RCC_MCO_PLL2CLK: PLL2 clock selected
//!     @arg RCC_MCO_PLL3CLK_Div2: PLL3 clock divided by 2 selected
//!     @arg RCC_MCO_XT1: External 3-25 MHz oscillator clock selected
//!     @arg RCC_MCO_PLL3CLK: PLL3 clock selected
//!
//!   For  @b other_STM32_devices, this parameter can be one of the following values:
//!     @arg RCC_MCO_NoClock: No clock selected
//!     @arg RCC_MCO_SYSCLK: System clock selected
//!     @arg RCC_MCO_HSI: HSI oscillator clock selected
//!     @arg RCC_MCO_HSE: HSE oscillator clock selected
//!     @arg RCC_MCO_PLLCLK_Div2: PLL clock divided by 2 selected
#define FK_MCO_CONFIG_API()													    RCC_MCOConfig(RCC_MCO_SYSCLK)
#define FK_MCO_OUTPUT_API()													    fk_set_io((UINT32)FK_PORTA,FK_PIN8,GPIO_Speed_50MHz,GPIO_Mode_AF_PP);FK_MCO_CONFIG_API()
#define FK_SET_FLASH_PREFETCH_API()							        	        FLASH->ACR|=FLASH_ACR_PRFTBE
#define FK_SET_FLASH_LATENCY_API()										        FLASH->ACR&=(uint32_t)((uint32_t)~FLASH_ACR_LATENCY);FLASH->ACR|=(uint32_t)FLASH_ACR_LATENCY_2


//=================================================================================================================//
//System Tick
//=================================================================================================================//
// System Tick
//! @brief Setting 1ms timer for doing something you want
#define FK_1MS_SYSTEM_TICK_ENABLE_API(func)							            SysTick_Config(FK_SYSTEM_MS_PRESCALER);gfunc_fk_systick_func=func
//! @brief Setting 250ms timer for doing something you want
#define FK_250MS_SYSTEM_TICK_ENABLE_API(func)							        SysTick_Config(FK_SYSTEM_MS_PRESCALER*250);gfunc_fk_systick_func=func
//! @brief Setting 500ms timer for doing something you want
#define FK_500MS_SYSTEM_TICK_ENABLE_API(func)							        SysTick_Config(FK_SYSTEM_MS_PRESCALER*500);gfunc_fk_systick_func=func
//! @brief Setting 1 sec timer for doing something you want
#define FK_1S_SYSTEM_TICK_ENABLE_API(func)								        SysTick_Config(FK_SYSTEM_MS_PRESCALER*1000);gfunc_fk_systick_func=func
//! @brief Setting ms unit system tick
#define FK_MS_SYSTEM_TICK_ENABLE_API(func,ms)                     	            SysTick_Config(FK_SYSTEM_MS_PRESCALER*ms);gfunc_fk_systick_func=func
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_SYSTEM_UDEF_H 
