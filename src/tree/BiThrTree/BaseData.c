#ifndef _BASE_DATA_
#define _BADE_DATA_

typedef enum {Link, Thread} PointerTag; //Link��ʾָ�����Һ��ӵ�ָ�룬 Thread��ʾָ��ǰ�����̵�����
typedef struct BiThrNode
{
  TElemType data;
  struct BiThrNode *lchild, *rchild;
  PointerTag LTag;
  PointerTag RTag;
} BiThrNode, *BiThrTree'

#endif