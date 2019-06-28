#ifndef __led_h__
#define __led_h__
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void LED_Init(void);
void LED_Set(u8 n);

#endif

