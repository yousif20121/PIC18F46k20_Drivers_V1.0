/* 
 * File:   CHAR_LCD.h
 * Author: Yousif Elraey
 *
 * Created on October 21, 2023, 5:12 PM
 */

#ifndef CHAR_LCD_H
#define	CHAR_LCD_H

/** Section #1: Includes */
#include "../../MCAL/GPIO/GPIO.h"
#include "CHAR_LCD_CFG.h"

/** Section #2: Macros Deceleration */
#define LCD_CLEAR                                0x01
#define LCD_RET_HOME                             0x02
#define LCD_ENTRY_MODE                           0x06
#define LCD_CURS_OFF_DISP_ON                     0x0C
#define LCD_CURS_OFF_DISP_OFF                    0x08
#define LCD_CURS_ON_BLINK_ON                     0x0F
#define LCD_CURS_ON_BLINK_OFF                    0x0E
#define LCD_DISP_SHIFT_RIGHT                     0x1C
#define LCD_DISP_SHIFT_LEFT                      0x18
#define LCD_4BIT_MODE_2_LINE                     0x28
#define LCD_8BIT_MODE_2_LINE                     0x38
#define LCD_CGRAM_START                          0x40
#define LCD_DDRAM_START                          0x80



/** Section #3: Data Types Definition  */

typedef struct{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
} char_lcd_4bit_t;


typedef struct{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];
} char_lcd_8bit_t;


/** Section #4: Functions Deceleration */

/** 4-Bit LCD */
Std_ReturnType ECU_LCD_4BIT_Init(const char_lcd_4bit_t *lcd);
Std_ReturnType ECU_LCD_4BIT_Send_Command(const char_lcd_4bit_t *lcd, uint8 command);
Std_ReturnType ECU_LCD_4BIT_Send_Char(const char_lcd_4bit_t *lcd, uint8 data);
Std_ReturnType ECU_LCD_4BIT_Send_DataPosition(const char_lcd_4bit_t *lcd, uint8 data, uint8 row, uint8 col);
Std_ReturnType ECU_LCD_4BIT_Send_String(const char_lcd_4bit_t *lcd, uint8 *str);
Std_ReturnType ECU_LCD_4BIT_Send_StringPosition(const char_lcd_4bit_t *lcd, uint8 *str, uint8 row, uint8 col);
Std_ReturnType ECU_LCD_4BIT_Send_Custom_Char(const char_lcd_4bit_t *lcd, uint8 mem_pos, uint8 row, uint8 col, const uint8 _chr[]);

/** 8-Bit LCD */
Std_ReturnType ECU_LCD_8BIT_Init(const char_lcd_8bit_t *lcd);
Std_ReturnType ECU_LCD_8BIT_Send_Command(const char_lcd_8bit_t *lcd, uint8 command);
Std_ReturnType ECU_LCD_8BIT_Send_Char(const char_lcd_8bit_t *lcd, uint8 data);
Std_ReturnType ECU_LCD_8BIT_Send_DataPosition(const char_lcd_8bit_t *lcd, uint8 data, uint8 row, uint8 col);
Std_ReturnType ECU_LCD_8BIT_Send_String(const char_lcd_8bit_t *lcd, uint8 *str);
Std_ReturnType ECU_LCD_8BIT_Send_StringPosition(const char_lcd_8bit_t *lcd, uint8 *str, uint8 row, uint8 col);
Std_ReturnType ECU_LCD_8BIT_Send_Custom_Char(const char_lcd_8bit_t *lcd, uint8 mem_pos, uint8 row, uint8 col, const uint8 _chr[]);

/** Data Types Conversion */
void uint8ToString(uint8 value, uint8 *str);
void uint16ToString(uint16 value, uint8 *str);
void uint32ToString(uint32 value, uint8 *str);


#endif	/* CHAR_LCD_H */

/**
 * To use this LCD driver:
 * Replace any thing within four asterisks with your data
 * Add extern button_t **variable name** to app.h
 * ex: **port** ----> GPIO_PORTA
___________________________________________________________

* for 4-bit LCD:
 ______________
char_lcd_4bit_t **variable name** = {
    .lcd_rs.port = **port**,
    .lcd_rs.pin = **pin**,
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    
    .lcd_en.port = **port**,
    .lcd_en.pin = **pin**,
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    
    .lcd_data[0].port = **port**
    .lcd_data[0].port = **port**,
    .lcd_data[0].pin = **pin**,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    
    .lcd_data[1].port = **port**
    .lcd_data[1].port = **port**,
    .lcd_data[1].pin = **pin**,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
  
    .lcd_data[2].port = **port**
    .lcd_data[2].port = **port**,
    .lcd_data[2].pin = **pin**,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
  
    .lcd_data[3].port = **port**
    .lcd_data[3].port = **port**,
    .lcd_data[3].pin = **pin**,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,

};
 
 * for 8-bit LCD:
 ______________
char_lcd_8bit_t **variable name** = {
    .lcd_rs.port = **port**,
    .lcd_rs.pin = **pin**,
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    
    .lcd_en.port = **port**,
    .lcd_en.pin = **pin**,
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    
    .lcd_data[0].port = **port**
    .lcd_data[0].port = **port**,
    .lcd_data[0].pin = **pin**,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    
    .lcd_data[1].port = **port**
    .lcd_data[1].port = **port**,
    .lcd_data[1].pin = **pin**,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
  
    .lcd_data[2].port = **port**
    .lcd_data[2].port = **port**,
    .lcd_data[2].pin = **pin**,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
  
    .lcd_data[3].port = **port**
    .lcd_data[3].port = **port**,
    .lcd_data[3].pin = **pin**,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
 
    .lcd_data[4].port = **port**
    .lcd_data[4].port = **port**,
    .lcd_data[4].pin = **pin**,
    .lcd_data[4].direction = GPIO_OUTPUT,
    .lcd_data[4].logic = GPIO_LOW,
    
    .lcd_data[5].port = **port**
    .lcd_data[5].port = **port**,
    .lcd_data[5].pin = **pin**,
    .lcd_data[5].direction = GPIO_OUTPUT,
    .lcd_data[5].logic = GPIO_LOW,
  
    .lcd_data[6].port = **port**
    .lcd_data[6].port = **port**,
    .lcd_data[6].pin = **pin**,
    .lcd_data[6].direction = GPIO_OUTPUT,
    .lcd_data[6].logic = GPIO_LOW,
  
    .lcd_data[7].port = **port**
    .lcd_data[7].port = **port**,
    .lcd_data[7].pin = **pin**,
    .lcd_data[7]].direction = GPIO_OUTPUT,
    .lcd_data[7].logic = GPIO_LOW,

};

*/