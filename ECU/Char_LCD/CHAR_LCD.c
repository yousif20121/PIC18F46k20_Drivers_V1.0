/* 
 * File:   CHAR_LCD.c
 * Author: Yousif Elraey
 *
 * Created on October 21, 2023, 5:12 PM
 */

#include "CHAR_LCD.h"

/** Helper Functions Prototypes */
static Std_ReturnType ECU_LCD_Send_4Bits_BitByBit(const char_lcd_4bit_t *lcd, uint8 data_command);
static Std_ReturnType ECU_LCD_4Bits_Send_EN(const char_lcd_4bit_t *lcd);
static Std_ReturnType ECU_LCD_8Bits_Send_EN(const char_lcd_8bit_t *lcd);
static Std_ReturnType ECU_LCD_4Bits_Set_Cursor(const char_lcd_4bit_t *lcd, uint8 row, uint8 col);
static Std_ReturnType ECU_LCD_8Bits_Set_Cursor(const char_lcd_8bit_t *lcd, uint8 row, uint8 col);

/** 4-Bit LCD */
#if ECU_LCD_4BIT_ALL_CONFIG == ENABLE

/**
 * ECU_LCD_4BIT_Init - Initialize a 4-bit LCD.
 *
 * This function initializes a 4-bit LCD display.
 *
 * @param lcd Pointer to the 4-bit LCD configuration structure.
 * @return    Returns the status of the initialization:
 *            - E_OK if the LCD was successfully initialized.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or initialization failure).
 */
#if ECU_LCD_4BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_4BIT_Init(const char_lcd_4bit_t *lcd){
    
    Std_ReturnType ret = E_NOT_OK;
    uint8 Local_DPins_Count = ZERO_INIT;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Init(&(lcd->lcd_rs));
        ret = GPIO_PIN_Init(&(lcd->lcd_en));
        for(Local_DPins_Count = 0; Local_DPins_Count < 4; Local_DPins_Count++){
            ret = GPIO_PIN_Init(&(lcd->lcd_data[Local_DPins_Count]));
        }
        __delay_ms(20);
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_4BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_4BIT_MODE_2_LINE);
        __delay_us(150);
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_4BIT_MODE_2_LINE);
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_CLEAR);
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_RET_HOME);
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_ENTRY_MODE);
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_CURS_OFF_DISP_ON);
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_4BIT_MODE_2_LINE);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * ECU_LCD_4BIT_Send_Command - Send a command to a 4-bit LCD.
 *
 * This function sends a command to control a 4-bit LCD display.
 *
 * @param lcd     Pointer to the 4-bit LCD configuration structure.
 * @param command The command to be sent to the LCD.
 * @return        Returns the status of the operation:
 *                - E_OK if the command was successfully sent.
 *                - E_NOT_OK if an error occurred (e.g., NULL pointer or command transmission failure).
 */
#if ECU_LCD_4BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_4BIT_Send_Command(const char_lcd_4bit_t *lcd, uint8 command){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Write(&(lcd->lcd_rs), GPIO_LOW);
        
        ret = ECU_LCD_Send_4Bits_BitByBit(lcd, command >> NIBBLE);
        ret = ECU_LCD_4Bits_Send_EN(lcd);
                
        ret = ECU_LCD_Send_4Bits_BitByBit(lcd, command);
        ret = ECU_LCD_4Bits_Send_EN(lcd);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * ECU_LCD_4BIT_Send_Char - Send a character to a 4-bit LCD.
 *
 * This function sends a character to display on a 4-bit LCD.
 *
 * @param lcd  Pointer to the 4-bit LCD configuration structure.
 * @param data The character to be displayed on the LCD.
 * @return     Returns the status of the operation:
 *             - E_OK if the character was successfully sent.
 *             - E_NOT_OK if an error occurred (e.g., NULL pointer or character transmission failure).
 */
#if ECU_LCD_4BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_4BIT_Send_Char(const char_lcd_4bit_t *lcd, uint8 data){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Write(&(lcd->lcd_rs), GPIO_HIGH);
        
        ret = ECU_LCD_Send_4Bits_BitByBit(lcd, data >> NIBBLE);
        ret = ECU_LCD_4Bits_Send_EN(lcd);
                
        ret = ECU_LCD_Send_4Bits_BitByBit(lcd, data);
        ret = ECU_LCD_4Bits_Send_EN(lcd);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * ECU_LCD_4BIT_Send_DataPosition - Send character data to a specific position on a 4-bit LCD.
 *
 * This function sends character data to a specified row and column on a 4-bit LCD display.
 *
 * @param lcd  Pointer to the 4-bit LCD configuration structure.
 * @param data The character data to be displayed.
 * @param row  The row where the character should be displayed (ROW1, ROW2, ROW3, or ROW4).
 * @param col  The column where the character should be displayed (1 to 16).
 * @return     Returns the status of the operation:
 *             - E_OK if the character data was successfully sent to the specified position.
 *             - E_NOT_OK if an error occurred (e.g., NULL pointer or invalid row/column).
 */
#if ECU_LCD_4BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_4BIT_Send_DataPosition(const char_lcd_4bit_t *lcd, uint8 data, uint8 row, uint8 col){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = ECU_LCD_4Bits_Set_Cursor(lcd, row, col);
        ret = ECU_LCD_4BIT_Send_Char(lcd, data);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * ECU_LCD_4BIT_Send_String - Send a string to a 4-bit LCD.
 *
 * This function sends a null-terminated string to be displayed on a 4-bit LCD.
 *
 * @param lcd Pointer to the 4-bit LCD configuration structure.
 * @param str Null-terminated string to be displayed.
 * @return    Returns the status of the operation:
 *            - E_OK if the string was successfully sent and displayed.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or string transmission failure).
 */
#if ECU_LCD_4BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_4BIT_Send_String(const char_lcd_4bit_t *lcd, uint8 *str){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        while(*str){
            ret = ECU_LCD_4BIT_Send_Char(lcd, *str);
            str++;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * ECU_LCD_4BIT_Send_StringPosition - Send a string to a specific position on a 4-bit LCD.
 *
 * This function sends a null-terminated string to be displayed at a specified row and column on a 4-bit LCD display.
 *
 * @param lcd Pointer to the 4-bit LCD configuration structure.
 * @param str Null-terminated string to be displayed.
 * @param row The row where the string should be displayed (ROW1, ROW2, ROW3, or ROW4).
 * @param col The column where the string should start (1 to 16).
 * @return    Returns the status of the operation:
 *            - E_OK if the string was successfully sent and displayed at the specified position.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or invalid row/column).
 */
#if ECU_LCD_4BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_4BIT_Send_StringPosition(const char_lcd_4bit_t *lcd, uint8 *str, uint8 row, uint8 col){
        
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = ECU_LCD_4Bits_Set_Cursor(lcd, row, col);
        while(*str){
            ret = ECU_LCD_4BIT_Send_Char(lcd, *str);
            str++;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
}
#endif

/**
 * ECU_LCD_4BIT_Send_Custom_Char - Send a custom character to a 4-bit LCD.
 *
 * This function sends a custom character to be displayed on a 4-bit LCD display.
 *
 * @param lcd     Pointer to the 4-bit LCD configuration structure.
 * @param mem_pos The memory position for storing the custom character (0 to 7).
 * @param row     The row where the custom character should be displayed (ROW1, ROW2, ROW3, or ROW4).
 * @param col     The column where the custom character should be displayed (1 to 16).
 * @param _chr    An array representing the custom character.
 * @return        Returns the status of the operation:
 *                - E_OK if the custom character was successfully sent and displayed.
 *                - E_NOT_OK if an error occurred (e.g., NULL pointer or invalid parameters).
 */
#if ECU_LCD_4BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_4BIT_Send_Custom_Char(const char_lcd_4bit_t *lcd, uint8 mem_pos, uint8 row, uint8 col, const uint8 _chr[]){

    Std_ReturnType ret = E_OK;
    uint8 lcd_counter = ZERO_INIT;
    
    if(NULL != lcd){
        ret = ECU_LCD_4BIT_Send_Command(lcd, LCD_CGRAM_START + (mem_pos*8));
        for(lcd_counter = 0; lcd_counter <= 7; lcd_counter++){
            ECU_LCD_4BIT_Send_Char(lcd, _chr[lcd_counter]);
        }
        ECU_LCD_4BIT_Send_DataPosition(lcd, mem_pos, row, col);
    }
    else{
        ret = E_NOT_OK;
    }

}
#endif

#endif

/** 8-Bit LCD */
#if ECU_LCD_8BIT_ALL_CONFIG == ENABLE

/**
 * ECU_LCD_8BIT_Init - Initialize an 8-bit LCD.
 *
 * This function initializes an 8-bit LCD display.
 *
 * @param lcd Pointer to the 8-bit LCD configuration structure.
 * @return    Returns the status of the initialization:
 *            - E_OK if the LCD was successfully initialized.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or initialization failure).
 */
#if ECU_LCD_8BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_8BIT_Init(const char_lcd_8bit_t *lcd){
    
    Std_ReturnType ret = E_NOT_OK;
    uint8 Local_DPins_Count = ZERO_INIT;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Init(&(lcd->lcd_rs));
        ret = GPIO_PIN_Init(&(lcd->lcd_en));
        for(Local_DPins_Count = 0; Local_DPins_Count < 8; Local_DPins_Count++){
            ret = GPIO_PIN_Init(&(lcd->lcd_data[Local_DPins_Count]));
        }
        __delay_ms(20);
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_8BIT_MODE_2_LINE);
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_CLEAR);
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_RET_HOME);
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_ENTRY_MODE);
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_CURS_OFF_DISP_ON);
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_8BIT_MODE_2_LINE);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * ECU_LCD_8BIT_Send_Command - Send a command to an 8-bit LCD.
 *
 * This function sends a command to control an 8-bit LCD display.
 *
 * @param lcd     Pointer to the 8-bit LCD configuration structure.
 * @param command The command to be sent to the LCD.
 * @return        Returns the status of the operation:
 *                - E_OK if the command was successfully sent.
 *                - E_NOT_OK if an error occurred (e.g., NULL pointer or command transmission failure).
 */
#if ECU_LCD_8BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_8BIT_Send_Command(const char_lcd_8bit_t *lcd, uint8 command){
    
    Std_ReturnType ret = E_NOT_OK;
    uint8 Local_DPins_Count = ZERO_INIT;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Write(&(lcd->lcd_rs), GPIO_LOW);
        for(Local_DPins_Count = 0; Local_DPins_Count < 4; Local_DPins_Count++){
                    ret = GPIO_PIN_Write(&(lcd->lcd_data[Local_DPins_Count]), (command >> Local_DPins_Count) & (uint8)0x01);
        }
        ret = ECU_LCD_8Bits_Send_EN(lcd);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
 
}
#endif

/**
 * ECU_LCD_8BIT_Send_Char - Send a character to an 8-bit LCD.
 *
 * This function sends a character to display on an 8-bit LCD.
 *
 * @param lcd  Pointer to the 8-bit LCD configuration structure.
 * @param data The character to be displayed on the LCD.
 * @return     Returns the status of the operation:
 *             - E_OK if the character was successfully sent.
 *             - E_NOT_OK if an error occurred (e.g., NULL pointer or character transmission failure).
 */
#if ECU_LCD_8BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_8BIT_Send_Char(const char_lcd_8bit_t *lcd, uint8 data){
    
    Std_ReturnType ret = E_NOT_OK;
    uint8 Local_DPins_Count = ZERO_INIT;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Write(&(lcd->lcd_rs), GPIO_LOW);
        for(Local_DPins_Count = 0; Local_DPins_Count < 4; Local_DPins_Count++){
                    ret = GPIO_PIN_Write(&(lcd->lcd_data[Local_DPins_Count]), (command >> Local_DPins_Count) & (uint8)0x01);
        }
        ret = ECU_LCD_8Bits_Send_EN(lcd);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * ECU_LCD_8BIT_Send_DataPosition - Send character data to a specific position on an 8-bit LCD.
 *
 * This function sends character data to a specified row and column on an 8-bit LCD display.
 *
 * @param lcd  Pointer to the 8-bit LCD configuration structure.
 * @param data The character data to be displayed.
 * @param row  The row where the character should be displayed (ROW1, ROW2, ROW3, or ROW4).
 * @param col  The column where the character should be displayed (1 to 16).
 * @return     Returns the status of the operation:
 *             - E_OK if the character data was successfully sent to the specified position.
 *             - E_NOT_OK if an error occurred (e.g., NULL pointer or invalid row/column).
 */
#if ECU_LCD_8BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_8BIT_Send_DataPosition(const char_lcd_8bit_t *lcd, uint8 data, uint8 row, uint8 col){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = ECU_LCD_8Bits_Set_Cursor(lcd, row, col);
        ret = ECU_LCD_8BIT_Send_Char(lcd, data);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * ECU_LCD_8BIT_Send_String - Send a string to an 8-bit LCD.
 *
 * This function sends a null-terminated string to be displayed on an 8-bit LCD.
 *
 * @param lcd Pointer to the 8-bit LCD configuration structure.
 * @param str Null-terminated string to be displayed.
 * @return    Returns the status of the operation:
 *            - E_OK if the string was successfully sent and displayed.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or string transmission failure).
 */
#if ECU_LCD_8BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_8BIT_Send_String(const char_lcd_8bit_t *lcd, uint8 *str){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        while(*str){
            ret = ECU_LCD_8BIT_Send_Char(lcd, *str);
            str++;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * ECU_LCD_8BIT_Send_StringPosition - Send a string to a specific position on an 8-bit LCD.
 *
 * This function sends a null-terminated string to be displayed at a specified row and column on an 8-bit LCD display.
 *
 * @param lcd Pointer to the 8-bit LCD configuration structure.
 * @param str Null-terminated string to be displayed.
 * @param row The row where the string should be displayed (ROW1, ROW2, ROW3, or ROW4).
 * @param col The column where the string should start (1 to 16).
 * @return    Returns the status of the operation:
 *            - E_OK if the string was successfully sent and displayed at the specified position.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or invalid row/column).
 */
#if ECU_LCD_8BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_8BIT_Send_StringPosition(const char_lcd_8bit_t *lcd, uint8 *str, uint8 row, uint8 col){
        
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = ECU_LCD_8Bits_Set_Cursor(lcd, row, col);
        while(*str){
            ret = ECU_LCD_8BIT_Send_Char(lcd, *str);
            str++;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * ECU_LCD_8BIT_Send_Custom_Char - Send a custom character to an 8-bit LCD.
 *
 * This function sends a custom character to be displayed on an 8-bit LCD.
 *
 * @param lcd    Pointer to the 8-bit LCD configuration structure.
 * @param row    The row where the custom character should be displayed (ROW1, ROW2, ROW3, or ROW4).
 * @param col    The column where the custom character should be displayed (1 to 16).
 * @param _chr   Array containing the custom character data (8 bytes).
 * @param mem_pos Memory position for storing the custom character (0 to 7).
 * @return       Returns the status of the operation:
 *               - E_OK if the custom character was successfully sent and displayed.
 *               - E_NOT_OK if an error occurred (e.g., NULL pointer, invalid row/column, or memory position).
 */
#if ECU_LCD_8BIT_CONFIG == ENABLE
Std_ReturnType ECU_LCD_8BIT_Send_Custom_Char(const char_lcd_8bit_t *lcd, uint8 row, uint8 col, const uint8 _chr[], uint8 mem_pos){

    Std_ReturnType ret = E_OK;
    uint8 lcd_counter = ZERP_INIT;
    
    if(NULL != lcd){
        ret = ECU_LCD_8BIT_Send_Command(lcd, LCD_CGRAM_START + (mem_pos*8));
        for(lcd_counter = 0; lcd_counter <= 7; lcd_counter++){
            ECU_LCD_8BIT_Send_Char(lcd, _chr[lcd_counter]);
        }
        ECU_LCD_8BIT_Send_DataPosition(lcd, mem_pos, row, col);
    }
    else{
        ret = E_NOT_OK;
    }
    
}
#endif

#endif



/** Data Conversion Functions */

/**
 * uint8ToString - Convert a uint8 value to a string.
 *
 * This function converts a uint8 value to its string representation.
 *
 * @param value  The uint8 value to be converted to a string.
 * @param str    Pointer to the buffer where the string representation will be stored.
 */
void uint8ToString(uint8 value, uint8 *str){
   
    
    if(NULL != str){
        memset(str, '\0', 4);
        sprintf(str, "%i", value);
    }
    else{/** Do nothing */}
    
}

/**
 * uint16ToString - Convert a uint16 value to a string.
 *
 * This function converts a uint16 value to its string representation.
 *
 * @param value  The uint16 value to be converted to a string.
 * @param str    Pointer to the buffer where the string representation will be stored.
 */
void uint16ToString(uint16 value, uint8 *str){

    if(NULL != str){
        memset(str, '\0', 6);
        sprintf(str, "%i", value);
    }
    else{/** Do nothing */}

}

/**
 * uint32ToString - Convert a uint32 value to a string.
 *
 * This function converts a uint32 value to its string representation.
 *
 * @param value  The uint32 value to be converted to a string.
 * @param str    Pointer to the buffer where the string representation will be stored.
 */
void uint32ToString(uint32 value, uint8 *str){
    
    if(NULL != str){
        memset(str, '\0', 11);
        sprintf(str, "%i", value);
    }
    else{/** Do nothing */}
    
}


/** Helper Functions */

/**
 * ECU_LCD_Send_4Bits_BitByBit - Send a 4-bit data/command to an LCD bit by bit.
 *
 * This function sends a 4-bit data/command to an LCD by transmitting each bit individually.
 *
 * @param lcd          Pointer to the 4-bit LCD configuration structure.
 * @param data_command The 4-bit data/command to be sent.
 * @return             Returns the status of the operation:
 *                     - E_OK if the data/command was successfully sent.
 *                     - E_NOT_OK if an error occurred (e.g., NULL pointer or transmission failure).
 */
static Std_ReturnType ECU_LCD_Send_4Bits_BitByBIt(const char_lcd_4bit_t *lcd, uint8 data_command){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Write(&(lcd->lcd_data[0]), (data_command >> 0) & (uint8)0x01);
        if(E_OK == ret){
            ret = GPIO_PIN_Write(&(lcd->lcd_data[0]), (data_command >> 1) & (uint8)0x01);
        }
        if(E_OK == ret){
            ret = GPIO_PIN_Write(&(lcd->lcd_data[0]), (data_command >> 2) & (uint8)0x01);
        }
        if(E_OK == ret){
            ret = GPIO_PIN_Write(&(lcd->lcd_data[0]), (data_command >> 3) & (uint8)0x01);
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
 
}

/**
 * ECU_LCD_4Bits_Send_EN - Send an Enable (EN) pulse for a 4-bit LCD.
 *
 * This function generates an Enable (EN) pulse to trigger data/command transmission for a 4-bit LCD.
 *
 * @param lcd Pointer to the 4-bit LCD configuration structure.
 * @return    Returns the status of the operation:
 *            - E_OK if the EN pulse was successfully generated.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or pulse generation failure).
 */
static Std_ReturnType ECU_LCD_4Bits_Send_EN(const char_lcd_4bit_t *lcd){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Write(&(lcd->lcd_en), GPIO_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_Write(&(lcd->lcd_en), GPIO_LOW);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
 
}

/**
 * ECU_LCD_8Bits_Send_EN - Send an Enable (EN) pulse for an 8-bit LCD.
 *
 * This function generates an Enable (EN) pulse to trigger data/command transmission for an 8-bit LCD.
 *
 * @param lcd Pointer to the 8-bit LCD configuration structure.
 * @return    Returns the status of the operation:
 *            - E_OK if the EN pulse was successfully generated.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or pulse generation failure).
 */
static Std_ReturnType ECU_LCD_8Bits_Send_EN(const char_lcd_8bit_t *lcd){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != lcd){
        ret = GPIO_PIN_Write(&(lcd->lcd_en), GPIO_HIGH);
        __delay_us(5);
        ret = GPIO_PIN_Write(&(lcd->lcd_en), GPIO_LOW);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
 
}

/**
 * ECU_LCD_4Bits_Set_Cursor - Set the cursor position for a 4-bit LCD.
 *
 * This function sets the cursor position on a 4-bit LCD display.
 *
 * @param lcd Pointer to the 4-bit LCD configuration structure.
 * @param row The row where the cursor should be positioned (ROW1, ROW2, ROW3, or ROW4).
 * @param col The column where the cursor should be positioned (1 to 16).
 * @return    Returns the status of the operation:
 *            - E_OK if the cursor position was successfully set.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or invalid row/column).
 */
static Std_ReturnType ECU_LCD_4Bits_Set_Cursor(const char_lcd_4bit_t *lcd, uint8 row, uint8 col){
    
    Std_ReturnType ret = E_NOT_OK;
    
    col--;
    
    switch(row){
        case ROW1:  ret = ECU_LCD_4BIT_Send_Command(lcd, (0x80 + col)); break;
        case ROW2:  ret = ECU_LCD_4BIT_Send_Command(lcd, (0xc0 + col)); break;
        case ROW3:  ret = ECU_LCD_4BIT_Send_Command(lcd, (0x94 + col)); break;
        case ROW4:  ret = ECU_LCD_4BIT_Send_Command(lcd, (0xd4 + col)); break;
        default: /** Do nothing */ ;
    }
    
}

/**
 * ECU_LCD_8Bits_Set_Cursor - Set the cursor position for an 8-bit LCD.
 *
 * This function sets the cursor position on an 8-bit LCD display.
 *
 * @param lcd Pointer to the 8-bit LCD configuration structure.
 * @param row The row where the cursor should be positioned (ROW1, ROW2, ROW3, or ROW4).
 * @param col The column where the cursor should be positioned (1 to 16).
 * @return    Returns the status of the operation:
 *            - E_OK if the cursor position was successfully set.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer or invalid row/column).
 */
static Std_ReturnType ECU_LCD_8Bits_Set_Cursor(const char_lcd_8bit_t *lcd, uint8 row, uint8 col){
    
    Std_ReturnType ret = E_NOT_OK;
    
    col--;
    
    switch(row){
        case ROW1:  ret = ECU_LCD_8BIT_Send_Command(lcd, (0x80 + col)); break;
        case ROW2:  ret = ECU_LCD_8BIT_Send_Command(lcd, (0xc0 + col)); break;
        case ROW3:  ret = ECU_LCD_8BIT_Send_Command(lcd, (0x94 + col)); break;
        case ROW4:  ret = ECU_LCD_8BIT_Send_Command(lcd, (0xd4 + col)); break;
        default: /** Do nothing */ ;
    }
    
}