//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
#ifndef FK_GLB_VARS_H
#define FK_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 fk_glb_vars.h
//
//! @author 	 Willman Chen
//
//! @date 		 2010/10/25
//
//  @brief 		 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// T Y P E D E F   S T R U C T   D E F I N I T I O N
//
//**********************************************************************************************************************
    typedef struct
    {
        UINT32 dma1:1;
        UINT32 dma2:1;
        UINT32 dma3:1;
        UINT32 dma4:1;
        UINT32 dma5:1;
        UINT32 dma6:1;
        UINT32 dma7:1;
        UINT32 dma8:1;
        UINT32 dma9:1;
        UINT32 dma10:1;
        UINT32 dma11:1;
        UINT32 dma12:1;
        UINT32 rtc:1;
        UINT32 usart1:1;
        UINT32 usart2:1;
        UINT32 usart3:1;
        UINT32 capture:1;
        UINT32 mcu_high:1;
        UINT32 dma_null:14;
    } STC_FK_INTERRUPT;
    extern STC_FK_INTERRUPT gs_fk_interrupt_list;
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
    void fk_glb_vars_init();
#endif		// FK_GLB_VARS_H 
#ifdef FK_ALLOC
#define EXTERNAL
#else
#define EXTERNAL extern
#endif
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E
//
//**********************************************************************************************************************
    EXTERNAL void (*gfunc_fk_systick_func)(void);
    EXTERNAL void (*gfunc_fk_exti_func[FK_EXTI_TOTAL])(void);
    EXTERNAL void (*gfunc_fk_dma_func[FK_DMA_TOTAL])(void);
    EXTERNAL void (*gfunc_fk_timer_interrupt[FK_TIMER_INTERRUPT_TOTAL])(void);
    EXTERNAL void (*gfunc_fk_rtc_func)(void);
    EXTERNAL void (*gfunc_fk_rtc_alarm_func)(void);
    EXTERNAL UINT8 (*gfunc_fk_uart_tx_func[FK_UART_SETS])(void);
    EXTERNAL void (*gfunc_fk_uart_rx_func[FK_UART_SETS])(void);
    EXTERNAL void (*gfunc_fk_adc_func)(void);
    EXTERNAL void (*gfunc_fk_pvd_func)(void);
    EXTERNAL UINT8 gb_fk_capture_compare_timer;
    EXTERNAL UINT8 gb_fk_capture_compare_channel;
    EXTERNAL UINT8 gb_fk_i2c_status_flag;
    extern const UINT32 gt_fk_exti_line[];
    extern const UINT32 gt_fk_pin_index[];
    extern const void* gt_fk_port_index[];
    extern const UINT32 gt_fk_portsource_register[];
    extern const UINT32 gt_fk_pinsource_register[];
    extern const UINT32 gt_fk_periph_register[];
    extern const UINT32 gt_fk_exti_irq_register[];
    extern const UINT32 gt_fk_dma_irq_register[];
    extern const UINT32 gt_fk_dma_channel_register[];
    extern const UINT32 gt_fk_dma_TC_register[];
    extern const UINT32 gt_fk_dma_GL_register[];
    extern const UINT8 gt_fk_exti_priority[];
    extern const UINT8 gt_fk_dma_priority[];
    extern const UINT32 gt_fk_timer_periph_register[];
    extern const UINT32 gt_fk_timer_register[];
    extern const UINT32 gt_fk_timer_irq[];
    extern const UINT8 gt_fk_timer_priority[];
    extern const UINT32 gt_fk_uart_periph_register[];
    extern const UINT32 gt_fk_uart_port_register[];
    extern const UINT32 gt_fk_uart_tx_pin_register[];
    extern const UINT32 gt_fk_uart_rx_pin_register[];
    extern const UINT32 gt_fk_uart_name[];
    extern const UINT32 gt_fk_uart_remap_register[];
    extern const UINT32 gt_fk_uart_irq_register[];
    extern const UINT8 gt_fk_uart_priority[];
    extern const UINT32 gt_fk_adc_pin[];
    extern const void* gt_fk_adc_port[];
    extern const UINT32 gt_fk_adc_register[];
    extern const UINT32 gt_fk_dac_register[];
    extern const void* gt_fk_i2c_register[];
    extern const void* gt_fk_i2c_port[];
    extern const UINT32 gt_fk_i2c_pin[];
    extern const UINT32 gt_fk_i2c_periph[];
    extern const UINT32 gt_fk_spi_register[];
    extern const UINT32 gt_fk_spi_gpio_clock[];
    extern const void* gt_fk_spi_port[];
    extern const UINT32 gt_fk_spi_pins[];
    extern const UINT32 gt_fk_spi_periph[];
    
    EXTERNAL UART_HandleTypeDef fk_usart1,fk_usart2, fk_usart3;   
    extern UART_HandleTypeDef* gt_fk_usart_handle[];
    extern TIM_HandleTypeDef* gt_fk_timer_handle[];
    EXTERNAL TIM_HandleTypeDef fk_tim2,fk_tim3,fk_tim4,fk_tim5,fk_tim6,fk_tim7;
    EXTERNAL FLASH_EraseInitTypeDef fk_flash_init;
    //EXTERNAL DAC_HandleTypeDef fk_dac;
    //EXTERNAL I2C_HandleTypeDef fk_i2c1;
    //EXTERNAL RTC_HandleTypeDef fk_rtc;
    EXTERNAL 	UINT8		gb_fk_i2c1_hw_repeat_flag;
	EXTERNAL 	UINT8   	gb_fk_i2c1_hw_time_out_sw;
	EXTERNAL 	UINT16  	gb_fk_i2c1_hw_time_out_counter;
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#undef EXTERNAL
#ifdef __cplusplus
}
#endif
