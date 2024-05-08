#include "PageStack.h"

uint8_t user_Stack_Push(user_Stack_T* stack, StackData_t datain)
{
  if(stack->Top_Point == MAX_DEPTH - 1)
	{return -1;}
	
	stack->Data[stack->Top_Point++] = datain;
	return 0;
}

uint8_t user_Stack_Pop(user_Stack_T* stack)
{
  if(stack->Top_Point == 0)
	{return -1;}
	
	stack->Data[--stack->Top_Point] = NULL;
	return 0;
}

uint8_t user_Stack_isEmpty(user_Stack_T* stack)
{
	if(stack->Top_Point == 0)
	{return 1;} 

	return 0;
}

void user_Stack_Clear(user_Stack_T* stack)
{
	while(!user_Stack_isEmpty(stack))
	{
		user_Stack_Pop(stack);
	}
}

