#ifndef _BASE_DATA_
#define _BASE_DATA_

#define FALSE 0
#define TRUE 1

typedef int Status;

typedef struct BiTNode
{
  int data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p);
Status InsertBST(BiTree *T, int key);
Status DeleteBST(BiTree *T, int key);
Status Delete(BiTree *p);
#endif