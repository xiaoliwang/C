/**
 * πÈ≤¢≈≈–Ú(µ›πÈ)
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

void MSort(int SR[], int TR1[], int s, int t) {
  int m;
  int TR2[t];
  memset(TR2, 0, sizeof(int) * t);
  
  if (s == t) {
    TR1[s] = SR[s];
  } else {
    m = (s + t) / 2;
    MSort(SR, TR2, s, m);
    MSort(SR, TR2, m + 1, t);
    Merge(TR2, TR1, s, m, t);
  }
}

void MergeSort(SqList *L) {
  MSort(L->r, L->r, 1, L->length); 
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
  
  puts("begin");
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