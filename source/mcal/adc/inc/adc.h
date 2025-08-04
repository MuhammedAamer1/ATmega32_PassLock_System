/*
 * adc.h
 *
 * Created: 7/21/2025 6:05:13 PM
 *  Author: mo7am
 */ 

/*
8 ADC channels
10 bit 

configurations 
- Vref
- prescaler 
 
*/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "adc_types.h"

#define ADC_CHANNEL_MASK	0xE0
#define ADC_STEP_SIZE      4.9 // mv 

void adc_init(void);
u16 adc_digitalRead(adc_chnlId_t channelId);
f32 adc_voltRead(adc_chnlId_t channelId);
#endif /* ADC_H_ */