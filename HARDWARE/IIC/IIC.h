#ifndef __IIC_H__
#define __IIC_H__
#include <type.h>
#include <stm32f10x.h>
#define ack   1
#define nack  0
   	   		   
////驱动接口，GPIO模拟IIC

#define SDA_IN()  {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=0x80000000;}
#define SDA_OUT() {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=0x30000000;}


//IO操作函数	 
#define IIC_SCL    PBout(6) //SCL
#define IIC_SDA    PBout(7) //SDA	 
#define READ_SDA   PBin(7)  //输入SDA 

extern void IICInit(void);
extern void IICStart(void);
extern void IICStop(void);
extern uint8_t IICWaitAck(void);
extern void IICAck(void);
extern void IICNack(void);
extern uint8_t IICReadOneByte(uint8_t a);
extern void IICWriteOneByte(uint8_t data);
extern uint8_t IICReadBytes(uint8_t dev_addr,uint8_t reg,uint8_t* data,uint8_t len);
extern uint8_t IICWriteBytes(uint8_t dev_addr,uint8_t reg,uint8_t* data,uint8_t len);
extern void IICWriteByteToRegister(uint8_t dev_addr,uint8_t reg,uint8_t data);
extern uint8_t IICReadByteFromRegister(uint8_t dev_addr,uint8_t reg);

#endif


