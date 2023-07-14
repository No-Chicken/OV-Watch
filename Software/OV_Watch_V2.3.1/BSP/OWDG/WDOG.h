#ifndef __WDOG_H__
#define __WDOG_H__

#ifdef __cplusplus
extern "C" {
#endif

void WDOG_Port_Init(void);
void WDOG_Enable(void);
void WDOG_Disnable(void);
void WDOG_Feed(void);


#ifdef __cplusplus
}
#endif
#endif

