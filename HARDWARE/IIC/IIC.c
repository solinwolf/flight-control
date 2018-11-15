
#include <type.h>
#include <IIC.h>
#include <delay.h>
#include "usart.h"

void IICInit(void)
{
	/*Initialize ports */
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			     
	//配置PB6 PB7 为开漏输出  刷新频率为10Mhz
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	//应用配置到GPIOB 
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void IICStart(void)
{
	SDA_OUT();
	IIC_SDA = 1;
	IIC_SCL = 1;
	delay_us(2);
	IIC_SDA = 0;
	delay_us(2);
	IIC_SCL = 0;
	
}
void IICStop(void)
{
	SDA_OUT();
	IIC_SCL = 1;
	IIC_SDA = 0;
	delay_us(2);
	IIC_SCL = 1;
	IIC_SDA = 1;
	delay_us(2);
}
uint8_t IICWaitAck(void)
{
	uint8_t ucErrTime=0;
	SDA_IN();      //SDA设置为输入  
	IIC_SDA=1;delay_us(2);	   
	IIC_SCL=1;delay_us(2);	 
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>50)
		{
			IICStop();
			return 1;
		}
		delay_us(2);
	}
	IIC_SCL=0;//时钟输出0 	   
	return 0;  
} 

void IICAck(void)
{
	SDA_OUT();
	IIC_SCL = 1;
	IIC_SDA = 0;
	delay_us(2);
	IIC_SCL = 0;
	delay_us(2);
}
void IICNack(void)
{
	SDA_OUT();
	IIC_SCL = 1;
	IIC_SDA = 1;
	delay_us(2);
	IIC_SCL = 0;
	delay_us(2);
}
uint8_t IICReadOneByte(uint8_t a)
{
	uint8_t ret = 0;
	uint8_t index = 0;
	SDA_IN();
	for(index=0;index<8;index++)
	{
		IIC_SCL = 0;
		delay_us(2);
		IIC_SCL = 1;
		ret <<= 1;
		if(READ_SDA)ret++;
		delay_us(2);
	}
	if(!ack)
		IICNack();
	else
		IICAck();
	return ret;
}

void IICWriteOneByte(uint8_t data)
{
    uint8_t t;   
	SDA_OUT(); 	    
    IIC_SCL=0;//拉低时钟开始数据传输
	delay_us(2); 
    for(t=0;t<8;t++)
    {              
        IIC_SDA=(data&0x80)>>7;
        data<<=1; 	  
		delay_us(2);   
		IIC_SCL=1;
		delay_us(2); 
		IIC_SCL=0;	
		delay_us(2);
    }	 

}

void IICWriteByteToRegister(uint8_t dev_addr,uint8_t reg,uint8_t data)
{
	IICStart();
	IICWriteOneByte(dev_addr);
	IICWaitAck();

	IICWriteOneByte(reg);
	IICWaitAck();


	IICWriteOneByte(data);
	IICWaitAck();


	IICStop();
}

uint8_t IICReadByteFromRegister(uint8_t dev_addr,uint8_t reg)
{
	uint8_t data = 0;
	IICStart();
	IICWriteOneByte(dev_addr);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK for Address\r\n");
		IICStop();
		return data;
	}

	IICWriteOneByte(reg);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK Register %02X\r\n",reg);
		IICStop();
		return data;
	}

	IICStart();
	IICWriteOneByte(dev_addr+1);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK Data \r\n");
		IICStop();
		return data;
	}

	data = IICReadOneByte(nack);
	IICStop();
	return data;
}


uint8_t IICReadBytes(uint8_t dev_addr,uint8_t reg,uint8_t* data,uint8_t len)
{
	uint8_t index = 0;
	if(!data || len<=0)
		return index;
	IICStart();
	IICWriteOneByte(dev_addr);
	
	if(IICWaitAck())
	{
		printf("\r\n NO ACK for Address\r\n");
		IICStop();
		return index;
	}



	IICWriteOneByte(reg);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK Register %02X\r\n",reg);
		IICStop();
		return index;
	}



	IICStart();
	IICWriteOneByte(dev_addr+1);
	if(IICWaitAck())
	{
		printf("\r\n NO ACK Data \r\n");
		IICStop();
		return index;
	}


	for(index=0;index<len;index++)
	{
		
		if(index!=(len-1))
			data[index] = IICReadOneByte(ack);
		else
			data[index] = IICReadOneByte(nack);
	}
	IICStop();
	return index;
}
uint8_t IICWriteBytes(uint8_t dev_addr,uint8_t reg,uint8_t* data,uint8_t len)
{
	uint8_t index = 0;
	if(!data || len<=0)
		return 1;
	IICStart();
	IICWriteOneByte(dev_addr);
	IICWaitAck();


	IICWriteOneByte(reg);
	IICWaitAck();

	for(index=0;index<len;index++)
	{
		IICWriteOneByte(data[index]);
		IICWaitAck();
	}
	IICStop();
	return 0;

}

void IICSetBits(uint8_t dev_addr,uint8_t reg,uint8_t bits)
{
	uint8_t data = 0;
	data = IICReadByteFromRegister(dev_addr,reg);
	data &= ~bits;
	data |= bits;
	
	IICWriteByteToRegister(dev_addr,reg,data);
}

void IICResetBits(uint8_t dev_addr,uint8_t reg,uint8_t bits)
{
	uint8_t data = 0;
	data = IICReadByteFromRegister(dev_addr,reg);

	data &= ~bits;

	IICWriteByteToRegister(dev_addr,reg,data);
}


