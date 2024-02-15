/* 
 * File:   CHAR_LCD_CFG.h
 * Author: Yousif Elraey
 *
 * Created on October 21, 2023, 5:22 PM
 */

#ifndef CHAR_LCD_CFG_H
#define	CHAR_LCD_CFG_H

/** CONFIG STATUS: ENABLE & DISABLE */
#define ENABLE                                  0x01
#define DISABLE                                 0x00

/** POSTIONS: NIBBLE */
#define NIBBLE                                  4

/** CONFIG BUTTONS: ECU_BUTTON_CONFIG */
#define ECU_LCD_4BIT_CONFIG                     ENABLE
#define ECU_LCD_4BIT_ALL_CONFIG                 ENABLE

#define ECU_LCD_8BIT_CONFIG                     ENABLE
#define ECU_LCD_8BIT_ALL_CONFIG                 ENABLE

#endif	/* CHAR_LCD_CFG_H */