//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_task.c
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\pfc_drv.h"
#include "pfc_glb_vars.h"
#include "pfc_task.h"
#include "pfc_idef.h"
#include "..\pfc_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_make_zero_checksum
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 This function will make the zero-checksum of an array,and fill the zero-checksum value in the last two-bytes.
//
//**********************************************************************************************************************
void pfc_make_zero_checksum(UINT16 *array,UINT32 len)
{
  UINT16 chksum=0;
  UINT32 i;
  UINT16 *data=array;
  len=(len-2)/2;
  for (i=0; i<len; i++)
  {
    chksum+=*data++;
  }
  *(data)=(~chksum+1);
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_add_sec
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 This function will make the zero-checksum of an array,and fill the zero-checksum value in the last two-bytes.
//
//**********************************************************************************************************************
void pfc_add_sec()
{
  if (++PFC_SEC>=60)
  {
    PFC_SEC=0;
    if (++PFC_MIN>=60)
    {
      PFC_MIN=0;
      if (++PFC_HOUR>=24)
      {
        PFC_HOUR=0;
        if (++PFC_DAY>gt_pfc_days_of_month[PFC_MONTH])
        {
          PFC_DAY=1;
          if (++PFC_MONTH>12)
          {
            PFC_MONTH=1;
            ++PFC_YEAR;
          }
        }
      }
    }
  }
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_1ms_interrupt_func
//
//! @author	 Jacky Lin
//
//! @date 	 2018/10/16
//
//! @brief
//
//**********************************************************************************************************************
void pfc_1ms_interrupt_func()
{
    for(UINT8 index=0; index<PFC_TOTAL_TIMER_CNT; index++)
    {
        if(gs_pfc_timer[index].sw==SET)
        {
            if(gs_pfc_timer[index].cnt < 0xFFFFFFFF)
                gs_pfc_timer[index].cnt++;
        }
    }  
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn                  pfc_quicksort_func
//
//! @author           Simon Lu
//
//! @date              2013/09/13
//
//! @brief
//
//**********************************************************************************************************************
void pfc_quicksort_func(UINT32 A[], INT32 left, INT32 right)
{
    INT32 i, j ;
    UINT32 s , Temp;
    s= Temp=0;
    
    if(left < right)
    {
        s = A[(left+right)/2];
        i = left - 1;
        j = right + 1;
        while(1)
        {
            while(A[++i] < s) ;  // �V�k��
            while(A[--j] > s) ;  // �V����
            if(i >= j) break;
            Temp = A[i];
            A[i] = A[j];
            A[j] = Temp;
        }
        pfc_quicksort_func(A, left, i-1);   // �索��i�滼�j
        pfc_quicksort_func(A, j+1, right);  // ��k��i�滼�j
    }
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_choose_communication_channel
//
//! @author	 Jacky Lin
//
//! @date 	 2023/06/07
//
//! @brief 	 
//
//**********************************************************************************************************************
UINT8 pfc_choose_communication_channel(UINT8 enable, UINT16 channel)
{       
    UINT8 new_status=PFC_DEVICE_NULL;
        
    if(enable)
    {
          PFC_ADG1607_EN_HIGH();
    }
    else 
    {
          PFC_ADG1607_EN_LOW();
          return new_status;
    }
    switch(channel)
    {
          case PFC_1ST_DEVICE:          
            PFC_ADG1607_A0_LOW(); PFC_ADG1607_A1_LOW();   PFC_ADG1607_A2_LOW();      break;        
          case PFC_2ND_DEVICE:         
            PFC_ADG1607_A0_HIGH(); PFC_ADG1607_A1_LOW();   PFC_ADG1607_A2_LOW();      break;        
          case PFC_3RD_DEVICE:          
            PFC_ADG1607_A0_LOW(); PFC_ADG1607_A1_HIGH();   PFC_ADG1607_A2_LOW();      break;        
          case PFC_4TH_DEVICE:          
            PFC_ADG1607_A0_HIGH(); PFC_ADG1607_A1_HIGH();   PFC_ADG1607_A2_LOW();      break;        
          case PFC_5TH_DEVICE:          
            PFC_ADG1607_A0_LOW(); PFC_ADG1607_A1_LOW();   PFC_ADG1607_A2_HIGH();      break;        
          case PFC_6TH_DEVICE:          
            PFC_ADG1607_A0_HIGH(); PFC_ADG1607_A1_LOW();   PFC_ADG1607_A2_HIGH();      break;        
          case PFC_7TH_DEVICE:          
            PFC_ADG1607_A0_LOW(); PFC_ADG1607_A1_HIGH();   PFC_ADG1607_A2_HIGH();      break;        
          case PFC_8TH_DEVICE:          
            PFC_ADG1607_A0_HIGH(); PFC_ADG1607_A1_HIGH();   PFC_ADG1607_A2_HIGH();      break;      
          default:       
            return new_status;       
    }
    new_status=channel;
    return new_status;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_connected_timeout
//
//! @author	 Jacky Lin
//
//! @date 	 2022/08/30
//
//! @brief 	 
//
//**********************************************************************************************************************
void pfc_userinterface_task()
{
#if MAIN_USE_KEY == 1                         //uif key use
    if (PFC_KEY_TASK_CHK_API() )
    {
        PFC_KEY_TASK_API();
        PFC_CLR_KEY_TASK_API();
    }
#endif
#if MAIN_USE_UIF == 1
    if (PFC_UIF_TASK_CHK_API() )
    {
        UIF_TASK_API();
        PFC_CLR_UIF_TASK_API();
    }
#endif 
    
#if MAIN_USE_LED == 1
    if (PFC_LED_TASK_CHK_API() )
    {
        PFC_LED_TASK_API();
        PFC_CLR_LED_TASK_API();
    }      
#endif
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_task
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 This function will make the zero-checksum of an array,and fill the zero-checksum value in the last two-bytes.
//
//**********************************************************************************************************************
void pfc_task()
{
    if(PFC_GET_1ST_TIMER_CNT>=PFC_TIMER_10MS)
    {
        PFC_1ST_TIMER_RESET();
        //BTC_TASK_API(); 
        PFC_SET_LED_TASK_API();        
    }         
  
    if (PFC_LOAD_DEFAULT_SETTING==8013)
    {
        pfc_glb_vars_load_default();
        PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();
        PFC_RESTORE_USER_DATA_API();
        PFC_RESTORE_FACTORY_DATA_API();
    }
    if (PFC_LOAD_FIRMWARE_SETTING==8013)
    {
        pfc_glb_vars_load_factory();
        PFC_MAKE_FACTORY_EEPROM_ZERO_CHECKSUM_API();
        pfc_glb_vars_load_default();      
        PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();      
        PFC_RESTORE_USER_DATA_API();
        PFC_RESTORE_FACTORY_DATA_API();        
    }
    if (PFC_SAVE_SYSTEM_VAR_TO_EEPROM )
    {
        PFC_SAVE_SYSTEM_VAR_TO_EEPROM=0;
        PFC_SAVE_CALIBRATION_SETTING=0;
        PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();
        PFC_MAKE_FACTORY_EEPROM_ZERO_CHECKSUM_API();
        PFC_RESTORE_USER_DATA_API();
        PFC_RESTORE_FACTORY_DATA_API();
    }
    PFC_ENTER_STOP_MODE_API();
}

