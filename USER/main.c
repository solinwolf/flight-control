#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include <moto.h>
#include <mpu6050.h>
#include <iic.h>
/************************************************

************************************************/
int main(void)
{		
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	LED_Init();			     //LED�˿ڳ�ʼ��
//	MotorInit();          //����ʼ��
//	MotorPwmFlash(20,20,20,20);
	IICInit();
	MPU6050Init();

	while(1)
	{
		printf("Temperature:%f\r\n",MPU6050ReadTemp());
		delay_ms(100);
	}	 
}

