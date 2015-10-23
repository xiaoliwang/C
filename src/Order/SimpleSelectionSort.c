/**
 * 简单排序
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

void swap(SqList *L, int i, int j)
{
  int temp = L->r[i];
  L->r[i] = L->r[j];
  L->r[j] = temp;
}

void SimpleSelectionSort(SqList *L)
{
  int i, j, min;
  for (i = 1; i < L->length; i++) {
    min = i;
    for (j = i + 1; j <= L->length; j++) {
      if (L->r[min] > L->r[j])
        min = j;
    }
    if (i != min);
      swap(L, i, min);
  }
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
  SimpleSelectionSort(L);
  for (int i =1; i < 11; i++)
    printf("%d ", L->r[i]);
  puts("");
}