#include "led.h"

/********************************************************
@函数名		：	LED_Init
@时间			：	2016-03-16
@功能			：	初始化引脚
@输入参数	：	无
@返回值		：	无
@备注			：	PB12
********************************************************/
void LED_Init(void)
{
		GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);	 //使能A端口时钟
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_15;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  //初始化GPIOA
 	GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_15);	
	
//	GPIO_InitTypeDef	GPIO_InitStructure;
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	
//	GPIO_SetBits(GPIOA,GPIO_Pin_15);
}

/********************************************************
@函数名		：	LED_Set
@时间			：	2016-03-17
@功能			：	设置LED1亮灭
@输入参数	：	n=1：亮   n=0：灭
@返回值		：	无
@备注			：	
********************************************************/
void LED_Set(u8 n)
{
	if(n)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_15);
	}
	else
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_15);
	}
}


