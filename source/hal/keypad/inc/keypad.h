/**************************************************
 * keypad.h
 * Created: 7/17/2025 8:41:25 PM
 * Author: Muhammad
 **************************************************/ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#include "keypad_cfg.h" 

void keypad_init(void);
boolean keypad_keyIsPressed(void);
u8 keypad_getKeyPressed(void);
u8 keypad_waitForKey();



#endif /* KEYPAD_H_ */