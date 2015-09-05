//S[0],T[0] 分别为S,T的长度
int Index(String S, String T, int pos)
{
  inti = pos;
  int j = 1;
  while (i <= S[0] && j <= T[0]) 
  {
    if (S[i] == T[j]) {
      ++i;
      ++j;
    } else {
      i = i - j + 2;
      j = 1;
    }
  }
  if (j > T[0])
    return i - T[0];
  else
    return 0;    
}