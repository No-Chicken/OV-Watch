#ifndef __EM70X8_H__
#define __EM70X8_H__

#include "iic_hal.h"

#define EM7028_ID					0x36
#define EM7028_ADDR				0x24

#define ID_REG						0x00
#define HRS_CFG						0x01
#define HRS_INT_CTRL			0x02
#define HRS_LT_L					0X03
#define HRS_LT_H					0x04
#define HRS_HT_L					0x05
#define HRS_HT_H					0x06
#define LED_CRT						0x07
#define	HRS2_DATA_OFFSET	0x08
#define HRS2_CTRL					0x09
#define HRS2_GAIN_CTRL		0x0A
#define HRS1_CTRL					0x0D
#define INT_CTRL					0x0E
#define SOFT_RESET				0x0F

#define HRS2_DATA0_L		0x20
#define HRS2_DATA0_H		0x21
#define HRS2_DATA1_L		0x22
#define HRS2_DATA1_H		0x23
#define HRS2_DATA2_L		0x24
#define HRS2_DATA2_H		0x25
#define HRS2_DATA3_L		0x26
#define HRS2_DATA3_H		0x27

#define HRS1_DATA0_L		0x28
#define HRS1_DATA0_H		0x29
#define HRS1_DATA1_L		0x2A
#define HRS1_DATA1_H		0x2B
#define HRS1_DATA2_L		0x2C
#define HRS1_DATA2_H		0x2D
#define HRS1_DATA3_L		0x2E
#define HRS1_DATA3_H		0x2F

uint8_t  EM7028_ReadOneReg(unsigned char RegAddr);
void  EM7028_WriteOneReg(unsigned char RegAddr, unsigned char dat);

uint8_t EM7028_Get_ID(void);
uint8_t EM7028_hrs_init(void);
uint8_t EM7028_hrs_Enable(void);
uint8_t EM7028_hrs_DisEnable(void);
uint16_t EM7028_Get_HRS1(void);

#endif
