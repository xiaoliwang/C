#ifndef _Base_Data_
#define _Base_Data_

#define MAX_TREE_SIZE 100
typedef int TElemType;

typedef struct CSNode
{
  TElemType data;
  struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;

#endif