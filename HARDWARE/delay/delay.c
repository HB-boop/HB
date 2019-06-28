#include "delay.h"

void delay_init(void)
{
//	SysTick_CLKSourceConfig(SysTick_CLKSouce_IICLK);
	SysTick->CTRL |= SysTick_CLKSource_HCLK;
}

void delay_us(u32 nus)
{
	RCC_ClocksTypeDef	rccclk;
	u8								i;
	
	RCC_GetClocksFreq(&rccclk);
	i=(u8)(rccclk.HCLK_Frequency/1000000);
	
	SysTick->LOAD=i*nus;
	SysTick->CTRL=0X00000005;
	while(!(SysTick->CTRL&0X00010000));
	SysTick->CTRL=0X00000004;
}

void delay_ms(u32 nms)
{
	delay_us(nms*1000);
}

void delay_u(u16 nus)
{
	u32 i;
	for(i=0;i<72*nus;i++);
}
