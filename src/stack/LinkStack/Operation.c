#include "DataBase.h"

Status Push(LinkStack *S, SElemType e)
{
  LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
  s->data = e;
  s->next = S->top;
  S->top = s;
  S->count++;
  return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
  LinkStackPtr p;
  if(StackEmpty(*S))
	  return ERROR;
  *e = S->top->data
  p = S->top;
  S->top = S->top->next;
  free(p);
  S->count--;
  return OK;
}