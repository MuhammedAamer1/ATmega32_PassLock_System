/*
 * Authentication.h
 *
 * Created: 7/23/2025 8:51:43 PM
 *  Author: Administrator
 */ 


#ifndef AUTHENTICATION_H_
#define AUTHENTICATION_H_


#define PASSWORD_LENGTH 6
#define BIRTHDAY_LENGTH 6
#define MAX_TRIES 3

#define PASSWORD_ADDRESS 0x00
#define BIRTHDAY_ADDRESS 0x10
#define PASSWORD_FLAG_ADDR 0x20
#define PASSWORD_SET_FLAG 0x01

#include "std_types.h"


void set_Password(void);

boolean log_In(void);

void set_Birthday(void);

void forget_Password(void);

void start_Authentication(void);

#endif /* AUTHENTICATION_H_ */