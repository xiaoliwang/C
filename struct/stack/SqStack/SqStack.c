#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

void main(int argc, const char *argv[])
{
  SqStack *sqstack = (SqStack *) malloc(sizeof(SqStack));
  Push(sqstack, 1);
  Push(sqstack, 2);
  SElemType *e = (SElemType *) malloc(sizeof(SElemType));
  Pop(sqstack, e);
  printf("%d\n", *e);
  Pop(sqstack, e);
  printf("%d\n", *e);
}