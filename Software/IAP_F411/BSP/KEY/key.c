#include "key.h"
#include "delay.h"

void Key_Port_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = KEY1_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY1_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
}

uint8_t KeyScan(uint8_t mode)
{
	static uint8_t key_up = 1;
	uint8_t keyvalue=0;
	if(mode) key_up = 1;
	if( key_up && ((!KEY1) || KEY2))
	{
		delay_ms(3);//ensure the key is down
		if(!KEY1) keyvalue = 1;
		else if(KEY2) keyvalue = 2;
		if(keyvalue) key_up = 0;
	}
	else
	{
		delay_ms(3);//ensure the key is up
		if(KEY1 && (!KEY2))
			key_up = 1;
	}
	return keyvalue;
}

