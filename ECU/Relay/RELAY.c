/* 
 * File:   RELAY.c
 * Author: Yousif Elraey
 *
 * Created on October 4, 2023, 2:52 PM
 */

#include "RELAY.h"

/**
 * ECU_RELAY_Init - Initialize the configuration of a relay.
 *
 * This function initializes the configuration of a relay based on the provided
 * relay structure, including GPIO pin configuration, direction, and initial logic level.
 *
 * @param relay Pointer to the relay configuration structure.
 * @return      Returns the status of the operation:
 *              - E_OK if the relay configuration was successfully initialized.
 *              - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_RELAY_CONFIG == ENABLE
Std_ReturnType ECU_RELAY_Init(const relay_t *relay){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != relay){
        pin_config_t pin_obj = {
        .port = relay->port_relay,
        .pin = relay->pin_relay,
        .direction = GPIO_OUTPUT,
        .logic = relay->relay_status
        };
        GPIO_PIN_Init(&pin_obj);
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * ECU_RELAY_ONN - Turn ON a relay.
 *
 * This function sets the logic level of a relay to HIGH, turning the relay ON.
 *
 * @param relay Pointer to the relay configuration structure.
 * @return      Returns the status of the operation:
 *              - E_OK if the relay was successfully turned ON.
 *              - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_RELAY_CONFIG == ENABLE
Std_ReturnType ECU_RELAY_ONN(const relay_t *relay){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != relay){
        pin_config_t pin_obj = {
        .port = relay->port_relay,
        .pin = relay->pin_relay,
        .direction = GPIO_OUTPUT,
        .logic = relay->relay_status
        };
        GPIO_PIN_Write(&pin_obj, GPIO_HIGH);
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * ECU_RELAY_OFF - Turn OFF a relay.
 *
 * This function sets the logic level of a relay to LOW, turning the relay OFF.
 *
 * @param relay Pointer to the relay configuration structure.
 * @return      Returns the status of the operation:
 *              - E_OK if the relay was successfully turned OFF.
 *              - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_RELAY_CONFIG == ENABLE
Std_ReturnType ECU_RELAY_OFF(const relay_t *relay){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != relay){
        pin_config_t pin_obj = {
        .port = relay->port_relay,
        .pin = relay->pin_relay,
        .direction = GPIO_OUTPUT,
        .logic = relay->relay_status
        };
        GPIO_PIN_Write(&pin_obj, GPIO_LOW);
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif