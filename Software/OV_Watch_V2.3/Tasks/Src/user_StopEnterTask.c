/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_MPUCheckTask.h"

#include "ui.h"
#include "ui_HomePage.h"
#include "ui_OffTimePage.h"

#include "main.h"
#include "stm32f4xx_it.h"
#include "lcd_init.h"
#include "power.h"
#include "CST816.h"
#include "MPU6050.h"
#include "key.h"
#include "WDOG.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint16_t IdleTimerCount = 0;

/* Private function prototypes -----------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/

/**
	* @brief  Enter Idle state
  * @param  argument: Not used
  * @retval None
  */
void IdleEnterTask(void *argument)
{
	uint8_t Idlestr=0;
	uint8_t IdleBreakstr=0;
	while(1)
	{
		//light get dark
		if(osMessageQueueGet(Idle_MessageQueue,&Idlestr,NULL,1)==osOK)
		{
			LCD_Set_Light(5);
		}
		//resume light if light got dark and idle state breaked by key pressing or screen touching
		if(osMessageQueueGet(IdleBreak_MessageQueue,&IdleBreakstr,NULL,1)==osOK)
		{
			IdleTimerCount = 0;
			LCD_Set_Light(ui_LightSliderValue);
		}
		osDelay(10);
	}
}

/**
  * @brief  enter the stop mode and resume
  * @param  argument: Not used
  * @retval None
  */
void StopEnterTask(void *argument)
{
	uint8_t Stopstr;
	uint8_t BatDetStr;
	while(1)
	{
		if(osMessageQueueGet(Stop_MessageQueue,&Stopstr,NULL,0)==osOK)
		{
			
			/***** your sleep operations *****/
			sleep:
			IdleTimerCount = 0;

			//sensors
			
			//lcd
			LCD_RES_Clr();
			LCD_Close_Light();
			//touch
			CST816_Sleep();
			/*********************************/
			
			vTaskSuspendAll();
			//Disnable Watch Dog
			WDOG_Disnable();
			//systick int
			CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
			//enter stop mode
			HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON,PWR_STOPENTRY_WFI);
			
			//resume run mode and reset the sysclk
			SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
			HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq));
			SystemClock_Config();
			xTaskResumeAll();
			
			/***** your wakeup operations *****/
			//MPU Check
			if(HardInt_mpu_flag)
			{
				HardInt_mpu_flag = 0;
				if(!KEY1 || KEY2 || ChargeCheck())
				{
					//resume, go on
				}
				else if(user_MPU_Wrist_EN)
				{
					if(MPU_isHorizontal() && user_MPU_Wrist_State == WRIST_DOWN)
					{
						user_MPU_Wrist_State = WRIST_UP;
						//resume
					}
					else if(!MPU_isHorizontal() && user_MPU_Wrist_State == WRIST_UP)
					{
						user_MPU_Wrist_State = WRIST_DOWN;
						IdleTimerCount  = 0;
						goto sleep;
					}
					else 
					{
						IdleTimerCount  = 0;
						goto sleep;
					}
				}
				else
				{
					IdleTimerCount  = 0;
					goto sleep;
				}
			}
			//sensors
			
			//lcd
			LCD_Init();
			LCD_Set_Light(ui_LightSliderValue);
			//touch
			CST816_Wakeup();
			//check if is Charging
			if(ChargeCheck())
			{HardInt_Charg_flag = 1;}
			//send the bat detect message
			osMessageQueuePut(BatDet_MessageQueue, &BatDetStr, 0, 1);
			delay_ms(500);
			/**********************************/
			
		}
		osDelay(10);
	}
}

void IdleTimerCallback(void *argument)
{
	IdleTimerCount+=1;
	//make sure the LightOffTime<TurnOffTime
	if(IdleTimerCount == (ui_LTimeValue*10))
	{
		uint8_t Idlestr=0;
		//send the Light off message
		osMessageQueuePut(Idle_MessageQueue, &Idlestr, 0, 1);
		
	}
	if(IdleTimerCount == (ui_TTimeValue*10))
	{
		uint8_t Stopstr = 1;
		IdleTimerCount  = 0;
		//send the Stop message
		osMessageQueuePut(Stop_MessageQueue, &Stopstr, 0, 1);
	}
}


