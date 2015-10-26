#include <stdlib.h>
#include <stdio.h>
#include "BaseData.h"

int main(int argc, const char *argv[])
{
  int i;
  int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
  BiTree T = NULL;
  for (i = 0; i < 10; i++) {
    InsertBST(&T, a[i]);
  }
  
  BiTree p;
  int status = SearchBST(T, 62, NULL, &p);
  printf("status: %d\n", status);
  printf("p: %d\n", p->data);
  DeleteBST(&T, 62);
  status = SearchBST(T, 62, NULL, &p);
  printf("status: %d\n", status);
  printf("p: %d\n", p->data);
  status = SearchBST(T, 51, NULL, &p);
  printf("status: %d\n", status);
  printf("p: %d\n", p->data);
}