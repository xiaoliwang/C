#include "BaseData.h"

Status Push(SqStack *S, SElemType e)
{
  if (S->top == MAXSIZE - 1)
	  return ERROR;
  S->data[++S->top] = e;
  return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
  if (S->top == -1)
	  return ERROR;
  *e = S->data[S->top--];
  return OK;
}