/**
 * 希尔排序
 * 需要了解步长
 */
#include <stdio.h>
#include <stdlib.h>
 
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef struct
{
  int r[MAXSIZE + 1];
  int length;
}SqList;

void ShellSort(SqList *L)
{
  int i, j;
  int increment = L->length;
  do {
    increment = increment/3 + 1;
    for (i = increment + 1; i < L->length; i++) {
      L->r[0] = L->r[i];
      for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j-=increment)
        L->r[j + increment] = L->r[j];
      L->r[j + increment] = L->r[0];
    }
  }while (increment > 1);
}

int main(int argc, const char* argv[])
{
  int i;
  SqList *L;
  L = (SqList *) malloc(sizeof(SqList));
  L->r[0] = 0;
  for (int i = 1; i < 11; i++)
    L->r[i] = 11 - i;
  L->length = 11;
  ShellSort(L);
  for (int i =1; i < 11; i++)
    printf("%d ", L->r[i]);
  puts("");
}