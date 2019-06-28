#ifndef __usart1_h__
#define __usart1_h__
#include "stdio.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
#include "misc.h"
#include "delay.h"




extern u8 rx1_num,tx1_num,tx1_nums,usart1_flag;
extern u8 rx1_dat[50],tx1_dat[50];

u16 GetCheckCode(u8 *puchMsg,u8 usDataLen);
void usart1_Init(void);
void usart1_Send(u8 len);

#endif

