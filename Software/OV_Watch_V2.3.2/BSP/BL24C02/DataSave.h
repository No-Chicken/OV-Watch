#ifndef __DATASAVE_H__
#define __DATASAVE_H__

#include "BL24C02.h"

void EEPROM_Init(void);
uint8_t EEPROM_Check(void);
uint8_t SettingSave(uint8_t *buf, uint8_t addr, uint8_t lenth);
uint8_t SettingGet(uint8_t *buf, uint8_t addr, uint8_t lenth);

#endif
