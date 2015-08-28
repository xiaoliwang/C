#include "Data_Base.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
  SqList *sqlist = (SqList*) malloc(sizeof(SqList));
  InitSqList(sqlist);
  printf("初始化后长度为%d\n", sqlist->length);

  ElemType *pe = (ElemType *) malloc(sizeof(ElemType));
  GetElem(*sqlist, 2, pe);
  printf("获取位置2的元素值为%d\n", *pe);
  
  ElemType e = 12;
  ListInsert(sqlist, 2 ,e);
  GetElem(*sqlist, 2, pe);
  printf("插入一个元素后的长度%d\n", sqlist->length);
  printf("插入后位置2的元素值为%d\n", *pe);
  
  ListDelete(sqlist, 2, e);
  printf("删除位置2的元素%d\n", e);
  GetElem(*sqlist, 2, pe);
  printf("获取现在位置2的元素%d\n", *pe);
  printf("删除后的长度为%d\n", sqlist->length);
  
  free(pe);
  free(sqlist);
  return TRUE;
}
