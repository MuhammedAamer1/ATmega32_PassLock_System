/*
 * eeprom.c
 *
 * Created: 7/20/2025 5:52:43 PM
 *  Author: mo7am
 */ 

#include "std_types.h"
#include "eeprom_registers.h"
#include "bit_math.h"

u8 eeprom_read(u16 addr)
{
/* Wait for completion of previous write */
	while (CHECK_BIT(EEPROM_EECR_REG, EEWE_BIT_NO) == 1)
	{
		; /*	wait	*/
	}
/* Set up address register */
	EEPROM_EEARL_REG = (u8)addr;
	EEPROM_EEARH_REG = (u8)(addr>>8);
	
/* Start eeprom read by writing EERE */
SET_BIT(EEPROM_EECR_REG,EERE_BIT_NO);

/* Return data from data register */
return EEPROM_EEDR_REG;	
}

void eeprom_write(u16 addr, u8 data)
{
	/* Wait for completion of previous write */
	while (CHECK_BIT(EEPROM_EECR_REG, EEWE_BIT_NO) == 1)
		{
			; /*	wait	*/
		}
	/* Set up address and data registers */
	//EEAR = addr;
	EEPROM_EEARL_REG = (u8)addr;
	EEPROM_EEARH_REG = (u8)(addr>>8);
	
	EEPROM_EEDR_REG = data;
	/* Write logical one to EEMWE */
	//EECR |= (1<<EEMWE);
	SET_BIT(EEPROM_EECR_REG,EEMWE_BIT_NO);

	/* Start eeprom write by setting EEWE */
	//EECR |= (1<<EEWE);	
	SET_BIT(EEPROM_EECR_REG,EEWE_BIT_NO);
}