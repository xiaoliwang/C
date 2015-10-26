#include "DataBase.h"
#include <stdlib.h>
#include <error.h>

#define OVERFLOW -1

Status Init(LinkQueue *Q)
{
  Q->front = (QueuePtr) malloc(sizeof(QNode));
  Q->rear = Q->front;
  return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e)
{
  QueuePtr s = (QueuePtr) malloc(sizeof(QNode));
  if (!s)
    exit(OVERFLOW);
  s->data = e;
  s->next = NULL;
  Q->rear->next = s;
  Q->rear = s;
  return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
  QueuePtr p;
  if (Q->front == Q->rear)
    return ERROR;
  p = Q->front->next;
  *e = p->data;
  Q->front->next = p->next;
  if (Q->rear == p)
    Q->rear = Q->front;
  free(p);
  return OK;
}