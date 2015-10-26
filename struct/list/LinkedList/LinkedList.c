#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
  int i;
  LinkList *L = (LinkList *)malloc(sizeof(LinkList));
  CreateListHead(L, 10);

  LinkList p = *L;
  printf("�����ͷ����\n");
  for (i = 0; i < 10; i++) {
	  p = p->next;
	  printf("%d\n", p->data);
  }
  
  CreateListTail(L, 10);
  
  p = *L;
  printf("�����β����\n");
  for (i = 0; i < 10; i++) {
	  p = p->next;
	  printf("%d\n", p->data);
  }
  
  printf("��λ��4����15��ȡλ��4\n");
  ListInsert(L, 4, 15);
  ElemType *pe = (ElemType *) malloc(sizeof(ElemType));
  GetElem(*L, 4, pe);
  printf("%d\n", *pe);
  
  printf("ɾ��λ��4���ȡ\n");
  ListDelete(L, 4, pe);
  printf("%d\n", *pe);
  GetElem(*L, 4, pe);
  printf("%d\n", *pe);
  
  ClearList(L);
  free(L);
  return TRUE;
}