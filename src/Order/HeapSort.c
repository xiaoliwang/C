/**
 * 堆排序
 *
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

//生成大顶堆
void HeapAdjust(SqList *L, int s, int m) {
  int temp, j;
  temp = L->r[s];
  for (j = 2 * s; j <= m; j *= 2) {
    if (j < m && L->r[j] < L->r[j+1])
      ++j;
    if (temp >= L->r[j])
      break;
    L->r[s] = L->r[j];
    s = j;
  }
  L->r[s] = temp;
}

void HeapSort(SqList *L)
{
  int i;
  //生成大顶堆
  for (i = L->length/2; i > 1; i--)
    HeapAdjust(L, i, L->length - 1);
  //根据大顶堆排序
  for (i = L->length - 1; i > 1; i--) {
    swap(L, 1, i);
    HeapAdjust(L, 1, i - 1);
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
  HeapSort(L);
  for (int i =1; i < 11; i++)
    printf("%d ", L->r[i]);
  puts("");
}