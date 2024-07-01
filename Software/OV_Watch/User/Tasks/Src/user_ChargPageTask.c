/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "user_StopEnterTask.h"
#include "ui_HomePage.h"
#include "ui_ChargPage.h"
#include "main.h"
#include "HWDataAccess.h"
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
			if((ChargeCheck()) && (Page_Get_NowPage()->page_obj != &ui_ChargPage))
			{
				Page_Load(&Page_Charg);
			}
			else if((!ChargeCheck()) && (Page_Get_NowPage()->page_obj == &ui_ChargPage))
			{
				Page_Back();
			}
		}
		osDelay(500);
	}
}

void ChargPageRenewTask(void *argument)
{
	while(1)
	{
		if(Page_Get_NowPage()->page_obj == &ui_ChargPage)
		{
			uint8_t value_strbuf[5];

			HW_DateTimeTypeDef DateTime;
    		HW_RTC_Get_TimeDate(&DateTime);

			if(ui_TimeMinuteValue != DateTime.Minutes)
			{
				ui_TimeMinuteValue = DateTime.Minutes;
				sprintf(value_strbuf,"%02d",ui_TimeMinuteValue);
				lv_label_set_text(ui_ChargPagebMinLabel, value_strbuf);
			}

			if(ui_TimeHourValue != DateTime.Hours)
			{
				ui_TimeHourValue = DateTime.Hours;
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
