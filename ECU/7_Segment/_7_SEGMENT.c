/* 
 * File:   _7_SEGMENT.c
 * Author: Yousif Elraey
 *
 * Created on October 5, 2023, 6:38 PM
 */

#include "_7_SEGMENT.h"

/**
 * ECU_7_SEG_Init - Initialize the configuration of a 7-segment display.
 *
 * This function initializes the configuration of a 7-segment display based on the
 * provided segment structure, including GPIO pin configurations for each segment.
 *
 * @param seg Pointer to the 7-segment display configuration structure.
 * @return    Returns the status of the operation:
 *            - E_OK if the 7-segment display configuration was successfully initialized.
 *            - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_7_SEG_CONFIG == ENABLE
Std_ReturnType ECU_7_SEG_Init(const segment_t *seg){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != seg){
        ret = GPIO_PIN_Init(&(seg->segment_pins[_7_SEG_PIN_0]));
        ret = GPIO_PIN_Init(&(seg->segment_pins[_7_SEG_PIN_1]));
        ret = GPIO_PIN_Init(&(seg->segment_pins[_7_SEG_PIN_2]));
        ret = GPIO_PIN_Init(&(seg->segment_pins[_7_SEG_PIN_3]));
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * ECU_7_SEG_Write_Number - Display a decimal number on a 7-segment display.
 *
 * This function configures the 7-segment display to visually represent the provided
 * decimal number using individual GPIO pins for each segment.
 *
 * @param seg    Pointer to the 7-segment display configuration structure.
 * @param number Decimal number to be displayed (0 to 15 for a 4-bit display).
 * @return       Returns the status of the operation:
 *               - E_OK if the number was successfully displayed on the 7-segment display.
 *               - E_NOT_OK if an error occurred (e.g., NULL pointer or invalid number).
 */
#if ECU_7_SEG_CONFIG == ENABLE
Std_ReturnType ECU_7_SEG_Write_Number(const segment_t *seg, uint8 number){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != seg && number <= MAX_NUM){
        ret = GPIO_PIN_Write(&(seg->segment_pins[_7_SEG_PIN_0]), (number & 0x01));
        ret = GPIO_PIN_Write(&(seg->segment_pins[_7_SEG_PIN_1]), ((number >>1) & 0x01));
        ret = GPIO_PIN_Write(&(seg->segment_pins[_7_SEG_PIN_1]), ((number >>2) & 0x01));
        ret = GPIO_PIN_Write(&(seg->segment_pins[_7_SEG_PIN_1]), ((number >>3) & 0x01));
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif