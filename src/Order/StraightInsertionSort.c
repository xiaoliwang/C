/**
 * 直接插入排序
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

void InsertSort(SqList *L)
{
  int i, j, k;
  for (i = 2; i <= L->length; i++) {
    if (L->r[i] < L->r[i - 1]) {
      L->r[0] = L->r[i];
      for(j = i - 1; L->r[j] > L->r[0]; j--) {
        L->r[j + 1] = L->r[j];
      }
      L->r[j + 1] = L->r[0];
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
  InsertSort(L);
  for (int i =1; i < 11; i++)
    printf("%d ", L->r[i]);
  puts("");
}