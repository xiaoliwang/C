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
	int top1;
	int top2;
}SqDoubleStack;

Status Push(SqDoubleStack *S, SElemType e, int stackNumber);
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber);

#endif