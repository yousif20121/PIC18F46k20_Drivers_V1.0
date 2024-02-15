/* 
 * File:   DC_Motor.h
 * Author: Yousif Elraey
 *
 * Created on October 5, 2023, 11:47 AM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/** Section #1: Includes */
#include "../../MCAL/GPIO/GPIO.h"
#include "DC_MOTOR_CFG.h"


/** Section #2: Macros Deceleration */

// Define status values for a DC motor: ON and OFF
#define DC_MOTOR_ON_STATUS          0x01U
#define DC_MOTOR_OFF_STATUS         0x00U

// Define constants representing DC motor pins configuration
#define DC_MOTOR_PIN_1              0x00U
#define DC_MOTOR_PIN_2              0x01U


/** Section #3: Data Types Definition  */

// Define a structure to represent a pair of DC motor configurations
typedef struct {
    pin_config_t dc_motor[2];  // Array of two DC motor pins configuration
} dc_motor_t;


/** Section #4: Functions Deceleration */
Std_ReturnType ECU_DC_MOTOR_Init(const dc_motor_t *dc_motor);
Std_ReturnType ECU_DC_MOTOR_Forward(const dc_motor_t *dc_motor);
Std_ReturnType ECU_DC_MOTOR_Stop(const dc_motor_t *dc_motor);
Std_ReturnType ECU_DC_MOTOR_Move_Right(const dc_motor_t *dc_motor);
Std_ReturnType ECU_DC_MOTOR_Move_Left(const dc_motor_t *dc_motor);

#endif	/* DC_MOTOR_H */

/**
 * To use this DC motor driver:
 * Replace any thing within four asterisks with your data
 * Add extern dc_motor_t **variable name** to app.h
 * ex: **port** ----> GPIO_PORTA
___________________________________________________________

dc_motor_t **variable name_1** = {
    .dc_motor[DC_MOTOR_PIN_1].port = **port**,
    .dc_motor[DC_MOTOR_PIN_1].pin = **pin**,
    .dc_motor[DC_MOTOR_PIN_1].direction = GPIO_OUTPUT,
    .dc_motor[DC_MOTOR_PIN_1].logic = **ON or OFF**,
 
    .dc_motor[DC_MOTOR_PIN_2].port = **port**,
    .dc_motor[DC_MOTOR_PIN_2].pin = **pin**,
    .dc_motor[DC_MOTOR_PIN_2].direction = GPIO_OUTPUT,
    .dc_motor[DC_MOTOR_PIN_2].logic = **ON or OFF**
};

*/