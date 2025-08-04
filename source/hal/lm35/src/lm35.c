/*
 * lm35.c
 *
 * Created: 7/21/2025 9:06:13 PM
 *  Author: mo7am
 */ 
#include "lm35_cfg.h"

void lm35_init(void)
{
	adc_init();
}

u8 lm35_readTemp(void)
{
	f32 snsVolt_v =0;
	f64 sensVolt_mv =0;
	u8 temp =0;
	snsVolt_v = adc_voltRead(LM35_ADC_CHANNEL);
	
	sensVolt_mv = snsVolt_v*1000;   //convert to mv
	
	sensVolt_mv = sensVolt_mv/10;    //convert to celicus degree
	
	temp = (u8)sensVolt_mv;
	return temp;
}