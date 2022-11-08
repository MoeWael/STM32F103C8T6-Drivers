 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_program.c
 *
 * Description: Source file for the STM32 ADC driver
 *
 * Author: 
 *
 *******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


#define ADC1_EN 	9
#define ADC1_2_GIN 18
/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

volatile u16 g_adcResult = 0;

#if ADC_SINGLE_MULTIPLE == MULTIPLE_CHANNEL_MODE
u16 g_adcResultsArray[NUMBER_OF_CONVERSIONS] = {0};
#endif
/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void ADC_voidInit(void){


#if ADC_SINGLE_MULTIPLE == SINGLE_CHANNEL_MODE

	//SEQ1
	ADC1->SQR3  |= (ADC_SQ1_VAL << ADC_SQ1);
	//Set sampling rate to (239.5 cycles)
	ADC1_SMPR2 |= (ADC_SMP0_SELECTION << ADC_SMP0);
	/* Enable End of conversion interrupt */
	SET_BIT(ADC1_CR1, ADC_CR1_EOCIE);
#endif


#if ADC_SINGLE_MULTIPLE == MULTIPLE_CHANNEL_MODE

	//SEQ1
	ADC1_SQR3  |= (ADC_SQ1_VAL << ADC_SQ1);
	ADC1_SMPR2 |= (ADC_SMP1_SELECTION << ADC_SMP1);
	//SEQ2
	ADC1_SQR3  |= (ADC_SQ2_VAL << ADC_SQ2);
	ADC1_SMPR2 |= (ADC_SMP2_SELECTION << ADC_SMP2);
	//SEQ3
	ADC1_SQR3  |= (ADC_SQ2_VAL << ADC_SQ3);
	ADC1_SMPR2 |= (ADC_SMP3_SELECTION << ADC_SMP3);
	//SEQ4
	ADC1_SQR3  |= (ADC_SQ4_VAL << ADC_SQ4);
	ADC1_SMPR2 |= (ADC_SMP4_SELECTION << ADC_SMP4);
	//SEQ5
	ADC1_SQR3  |= (ADC_SQ5_VAL << ADC_SQ5);
	ADC1_SMPR2 |= (ADC_SMP5_SELECTION << ADC_SMP5);
	//SEQ6
	ADC1_SQR3  |= (ADC_SQ6_VAL << ADC_SQ6);
	ADC1_SMPR2 |= (ADC_SMP6_SELECTION << ADC_SMP6);
	//SEQ7
	ADC1_SQR2  |= (ADC_SQ7_VAL << ADC_SQ7);
	ADC1_SMPR2 |= (ADC_SMP7_SELECTION << ADC_SMP7);
	//SEQ8
	ADC1_SQR2  |= (ADC_SQ8_VAL << ADC_SQ8);
	ADC1_SMPR2 |= (ADC_SMP8_SELECTION << ADC_SMP8);
	//SEQ9
	ADC1_SQR2  |= (ADC_SQ9_VAL << ADC_SQ9);
	ADC1_SMPR2 |= (ADC_SMP9_SELECTION << ADC_SMP9);
	//SEQ10
	ADC1_SQR2  |= (ADC_SQ10_VAL << ADC_SQ10);
	ADC2_SMPR1 |= (ADC_SMP10_SELECTION << ADC_SMP10);
	//SEQ11
	ADC1_SQR2  |= (ADC_SQ11_VAL << ADC_SQ11);
	ADC2_SMPR1 |= (ADC_SMP11_SELECTION << ADC_SMP11);
	//SEQ12
	ADC1_SQR2  |= (ADC_SQ12_VAL << ADC_SQ12);
	ADC2_SMPR1 |= (ADC_SMP12_SELECTION << ADC_SMP12);
	//SEQ13
	ADC1_SQR1  |= (ADC_SQ13_VAL << ADC_SQ13);
	ADC2_SMPR1 |= (ADC_SMP13_SELECTION << ADC_SMP13);
	//SEQ14
	ADC1_SQR1  |= (ADC_SQ14_VAL << ADC_SQ14);
	ADC2_SMPR1 |= (ADC_SMP14_SELECTION << ADC_SMP14);
	//SEQ15
	ADC1_SQR1  |= (ADC_SQ15_VAL << ADC_SQ15);
	ADC2_SMPR1 |= (ADC_SMP15_SELECTION << ADC_SMP15);
	//SEQ16
	ADC1_SQR1  |= (ADC_SQ16_VAL << ADC_SQ16);
	ADC2_SMPR1 |= (ADC_SMP16_SELECTION << ADC_SMP16);

	/* Set ADC to Scan Mode (Multiple Channels) */
	SET_BIT(ADC1_CR1, ADC_CR1_SCAN);

	/* Enable DMA Mode */
	SET_BIT(ADC1_CR2, ADC_CR2_DMA);

	/* Set up DMA
	 * Put ADC_DR address (where data is taken from) into DMA_CPAR
	 * Put g_adcResultsArray address (where data will be written to) into DMA_CMAR  */
	
	/****VIP****/
	/*CLear DMA1_CCR1_EN flag */
	CLR_BIT(DMA1_CCR1, DMA1_CCR1_EN);
	DMA1_CPAR1 = (u32)(&ADC1_DR);

	DMA1_CMAR1 = (u32)g_adcResultsArray;

	/* Set DMA_CNDTR to number of transfers */
	DMA1_CNDTR1 = NUMBER_OF_CONVERSIONS;

	/* Enable Memory Increment mode */
	SET_BIT(DMA1_CCR1, DMA1_CCR1_MINC);

	/* Enable Circular mode */
	SET_BIT(DMA1_CCR1, DMA1_CCR1_CIRC);

	/* Set MSIZE and PSIZE to 16 bits */
	DMA1_CCR1 |= (DMA_PSIZE_SELECTION << DMA1_CCR1_PSIZE);
	DMA1_CCR1 |= (DMA_MSIZE_SELECTION << DMA1_CCR1_MSIZE);

	/* Enable DMA Channel */
	SET_BIT(DMA1_CCR1, DMA1_CCR1_EN);
#endif

	 /* Set L bits to number of conversions */
	ADC1_SQR1 |= ((NUMBER_OF_CONVERSIONS-1) << ADC_SQR1_L);

	/* Enable ADC and start conversion */
	SET_BIT(ADC1_CR2, ADC_CR2_ADON);

#if ADC_MODE == CONTINUOUS_CONV
	/* Set ADC to continuous mode */
	SET_BIT(ADC1_CR2, ADC_CR2_CONT);
#endif
	SET_BIT(ADC1_CR2, ADC_CR2_ADON);
	/* Calibrate the ADC and wait till it's done */
	SET_BIT(ADC1_CR2, ADC_CR2_CAL);

}

u32 ADC_u32ReadData(void){
	while(GET_BIT(ADC1_SR, ADC_SR_EOC) == LOW);
	return ADC1_DR;
}

void ADC1_2_IRQHandler(void){
	if(GET_BIT(ADC1_SR, ADC_SR_EOC) == HIGH){
		g_adcResult = ADC1_DR;
	}
}

void ADC_voidStartConversion(void)
{
	/*Enable External Trigger in ADC_CR2 Register*/
	SET_BIT(ADC1_CR2, ADC_CR2_EXTTRIG);
	
	/*Select Trigger mode in ADC_CR2_EXTSEL bits*/
	ADC1_CR2 |= ADC1_TRIG_MODE << ADC_CR2_EXTSEL;
	
	/*Start conversion using software start have to set ADC_CR2_SWSTART*/
	SET_BIT(ADC1_CR2, ADC_CR2_SWSTART);
}
