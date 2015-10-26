#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "BaseData.h"

//前序创建二叉树
void CreateBiThrTree(BiThrTree *T)
{
  TElemType ch;
  scanf("%c", &ch);
  
  if (ch == '#') {
    *T = NULL;
  } else {
    *T = (BiThrTree) malloc(sizeof(BiThrNode));
    memset(*T, 0, sizeof(BiThrNode));
    (*T)->data = ch;
    CreateBiThrTree(&(*T)->lchild);
    CreateBiThrTree(&(*T)->rchild);
  }
}

//设置全局变量，pre指向前一个对象
BiThrTree pre;

//为线索化添加头指针
void InThreading_HEAD(BiThrTree *h, BiThrTree t)
{
  *h = (BiThrTree) malloc(sizeof(BiThrNode));
  
  if (!t) {
    (*h)->lchild = *h;
    (*h)->LTag = Link;
    (*h)->rchild = *h;
    (*h)->RTag = Link;
  } else {
    pre = *h;
    (*h)->lchild = t;
    (*h)->LTag = Link;
    InThreading(t);
    pre->rchild = *h;
    pre->RTag = Thread;
    (*h)->rchild = pre;
  }
}

// 中序遍历进行中序线索化
void InThreading(BiThrTree p)
{  
  if (!pre)
    pre = (BiThrTree) malloc(sizeof(BiThrNode));
  
  if (p) {
    InThreading(p->lchild);
    if (!p->lchild) {
      p->LTag = Thread;
      p->lchild = pre;
    }
    if (!pre->rchild) {
      pre->RTag = Thread;
      pre->rchild = p;
    }
    pre = p;
    InThreading(p->rchild);
  } 
}


//中序线索遍历
int InOrderTraverse_Thr(BiThrTree T)
{
  BiThrTree p = (BiThrTree) malloc(sizeof(BiThrNode));
  p = T->lchild;
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
  return OK;
}
