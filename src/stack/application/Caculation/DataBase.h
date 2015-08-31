#ifndef _DATA_BASE_
#define _DATA_BASE_

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char *SElemType;
typedef int Status;

typedef struct StackNode
{
  SElemType data;
  struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
  LinkStackPtr top;
  int count;
}LinkStack;

Status Init(LinkStack *S);
Status Push(LinkStack *S, SElemType e);
Status Pop(LinkStack *S, SElemType *e);
Status StackEmpty(LinkStack S);

#endif