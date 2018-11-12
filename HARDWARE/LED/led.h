#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK��ӢSTM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5	

void LED_Init(void);//��ʼ��

#define LED1_ON    GPIO_SetBits(GPIOA,GPIO_Pin_8)
#define LED1_OFF    GPIO_ResetBits(GPIOA,GPIO_Pin_8)


#define LED2_ON    GPIO_SetBits(GPIOA,GPIO_Pin_11)
#define LED2_OFF    GPIO_ResetBits(GPIOA,GPIO_Pin_11)


#define LED3_ON    GPIO_SetBits(GPIOB,GPIO_Pin_1)
#define LED3_OFF    GPIO_ResetBits(GPIOB,GPIO_Pin_1)


#define LED4_ON    GPIO_SetBits(GPIOB,GPIO_Pin_3)
#define LED4_OFF    GPIO_ResetBits(GPIOB,GPIO_Pin_3)

#endif
