#ifndef _NODE_
#define _NODE_

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node{
  ElemType data;
  struct Node *next;
} Node;

typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
Status CreateListHead(LinkList *L, int n);
Status CreateListTail(LinkList *L, int n);
Status ClearList(LinkList *L);

#endif 