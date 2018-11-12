#ifndef __MPU6050_H__
#define __MPU6050_H__




#define MPU6050_ADDR		 0xD0




/**MPU6050 寄存器地址**/
#define SELF_TEST_X   		 0x0D    /*自检寄存器*/
#define SELF_TEST_Y     	 0x0E
#define SELF_TEST_Z    		 0x0F
#define SELF_TEST_A    		 0x10

#define SAMPLE_RATE_DIVIDER  0x19   /*采样频率分频器*/
#define CONFIG         		 0x1A   /*配置寄存器*/
#define GYROSCOPE_CONFIG     0x1B   /*陀螺仪配置寄存器*/    
#define ACCELEROMETER_CONFIG 0x1C   /*加速度计配置寄存器*/
#define MOTION_DETECTION_THRESHOLD   0x1F  /*运动检测阈值*/
#define FIFO_ENABLE          0x23   /*FIFO使能*/
#define I2C_MASTER_CONTROL   0x24   /*I2C主机控制*/

#define I2C_SLAVE0_ADDR  	 0x25  /*I2C 从机0控制寄存器*/
#define I2C_SLAVE0_REG       0x26  
#define I2C_SLAVE0_CTRL		 0x27

#define I2C_SLAVE1_ADDR  	 0x28  /*I2C 从机1控制寄存器*/
#define I2C_SLAVE1_REG       0x29  
#define I2C_SLAVE1_CTRL		 0x2A

#define I2C_SLAVE2_ADDR  	 0x2B  /*I2C 从机2控制寄存器*/
#define I2C_SLAVE2_REG       0x2C  
#define I2C_SLAVE2_CTRL		 0x2D

#define I2C_SLAVE3_ADDR  	 0x2E  /*I2C 从机3控制寄存器*/
#define I2C_SLAVE3_REG       0x2F  
#define I2C_SLAVE3_CTRL		 0x30

#define I2C_SLAVE4_ADDR  	 0x31  /*I2C 从机4控制寄存器*/
#define I2C_SLAVE4_REG       0x32  
#define I2C_SLAVE4_CTRL		 0x33

#define I2C_MASTER_STATUS	 0x36  /*I2C主机状态*/
#define INT_ENABLE_CONFIG	 0x37  /*INT引脚/旁路有效,使能配置*/
#define INTERRUPT_ENABLE 	 0x38  /*中断使能*/
#define INTERRUPT_STATUS	 0x3A  /*中断过状态*/

#define ACCEL_XOUT_H		 0x3B	/*加速度计测量值*/
#define ACCEL_XOUT_L		 0x3C
#define ACCEL_YOUT_H		 0x3D	
#define ACCEL_YOUT_L		 0x3E
#define ACCEL_ZOUT_H	     0x3F
#define ACCEL_ZOUT_L		 0x40

#define TEMP_OUT_H			 0x41
#define TEMP_OUT_L			 0x42

#define GYRO_XOUT_H			 0x43  /*陀螺仪测量值*/
#define GYRO_XOUT_L			 0x44
#define	GYRO_YOUT_H		 	 0x45	
#define GYRO_YOUT_L			 0x46
#define GYRO_ZOUT_H			 0x47
#define	GYRO_ZOUT_L			 0x48

#define EXTERNAL_SENSOR_DATA_BASE	0x49 /*外部传感器数据基地址*/
#define EXTERNAL_SENSOR_DATA(index) (EXTERNAL_SENSOR_DATA_BASE+index) /*index=0~23*/

#define I2C_SLAVE0_DATA_OUT	 0x63  /*I2C从机0数据输出*/
#define I2C_SLAVE1_DATA_OUT	 0x64  /*I2C从机1数据输出*/
#define I2C_SLAVE2_DATA_OUT	 0x65  /*I2C从机2数据输出*/
#define I2C_SLAVE3_DATA_OUT	 0x66  /*I2C从机3数据输出*/

#define I2C_MASTER_DELAY_CTRL  0x67 /*I2C主机延时管理*/
#define SIGNAL_PATH_RESET	 0x68   /*信号通道复位*/
#define MOTION_DETECTION_CTRL  0x69 /*运动检测控制*/
#define USER_CONTROL 		 0x6A	/*用户配置*/
#define POWER_MANAGEMENT1    0x6B  /*电源管理1*/
#define POWER_MANAGEMENT2    0x6C  /*电源管理2*/
#define FIFO_COUNTER_H		 0x72  /*FIFO计数寄存器*/
#define FIFO_COUNTER_L		 0x73  /*FIFO计数寄存器*/
#define FIFO_RW				 0x74  /*FIFO读写*/
#define WHO_AM_I             0x75  /*标识设备身份寄存器*/

void MPU6050Init(void);
uint8_t MPU6050GetDeviceID(uint8_t dev_addr);
float MPU6050ReadTemp(void);


#endif
