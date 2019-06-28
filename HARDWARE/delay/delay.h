#ifndef __delay_h__
#define __delay_h__
#include "stm32f10x_rcc.h"

void delay_init(void);
void delay_us(u32 nus);
void delay_ms(u32 nms);
void delay_u(u16 nus);

#endif
