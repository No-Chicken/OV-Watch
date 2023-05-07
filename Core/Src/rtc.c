#include "rtc.h"

RTC_HandleTypeDef hrtc;

void RTC_Init(void)
{
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }
	
	/** Initialize RTC and set the Time and Date
  */
	RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};
	
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	if(HAL_RTCEx_BKUPRead(&hrtc,RTC_BKP_DR0)!=0X5050)//是否第一次配置
  { 
    
		sTime.Hours = 0x11;
		sTime.Minutes = 0x59;
		sTime.Seconds = 0x55;
		sTime.SubSeconds = 0x0;
		if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
		{
			Error_Handler();
		}
		sDate.WeekDay = RTC_WEEKDAY_TUESDAY;
		sDate.Month = RTC_MONTH_NOVEMBER;
		sDate.Date = 0x08;
		sDate.Year = 0x22;
		if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
		{
			Error_Handler();
		}
    HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR0,0X5050);//标记已经初始化过了
  } 
	
}

void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle)
{

  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(rtcHandle->Instance==RTC)
  {
  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* RTC clock enable */
    __HAL_RCC_RTC_ENABLE();
  }
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();

  }
}


uint8_t weekday_cluculate(int y,int m,int d,int c)
{
	int w;
	if (m == 1 || m == 2)
	{y--, m += 12;}
	w = y + y / 4 + c / 4  + 26*(m + 1)/10 + d - 1 - 2 * c;
	while(w<0)
		w+=7;
	w%=7;
	w=(w==0)?7:w;
	return w;
}

void RTC_SetTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	RTC_TimeTypeDef time={0};//不设置为{0}时间就会离谱
	time.Hours=hours;
	time.Minutes=minutes;
	time.Seconds=seconds;
	if (HAL_RTC_SetTime(&hrtc, &time, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
}

void RTC_SetDate(uint8_t year, uint8_t month, uint8_t date)
{
	RTC_DateTypeDef setdate={0};//不设置为{0}时间就会离谱
	setdate.Date=date;
	setdate.Month=month;
	setdate.Year=year;
	
	//culculat the weekday
	setdate.WeekDay = weekday_cluculate(year,month,date,20);
	
	if (HAL_RTC_SetDate(&hrtc, &setdate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
}


