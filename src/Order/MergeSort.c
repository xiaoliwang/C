/**
 * πÈ≤¢≈≈–Ú
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

void Merge(int SR[], int TR[], int i, int m, int n) {
  int j, k, l;
  printf("%d,%d,%d\n",i ,m ,n);
  
  puts("SR");
  for (int i = 1; i < 11; i++)
    printf("%d ", SR[i]);
  puts("");
  puts("BTR");
  for (int i = 1; i < 11; i++)
    printf("%d ", TR[i]);
  puts("");
  
  for (j = m + 1, k = i; i <= m && j <= n; k++) {
    if (SR[i] < SR[j])
      TR[k] = SR[i++];
    else
      TR[k] = SR[j++];
  }
  if (i <= m) {
    for (l = 1; l <= m - i; l++)
      TR[k + l] = SR[i + l];
  }
  if (j <= n) {
    for (l = 1; l < n - j; l++)
      TR[k + l] =SR[j + l];
  }
  puts("ATR");
  for (int i =1; i < 11; i++)
    printf("%d ", TR[i]);
  puts("");
}

void MSort(int SR[], int TR1[], int s, int t) {
  int m;
  int TR2[MAXSIZE + 1] = {0,0,0,0,0,0,0,0,0,0,0};
  
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
  int i;
  SqList *L;
  L = (SqList *) malloc(sizeof(SqList));
  L->r[0] = 0;
  for (int i = 1; i < 11; i++)
    L->r[i] = 11 - i;
  L->length = 10;
  
  MergeSort(L);
  for (int i =1; i < 11; i++)
    printf("%d ", L->r[i]);
  puts("");
}