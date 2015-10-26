#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BaseData1.h"

int main(int argc, const char *argv[])
{
  int i;
  String T = "8aacabcxd";
  int len = strlen(T);
  int *next = (int *)malloc(len * sizeof(int));
  memset(next, 0, len * sizeof(int));
  get_next(T, next);
  for (i = 0; i < len; i++) {
    printf("%d\n", next[i]);
  }
  return OK;
}

void get_next(String T, int *next)
{
  int i, j;
  i = 1;
  j = 0;
  next[1] = 0;
  int len = (int) (T[0] - '0');
  while (i < len) {
    if (j == 0 || T[i] == T[j]) {
      printf("T[i]%c%d\n", T[i],i);
      printf("T[j]%c%d\n\n", T[j],j);
      next[++i] = ++j;
    } else {
      j = next[j];
    }
  }
}
