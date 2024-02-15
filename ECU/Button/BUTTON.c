/* 
 * File:   BUTTON.c
 * Author: Yousif Elraey
 *
 * Created on October 3, 2023, 9:29 PM
 */

#include "BUTTON.h"


/**
 * ECU_BUTTON_Init - Initialize the configuration of a button.
 *
 * This function initializes the configuration of a button based on the provided
 * button structure, including GPIO pin configuration and direction.
 *
 * @param btn Pointer to the button configuration structure.
 * @return    Returns the status of the operation:
 *            - E_OK if the button configuration was successfully initialized.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_BUTTON_CONFIG == ENABLE
Std_ReturnType ECU_BUTTON_Init(button_t *btn){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(btn != NULL){
        ret = GPIO_PIN_Direction_Init(&(btn->button_pin));
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * ECU_BUTTON_Read - Read the state of a button.
 *
 * This function reads the current state of a button based on the provided
 * button configuration and updates the btn_state variable accordingly.
 *
 * @param btn       Pointer to the button configuration structure.
 * @param btn_state Pointer to a variable to store the retrieved button state.
 * @return          Returns the status of the operation:
 *                  - E_OK if the button state was successfully read.
 *                  - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_BUTTON_CONFIG == ENABLE
Std_ReturnType ECU_BUTTON_Read(button_t *btn, button_state_t *btn_state){
    
    Std_ReturnType ret = E_NOT_OK;
    
    logic_t pin_logic_status = GPIO_LOW;
    
    
    if(NULL != btn && NULL != btn_state){
        
        GPIO_PORT_Read(&(btn->button_pin), &pin_logic_status);
        
        if(BUTTON_ACTIVE_HIGH == btn->button_connection){
            if(GPIO_HIGH == pin_logic_status){
                *btn_state = BUTTON_PRESSED;
            }
            else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_connection){
            if(GPIO_HIGH == pin_logic_status){
                *btn_state = BUTTON_RELEASED;
            }
            else{
                *btn_state = BUTTON_PRESSED;
            }
        }
        else{/* Nothing */}
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

