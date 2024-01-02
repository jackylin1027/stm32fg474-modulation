//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_slave_task.c
//
//! @author 	 Jacky Lin
//
//! @date 		 20200709
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\modbus_slave_drv.h" 
#include "modbus_slave_glb_vars.h"
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
  //! @fn 			 modbus_slave_task
  //
  //! @author 	 Jacky Lin
  //
  //! @date 		 20200709
  //
  //! @brief 		 task function
  //
  //! @param 		 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void modbus_slave_task()
  {
    
  }//**********************************************************************************************************************
  //
  // Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	     modbus_slave_write_multi_register
  //
  //! @author 	 Jacky Lin
  //
  //! @date 		 2020/03/02
  //
  //! @brief 		 task function
  //
  //! @param 		 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void modbus_slave_write_multi_register()
  {
    UINT16 register_addr,i;
    UINT16 register_value;
    UINT8  check=0,check2=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS,type=0;
    STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *cmd=(STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *)&gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
    register_addr=(cmd->register_address_h<<MODBUS_SLAVE_BYTE_BITS)|(cmd->register_address_l);
    register_value=(cmd->register_value_h<<MODBUS_SLAVE_BYTE_BITS)|(cmd->register_value_l);
    
    if (register_addr<MODBUS_SLAVE_DDF_START_ADDRESS && register_addr>=MODBUS_SLAVE_READ_WRITE_START_ADDRESS && register_addr+register_value<=MODBUS_SLAVE_DDF_START_ADDRESS)
    {
      check=1;
      type=1;
    }
    if (register_addr>=MODBUS_SLAVE_READWRITE_REMAP_ADDRESS && register_addr<MODBUS_SLAVE_READWRITE_REMAP_ADDRESS+MODBUS_SLAVE_READ_WRITE_NUM && register_addr+register_value<MODBUS_SLAVE_READWRITE_REMAP_ADDRESS+MODBUS_SLAVE_READ_WRITE_NUM)
    {
      check=1;
      type=2;
    }
    
    if (register_value==0)
      check=0;
    
    if (check==0)
    {
      if (register_addr<MODBUS_SLAVE_DDF_START_ADDRESS && register_addr>=MODBUS_SLAVE_READ_WRITE_START_ADDRESS)
        check2=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
      if (register_addr>=MODBUS_SLAVE_READWRITE_REMAP_ADDRESS && register_addr<MODBUS_SLAVE_READWRITE_REMAP_ADDRESS+MODBUS_SLAVE_READ_WRITE_NUM )
        check2=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
      if (register_value==0)
        check2=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
      
      if (check2==MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS)
      {
        gs_modbus_slave_error_package.error_code=MODBUS_SLAVE_ERROR_CODE_MASK|(cmd->function_code);
        gs_modbus_slave_error_package.exception_code=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS;
      }
      else 
      {
        gs_modbus_slave_error_package.error_code=MODBUS_SLAVE_ERROR_CODE_MASK|(cmd->function_code);
        gs_modbus_slave_error_package.exception_code=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
      }
    }
    
    // after all check tasks , we need to fill something they want.
    if (gs_modbus_slave_error_package.error_code==0)
    {
      UINT16 start_addr;
      UINT16 data_value;
      UINT8 *data_ptr;
      UINT8  high_byte,low_byte,byte_count;
      // get the address and value
      STC_MODBUS_SLAVE_WRITE_MULTI_REGISTER_CMD_PACKAGE *ptr=(STC_MODBUS_SLAVE_WRITE_MULTI_REGISTER_CMD_PACKAGE *)&gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
      start_addr=(ptr->register_address_h<<MODBUS_SLAVE_BYTE_BITS)|(ptr->register_address_l);
      if (type==1)
        start_addr-=MODBUS_SLAVE_READ_WRITE_START_ADDRESS;
      else
        start_addr-=MODBUS_SLAVE_READWRITE_REMAP_ADDRESS;
      data_value=(ptr->register_value_h<<MODBUS_SLAVE_BYTE_BITS)|(ptr->register_value_l);
      // action
      for (i=0; i<data_value; i++)
      {
        data_ptr=(UINT8*)gt_modbus_slave_read_write[start_addr+i];
        high_byte=*((UINT8*)&ptr->data+2*i);
        low_byte=*((UINT8*)&ptr->data+2*i+1);
        *(data_ptr)=low_byte;
        *(data_ptr+1)=high_byte;
      }
      // fill response value
      STC_MODBUS_SLAVE_WRITE_MULTI_REGISTER_RESPONSE_PACKAGE *response=(STC_MODBUS_SLAVE_WRITE_MULTI_REGISTER_RESPONSE_PACKAGE*)&gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
      response->function_code=gs_modbus_slave_package_ptr->id_code;
      response->register_address_h=(register_addr&MODBUS_SLAVE_HIGH_BYTE_MASK)>>MODBUS_SLAVE_BYTE_BITS;
      response->register_address_l=(register_addr&MODBUS_SLAVE_LOW_BYTE_MASK);
      byte_count=data_value/gs_modbus_slave_package_ptr->return_byte_cnt;
      response->byte_count_h=(byte_count&MODBUS_SLAVE_HIGH_BYTE_MASK)>>MODBUS_SLAVE_BYTE_BITS;
      response->byte_count_l=(byte_count&MODBUS_SLAVE_LOW_BYTE_MASK);
      gb_modbus_slave_response_length=sizeof(STC_MODBUS_SLAVE_WRITE_MULTI_REGISTER_RESPONSE_PACKAGE);
    }
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	     modbus_slave_write_single_register
  //
  //! @author 	 Jacky Lin
  //
  //! @date 		 2020/03/02
  //
  //! @brief 		 task function
  //
  //! @param 		 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void modbus_slave_write_single_register()
  {
    UINT16 register_addr;
    UINT8  check=0,type=0;
    STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *cmd=(STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *)&gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
    register_addr=(cmd->register_address_h<<MODBUS_SLAVE_BYTE_BITS)|(cmd->register_address_l);
    
    if (register_addr<MODBUS_SLAVE_DDF_START_ADDRESS && register_addr>=MODBUS_SLAVE_READ_WRITE_START_ADDRESS)
    {
      check=1;
      type=1;
    }
    if (register_addr>=MODBUS_SLAVE_READWRITE_REMAP_ADDRESS && register_addr<MODBUS_SLAVE_READWRITE_REMAP_ADDRESS+MODBUS_SLAVE_READ_WRITE_NUM)
    {
      check=1;
      type=2;
    }
    
    if (check==0)
    {
      gs_modbus_slave_error_package.error_code=MODBUS_SLAVE_ERROR_CODE_MASK|(cmd->function_code);
      gs_modbus_slave_error_package.exception_code=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS;
    }
    
    // after all check tasks , we need to fill something they want.
    if (gs_modbus_slave_error_package.error_code==0)
    {
      UINT16 *data_ptr;
      // get the address and value
      STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *ptr=(STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *)&gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
      // we don't fill response value,'cause the response is same as command code
      if (type==1)
        data_ptr=(UINT16*)gt_modbus_slave_read_write[register_addr-MODBUS_SLAVE_READ_WRITE_START_ADDRESS];
      else
        data_ptr=(UINT16*)gt_modbus_slave_read_write[register_addr-MODBUS_SLAVE_READWRITE_REMAP_ADDRESS];
      *(data_ptr)=(ptr->register_value_h<<MODBUS_SLAVE_BYTE_BITS)|(ptr->register_value_l);
      gb_modbus_slave_response_length=sizeof(STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE);
    }
  }
  
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_slave_read_input_registers
//
//! @author 	 Jacky Lin
//
//! @date 		 2020/03/02
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_slave_read_input_registers()
{
    UINT16  i;
    INT32 register_addr;
    UINT16 register_value;
    UINT8 check=0,type=0,check2=0;
    STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *cmd=(STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *)&gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
    register_addr=(cmd->register_address_h<<MODBUS_SLAVE_BYTE_BITS)|(cmd->register_address_l);
    if (register_addr < MODBUS_SLAVE_LAST_ADDRESS && register_addr>=MODBUS_SLAVE_HEADER_START_ADDRESS)
    {
      check=1;
      type=1;
    }
    if (register_addr>=MODBUS_SLAVE_READONLY_REMAP_ADDRESS && register_addr<MODBUS_SLAVE_READONLY_REMAP_ADDRESS+MODBUS_SLAVE_READONLY_NUM)
    {
      check=1;
      type=2;
    }
    if (register_addr >=MODBUS_SLAVE_READWRITE_REMAP_ADDRESS && register_addr<MODBUS_SLAVE_READWRITE_REMAP_ADDRESS+MODBUS_SLAVE_READ_WRITE_NUM)
    {
      check=1;
      type=3;
    }
    
    if (check==0)
    {
        gs_modbus_slave_error_package.error_code=MODBUS_SLAVE_ERROR_CODE_MASK|(cmd->function_code);
        gs_modbus_slave_error_package.exception_code=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS;
    }

    register_value=(cmd->register_value_h<<MODBUS_SLAVE_BYTE_BITS)|(cmd->register_value_l);
    if (check==1)
    {
        if (type==1 && register_value+register_addr>MODBUS_SLAVE_LAST_ADDRESS)
            check2=1;
        //===== modbus table �}��Ū���� address �̾ڳ]�w��MAX_DEVICE_NUM�ӨM�w, Ver0.0.03 =====
        if (type==2 && register_value+register_addr>MODBUS_SLAVE_READONLY_REMAP_ADDRESS+MODBUS_SLAVE_READONLY_NUM)
            check2=1;
        if (type==3 && register_value+register_addr>MODBUS_SLAVE_READWRITE_REMAP_ADDRESS+MODBUS_SLAVE_READ_WRITE_NUM)
            check2=1;
        if (register_value==0 || check2==1)
        {
            gs_modbus_slave_error_package.error_code=MODBUS_SLAVE_ERROR_CODE_MASK|(cmd->function_code);
            gs_modbus_slave_error_package.exception_code=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_DATA_VALUE;
        }
    }
    // after all check tasks , we need to fill something they want.
    if (gs_modbus_slave_error_package.error_code==0)
    {
        UINT16 data_length;
        UINT16 *data_ptr;
        UINT8  high_byte,low_byte;
        // get the address and value
        STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *ptr=(STC_MODBUS_SLAVE_READ_WRITE_REGISTER_PACKAGE *)&gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
        data_length=(ptr->register_value_h<<MODBUS_SLAVE_BYTE_BITS)|(ptr->register_value_l);
        // fill response value
        STC_MODBUS_SLAVE_RESPONSE_READ_HOLDING_REGISTER_PACKAGE *response=(STC_MODBUS_SLAVE_RESPONSE_READ_HOLDING_REGISTER_PACKAGE *)&gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
        response->function_code=gs_modbus_slave_package_ptr->id_code;
        response->byte_count=gs_modbus_slave_package_ptr->return_byte_cnt*data_length;
        for (i=0; i<data_length; i++)
        {
            if (register_addr+i>=MODBUS_SLAVE_HEADER_START_ADDRESS && register_addr+i<MODBUS_SLAVE_READONLY_START_ADDRESS)
            {
                data_ptr=(UINT16*)gt_modbus_slave_header[register_addr-MODBUS_SLAVE_HEADER_START_ADDRESS+i];
            }            
            else if (register_addr+i>=MODBUS_SLAVE_READONLY_START_ADDRESS && register_addr+i<MODBUS_SLAVE_READ_WRITE_START_ADDRESS)
            {
                data_ptr=(UINT16*)gt_modbus_slave_readonly[register_addr-MODBUS_SLAVE_READONLY_START_ADDRESS+i]; 
            }
            else if (register_addr+i>=MODBUS_SLAVE_READONLY_REMAP_ADDRESS && register_addr+i<MODBUS_SLAVE_READONLY_REMAP_ADDRESS+MODBUS_SLAVE_READONLY_NUM)
            {
                data_ptr=(UINT16*)gt_modbus_slave_readonly[register_addr-MODBUS_SLAVE_READONLY_REMAP_ADDRESS+i]; 
            }
            else if (register_addr+i>=MODBUS_SLAVE_READ_WRITE_START_ADDRESS && register_addr+i<MODBUS_SLAVE_DDF_START_ADDRESS)
            {
                data_ptr=(UINT16*)gt_modbus_slave_read_write[register_addr-MODBUS_SLAVE_READ_WRITE_START_ADDRESS+i];
            }
            else if (register_addr+i>=MODBUS_SLAVE_READWRITE_REMAP_ADDRESS && register_addr+i<MODBUS_SLAVE_READWRITE_REMAP_ADDRESS+MODBUS_SLAVE_READ_WRITE_NUM)
            {
                data_ptr=(UINT16*)gt_modbus_slave_read_write[register_addr-MODBUS_SLAVE_READWRITE_REMAP_ADDRESS+i];
            }
            else if (register_addr+i>=MODBUS_SLAVE_DDF_START_ADDRESS && register_addr+i<MODBUS_SLAVE_LAST_ADDRESS)
            {
                data_ptr=(UINT16*)&gt_modbus_slave_ddf_file[register_addr-MODBUS_SLAVE_DDF_START_ADDRESS+i];
            }

            high_byte=(*(data_ptr)&MODBUS_SLAVE_HIGH_BYTE_MASK)>>MODBUS_SLAVE_BYTE_BITS;
            low_byte=(*(data_ptr)&MODBUS_SLAVE_LOW_BYTE_MASK);
            *((UINT8*)&response->data+2*i)=high_byte;
            *((UINT8*)&response->data+2*i+1)=low_byte;
        }
        gb_modbus_slave_response_length=sizeof(STC_MODBUS_SLAVE_RESPONSE_READ_HOLDING_REGISTER_PACKAGE)+response->byte_count+MODBUS_SLAVE_CRC_LEN-1;
    }
}
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 			 modbus_slave_receiving_and_checking
  //
  //! @author 	 Jacky Lin
  //
  //! @date 		 2020/02/27
  //
  //! @brief 		 The API for modbus slave receive function in every time
  //
  //! @param 		 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void modbus_slave_receiving_and_checking()
  {
    UINT8 byte_value;
    // we don't want do anything as we are not on "STOP" or "RECEIVING".
    MODBUS_SLAVE_RESET_TIMEOUT_TIMER_API();
    byte_value=MODBUS_SLAVE_RECEIVE_API();
    if (gb_modbus_slave_state!=MODBUS_SLAVE_STATE_RECEIVING_AND_CHECKING && gb_modbus_slave_state!=MODBUS_SLAVE_STATE_STOP)
      return ;
    
    if (MODBUS_SLAVE_MODE==MODBUS_SLAVE_RTU_MODE)
    {
      gb_modbus_slave_ptr %= MODBUS_SLAVE_MAX_BUFFER_SIZE;
      gb_modbus_slave_buffer[gb_modbus_slave_ptr++]=byte_value;
    }
    
    if (MODBUS_SLAVE_MODE==MODBUS_SLAVE_ASCII_MODE)
    {
      // byte code transform
      UINT8 char_value=MODBUS_SLAVE_ASCII_NULL_VALUE;
      if (byte_value>=MODBUS_SLAVE_ASCII_ZERO_CHAR && byte_value<=MODBUS_SLAVE_ASCII_NINE_CHAR)
        char_value=byte_value-MODBUS_SLAVE_ASCII_ZERO_CHAR;
      if (byte_value>=MODBUS_SLAVE_ASCII_A_CHAR && byte_value<=MODBUS_SLAVE_ASCII_F_CHAR)
        char_value=byte_value-MODBUS_SLAVE_ASCII_A_CHAR+MODBUS_SLAVE_HEX_A;
      if (byte_value==MODBUS_SLAVE_ASCII_START_CHAR)
        char_value=MODBUS_SLAVE_ASCII_START_CHAR;
      
      // present for ':' and error char code
      if (byte_value==MODBUS_SLAVE_ASCII_START_CHAR || char_value==MODBUS_SLAVE_ASCII_NULL_VALUE)
        gb_modbus_slave_char_ptr=0;
      if (char_value==MODBUS_SLAVE_ASCII_NULL_VALUE)
        return ;
      
      switch (gb_modbus_slave_char_ptr++)
      {
      case 0:
        {
          if (byte_value==MODBUS_SLAVE_ASCII_START_CHAR)
          {
            gb_modbus_slave_char_ptr++;
            gb_modbus_slave_ptr=0;
          }
          return ;
        }
      default:
        {
          UINT8 low_byte=(gb_modbus_slave_char_ptr-1)%2;
          if (low_byte==1)
          {
            gb_modbus_slave_buffer[gb_modbus_slave_ptr++]|=char_value;
            byte_value=gb_modbus_slave_buffer[gb_modbus_slave_ptr-1];
          }
          else
          {
            gb_modbus_slave_buffer[gb_modbus_slave_ptr]=(char_value<<MODBUS_SLAVE_HALF_BYTE_BITS);
            return ;
          }
        }
      }
    } //  if (gs_modbus_slave_status.modbus_mode==MODBUS_SLAVE_ASCII_MODE)
    switch (gb_modbus_slave_ptr-1)
    {
    case MODBUS_SLAVE_BYTE_NAME_ADDRESS:
      {
        if(gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS]=='*')
        {
          // not do anything
        }       
        else if (gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS]!=MODBUS_SLAVE_ID)
        {
          gb_modbus_slave_state=MODBUS_SLAVE_STATE_BACK_TO_STOP;
        }
        else
        {
          gb_modbus_slave_state=MODBUS_SLAVE_STATE_RECEIVING_AND_CHECKING;
          gs_modbus_slave_package_ptr=(STC_MODBUS_SLAVE_COMMAND_INFO*)&gt_modbus_slave_valid_function[MODBUS_SLAVE_BYTE_NAME_ADDRESS];
        }
        break;
      }
    case MODBUS_SLAVE_BYTE_NAME_FUNCTION_BYTE:
    {        
      if(gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS]=='*')
      {
        // not do anything
      }          
      if (byte_value>=MODBUS_SLAVE_MAX_COMMAND || (gs_modbus_slave_package_ptr+byte_value)->supported==MODBUS_SLAVE_SUPPORTED_CMD_NO)
      {
        gs_modbus_slave_error_package.error_code=MODBUS_SLAVE_ERROR_CODE_MASK|byte_value;
        gs_modbus_slave_error_package.exception_code=MODBUS_SLAVE_EXCEPTION_CODE_ILLEGAL_FUNCTION;
      }    
      else
      {
        gs_modbus_slave_package_ptr+=byte_value;
      }
      break;
    }
    default:
      break;
    }
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 			 modbus_slave_null_func
  //
  //! @author 	 Jacky Lin
  //
  //! @date 		 2020/03/02
  //
  //! @brief 		 None 
  //
  //! @param 		 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void modbus_slave_null_func()
  {
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 			 modbus_slave_sending
  //
  //! @author 	 Jacky Lin
  //
  //! @date 		 2020/02/27
  //
  //! @brief 		 The API for modbus slave sending function after timeout event
  //
  //! @param 		 None
  //
  //! @return 	 mount of data transmit finish
  //
  //**********************************************************************************************************************
UINT8 modbus_slave_sending()
{
  if (gb_modbus_slave_state==MODBUS_SLAVE_STATE_SENDING)
  {
      if (gb_modbus_slave_ptr!=gb_modbus_slave_response_length )
      {
          MODBUS_SLAVE_SEND_OUT_API(gb_modbus_slave_buffer[gb_modbus_slave_ptr++]);
          MODBUS_SLAVE_RESET_TIMEOUT_TIMER_API();
          return 1;
      }
      if (gb_modbus_slave_ptr==gb_modbus_slave_response_length)
      {
          MODBUS_SLAVE_RESET_TIMEOUT_TIMER_API();
          gb_modbus_slave_state=MODBUS_SLAVE_STATE_BACK_TO_STOP;
      }
  } // if (gs_modbus_slave_status.state==MODBUS_SLAVE_STATE_SENDING)
  return 0;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_slave_go_back_stop
//
//! @author 	 Jacky Lin
//
//! @date 		 2020/03/02
//
//! @brief 		 None 
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_slave_go_back_stop(void)
{
    MODBUS_SLAVE_INIT_API();
    MODBUS_SLAVE_UART_LOW_SPEED_API();
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_slave_timeout_isr
//
//! @author 	 Jacky Lin
//
//! @date 		 2020/07/10
//
//! @brief 		 modbus slave task function after hbtc timeout event 
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_slave_timeout_isr(void)
{
   UINT8 check_pass=0,lrc,i;
    UINT16 crc;
    
    if (gb_modbus_slave_state!=MODBUS_SLAVE_STATE_RECEIVING_AND_CHECKING&&gb_modbus_slave_state!=MODBUS_SLAVE_STATE_BACK_TO_STOP)
        return ;
    
    switch (gb_modbus_slave_state)
    {
    case MODBUS_SLAVE_STATE_RECEIVING_AND_CHECKING:
      {
        if (MODBUS_SLAVE_MODE==MODBUS_SLAVE_RTU_MODE)
        {
          // check CRC
          UINT32 crc,hi_byte,low_byte;
          crc=MODBUS_SLAVE_CRC_CODE_API(gb_modbus_slave_buffer,gb_modbus_slave_ptr-MODBUS_SLAVE_CRC_LEN);
          hi_byte=(crc&MODBUS_SLAVE_HIGH_BYTE_MASK)>>MODBUS_SLAVE_BYTE_BITS;
          low_byte=crc&MODBUS_SLAVE_LOW_BYTE_MASK;
          // crc pass
          if (hi_byte==gb_modbus_slave_buffer[gb_modbus_slave_ptr-MODBUS_SLAVE_CRC_HI_BYTE_POS] && low_byte==gb_modbus_slave_buffer[gb_modbus_slave_ptr-MODBUS_SLAVE_CRC_LOW_BYTE_POS])
            check_pass=1;
        }
        else // ASCII Mode
        {
          // check LRC
          UINT8 lrc=0x00;
          UINT8 i;
          for (i=0; i<gb_modbus_slave_ptr; i++)
            lrc+=gb_modbus_slave_buffer[i];
          if (lrc==0)
            check_pass=1;
        }
        if (check_pass==1)
        {
          gb_modbus_slave_state=MODBUS_SLAVE_STATE_ACTION;
          if (gs_modbus_slave_error_package.error_code==0)
            gs_modbus_slave_package_ptr->action();
          if (gs_modbus_slave_error_package.error_code!=0)
          {
            UINT8 *ptr=(UINT8*)&gs_modbus_slave_error_package;
            UINT8 i;
            for (i=0; i<MODBUS_SLAVE_ERROR_PACKAGE_LEN; i++)
              gb_modbus_slave_buffer[i]=*(ptr+i);
            gb_modbus_slave_response_length=MODBUS_SLAVE_ERROR_PACKAGE_LEN;
          }
          // fill PDU's fields
          gb_modbus_slave_buffer[MODBUS_SLAVE_BYTE_NAME_ADDRESS]=MODBUS_SLAVE_ID;
          if (MODBUS_SLAVE_MODE==MODBUS_SLAVE_RTU_MODE)
          {
            // CRC
            crc=MODBUS_SLAVE_CRC_CODE_API(gb_modbus_slave_buffer,gb_modbus_slave_response_length-MODBUS_SLAVE_CRC_LEN);
            gb_modbus_slave_buffer[gb_modbus_slave_response_length-MODBUS_SLAVE_CRC_HI_BYTE_POS]=(crc&MODBUS_SLAVE_HIGH_BYTE_MASK)>>MODBUS_SLAVE_BYTE_BITS;
            gb_modbus_slave_buffer[gb_modbus_slave_response_length-MODBUS_SLAVE_CRC_LOW_BYTE_POS]=crc&MODBUS_SLAVE_LOW_BYTE_MASK;
          }
          else // ASCII Mode
          {
            // 'cause we uses LRC (1 byte) instead of CRC ( 2 bytes )
            gb_modbus_slave_response_length--;
            lrc=0x00;
            for (i=0; i<gb_modbus_slave_response_length-1; i++)
              lrc+=gb_modbus_slave_buffer[i];
            // making LRC code
            lrc=(~lrc)+1;
            gb_modbus_slave_buffer[gb_modbus_slave_response_length-1]=lrc;
            gb_modbus_slave_char_ptr=0;
          } // if (gs_modbus_slave_status.modbus_mode==MODBUS_SLAVE_RTU_MODE)
          gb_modbus_slave_state=MODBUS_SLAVE_STATE_RESPONSE;
          gb_modbus_slave_ptr=0;
          gb_modbus_slave_state=MODBUS_SLAVE_STATE_SENDING;
          MODBUS_SLAVE_SET_WRITE_OUT_API();
          if (MODBUS_SLAVE_MODE==MODBUS_SLAVE_RTU_MODE)
          {
            MODBUS_SLAVE_START_TX_API();
          }
          else
          {
            MODBUS_SLAVE_SEND_OUT_API(MODBUS_SLAVE_ASCII_START_CHAR);
            gb_modbus_slave_char_ptr++;
          }
          MODBUS_SLAVE_RESET_TIMEOUT_TIMER_API();
        }
        else	// crc or lrc fail
        {
          gb_modbus_slave_state=MODBUS_SLAVE_STATE_BACK_TO_STOP;// mark
          modbus_slave_go_back_stop();      //======  timer �̭����i�H�� uart init, systemclock�|���~
        }
        break;
      }
    case MODBUS_SLAVE_STATE_SENDING:
    case MODBUS_SLAVE_STATE_BACK_TO_STOP:
      modbus_slave_go_back_stop();          //======  timer �̭����i�H�� uart init, systemclock�|���~
      break;
    default:
      break;
    }
    return ;  
}  
#ifdef __cplusplus
}
#endif

