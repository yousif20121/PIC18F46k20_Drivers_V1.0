/* 
 * File:   INT_GEN_CFG.h
 * Author: Yousif Elraey
 *
 * Created on December 3, 2023, 6:12 PM
 */

#ifndef INT_GEN_CFG_H
#define	INT_GEN_CFG_H

/* To control either the INT feature(s) in microcontroller is enabled or not */
#define INT_FEATURE_ENABLE               1
#define INT_FEATURE_DISABLE              0

#define INT_PRIORITY_LEVELS_EN           INT_FEATURE_ENABLE
#define INT_EXT_INTx_FEATURE_EN          INT_FEATURE_ENABLE
#define INT_OC_FEATURE_EN                INT_FEATURE_ENABLE

#define ADC_INTERRUPT_FEATURE_ENABLE     INT_FEATURE_ENABLE


#endif	/* INT_GEN_CFG_H */

