#ifndef _POWER_H_
#define _POWER_H_

#include "stm32f4xx_hal.h"

#define BAT_CHECK_PORT	GPIOA
#define BAT_CHECK_PIN		GPIO_PIN_1

#define CHARGE_PORT			GPIOA
#define CHARGE_PIN			GPIO_PIN_2

#define POWER_PORT			GPIOA
#define POWER_PIN				GPIO_PIN_3

void Power_Pins_Init(void);
void Power_Enable(void);
void Power_DisEnable(void);
float BatCheck(void);
float BatCheck_8times(void);
uint8_t ChargeCheck(void);
uint8_t PowerCalculate(void);
void Power_Init(void);

#endif
