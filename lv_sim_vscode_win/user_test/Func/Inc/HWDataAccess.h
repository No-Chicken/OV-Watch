/**
 *  @addtogroup  Hareware Middle Layer
 *  @brief       Hardware Middle Layer, to access data from BSP and STM32 HAL Library
 *
 *  @{
 *      @file       HWDataAccess.h
 *      @brief      middleware, for UI and APP Layer to get the hardware data
 *      @details    you can enable or disable in .h file.
 * 					        加这个文件就是为了方便UI移植, 比如你要把工程移植到PC仿真,
 *   				        直接把MidFunc中的文件和UI文件都复制过去,
 * 					        然后直接把.h文件中的HW_USE_HARDWARE变成0就行了.
 */


#ifndef HWDATAACCESS_H
#define HWDATAACCESS_H

#ifdef __cplusplus
extern "C" {
#endif


/***************************
 *  Hardware Define
 ***************************/
/**
 *  if not use, just set 0
 *
 *
 *  if just test ui, no hardware, just set HW_USE_HARDWARE 0
 *
 */

#define HW_USE_HARDWARE 0

#if HW_USE_HARDWARE
  #define HW_USE_RTC 1
  #define HW_USE_IMU 1
  #define HW_USE_BLE 1
  #define HW_USE_BAT 1
  #define HW_USE_LCD 1
#endif

/***************************
 *  Includes
 ***************************/

#include "stdint.h"
#include <stdbool.h>

#if HW_USE_RTC
  #include "rtc.h"
#endif

#if HW_USE_IMU
  #include "user_MPUCheckTask.h"
#endif

#if HW_USE_BLE
  #include "kt6328.h"
#endif

#if HW_USE_BAT
  #include "power.h"
#endif

#if HW_USE_LCD
  #include "lcd_init.h"
#endif

/***************************
 *  TypeDefs
 ***************************/
/**
  * @brief  HW RTC DateTime structure definition
  */
typedef struct
{
    uint8_t WeekDay;    /*!< Specifies the RTC Date WeekDay.
                            This parameter can be a value of @ref RTC_WeekDay_Definitions */

    uint8_t Month;      /*!< Specifies the RTC Date Month (in BCD format).
                            This parameter can be a value of @ref RTC_Month_Date_Definitions */

    uint8_t Date;       /*!< Specifies the RTC Date.
                            This parameter must be a number between Min_Data = 1 and Max_Data = 31 */

    uint8_t Year;       /*!< Specifies the RTC Date Year.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 99 */

    uint8_t Hours;      /*!< Specifies the RTC Time Hour.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 12 if the RTC_HourFormat_12 is selected
                            This parameter must be a number between Min_Data = 0 and Max_Data = 23 if the RTC_HourFormat_24 is selected */

    uint8_t Minutes;    /*!< Specifies the RTC Time Minutes.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 59 */

    uint8_t Seconds;    /*!< Specifies the RTC Time Seconds.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 59 */

} HW_DateTimeTypeDef;


/***************************
 *  PROTOTYPES
 ***************************/

//RTC
void HW_RTC_Get_TimeDate(HW_DateTimeTypeDef * nowdatetime);
void HW_RTC_Set_Date(uint8_t year, uint8_t month, uint8_t date);
void HW_RTC_Set_Time(uint8_t hours, uint8_t minutes, uint8_t seconds);
uint8_t HW_weekday_calculate(uint8_t setyear, uint8_t setmonth, uint8_t setday, uint8_t century);
//IMU
uint8_t HW_MPU_Wrist_is_Enabled(void);
void HW_MPU_Wrist_Enable(void);
void HW_MPU_Wrist_Disable(void);
//BLE
void HW_BLE_Enable(void);
void HW_BLE_Disable(void);
//POW
void HW_Power_Shutdown(void);
//LCD
void HW_LCD_Set_Light(uint8_t dc);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
