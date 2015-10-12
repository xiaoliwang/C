/*
 * 树的双亲孩子表示法
 * author: TomCao
 */
 
#ifndef _BASE_DATA_
#define _BASE_DATA_

#define MAX_TREE_SIZE 100
typedef int TElemType;

typedef struct CTNode
{
  int child;  //没有孩子指向null
  struct CTNode *next;
} *ChildPtr;

typedef struct
{
  TElemType data;
  int parent;  //root使用-1表示双亲
  ChildPtr firstchild;
} CTBox;

typedef struct
{
  CTBox nodes[MAX_TREE_SIZE];
  int r, n;  //根的位置和结点
} CTree;

#endif