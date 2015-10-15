#ifndef _ASSIST_
#define _ASSIST_

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;
typedef int Boolean;

typedef struct
{
  ElemType data[MAXSIZE];
  int front;
  int rear;
}Queue;

void InitQueue(Queue *Q);
Status EnQueue(Queue *Q, ElemType e);
Status DeQueue(Queue *Q, ElemType *e);
Boolean QueueEmpty(Queue);
#endif