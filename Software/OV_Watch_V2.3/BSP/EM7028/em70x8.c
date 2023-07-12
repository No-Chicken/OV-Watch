#include "em70x8.h"

#define CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE();
iic_bus_t EM7028_bus = 
{
	.IIC_SDA_PORT = GPIOB,
	.IIC_SCL_PORT = GPIOB,
	.IIC_SDA_PIN  = GPIO_PIN_13,
	.IIC_SCL_PIN  = GPIO_PIN_14,
};

uint8_t  EM7028_ReadOneReg(unsigned char RegAddr)
{
	unsigned char dat;
	dat = IIC_Read_One_Byte(&EM7028_bus, EM7028_ADDR, RegAddr);
	return dat;
}

void  EM7028_WriteOneReg(unsigned char RegAddr, unsigned char dat)
{
	IIC_Write_One_Byte(&EM7028_bus, EM7028_ADDR, RegAddr, dat);
}

uint8_t EM7028_Get_ID()
{
	return EM7028_ReadOneReg(ID_REG);
}

uint8_t EM7028_hrs_init()
{
	uint8_t i = 5;
	
	CLK_ENABLE;
	IICInit(&EM7028_bus);
	
	while(EM7028_Get_ID() != 0x36 && i)
	{
		HAL_Delay(100);
		i--;
	}
	if(!i)
	{return 1;}
	EM7028_WriteOneReg(HRS_CFG,0x00);				
	//HRS1_EN, HRS2_dis
	//Heart Beat Measurement is enabled with LED1 turned on and only Red Light Sensor and IR sensor enabled. 
	//When LED1 turned on, the result stores to HRS_DATA0;
	EM7028_WriteOneReg(HRS2_DATA_OFFSET, 0x00);
	//0 offset
	EM7028_WriteOneReg(HRS2_GAIN_CTRL, 0x7f);		
	//HRS2 GAIN = 1
	EM7028_WriteOneReg(HRS1_CTRL, 0x47);
	//HRS1 GAIN =1, HRS1 RANGE =8, HRS1 FREQ = 2.62144MHz (1.5625ms), HRS1 RES = 16 bits, HRS1 mode
	EM7028_WriteOneReg(INT_CTRL, 0x00);
	//LED programmed current = 2.5mA
	return 0;
}

uint8_t EM7028_hrs_Enable()
{
	uint8_t i = 5;
	while(EM7028_Get_ID() != 0x36 && i)
	{
		HAL_Delay(100);
		i--;
	}
	if(!i)
	{return 1;}
	EM7028_WriteOneReg(HRS_CFG,0x08);
	return 0;
}

uint8_t EM7028_hrs_DisEnable()
{
	uint8_t i = 5;
	while(EM7028_Get_ID() != 0x36 && i)
	{
		HAL_Delay(100);
		i--;
	}
	if(!i)
	{return 1;}
	EM7028_WriteOneReg(HRS_CFG,0x00);
	return 0;
}

uint16_t EM7028_Get_HRS1(void)
{
	uint16_t dat;
	dat = EM7028_ReadOneReg(HRS1_DATA0_H);
	dat <<= 8;
	dat |= EM7028_ReadOneReg(HRS1_DATA0_L);
	return dat;
}
