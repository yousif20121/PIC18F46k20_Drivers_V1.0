/** 
 * File:   STD_TYPES.h
 * Author: Yousif Elraey
 *
 * Created on September 23, 2023, 8:54 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H


/** Section #1: Includes */
#include "STD_LIBS.h"
#include "DEVICE_CFG.h"
#include "COMPILER.h"


/** Section #2: Macros Deceleration */

/** OUTPUT: HIGH & LOW */
#define STD_HIGH                            0x01
#define STD_LOW                             0x00

/** STATUS: ACTIVE & IDLE */
#define STD_ACTIVE                          0x01
#define STD_IDLE                            0x00

/** RETURN TYPES: OK & N_OK */
#define E_OK                (Std_ReturnType)0x01
#define E_NOT_OK            (Std_ReturnType)0x00

/** MAX NUM: PORT_MAX & PIN_MAX */
#define PORT_MAX                               5
#define PIN_MAX                                8

/** ZERO MACRO */
#define ZERO_INIT                           0x00 


/** Section #3: Data Types Definition  */

/** Unsigned Data Types */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

/** Signed Data Types */
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

/** Standard Return Type for All Functions */
typedef uint8 Std_ReturnType;


#endif	/* STD_TYPES_H */

