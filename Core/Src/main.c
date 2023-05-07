/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "rtc.h"
#include "gpio.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "adc.h"
#include "usart.h"
#include "stm32f4xx_it.h"
//sys
#include "stdio.h"
#include "delay.h"
//hardwares
#include "lcd.h"
#include "lcd_init.h"
#include "CST816.h"
#include "SPL06_001.h"
#include "em70x8.h"
#include "LSM303.h"
#include "mpu6050.h"
#include "AHT21.h"
#include "BL24C02.h"
#include "power.h"
#include "key.h"
#include "HC04.h"
#include "WDOG.h"
#include "ICcard.h"
//gui
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "ui.h"

#include "ui_HomePage.h"
#include "ui_MenuPage.h"
#include "ui_SetPage.h"
#include "ui_OffTimePage.h"
#include "ui_DateTimeSetPage.h"
//tasks
#include "user_TasksInit.h"
#include "user_SensorPageTask.h"

uint8_t Sensor_LSM303_Erro=1;
uint8_t Sensor_AHT21_Erro=1;
uint8_t Sensor_SPL_Erro=1;
uint8_t Sensor_EM_Erro=1;
uint8_t Sensor_MPU_Erro=1;


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  HAL_Init();
	//sysclk
  SystemClock_Config();
	//per
  GPIO_Init();
  RTC_Init();
	DMA_Init();
	SPI1_Init();		//初始化SPI
	ADC1_Init();
	TIM3_Init();		//初始化PWM(LCD_BLK调光)
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);//PWM Start
	USART1_UART_Init();
	HAL_UART_Receive_DMA(&huart1,(uint8_t*)HardInt_receive_str,35);
	__HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);
	//sys delay
	delay_init();
	//key
	Key_Port_Init();
	//HC-04
	HC04_Init();
	HC04_Disable();
	//ICcard
	ICcard_Port_Init();
	ICcard_Select(0);
	//sensors
	Sensor_AHT21_Erro  = AHT_Init();
	Sensor_EM_Erro     = EM7028_hrs_init();
	EM7028_hrs_DisEnable();
	Sensor_LSM303_Erro = LSM303DLH_Init();
	LSM303DLH_Sleep();
	Sensor_MPU_Erro = MPU_Init();
//	Sensor_SPL_Erro    = SPL_init();//power is too high
//	SPL_Sleep();
	//long press 3 sec
	delay_ms(3000);
	//power
	Power_Init();
	//touch
	CST816_GPIO_Init();
	CST816_RESET();
	//lcd
	LCD_Init();
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK);
	delay_ms(10);
	LCD_Set_Light(50);
	LCD_ShowString(72,LCD_H/2,(uint8_t*)"Welcome!",WHITE,BLACK,24,0);//12*6,16*8,24*12,32*16
	LCD_ShowString(42,LCD_H/2+48,(uint8_t*)"OV-Watch V2.2",WHITE,BLACK,24,0);
	delay_ms(1000);
	LCD_Fill(0,LCD_H/2-24,LCD_W,LCD_H/2+49,BLACK);
	
	//LVGL init
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	ui_init();
	
  /* Init scheduler */
	osKernelInitialize();  
  User_Tasks_Init();

  /* Start scheduler */
  osKernelStart();

  while (1)
  {

  }
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
  if (htim->Instance == TIM1) {
    HAL_IncTick();
		user_HR_timecount += 1;
		if(user_HR_timecount == 30)
		{
			user_HR_timecount = 0;
			user_HR_TimeFlag = 1;
		}
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
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
