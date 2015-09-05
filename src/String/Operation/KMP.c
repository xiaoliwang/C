#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * String;

void get_next(String T, int *next);

int main(int argc, const char *argv[])
{
  int i = 0;
  String T = "7aaaaabcaaa";
  int *next = (int *)malloc(8 *sizeof(int));
  memset(next, 0, 8 *sizeof(int));
  get_next(T, next);
  for (i = 0; i < 7; i++) {
    printf("%d\n", next[i]);
  }
}

void get_next(String T, int *next)
{
  int i, j;
  i = 1;
  j = 0;
  next[1] = 0;
  int len = T[0] - '0';
  while (i < len){
    if (j == 0 || T[i] == T[j]) {
      ++i;
      ++j;
      next[i] = j;
    } else
      j = next[j];
  }
}
