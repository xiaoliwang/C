#ifndef _DATA_BASE_
#define _DATA_BASE_

#define MAXSIZE 11
#define OK 1
#define ERROR 0

typedef int Status;
typedef int QElemType;

typedef struct QNode
{
  QElemType data;
  struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
  QueuePtr front, rear;
}LinkQueue;

Status Init(LinkQueue *Q);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);

#endif