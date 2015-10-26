/*
 * ����˫�׺��ӱ�ʾ��
 * author: TomCao
 */
 
#ifndef _BASE_DATA_
#define _BASE_DATA_

#define MAX_TREE_SIZE 100
typedef int TElemType;

typedef struct CTNode
{
  int child;  //û�к���ָ��null
  struct CTNode *next;
} *ChildPtr;

typedef struct
{
  TElemType data;
  int parent;  //rootʹ��-1��ʾ˫��
  ChildPtr firstchild;
} CTBox;

typedef struct
{
  CTBox nodes[MAX_TREE_SIZE];
  int r, n;  //����λ�úͽ��
} CTree;

#endif