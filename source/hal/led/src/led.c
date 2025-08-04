/****************************************
 * led.c
 * Created: 7/14/2025 9:20:58 PM
 *  Author: Muhammad
 ****************************************/ 
#include "dio.h"
#include "led_types.h"
#include "led_cfg.h"

void led_init(void)
{
	dio_setPinDirection(LED1_PORT, LED1_PIN,OUTPUT);
	dio_setPinDirection(LED2_PORT, LED2_PIN,OUTPUT);
	dio_setPinDirection(LED3_PORT, LED3_PIN,OUTPUT);
}

void led_on(led_ledId_t ledID)
{
	switch (ledID)
	{
		case LED1:
		dio_writePin(LED1_PORT, LED1_PIN, HIGH);
		break;
		
		case LED2:
		dio_writePin(LED2_PORT, LED2_PIN, HIGH);
		break;		
		
		case LED3:
		dio_writePin(LED3_PORT, LED3_PIN, HIGH);
		break;		
	}
}

void led_off(led_ledId_t ledID)
{
	switch (ledID)
	{
		case LED1:
		dio_writePin(LED1_PORT, LED1_PIN, LOW);
		break;
		
		case LED2:
		dio_writePin(LED2_PORT, LED2_PIN, LOW);
		break;		
		
		case LED3:
		dio_writePin(LED3_PORT, LED3_PIN, LOW);
		break;		
	}	
}

void led_toggle(led_ledId_t ledID)
{
	switch (ledID)
	{
		case LED1:
		dio_flipPin(LED1_PORT, LED1_PIN);
		break;

		case LED2:
		dio_flipPin(LED2_PORT, LED2_PIN);
		break;		
		
		case LED3:
		dio_flipPin(LED3_PORT, LED3_PIN);
		break;		
	}	
}
