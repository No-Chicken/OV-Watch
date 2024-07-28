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
  #define HW_USE_RTC    1
  #define HW_USE_BLE    1
  #define HW_USE_BAT    1
  #define HW_USE_LCD    1
  #define HW_USE_IMU    1
  #define HW_USE_AHT21  1
  #define HW_USE_SPL06  1
  #define HW_USE_LSM303 1
  #define HW_USE_EM7028 1
#endif

/***************************
 *  Includes
 ***************************/

#include "stdint.h"
#include <stdbool.h>

#if HW_USE_RTC
  #include "rtc.h"
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

#if HW_USE_IMU
  #include "MPU6050.h"
  #include "inv_mpu.h"
  #include "inv_mpu_dmp_motion_driver.h"
#endif

#if HW_USE_AHT21
  #include "AHT21.h"
#endif

#if HW_USE_SPL06
  #include "SPL06_001.h"
#endif

#if HW_USE_LSM303
  #include "LSM303.h"
#endif

#if HW_USE_EM7028
  #include "em70x8.h"
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


/**
  * @brief  HW RTC Interface definition
  */
typedef struct
{
    void (*GetTimeDate)(HW_DateTimeTypeDef *nowdatetime);
    void (*SetDate)(uint8_t year, uint8_t month, uint8_t date);
    void (*SetTime)(uint8_t hours, uint8_t minutes, uint8_t seconds);
    uint8_t (*CalculateWeekday)(uint8_t setyear, uint8_t setmonth, uint8_t setday, uint8_t century);
} HW_RTC_InterfaceTypeDef;


/**
  * @brief  HW BLE Interface definition
  */
typedef struct
{
    void (*Enable)(void);
    void (*Disable)(void);
} HW_BLE_InterfaceTypeDef;


/**
  * @brief  HW Power Interface definition
  */
typedef struct
{
    uint8_t power_remain;

    void (*Init)(void);
    void (*Shutdown)(void);
    uint8_t (*BatCalculate)(void);
} HW_Power_InterfaceTypeDef;


/**
  * @brief  HW LCD Interface definition
  */
typedef struct
{
    void (*SetLight)(uint8_t dc);
} HW_LCD_InterfaceTypeDef;


/**
  * @brief  HW IMU wrist state defines
  */
#define WRIST_UP 1
#define WRIST_DOWN 0

/**
  * @brief  HW IMU Interface definition
  */
typedef struct
{
    uint8_t ConnectionError;
    uint16_t Steps;
    uint8_t wrist_state;
    uint8_t wrist_is_enabled;

    int (*Init)(void);
    void (*WristEnable)(void);
    void (*WristDisable)(void);
    uint16_t (*GetSteps)(void);
    int (*SetSteps)(unsigned long count);
} HW_IMU_InterfaceTypeDef;


/**
  * @brief  HW AHT21 Interface definition
  */
typedef struct
{
  uint8_t ConnectionError;
  uint8_t temperature;
  uint8_t humidity;
  uint8_t (*Init)(void);
  void (*GetHumiTemp)(float *humi, float *temp);
} HW_AHT21_InterfaceTypeDef;


/**
  * @brief  HW SPL06-001 Barometer Interface definition
  */
typedef struct
{
  uint8_t ConnectionError;
  uint16_t altitude;
  uint8_t (*Init)(void);

} HW_Barometer_InterfaceTypeDef;

/**
  * @brief  HW LSM_303 E-compass Interface definition
  */
typedef struct
{
  uint8_t ConnectionError;
  uint16_t direction;
  uint8_t (*Init)(void);
  void (*Sleep)(void);

} HW_Ecompass_InterfaceTypeDef;

/**
  * @brief  HW EM7028 heart rate meter Interface definition
  */
typedef struct
{
  uint8_t ConnectionError;
  uint8_t HrRate;
  uint8_t SPO2;
  uint8_t (*Init)(void);
  void (*Sleep)(void);

} HW_HRmeter_InterfaceTypeDef;

/**
  * @brief  Hardware Interface structure definition
  */
typedef struct
{
    HW_RTC_InterfaceTypeDef RealTimeClock;
    HW_BLE_InterfaceTypeDef BLE;
    HW_Power_InterfaceTypeDef Power;
    HW_LCD_InterfaceTypeDef LCD;
    HW_IMU_InterfaceTypeDef IMU;
    HW_AHT21_InterfaceTypeDef AHT21;
    HW_Barometer_InterfaceTypeDef Barometer;
    HW_Ecompass_InterfaceTypeDef Ecompass;
    HW_HRmeter_InterfaceTypeDef HR_meter;
} HW_InterfaceTypeDef;



/***************************
 *  PROTOTYPES
 ***************************/


/***************************
 *  External Variables
 ***************************/
extern HW_InterfaceTypeDef HWInterface;



#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
