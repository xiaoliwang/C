#include "DataBase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<memory.h>

Status Init(LinkStack *S)
{
	S->top = NULL;
	S->count = 0;
	return OK;
}

Status Push(LinkStack *S, SElemType e, int type)
{
  LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
  int len;
  switch (type) {
    case 1:
	  len = (strlen(e) + 1) * sizeof(char);
      s->data = (char *) malloc(len);
	  memcpy(s->data, e, len);
      break;
	case 2:
	  len = sizeof (int);
	  s->data = (int *) malloc(len);
	  memcpy(s->data, e, len);
	  break;
  }
 
  s->next = S->top;
  S->top = s;
  S->count++;
  return OK;
}

Status Pop(LinkStack *S, SElemType *e, int type)
{
  LinkStackPtr p;
  int len;
  if(StackEmpty(*S))
	  return ERROR;
  switch (type){
    case 1:
	  len = (strlen(S->top->data) + 1) * sizeof(char);
      *e = (char *) malloc(len);
	  memcpy(*e, S->top->data, len);
      break;
    case 2:
      len = sizeof(int);
	  *e = (int *) malloc(sizeof(int));
      memcpy(*e, S->top->data, len);
	  break;
  }
 
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
