/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
#include "usart.h"
/* Private includes ----------------------------------------------------------*/

#include "key.h"

/* USER CODE BEGIN PV */
uint8_t HardInt_receive_str[35];
uint8_t HardInt_uart_flag=0;
uint8_t HardInt_mpu_flag=0;
uint8_t HardInt_Charg_flag=0;

extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef hdma_spi1_tx;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern UART_HandleTypeDef huart1;

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{

  while (1)
  {

  }

}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  
  while (1)
  {
    
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  
  while (1)
  {
   
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{

}


/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line2 interrupt.Charg interrupt
  */
void EXTI2_IRQHandler(void)
{

	HardInt_Charg_flag = 1;

  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);

}

/**
  * @brief This function handles EXTI line4 interrupt.Key2 interrupt
  */
void EXTI4_IRQHandler(void)
{

  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
	
}


/**
  * @brief This function handles EXTI line[9:5] interrupts.Key1 interrupt
  */
void EXTI9_5_IRQHandler(void)
{
	
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);

}

/**
  * @brief This function handles EXTI line[15:10] interrupts.MPU Interrupt
  */
void EXTI15_10_IRQHandler(void)
{
	HardInt_mpu_flag = 1;
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);

}

/**
  * @brief This function handles TIM1 update interrupt and TIM10 global interrupt.Time base(ms)
  */
void TIM1_UP_TIM10_IRQHandler(void)
{
	
  HAL_TIM_IRQHandler(&htim1);

}

/**
  * @brief This function handles DMA2 stream2 global interrupt.
  */
void DMA2_Stream2_IRQHandler(void)
{

  HAL_DMA_IRQHandler(&hdma_spi1_tx);

}

/**
  * @brief This function handles DMA2 stream5 global interrupt.
  */
void DMA2_Stream5_IRQHandler(void)
{

  HAL_DMA_IRQHandler(&hdma_usart1_rx);

}

/**
  * @brief This function handles DMA2 stream7 global interrupt.
  */
void DMA2_Stream7_IRQHandler(void)
{

  HAL_DMA_IRQHandler(&hdma_usart1_tx);

}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
	if(__HAL_UART_GET_FLAG(&huart1,UART_FLAG_IDLE)!=RESET)
	{
    HardInt_uart_flag = 1;
		__HAL_UART_CLEAR_FLAG(&huart1,UART_FLAG_IDLE);
		HAL_UART_DMAStop(&huart1);
    HAL_UART_Receive_DMA(&huart1, HardInt_receive_str, 35);
	}
  HAL_UART_IRQHandler(&huart1);

}

