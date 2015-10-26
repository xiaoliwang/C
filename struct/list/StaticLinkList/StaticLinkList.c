#include <stdio.h>
#include "Data_Base.h"

void main(int argc, const char *argv[])
{
  int i, j, k;
  StaticLinkList list;
  InitList(list);
  for (i = 1; i < 5; i++) {
	  j = 100 + i;
	  ListInsert(list, i, j);
  }
  ListInsert(list, 3, 10);
  for (i = 0; i < 10; i++)
  {
    printf("%d[%d]	",  list[i].cur, list[i].data);
  }
  printf("\n");
  ListDelete(list, 3);

  for (i = 0; i < 10; i++)
  {
    printf("%d[%d]	",  list[i].cur, list[i].data);
  }
  
}