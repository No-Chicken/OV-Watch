#ifndef __USER_HOMEPAGETASK_H__
#define __USER_HOMEPAGETASK_H__

#ifdef __cplusplus
extern "C" {
#endif

void TimeRenewTask(void *argument);
void BatDet_Task(void *argument);
void HomePageSensorDataRenew_Task(void *argument);

#ifdef __cplusplus
}
#endif

#endif

