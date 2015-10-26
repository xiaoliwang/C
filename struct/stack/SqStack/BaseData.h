#ifndef _DATA_BASE_
#define _DATA_BASE_

#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);

#endif