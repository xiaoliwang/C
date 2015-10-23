#include <stdlib.h>
#include <stdio.h>
#include "BaseData.h"

int main(int argc, const char* argv[])
{
  int i;
  int* addr = (int *) malloc(sizeof(int));
  HashTable H;
  InitHashTable(&H);
  for (i = 0; i < 10; i++) {
    InsertHash(&H, i * 2);
  }
  int t = SearchHash(H, 12, addr);
  printf("%d\n", t);
}