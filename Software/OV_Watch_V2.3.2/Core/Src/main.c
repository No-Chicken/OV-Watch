/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "adc.h"
#include "dma.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32f4xx_it.h"
#include "delay.h"
#include "lcd.h"
#include "lcd_init.h"
#include "CST816.h"
#include "SPL06_001.h"
#include "LSM303.h"
#include "mpu6050.h"
#include "AHT21.h"
#include "em70x8.h"
#include "BL24C02.h"
#include "DataSave.h"
#include "power.h"
#include "key.h"
#include "KT6328.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
//gui
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "ui.h"

//Wrist setting
#include "user_MPUCheckTask.h"
//APP SYS setting
#include "ui_DateTimeSetPage.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t Sensor_LSM303_Erro=1;
uint8_t Sensor_AHT21_Erro=1;
uint8_t Sensor_SPL_Erro=1;
uint8_t Sensor_EM_Erro=1;
uint8_t Sensor_MPU_Erro=1;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_RTC_Init();
  MX_SPI1_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	//RTC Wake
	if(HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 2000, RTC_WAKEUPCLOCK_RTCCLK_DIV16) != HAL_OK)
  {
    Error_Handler();
  }
	//usart start
	HAL_UART_Receive_DMA(&huart1,(uint8_t*)HardInt_receive_str,25);
	__HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);
	
	//PWM Start
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
	
	//sys delay
	delay_init();
	//wait
	delay_ms(1000);
	
	//power
	Power_Init();
	
	//key
	Key_Port_Init();
	
	//sensor
	uint8_t num = 3;
	while(num && Sensor_AHT21_Erro)
	{
		num--;
		Sensor_AHT21_Erro = AHT_Init();
	}
	
	num = 3;
	while(num && Sensor_LSM303_Erro)
	{
		num--;
		Sensor_LSM303_Erro = LSM303DLH_Init();
	}
	if(!Sensor_LSM303_Erro)
		LSM303DLH_Sleep();
	
	num = 3;
	while(num && Sensor_SPL_Erro)
	{
		num--;
		Sensor_SPL_Erro = SPL_init();
	}
	
	num = 3;
	while(num && Sensor_MPU_Erro)
	{
		num--;
		Sensor_MPU_Erro = mpu_dmp_init();
		//Sensor_MPU_Erro = MPU_Init();
	}
	
	num = 3;
	while(num && Sensor_EM_Erro)
	{
		num--;
		Sensor_EM_Erro = EM7028_hrs_init();
	}
	if(!Sensor_EM_Erro)
		EM7028_hrs_DisEnable();
		
	
		
	//EEPROM
	EEPROM_Init();
	if(!EEPROM_Check())
	{
		uint8_t recbuf[3];
		SettingGet(recbuf,0x10,2);
		if((recbuf[0]!=0 && recbuf[0]!=1) || (recbuf[1]!=0 && recbuf[1]!=1))
		{
			user_MPU_Wrist_EN = 0;
			user_APPSy_EN = 0;
		}
		else
		{
			user_MPU_Wrist_EN = recbuf[0];
			user_APPSy_EN = recbuf[1];
		}
		
		RTC_DateTypeDef nowdate;
		HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);
		
		SettingGet(recbuf,0x20,3);
		if(recbuf[0] == nowdate.Date)
		{
			uint16_t steps=0;
			steps = recbuf[1]&0x00ff;
			steps = steps<<8 | recbuf[2];
			if(!Sensor_MPU_Erro)
				dmp_set_pedometer_step_count((unsigned long)steps);
		}
	}
	
	
	
	//BLE
	KT6328_GPIO_Init();
	KT6328_Enable();
	
	//set the KT6328 BautRate 9600
	//default is 115200
	//printf("AT+CT01\r\n");
	
	//touch
	CST816_GPIO_Init();
	CST816_RESET();
	
	//lcd
	LCD_Init();
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK);
	delay_ms(10);
	LCD_Set_Light(50);
	LCD_ShowString(72,LCD_H/2,(uint8_t*)"Welcome!",WHITE,BLACK,24,0);//12*6,16*8,24*12,32*16
	LCD_ShowString(42,LCD_H/2+48,(uint8_t*)"OV-Watch V2.3",WHITE,BLACK,24,0);
	delay_ms(1000);
	LCD_Fill(0,LCD_H/2-24,LCD_W,LCD_H/2+49,BLACK);

	//LVGL init
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	ui_init();
	
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
