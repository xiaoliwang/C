#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
Status GetElem(LinkList L, int i, ElemType *e){
  int j;
  LinkList p;
  p = L->next;
  j = 1;
  while (p && j < i){
    p = p->next;
    ++j;
  }
  if (!p || j > i)
    return ERROR;
  *e = p->data;
  return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e){
  int j;
  LinkList p, s;
  p = *L;
  j = 1;
  while (p && j < i)
  {
    p = p->next;
    ++j;
  }
  if(!p || j > i)
    return ERROR;
  s = (LinkList)malloc(sizeof(Node));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e){
  int j;
  LinkList p, q;
  p = *L;
  j = 1;
  while (p->next && j < i){
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i)
    return ERROR;
  q = p->next;
  p->next = q->next;
  *e = q->data;
  free(q);
  return OK;
}

/*插入队头创建*/
Status CreateListHead(LinkList *L, int n){
  LinkList p;
  int i;
  *L = (LinkList) malloc(sizeof(Node));
  (*L)->next = NULL;
  for (i = 0; i < n; i++)
  {
    p = (LinkList) malloc(sizeof(Node));
    p->data = i;
    p->next = (*L)->next;
    (*L)->next = p;
  } 
}

/*插入对尾创建*/
Status CreateListTail(LinkList *L, int n){
  LinkList p,r;
  int i;
  *L = (LinkList) malloc(sizeof(Node));
  r = *L;
  for (i = 0; i < n; i++)
  {
    p = (LinkList) malloc(sizeof(Node));
    p->data = i;
    r->next = p;
    r = p;
  }
  r->next = NULL;
}

Status ClearList(LinkList *L){
  LinkList p,q;
  p = (*L)->next;
  while (p)
  {
    q = p->next;
    free(p);
    p = q;
  }
  (*L)->next = NULL;
  return OK;
}