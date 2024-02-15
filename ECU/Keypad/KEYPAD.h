/* 
 * File:   KEYPAD.h
 * Author: Yousif Elraey
 *
 * Created on October 6, 2023, 9:00 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/** Section #1: Includes */
#include "../../MCAL/GPIO/GPIO.h"
#include "KEYPAD_CFG.h"


/** Section #2: Macros Deceleration */

// Define constants for the dimensions of an ECU keypad matrix
#define ECU_KEYPAD_ROWS             4
#define ECU_KEYPAD_COLS             4

// Define constants representing keypad row and column pins
#define KEYPAD_ROW_PIN_0            0
#define KEYPAD_ROW_PIN_1            1
#define KEYPAD_ROW_PIN_2            2
#define KEYPAD_ROW_PIN_3            3

#define KEYPAD_COL_PIN_0            0
#define KEYPAD_COL_PIN_1            1
#define KEYPAD_COL_PIN_2            2
#define KEYPAD_COL_PIN_3            3


/** Section #3: Data Types Definition  */

// Define a structure to represent the configuration of a keypad
typedef struct {
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];  // Array of pin configurations for keypad rows
    pin_config_t keypad_col_pins[ECU_KEYPAD_COLS];  // Array of pin configurations for keypad columns
} keypad_t;


/** Section #4: Functions Deceleration */
Std_ReturnType ECU_KEYPAD_Init(const keypad_t *keypad);
Std_ReturnType ECU_KEYPAD_Get_Value(const keypad_t *keypad, uint8 *value);


#endif	/* KEYPAD_H */

/**
 * To use this keypad driver:
 * Replace any thing within four asterisks with your data
 * Add extern keypad_t **variable name** to app.h
 * ex: **port** ----> GPIO_PORTA
___________________________________________________________

keypad_t **variable name** = {
    .keypad_row_pins[KEYPAD_ROW_PIN_0].port = **port**,
    .keypad_row_pins[KEYPAD_ROW_PIN_0].pin = **pin**,
    .keypad_row_pins[KEYPAD_ROW_PIN_0].direction = GPIO_OUTPUT,
    .keypad_row_pins[KEYPAD_ROW_PIN_0].logic = **HIGH/LOW**,
 
    .keypad_row_pins[KEYPAD_ROW_PIN_1].port = **port**,
    .keypad_row_pins[KEYPAD_ROW_PIN_1].pin = **pin**,
    .keypad_row_pins[KEYPAD_ROW_PIN_1].direction = GPIO_OUTPUT,
    .keypad_row_pins[KEYPAD_ROW_PIN_1].logic = **HIGH/LOW**,
  
    .keypad_row_pins[KEYPAD_ROW_PIN_2].port = **port**,
    .keypad_row_pins[KEYPAD_ROW_PIN_2].pin = **pin**,
    .keypad_row_pins[KEYPAD_ROW_PIN_2].direction = GPIO_OUTPUT,
    .keypad_row_pins[KEYPAD_ROW_PIN_2].logic = **HIGH/LOW**,
   
    .keypad_row_pins[KEYPAD_ROW_PIN_3].port = **port**,
    .keypad_row_pins[KEYPAD_ROW_PIN_3].pin = **pin**,
    .keypad_row_pins[KEYPAD_ROW_PIN_3].direction = GPIO_OUTPUT,
    .keypad_row_pins[KEYPAD_ROW_PIN_3].logic = **HIGH/LOW**,
  
 
  ` .keypad_col_pins[KEYPAD_COL_PIN_0].port = **port**,
    .keypad_col_pins[KEYPAD_COL_PIN_0].pin = **pin**,
    .keypad_col_pins[KEYPAD_COL_PIN_0].direction = GPIO_INPUT,
    .keypad_col_pins[KEYPAD_COL_PIN_0].logic = **HIGH/LOW**,
    
    .keypad_col_pins[KEYPAD_COL_PIN_1].port = **port**,
    .keypad_col_pins[KEYPAD_COL_PIN_1].pin = **pin**,
    .keypad_col_pins[KEYPAD_COL_PIN_1].direction = GPIO_INPUT,
    .keypad_col_pins[KEYPAD_COL_PIN_1].logic = **HIGH/LOW**,
  
    .keypad_col_pins[KEYPAD_COL_PIN_2].port = **port**,
    .keypad_col_pins[KEYPAD_COL_PIN_2].pin = **pin**,
    .keypad_col_pins[KEYPAD_COL_PIN_2].direction = GPIO_INPUT,
    .keypad_col_pins[KEYPAD_COL_PIN_2].logic = **HIGH/LOW**,
 
   `.keypad_col_pins[KEYPAD_COL_PIN_3].port = **port**,
    .keypad_col_pins[KEYPAD_COL_PIN_3].pin = **pin**,
    .keypad_col_pins[KEYPAD_COL_PIN_3].direction = GPIO_INPUT,
    .keypad_col_pins[KEYPAD_COL_PIN_3].logic = **HIGH/LOW**,

};

*/