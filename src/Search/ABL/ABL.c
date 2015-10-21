#include <stdio.h>
#include "BaseData.h"

int main(int argc, const char* argv[])
{
  int i;
  int a[10] = {3,2,1,4,5,6,8,7,9,0};
  BiTree T = NULL;
  Status taller;
  for (i = 0; i < 10; i++) {
    InsertAVL(&T, a[i], &taller);
  }
  Print_Tree(&T);
}