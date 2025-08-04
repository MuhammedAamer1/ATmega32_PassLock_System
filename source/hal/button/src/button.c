/*
 * button.c
 *
 * Created: 7/15/2025 6:37:28 PM
 *  Author: mo7am
 */ 

#include "button.h"
#include "dio.h"

void button_init(void)
{
	dio_setPinDirection(BUTTON1_PORT, BUTTON1_PIN, INPUT);
	dio_setPinDirection(BUTTON2_PORT, BUTTON2_PIN, INPUT);
	dio_setPinDirection(BUTTON3_PORT, BUTTON3_PIN, INPUT);
}

button_buttonSts_t button_getStatus(button_buttonId_t buttonId)
{
	button_buttonSts_t loc_ret= RELEASED;
	
	switch (buttonId)
	{
		case Button1:
		 if (dio_readPin(BUTTON1_PORT,BUTTON1_PIN) == HIGH)
		 {
			loc_ret = PRESSED ;
		 }
		 else
		 {
			 loc_ret = RELEASED;
		 }
		break;
		
		case Button2:
		if (dio_readPin(BUTTON2_PORT,BUTTON2_PIN) == HIGH)
		{
			loc_ret = PRESSED;
		}
		else
		{
			loc_ret = RELEASED;
		}
		break;
		
		case Button3:
		if (dio_readPin(BUTTON3_PORT,BUTTON3_PIN) == HIGH)
		{
			loc_ret = PRESSED;
		}
		else
		{
			loc_ret = RELEASED;
		}
		break;		
	}
	return loc_ret;
}