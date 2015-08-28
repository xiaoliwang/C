#include "Data_Base.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
  SqList* sqlist = (SqList*) malloc(sizeof(SqList));
  int status = InitSqList(sqlist);
  if (status) {
    printf("%d\n", sqlist->length);
  } else {
    printf("程序有bug");
  }

  ElemType *pe = (ElemType *) malloc(sizeof(ElemType));
  status = GetElem(*sqlist, 2, pe);
  if (status) {
    printf("%d\n", *pe);
  } else {
    printf("GetElem 函数挂了");
  }
  
  ElemType e = 12;
  status = ListInsert(sqlist, 2 ,e);
  if (status) {
    printf("%d\n", *pe);
  } else {
    printf("ListInsert 函数挂了");
  }

  status = GetElem(*sqlist, 2, pe);
  if (status) {
    printf("%d\n", *pe);
  } else {
    printf("程序有bug");
  }

  free(pe);
  free(sqlist);
  return TRUE;
}
