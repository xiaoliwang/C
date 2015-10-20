#ifndef _BASE_DATA_
#define _BASE_DATA_

#define LH +1
#define EH 0
#define RH -1

typedef struct BiTNode
{
  int data;
  int bf;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;



#endif