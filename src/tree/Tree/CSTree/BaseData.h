/*
 * 树的孩子兄弟表示法
 * author: TomCao
 * 该表示法可以将任意一棵复杂数转换为二叉树
 */

#ifndef _BASE_DATA_
#define _BASE_DATA_

typedef int TElemType;

typedef struct CSNode
{
  TElemType data;
  //firstchild 为长子
  //rightsib 为二弟
  struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;

#endif