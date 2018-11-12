#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
 

//��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PA PB�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_11;	 //PA.8 PA.11 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8 GPIOA.11
 GPIO_ResetBits(GPIOA,GPIO_Pin_8);						 //PA.8 �����
 GPIO_ResetBits(GPIOA,GPIO_Pin_11);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_3;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.1 GPIOB.3
 GPIO_ResetBits(GPIOB,GPIO_Pin_1);						 //PB.1 �����
	
 GPIO_ResetBits(GPIOB,GPIO_Pin_3);

}




 
