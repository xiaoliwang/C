#include "DataBase.h"
#include <stdio.h>
#include <stdlib.h>

Status Init(LinkStack *S)
{
	S->top = NULL;
	S->count = 0;
	return OK;
}

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
  *e = S->top->data;
  p = S->top;
  S->top = S->top->next;
  free(p);
  S->count--;
  return OK;
}

Status StackEmpty(LinkStack S)
{
  if (S.count) 
  {
	  return FALSE;
  } else {
	  return TRUE;
  }
}