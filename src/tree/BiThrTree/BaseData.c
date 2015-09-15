#ifndef _BASE_DATA_
#define _BADE_DATA_

typedef enum {Link, Thread} PointerTag; //Link表示指向左右孩子的指针， Thread表示指向前驱或后继的线索
typedef struct BiThrNode
{
  TElemType data;
  struct BiThrNode *lchild, *rchild;
  PointerTag LTag;
  PointerTag RTag;
} BiThrNode, *BiThrTree'

#endif