#ifndef _SPL06_001_H_
#define _SPL06_001_H_

#include "iic_hal.h"

//your own settings
//see the table in the datasheet
#define KT							524288.0		
#define KP							1572864.0

#define SPL_CHIP_ID					0X10
#define SPL_CHIP_ADDRESS		0x76
//register map
//pressure data
#define SPL_PRS_B2					0x00
#define SPL_PRS_B1					0x01
#define SPL_PRS_B0					0x02
//temperature data
#define SPL_TMP_B2					0x03
#define SPL_TMP_B1					0x04
#define SPL_TMP_B0					0x05
//Config
#define SPL_PRS_CFG					0x06
#define SPL_TMP_CFG					0x07
#define SPL_MEAS_CFG				0x08
#define SPL_CFG_REG					0x09
#define SPL_INT_STS					0x0A
#define SPL_FIFO_STS				0x0B
#define SPL_RESET_REG				0x0C
//ID
#define SPL_ID_REG					0x0D
//Calibration Coefficients
#define COEF_C0						0x10
#define COEF_C0_C1				0x11
#define COEF_C1						0x12
#define COEF_C00_H				0x13
#define COEF_C00_L				0x14
#define COEF_C00_C10			0x15
#define COEF_C10_M				0x16
#define COEF_C10_L				0x17
#define COEF_C01_H				0x18
#define COEF_C01_L				0x19
#define COEF_C11_H				0x1A
#define COEF_C11_L				0x1B
#define COEF_C20_H				0x1C
#define COEF_C20_L				0x1D
#define COEF_C21_H				0x1E
#define COEF_C21_L				0x1F
#define COEF_C30_H				0x20
#define COEF_C30_L				0x21

//pressure config(6:4)
#define PM_RATE1				0x00		//1   measurements pr sec
#define PM_RATE2				0x01		//2   measurements pr sec
#define PM_RATE3				0x02		//4   measurements pr sec
#define PM_RATE4				0x03		//8   measurements pr sec
#define PM_RATE5				0x04		//16  measurements pr sec
#define PM_RATE6				0x05		//32  measurements pr sec
#define PM_RATE7				0x06		//64  measurements pr sec
#define PM_RATE8				0x07		//128 measurements pr sec
//pressure config(3:0)
//oversampling rate
#define	PM_PRC1					0x00		//single
#define	PM_PRC2					0x01		//2   times (low power) 
#define	PM_PRC3					0x02		//4   times 
#define	PM_PRC4					0x03		//8   times (standard)
#define	PM_PRC5					0x04		//16  times	(need a bit shift in CFG_CFG)
#define	PM_PRC6					0x05		//32  times	(need a bit shift in CFG_CFG)
#define	PM_PRC7					0x06		//64  times	(high precision)(need a bit shift in CFG_CFG)
#define	PM_PRC8					0x07		//128 times	(need a bit shift in CFG_CFG)
//temperature config
//extrenal or internal(7)
#define TMP_EXT 0x01
#define TMP_INT 0x00
//Temperature measurement rate(6:4)
#define TMP_RATE1				0x00		//1   measurements pr sec
#define TMP_RATE2				0x01		//2   measurements pr sec
#define TMP_RATE3				0x02		//4   measurements pr sec
#define TMP_RATE4				0x03		//8   measurements pr sec
#define TMP_RATE5				0x04		//16  measurements pr sec
#define TMP_RATE6				0x05		//32  measurements pr sec
#define TMP_RATE7				0x06		//64  measurements pr sec
#define TMP_RATE8				0x07		//128 measurements pr sec
//Temperature oversampling(3:0)
#define	TMP_PRC1				0x00		//single
#define	TMP_PRC2				0x01		//2   times
#define	TMP_PRC3				0x02		//4   times 
#define	TMP_PRC4				0x03		//8   times
#define	TMP_PRC5				0x04		//16  times
#define	TMP_PRC6				0x05		//32  times
#define	TMP_PRC7				0x06		//64  times
#define	TMP_PRC8				0x07		//128 times

uint8_t SPL_ReadOneReg(uint8_t addr);
void SPL_WriteOneReg(uint8_t addr, uint8_t dat);

uint8_t SPL_init(void);
void SPL_Sleep(void);
void SPL_Wakeup(void);
uint8_t SPL_GetID(void);

float Altitude_Calculate(void);
float Pressure_Calculate(void);
float Temperature_Calculate(void);

#endif
