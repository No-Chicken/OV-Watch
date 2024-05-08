#include <math.h>
#include "SPL06_001.h"

#define SPL_CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE()
iic_bus_t SPL_bus = 
{
	.IIC_SDA_PORT = GPIOB,
	.IIC_SCL_PORT = GPIOB,
	.IIC_SDA_PIN  = GPIO_PIN_13,
	.IIC_SCL_PIN  = GPIO_PIN_14,
};

int16_t c0,c1,c01,c11,c20,c21,c30;
int32_t c00,c10;

uint8_t SPL_ReadOneReg(uint8_t addr)
{
	uint8_t dat;
	dat = IIC_Read_One_Byte(&SPL_bus, SPL_CHIP_ADDRESS,addr);
	return dat;
}

void SPL_WriteOneReg(uint8_t addr, uint8_t dat)
{
	IIC_Write_One_Byte(&SPL_bus, SPL_CHIP_ADDRESS,addr,dat);
}

int32_t Get_Traw()
{
	uint8_t buff[3];
	int32_t Traw;
	buff[0] = SPL_ReadOneReg(SPL_TMP_B0);
	buff[1] = SPL_ReadOneReg(SPL_TMP_B1);
	buff[2] = SPL_ReadOneReg(SPL_TMP_B2);
	Traw = buff[2];
	Traw = Traw << 8 | buff[1];
	Traw = Traw << 8 | buff[0];
	if(Traw & (1<<23))
	{Traw |= 0xFF000000;}//24 bit 2´s complement numbers
	return Traw;
}

int32_t Get_Praw()
{
	uint8_t buff[3];
	int32_t Praw;
	buff[0] = SPL_ReadOneReg(SPL_PRS_B0);
	buff[1] = SPL_ReadOneReg(SPL_PRS_B1);
	buff[2] = SPL_ReadOneReg(SPL_PRS_B2);
	Praw = buff[2];
	Praw = Praw << 8 | buff[1];
	Praw = Praw << 8 | buff[0];
	if(Praw & (1<<23))
	{Praw |= 0xFF000000;}//24 bit 2´s complement numbers
	return Praw;
}

int16_t get_c0()
{
	uint8_t buff[2];
	int16_t c0;
	buff[0] = SPL_ReadOneReg(COEF_C0);
	buff[1] = SPL_ReadOneReg(COEF_C0_C1);
	c0 = buff[0];
	c0 = (c0 << 4) | (buff[1] >> 4);
	if(c0 & (1<<11))
	{c0 |= 0xF000;}
	return c0;
}

int16_t get_c1()
{
	uint8_t buff[2];
	int16_t c1;
	buff[0] = SPL_ReadOneReg(COEF_C0_C1);
	buff[1] = SPL_ReadOneReg(COEF_C1);
	c1 = buff[0] & 0x0F;
	c1 = (c1 << 8) | buff[1] ;
	if(c1 & (1<<11))
	{c1 |= 0xF000;}
	return c1;
}

int32_t get_c00()
{
	uint8_t buff[3];
	int32_t c00;
	buff[0] = SPL_ReadOneReg(COEF_C00_H);
	buff[1] = SPL_ReadOneReg(COEF_C00_L);
	buff[2] = SPL_ReadOneReg(COEF_C00_C10);
	c00 = buff[0];
	c00 = c00<<8 | buff[1];
	c00 = (c00<<4) | (buff[2]>>4);
	if(c00 & (1<<19))
	{c00 |= 0xFFF00000;}
	return c00;
}

int32_t get_c10()
{
	uint8_t buff[3];
	int32_t c10;
	buff[0] = SPL_ReadOneReg(COEF_C00_C10);
	buff[1] = SPL_ReadOneReg(COEF_C10_M);
	buff[2] = SPL_ReadOneReg(COEF_C10_L);
	c10 = buff[0] & 0x0F;
	c10 = c10<<8 | buff[1];
	c10 = c10<<8 | buff[2];
	if(c10 & (1<<19))
	{c10 |= 0xFFF00000;}
	return c10;
}

int16_t get_c01()
{
	uint8_t buff[2];
	int32_t c01;
	buff[0] = SPL_ReadOneReg(COEF_C01_H);
	buff[1] = SPL_ReadOneReg(COEF_C01_L);
	c01 = buff[0];
	c01 = c01<<8 | buff[1];
	return c01;
}

int16_t get_c11()
{
	uint8_t buff[2];
	int32_t c11;
	buff[0] = SPL_ReadOneReg(COEF_C11_H);
	buff[1] = SPL_ReadOneReg(COEF_C11_L);
	c11 = buff[0];
	c11 = c11<<8 | buff[1];
	return c11;
}

int16_t get_c20()
{
	uint8_t buff[2];
	int32_t c20;
	buff[0] = SPL_ReadOneReg(COEF_C20_H);
	buff[1] = SPL_ReadOneReg(COEF_C20_L);
	c20 = buff[0];
	c20 = c20<<8 | buff[1];
	return c20;
}

int16_t get_c21()
{
	uint8_t buff[2];
	int32_t c21;
	buff[0] = SPL_ReadOneReg(COEF_C21_H);
	buff[1] = SPL_ReadOneReg(COEF_C21_L);
	c21 = buff[0];
	c21 = c21<<8 | buff[1];
	return c21;
}

int16_t get_c30()
{
	uint8_t buff[2];
	int32_t c30;
	buff[0] = SPL_ReadOneReg(COEF_C30_H);
	buff[1] = SPL_ReadOneReg(COEF_C30_L);
	c30 = buff[0];
	c30 = c30<<8 | buff[1];
	return c30;
}

uint8_t SPL_init()
{
	
	SPL_CLK_ENABLE;
	IICInit(&SPL_bus);
	
	SPL_WriteOneReg(SPL_PRS_CFG, 0x01);		// Pressure 2x oversampling

	SPL_WriteOneReg(SPL_TMP_CFG, 0x80);		// External Temperature 1x oversampling

	SPL_WriteOneReg(SPL_MEAS_CFG, 0x07);	// continuous pressure and temperature measurement

	SPL_WriteOneReg(SPL_CFG_REG, 0x00);		//   
	
	c0 = get_c0();
	c1 = get_c1();
	c01 = get_c01();
	c11 = get_c11(); 
	c20 = get_c20();
	c21 = get_c21();
	c30 = get_c30();
	c00 = get_c00();
	c10 = get_c10();
	
	if(SPL_ReadOneReg(SPL_PRS_CFG)!=0x01 || SPL_ReadOneReg(SPL_CFG_REG)!=0x00)
	{return 1;}//ERRO
	else 
	{return 0;}//SUCCESS
}

void SPL_Sleep()
{
	SPL_WriteOneReg(SPL_MEAS_CFG, 0x00);	// standby
	//SPL_WriteOneReg(SPL_RESET_REG,0x09);//reset
}
	
void SPL_Wakeup()
{
	SPL_WriteOneReg(SPL_MEAS_CFG, 0x07);	// continuous pressure and temperature measurement
	//SPL_init();
}

uint8_t SPL_GetID()
{
	return SPL_ReadOneReg(SPL_ID_REG);
}

float Temperature_Calculate()
{
	float Traw_sc, Tcomp;
	Traw_sc = Get_Traw();
	Traw_sc /= KT;
	Tcomp = c0 * 0.5 + c1 * Traw_sc;
	return Tcomp;
}

float Pressure_Calculate()
{
	float Traw_sc, Praw_sc, Pcomp;
	Traw_sc = Get_Traw();
	Traw_sc /= KT;
	Praw_sc = Get_Praw();
	Praw_sc /= KP;
	Pcomp = (c00) + Praw_sc * ((c10) + Praw_sc * ((c20) + Praw_sc * (c30))) + Traw_sc * (c01) + Traw_sc * Praw_sc * ((c11) + Praw_sc * (c21));
	 
	return Pcomp;
}

float Altitude_Calculate()
{
	float Altitude;
	Altitude = 44330 * (1 - powf(Pressure_Calculate()/101325, 0.1903));
	return Altitude;
}
