/* 
 * File:   INT_INTERNAL.h
 * Author: Yousif Elraey
 *
 * Created on December 3, 2023, 5:39 PM
 */

#ifndef INT_INTERNAL_H
#define	INT_INTERNAL_H

/** Section #1: Includes */
#include "INT_CONFIG.h"

/** Section #1: Includes */
/** Section #2: Macros Deceleration */
/** Section #3: Data Types Definition  */

/** Section #4: Macros Functions Deceleration */
#if ADC_INTERRUPT_FEATURE_ENABLE == INT_FEATURE_ENABLE

#define ADC_INT_ENABLE()       (PIE1bits.ADIE = 1)
#define ADC_INT_DISABLE()      (PIE1bits.ADIE = 0)
#define ADC_INT_FLAG_CLEAR()   (PIR1bits.ADIF = 0)

#if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE

#define ADC_INT_HP_SET()       (IPR1bits.ADIP = 1)
#define ADC_INT_LP_SET()       (IPR1bits.ADIP = 0)

#endif

#endif

/** Section #5: Functions Deceleration */

#endif	/* INT_INTERNAL_H */

