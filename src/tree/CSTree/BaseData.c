#ifndef _BASE_DATA_
#define _BASE_DATA_

#define MAX_TREE_SIZE 100
typedef int TElemType;

typedef struct CSNode
{
  TElemType data;
  struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;

#endif