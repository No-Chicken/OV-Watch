#ifndef __USER_SCRRENEWTASK_H__
#define __USER_SCRRENEWTASK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "PageStack.h"
	
void ScrRenewTask(void *argument);

extern user_Stack_T ScrRenewStack;

#ifdef __cplusplus
}
#endif

#endif

