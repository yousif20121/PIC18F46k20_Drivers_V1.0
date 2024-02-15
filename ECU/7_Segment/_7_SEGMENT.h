/* 
 * File:   _7_SEGMENT.h
 * Author: Yousif Elraey
 *
 * Created on October 5, 2023, 6:37 PM
 */

#ifndef _7_SEGMENT_H
#define	_7_SEGMENT_H

/** Section #1: Includes */
#include "../../MCAL/GPIO/GPIO.h"
#include "_7_SEGMENT_CFG.h"

/** Section #2: Macros Deceleration */

//
#define _7_SEG_PIN_0            0
#define _7_SEG_PIN_1            1
#define _7_SEG_PIN_2            2
#define _7_SEG_PIN_3            3

//
#define MAX_NUM                 9

/** Section #3: Data Types Definition  */

//
typedef enum{
    SEG_COM_ANODE = 0,
    SEG_COM_CATHODE       
} segment_type_t;


//
typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
} segment_t;


/** Section #4: Functions Deceleration */
Std_ReturnType ECU_7_SEG_Init(const segment_t *seg);
Std_ReturnType ECU_7_SEG_Write_Number(const segment_t *seg, uint8 number);

#endif	/* _7_SEGMENT_H */

/**
 * To use this 7 Segment driver:
 * Attach 7 Segment with BCD Encoder
 * Add extern segment_t **variable name** to app.h
 * Replace any thing within four asterisks with your data
 * ex: **port** ----> GPIO_PORTA
___________________________________________________________

segment_t **variable name** = {
    .segment_pins[_7_SEG_PIN_0].port = **port**,
    .segment_pins[_7_SEG_PIN_0].pin = **pin**,
    .segment_pins[_7_SEG_PIN_0].direction = GPIO_OUTPUT,
    .segment_pins[_7_SEG_PIN_0].logic = **HIGH/LOW**
    
    .segment_pins[_7_SEG_PIN_1].port = **port**,
    .segment_pins[_7_SEG_PIN_1].pin = **pin**,
    .segment_pins[_7_SEG_PIN_1].direction = GPIO_OUTPUT,
    .segment_pins[_7_SEG_PIN_1].logic = **HIGH/LOW**
   
    .segment_pins[_7_SEG_PIN_2].port = **port**,
    .segment_pins[_7_SEG_PIN_2].pin = **pin**,
    .segment_pins[_7_SEG_PIN_2].direction = GPIO_OUTPUT,
    .segment_pins[_7_SEG_PIN_2].logic = **HIGH/LOW**
   
    .segment_pins[_7_SEG_PIN_2].port = **port**,
    .segment_pins[_7_SEG_PIN_2].pin = **pin**,
    .segment_pins[_7_SEG_PIN_2].direction = GPIO_OUTPUT,
    .segment_pins[_7_SEG_PIN_2].logic = **HIGH/LOW**
   
     .segment_type = **ANODE/CATHODE**
};

*/