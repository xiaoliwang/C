#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BaseData2.h"

int main(int argc, const char *argv[])
{
  String S = "abcdabcdeabcde";
  int len1 = strlen(S);
  String T = "abcde";
  int len2 = strlen(T);
  int index = Index_KMP(S, len1, T, len2, 6);
  printf("%d\n", index);
  return OK;
}

int Index_KMP(String S, int len1, String T, int len2, int pos)
{
  int i = pos;
  int j = 0;
  int *next = (int *) malloc(len2 * sizeof(int));
  memset(next, 0, len2 * sizeof(int));
  get_next(T, len2, next);
  while (i < len1 && j < len2) {
    if (j == 0 || S[i] == T[j]) {
      ++i;
      ++j;
    } else {
      j = next[j] - 1;
    }
  }
  if (j = len2)
    return i - len2;
  else 
    return 0;
}

void get_next(String T, int len, int *next)
{
  int i = 1, j = 0;
  next[0] = 0;
  next[1] = 1;
  len = len - 1;
  while (i < len) {
    if (T[i] == T[j]) {
      next[++i] = ++j + 1;
    } else if (j == 0) {
      next[++i] = 1;
    } else {
      j = 0;
    }
  }
}