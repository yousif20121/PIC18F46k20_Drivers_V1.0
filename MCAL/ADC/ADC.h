/* 
 * File:   ADC.h
 * Author: Yousif Elraey
 *
 * Created on December 17, 2023, 9:23 PM
 */

#ifndef ADC_H
#define	ADC_H

/** Section #1: Includes */
#include "../COMPILER.h"
#include "../STD_TYPES.h"
#include "../GPIO/GPIO.h"
#include "../Interrupt/INT_CONFIG.h"
#include "../Interrupt/INT_INTERNAL.h"
#include "ADC_CFG.h"

/** Section #2: Macros Deceleration */
#define ADC_AN0_ANALOG_FUNCTIONALITY     0x0E
#define ADC_AN1_ANALOG_FUNCTIONALITY     0x0D
#define ADC_AN2_ANALOG_FUNCTIONALITY     0x0C
#define ADC_AN3_ANALOG_FUNCTIONALITY     0x0B
#define ADC_AN4_ANALOG_FUNCTIONALITY     0x0A
#define ADC_AN5_ANALOG_FUNCTIONALITY     0x09
#define ADC_AN6_ANALOG_FUNCTIONALITY     0x08
#define ADC_AN7_ANALOG_FUNCTIONALITY     0x07
#define ADC_AN8_ANALOG_FUNCTIONALITY     0x06
#define ADC_AN9_ANALOG_FUNCTIONALITY     0x05
#define ADC_AN10_ANALOG_FUNCTIONALITY    0x04
#define ADC_AN11_ANALOG_FUNCTIONALITY    0x03
#define ADC_AN12_ANALOG_FUNCTIONALITY    0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY     0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY    0x0F

#define ADC_RESULT_RIGHT                 0x01U
#define ADC_RESULT_LEFT                  0x00U

#define ADC_VOLTAGE_REFERANCE_ENABLED    0x01U
#define ADC_VOLTAGE_REFERANCE_DISABLED   0x00U

#define ADC_CONVERSION_COMPLETED         1
#define ADC_CONVERSION_INPROGRESS        0



/** Section #3: Data Types Definition  */
typedef enum {
    ADC_CH_AN0 = 0,
    ADC_CH_AN1,
    ADC_CH_AN2,
    ADC_CH_AN3,
    ADC_CH_AN4,
    ADC_CH_AN5,
    ADC_CH_AN6,
    ADC_CH_AN7,
    ADC_CH_AN8,
    ADC_CH_AN9,
    ADC_CH_AN10,
    ADC_CH_AN11,
    ADC_CH_AN12
} adc_channel_select_t;

typedef enum{
    ADC_0_TAD = 0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD
} adc_acq_time_t;

typedef enum{
    ADC_CONVERSION_FOSC_DIV_2 = 0,
    ADC_CONVERSION_FOSC_DIV_8,
    ADC_CONVERSION_FOSC_DIV_32,
    ADC_CONVERSION_FOSC_DIV_FRC,
    ADC_CONVERSION_FOSC_DIV_4,
    ADC_CONVERSION_FOSC_DIV_16,
    ADC_CONVERSION_FOSC_DIV_64,
} adc_conv_clk_t;

typedef struct{
    #if ADC_INTERRUPT_FEATURE_ENABLE == INT_FEATURE_ENABLE
    void (*adc_InterruptHandler)(void);
    interrupt_priority_cfg priority;
    #endif
    adc_acq_time_t acq_time;
    adc_conv_clk_t conv_clk;
    adc_channel_select_t adc_channel;
    uint8 voltage_ref       : 1;
    uint8 result_format     : 1;
    uint8 adc_reserved      : 6;
} adc_config_t;

typedef uint16 adc_result_t;

/** Section #4: Macros Functions Deceleration */
#define ADC_CONVERSION_STATUS()         (ADCON0bits.GO_nDONE)
#define ADC_START_CONVERSION()          (ADCON0bits.GODONE = 1)

#define ADC_CONVERTER_ENABLE()          (ADCON0bits.ADON = 1)
#define ADC_CONVERTER_DISABLE()         (ADCON0bits.ADON = 0)

#define ADC_VOLTAGE_REF_ENABLE()        do{ADCON1bits.VCFG1 = 1;\
                                        ADCON1bits.VCFG0 = 1;\
                                        }while(0)
#define ADC_VOLTAGE_REF_DISABLE()       do{ADCON1bits.VCFG1 = 0;\
                                            ADCON1bits.VCFG0 = 0;\
                                        }while(0)

//#define ADC_AN_DG_PORT_CFG(_CONFIG)     (ADCON1bits.PCFG = _CONFIG)
#define ADC_RES_RIGHT_FORMAT()          (ADCON2bits.ADFM = 1)
#define ADC_RES_LEFT_FORMAT()          (ADCON2bits.ADFM = 0)


/** Section #5: Functions Deceleration */
Std_ReturnType ADC_INIT(const adc_config_t *_adc);
Std_ReturnType ADC_Terminate(const adc_config_t *_adc);
Std_ReturnType ADC_CHANNEL_Select(const adc_config_t *_adc, adc_channel_select_t channel);
Std_ReturnType ADC_ConversionStart(const adc_config_t *_adc);
Std_ReturnType ADC_ConversionStatus(const adc_config_t *_adcc, uint8 *conversion_status);
Std_ReturnType ADC_ConversionGetResult(const adc_config_t *_adc, adc_result_t *conversion_result);
Std_ReturnType ADC_ConversionGet_BLOCKING(const adc_config_t *_adc, adc_channel_select_t channel, adc_result_t *conversion_result);

#endif	/* ADC_H */

