#ifndef _BASE_DATA_
#define BASE_DATA_

#define MAX_TREE_SIZE 100

typedef int TElemType;
typedef struct PTNode
{
  TElemType data;
  int parent;
} PTNode;

typedef struct
{
  PTNode nodes[MAX_TREE_SIZE];
  int r, n;
} PTree;

#endif