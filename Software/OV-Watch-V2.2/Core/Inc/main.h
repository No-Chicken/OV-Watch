#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f4xx_hal.h"

void Error_Handler(void);

#define LED_Test_Pin GPIO_PIN_13
#define LED_Test_GPIO_Port GPIOC

void SystemClock_Config(void);

extern uint8_t Sensor_LSM303_Erro;
extern uint8_t Sensor_AHT21_Erro;
extern uint8_t Sensor_SPL_Erro;
extern uint8_t Sensor_EM_Erro;

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
