/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "user_RunModeTasks.h"
#include "ui_HomePage.h"
#include "ui_ChargPage.h"
#include "main.h"
#include "HWDataAccess.h"
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
		// 硬件中断发生
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

