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
	u16 accel[3] = {0};
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
	LED_Init();			     //LED端口初始化
//	MotorInit();          //马达初始化
//	MotorPwmFlash(20,20,20,20);
	IICInit();
	MPU6050Init();
	
	while(1)
	{
		MPU6050ReadAccel(MPU6050_ADDR,accel);
		printf("data:%2X\r\n",IICReadByteFromRegister(MPU6050_ADDR, WHO_AM_I));
		delay_ms(2000);
	}	 
}

