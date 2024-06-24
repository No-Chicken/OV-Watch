/**
 *  @addtogroup  Hareware Middle Layer
 *  @brief       Hardware Middle Layer, to get data from BSP and STM32 HAL Library
 *
 *  @{
 *      @file       HWDataGet.c
 *      @brief      middleware, for UI and APP Layer to get the hardware data
 *      @details    you can enable or disable in .h file.
 * 					加这个文件就是为了方便移植, 比如你要把工程移植到PC仿真,
 *   				直接把MidFunc中的文件和UI文件都复制过去,
 * 					然后直接把.h文件中的HW_USE_XXX都变成0就行了.
 */

#include "HWDataAccess.h"

/**************************************************************************/
/*!
    @brief  to get the real time clock from the hardware

    @param  nowdatetime to storge the data&time

	@return None
*/
/**************************************************************************/
void HW_RTC_Get_TimeDate(HW_DateTimeTypeDef * nowdatetime)
{
	#if HW_USE_RTC
		if (nowdatetime != NULL)
		{
            RTC_DateTypeDef nowdate;
            RTC_TimeTypeDef nowtime;
			HAL_RTC_GetTime(&hrtc, &nowtime, RTC_FORMAT_BIN);
			HAL_RTC_GetDate(&hrtc, &nowdate, RTC_FORMAT_BIN);
            nowdatetime->Year = nowdate.Year;
            nowdatetime->Month = nowdate.Month;
            nowdatetime->Date = nowdate.Date;
			nowdatetime->WeekDay = weekday_cluculate(nowdatetime->Year, nowdatetime->Month, nowdatetime->Date, 20);
            nowdatetime->Hours = nowtime.Hours;
            nowdatetime->Minutes = nowtime.Minutes;
            nowdatetime->Seconds = nowtime.Seconds;
		}
	#else
		nowdatetime->Year = 24;
		nowdatetime->Month = 6;
		nowdatetime->Date = 23;
		nowdatetime->WeekDay = weekday_cluculate(nowdatetime->Year, nowdatetime->Month, nowdatetime->Date, 20);
		nowdatetime->Hours = 11;
		nowdatetime->Minutes = 59;
		nowdatetime->Seconds = 55;
	#endif
}

/**************************************************************************/
/*!
    @brief  check the MPU Wrist wake up is enabled or not

    @param	NULL

	@return true if the Wrist wake up is enabled
*/
/**************************************************************************/
uint8_t HW_MPU_Wrist_is_Enabled(void)
{
	#if HW_USE_IMU
		if(user_MPU_Wrist_EN)
		{
			return true;
		}
	#endif
	return false;
}


/**************************************************************************/
/*!
    @brief  set the MPU Wrist wake up to enabled

    @param	NULL

	@return NULL
*/
/**************************************************************************/
void HW_MPU_Wrist_Enable(void)
{
	user_MPU_Wrist_EN = 1;
}


/**************************************************************************/
/*!
    @brief  set the MPU Wrist wake up to disabled

    @param	NULL

	@return NULL
*/
/**************************************************************************/
void HW_MPU_Wrist_Disable(void)
{
	user_MPU_Wrist_EN = 0;
}
