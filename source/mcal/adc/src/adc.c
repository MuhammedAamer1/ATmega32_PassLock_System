/*
 * adc.c
 *
 * Created: 7/21/2025 6:05:28 PM
 *  Author: mo7am
 */ 
#include "adc_registers.h"
#include "adc_types.h"
#include "adc.h"
#include "bit_math.h"

void adc_init(void)
{
	//Enable ADC
	SET_BIT(ADC_ADCSRA_REG, ADC_ENABLE_BIT_NO);
	// set Vref=5(vcc)
	ADC_ADMUX_REG |= ADC_VREF_VCC;
	// set prescaler = 128
	ADC_ADCSRA_REG |= ADC_CLK_PRESCALER_128;
}

u16 adc_digitalRead(adc_chnlId_t channelId)
{
	u16 loc_ret =0;
	//set channel no to be converted
	ADC_ADMUX_REG &= ADC_CHANNEL_MASK;	/*	reset chanl id part before update	*/
	ADC_ADMUX_REG |= (u8)channelId;
	
	//start conversion
	SET_BIT(ADC_ADCSRA_REG,ADC_START_CONV_BIT_NO);
	//wait till conversion completed
	while (CHECK_BIT(ADC_ADCSRA_REG, ADC_COMP_INT_FLAG_BIT_NO) == 1)
	{
		; //do nothing
	}
	SET_BIT(ADC_ADCSRA_REG, ADC_COMP_INT_FLAG_BIT_NO); // clear interrupt flag 
	// return conversion result
	loc_ret = (ADC_ADCL_REG) | (ADC_ADCH_REG<<8);
	return loc_ret;
}

f32 adc_voltRead(adc_chnlId_t channelId)
{
	u16 loc_ret =0;
	f64 loc_volt;
	
	loc_ret = adc_digitalRead(channelId);
	loc_volt = loc_ret * ADC_STEP_SIZE;
	loc_volt = loc_volt/1000;    // from mv to v
	
	return loc_volt;
}