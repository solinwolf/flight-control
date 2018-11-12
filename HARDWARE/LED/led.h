#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK精英STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5	

void LED_Init(void);//初始化

#define LED1_ON    GPIO_SetBits(GPIOA,GPIO_Pin_8)
#define LED1_OFF    GPIO_ResetBits(GPIOA,GPIO_Pin_8)


#define LED2_ON    GPIO_SetBits(GPIOA,GPIO_Pin_11)
#define LED2_OFF    GPIO_ResetBits(GPIOA,GPIO_Pin_11)


#define LED3_ON    GPIO_SetBits(GPIOB,GPIO_Pin_1)
#define LED3_OFF    GPIO_ResetBits(GPIOB,GPIO_Pin_1)


#define LED4_ON    GPIO_SetBits(GPIOB,GPIO_Pin_3)
#define LED4_OFF    GPIO_ResetBits(GPIOB,GPIO_Pin_3)

#endif
