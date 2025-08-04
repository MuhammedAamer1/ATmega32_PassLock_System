/**********************************************
 * dio.c
 * Created: 7/14/2025 9:21:34 PM
 *  Author: Muhammad
 ***********************************************/ 
#include "bit_math.h"
#include "std_types.h"
#include "dio_registers.h"
#include "dio.h"

void dio_setPinDirection(dio_portId_t portId, dio_pinId_t pinId, dio_direction_t dir)
{
	//DDR	
	switch (portId)
	{
		case DIO_PORTA: //PORTA
		if (dir == OUTPUT)  //output
		{
			SET_BIT(DIO_DDRA_REG, pinId);
		}
		else //input
		{
			CLR_BIT(DIO_DDRA_REG, pinId);
		}
		break; 
		
		case DIO_PORTB:      //PORTB
		if (dir == OUTPUT)   //output
		{
			SET_BIT(DIO_DDRB_REG, pinId);
		}
		else //input
		{
			CLR_BIT(DIO_DDRB_REG, pinId);
		}
		break; 
		
		case DIO_PORTC:     //PORTC
		if (dir == OUTPUT)  //output
		{
			SET_BIT(DIO_DDRC_REG, pinId);
		}
		else //input
		{
			CLR_BIT(DIO_DDRC_REG, pinId);
		}
		break; 
		
		case DIO_PORTD:      //PORTD
		if (dir == OUTPUT)   //output
		{
			SET_BIT(DIO_DDRD_REG, pinId);
		}
		else //input
		{
			CLR_BIT(DIO_DDRD_REG, pinId);
		}
		break; 
	}
}


void dio_writePin(dio_portId_t portId, dio_pinId_t pinId, dio_level_t level)
{
	switch (portId)
	{
		case DIO_PORTA:
		 if (level == HIGH)
		 {
			 SET_BIT(DIO_PORTA_REG,pinId);
		 }
		 else
		 {
			 CLR_BIT(DIO_PORTA_REG,pinId);
		 }
		break;
		
		case DIO_PORTB:
		if (level == HIGH)
		{
			SET_BIT(DIO_PORTB_REG,pinId);
		}
		else
		{
			CLR_BIT(DIO_PORTB_REG,pinId);
		}
		break;		
		
		case DIO_PORTC:
		if (level == HIGH)
		{
			SET_BIT(DIO_PORTC_REG,pinId);
		}
		else
		{
			CLR_BIT(DIO_PORTC_REG,pinId);
		}
		break;	
		
		case DIO_PORTD:
		if (level == HIGH)
		{
			SET_BIT(DIO_PORTD_REG,pinId);
		}
		else
		{
			CLR_BIT(DIO_PORTD_REG,pinId);
		}
		break;			
	}
}


void dio_flipPin(dio_portId_t portId, dio_pinId_t pinId)
{
	switch (portId)
	{
		case DIO_PORTA:
		FLIP_BIT(DIO_PORTA_REG,pinId);
		break;	
		
		case DIO_PORTB:
		FLIP_BIT(DIO_PORTB_REG,pinId);
		break;	
		
		case DIO_PORTC:
		FLIP_BIT(DIO_PORTC_REG,pinId);
		break;	
		
		case DIO_PORTD:
		FLIP_BIT(DIO_PORTD_REG,pinId);
		break;	
	}
}

dio_level_t dio_readPin(dio_portId_t portId, dio_pinId_t pinId)
{
	dio_level_t loc_ret = LOW;
	
	switch (portId)
	{
		case DIO_PORTA:
		if (CHECK_BIT(DIO_PINA_REG,pinId) == 1)
		{
			loc_ret = HIGH;
		}
		else
		{
			loc_ret = LOW;
		}
		break;

		case DIO_PORTB:
		if (CHECK_BIT(DIO_PINB_REG,pinId) == 1)
		{
			loc_ret = HIGH;
		}
		else
		{
			loc_ret = LOW;
		}
		break;		
	
		case DIO_PORTC:
		if (CHECK_BIT(DIO_PINC_REG,pinId) == 1)
		{
			loc_ret = HIGH;
		}
		else
		{
			loc_ret = LOW;
		}
		break;		

		case DIO_PORTD:
		if (CHECK_BIT(DIO_PIND_REG,pinId) == 1)
		{
			loc_ret = HIGH;
		}
		else
		{
			loc_ret = LOW;
		}
		break;		
	}
	
	return loc_ret;
}

void dio_setPortDirection(dio_portId_t portId, dio_direction_t dir)
{
	switch (portId)
	{
		case DIO_PORTA:
		if (dir == OUTPUT)
		{
			DIO_DDRA_REG = 0xFF;
		}
		else
		{
			DIO_DDRA_REG = 0x00;
		}
		break;
		
		case DIO_PORTB:
		if (dir == OUTPUT)
		{
			DIO_DDRB_REG = 0xFF;
		}
		else
		{
			DIO_DDRB_REG = 0x00;
		}
		break;	
		
		case DIO_PORTC:
		if (dir == OUTPUT)
		{
			DIO_DDRC_REG = 0xFF;
		}
		else
		{
			DIO_DDRC_REG = 0x00;
		}
		break;		
	
		case DIO_PORTD:
		if (dir == OUTPUT)
		{
			DIO_DDRD_REG = 0xFF;
		}
		else
		{
			DIO_DDRD_REG = 0x00;
		}
		break;			
	}
}
void dio_writePort(dio_portId_t portId, u8 data)
{
	switch (portId)
	{
		case DIO_PORTA:
			DIO_PORTA_REG = data;
		break;
		
		case DIO_PORTB:
		DIO_PORTB_REG = data;
		break;		
		
		case DIO_PORTC:
		DIO_PORTC_REG = data;
		break;		
		
		case DIO_PORTD:
		DIO_PORTD_REG = data;
		break;		
	}
}


void dio_writePortMask(dio_portId_t portId, u8 data, u8 mask)
{
	switch (portId)
	{
		case DIO_PORTA:
		DIO_PORTA_REG = (DIO_PORTA_REG & ~mask) | (data);
		break;
		
		case DIO_PORTB:
		DIO_PORTB_REG = data;
		break;
		
		case DIO_PORTC:
		DIO_PORTC_REG = data;
		break;
		
		case DIO_PORTD:
		DIO_PORTD_REG = data;
		break;
	}	
}