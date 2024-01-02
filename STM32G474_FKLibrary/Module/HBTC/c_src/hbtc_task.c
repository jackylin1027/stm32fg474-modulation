//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 hbtc_task.c
//
//! @author 	 Willman Chen
//
//! @date 		 2010/12/27
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\hbtc_drv.h" 
#include "hbtc_glb_vars.h"
#include "hbtc_task.h"
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
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 hbtc_task
//
//! @author 	 Willman Chen
//
//! @date 		 2010/12/27
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void hbtc_set_timer(UINT8 set,UINT32 timing,void(*func)(void))
{
  HBTC_SET_RUNNING_API();
  gl_hbtc_timer[set].timer=timing;
  gl_hbtc_timer[set].func=func;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn		 hbtc_timer_isr
//
//! @author 	 Willman Chen
//
//! @date	 2010/12/27
//
//! @brief	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void hbtc_timer_isr()
{
    UINT8 i,status=HBTC_SLEEP;
    HBTC_FK_I2C1_HW_CHECK_TIMEOUT_API();
    FK_SET_OUTPUT_PIN_TOGGLE_API(FK_PORTB,FK_PIN9);
    HBTC_SET_RUNNING_API();
    if (HBTC_CHK_STATUS_API()==HBTC_RUNNING)
    {
      for (i=0;i<HBTC_TOTAL_TIMER;i++)
      {
        if (gl_hbtc_timer[i].timer)
        {
          status=HBTC_RUNNING;
          if (--gl_hbtc_timer[i].timer==0) 
            gl_hbtc_timer[i].func();
        }
      }
      if (status==HBTC_SLEEP)
        HBTC_SET_SLEEP_API();
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn		 	hbtc_timer_isr
//
//! @author 	 	Willman Chen
//
//! @date	 		2010/12/27
//
//! @brief			Register initial function
//
//! @param 	 	50 us counter
//
//! @return 	 	TIM1 Driver for pulse output
//
//**********************************************************************************************************************
void hbtc_timer1_isr()
{    
  
}
#ifdef __cplusplus
}
#endif

