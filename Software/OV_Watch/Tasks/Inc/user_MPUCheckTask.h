#ifndef __USER_MPUCHECKTASK_H__
#define __USER_MPUCHECKTASK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "user_TasksInit.h"


#define WRIST_UP 1
#define WRIST_DOWN 0
extern uint8_t user_MPU_Wrist_State;
extern uint8_t user_MPU_Wrist_EN;

void MPUCheckTask(void *argument);

	
#ifdef __cplusplus
}
#endif

#endif

