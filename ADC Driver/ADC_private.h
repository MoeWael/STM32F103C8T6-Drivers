 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_private.h
 *
 * Description: Private file for the STM32 ADC driver
 *
 * Author: 
 *
 *******************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "STD_TYPES.h"

/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/

#define ADC1_BASE_ADDRESS 0x40012400
#define ADC2_BASE_ADDRESS 0x40012800

#define ADC1_SR      *(volatile u32*)(ADC1_BASE_ADDRESS + 0x00)
#define ADC1_CR1     *(volatile u32*)(ADC1_BASE_ADDRESS + 0x04)
#define ADC1_CR2     *(volatile u32*)(ADC1_BASE_ADDRESS + 0x08)
#define ADC1_SMPR1   *(volatile u32*)(ADC1_BASE_ADDRESS + 0x0C)
#define ADC1_SMPR2   *(volatile u32*)(ADC1_BASE_ADDRESS + 0x10)
#define ADC1_JOFR1   *(volatile u32*)(ADC1_BASE_ADDRESS + 0x14)
#define ADC1_JOFR2   *(volatile u32*)(ADC1_BASE_ADDRESS + 0x18)
#define ADC1_JOFR3   *(volatile u32*)(ADC1_BASE_ADDRESS + 0x1C)
#define ADC1_JOFR4   *(volatile u32*)(ADC1_BASE_ADDRESS + 0x20)
#define ADC1_HTR     *(volatile u32*)(ADC1_BASE_ADDRESS + 0x24)
#define ADC1_LTR     *(volatile u32*)(ADC1_BASE_ADDRESS + 0x28)
#define ADC1_SQR1    *(volatile u32*)(ADC1_BASE_ADDRESS + 0x2C)
#define ADC1_SQR2    *(volatile u32*)(ADC1_BASE_ADDRESS + 0x30)
#define ADC1_SQR3    *(volatile u32*)(ADC1_BASE_ADDRESS + 0x34)
#define ADC1_JSQR    *(volatile u32*)(ADC1_BASE_ADDRESS + 0x38)
#define ADC1_JDR1    *(volatile u32*)(ADC1_BASE_ADDRESS + 0x3C)
#define ADC1_JDR2    *(volatile u32*)(ADC1_BASE_ADDRESS + 0x40)
#define ADC1_JDR3    *(volatile u32*)(ADC1_BASE_ADDRESS + 0x44)
#define ADC1_JDR4    *(volatile u32*)(ADC1_BASE_ADDRESS + 0x48)
#define ADC1_DR      *(volatile u32*)(ADC1_BASE_ADDRESS + 0x4C)

#define ADC2_SR      *(volatile u32*)(ADC2_BASE_ADDRESS + 0x00)
#define ADC2_CR1     *(volatile u32*)(ADC2_BASE_ADDRESS + 0x04)
#define ADC2_CR2     *(volatile u32*)(ADC2_BASE_ADDRESS + 0x08)
#define ADC2_SMPR1   *(volatile u32*)(ADC2_BASE_ADDRESS + 0x0C)
#define ADC2_SMPR2   *(volatile u32*)(ADC2_BASE_ADDRESS + 0x10)
#define ADC2_JOFR1   *(volatile u32*)(ADC2_BASE_ADDRESS + 0x14)
#define ADC2_JOFR2   *(volatile u32*)(ADC2_BASE_ADDRESS + 0x18)
#define ADC2_JOFR3   *(volatile u32*)(ADC2_BASE_ADDRESS + 0x1C)
#define ADC2_JOFR4   *(volatile u32*)(ADC2_BASE_ADDRESS + 0x20)
#define ADC2_HTR     *(volatile u32*)(ADC2_BASE_ADDRESS + 0x24)
#define ADC2_LTR     *(volatile u32*)(ADC2_BASE_ADDRESS + 0x28)
#define ADC2_SQR1    *(volatile u32*)(ADC2_BASE_ADDRESS + 0x2C)
#define ADC2_SQR2    *(volatile u32*)(ADC2_BASE_ADDRESS + 0x30)
#define ADC2_SQR3    *(volatile u32*)(ADC2_BASE_ADDRESS + 0x34)
#define ADC2_JSQR    *(volatile u32*)(ADC2_BASE_ADDRESS + 0x38)
#define ADC2_JDR1    *(volatile u32*)(ADC2_BASE_ADDRESS + 0x3C)
#define ADC2_JDR2    *(volatile u32*)(ADC2_BASE_ADDRESS + 0x40)
#define ADC2_JDR3    *(volatile u32*)(ADC2_BASE_ADDRESS + 0x44)
#define ADC2_JDR4    *(volatile u32*)(ADC2_BASE_ADDRESS + 0x48)
#define ADC2_DR      *(volatile u32*)(ADC2_BASE_ADDRESS + 0x4C)

/*******************************************************************************
 *                           Pins Definitions                                  *
 *******************************************************************************/

#define ADC_CR1_EOCIE 5
#define ADC_SQR1_L    20
#define ADC_CR2_ADON  0
#define ADC_CR2_CONT  1
#define ADC_CR2_SWSTART 22
#define ADC_CR2_EXTTRIG 20
#define ADC_CR2_EXTSEL  17
#define ADC_CR2_CAL   2
#define ADC_SR_EOC    1
#define ADC_CR1_SCAN  8
#define ADC_CR2_DMA   8
#define ADC_SR_EOC    1
/*******************************************************************************
 *                       Sequence Definitions                                  *
 *******************************************************************************/

#define ADC_SQR1_IN_ORDER 540109
#define ADC_SQR2_IN_ORDER 414524679
#define ADC_SQR3_IN_ORDER 206703681

/*******************************************************************************
 *                     Temporary DMA Registers Definitions                     *
 *******************************************************************************/
#define DMA1_BASE_ADDRESS 0x40020000
#define DMA2_BASE_ADDRESS 0x40020400

#define DMA1_CHANNEL1_BASE_ADDRESE	DMA1_BASE_ADDRESS+0X008

#define DMA1_CCR1   *(volatile u32*)(DMA1_BASE_ADDRESS + 0x008)
#define DMA1_CNDTR1 *(volatile u32*)(DMA1_BASE_ADDRESS + 0x00C)
#define DMA1_CPAR1  *(volatile u32*)(DMA1_BASE_ADDRESS + 0x010)
#define DMA1_CMAR1  *(volatile u32*)(DMA1_BASE_ADDRESS + 0x014)

/*******************************************************************************
 *                     Temporary DMA Pins Definitions                          *
 *******************************************************************************/
#define DMA1_CCR1_EN    0
#define DMA1_CCR1_CIRC  5
#define DMA1_CCR1_MINC  7
#define DMA1_CCR1_PSIZE 8
#define DMA1_CCR1_MSIZE 10



/*New*/


/*******************************************************************************/
/***********************   BITS_OF_ADC_SMPR1_REGISTER  **************************/
/*******************************************************************************/
#define ADC_SMP10			0
#define ADC_SMP11			3
#define ADC_SMP12			6
#define ADC_SMP13			9
#define ADC_SMP14			12
#define ADC_SMP15			15
#define ADC_SMP16			18
#define ADC_SMP17			21


/*******************************************************************************/
/***********************   BITS_OF_ADC_SMPR2_REGISTER  **************************/
/*******************************************************************************/
#define ADC_SMP0			0
#define ADC_SMP1			3
#define ADC_SMP2			6
#define ADC_SMP3			9
#define ADC_SMP4			12
#define ADC_SMP5			15
#define ADC_SMP6			18
#define ADC_SMP7			21
#define ADC_SMP8			24
#define ADC_SMP9			27


/*******************************************************************************/
/***********************   BITS_OF_ADC_SQR3_REGISTER  **************************/
/*******************************************************************************/
#define ADC_SQR1_L			20
#define ADC_SQ1				0
#define ADC_SQ2		 		5
#define ADC_SQ3				10
#define ADC_SQ4				15
#define ADC_SQ5				20
#define ADC_SQ6				25


/*******************************************************************************/
/***********************   BITS_OF_ADC_SQR2_REGISTER  **************************/
/*******************************************************************************/
#define ADC_SQ7				0
#define ADC_SQ8				5
#define ADC_SQ9				10
#define ADC_SQ10			15
#define ADC_SQ11			20
#define ADC_SQ12			25


/*******************************************************************************/
/***********************   BITS_OF_ADC_SQR1_REGISTER  **************************/
/*******************************************************************************/
#define ADC_SQ13 			0
#define ADC_SQ14 			5
#define ADC_SQ15 			10
#define ADC_SQ16 			15


/*******************************************************************************/
/***********************   Options of congifugration  **************************/
/*******************************************************************************/

/*ADC sample time register 1 (ADC_SMPR1,2)*/
#define ADC_1_5_CYCLES		0
#define ADC_7_5_CYCLES		1
#define ADC_13_5_CYCLES		2
#define ADC_28_5_CYCLES		3
#define ADC_41_5_CYCLES		4
#define ADC_55_5_CYCLES		5
#define ADC_71_5_CYCLES		6
#define ADC_239_5_CYCLES	7


/*Modes of conversion*/
#define ADC1_CR2_EXTSEL_TIMER1CC1		0		
#define ADC1_CR2_EXTSEL_TIMER1CC2		1		
#define ADC1_CR2_EXTSEL_TIMER1CC3		2
#define ADC1_CR2_EXTSEL_TIMER2CC2		3
#define ADC1_CR2_EXTSEL_TIMER3TRGO		4
#define ADC1_CR2_EXTSEL_TIMER4CC4		5
#define ADC1_CR2_EXTSEL_EXTLINE11		6
#define ADC1_CR2_EXTSEL_SWSTART			7


/*Memory size & Peripheral size*/
#define	DMA_MSIZE_PSIZE_8BIT	0
#define	DMA_MSIZE_PSIZE_16BIT	1
#define	DMA_MSIZE_PSIZE_32BIT	2

#define LOW		0
#define HIGH	1

#endif /* ADC_PRIVATE_H_ */
