#include "WDOG.h"
#include "main.h"

//WDOG_EN
#define WDOG_EN_PORT	GPIOB
#define WDOG_EN_PIN		GPIO_PIN_1
//WDI
#define WDI_PORT	GPIOB
#define WDI_PIN		GPIO_PIN_2

void WDOG_Port_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitStructure.Pin = WDOG_EN_PIN;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(WDOG_EN_PORT, &GPIO_InitStructure);
  GPIO_InitStructure.Pin = WDI_PIN;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(WDI_PORT, &GPIO_InitStructure);
}

void WDOG_Enable(void)
{
  HAL_GPIO_WritePin(WDOG_EN_PORT,WDOG_EN_PIN,GPIO_PIN_RESET);
}

void WDOG_Disnable(void)
{
  HAL_GPIO_WritePin(WDOG_EN_PORT,WDOG_EN_PIN,GPIO_PIN_SET);
}

void WDOG_Feed(void)
{
  HAL_GPIO_TogglePin(WDI_PORT,WDI_PIN);
}
