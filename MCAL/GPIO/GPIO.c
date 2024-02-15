 /**
 * File:   GPIO.h
 *
 * Author: Yousif Elraey
 *
 * Created on September 23, 2023, 8:32 PM
 */

#include "GPIO.h"

/** Array of pointers to TRIS (Data Direction) Registers for each port */
volatile uint8 *TRIS_REG[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};

/** Array of pointers to LAT (Latch) Registers for each port */
volatile uint8 *LAT_REG[] = {&LATA, &LATB, &LATC, &LATD, &LATE};

/** Array of pointers to PORT Registers for each port */
volatile uint8 *PORT_REG[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};


                                /** PIN Control Functions */

/**
 * GPIO_PIN_Direction_Init - Initialize the direction of a GPIO pin based on the provided configuration.
 *
 * This function initializes the direction of a GPIO pin (input or output) based on the
 * configuration provided in the pin_config structure.
 *
 * @param _pin_config  Pointer to the pin configuration structure. @ref pin_config_t
 * @return             Returns the status of the operation:
 *                     - E_OK if the pin direction was successfully initialized.
 *                     - E_NOT_OK if an error occurred (e.g., invalid pin configuration).
 */
#if GPIO_PIN_CONFIG == ENABLE
Std_ReturnType GPIO_PIN_Direction_Init(const pin_config_t *_pin_config){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _pin_config && _pin_config->port <= PORT_MAX - 1 && _pin_config->pin <= PIN_MAX - 1){
        switch(_pin_config->direction){
            case GPIO_OUTPUT:
                CLEAR_BIT(*TRIS_REG[_pin_config->port], _pin_config->pin);
                ret = E_OK;
                break;
            
            case GPIO_INPUT:
                SET_BIT(*TRIS_REG[_pin_config->port], _pin_config->pin);
                ret = E_OK;
                break;
            
            default:    
                ret = E_NOT_OK;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * GPIO_PIN_Write - Write a logic level to a GPIO pin.
 *
 * This function writes a logic level (GPIO_LOW or GPIO_HIGH) to a specified GPIO pin
 * based on the provided pin configuration.
 *
 * @param _pin_config  Pointer to the pin configuration structure.
 * @param logic        The logic level to be written to the pin (GPIO_LOW or GPIO_HIGH).
 * @return            Returns the status of the operation:
 *                    - E_OK if the operation was successful.
 *                    - E_NOT_OK if an error occurred (e.g., invalid pin configuration or logic value).
 */
#if GPIO_PIN_CONFIG == ENABLE
Std_ReturnType GPIO_PIN_Write(const pin_config_t *_pin_config, logic_t logic){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _pin_config && _pin_config->port <= PORT_MAX - 1 && _pin_config->pin <= PIN_MAX - 1){
        switch(logic){
            case GPIO_LOW:
                CLEAR_BIT(*LAT_REG[_pin_config->port], _pin_config->pin);
                ret = E_OK;
                break;
                
            case GPIO_HIGH:
                SET_BIT(*LAT_REG[_pin_config->port], _pin_config->pin);
                ret = E_OK;
                break;
                
            default:
                ret = E_NOT_OK;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * GPIO_PIN_Init - Initialize a GPIO pin based on the provided configuration.
 *
 * This function initializes a GPIO pin by setting its direction and initial logic level
 * based on the configuration provided in the pin_config structure.
 *
 * @param _pin_config  Pointer to the pin configuration structure.
 * @return             Returns the status of the operation:
 *                     - E_OK if the pin was successfully initialized.
 *                     - E_NOT_OK if an error occurred (e.g., invalid pin configuration).
 */
#if GPIO_PIN_CONFIG == ENABLE
Std_ReturnType GPIO_PIN_Init(const pin_config_t *_pin_config){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _pin_config && _pin_config->port <= PORT_MAX - 1 && _pin_config->pin <= PIN_MAX - 1){
        ret = GPIO_PIN_Direction_Init(_pin_config);
        if(E_OK == ret){
           ret = GPIO_PIN_Write(_pin_config, _pin_config->logic);
        }
        else{
            ret = E_NOT_OK;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

/**
 * GPIO_PIN_Get_Direction - Get the current direction status of a GPIO pin.
 *
 * This function retrieves the current direction status (input or output) of a GPIO pin
 * based on the provided pin configuration and updates the direction_status variable.
 *
 * @param _pin_config      Pointer to the pin configuration structure.
 * @param direction_status Pointer to a variable to store the retrieved direction status.
 * @return                 Returns the status of the operation:
 *                         - E_OK if the direction status was successfully retrieved.
 *                         - E_NOT_OK if an error occurred (e.g., invalid pin configuration or NULL pointer).
 */
#if GPIO_PIN_CONFIG == ENABLE
Std_ReturnType GPIO_PIN_Get_Direction(const pin_config_t *_pin_config, direction_t *direction_status){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _pin_config && NULL != direction_status && _pin_config->port <= PORT_MAX - 1 && _pin_config->pin <= PIN_MAX - 1){
        *direction_status = READ_BIT(*TRIS_REG[_pin_config->port], _pin_config->pin);
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * GPIO_PIN_Read - Read the logic level of a GPIO pin.
 *
 * This function reads the current logic level of a GPIO pin based on the provided
 * pin configuration and updates the logic variable.
 *
 * @param _pin_config  Pointer to the pin configuration structure.
 * @param logic        Pointer to a variable to store the retrieved logic level.
 * @return             Returns the status of the operation:
 *                     - E_OK if the logic level was successfully read.
 *                     - E_NOT_OK if an error occurred (e.g., invalid pin configuration or NULL pointer).
 */
#if GPIO_PIN_CONFIG == ENABLE
Std_ReturnType GPIO_PIN_Read(const pin_config_t *_pin_config, logic_t *logic){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _pin_config && NULL != logic && _pin_config->port <= PORT_MAX - 1 && _pin_config->pin <= PIN_MAX - 1){
        *logic = READ_BIT(*PORT_REG[_pin_config->port], _pin_config->pin);
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * GPIO_PIN_Toggle - Toggle the logic level of a GPIO pin.
 *
 * This function toggles the current logic level of a GPIO pin based on the provided
 * pin configuration.
 *
 * @param _pin_config  Pointer to the pin configuration structure.
 * @return             Returns the status of the operation:
 *                     - E_OK if the logic level was successfully toggled.
 *                     - E_NOT_OK if an error occurred (e.g., invalid pin configuration).
 */
#if GPIO_PIN_CONFIG == ENABLE
Std_ReturnType GPIO_PIN_Toggle(const pin_config_t *_pin_config){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _pin_config && _pin_config->port <= PORT_MAX - 1 && _pin_config->pin <= PIN_MAX - 1){
        TOGGLE_BIT(*LAT_REG[_pin_config->port], _pin_config->pin);
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif


                                /** PORT Control Functions */

/**
 * GPIO_PORT_Direction_Init - Initialize the direction of all pins in a GPIO port.
 *
 * This function initializes the direction of all pins in a GPIO port based on the
 * provided port index and direction value.
 *
 * @param port      The index of the GPIO port.
 * @param direction The direction value to set for all pins in the port (e.g., TRIS register value).
 * @return          Returns the status of the operation:
 *                  - E_OK if the port direction was successfully initialized.
 *                  - E_NOT_OK if an error occurred (e.g., invalid port index).
 */
#if GPIO_PORT_CONFIG == ENABLE
Std_ReturnType GPIO_PORT_Direction_Init(port_index_t port, uint8 direction){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(port <= PORT_MAX - 1){
        *TRIS_REG[port] = direction;
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * GPIO_PORT_Get_Direction - Get the current direction status of a GPIO port.
 *
 * This function retrieves the current direction status of all pins in a GPIO port
 * based on the provided port index and updates the direction_status variable.
 *
 * @param port             The index of the GPIO port.
 * @param direction_status Pointer to a variable to store the retrieved direction status.
 * @return                 Returns the status of the operation:
 *                         - E_OK if the direction status was successfully retrieved.
 *                         - E_NOT_OK if an error occurred (e.g., invalid port index or NULL pointer).
 */
#if GPIO_PORT_CONFIG == ENABLE
Std_ReturnType GPIO_PORT_Get_Direction(port_index_t port, uint8 *direction_status){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(port <= PORT_MAX - 1 && NULL != direction_status){
        *direction_status = *TRIS_REG[port];
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * GPIO_PORT_Write - Write a logic level to all pins in a GPIO port.
 *
 * This function writes a logic level to all pins in a GPIO port based on the provided
 * port index and logic value.
 *
 * @param port   The index of the GPIO port.
 * @param logic  The logic level to be written to all pins in the port.
 * @return       Returns the status of the operation:
 *               - E_OK if the logic level was successfully written to the port.
 *               - E_NOT_OK if an error occurred (e.g., invalid port index).
 */
#if GPIO_PORT_CONFIG == ENABLE
Std_ReturnType GPIO_PORT_Write(port_index_t port, uint8 logic){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(port <= PORT_MAX - 1){
        LAT_REG[port] = logic;
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * GPIO_PORT_Read - Read the logic level of all pins in a GPIO port.
 *
 * This function reads the current logic level of all pins in a GPIO port based on the
 * provided port index and updates the logic variable.
 *
 * @param port  The index of the GPIO port.
 * @param logic Pointer to a variable to store the retrieved logic level.
 * @return      Returns the status of the operation:
 *              - E_OK if the logic level was successfully read from the port.
 *              - E_NOT_OK if an error occurred (e.g., invalid port index or NULL pointer).
 */
#if GPIO_PORT_CONFIG == ENABLE
Std_ReturnType GPIO_PORT_Read(port_index_t port, uint8 *logic){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(port <= PORT_MAX - 1 && NULL != logic){
        *logic = *LAT_REG[port];
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif

/**
 * GPIO_PORT_Toggle - Toggle the logic level of all pins in a GPIO port.
 *
 * This function toggles the current logic level of all pins in a GPIO port based on the
 * provided port index.
 *
 * @param port The index of the GPIO port.
 * @return     Returns the status of the operation:
 *             - E_OK if the logic levels were successfully toggled in the port.
 *             - E_NOT_OK if an error occurred (e.g., invalid port index).
 */
#if GPIO_PORT_CONFIG == ENABLE
Std_ReturnType GPIO_PORT_Toggle(port_index_t port){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(port <= PORT_MAX - 1){
        *LAT_REG[port] ^= PORT_MASK;
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}
#endif