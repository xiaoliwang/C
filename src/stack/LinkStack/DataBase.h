#ifndef _DATA_BASE_
#define _DATA_BASE_

#define OK 1
#define ERROR０

typedef int StackNode;
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

#endif