/**
 * File:   GPIO.h
 * Author: Yousif Elraey
 *
 * Created on September 23, 2023, 8:32 PM
 */

#ifndef GPIO_H
#define	GPIO_H

/** Section #1: Includes */
#include "../COMPILER.h"
#include "../STD_TYPES.h"
#include "../STD_LIBS.h"
#include "../DEVICE_CFG.h"
#include "GPIO_CFG.h"

/** Section #2: Macros Deceleration */

#define BIT_MASK              1           // Bit mask for bit manipulation   
#define PORT_MASK          0xFF           // Port mask for port manipulation

/** Section #3: Data Types Definition  */

// Enumeration for logic levels
typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH
} logic_t;

// Enumeration for pin directions
typedef enum {
    GPIO_OUTPUT = 0,
    GPIO_INPUT
} direction_t;

// Enumeration for port indices
typedef enum {
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE
} port_index_t;

// Enumeration for pin indices
typedef enum {
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
} pin_index_t;

// Structure for pin configuration
typedef struct {
    uint8 port         : 3;         // 3-bit field for specifying the port
    uint8 pin          : 3;         // 3-bit field for specifying the pin
    uint8 direction    : 1;         // 1-bit field for specifying the pin direction (INPUT or OUTPUT)
    uint8 logic        : 1;         // 1-bit field for specifying the logic level (LOW or HIGH)
} pin_config_t;


/** Section #4: Macros Functions Deceleration */

/** Memory Access */

// Macro for safely accessing hardware registers via memory-mapped addresses 
#define HWREG(_X)                   (*((volatile uint8 *)(_X))) 


/* Bit Manipulation */

// Set a specific bit in a register to '1'
#define SET_BIT(REG, BIT_POSN)      (REG |=  (BIT_MASK << BIT_POSN))

// Clear a specific bit in a register to '0'
#define CLEAR_BIT(REG, BIT_POSN)    (REG &= ~(BIT_MASK << BIT_POSN))

// Toggle a specific bit in a register
#define TOGGLE_BIT(REG, BIT_POSN)   (REG ^=  (BIT_MASK << BIT_POSN))

// Read the state of a specific bit in a register
#define READ_BIT(REG, BIT_POSN)     ((REG >> BIT_POSN) & BIT_MASK)



/** Section #5: Functions Deceleration */

/** PIN Control Functions */
Std_ReturnType GPIO_PIN_Direction_Init(const pin_config_t *_pin_config);
Std_ReturnType GPIO_PIN_Init(const pin_config_t *_pin_config);
Std_ReturnType GPIO_PIN_Get_Direction(const pin_config_t *_pin_config, direction_t *direction_status);
Std_ReturnType GPIO_PIN_Write(const pin_config_t *_pin_config, logic_t logic);
Std_ReturnType GPIO_PIN_Read(const pin_config_t *_pin_config, logic_t *logic);
Std_ReturnType GPIO_PIN_Toggle(const pin_config_t *_pin_config);

/** PORT Control Functions */
Std_ReturnType GPIO_PORT_Direction_Init(port_index_t port, uint8 direction);
Std_ReturnType GPIO_PORT_Get_Direction(port_index_t port, uint8 *direction_status);
Std_ReturnType GPIO_PORT_Write(port_index_t port, uint8 logic);
Std_ReturnType GPIO_PORT_Read(port_index_t port, uint8 *logic);
Std_ReturnType GPIO_PORT_Toggle(port_index_t port);


#endif	/* GPIO_H */

