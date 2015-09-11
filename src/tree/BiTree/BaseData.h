#ifndef _BASE_DATA_
#define _BASE_DATA_

typedef char TElemType;

typedef struct BiTNode
{
  TElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree *T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
#endif