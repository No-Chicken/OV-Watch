/**
  ******************************************************************************
  * @file    STM32F4xx_IAP/src/flash_if.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    10-October-2011
  * @brief   This file provides all the memory related operation functions.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/** @addtogroup STM32F4xx_IAP
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "flash_if.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static uint32_t GetSector(uint32_t Address);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Unlocks Flash for write access
  * @param  None
  * @retval None
  */
void FLASH_If_Init(void)
{
   HAL_FLASH_Unlock();

  /* Clear pending flags (if any) */
   __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                  FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);

}
/**
  * @brief  This function does an erase of all user flash area
  * @param  StartSector: start of user flash area
  * @retval 0: user flash area successfully erased
  *         1: error occurred
  */
uint32_t FLASH_If_Erase(uint32_t StartSector)
{
    uint32_t UserStartSector;
    uint32_t SectorError;
    FLASH_EraseInitTypeDef pEraseInit;

    /* Unlock the Flash to enable the flash control register access *************/

    /* Get the sector where start the user flash area */
    UserStartSector = GetSector(APPLICATION_ADDRESS);

    pEraseInit.TypeErase = TYPEERASE_SECTORS;
    pEraseInit.Sector = UserStartSector;
    pEraseInit.NbSectors = GetSector(USER_FLASH_END_ADDRESS)-UserStartSector+1 ;
    pEraseInit.VoltageRange = VOLTAGE_RANGE_3;

    if (HAL_FLASHEx_Erase(&pEraseInit, &SectorError) != HAL_OK)
    {
        /* Error occurred while page erase */
        return (1);
    }
    return (0);

}

/**
  * @brief  This function erase one sector
  * @param  StartSector: start of user flash area
  * @retval 0: user flash area successfully erased
  *         1: error occurred
  */
uint32_t FLASH_If_Erase_One_Sector(uint32_t StartSector)
{
    uint32_t SectorError;
    FLASH_EraseInitTypeDef pEraseInit;

    pEraseInit.TypeErase = TYPEERASE_SECTORS;
    pEraseInit.Sector = StartSector;
    pEraseInit.NbSectors = 1 ;
    pEraseInit.VoltageRange = VOLTAGE_RANGE_3;

    if (HAL_FLASHEx_Erase(&pEraseInit, &SectorError) != HAL_OK)
    {
        /* Error occurred while page erase */
        return (1);
    }
    return (0);

}

/**
  * @brief  This function writes a data buffer in flash (data are 32-bit aligned).
  * @note   After writing data buffer, the flash content is checked.
  * @param  FlashAddress: start address for writing data buffer
  * @param  Data: pointer on data buffer
  * @param  DataLength: length of data buffer (unit is 32-bit word)
  * @retval 0: Data successfully written to Flash memory
  *         1: Error occurred while writing data in Flash memory
  *         2: Written Data in flash memory is different from expected one
  */
uint32_t FLASH_If_Write(__IO uint32_t* FlashAddress, uint32_t* Data ,uint32_t DataLength)
{
  uint32_t i = 0;

  for (i = 0; (i < DataLength) && (*FlashAddress <= (USER_FLASH_END_ADDRESS-4)); i++)
  {
    /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
       be done by word */
    FLASH_ProgramWord(*FlashAddress, *(uint32_t*)(Data+i));
     /* Check the written value */
      if (*(uint32_t*)*FlashAddress != *(uint32_t*)(Data+i))
      {
        /* Flash content doesn't match SRAM content */
        return(2);
      }
      /* Increment FLASH destination address */
      *FlashAddress += 4;
  }

  return (0);
}

/**
  * @brief  Returns the write protection status of user flash area.
  * @param  None
  * @retval 0: No write protected sectors inside the user flash area
  *         1: Some sectors inside the user flash area are write protected
  */
uint16_t FLASH_If_GetWriteProtectionStatus(void)
{
  uint32_t UserStartSector = FLASH_SECTOR_1;

  /* Get the sector where start the user flash area */
  UserStartSector = GetSector(APPLICATION_ADDRESS);

  /* Check if there are write protected sectors inside the user flash area */
  if ((*(__IO uint16_t *)(OPTCR_BYTE2_ADDRESS) >> (UserStartSector/8)) == (0xFFF >> (UserStartSector/8)))
  { /* No write protected sectors inside the user flash area */
    return 1;
  }
  else
  { /* Some sectors inside the user flash area are write protected */
    return 0;
  }
}

/**
  * @brief  Disables the write protection of user flash area.
  * @param  None
  * @retval 1: Write Protection successfully disabled
  *         2: Error: Flash write unprotection failed
  */
uint32_t FLASH_If_DisableWriteProtection(void)
{
  __IO uint32_t UserStartSector = FLASH_SECTOR_1, UserWrpSectors = OB_WRP_SECTOR_1;

  /* Get the sector where start the user flash area */
  UserStartSector = GetSector(APPLICATION_ADDRESS);

  /* Mark all sectors inside the user flash area as non protected */
  UserWrpSectors = 0xFFF-((1 << (UserStartSector/8))-1);

  /* Unlock the Option Bytes */

  HAL_FLASH_Unlock();
  /* Disable the write protection for all sectors inside the user flash area */
  FLASH_OB_DisableWRP(UserWrpSectors, FLASH_BANK_1);

  /* Start the Option Bytes programming process. */
  if (HAL_FLASH_OB_Launch( ) != HAL_OK)
  {
    /* Error: Flash write unprotection failed */
    return (2);
  }

  /* Write Protection successfully disabled */
  return (1);
}

/**
  * @brief  Gets the sector of a given address
  * @param  Address: Flash address
  * @retval The sector of a given address
  */

static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
  else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;
  }
  else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
  {
    sector = FLASH_SECTOR_6;
  }
	 else/*(Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_7))*/
  {
    sector = FLASH_SECTOR_7;
  }
//  else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
//  {
//    sector = FLASH_SECTOR_7;
//  }
//  else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
//  {
//    sector = FLASH_SECTOR_8;
//  }
//  else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
//  {
//    sector = FLASH_SECTOR_9;
//  }
//  else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
//  {
//    sector = FLASH_SECTOR_10;
//  }
//  else/*(Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_11))*/
//  {
//    sector = FLASH_SECTOR_11;
//  }
    return sector;
}


HAL_StatusTypeDef FLASH_OB_DisableWRP(uint32_t WRPSector, uint32_t Banks)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_OB_WRP_SECTOR(WRPSector));
  assert_param(IS_FLASH_BANK(Banks));

  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation(50000);

  if(status == HAL_OK)
  {
    *(__IO uint16_t*)OPTCR_BYTE2_ADDRESS |= (uint16_t)WRPSector;
  }

  return status;
}


void FLASH_ProgramWord(uint32_t Address, uint32_t Data)
{
  /* Check the parameters */
  assert_param(IS_FLASH_ADDRESS(Address));

  /* If the previous operation is completed, proceed to program the new data */
  CLEAR_BIT(FLASH->CR, FLASH_CR_PSIZE);
  FLASH->CR |= FLASH_PSIZE_WORD;
  FLASH->CR |= FLASH_CR_PG;

  *(__IO uint32_t*)Address = Data;
}
/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
