/* Private includes -----------------------------------------------------------*/
//includes
#include "user_MPUCheckTask.h"

#include "main.h"
#include "stm32f4xx_it.h"
#include "MPU6050.h"

#include "ui.h"
#include "ui_SetPage.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t user_MPU_Wrist_State = WRIST_UP;
uint8_t user_MPU_Wrist_EN = 0;

/* Private function prototypes -----------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/

/**
  * @brief  enter the stop mode and resume
  * @param  argument: Not used
  * @retval None
  */
void MPUCheckTask(void *argument)
{
	while(1)
	{
		if(user_MPU_Wrist_EN)
		{
			if(HardInt_mpu_flag)
			{
				HardInt_mpu_flag = 0;
				if(MPU_isHorizontal())
				{
					user_MPU_Wrist_State = WRIST_UP;
				}
				else
				{
					if(user_MPU_Wrist_State == WRIST_UP)
					{
						user_MPU_Wrist_State = WRIST_DOWN;
						uint8_t Stopstr;
						osMessageQueuePut(Stop_MessageQueue, &Stopstr, 0, 1);//sleep
					}
				}
			}
		}
		osDelay(500);
	}
}


