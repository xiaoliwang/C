#include "BaseData.h"
#include <stdio.h>

void preOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  printf("%c", T->data);
  preOrderTraverse(T->lchild);
  preOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  InOrderTraverse(T->lchild);
  printf("%c", T->data);
  InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  PostOrderTraverse(T->lchild);
  PostOrderTraverse(T->rchild);
  printf("%c", T->data);
}