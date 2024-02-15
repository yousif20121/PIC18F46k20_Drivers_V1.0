/* 
 * File:   INT_EXTERNAL.c
 * Author: Yousif Elraey
 *
 * Created on December 3, 2023, 5:39 PM
 */

#include "INT_EXTERNAL.h"

static void (*INT0_InterruptHandler)(void) = NULL;
static void (*INT1_InterruptHandler)(void) = NULL;
static void (*INT2_InterruptHandler)(void) = NULL;

static void (*RB4_InterruptHandler_HIGH)(void) = NULL;
static void (*RB4_InterruptHandler_LOW)(void) = NULL;
static void (*RB5_InterruptHandler_HIGH)(void) = NULL;
static void (*RB5_InterruptHandler_LOW)(void) = NULL;
static void (*RB6_InterruptHandler_HIGH)(void) = NULL;
static void (*RB6_InterruptHandler_LOW)(void) = NULL;
static void (*RB7_InterruptHandler_HIGH)(void) = NULL;
static void (*RB7_InterruptHandler_LOW)(void) = NULL;


/* Helper Functions Prototypes */
static Std_ReturnType INT_INTx_EN(const interrupt_INTx_t *int_obj);
static Std_ReturnType INT_INTx_DIS(const interrupt_INTx_t *int_obj);
static Std_ReturnType INT_INTx_PRIORITY_INIT(const interrupt_INTx_t *int_obj);
static Std_ReturnType INT_INTx_EDGE_INIT(const interrupt_INTx_t *int_obj);
static Std_ReturnType INT_INTx_PIN_INIT(const interrupt_INTx_t *int_obj);
static Std_ReturnType INT_INTx_FLAG_INIT(const interrupt_INTx_t *int_obj);

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj);


Std_ReturnType INT_INTx_Init(const interrupt_INTx_t *int_obj){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        ret = INT_INTx_DIS(int_obj);
        
        ret = INT_INTx_FLAG_INIT(int_obj);
        
        ret = INT_INTx_EDGE_INIT(int_obj);
        
        #if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE
        ret = INT_INTx_PRIORITY_INIT(int_obj);
        #endif
        
        ret = INT_INTx_PIN_INIT(int_obj);
        
        ret = INTx_SetInterruptHandler(int_obj);
        
        ret = INT_INTx_EN(int_obj);
        
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}

void INT0_ISR(void){
    
    INT_EXT_INT0_FLAG_CLEAR();
    
    /* Code */
    
    if(INT0_InterruptHandler){
        INT0_InterruptHandler();
    }
    
}

void INT1_ISR(void){
    
    INT_EXT_INT1_FLAG_CLEAR();
    
    /* Code */
    
    if(INT1_InterruptHandler){
        INT1_InterruptHandler();
    }
    
}

void INT2_ISR(void){
    
    INT_EXT_INT2_FLAG_CLEAR();
    
    /* Code */
    
    if(INT2_InterruptHandler){
        INT2_InterruptHandler();
    }
    
}

void RB4_ISR(uint8 RB4_Source){
    
    INT_EXT_RB_FLAG_CLEAR();
    
    /* Code */
    if (0 == RB4_Source){
        if(RB4_InterruptHandler_HIGH){
            RB4_InterruptHandler_HIGH();
        }
    }
    
    else if(1 == RB4_Source){
        if(RB4_InterruptHandler_LOW){
            RB4_InterruptHandler_LOW();
        }        
    }
    else{/* Do nothing */}

  
}

void RB5_ISR(uint8 RB5_Source){
    
    INT_EXT_RB_FLAG_CLEAR();
    
    /* Code */
    if (0 == RB5_Source){
        if(RB5_InterruptHandler_HIGH){
            RB5_InterruptHandler_HIGH();
        }
    }
    
    else if(1 == RB5_Source){
        if(RB5_InterruptHandler_LOW){
            RB5_InterruptHandler_LOW();
        }        
    }
    else{/* Do nothing */}

  
}

void RB6_ISR(uint8 RB6_Source){
    
    INT_EXT_RB_FLAG_CLEAR();
    
    /* Code */
    if (0 == RB6_Source){
        if(RB6_InterruptHandler_HIGH){
            RB6_InterruptHandler_HIGH();
        }
    }
    
    else if(1 == RB6_Source){
        if(RB6_InterruptHandler_LOW){
            RB6_InterruptHandler_LOW();
        }        
    }
    else{/* Do nothing */}
  
}

void RB7_ISR(uint8 RB7_Source){
    
    INT_EXT_RB_FLAG_CLEAR();
    
    /* Code */
    if (0 == RB7_Source){
        if(RB7_InterruptHandler_HIGH){
            RB7_InterruptHandler_HIGH();
        }
    }
    
    else if(1 == RB7_Source){
        if(RB7_InterruptHandler_LOW){
            RB7_InterruptHandler_LOW();
        }        
    }
    else{/* Do nothing */}
  
}


Std_ReturnType INT_INTx_Disable(const interrupt_INTx_t *int_obj){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        ret = INT_INTx_DIS(int_obj);
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
}


Std_ReturnType INT_RBx_Init(const interrupt_RBx_t *int_obj){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        INT_EXT_RB_DISABLE();
        INT_EXT_RB_FLAG_CLEAR();
        #if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE
            INT_IPEN_ENABLE();
            if(INTERRUPT_LP == (int_obj->priority)){
                INT_GIEL_ENABLE();
                INT_EXT_RB_PRIORITY_LOW();
            }
            else if(INTERRUPT_HP == (int_obj->priority)){
                INT_GIEH_ENABLE();
                INT_EXT_RB_PRIORITY_HIGH();
            }
            else{/* Do Nothing */}
            #else
                INT_GIE_ENABLE();
                INT_PEIE_ENABLE();
            #endif
            ret = GPIO_PIN_Direction_Init(&(int_obj->mcu_pin));
            switch(int_obj->mcu_pin.pin){
                case GPIO_PIN4:
                    RB4_InterruptHandler_HIGH = int_obj->INT_EXT_HANDLER_HIGH;
                    RB4_InterruptHandler_LOW = int_obj->INT_EXT_HANDLER_LOW;
                    break;
                    
                case GPIO_PIN5:
                    RB5_InterruptHandler_HIGH = int_obj->INT_EXT_HANDLER_HIGH;
                    RB5_InterruptHandler_LOW = int_obj->INT_EXT_HANDLER_LOW;
                    break;
                    
                case GPIO_PIN6:
                    RB6_InterruptHandler_HIGH = int_obj->INT_EXT_HANDLER_HIGH;
                    RB6_InterruptHandler_LOW = int_obj->INT_EXT_HANDLER_LOW;
                    break;
                    
                case GPIO_PIN7:
                    RB7_InterruptHandler_HIGH = int_obj->INT_EXT_HANDLER_HIGH;
                    RB7_InterruptHandler_LOW = int_obj->INT_EXT_HANDLER_LOW;
                    break;
                default:
                    ret = E_NOT_OK;
                    break;
            }
        INT_EXT_RB_ENABLE();
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
}


Std_ReturnType INT_RBx_Terminate(const interrupt_INTx_t *int_obj){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
}


/* Helper Functions */

/* INTx */
static Std_ReturnType INT_INTx_EN(const interrupt_INTx_t *int_obj){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        switch(int_obj->src){
            case INT_EXT_INT0:
                #if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE
                    INT_GIEH_ENABLE();
                #else
                    INT_GIE_ENABLE();
                    INT_PEIE_ENABLE();
                #endif
                INT_EXT_INT0_ENABLE();
                ret = E_OK;
                break;
            
            case INT_EXT_INT1:
                #if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE
                INT_IPEN_ENABLE();
                if(INTERRUPT_LP == (int_obj->priority)){
                    INT_GIEL_ENABLE();
                }
                else if(INTERRUPT_HP == (int_obj->priority)){
                    INT_GIEH_ENABLE();
                }
                else{/* Do Nothing */}
                #else
                    INT_GIE_ENABLE();
                    INT_PEIE_ENABLE();
                #endif
                INT_EXT_INT1_ENABLE(); 
                ret = E_OK;
                break;
            
            case INT_EXT_INT2:
                #if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE
                INT_IPEN_ENABLE();
                if(INTERRUPT_LP == (int_obj->priority)){
                    INT_GIEL_ENABLE();
                }
                else if(INTERRUPT_HP == (int_obj->priority)){
                    INT_GIEH_ENABLE();
                }
                else{/* Do Nothing */}
                #else
                    INT_GIE_ENABLE();
                    INT_PEIE_ENABLE();
                #endif
                INT_EXT_INT2_ENABLE(); 
                ret = E_OK;
                break;    
            
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}


static Std_ReturnType INT_INTx_DIS(const interrupt_INTx_t *int_obj){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        switch(int_obj->src){
            case INT_EXT_INT0: 
                INT_EXT_INT0_DISABLE(); 
                ret = E_OK;
                break;
            
            case INT_EXT_INT1: 
                INT_EXT_INT1_DISABLE(); 
                ret = E_OK;
                break;
            
            case INT_EXT_INT2: 
                INT_EXT_INT2_DISABLE(); 
                ret = E_OK;
                break;    
            
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
}

#if INT_PRIORITY_LEVELS_EN == INT_FEATURE_ENABLE
static Std_ReturnType INT_INTx_PRIORITY_INIT(const interrupt_INTx_t *int_obj){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        switch(int_obj->src){
            case INT_EXT_INT1: 
                if(INTERRUPT_LP == (int_obj->priority)){
                    INT_EXT_INT1_LP_SET();
                }
                else if(INTERRUPT_HP == (int_obj->priority)){
                    INT_EXT_INT1_HP_SET();
                }
                else{/* Do Nothing */}
                
                ret = E_OK;
                break;
            
            case INT_EXT_INT2: 
                if(INTERRUPT_LP == (int_obj->priority)){
                    INT_EXT_INT2_LP_SET();
                }
                else if(INTERRUPT_HP == (int_obj->priority)){
                    INT_EXT_INT2_HP_SET();
                }
                else{/* Do Nothing */}
                
                ret = E_OK;
                break;    
            
            default:
                ret = E_NOT_OK;
                break;
        }
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
#endif

static Std_ReturnType INT_INTx_EDGE_INIT(const interrupt_INTx_t *int_obj){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        switch(int_obj->src){
            case INT_EXT_INT0: 
                if(INT_FALLING_EDGE == (int_obj->edge)){
                    INT_EXT_INT0_FALLING_SET();
                }
                else if(INT_RISING_EDGE == (int_obj->edge)){
                    INT_EXT_INT0_RISING_SET();
                }
                else{/* Do Nothing */}
                
                ret = E_OK;
                break;
                
            case INT_EXT_INT1: 
                if(INT_FALLING_EDGE == (int_obj->edge)){
                    INT_EXT_INT1_FALLING_SET();
                }
                else if(INT_RISING_EDGE == (int_obj->edge)){
                    INT_EXT_INT1_RISING_SET();
                }
                else{/* Do Nothing */}
                
                ret = E_OK;
                break;
                
            case INT_EXT_INT2: 
                if(INT_FALLING_EDGE == (int_obj->edge)){
                    INT_EXT_INT2_FALLING_SET();
                }
                else if(INT_RISING_EDGE == (int_obj->edge)){
                    INT_EXT_INT2_RISING_SET();
                }
                else{/* Do Nothing */}
                
                ret = E_OK;
                break; 
                
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;

}


static Std_ReturnType INT_INTx_PIN_INIT(const interrupt_INTx_t *int_obj){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        ret = GPIO_PIN_Direction_Init(&(int_obj->mcu_pin));
    }
    else{
        ret = E_NOT_OK;
    }

}


static Std_ReturnType INT_INTx_FLAG_INIT(const interrupt_INTx_t *int_obj){
    
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        switch(int_obj->src){
            case INT_EXT_INT0: 
                INT_EXT_INT0_FLAG_CLEAR();
                ret = E_OK;
                break;
                
            case INT_EXT_INT1: 
                INT_EXT_INT1_FLAG_CLEAR();
                ret = E_OK;
                break;
                
            case INT_EXT_INT2: 
                INT_EXT_INT2_FLAG_CLEAR();
                ret = E_OK;
                break;
                
            default:
                ret = E_NOT_OK;
                break;
        }
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != InterruptHandler){
        INT0_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void)){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != InterruptHandler){
        INT1_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void)){

    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != InterruptHandler){
        INT2_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}

static Std_ReturnType INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj){
        
    Std_ReturnType ret = E_NOT_OK;
    
    if(NULL != int_obj){
        switch(int_obj->src){
            case INT_EXT_INT0: 
                ret = INT0_SetInterruptHandler(int_obj->INT_EXT_HANDLER);
                break;
            
            case INT_EXT_INT1: 
                ret = INT1_SetInterruptHandler(int_obj->INT_EXT_HANDLER);
                break;
            
            case INT_EXT_INT2: 
                ret = INT2_SetInterruptHandler(int_obj->INT_EXT_HANDLER);
                break;    
            
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    
    return ret;
    
}