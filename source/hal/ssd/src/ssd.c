/*
 * ssd.c
 *
 * Created: 7/15/2025 8:40:16 PM
 *  Author: mo7am
 */ 

#include "ssd_cfg.h"

u8 cc_7seg[10] = {0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	
void ssd_init(void)
{
	dio_setPortDirection(SSD_PORT, OUTPUT);
}

void ssd_display(u8 num)
{
	dio_writePortMask(SSD_PORT, (num/10)&DIGIT1_MASK, DIGIT1_MASK);
	dio_writePortMask(SSD_PORT, (num%10)<<4,DIGIT2_MASK);
}