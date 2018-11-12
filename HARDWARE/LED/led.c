#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
 

//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);	 //使能PA PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_11;	 //PA.8 PA.11 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8 GPIOA.11
 GPIO_ResetBits(GPIOA,GPIO_Pin_8);						 //PA.8 输出高
 GPIO_ResetBits(GPIOA,GPIO_Pin_11);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_3;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.1 GPIOB.3
 GPIO_ResetBits(GPIOB,GPIO_Pin_1);						 //PB.1 输出高
	
 GPIO_ResetBits(GPIOB,GPIO_Pin_3);

}




 
