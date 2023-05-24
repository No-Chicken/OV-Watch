#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define PWM_PERIOD 300
#define PWM_COMPARE 0

extern TIM_HandleTypeDef htim3;

void TIM3_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif

#endif

