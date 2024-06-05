/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "user_StopEnterTask.h"
#include "ui_HomePage.h"
#include "ui_ChargPage.h"
#include "main.h"
#include "rtc.h"
#include "power.h"
#include "stm32f4xx_it.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  charg page enter task
  * @param  argument: Not used
  * @retval None
  */
void ChargPageEnterTask(void *argument)
{
	while(1)
	{
		if(HardInt_Charg_flag)
		{
			IdleTimerCount = 0;
			HardInt_Charg_flag = 0;
			if((ChargeCheck()) && (ScrRenewStack.Data[ScrRenewStack.Top_Point-1] != (long long int)&ui_ChargPage))
			{
				ui_ChargPage_screen_init();
				lv_scr_load_anim(ui_ChargPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
				user_Stack_Push(&ScrRenewStack,(long long int)&ui_ChargPage);
			}
			else if((!ChargeCheck()) && (ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_ChargPage))
			{
				ui_HomePage_screen_init();
				lv_scr_load_anim(ui_HomePage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
				user_Stack_Pop(&ScrRenewStack);
				user_Stack_Push(&ScrRenewStack,(long long int)&ui_HomePage);
			}
		}
		osDelay(500);
	}
}

void ChargPageRenewTask(void *argument)
{
	while(1)
	{
		if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_ChargPage)
		{
			uint8_t value_strbuf[5];
			RTC_DateTypeDef nowdate;
			RTC_TimeTypeDef nowtime;
			
			HAL_RTC_GetTime(&hrtc,&nowtime,RTC_FORMAT_BIN);//
			HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);
			
			if(ui_TimeMinuteValue != nowtime.Minutes)
			{
				ui_TimeMinuteValue = nowtime.Minutes;
				sprintf(value_strbuf,"%02d",ui_TimeMinuteValue);
				lv_label_set_text(ui_ChargPagebMinLabel, value_strbuf);
			}
			
			if(ui_TimeHourValue != nowtime.Hours)
			{
				ui_TimeHourValue = nowtime.Hours;
				sprintf(value_strbuf,"%02d",ui_TimeHourValue);
				lv_label_set_text(ui_ChargPagebHourLabel, value_strbuf);
			}
			
			ui_BatArcValue = PowerCalculate();
			if(ui_BatArcValue>0 && ui_BatArcValue<=100)
			{
				lv_arc_set_value(ui_CharPageBatArc, ui_BatArcValue);
				sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
				lv_label_set_text(ui_ChargPageBatNum, value_strbuf);
			}
			else
			{ui_BatArcValue=0;}
			
		}
		osDelay(2000);
	}
}
