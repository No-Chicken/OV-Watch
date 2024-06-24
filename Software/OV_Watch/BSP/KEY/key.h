#ifndef __KEY_H__
#define __KEY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

//KEY1
#define KEY1_PORT	GPIOA
#define KEY1_PIN	GPIO_PIN_5
#define KEY1 HAL_GPIO_ReadPin(KEY1_PORT,KEY1_PIN)
//KEY_Wake
#define KEY2_PORT	GPIOA
#define KEY2_PIN	GPIO_PIN_4
#define KEY2 HAL_GPIO_ReadPin(KEY2_PORT,KEY2_PIN)
	
void Key_Port_Init(void);
void Key_Interrupt_Callback(void);
uint8_t KeyScan(uint8_t mode);




#ifdef __cplusplus
}
#endif
#endif

