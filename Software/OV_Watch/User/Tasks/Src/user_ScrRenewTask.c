/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "main.h"
#include "lvgl.h"
#include "ui_HomePage.h"
#include "ui_MenuPage.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
extern osMessageQueueId_t Key_MessageQueue;

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  Screen renew task
  * @param  argument: Not used
  * @retval None
  */
void ScrRenewTask(void *argument)
{
	uint8_t keystr=0;
	while(1)
	{
		if(osMessageQueueGet(Key_MessageQueue,&keystr,NULL,0)==osOK)
		{
			//key1 pressed
			if(keystr == 1)
			{

				Page_Back();
				if(Page_Get_NowPage()->page_obj == &ui_MenuPage)
				{
					//HR sensor sleep
					EM7028_hrs_DisEnable();
					//sensor sleep
					LSM303DLH_Sleep();
					// SPL_Sleep();
				}
			}
			//key2 pressed
			else if(keystr == 2)
			{
				Page_Back_Bottom();
				//HR sensor sleep
				EM7028_hrs_DisEnable();
  				//sensor sleep
				LSM303DLH_Sleep();
				// SPL_Sleep();
			}
		}
		osDelay(10);
	}
}
