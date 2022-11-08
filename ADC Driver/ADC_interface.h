 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_interface.h
 *
 * Description: interface file for the STM32 ADC driver
 *
 * Author: 
 *
 *******************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_config.h"

/*******************************************************************************
 *                         Functions Prototypes                                *
 *******************************************************************************/
void ADC_voidInit(void);
u32 ADC_u32ReadData(void);
void ADC_voidStartConversion(void);

/*******************************************************************************
 *                         Variables Extern                                    *
 *******************************************************************************/
extern volatile u16 g_adcResult;
extern u16 g_adcResultsArray[NUMBER_OF_CONVERSIONS];

#endif /* ADC_INTERFACE_H_ */
