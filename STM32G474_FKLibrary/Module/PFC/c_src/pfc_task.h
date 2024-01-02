#ifndef PFC_TASK_H
#define PFC_TASK_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_task.h
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\pfc_udef.h"
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void pfc_make_zero_checksum(UINT16 *,UINT32);
void pfc_task();
void pfc_add_sec();
void pfc_1ms_interrupt_func();
void pfc_quicksort_func(UINT32 A[], INT32 left, INT32 right);
void pfc_distribut_param_init();
void pfc_userinterface_task();
UINT8 pfc_choose_communication_channel(UINT8 enable, UINT16 channel);
void pfc_manual_change_channel_timeout_isr();
void pfc_display_cycle_behavior(UINT16 cycle_mode,UINT16 show_value_time_goal,UINT16 show_channel_time_goal,UINT16 repeat_times_target,UINT8 reset_timer);
void pfc_manual_change_channel_task();
void pfc_show_channel_timeout_isr();
#endif		// PFC_TASK_H 
