/* 
 * File:   INT_EXTERNAL.h
 * Author: Yousif Elraey
 *
 * Created on December 3, 2023, 5:39 PM
 */

#ifndef INT_EXTERNAL_H
#define	INT_EXTERNAL_H

/** Section #1: Includes */
#include "INT_CONFIG.h"

/** Section #2: Macros Deceleration */

/** Section #3: Data Types Definition  */
typedef enum{
    INT_FALLING_EDGE = 0,
    INT_RISING_EDGE       
} interrupt_INTx_edge;

typedef enum{
    INT_EXT_INT0 = 0,
    INT_EXT_INT1,
    INT_EXT_INT2
} interrupt_INTx_src;


typedef struct{
    void(* INT_EXT_HANDLER)(void);
    pin_config_t mcu_pin;
    interrupt_INTx_edge edge;
    interrupt_INTx_src src;
    interrupt_priority_cfg priority; 
} interrupt_INTx_t;

typedef struct{
    void(* INT_EXT_HANDLER_HIGH)(void);
    void(* INT_EXT_HANDLER_LOW)(void);
    pin_config_t mcu_pin;
    interrupt_priority_cfg priority;
} interrupt_RBx_t;

/** Section #4: Macros Functions Deceleration */
/* INTx PORTS */
#if INT_EXT_INTx_FEATURE_EN == INT_FEATURE_ENABLE

/* INT0 */
#define INT_EXT_INT0_ENABLE()       (INTCONbits.INT0IE = 1)
#define INT_EXT_INT0_DISABLE()      (INTCONbits.INT0IE = 0)

#define INT_EXT_INT0_FLAG_CLEAR()   (INTCONbits.INT0IF = 0)

#define INT_EXT_INT0_RISING_SET()   (INTCON2bits.INTEDG0 = 1)
#define INT_EXT_INT0_FALLING_SET()  (INTCON2bits.INTEDG0 = 0) 

/* INT1 */
#define INT_EXT_INT1_ENABLE()       (INTCON3bits.INT1IE = 1)
#define INT_EXT_INT1_DISABLE()      (INTCON3bits.INT1IE = 0)

#define INT_EXT_INT1_FLAG_CLEAR()   (INTCON3bits.INT1IF = 0)

#define INT_EXT_INT1_RISING_SET()   (INTCON2bits.INTEDG1 = 1)
#define INT_EXT_INT1_FALLING_SET()  (INTCON2bits.INTEDG1 = 0)

/* INT2 */
#define INT_EXT_INT2_ENABLE()       (INTCON3bits.INT2IE = 1)
#define INT_EXT_INT2_DISABLE()      (INTCON3bits.INT2IE = 0)

#define INT_EXT_INT2_FLAG_CLEAR()   (INTCON3bits.INT2IF = 0)

#define INT_EXT_INT2_RISING_SET()   (INTCON2bits.INTEDG2 = 1)
#define INT_EXT_INT2_FALLING_SET()  (INTCON2bits.INTEDG2 = 0)

#if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE

/* INT1 */
#define INT_EXT_INT1_HP_SET()       (INTCON3bits.INT1IP = 1)
#define INT_EXT_INT1_LP_SET()       (INTCON3bits.INT1IP = 0)

/* INT2 */
#define INT_EXT_INT2_HP_SET()       (INTCON3bits.INT2IP = 1)
#define INT_EXT_INT2_LP_SET()       (INTCON3bits.INT2IP = 0)

#endif

#endif

/* ON CHANGE PORTS KBx */
#if INT_OC_FEATURE_EN == INT_FEATURE_ENABLE

/* RBx */
#define INT_EXT_RB_ENABLE()         (INTCONbits.RBIE = 1)
#define INT_EXT_RB_DISABLE()        (INTCONbits.RBIE = 0)
#define INT_EXT_RB_FLAG_CLEAR()     (INTCONbits.RBIF = 0)

#if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE

#define INT_EXT_RB_PRIORITY_HIGH()    (INTCON2bits.RBIP = 1)
#define INT_EXT_RB_PRIORITY_LOW()     (INTCON2bits.RBIP = 0)

#endif

#endif

/** Section #5: Functions Deceleration */
Std_ReturnType INT_INTx_Init(const interrupt_INTx_t *int_obj);
Std_ReturnType INT_INTx_Terminate(const interrupt_INTx_t *int_obj);
Std_ReturnType INT_RBx_Init(const interrupt_RBx_t *int_obj);
Std_ReturnType INT_RBx_Terminate(const interrupt_INTx_t *int_obj);


#endif	/* INT_EXTERNAL_H */

