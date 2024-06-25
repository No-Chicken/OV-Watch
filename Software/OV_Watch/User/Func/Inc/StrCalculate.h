#include <stdint.h>

#define NUMBER_TYPE 0
#define SYMBOL_TYPE 1
#define POINT_TYPE 3
#define CAL_DEPTH 5

typedef struct
{
    char strque[10];
    uint8_t Top_Point;

}StrStack_t;

uint8_t strput(StrStack_t * st,char strin);
uint8_t strdel(StrStack_t * st);
uint8_t strstack_isEmpty(StrStack_t* st);
void strclear(StrStack_t* sq);

typedef struct
{
    char datatype;
    float number;
    char symbol;
}caldata_t;

typedef struct
{
    float data[CAL_DEPTH];
    uint8_t Top_Point;

}NumStack_t;

typedef struct
{
    char data[CAL_DEPTH];
    uint8_t Top_Point;

}SymStack_t;

void NumStackClear(NumStack_t* st);
void SymStackClear(SymStack_t* st);
uint8_t NumSymSeparate(char * str, uint8_t strlen, NumStack_t * NumStack, SymStack_t * SymStack);
uint8_t StrCalculate(char * str, NumStack_t * NumStack, SymStack_t * SymStack);
uint8_t isIntNumber(float number);

