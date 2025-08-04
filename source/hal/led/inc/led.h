/****************************************
 * led.h
 * Created: 7/14/2025 9:20:58 PM
 *  Author: Muhammad
 ****************************************/ 


#ifndef LED_H_
#define LED_H_

#include "led_types.h"

void led_init(void);
void led_on(led_ledId_t ledID);
void led_off(led_ledId_t ledID);
void led_toggle(led_ledId_t ledID);

#endif /* LED_H_ */