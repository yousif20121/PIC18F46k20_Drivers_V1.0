/* 
 * File:   INT_MANAGER.c
 * Author: Yousif Elraey
 *
 * Created on December 3, 2023, 5:40 PM
 */

#include "INT_MANAGER.h"
#include "INT_CONFIG.h"

static volatile uint8 RB4_Flag = 1;
static volatile uint8 RB5_Flag = 1;
static volatile uint8 RB6_Flag = 1;
static volatile uint8 RB7_Flag = 1;

#if INT_PRIORITY_LEVELS_EN == 0


/**
 * @brief High-priority interrupt service routine.
 *
 * This function handles high-priority interrupts and calls specific
 * interrupt service routines based on the interrupt source.
 * The interrupt sources checked are INT0 and INT2.
 */
void __interrupt() InterruptManagerHigh(void){
    if((INT_ENABLE == INTCONbits.INT0IE) && (INT_OCCUR == INTCONbits.INT0IF)) {
        INT0_ISR();
    }
    else{ /* Nothing */ }
    if((INT_ENABLE == INTCON3bits.INT2IE) && (INT_OCCUR == INTCON3bits.INT2IF)) {
       INT2_ISR();
    }
    else{ /* Nothing */ }

}


/**
 * @brief Low-priority interrupt service routine.
 *
 * This function handles low-priority interrupts and calls a specific
 * interrupt service routine based on the interrupt source, which is INT1.
 */
void __interrupt(low_priority) InterruptManagerLow(void){
    if((INT_ENABLE == INTCON3bits.INT1IE) && (INT_OCCUR == INTCON3bits.INT1IF)) {
       INT2_ISR();
    }
    else{ /* Nothing */ }


}

#else
/**
 * @brief Interrupt service routine for handling external and change-on-port interrupts.
 *
 * This function handles various interrupts, including INT0, INT1, INT2, and change-on-port interrupts
 * for specific pins (RB4, RB5, RB6, RB7). It calls corresponding interrupt service routines based on the
 * interrupt sources and conditions.
 */
void __interrupt() InterruptManager(void){
    /*INTx pins */
    if((INT_ENABLE == INTCONbits.INT0IE) && (INT_OCCUR == INTCONbits.INT0IF)) {
        INT0_ISR();
    }
    else{ /* Nothing */ }
    
    if((INT_ENABLE == INTCON3bits.INT1IE) && (INT_OCCUR == INTCON3bits.INT1IF)) {
        INT1_ISR();
    }
    else{ /* Nothing */ }
    
    if((INT_ENABLE == INTCON3bits.INT2IE) && (INT_OCCUR == INTCON3bits.INT2IF)) {
        INT2_ISR();
    }
    else{ /* Nothing */ }
    
    
    /* On change pins */
    if((INT_ENABLE == INTCONbits.RBIE) && (INT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_HIGH) && (1 == RB4_Flag)) {
        RB4_Flag = 0;
        RB4_ISR(0);
    }
    else{ /* Nothing */ }
    if((INT_ENABLE == INTCONbits.RBIE) && (INT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == GPIO_LOW) && (0 == RB4_Flag)) {
        RB4_Flag = 1;
        RB4_ISR(1);
    }
    else{ /* Nothing */ }
    
    
    if((INT_ENABLE == INTCONbits.RBIE) && (INT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_HIGH) && (1 == RB5_Flag)) {
        RB5_Flag = 0;
        RB5_ISR(0);
    }
    else{ /* Nothing */ }
    
    if((INT_ENABLE == INTCONbits.RBIE) && (INT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == GPIO_LOW) && (0 == RB5_Flag)) {
        RB5_Flag = 1;
        RB5_ISR(1);
    }
    else{ /* Nothing */ }
    
    
    if((INT_ENABLE == INTCONbits.RBIE) && (INT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_HIGH) && (1 == RB6_Flag)) {
        RB6_Flag = 0;
        RB6_ISR(0);
    }
    else{ /* Nothing */ }
    
    if((INT_ENABLE == INTCONbits.RBIE) && (INT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == GPIO_LOW) && (0 == RB6_Flag)) {
        RB6_Flag = 1;
        RB6_ISR(1);
    }
    else{ /* Nothing */ }
    
    
    if((INT_ENABLE == INTCONbits.RBIE) && (INT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_HIGH) && (1 == RB7_Flag)) {
        RB7_Flag = 0;
        RB7_ISR(0);
    }
    else{ /* Nothing */ }
    
    if((INT_ENABLE == INTCONbits.RBIE) && (INT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == GPIO_LOW) && (0 == RB7_Flag)) {
        RB7_Flag = 1;
        RB7_ISR(1);
    }
    else{ /* Nothing */ }
    

}


#endif