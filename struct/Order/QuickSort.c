/*
 * øÏÀŸ≈≈–Ú
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

int Partition(SqList *L, int low, int high) {
  int pivotkey;
  
  int m = low + (high - low) / 2;
  if (L->r[low] > L->r[high])
    swap(L, low, high);
  if (L->r[m] > L->r[high])
    swap(L, high, m);
  if (L->r[m] > L->r[low])
    swap(L, m, low);
  
  pivotkey = L->r[low];
  L->r[0] = pivotkey;
  while (low < high) {
    while (low < high && L->r[high] >= pivotkey)
      high--;
    L->r[low] = L->r[high];
    while(low < high && L->r[low] <= pivotkey)
      low++;
    L->r[high] = L->r[low];
  }
  L->r[low] = L->r[0];
  return low;
}
 
void QSort(SqList *L, int low, int high) {
  int pivot;
  /**if (low < high) {
    pivot = Partition(L, low, high);
    QSort(L, low, pivot - 1);
    QSort(L, pivot + 1, high);
  }*/
  //Œ≤µ›πÈ
  while (low < high) {
    pivot = Partition(L, low, high);
    QSort(L, low, pivot - 1);
    low = pivot + 1;
  }
}

void QuickSort(SqList *L) {
  QSort(L, 1, L->length);
}

int main(int argc, const char* argv[]) {
   int i, n;
  SqList *L = (SqList *) malloc(sizeof(SqList));
  n = 10;
  L->r[0] = 0;
  for (i = 1; i <= n; i++) {
    L->r[i] = 100 - 2 * i;
  }
  L->length = n;
  
  puts("BEGIN");
  for (i = 1; i <= n; i++) {
    printf("%d ", L->r[i]);
  }
  puts("");
  
  QuickSort(L);
  
  puts("The End");
  for (i = 1; i <= n; i++) {
    printf("%d ", L->r[i]);
  }
  puts("");
  return 0;
}