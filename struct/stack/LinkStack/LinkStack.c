#include <stdio.h>
#include <stdlib.h>
#include "DataBase.h"

void main(int argc, const char *argv[])
{
  LinkStack *S = (LinkStack *)malloc(sizeof(LinkStack));
  Init(S);
  Push(S, 1);
  SElemType *e = (SElemType *)malloc(sizeof(SElemType));
  Pop(S, e);
  printf("%d\n", *e);
}