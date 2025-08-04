/****************************************
 * dio.h
 * Created: 7/14/2025 9:20:58 PM
 *  Author: Muhammad
 ****************************************/ 


#ifndef DIO_H_
#define DIO_H_

#include "dio_types.h"
#include "std_types.h"

void dio_setPinDirection(dio_portId_t portId, dio_pinId_t pinId, dio_direction_t dir);
void dio_writePin(dio_portId_t portId, dio_pinId_t pinId, dio_level_t level);
void dio_flipPin(dio_portId_t portId, dio_pinId_t pinId);
dio_level_t dio_readPin(dio_portId_t portId, dio_pinId_t pinId);

void dio_setPortDirection(dio_portId_t portId, dio_direction_t dir);
void dio_writePort(dio_portId_t portId, u8 data);
void dio_writePortMask(dio_portId_t portId, u8 data, u8 mask);
#endif /* DIO_H_ */