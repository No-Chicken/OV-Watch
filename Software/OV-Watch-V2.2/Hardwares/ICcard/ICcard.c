#include "ICcard.h"

//UID_SEL
#define UID_SEL_PORT	GPIOA
#define UID_SEL_PIN		GPIO_PIN_6

void ICcard_Port_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitStruct.Pin = UID_SEL_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(UID_SEL_PORT, &GPIO_InitStruct);
}

void ICcard_Select(uint8_t sel)
{
  if(sel)
  {
    HAL_GPIO_WritePin(UID_SEL_PORT,UID_SEL_PIN,GPIO_PIN_SET);
  }
  else
  {
    HAL_GPIO_WritePin(UID_SEL_PORT,UID_SEL_PIN,GPIO_PIN_RESET);
  }
}

