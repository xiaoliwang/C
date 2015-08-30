#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

void main(int argc, const char *argv[])
{
  SqDoubleStack *sqdoublestack = (SqDoubleStack *) malloc(sizeof(SqDoubleStack));
  Push(sqdoublestack, 1, 1);
  Push(sqdoublestack, 3, 2);
  Push(sqdoublestack, 2, 1);
  SElemType *e = (SElemType *) malloc(sizeof(SElemType));
  Pop(sqdoublestack, e, 1);
  printf("%d\n", *e);
  Pop(sqdoublestack, e, 1);
  printf("%d\n", *e);
  Pop(sqdoublestack, e, 2);
  printf("%d\n", *e);
}