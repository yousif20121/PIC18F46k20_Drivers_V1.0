/* 
 * File:   LED.h
 * Author: Yousif Elraey
 *
 * Created on September 23, 2023, 8:42 PM
 */

#include "LED.h"

/**
 * ECU_LED_Init - Initialize the configuration of an LED.
 *
 * This function initializes the configuration of an LED based on the provided
 * LED structure, including GPIO pin configuration, direction, and initial logic level.
 *
 * @param led Pointer to the LED configuration structure.
 * @return    Returns the status of the operation:
 *            - E_OK if the LED configuration was successfully initialized.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_LED_CONFIG == ENABLE
Std_ReturnType ECU_LED_Init(const led_t *led){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != led){
        pin_config_t pin_obj = {
        .port = led->port_led,
        .pin = led->pin_led,
        .direction = GPIO_OUTPUT,
        .logic = led->led_status
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
 * ECU_LED_ON - Turn ON an LED.
 *
 * This function sets the logic level of an LED to HIGH, turning the LED ON.
 *
 * @param led Pointer to the LED configuration structure.
 * @return    Returns the status of the operation:
 *            - E_OK if the LED was successfully turned ON.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_LED_CONFIG == ENABLE
Std_ReturnType ECU_LED_ON(const led_t *led){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != led){
        pin_config_t pin_obj = {
        .port = led->port_led,
        .pin = led->pin_led,
        .direction = GPIO_OUTPUT,
        .logic = led->led_status
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
 * ECU_LED_OFF - Turn OFF an LED.
 *
 * This function sets the logic level of an LED to LOW, turning the LED OFF.
 *
 * @param led Pointer to the LED configuration structure.
 * @return    Returns the status of the operation:
 *            - E_OK if the LED was successfully turned OFF.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_LED_CONFIG == ENABLE
Std_ReturnType ECU_LED_OFF(const led_t *led){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != led){
        pin_config_t pin_obj = {
        .port = led->port_led,
        .pin = led->pin_led,
        .direction = GPIO_OUTPUT,
        .logic = led->led_status
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

/**
 * ECU_LED_TOGGLE - Toggle the state of an LED.
 *
 * This function toggles the state of an LED by changing its logic level.
 *
 * @param led Pointer to the LED configuration structure.
 * @return    Returns the status of the operation:
 *            - E_OK if the LED state was successfully toggled.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_LED_CONFIG == ENABLE
Std_ReturnType ECU_LED_TOGGLE(const led_t *led){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != led){
        pin_config_t pin_obj = {
        .port = led->port_led,
        .pin = led->pin_led,
        .direction = GPIO_OUTPUT,
        .logic = led->led_status
        };
        GPIO_PIN_Toggle(&pin_obj);
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif