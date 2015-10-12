/*
 * 树的双亲表示法
 * author: TomCao
 */
  
#ifndef _BASE_DATA_
#define _BASE_DATA_

#define MAX_TREE_SIZE 100

typedef int TElemType;
typedef struct PTNode
{
  TElemType data;
  int parent; //双亲位置，root使用-1表示
} PTNode;

typedef struct
{
  PTNode nodes[MAX_TREE_SIZE];
  int r, n;  //根的位置和结点数
} PTree;

#endif