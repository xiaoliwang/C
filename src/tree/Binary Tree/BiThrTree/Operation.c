#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

//前序创建线索树
void CreateBiThrTree(BiThrTree *T)
{
  TElemType ch;
  scanf("%c", &ch);
  if (ch == '#') {
    *T = NULL;
  } else {
    *T = (BiThrTree) malloc(sizeof(BiThrNode));
    (*T)->data = ch;
    CreateBiThrTree(&(*T)->lchild);
    CreateBiThrTree(&(*T)->rchild);
  }
}

//设置全局变量
BiThrTree pre; 

// 中序遍历进行中序线索化
void InThreading(BiThrTree p)
{
  pre = (BiThrTree) malloc(sizeof(BiThrNode));
  if (p) {
    InThreading(p->lchild);
    if (!p->lchild) {
      p->LTag = Thread;
      p->lchild = pre;
    }
    if (!p->rchild) {
      pre->RTag = Thread;
      pre->rchild = p;
    }
    pre = p;
    InThreading(p->rchild);
  }
}

//中序遍历
void InOrderTraverse_Thr(BiThrTree T)
{
  BiThrTree p = (BiThrTree) malloc(sizeof(BiThrNode));
  p = T->lchild;
  puts("he");
  while (p != T) {
    while (p->LTag == Link)
      p = p->lchild;
    printf("%c", p->data);
    while (p->RTag == Thread && p->rchild != T) {
      p = p->rchild;
      printf("%c", p->data);
    }
    p = p->rchild;
  }
}
