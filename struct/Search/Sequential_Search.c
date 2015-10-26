int Sequential_Search(int *a, int n, int key)
{
  int i;
  for (i = 1; i < n; i++) {
    if (a[i] == key)
      return i;
  }
  return 0;
}

int Sequential_Search2 (int *a, int n, int key)
{
  int i;
  a[0] = key;
  i = n;
  while (a[i] != key)
  {
    i--;
  }
  return i;
}