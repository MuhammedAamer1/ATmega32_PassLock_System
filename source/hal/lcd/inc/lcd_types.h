/*************************************************
 * lcd_types.h
 * Created: 7/17/2025 6:08:42 PM
 * Author: Muhammad
 **************************************************/

#ifndef LCD_TYPES_H_
#define LCD_TYPES_H_

typedef enum 
{
	_LCD_CLEAR=0x01,
	_LCD_CURSOR_OFF=0x0C,
	_LCD_CURSOR_ON=0x0F,
	_LCD_4BIT_MODE=0x28,
	_LCD_INIT_CMD=0x30,
	_LCD_8BIT_MODE=0x38,
	_LCD_ON=0x0F,
	_LCD_CURSOR_UNDERLINE=0x0E,
	_LCD_TURN_ON_CURSOR_ON=0x0D,
	_LCD_CURSOR_SHIFT_LEFT=0x10,
	_LCD_CURSOR_SHIFT_RIGHT=0x14,
	_LCD_CURSOR_INCREMENT=0x06,
	_LCD_CGRAM_START_ADDRESS=0x40	
}lcd_cmd_t;



#endif /* LCD_TYPES_H_ */