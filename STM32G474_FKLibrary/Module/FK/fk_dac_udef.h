#ifndef FK_DAC_UDEF_H
#define FK_DAC_UDEF_H
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
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************

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
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// DAC Function
//! @brief The API for enabling DAC1 function
#define FK_DAC1_ENABLE_API(port,pin)                                            fk_set_dac(FK_DAC_CHANNEL1,(UINT32)port,pin)
//! @brief The API for enabling DAC2 function
#define FK_DAC2_ENABLE_API(port,pin)                                            fk_set_dac(FK_DAC_CHANNEL2,(UINT32)port,pin)
//! @brief The API for setting DAC1 value
#define FK_DAC1_SET_VALUE_API(handle,val)                                       HAL_DAC_SetValue(handle,DAC_CHANNEL_1,DAC_ALIGN_12B_L,(val<<4))
//! @brief The API for setting DAC2 value       
#define FK_DAC2_SET_VALUE_API(handle,val)                                       HAL_DAC_SetValue(handle,DAC_CHANNEL_2,DAC_ALIGN_12B_L,(val<<4))

//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_DAC_UDEF_H 
