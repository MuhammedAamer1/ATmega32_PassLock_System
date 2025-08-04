/*
 * Authentication.c
 *
 * Created: 7/23/2025 9:01:56 PM
 * Author: Muhammed
 */

#define F_CPU 16000000UL

#include "Authentication.h"
#include "lcd.h"
#include "keypad.h"
#include "std_types.h"
#include "eeprom.h"
#include <util/delay.h>
#include "led.h"
#include "button.h"


//************************************************************************************************************************************

void set_Birthday(void)
{
	u8 birthday1[BIRTHDAY_LENGTH + 1];

	while (1)
	{
		while (keypad_keyIsPressed()) {
			_delay_ms(50);
		}

		lcd_clear();
		lcd_displaystr((u8*)"Set Birthday:");
		lcd_gotoRowColumn(1, 0);
		lcd_displaystr((u8*)"(DD-MM-YYYY)");
		_delay_ms(3000);
		lcd_gotoRowColumn(1, 0);
		lcd_displaystr((u8*)"                ");
		lcd_gotoRowColumn(1, 0);

		for (u8 i = 0; i < BIRTHDAY_LENGTH; i++)
		{
			birthday1[i] = keypad_waitForKey();
			lcd_displayChr('#');
			_delay_ms(300);
		}
		birthday1[BIRTHDAY_LENGTH] = '\0';

		while (keypad_keyIsPressed()) {
			_delay_ms(50);
		}

		for (u8 i = 0; i < BIRTHDAY_LENGTH; i++)
		{
			eeprom_write(BIRTHDAY_ADDRESS + i, birthday1[i]);
		}

		lcd_clear();
		lcd_displaystr((u8*)"Birthday Saved!");
		_delay_ms(1500);
		break;
	}
}





//************************************************************************************************************************************

void set_Password(void)
{
	u8 pass1[PASSWORD_LENGTH + 1];
	u8 pass2[PASSWORD_LENGTH + 1];

	while (1)
	{
		while (keypad_keyIsPressed()) {
			_delay_ms(50);
		}

		lcd_clear();
		lcd_displaystr((u8*)"Set Password:");
		lcd_gotoRowColumn(1, 0);
		_delay_ms(500);

		for (u8 i = 0; i < PASSWORD_LENGTH; i++)
		{
			pass1[i] = keypad_waitForKey();
			lcd_displayChr('*');
			_delay_ms(300);
		}
		pass1[PASSWORD_LENGTH] = '\0';

		while (keypad_keyIsPressed()) {
			_delay_ms(50);
		}

		lcd_clear();
		lcd_displaystr((u8*)"Confirm Password:");
		lcd_gotoRowColumn(1, 0);

		for (u8 i = 0; i < PASSWORD_LENGTH; i++)
		{
			pass2[i] = keypad_waitForKey();
			lcd_displayChr('*');
			_delay_ms(300);
		}
		pass2[PASSWORD_LENGTH] = '\0';

		boolean is_Match = TRUE;
		for (u8 i = 0; i < PASSWORD_LENGTH; i++)
		{
			if (pass1[i] != pass2[i])
			{
				is_Match = FALSE;
				break;
			}
		}

		if (is_Match)
		{
			for (u8 i = 0; i < PASSWORD_LENGTH; i++)
			{
				eeprom_write(PASSWORD_ADDRESS + i, pass1[i]);
			}
			eeprom_write(PASSWORD_FLAG_ADDR, PASSWORD_SET_FLAG);

			lcd_clear();
			lcd_displaystr((u8*)"Password Saved!");
			_delay_ms(1500);
			
			break;
		}
		else
		{
			lcd_clear();
			lcd_displaystr((u8*)"Mismatch! Retry");
			_delay_ms(1500);
		}
	}
}




//************************************************************************************************************************************

boolean log_In(void)
{
	boolean loc_ret = FALSE;
	u8 entered[PASSWORD_LENGTH + 1];
	u8 stored[PASSWORD_LENGTH + 1];

	lcd_clear();
	lcd_displaystr((u8*)"Enter Password:");
	lcd_gotoRowColumn(1, 0);

	for (u8 i = 0; i < PASSWORD_LENGTH; i++)
	{
		entered[i] = keypad_waitForKey();
		lcd_displayChr('*');
		_delay_ms(300);
	}
	entered[PASSWORD_LENGTH] = '\0';

	for (u8 i = 0; i < PASSWORD_LENGTH; i++)
	{
		stored[i] = eeprom_read(PASSWORD_ADDRESS + i);
	}
	stored[PASSWORD_LENGTH] = '\0';

	boolean match = TRUE;
	for (u8 i = 0; i < PASSWORD_LENGTH; i++)
	{
		if (entered[i] != stored[i])
		{
			match = FALSE;
			break;
		}
	}

	if (match)
	{
		led_on(LED3);
		led_off(LED2);
		
		lcd_clear();
		lcd_displaystr((u8*)"WELCOME!");
		_delay_ms(1500);

		loc_ret = TRUE;
	}
	else
	{
		led_on(LED2);
		led_off(LED3);

		lcd_clear();
		lcd_displaystr((u8*)"Wrong Password!");
		_delay_ms(1500);

		led_off(LED2);
		loc_ret = FALSE;
	}
	
	return loc_ret;
}




//************************************************************************************************************************************

boolean check_Flag(void)
{
	return (eeprom_read(PASSWORD_FLAG_ADDR) == PASSWORD_SET_FLAG);
}


void reset_Password(void)
{
	eeprom_write(PASSWORD_FLAG_ADDR, 0xFF);
	lcd_clear();
	lcd_displaystr((u8*)"Password Reset!");
	_delay_ms(1500);
	set_Password();
}




//************************************************************************************************************************************

void forget_Password(void)
{
	lcd_clear();
	lcd_displaystr((u8*)"Forget Password?");
	lcd_gotoRowColumn(1, 0);
	lcd_displaystr((u8*)"1-Yes 2-Retry");
	
	u8 choice = keypad_waitForKey();
	while (keypad_keyIsPressed()) {
		_delay_ms(50);
	}

	if (choice == 'A')
	{
		u8 entered_bday[BIRTHDAY_LENGTH + 1];
		u8 stored_bday[BIRTHDAY_LENGTH + 1];
		
		lcd_clear();
		lcd_displaystr((u8*)"Enter Birthday:");
		lcd_gotoRowColumn(1, 0);
		
		for (u8 i = 0; i < BIRTHDAY_LENGTH; i++) {
			entered_bday[i] = keypad_waitForKey();
			lcd_displayChr('#');
			_delay_ms(300);
		}
		entered_bday[BIRTHDAY_LENGTH] = '\0';

		for (u8 i = 0; i < BIRTHDAY_LENGTH; i++) {
			stored_bday[i] = eeprom_read(BIRTHDAY_ADDRESS + i);
		}
		stored_bday[BIRTHDAY_LENGTH] = '\0';

		boolean bday_match = TRUE;
		for (u8 i = 0; i < BIRTHDAY_LENGTH; i++) {
			if (entered_bday[i] != stored_bday[i]) {
				bday_match = FALSE;
				break;
			}
		}

		if (bday_match) {
			reset_Password();
		} else {
			lcd_clear();
			lcd_displaystr((u8*)"Wrong Birthday!");
			_delay_ms(1500);
		}
	}
}




//************************************************************************************************************************************

void start_Authentication(void)
{
	lcd_init();
	keypad_init();
	led_init();
	button_init();

	if (!check_Flag())
	{
		set_Password();
		set_Birthday();
	}

	u8 wrong_tries = 0;
	while (1)
	{
		if (log_In())
		{
			break;
		}
		else
		{
			wrong_tries++;
			if (wrong_tries >= MAX_TRIES)
			{
				forget_Password();
				wrong_tries = 0;
			}
		}
	}
}
