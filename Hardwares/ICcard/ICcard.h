#ifndef __ICCARD_H__
#define __ICCARD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void ICcard_Port_Init(void);
void ICcard_Select(uint8_t sel);

#ifdef __cplusplus
}
#endif
#endif 

