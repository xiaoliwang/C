#include "BaseData.h"
#include <stdio.h>

//前序遍历算法 root left right
void preOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  printf("%c", T->data);
  preOrderTraverse(T->lchild);
  preOrderTraverse(T->rchild);
}

//中序遍历算法 left root right
void InOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  InOrderTraverse(T->lchild);
  printf("%c", T->data);
  InOrderTraverse(T->rchild);
}

//后序遍历算法 left right root
void PostOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  PostOrderTraverse(T->lchild);
  PostOrderTraverse(T->rchild);
  printf("%c", T->data);
}