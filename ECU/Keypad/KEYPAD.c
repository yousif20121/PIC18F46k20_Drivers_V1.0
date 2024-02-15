/* 
 * File:   KEYPAD.c
 * Author: Yousif Elraey
 *
 * Created on October 6, 2023, 9:00 PM
 */

#include "KEYPAD.h"

// Define a 2D array to represent the values associated with each keypad button
uint8 keypad_btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLS]={
                                                            {'7', '8', '9', '/'}, 
                                                            {'4', '5', '6', '*'}, 
                                                            {'1', '2', '3', '-'}, 
                                                            {'#', '0', '=', '+'}
                                                          };

/**
 * ECU_KEYPAD_Init - Initialize the configuration of a keypad.
 *
 * This function initializes the configuration of a keypad based on the provided
 * keypad structure, including GPIO pin configurations for rows and columns.
 *
 * @param keypad Pointer to the keypad configuration structure.
 * @return       Returns the status of the operation:
 *               - E_OK if the keypad configuration was successfully initialized.
 *               - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_KEYPAD_CONFIG == ENABLE
Std_ReturnType ECU_KEYPAD_Init(const keypad_t *keypad){

    Std_ReturnType ret = E_NOT_OK;
    
    uint8 rows_counter = ZERO_INIT;
    uint8 cols_counter = ZERO_INIT;
    
    if(NULL != keypad){
        for(rows_counter = ZERO_INIT; rows_counter < ECU_KEYPAD_ROWS; rows_counter++){
            ret = GPIO_PIN_Init(&(keypad->keypad_row_pins[rows_counter]));
        }
        for(cols_counter = ZERO_INIT; cols_counter < ECU_KEYPAD_COLS; cols_counter++){
            ret = GPIO_PIN_Direction_Init(&(keypad->keypad_col_pins[cols_counter]));
        }
    }
    else{
        ret = E_NOT_OK; 
    }
    
    
    return ret;

}
#endif

/**
 * ECU_KEYPAD_Get_Value - Retrieve the pressed value from a keypad.
 *
 * This function scans a keypad matrix to determine the pressed key and
 * returns its corresponding value.
 *
 * @param keypad Pointer to the keypad configuration structure.
 * @param value  Pointer to the variable where the pressed value will be stored.
 * @return       Returns the status of the operation:
 *               - E_OK if the pressed value was successfully retrieved.
 *               - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_KEYPAD_CONFIG == ENABLE
Std_ReturnType ECU_KEYPAD_Get_Value(const keypad_t *keypad, uint8 *value){

    Std_ReturnType ret = E_NOT_OK;
    
    uint8 g_rows_counter = ZERO_INIT;
    uint8 g_cols_counter = ZERO_INIT;
    
    uint8 g_counter = ZERO_INIT;
    
    uint8 col_logic = ZERO_INIT;
    
    if(NULL != keypad && NULL != value){
        for(g_rows_counter = ZERO_INIT; g_rows_counter < ECU_KEYPAD_ROWS; g_rows_counter++){
            for(g_counter = ZERO_INIT; g_counter < ECU_KEYPAD_ROWS; g_counter++){
                ret = GPIO_PIN_Write(&(keypad->keypad_row_pins[g_rows_counter]), GPIO_LOW);
            }
            ret = GPIO_PIN_Write(&(keypad->keypad_row_pins[g_rows_counter]), GPIO_HIGH);
            for(g_cols_counter = ZERO_INIT; g_cols_counter < ECU_KEYPAD_ROWS; g_cols_counter++){
                ret = GPIO_PIN_Read(&(keypad->keypad_row_pins[g_cols_counter]), &col_logic);
                if(GPIO_HIGH == col_logic){
                    *value = keypad_btn_values[g_rows_counter][g_cols_counter];
                }
            }
        }
    }
    else{
        ret = E_NOT_OK; 
    }
    
    
    return ret;

}
#endif