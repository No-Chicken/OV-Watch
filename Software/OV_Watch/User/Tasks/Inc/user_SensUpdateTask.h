#ifndef __USER_SENSUPDATETASK_H__
#define __USER_SENSUPDATETASK_H__

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t user_HR_timecount;

void SensorDataUpdateTask(void *argument);
void HRDataUpdateTask(void *argument);
void MPUCheckTask(void *argument);

#ifdef __cplusplus
}
#endif

#endif

