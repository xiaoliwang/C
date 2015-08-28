#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
  int i;
  LinkList *L = (LinkList *)malloc(sizeof(LinkList));
  CreateListHead(L, 10);

  LinkList p = *L;
  printf("插入队头创建\n");
  for (i = 0; i < 10; i++) {
	  p = p->next;
	  printf("%d\n", p->data);
  }
  
  CreateListTail(L, 10);
  
  p = *L;
  printf("插入对尾创建\n");
  for (i = 0; i < 10; i++) {
	  p = p->next;
	  printf("%d\n", p->data);
  }
  
  printf("在位置4插入15获取位置4\n");
  ListInsert(L, 4, 15);
  ElemType *pe = (ElemType *) malloc(sizeof(ElemType));
  GetElem(*L, 4, pe);
  printf("%d\n", *pe);
  
  printf("删除位置4后获取\n");
  ListDelete(L, 4, pe);
  printf("%d\n", *pe);
  GetElem(*L, 4, pe);
  printf("%d\n", *pe);
  
  ClearList(L);
  free(L);
  return TRUE;
}