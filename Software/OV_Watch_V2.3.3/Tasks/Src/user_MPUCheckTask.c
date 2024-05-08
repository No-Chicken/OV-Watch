/* Private includes -----------------------------------------------------------*/
//includes
#include "user_MPUCheckTask.h"
#include "user_ScrRenewTask.h"

#include "main.h"
#include "stm32f4xx_it.h"
#include "MPU6050.h"

#include "ui.h"
#include "ui_SetPage.h"
#include "ui_HomePage.h"
#include "ui_MenuPage.h"
#include "ui_SetPage.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t user_MPU_Wrist_State = WRIST_UP;
uint8_t user_MPU_Wrist_EN = 0;

/* Private function prototypes -----------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/

/**
  * @brief  MPU6050 Check the state
  * @param  argument: Not used
  * @retval None
  */
void MPUCheckTask(void *argument)
{
	while(1)
	{
		if(user_MPU_Wrist_EN)
		{
			if(MPU_isHorizontal())
			{
				user_MPU_Wrist_State = WRIST_UP;
			}
			else
			{
				if(user_MPU_Wrist_State == WRIST_UP)
				{
					user_MPU_Wrist_State = WRIST_DOWN;
					if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_HomePage || 
						ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_MenuPage ||
						ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_SetPage)
					{
						uint8_t Stopstr;
						osMessageQueuePut(Stop_MessageQueue, &Stopstr, 0, 1);//sleep
					}
				}
				user_MPU_Wrist_State = WRIST_DOWN;
			}
		}
		osDelay(300);
	}
}


