/**
 * ������������Threaded Binary Tree��
 * author: TomCao
 * �Զ���������������
 */
#ifndef _BASE_DATA_
#define _BADE_DATA_
#define OK 1

typedef enum {Link, Thread} PointerTag; //Link��ʾָ�����Һ��ӵ�ָ�룬 Thread��ʾָ��ǰ�����̵�����
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