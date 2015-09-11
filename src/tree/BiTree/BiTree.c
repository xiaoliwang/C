#include "BaseData.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
  BiTree *T = (BiTree *) malloc(sizeof(BiTree));
  CreateBiTree(T);
  InOrderTraverse(*T);
  printf("\n");
  PostOrderTraverse(*T);
  printf("\n");
}


void CreateBiTree(BiTree *T)
{
  TElemType ch;
  scanf("%c", &ch);
  if (ch == '#') {
    *T = NULL;
  } else {
    *T = (BiTree) malloc(sizeof(BiTNode));
    (*T)->data = ch;
    CreateBiTree(&(*T)->lchild);
    CreateBiTree(&(*T)->rchild);
  }
}