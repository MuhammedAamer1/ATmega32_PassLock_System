/*
 * button_types.h
 *
 * Created: 7/15/2025 6:39:29 PM
 *  Author: mo7am
 */ 


#ifndef BUTTON_TYPES_H_
#define BUTTON_TYPES_H_

typedef enum
{
   Button1,
   Button2,
   Button3	
}button_buttonId_t;


typedef enum
{
	PRESSED,
	RELEASED
}button_buttonSts_t;


#endif /* BUTTON_TYPES_H_ */