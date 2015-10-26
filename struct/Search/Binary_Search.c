#include <stdio.h>
#include <stdlib.h>

int Binary_Search(int *a, int n, int key)
{
  int low, high, mid;
  low = 1;
  high = n;
  while (low < high)
  {
    mid = (low + high) / 2;
    if (key < a[mid])
      high = mid - 1;
    else if (key > a[mid])
      low = mid + 1;
    else
      return mid;
  }
  return 0;
}

//插值查找比较适合均匀分布
int Binary_Search2(int *a, int n, int key)
{
  int low, high, mid;
  low = 1;
  high = n;
  while (low < high)
  {
    mid = low + (int)(high - 1 - low) * ((float)key - a[low]) / (a[high - 1] - a[low]);
    if (key < a[mid])
      high = mid - 1;
    else if (key > a[mid])
      low = mid + 1;
    else
      return mid;
  }
  return 0;
}

int *F = NULL;
int Fibonacci_Search(int *a, int n, int key)
{
  int low, high, mid, i, k;
  int *b;
  //初始化Fibonacci函数
  if (!F) {
    F = (int *) malloc(100 * sizeof(int));
    F[0] = 0;
    F[1] = 1;
    for (i = 2; i < 100; ++i) {
      F[i] = F[i - 1] + F[i - 2];
    }
  }
  
  low = 1;
  high = n;
  k = 0;
  while (n > F[k])
    k++;
  
  b = (int *) malloc(F[k] * sizeof(int));
  for (i = 0; i < F[k]; i++) {
    if (i < n - 1) {
      b[i] = a[i];
    } else {
      b[i] = a[n - 1];
    }
  }
  
  while (low <= high) {
    mid = low + F[k - 1] - 1;
    if (key < b[mid]) {
      high = mid - 1;
      k = k - 1;
    }
    else if (key > b[mid]) {
      low = mid + 1;
      k = k - 2;
    }
    else {
      if (mid < n - 1)
        return mid;
      return n - 1;
    }
  }
  return 0;
}

int main(int argc, const char* argv[])
{
  int i;
  int n = 11;
  int *a = (int *) malloc(n * sizeof(int));
  for (i = 0; i < n; ++i) {
    a[i] = i;
  }
  int b1 = Binary_Search(a, n, 10);
  printf("%d\n", b1);
  int b2 = Binary_Search2(a, n, 10);
  printf("%d\n", b2);
  int b3 = Fibonacci_Search(a, n, 1);
  printf("%d\n", b3);
}