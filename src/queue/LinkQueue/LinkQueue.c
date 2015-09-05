#include <stdio.h>
#include <stdlib.h>
#include "DataBase.h"

int main(int argc, const char argv[])
{
  int i;
  LinkQueue *Q = (LinkQueue *) malloc(sizeof(LinkQueue));
  Init(Q);
  for (i = 0; i < 10; i++) {
    EnQueue(Q, i);
  }
  
  QElemType *e = (QElemType *) malloc(sizeof(QElemType));
  for (i = 0; i < 10; i++) {
    DeQueue(Q, e);
    printf("%d\n", *e);
  }
  free(e);
  free(Q);
  return OK;
}