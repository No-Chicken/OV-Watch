/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "main.h"
#include "lvgl.h"
#include "ui_HomePage.h"
#include "ui_MenuPage.h"
#include "ui_GameSelectPage.h"
#include "ui_SetPage.h"
#include "ui_OffTimePage.h"
#include "ui_DateTimeSetPage.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
extern osMessageQueueId_t Key_MessageQueue;
user_Stack_T ScrRenewStack;

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  Screen renew task
  * @param  argument: Not used
  * @retval None
  */
void ScrRenewTask(void *argument)
{
	uint8_t keystr=0;
	user_Stack_Push(&ScrRenewStack,(long long int)&ui_HomePage);
	while(1)
	{
		if(osMessageQueueGet(Key_MessageQueue,&keystr,NULL,0)==osOK)
		{
			//key1 pressed
			if(keystr == 1)
			{
				user_Stack_Pop(&ScrRenewStack);
				if(user_Stack_isEmpty(&ScrRenewStack))
				{
					ui_MenuPage_screen_init();
					lv_scr_load_anim(ui_MenuPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
					user_Stack_Push(&ScrRenewStack,(long long int)&ui_HomePage);
					user_Stack_Push(&ScrRenewStack,(long long int)&ui_MenuPage);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_HomePage)
				{
					ui_HomePage_screen_init();
					lv_scr_load_anim(ui_HomePage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_MenuPage)
				{
					ui_MenuPage_screen_init();
					lv_scr_load_anim(ui_MenuPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
					//HR sensor sleep
    			EM7028_hrs_DisEnable();
    			//sensor sleep
		    	LSM303DLH_Sleep();
					//SPL_Sleep();
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_GameSelectPage)
				{
					ui_GameSelectPage_screen_init();
					lv_scr_load_anim(ui_GameSelectPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_SetPage)
				{
					ui_SetPage_screen_init();
					lv_scr_load_anim(ui_SetPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_DateTimeSetPage)
				{
					ui_DateTimeSetPage_screen_init();
					lv_scr_load_anim(ui_DateTimeSetPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
				}
				
			}	
			//key2 pressed
			else if(keystr == 2)
			{
				user_Stack_Clear(&ScrRenewStack);
				ui_HomePage_screen_init();
				lv_scr_load_anim(ui_HomePage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
				user_Stack_Push(&ScrRenewStack,(long long int)&ui_HomePage);
				//HR sensor sleep
  			EM7028_hrs_DisEnable();
  			//sensor sleep
	    	LSM303DLH_Sleep();
				//SPL_Sleep();
			}
		}	
		osDelay(10);
	}
}
