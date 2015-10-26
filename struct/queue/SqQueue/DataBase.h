#ifndef _DATABASE_
#define _DATABASE_

#define MAXSIZE 11
#define OK 1
#define ERROR 0

typedef int QElemType;
typedef int Status;

typedef struct
{
  QElemType data[MAXSIZE];
  int front;
  int rear;
}SqQueue;

Status InitQueue(SqQueue *Q);
Status EnQueue(SqQueue *Q, QElemType e);
Status DeQueue(SqQueue *Q, QElemType *e);
#endif