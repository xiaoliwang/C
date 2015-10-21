#ifndef _BASE_DATA_
#define _BASE_DATA_

#define LH +1
#define EH 0
#define RH -1

#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct BiTNode
{
  int data;
  int bf;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status InsertAVL(BiTree *T, int e, Status *taller);
void Print_Tree(BiTree* T);
#endif