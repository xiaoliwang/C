#ifndef _DATA_BASE_
#define _DATA_BASE_

#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType data;
	int cur;
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space);
int Malloc_SLL(StaticLinkList space);
Status ListInsert(StaticLinkList L, int i, ElemType e);
Status ListDelete(StaticLinkList L, int i);
void Free_SSL(StaticLinkList space, int k);
int ListLength(StaticLinkList L);

#endif 