/*
 * button.h
 *
 * Created: 7/15/2025 6:37:14 PM
 *  Author: Muhammed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "button_types.h"
#include "button_cfg.h"

void button_init(void);
button_buttonSts_t button_getStatus(button_buttonId_t buttonId);



#endif /* BUTTON_H_ */
