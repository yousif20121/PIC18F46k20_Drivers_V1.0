/* 
 * File:   DC_MOTOR.c
 * Author: Yousif Elraey
 *
 * Created on October 5, 2023, 11:49 AM
 */

#include "DC_MOTOR.h"

/**
 * ECU_DC_MOTOR_Init - Initialize the configuration of a DC motor.
 *
 * This function initializes the configuration of a DC motor based on the provided
 * DC motor structure, including GPIO pin configurations for motor control.
 *
 * @param dc_motor Pointer to the DC motor configuration structure.
 * @return         Returns the status of the operation:
 *                 - E_OK if the DC motor configuration was successfully initialized.
 *                 - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_DC_MOTOR_CONFIG == ENABLE
Std_ReturnType ECU_DC_MOTOR_Init(const dc_motor_t *dc_motor){
   
   Std_ReturnType ret = E_NOT_OK;
   
   if(NULL != dc_motor){
       
       GPIO_PIN_Direction_Init(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]));
       GPIO_PIN_Direction_Init(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]));
       
       ret = E_OK;
   }
   else{
       ret = E_NOT_OK;
   }
   
   return ret;
   
}
#endif

/**
 * ECU_DC_MOTOR_Forward - Activate forward motion for a DC motor.
 *
 * This function sets the control pins of a DC motor to enable forward motion.
 *
 * @param dc_motor Pointer to the DC motor configuration structure.
 * @return         Returns the status of the operation:
 *                 - E_OK if the DC motor was successfully set to move forward.
 *                 - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_DC_MOTOR_CONFIG == ENABLE
Std_ReturnType ECU_DC_MOTOR_Forward(const dc_motor_t *dc_motor){
    
   Std_ReturnType ret = E_NOT_OK;
   
   if(NULL != dc_motor){
       
       GPIO_PIN_Write(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]), GPIO_HIGH);
       GPIO_PIN_Write(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]), GPIO_HIGH);
       
       ret = E_OK;
   }
   else{
       ret = E_NOT_OK;
   }
   
   return ret;

}
#endif

/**
 * ECU_DC_MOTOR_Stop - Stop motion for a DC motor.
 *
 * This function sets the control pins of a DC motor to stop its motion.
 *
 * @param dc_motor Pointer to the DC motor configuration structure.
 * @return         Returns the status of the operation:
 *                 - E_OK if the DC motor was successfully stopped.
 *                 - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_DC_MOTOR_CONFIG == ENABLE
Std_ReturnType ECU_DC_MOTOR_Stop(const dc_motor_t *dc_motor){
    
   Std_ReturnType ret = E_NOT_OK;
   
   if(NULL != dc_motor){
       
       GPIO_PIN_Write(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]), GPIO_LOW);
       GPIO_PIN_Write(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]), GPIO_LOW);
       
       ret = E_OK;
   }
   else{
       ret = E_NOT_OK;
   }
   
   return ret;

}
#endif

/**
 * ECU_DC_MOTOR_Move_Right - Activate rightward motion for a DC motor.
 *
 * This function sets the control pins of a DC motor to enable rightward motion.
 *
 * @param dc_motor Pointer to the DC motor configuration structure.
 * @return         Returns the status of the operation:
 *                 - E_OK if the DC motor was successfully set to move right.
 *                 - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_DC_MOTOR_CONFIG == ENABLE
Std_ReturnType ECU_DC_MOTOR_Move_Right(const dc_motor_t *dc_motor){
    
   Std_ReturnType ret = E_NOT_OK;
   
   if(NULL != dc_motor){
       
       GPIO_PIN_Write(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]), GPIO_HIGH);
       GPIO_PIN_Write(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]), GPIO_LOW);
       
       ret = E_OK;
   }
   else{
       ret = E_NOT_OK;
   }
   
   return ret;

}
#endif

/**
 * ECU_DC_MOTOR_Move_Left - Activate leftward motion for a DC motor.
 *
 * This function sets the control pins of a DC motor to enable leftward motion.
 *
 * @param dc_motor Pointer to the DC motor configuration structure.
 * @return         Returns the status of the operation:
 *                 - E_OK if the DC motor was successfully set to move left.
 *                 - E_NOT_OK if an error occurred (e.g., NULL pointer).
 */
#if ECU_DC_MOTOR_CONFIG == ENABLE
Std_ReturnType ECU_DC_MOTOR_Move_Left(const dc_motor_t *dc_motor){
    
   Std_ReturnType ret = E_NOT_OK;
   
   if(NULL != dc_motor){
       
       GPIO_PIN_Write(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]), GPIO_LOW);
       GPIO_PIN_Write(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]), GPIO_HIGH);
       
       ret = E_OK;
   }
   else{
       ret = E_NOT_OK;
   }
   
   return ret;

}
#endif


