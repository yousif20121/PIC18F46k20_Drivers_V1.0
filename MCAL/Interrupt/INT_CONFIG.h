/* 
 * File:   INT_CONFIG.h
 * Author: Yousif Elraey
 *
 * Created on December 3, 2023, 5:38 PM
 */

#ifndef INT_CONFIG_H
#define	INT_CONFIG_H

/** Section #1: Includes */
#include "../COMPILER.h"
#include "../STD_TYPES.h"
#include "../STD_LIBS.h"
#include "../GPIO/GPIO.h"
#include "INT_GEN_CFG.h"


/** Section #2: Macros Deceleration */

/* INT STATUS: ENABLE & DISABLE */
#define INT_ENABLE               1
#define INT_DISABLE              0

/* INT OCCURANCE: ENABLE & DISABLE */
#define INT_OCCUR                1
#define INT_NOT_OCCUR            0

/* INT PRIORITY: ENABLE & DISABLE */
#define INT_PRIORITY_ENABLE      1
#define INT_PRIORITY_DISABLE     0

/** Section #3: Data Types Definition  */
typedef enum{
    INTERRUPT_LP = 0,
    INTERRUPT_HP       
} interrupt_priority_cfg;

/** Section #4: Macros Functions Deceleration */

#if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE
/* INT IPEN: ENABLE & DISABLE */
#define INT_IPEN_ENABLE() (RCONbits.IPEN = 1)
#define INT_IPEN_DISABLE() (RCONbits.IPEN = 0)

/* INT GIEH: ENABLE & DISABLE */
#define INT_GIEH_ENABLE() (INTCONbits.GIEH = 1)
#define INT_GIEH_DISABLE() (INTCONbits.GIEH = 0)

/* INT GIEL: ENABLE & DISABLE */
#define INT_GIEL_ENABLE() (INTCONbits.GIEL = 1)
#define INT_GIEL_DISABLE() (INTCONbits.GIEL = 0)

#else
/* INT GIE: ENABLE & DISABLE */
#define INT_GIE_ENABLE() (INTCONbits.GIE = 1)
#define INT_GIE_DISABLE() (INTCONbits.GIE = 0)

/* INT PEIE: ENABLE & DISABLE */
#define INT_PEIE_ENABLE() (INTCONbits.PEIE = 1)
#define INT_PEIE_DISABLE() (INTCONbits.PEIE = 0)
#endif

/** Section #5: Functions Deceleration */

#endif	/* INT_CONFIG_H */

