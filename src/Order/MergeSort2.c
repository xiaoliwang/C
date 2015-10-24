/**
 * πÈ≤¢≈≈–Ú(∑«µ›πÈ)
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
 
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef struct
{
  int r[MAXSIZE + 1];
  int length;
}SqList;

void Merge(int SR[], int TR[], int i, int m, int n) {
  int j, k, l;
 
  for (j = m + 1, k = i; i <= m && j <= n; k++) {
    if (SR[i] < SR[j])
      TR[k] = SR[i++];
    else
      TR[k] = SR[j++];
  }
  
  if (i <= m)
    for (l = 1; l <= m - i + 1; l++)
      TR[k + l - 1] = SR[i + l - 1];
    
  if (j <= n) {
    for (l = 1; l <= n - j + 1; l++)
      TR[k + l - 1] =SR[j + l - 1];
  }
}

void MergePass(int SR[], int TR[], int s, int n) {
  int i = 1;
  int j;
  while (i <= n - 2 * s + 1) {
    Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
    i = i + 2 * s;
  }
  if (i < n - s + 1)
    Merge(SR, TR, i, i + s -1, n);
  else
    for (j = i; j <= n; j++)
      TR[j] = SR[j];
}

void MergeSort(SqList *L) {
  int *TR = (int *) malloc(L->length * sizeof(int));
  int k = 1;
  while (k < L->length) {
    MergePass(L->r, TR, k, L->length);
    k = 2 * k;
    MergePass(TR, L->r, k, L->length);
    k = 2 * k;
  }
}

int main(int argc, const char* argv[])
{
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
  
  MergeSort(L);
  
  puts("The End");
  for (i = 1; i <= n; i++) {
    printf("%d ", L->r[i]);
  }
  puts("");
  return 0;
}