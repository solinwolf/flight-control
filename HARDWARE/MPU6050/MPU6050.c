
#include <IIC.h>
#include <MPU6050.h>
#include <delay.h>

#include "usart.h"

void MPU6050Init(void)
{
	IICWriteByteToRegister(MPU6050_ADDR,POWER_MANAGEMENT1,0x80);
    delay_ms(100);

	IICWriteByteToRegister(MPU6050_ADDR,POWER_MANAGEMENT1,0x00);
	IICWriteByteToRegister(MPU6050_ADDR, GYROSCOPE_CONFIG, 3<<3);
	IICWriteByteToRegister(MPU6050_ADDR, ACCELEROMETER_CONFIG, 0);
    IICWriteByteToRegister(MPU6050_ADDR, SAMPLE_RATE_DIVIDER, 19);     
	IICWriteByteToRegister(MPU6050_ADDR,INTERRUPT_ENABLE,0x00);
	IICWriteByteToRegister(MPU6050_ADDR, USER_CONTROL, 0x00);
    IICWriteByteToRegister(MPU6050_ADDR, POWER_MANAGEMENT1, 0x01);     
	IICWriteByteToRegister(MPU6050_ADDR, FIFO_ENABLE, 0x00);
	IICWriteByteToRegister(MPU6050_ADDR, INT_ENABLE_CONFIG, 0x80);
	
	IICWriteByteToRegister(MPU6050_ADDR, POWER_MANAGEMENT1, 0x03);
	IICWriteByteToRegister(MPU6050_ADDR, POWER_MANAGEMENT2, 0x00);



}

uint8_t MPU6050GetDeviceID(uint8_t dev_addr)
{
	uint8_t ret = 0;
	IICStart();
	IICWriteOneByte(dev_addr);
	
	if(IICWaitAck())
	{
		printf("\r\n NO ACK for Address\r\n");	
		IICStop();
		return ret;
	}
	IICWriteOneByte(WHO_AM_I);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK Register %02X\r\n",WHO_AM_I);

		IICStop();
		return ret;
	}

	IICStart();
	IICWriteOneByte(dev_addr+1);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK Data \r\n");
		IICStop();
		return ret;
	}

	ret = IICReadOneByte(nack);
	IICStop();
	return ret;
}

float MPU6050ReadTemp(void)
{
	uint8_t data[2] = {0};
	int tmp = 0;
	float temp = 0.0;
	
	IICReadBytes(MPU6050_ADDR,TEMP_OUT_H,data,2);
	tmp = data[0];
	tmp = (int)((tmp<<8)|data[1]);
	
	temp = (float)tmp/340.0+36.53;
	
	return temp;
}

void MPU6050ReadAccel(uint8_t dev_addr,uint16_t* data)
{
	uint8_t buf[6] = {1};
	if(IICReadBytes(dev_addr,ACCEL_XOUT_H,buf,6))
	{
		data[0] = (uint16_t)(buf[0]<<8 | buf[1]);
		data[1] = (uint16_t)(buf[2]<<8 | buf[3]);
		data[2] = (uint16_t)(buf[4]<<8 | buf[5]);
	}

	printf("data:%d %d %d %d %d %d\r\n",buf[0],buf[1],buf[2],buf[3],buf[4],buf[5]);
	
}
void MPU6050ReadGyro(uint8_t dev_addr,uint16_t* data)
{
	uint8_t buf[6] = {1};
	if(IICReadBytes(dev_addr,GYRO_XOUT_H,buf,6)==6)
	{
		data[0] = (uint16_t)(buf[0]<<8 | buf[1]);
		data[1] = (uint16_t)(buf[2]<<8 | buf[3]);
		data[2] = (uint16_t)(buf[4]<<8 | buf[5]);

	}
	printf("data:%d %d %d %d %d %d\r\n",buf[0],buf[1],buf[2],buf[3],buf[4],buf[5]);

}



