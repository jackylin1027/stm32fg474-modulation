#ifndef FK_SPI_UDEF_H
#define FK_SPI_UDEF_H
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
// SPI Function
#define FK_SPI1_ENABLE_API(buf,len)											    fk_spi_init(FK_SPI1,FK_DMA_CHANNEL_TOTAL,buf,len)
#define FK_SPI2_ENABLE_API(buf,len)											    fk_spi_init(FK_SPI2,FK_DMA_CHANNEL_TOTAL,buf,len)     
#define FK_SPI1_DMA_ENABLE_API(dma_channel,buf,len)					            fk_spi_init(FK_SPI1,dma_channel,buf,len)
#define FK_SPI2_DMA_ENABLE_API(dma_channel,buf,len)					            fk_spi_init(FK_SPI2,dma_channel,buf,len)  

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
#endif		// FK_SPI_UDEF_H 
