/**
 * 线索二叉树（Threaded Binary Tree）
 * author: TomCao
 * 对二叉树进行线索化
 */
#ifndef _BASE_DATA_
#define _BADE_DATA_
#define OK 1

typedef enum {Link, Thread} PointerTag; //Link表示指向左右孩子的指针， Thread表示指向前驱或后继的线索
typedef int TElemType;

typedef struct BiThrNode
{
  TElemType data;
  struct BiThrNode *lchild, *rchild;
  PointerTag LTag;
  PointerTag RTag;
} BiThrNode, *BiThrTree;

void CreateBiThrTree(BiThrTree *T);
void InThreading(BiThrTree p);
void InOrderTraverse_Thr(BiThrTree T);

#endif