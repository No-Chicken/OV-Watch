#ifndef __USER_TASKSINIT_H__
#define __USER_TASKSINIT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "cmsis_os.h"

#define SCRRENEW_DEPTH	5

extern osMessageQueueId_t Key_MessageQueue;
extern osMessageQueueId_t Idle_MessageQueue;
extern osMessageQueueId_t Stop_MessageQueue;
extern osMessageQueueId_t IdleBreak_MessageQueue;
extern osMessageQueueId_t HomeUpdata_MessageQueue;
extern osMessageQueueId_t DataSave_MessageQueue;

void User_Tasks_Init(void);
void TaskTickHook(void);

#ifdef __cplusplus
}
#endif

#endif

