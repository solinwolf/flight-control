
#include <IIC.h>
#include <MPU6050.h>
#include <delay.h>

#include "usart.h"

void MPU6050Init(void)
{
	IICWriteByteToRegister(MPU6050_ADDR,POWER_MANAGEMENT1,0x80);
    delay_ms(50);
    IICWriteByteToRegister(MPU6050_ADDR, SAMPLE_RATE_DIVIDER, 0x00);      //SMPLRT_DIV    -- SMPLRT_DIV = 0  Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV)
    IICWriteByteToRegister(MPU6050_ADDR, POWER_MANAGEMENT1, 0x03);      //PWR_MGMT_1    -- SLEEP 0; CYCLE 0; TEMP_DIS 0; CLKSEL 3 (PLL with Z Gyro reference)
    IICWriteByteToRegister(MPU6050_ADDR, INT_ENABLE_CONFIG, 0 << 7 | 0 << 6 | 0 << 5 | 0 << 4 | 0 << 3 | 0 << 2 | 1 << 1 | 0 << 0);  // INT_PIN_CFG   -- INT_LEVEL_HIGH, INT_OPEN_DIS, LATCH_INT_DIS, INT_RD_CLEAR_DIS, FSYNC_INT_LEVEL_HIGH, FSYNC_INT_DIS, I2C_BYPASS_EN, CLOCK_DIS
    IICWriteByteToRegister(MPU6050_ADDR, CONFIG, 0x03);  //CONFIG        -- EXT_SYNC_SET 0 (disable input pin for data sync) ; default DLPF_CFG = 0 => ACC bandwidth = 260Hz  GYRO bandwidth = 256Hz)
	//	MPU6050_setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
    // Accel scale 8g (4096 LSB/g)
    IICWriteByteToRegister(MPU6050_ADDR, ACCELEROMETER_CONFIG, 2 << 3);

}

uint8_t MPU6050GetDeviceID(uint8_t dev_addr)
{
	uint8_t ret = 0;
	IICStart();
	IICWriteOneByte(dev_addr);
	
	if(IICWaitAck())
	{
		printf("\r\n NO ACK for Address\r\n");
	}
	IICWriteOneByte(WHO_AM_I);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK Register \r\n");
	}

	IICStart();
	IICWriteOneByte(dev_addr+1);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK Data \r\n");
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

