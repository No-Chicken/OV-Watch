#ifndef PAGESTACK_H
#define PAGESTACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../ui.h"

#define MAX_DEPTH 6

typedef long long int StackData_t;

typedef struct
{
    StackData_t Data[MAX_DEPTH];
    uint8_t Top_Point;

}user_Stack_T;

uint8_t user_Stack_Push(user_Stack_T* stack, StackData_t datain);
uint8_t user_Stack_Pop(user_Stack_T* stack);
uint8_t user_Stack_isEmpty(user_Stack_T* stack);
void user_Stack_Clear(user_Stack_T* stack);

user_Stack_T ScrRenewStack;

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
