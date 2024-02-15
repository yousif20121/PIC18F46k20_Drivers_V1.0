/* 
 * File:   ECU_INIT.h
 * Author: Yousif ELraey
 *
 * Created on October 6, 2023, 9:45 PM
 */

#ifndef ECU_INIT_H
#define	ECU_INIT_H

/** Section #1: Includes */
#include <stdio.h>
#include <stdlib.h>
#include "../MCAL/GPIO/GPIO.h"
#include "LED/LED.h"
#include "Button/BUTTON.h"
#include "Relay/RELAY.h"
#include "DC_Motor/DC_MOTOR.h"
#include "7_Segment/_7_SEGMENT.h"
#include "Keypad/KEYPAD.h"
#include "Char_LCD/CHAR_LCD.h"

/** Section #2: Functions Deceleration */
void ECU_Init(void);


#endif	/* ECU_INIT_H */

