/* 
 * File:   ADC.h
 * Author: Yousif Elraey
 *
 * Created on December 17, 2023, 9:23 PM
 */

#include <pic18f46k20.h>

#include "ADC.h"

static void (*ADC_InterruptHandler)(void) = NULL;

/* Helper Functions Prototypes */
static inline void adc_input_channel_port_config(adc_channel_select_t channel);
static inline void select_result_format(const adc_config_t *_adc);
static inline void config_voltage_ref(const adc_config_t *_adc);


Std_ReturnType ADC_INIT(const adc_config_t *_adc){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _adc){
        ADC_CONVERTER_DISABLE();
        
        ADCON2bits.ACQT = _adc->acq_time;
        
        ADCON2bits.ADCS = _adc->conv_clk;
        
        ADCON0bits.CHS = _adc->adc_channel;
        adc_input_channel_port_config(_adc->adc_channel);
        
        #if ADC_INTERRUPT_FEATURE_ENABLE == INT_FEATURE_ENABLE
        ADC_CONVERTER_ENABLE();
        ADC_INT_FLAG_CLEAR();
        #if INT_PRIORITY_LEVELS_EN == INTERRUPT_FEATURE_ENABLE
        if(INTERRUPT_HIGH_PRIORITY == _adc->priority){ADC_HighPriority_Set();}
        else if(INTERRUPT_LOW_PRIORITY == _adc->priority){ADC_LowPriority_Set();}
        else{ /* Do nothing */ }
        #endif
        ADC_InterruptHandler = _adc->adc_InterruptHandler;
        #endif
        
        select_result_format(_adc);
        
        config_voltage_ref(_adc);
        
        ADC_CONVERTER_ENABLE();
        
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}

Std_ReturnType ADC_Terminate(const adc_config_t *_adc){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _adc){
        ADC_CONVERTER_DISABLE();
        
        //
        
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}

Std_ReturnType ADC_CHANNEL_Select(const adc_config_t *_adc, adc_channel_select_t channel){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != _adc){
        ADCON0bits.CHS = channel;
        adc_input_channel_port_config(channel);
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
  
}

Std_ReturnType ADC_ConversionStart(const adc_config_t *adc){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != adc){
        ADC_START_CONVERSION();
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}

Std_ReturnType ADC_ConversionStatus(const adc_config_t *adc, uint8 *conversion_status){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if((NULL != adc) && (NULL != conversion_status)){
        *conversion_status = (uint8)(!(ADCON0bits.GO_nDONE));
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
  
}

Std_ReturnType ADC_ConversionGetResult(const adc_config_t *adc, adc_result_t *conversion_result){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if((NULL != adc) && (NULL != conversion_result)){
        if(ADC_RESULT_RIGHT == (adc->result_format)){
            *conversion_result = (adc_result_t)((ADRESH) << 8 + ADRESL);
        }
        else if(ADC_RESULT_LEFT == (adc->result_format)){
            *conversion_result = (adc_result_t)(((ADRESH) << 8 + ADRESL) >> 6);
        }
        else{
            ret = E_NOT_OK;
        }
        
        ret = E_OK;
        
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
  
}

Std_ReturnType ADC_ConversionGet_BLOCKING(const adc_config_t *adc, adc_channel_select_t channel, adc_result_t *conversion_result){
    
    Std_ReturnType ret = E_NOT_OK;
    
    
    if((NULL != adc) && (NULL != conversion_result)){
        ret = ADC_CHANNEL_Select(adc, channel);
        
        ret = ADC_ConversionStart(adc);
        
        while(ADCON0bits.GO_nDONE);
        ret = ADC_ConversionGetResult(adc, conversion_result);
        
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }

    
    return ret;
}


/* Helper Functions */
static inline void adc_input_channel_port_config(adc_channel_select_t channel){
    switch(channel){
        case ADC_CH_AN0:  SET_BIT(TRISA, _TRISA_RA0_POSN);    break;
        case ADC_CH_AN1:  SET_BIT(TRISA, _TRISA_RA1_POSN);    break;
        case ADC_CH_AN2:  SET_BIT(TRISA, _TRISA_RA2_POSN);    break;
        case ADC_CH_AN3:  SET_BIT(TRISA, _TRISA_RA3_POSN);    break;
        case ADC_CH_AN4:  SET_BIT(TRISA, _TRISA_RA5_POSN);    break;
        case ADC_CH_AN5:  SET_BIT(TRISE, _TRISE_RE0_POSN);    break;
        case ADC_CH_AN6:  SET_BIT(TRISE, _TRISE_RE1_POSN);    break;
        case ADC_CH_AN7:  SET_BIT(TRISE, _TRISE_RE2_POSN);    break;
        case ADC_CH_AN8:  SET_BIT(TRISB, _TRISB_RB2_POSN);    break;
        case ADC_CH_AN9:  SET_BIT(TRISB, _TRISB_RB3_POSN);    break;
        case ADC_CH_AN10: SET_BIT(TRISB, _TRISB_RB1_POSN);    break;
        case ADC_CH_AN11: SET_BIT(TRISB, _TRISB_RB4_POSN);    break;
        case ADC_CH_AN12: SET_BIT(TRISB, _TRISB_RB0_POSN);    break;
    }
}

static inline void select_result_format(const adc_config_t *_adc){
    if(ADC_RESULT_RIGHT == _adc->result_format){
        ADC_RES_RIGHT_FORMAT();
    }
    else if(ADC_RESULT_LEFT == _adc->result_format){
        ADC_RES_LEFT_FORMAT();
    }
    else{
        ADC_RES_RIGHT_FORMAT();
    }
}

static inline void config_voltage_ref(const adc_config_t *_adc){
    if(ADC_VOLTAGE_REFERANCE_ENABLED == _adc->voltage_ref){
        ADC_VOLTAGE_REF_ENABLE();
    }
    else if(ADC_VOLTAGE_REFERANCE_DISABLED == _adc->voltage_ref){
        ADC_VOLTAGE_REF_DISABLE();
    }
    else{
        ADC_VOLTAGE_REF_DISABLE();
    }
}