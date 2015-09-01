#include <stdio.h>
#include <stdlib.h>
#include "DataBase.h"

int main(int argc, const char* argv[])
{
  int i;
  SqQueue *sq = (SqQueue *) malloc(sizeof(SqQueue));
  InitQueue(sq);
  for (i = 0; i < 10; i++) {
	  EnQueue(sq, i);
  }
  QElemType *e = (QElemType *) malloc(sizeof(QElemType));
  for (i = 0; i < 10; i++) {
    DeQueue(sq, e);
    printf("%d\n", *e);
  }
  free(e);
  free(sq);
}