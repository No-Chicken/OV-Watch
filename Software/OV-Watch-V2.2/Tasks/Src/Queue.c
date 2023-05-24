#include "user_Queue.h"
 
void QueueInit(Queue* pq)
{
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
 
	pq->head = pq->tail = NULL;
 
}
 
void QueuePush(Queue* pq, QueueDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail!!!");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
 
	}
 
	//如果队列为空
	if (pq->head ==NULL&& pq->tail==NULL)//说明队列空
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;//the next in head and tail both changed 
		pq->tail = pq->tail->next;
	}
 
}
 
 
void QueuePop(Queue* pq)//队列特性  头删
{
	//一个节点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
 
	else//很多节点
	{
		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
		del = NULL;
	}

}
 
QueueDataType QueueFront(Queue* pq)
{
	return pq->head->data;
}
 
 
QueueDataType QueueBack(Queue* pq)
{
	return pq->tail->data;
}
 
uint8_t QueueEmpty(Queue* pq)
{
	return pq->head == NULL;   //空返回1  有元素0
 
}

uint16_t QueueSize(Queue* pq)
{
	uint16_t n = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		++n;
		cur = cur->next;
	}
 
	return n;
}

