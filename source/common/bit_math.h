/*********************************************
 * bit_math.h
 * Created: 7/14/2025 6:17:25 PM
 *  Author: Muhammad
 *****************************************/ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(reg,bit_no)    (reg |= (1<<bit_no))
#define CLR_BIT(reg,bit_no)	   (reg &= ~(1<<bit_no))
#define CHECK_BIT(reg,bit_no)  ((reg>>bit_no)&0x1)
#define FLIP_BIT(reg,bit_no)   (reg ^= (1<<bit_no))


#endif /* BIT_MATH_H_ */