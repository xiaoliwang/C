#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BaseData.h"

int main(int argc, const char *argv[])
{
  int i = 0;
  String T = "8abcabcxd";
  int *next = (int *)malloc(9 *sizeof(int));
  memset(next, 0, 9 *sizeof(int));
  get_next(T, next);
  for (i = 0; i < 9; i++) {
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
      ++i;
      ++j;
      next[i] = j;
      printf("等于:\ni=%d;j=%d;next[i]=%d\n", i, j, next[i]);
    } else {
      j = next[j];
      printf("不等于:\ni=%d;j=%d;next[i]=%d\n", i, j, next[i]);
    }
  }
}
