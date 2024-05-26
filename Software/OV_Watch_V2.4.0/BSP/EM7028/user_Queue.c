#include "user_Queue.h"


// 初始化队列
void initQueue(Queue *queue) 
{
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// 判断队列是否为空
bool isQueueEmpty(Queue *queue) 
{
    return queue->size == 0;
}

// 判断队列是否已满
bool isQueueFull(Queue *queue) 
{
    return queue->size == QUEUE_SIZE;
}

// 入队
void enqueue(Queue *queue, unsigned long item) 
{
    if (isQueueFull(queue)) 
    {
        printf("队列已满，无法入队！\n");
        return;
    }
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->data[queue->rear] = item;
    queue->size++;
}

// 出队
uint32_t dequeue(Queue *queue) 
{
    if (isQueueEmpty(queue)) 
    {
        printf("队列为空，无法出队！\n");
        return 0;
    }
    unsigned long item = queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->size--;
    return item;
}

