/**
 * 冒泡排序
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

void BubbleSort0(SqList *L)
{
  int i, j;
  for (i = 1; i < L->length; i++) {
    for (j = i + 1; j < L->length; j++)
      if (L->r[i] > L->r[j])
        swap(L, i, j);
  }
}

//典型冒泡排序
void BubbleSort(SqList *L)
{
  int i, j;
  for (i = 1; i < L->length; i++) {
    for (j = L->length - 1; j >= i; j--)
      if (L->r[j] > L->r[j+1])
        swap(L, j, j+1);
  }
}

//改进冒泡排序
void BubbleSort2(SqList *L)
{
  int i, j;
  Status flag = TRUE;
  for (i = 1; i < L->length && flag; i++) {
    flag = FALSE;
    for (j = L->length - 1; j >= i; j--) {
      if (L->r[j] > L->r[j+1]) {
        swap(L, j, j + 1);
        flag = TRUE;
      }
    }
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
  BubbleSort2(L);
  for (int i =1; i < 11; i++)
    printf("%d ", L->r[i]);
  puts("");
  return 0;
}