#include <stdio.h>
#include <stdlib.h>
#include "main.h"

typedef uint8_t QueueDataType;
 
typedef struct QueueNode
{
	struct QueueNode* next;
	QueueDataType data;
 
}QNode;
 
typedef struct Queue
{
	QNode* head;
	QNode* tail;
 
}Queue;
 
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
 
void QueuePush(Queue* pq, QueueDataType x);
void QueuePop(Queue* pq);
 
QueueDataType QueueFront(Queue* pq);
QueueDataType QueueBack(Queue* pq);
 
uint8_t QueueEmpty(Queue* pq);
uint16_t QueueSize(Queue* pq);
