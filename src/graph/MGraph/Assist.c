#include "Assist.h"

void InitQueue(Queue *Q)
{
  Q->front = 0;
  Q->rear = 0;
}

Status EnQueue(Queue *Q, ElemType e)
{
  if ((Q->rear + 1) % MAXSIZE == Q->front)
    return ERROR;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  return OK;
}

Status DeQueue(Queue *Q, ElemType *e)
{
  if (Q->front == Q->rear)
    return ERROR;
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
  return OK;
}

Boolean QueueEmpty(Queue Q)
{
  if (Q.rear == Q.front)
    return OK;
  else
    return ERROR;
}