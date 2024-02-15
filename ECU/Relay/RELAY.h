/* 
 * File:   RELAY.h
 * Author: Yousif Elraey
 *
 * Created on October 4, 2023, 2:52 PM
 */

#ifndef RELAY_H
#define	RELAY_H

/** Section #1: Includes */
#include "RELAY_CFG.h"
#include "../../MCAL/GPIO/GPIO.h"


/** Section #2: Macros Deceleration */

// Define status values for a relay: ON and OFF
#define RELAY_ON_STATUS         0x01U
#define RELAY_OFF_STATUS        0x00U


/** Section #3: Data Types Definition  */

// Structure for pin configuration
typedef struct{
    uint8 port_relay        :   4;
    uint8 pin_relay         :   3;
    uint8 relay_status      :   1;
} relay_t;


/** Section #5: Functions Deceleration */
Std_ReturnType ECU_RELAY_Init(const relay_t *relay);
Std_ReturnType ECU_RELAY_ONN(const relay_t *relay);
Std_ReturnType ECU_RELAY_OFF(const relay_t *relay);


#endif	/* RELAY_H */


/**
 * To use this relay driver:
 * Add extern relay_t **variable name** to app.h
 * Replace any thing within four asterisks with your data
 * ex: **port** ----> GPIO_PORTA
___________________________________________________________

relay_t **variable name** = {
    .port_led = **port**,
    .pin_led = **pin**,
    .relay_status = **ON or OFF**,
};

*/
