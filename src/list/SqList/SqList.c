#include "Data_Base.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
  SqList *sqlist = (SqList*) malloc(sizeof(SqList));
  InitSqList(sqlist);
  printf("��ʼ���󳤶�Ϊ%d\n", sqlist->length);

  ElemType *pe = (ElemType *) malloc(sizeof(ElemType));
  GetElem(*sqlist, 2, pe);
  printf("��ȡλ��2��Ԫ��ֵΪ%d\n", *pe);
  
  ElemType e = 12;
  ListInsert(sqlist, 2 ,e);
  GetElem(*sqlist, 2, pe);
  printf("����һ��Ԫ�غ�ĳ���%d\n", sqlist->length);
  printf("�����λ��2��Ԫ��ֵΪ%d\n", *pe);
  
  ListDelete(sqlist, 2, e);
  printf("ɾ��λ��2��Ԫ��%d\n", e);
  GetElem(*sqlist, 2, pe);
  printf("��ȡ����λ��2��Ԫ��%d\n", *pe);
  printf("ɾ����ĳ���Ϊ%d\n", sqlist->length);
  
  free(pe);
  free(sqlist);
  return TRUE;
}
