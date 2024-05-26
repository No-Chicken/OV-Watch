#include "power.h"
#include "adc.h"
#include "delay.h"

#define INTERNAL_RES 0.128
#define CHARGING_CUR 1

void Power_Pins_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(POWER_PORT, POWER_PIN, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA3 */
  GPIO_InitStruct.Pin = POWER_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(POWER_PORT, &GPIO_InitStruct);

  /*Configure GPIO pin : PA2 */
  GPIO_InitStruct.Pin = CHARGE_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(CHARGE_PORT, &GPIO_InitStruct);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);
	
}

void Power_Enable()
{
	HAL_GPIO_WritePin(POWER_PORT,POWER_PIN,GPIO_PIN_SET);
}

void Power_DisEnable()
{
	HAL_GPIO_WritePin(POWER_PORT,POWER_PIN,GPIO_PIN_RESET);
}

uint8_t ChargeCheck()//1:charging
{
	return HAL_GPIO_ReadPin(CHARGE_PORT,CHARGE_PIN);
}

float BatCheck()
{
	uint16_t dat;
	float BatVoltage;
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1,5);
	dat = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	BatVoltage = dat *2 *3.3 /4096;
	return BatVoltage;
}

float BatCheck_8times()
{
	uint32_t dat=0;
	uint8_t i;
	float BatVoltage;
	for(i=0;i<8;i++)
	{
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1,5);
		dat += HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
		delay_ms(1);
	}
	dat = dat>>3;
	BatVoltage = dat *2 *3.3 /4096;
	return BatVoltage;
}

uint8_t PowerCalculate()
{
	uint8_t power;
	float voltage;
	voltage = BatCheck_8times();
	
	if(ChargeCheck())
	{voltage -= INTERNAL_RES * CHARGING_CUR;}
	
	if((voltage >= 4.2))
	{power = 100;}
	else if(voltage >= 4.06 && voltage <4.2)
	{power = 90;}
	else if(voltage >= 3.98 && voltage <4.06)
	{power = 80;}
	else if(voltage >= 3.92 && voltage <3.98)
	{power = 70;}
	else if(voltage >= 3.87 && voltage <3.92)
	{power = 60;}
	else if(voltage >= 3.82 && voltage <3.87)
	{power = 50;}
	else if(voltage >= 3.79 && voltage <3.82)
	{power = 40;}
	else if(voltage >= 3.77 && voltage <3.79)
	{power = 30;}
	else if(voltage >= 3.74 && voltage <3.77)
	{power = 20;}
	else if(voltage >= 3.68 && voltage <3.74)
	{power = 10;}
	else if(voltage >= 3.45 && voltage <3.68)
	{power = 5;}
	return power;
}

void Power_Init(void)
{
	Power_Pins_Init();
	Power_Enable();
}


