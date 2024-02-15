/* 
 * File:   BUTTON.h
 * Author: Yousif Elraey
 *
 * Created on October 3, 2023, 9:29 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

/** Section #1: Includes */
#include "../../MCAL/GPIO/GPIO.h"
#include "BUTTON_CFG.h"

/** Section #2: Data Types Definition  */

// Enumeration for button states
typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED        
} button_state_t;


// Enumeration for button connections
typedef enum{
    BUTTON_ACTIVE_HIGH = 0,
    BUTTON_ACTIVE_LOW        
} button_active_t;

// Structure for button configurations
typedef struct{
    pin_config_t button_pin;
    button_active_t button_connection;
    button_state_t button_state;
} button_t;

/** Section #3: Functions Deceleration */
Std_ReturnType ECU_BUTTON_Init(button_t *btn);
Std_ReturnType ECU_BUTTON_Read(button_t *btn, button_state_t *btn_state);


#endif	/* BUTTON_H */

/**
 * To use this button driver:
 * Replace any thing within four asterisks with your data
 * Add extern button_t **variable name** to app.h
 * ex: **port** ----> GPIO_PORTA
___________________________________________________________

button_t **variable name** = {
    .button_pin.port = **port**,
    .button_pin.pin = **pin**,
    .button_pin.direction = GPIO_INPUT,
    .button_pin.logic = GPIO_LOW,
    
    .button_connection = **active high or active low**,
    
    .button_state = **state at the beginning of operation**
};

button_state_t **variable name** = BUTTON_RELEASED;

*/