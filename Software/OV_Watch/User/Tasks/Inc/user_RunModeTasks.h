#ifndef __USER_RUNMODETASKS_H__
#define __USER_RUNMODETASKS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "user_TasksInit.h"

void IdleEnterTask(void *argument);
void StopEnterTask(void *argument);

extern uint32_t IdleTimerCount;

#ifdef __cplusplus
}
#endif

#endif

