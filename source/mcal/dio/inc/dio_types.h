/****************************************
 * dio_types.h
 * Created: 7/14/2025 9:20:58 PM
 *  Author: Muhammad
 ****************************************/


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_


typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}dio_portId_t;

typedef enum
{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}dio_pinId_t;

typedef enum
{
	OUTPUT,
	INPUT
}dio_direction_t;

typedef enum
{
 LOW,
 HIGH	
}dio_level_t;


#endif /* DIO_TYPES_H_ */