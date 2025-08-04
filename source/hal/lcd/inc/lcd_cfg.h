/**************************************************
 * lcd_cfg.h
 * Created: 7/17/2025 6:08:42 PM
 * Author: Muhammad
 **************************************************/ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "dio.h"

#define LCD_DATA_PORT		DIO_PORTD

#define LCD_RS_PORT			DIO_PORTC
#define LCD_RS_PIN          DIO_PIN3

#define LCD_RW_PORT			DIO_PORTC
#define LCD_RW_PIN			DIO_PIN1

#define LCD_EN_PORT			DIO_PORTC
#define LCD_EN_PIN			DIO_PIN0

#define LCD_CMD_CLEAR       0x01


#endif /* LCD_CFG_H_ */