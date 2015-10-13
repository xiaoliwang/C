/**
 * ������������Threaded Binary Tree��
 * author: TomCao
 * �Զ���������������
 */
#ifndef _BASE_DATA_
#define _BASE_DATA_

#define OK 1
#define ERROR 0

typedef enum {Link, Thread} PointerTag; //Link��ʾָ�����Һ��ӵ�ָ�룬 Thread��ʾָ��ǰ�����̵�����
typedef char TElemType;

typedef struct BiThrNode
{
  TElemType data;
  struct BiThrNode *lchild, *rchild;
  PointerTag LTag, RTag;
} BiThrNode, *BiThrTree;

void CreateBiThrTree(BiThrTree *T);
void InThreading(BiThrTree p);
void InThreading_HEAD(BiThrTree *h, BiThrTree t);
int InOrderTraverse_Thr(BiThrTree T);
#endif
