/**************************************************
 * keypad_cfg.h
 * Created: 7/17/2025 8:41:25 PM
 * Author: Muhammad
 **************************************************/ 

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
#include "dio.h"

/*	Keypad Rows	*/
#define KPAD_ROW0_PORT		DIO_PORTB
#define KPAD_ROW0_PIN		DIO_PIN0

#define KPAD_ROW1_PORT		DIO_PORTB
#define KPAD_ROW1_PIN		DIO_PIN1

#define KPAD_ROW2_PORT		DIO_PORTB
#define KPAD_ROW2_PIN		DIO_PIN2

#define KPAD_ROW3_PORT		DIO_PORTB
#define KPAD_ROW3_PIN		DIO_PIN3

/*	Keypad columns	*/
#define KPAD_COL0_PORT		DIO_PORTB
#define KPAD_COL0_PIN		DIO_PIN4

#define KPAD_COL1_PORT		DIO_PORTB
#define KPAD_COL1_PIN		DIO_PIN5

#define KPAD_COL2_PORT		DIO_PORTB
#define KPAD_COL2_PIN		DIO_PIN6

#define KPAD_COL3_PORT		DIO_PORTB
#define KPAD_COL3_PIN		DIO_PIN7
#endif /* KEYPAD_CFG_H_ */