/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define LED_Test_Pin GPIO_PIN_13
#define LED_Test_GPIO_Port GPIOC

void GPIO_Init(void);

#ifdef __cplusplus
}
#endif
#endif

