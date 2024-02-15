/* 
 * File:   EEPROM.c
 * Author: Yousif Elraey
 *
 * Created on December 13, 2023, 1:06 PM
 */

#include "EEPROM.h"

Std_ReturnType EEPROM_DATA_WriteByte(uint16 bAdd, uint8 bData){
    
   Std_ReturnType ret = E_NOT_OK;
   
   uint8 GI_STATUS = INTCONbits.GIE;
   
   EEADRH = (uint8)((bAdd >> 8) & 0x03);
   EEADR = (uint8)(bAdd & 0xFF);
   
   EEDATA = bData;
   
   EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY;
   
   EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
   
   EECON1bits.WREN = ALLOW_WRITE_CYCLES_FLASH_EEPROM;
   
   INT_GIE_DISABLE();
   
   EECON2 = 0x55;
   EECON2 = 0xAA;
   
   EECON1bits.WR = INIT_DATA_EEPROM_WRITE_ERASE;
   while(EECON1bits.WR);
   
   EECON1bits.WREN = INHIBTS_WRITE_CYCLES_FLASH_EEPROM;
   
   INTCONbits.GIE = GI_STATUS;
   
   return ret;
   
}

Std_ReturnType EEPROM_DATA_ReadByte(uint16 bAdd, uint8 *bData){

    Std_ReturnType ret = E_NOT_OK;
   
    if(NULL != bData){
        EEADRH = (uint8)((bAdd >> 8) & 0x03);
        EEADR = (uint8)(bAdd & 0xFF);
        
        EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY;
   
        EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
        
        EECON1bits.RD = INIT_DATA_EEPROM_READ_ERASE;
        
        NOP();
        NOP();
        
        *bData = EEDATA;
        
    }
    else{
        ret = E_NOT_OK;
    }
      
   return ret;
    
}

