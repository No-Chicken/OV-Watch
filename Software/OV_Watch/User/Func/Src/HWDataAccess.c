/**
 *  @addtogroup  Hareware Middle Layer
 *  @brief       Hardware Middle Layer, to access data from BSP and STM32 HAL Library
 *
 *  @{
 *      @file       HWDataAccess.c
 *      @brief      middleware, for UI and APP Layer to get the hardware data
 *      @details    you can enable or disable in .h file.
 * 					加这个文件就是为了方便UI移植, 比如你要把工程移植到PC仿真,
 *   				直接把MidFunc中的文件和UI文件都复制过去,
 * 					然后直接把.h文件中的HW_USE_HARDWARE变成0就行了.
 */

#include "../Inc/HWDataAccess.h"


/***************************
 *  RTC Fucntions
 ***************************/

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
			nowdatetime->WeekDay = weekday_calculate(nowdatetime->Year, nowdatetime->Month, nowdatetime->Date, 20);
            nowdatetime->Hours = nowtime.Hours;
            nowdatetime->Minutes = nowtime.Minutes;
            nowdatetime->Seconds = nowtime.Seconds;
		}
	#else
		nowdatetime->Year = 24;
		nowdatetime->Month = 6;
		nowdatetime->Date = 23;
		nowdatetime->WeekDay = 7;
		nowdatetime->Hours = 11;
		nowdatetime->Minutes = 59;
		nowdatetime->Seconds = 55;
	#endif
}


/**************************************************************************/
/*!
    @brief  to set the RTC Date to hardware

    @param  nowdatetime to storge the data&time

	@return None
*/
/**************************************************************************/
void HW_RTC_Set_Date(uint8_t year, uint8_t month, uint8_t date)
{
	#if HW_USE_RTC
		RTC_SetDate(year, month, date);
	#endif
}

/**************************************************************************/
/*!
    @brief  to set the RTC Date to hardware

    @param  nowdatetime to storge the data&time

	@return None
*/
/**************************************************************************/
void HW_RTC_Set_Time(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	#if HW_USE_RTC
		RTC_SetTime(hours, minutes, seconds);
	#endif
}

/**************************************************************************/
/*!
    @brief  to calculate the weekday

    @param  nowdatetime to storge the data&time

	@return None
*/
/**************************************************************************/
uint8_t HW_weekday_calculate(uint8_t setyear, uint8_t setmonth, uint8_t setday, uint8_t century)
{
	int w;
	if (setmonth == 1 || setmonth == 2)
	{setyear--, setmonth += 12;}
	w = setyear + setyear / 4 + century / 4  + 26*(setmonth + 1)/10 + setday - 1 - 2 * century;
	while(w<0)
		w+=7;
	w%=7;
	w=(w==0)?7:w;
	return w;
}



/***************************
 *  Power Fucntions
 ***************************/
/**************************************************************************/
/*!
    @brief initialize the power

    @param	NULL

	@return NULL
*/
/**************************************************************************/
void HW_Power_Init(void)
{
	#if HW_USE_BAT
		Power_Init();
	#endif
}

/**************************************************************************/
/*!
    @brief shutdown the power

    @param	NULL

	@return NULL
*/
/**************************************************************************/
void HW_Power_Shutdown(void)
{
	#if HW_USE_BAT
		Power_DisEnable();
	#endif
}

/**************************************************************************/
/*!
    @brief	calculate the battery power remain

    @param	NULL

	@return bat power remain
*/
/**************************************************************************/
uint8_t HW_Power_BatCalculate(void)
{
	#if HW_USE_BAT
		return PowerCalculate();
	#endif
		return 0;
}


/***************************
 *  BLE Fucntions
 ***************************/

/**************************************************************************/
/*!
    @brief  enable BLE

    @param	NULL

	@return NULL
*/
/**************************************************************************/
void HW_BLE_Enable(void)
{
	#if HW_USE_BLE
		KT6328_Enable();
	#endif
}


/**************************************************************************/
/*!
    @brief  disable BLE

    @param	NULL

	@return NULL
*/
/**************************************************************************/
void HW_BLE_Disable(void)
{
	#if HW_USE_BLE
		KT6328_Disable();
	#endif
}



/***************************
 *  LCD Fucntions
 ***************************/

/**************************************************************************/
/*!
    @brief set the lcd light

    @param	dc the LCD light

	@return NULL
*/
/**************************************************************************/
void HW_LCD_Set_Light(uint8_t dc)
{
	#if HW_USE_LCD
		LCD_Set_Light(dc);
	#endif
}


/***************************
 *  IMU Fucntions
 ***************************/

/**************************************************************************/
/*!
    @brief  initialize the MPU6050

    @param	NULL

	@return 0 if successful
*/
/**************************************************************************/
uint8_t HW_MPU_Init(void)
{
	#if HW_USE_IMU
		return mpu_dmp_init();
	#endif
	return -1;
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
	#if HW_USE_IMU
		HWInterface.IMU.wrist_is_enabled = 1;
	#endif
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
	#if HW_USE_IMU
		HWInterface.IMU.wrist_is_enabled = 0;
	#endif
}


/**************************************************************************/
/*!
    @brief  get the MPU steps

    @param	NULL

	@return the steps
*/
/**************************************************************************/
uint16_t HW_MPU_Get_Steps(void)
{
	#if HW_USE_IMU
		unsigned long STEPS = 0;
		if(!HWInterface.IMU.ConnectionError)
			dmp_get_pedometer_step_count(&STEPS);
		return (uint16_t)STEPS;
	#endif
		return 0;
}

/**************************************************************************/
/*!
    @brief	set the MPU steps

    @param	NULL

	@return 0 if successful
*/
/**************************************************************************/
int HW_MPU_Set_Steps(unsigned long count)
{
	#if HW_USE_IMU
		if(!HWInterface.IMU.ConnectionError)
			return dmp_set_pedometer_step_count(count);
	#endif
		return -1;
}

/***************************
 *  temprature & humidity Fucntions
 ***************************/

/**************************************************************************/
/*!
    @brief  initialize the AHT21 - temprature & humidity sensor

    @param	NULL

	@return 0 if successful
*/
/**************************************************************************/
uint8_t HW_AHT21_Init(void)
{
	#if HW_USE_AHT21
		return AHT_Init();
	#endif
	return -1;
}

/**************************************************************************/
/*!
    @brief  get the temperature and humidity data for the aht21 sensor

    @param	humi humidity
	@param	temp temperature

	@return NULL
*/
/**************************************************************************/
void HW_AHT21_Get_Humi_Temp(float *humi, float *temp)
{
	#if HW_USE_AHT21
		//temp and humi messure
		if(!HWInterface.AHT21.ConnectionError)
			AHT_Read(humi,temp);
	#endif
}


/***************************
 *  Barometer Fucntions - SPL06-001
 ***************************/

/**************************************************************************/
/*!
    @brief  initialize the SPL06-001 Barometer sensor

    @param	NULL

	@return 0 if successful
*/
/**************************************************************************/
uint8_t HW_Barometer_Init(void)
{
	#if HW_USE_SPL06
		return SPL_init();
	#endif

	return -1;
}


/***************************
 *  E-compass Fucntions - LSM303
 ***************************/

/**************************************************************************/
/*!
    @brief  initialize the lsm303 E-compass sensor

    @param	NULL

	@return 0 if successful
*/
/**************************************************************************/
uint8_t HW_Ecompass_Init(void)
{
	#if HW_USE_LSM303
		return LSM303DLH_Init();
	#endif

	return -1;
}

/**************************************************************************/
/*!
    @brief  SET the lsm303 E-compass sensor to sleep mode

    @param	NULL

	@return NULL
*/
/**************************************************************************/
void HW_Ecompass_Sleep(void)
{
	#if HW_USE_LSM303
		LSM303DLH_Sleep();
	#endif
}

/***************************
 *  heart rate meter Fucntions - em7028
 ***************************/

/**************************************************************************/
/*!
    @brief  initialize the EM7028 heart rate sensor

    @param	NULL

	@return 0 if successful
*/
/**************************************************************************/
uint8_t HW_HRmeter_Init(void)
{
	#if HW_USE_EM7028
		return EM7028_hrs_init();
	#endif

	return -1;

}

/**************************************************************************/
/*!
    @brief  SET the EM7028 HR sensor to sleep mode

    @param	NULL

	@return NULL
*/
/**************************************************************************/
void HW_HRmeter_Sleep(void)
{
	#if HW_USE_EM7028
		EM7028_hrs_DisEnable();
	#endif
}






/***************************
 *  External Variables
 ***************************/
HW_InterfaceTypeDef HWInterface = {
    .RealTimeClock = {
        .GetTimeDate = HW_RTC_Get_TimeDate,
        .SetDate = HW_RTC_Set_Date,
        .SetTime = HW_RTC_Set_Time,
        .CalculateWeekday = HW_weekday_calculate
    },
    .BLE = {
        .Enable = HW_BLE_Enable,
        .Disable = HW_BLE_Disable
    },
    .Power = {
		.power_remain = 0,
		.Init = HW_Power_Init,
        .Shutdown = HW_Power_Shutdown,
		.BatCalculate = HW_Power_BatCalculate
    },
    .LCD = {
        .SetLight = HW_LCD_Set_Light
    },

	.IMU = {
		.ConnectionError = 1,
		.Steps = 0,
		.wrist_is_enabled = 0,
		.wrist_state = WRIST_UP,
		.Init = HW_MPU_Init,
        .WristEnable = HW_MPU_Wrist_Enable,
        .WristDisable = HW_MPU_Wrist_Disable,
        .GetSteps = HW_MPU_Get_Steps,
		.SetSteps = HW_MPU_Set_Steps
    },
	.AHT21 = {
		.ConnectionError = 1,
		.humidity = 67,
		.temperature = 26,
		.Init = HW_AHT21_Init,
		.GetHumiTemp = HW_AHT21_Get_Humi_Temp
	},
	.Barometer = {
		.ConnectionError = 1,
		.altitude = 19,
		.Init = HW_Barometer_Init,
	},
	.Ecompass = {
		.ConnectionError = 1,
		.direction = 45,
		.Init = HW_Ecompass_Init,
		.Sleep = HW_Ecompass_Sleep
	},
	.HR_meter = {
		.ConnectionError = 1,
		.HrRate = 0,
		.SPO2 = 99,
		.Init = HW_HRmeter_Init,
		.Sleep = HW_HRmeter_Sleep
	}
};

