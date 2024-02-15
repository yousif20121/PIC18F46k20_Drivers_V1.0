/* 
 * File:   EEPROM.h
 * Author: Yousif Elraey
 *
 * Created on December 13, 2023, 1:06 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

/** Section #1: Includes */
#include "../COMPILER.h"
#include "../STD_TYPES.h"
#include "../GPIO/GPIO.h"
#include "../Interrupt/INT_CONFIG.h"
#include "../Interrupt/INT_INTERNAL.h"

/** Section #2: Macros Deceleration */
#define ACCESS_FLASH_PROGRAM_MEMORY            1
#define ACCESS_EEPROM_PROGRAM_MEMORY           0
#define ACCESS_CONFIG_REG                      1
#define ACCESS_FLASH_EEPROM_MEMORY             0
#define ALLOW_WRITE_CYCLES_FLASH_EEPROM        1
#define INHIBTS_WRITE_CYCLES_FLASH_EEPROM      0
#define INIT_DATA_EEPROM_WRITE_ERASE           1
#define INIT_DATA_EEPROM_READ_ERASE            1

/** Section #3: Data Types Definition  */
/** Section #4: Macros Functions Deceleration */

/** Section #5: Functions Deceleration */
Std_ReturnType EEPROM_DATA_WriteByte(uint16 bAdd, uint8 bData);
Std_ReturnType EEPROM_DATA_ReadByte(uint16 bAdd, uint8 *bData);



#endif	/* EEPROM_H */

