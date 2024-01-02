//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_drv.c
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "pfc_drv.h"
#include "../pfc_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_sfr_init
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 Register initial function
//
//**********************************************************************************************************************
void pfc_sfr_init()
{       
    FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTB,FK_PIN1);
    FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTB,FK_PIN5);
    FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTB,FK_PIN7);
    //FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTB,FK_PIN9);
    FK_SET_OUTPUT_PIN_LOW_API(FK_PORTB,FK_PIN1);
    FK_SET_OUTPUT_PIN_LOW_API(FK_PORTB,FK_PIN5);
    FK_SET_OUTPUT_PIN_LOW_API(FK_PORTB,FK_PIN7);
    //FK_SET_OUTPUT_PIN_LOW_API(FK_PORTB,FK_PIN9);
}
