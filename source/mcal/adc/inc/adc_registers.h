/*
 * adc_registers.h
 *
 * Created: 7/21/2025 6:12:34 PM
 *  Author: mo7am
 */ 


#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

#include "std_types.h"

#define ADC_ADMUX_REG    (*(volatile u8*)(0x27))
#define ADC_ADCSRA_REG   (*(volatile u8*)(0x26))
#define ADC_ADCL_REG     (*(volatile u8*)(0x24))
#define ADC_ADCH_REG     (*(volatile u8*)(0x25))


#define ADC_ENABLE_BIT_NO	7
#define ADC_VREF_VCC			    (1<<6)
#define ADC_VREF_2_56				(3<<6)

#define ADC_START_CONV_BIT_NO		6
#define ADC_COMP_INT_FLAG_BIT_NO	4

#define ADC_CLK_PRESCALER_128		(7<<0)			

#endif /* ADC_REGISTERS_H_ */