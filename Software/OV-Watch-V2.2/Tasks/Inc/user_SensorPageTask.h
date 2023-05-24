#ifndef __USER_SENSORPAGETASK_H__
#define __USER_SENSORPAGETASK_H__

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t user_HR_timecount;
extern uint8_t user_HR_TimeFlag;

void SensorDataRenewTask(void *argument);
void HRDataRenewTask(void *argument);


#ifdef __cplusplus
}
#endif

#endif

