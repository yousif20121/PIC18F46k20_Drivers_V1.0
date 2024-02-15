/* 
 * File:   INT_MANAGER.h
 * Author: Yousif Elraey
 *
 * Created on December 3, 2023, 5:40 PM
 */

#ifndef INT_MANAGER_H
#define	INT_MANAGER_H

/** Section #1: Includes */
#include "INT_CONFIG.h"

/** Section #1: Includes */
/** Section #2: Macros Deceleration */
/** Section #3: Data Types Definition  */
/** Section #4: Macros Functions Deceleration */


/** Section #5: Functions Deceleration */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 RB4_Source);
void RB5_ISR(uint8 RB5_Source);
void RB6_ISR(uint8 RB6_Source);
void RB7_ISR(uint8 RB7_Source);

#endif	/* INT_MANAGER_H */

