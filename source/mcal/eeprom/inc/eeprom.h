/*
 * eeprom.h
 *
 * Created: 7/20/2025 5:52:30 PM
 *  Author: mo7am
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


u8 eeprom_read(u16 addr);
void eeprom_write(u16 addr, u8 data);


#endif /* EEPROM_H_ */