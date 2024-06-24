#ifndef HWDATAACCESS_H
#define HWDATAACCESS_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************
 *  Description
 ***************************/
/**
 *  这是用于UI层获取硬件层的数据的中间层
 *  如果不需要用则全部将下方所有的
 *  Hardware Define全部变成0
 *
 */

/***************************
 *  Hardware Define
 ***************************/
/**
 *  if not use, just set 0
 *  if just test ui, no hardware, just all set 0
 *
 */

#define HW_USE_RTC 1
#define HW_USE_IMU 1

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

//IMU
uint8_t HW_MPU_Wrist_is_Enabled(void);
void HW_MPU_Wrist_Enable(void);
void HW_MPU_Wrist_Disable(void);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
