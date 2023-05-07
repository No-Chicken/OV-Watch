#ifndef __RTC_H__
#define __RTC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

extern RTC_HandleTypeDef hrtc;

void RTC_Init(void);
void RTC_SetTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
void RTC_SetDate(uint8_t year, uint8_t month, uint8_t date);
uint8_t weekday_cluculate(int y,int m,int d,int c);

#ifdef __cplusplus
}
#endif

#endif 

