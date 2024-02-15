/* 
 * File:   LED.h
 * Author: Yousif Elraey
 *
 * Created on September 23, 2023, 8:42 PM
 */

#ifndef LED_H
#define	LED_H

/** Section #1: Includes */
#include "../../MCAL/GPIO/GPIO.h"
#include "LED_CFG.h"

/** Section #2: Data Types Definition  */

// Enumeration for LED levels
typedef enum {
    LED_OFF = 0,
    LED_ON
}led_status_t;

// Structure for LED configuration
typedef struct{
    uint8 port_led          :   3;
    uint8 pin_led           :   4;
    uint8 led_status        :   1;
}led_t;

/** Section #3: Functions Deceleration */
Std_ReturnType ECU_LED_Init(const led_t *led);
Std_ReturnType ECU_LED_ON(const led_t *led);
Std_ReturnType ECU_LED_OFF(const led_t *led);
Std_ReturnType ECU_LED_TOGGLE(const led_t *led);

#endif	/* LED_H */

/**
 * To use this LED driver:
 * Add extern led_t **variable name** to app.h
 * Replace any thing within four asterisks with your data
 * ex: **port** ----> GPIO_PORTA
___________________________________________________________

led_t **variable name** = {
    .port_led = **port**,
    .pin_led = **pin**,
    led_status = **ON or OFF**,
};

*/