/*
 * lcd.c
 *
 * Created: 7/17/2025 5:56:59 PM
 *  Author: mo7am
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "lcd.h"
#include "stdlib.h"
#include "adc.h"

static void lcd_enablePulse(void);
static void lcd_sendData(u8 data);

static void lcd_sendData(u8 data)
{
	dio_writePin(LCD_RS_PORT, LCD_RS_PIN, HIGH);
	
	dio_writePort(LCD_DATA_PORT, data);
	
	lcd_enablePulse();
}

static void lcd_enablePulse(void)
{
	dio_writePin(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(1);
	dio_writePin(LCD_EN_PORT, LCD_EN_PIN, LOW);
	_delay_ms(2);	
}

void lcd_init(void)
{
	dio_setPortDirection(LCD_DATA_PORT,OUTPUT);				/* config data line as output	*/
	dio_setPinDirection(LCD_RS_PORT, LCD_RS_PIN, OUTPUT);   /* config RS pin as output	*/
	dio_setPinDirection(LCD_RW_PORT, LCD_RW_PIN, OUTPUT);	/* config RW pin as output	*/
	dio_setPinDirection(LCD_EN_PORT, LCD_EN_PIN, OUTPUT);	/* config EN pin as output	*/
	
	dio_writePin(LCD_RW_PORT, LCD_RW_PIN, LOW);				/* we always write to LCD	*/
	
	_delay_ms(15);
	lcd_sendCmd(_LCD_INIT_CMD);
	_delay_ms(5);
	lcd_sendCmd(_LCD_INIT_CMD);
	_delay_us(100);
	lcd_sendCmd(_LCD_INIT_CMD);
	
	lcd_sendCmd(_LCD_TURN_ON_CURSOR_ON);
	lcd_sendCmd(_LCD_8BIT_MODE);
	lcd_gotoRowColumn(0,0);
}

void lcd_sendCmd(lcd_cmd_t cmd)
{
	dio_writePin(LCD_RS_PORT, LCD_RS_PIN, LOW);
	
	dio_writePort(LCD_DATA_PORT, cmd);
	
	lcd_enablePulse();
}


void lcd_displayChr(u8 chr)
{
	lcd_sendData (chr);	
}

void lcd_displaystr(u8 str[])
{
	while (*str != '\0')
	{
		lcd_displayChr(*str);
		str++;
	}
}

void lcd_gotoRowColumn(u8 row, u8 col)
{
	switch (row)
	{
		case 0:
		lcd_sendCmd(0x80+col);
		break;
		
		
		case 1:
		lcd_sendCmd(0xC0+col);
		break;
	}
}

void lcd_displayNum_u8(u8 num)
{
	  u8 buffer[3];
	 itoa(num,buffer,10);
	 lcd_displaystr(buffer);
}

void lcd_displayNum_u16(u16 num)
{
	u8 buffer[5];
	itoa(num,buffer,10);
	lcd_displaystr(buffer);
}

void lcd_displayNum_f32(f32 num)
{
	u8 buffer[20];
	//itoa(num, buffer,10);
	sprintf(buffer, "%f",num);
	lcd_displaystr(buffer);	
}


void lcd_clear(void)
{
	lcd_sendCmd(LCD_CMD_CLEAR);  
	_delay_ms(2); 
}
