 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_config.h
 *
 * Description: Config file for the STM32 ADC driver
 *
 * Author: 
 *
 *******************************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* Choose number of active channels
 * Valid inputs are 1-16            */

#define NUMBER_OF_CONVERSIONS 3

/* Choose ADC Mode
 * 0- Single Conversion
 * 1- Continuous Conversion  */

#define SINGLE_CONV      0
#define CONTINUOUS_CONV  1

#define ADC_MODE CONTINUOUS_CONV

/* Choose Single/Multiple channel mode
 * 0- Single Mode
 * 1- Multiple Mode                    */

#define SINGLE_CHANNEL_MODE   0
#define MULTIPLE_CHANNEL_MODE 1

#define ADC_SINGLE_MULTIPLE    MULTIPLE_CHANNEL_MODE


/*NEW*/

#define ADC_SQ1_VAL			0
#define ADC_SQ2_VAL 		5
#define ADC_SQ3_VAL			6
#define ADC_SQ4_VAL			0
#define ADC_SQ5_VAL			3
#define ADC_SQ6_VAL			10
#define ADC_SQ7_VAL			7
#define ADC_SQ8_VAL			8
#define ADC_SQ9_VAL			12
#define ADC_SQ10_VAL		11
#define ADC_SQ11_VAL		6
#define ADC_SQ12_VAL		5
#define ADC_SQ13_VAL		4
#define ADC_SQ14_VAL		9
#define ADC_SQ15_VAL		14
#define ADC_SQ16_VAL		0


/*
	sample time individually for each channel

	Options:
		1. ADC_1_5_CYCLES
		2. ADC_7_5_CYCLES
		3. ADC_13_5_CYCLES
		4. ADC_28_5_CYCLES
		5. ADC_41_5_CYCLES
		6. ADC_55_5_CYCLES
		7. ADC_71_5_CYCLES
		8. ADC_239_5_CYCLES

*/

#define ADC_SMP0_SELECTION			ADC_239_5_CYCLES
#define ADC_SMP1_SELECTION			ADC_239_5_CYCLES
#define ADC_SMP2_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP3_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP4_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP5_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP6_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP7_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP8_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP9_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP10_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP11_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP12_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP13_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP14_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP15_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP16_SELECTION			ADC_1_5_CYCLES
#define ADC_SMP17_SELECTION			ADC_1.5_CYCLES

/*
	Options
	
	1. ADC1_CR2_EXTSEL_TIMER1CC1	
	2. ADC1_CR2_EXTSEL_TIMER1CC2	
	3. ADC1_CR2_EXTSEL_TIMER1CC3	
	4. ADC1_CR2_EXTSEL_TIMER2CC2	
	5. ADC1_CR2_EXTSEL_TIMER3TRGO	
	6. ADC1_CR2_EXTSEL_TIMER4CC4	
	7. ADC1_CR2_EXTSEL_EXTLINE11	
	8. ADC1_CR2_EXTSEL_SWSTART		
		
	
*/

#define ADC1_TRIG_MODE		ADC1_CR2_EXTSEL_TIMER1CC1


/*
	Options:
	1.DMA_MSIZE_PSIZE_8BIT	
	2.DMA_MSIZE_PSIZE_16BIT	
	3.DMA_MSIZE_PSIZE_32BIT	
*/
#define  DMA_MSIZE_SELECTION	DMA_MSIZE_PSIZE_16BIT	
#define  DMA_PSIZE_SELECTION	DMA_MSIZE_PSIZE_16BIT



#endif /* ADC_CONFIG_H_ */
