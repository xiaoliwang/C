#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

void CreateMGraph(MGraph *G)
{
  int i, j, k, w;
  puts("���붥�����ͱ���(num,num)");
  scanf("%d,%d", &G->numVertexes, &G->numEdges);
  for (i = 0; i < G->numVertexes; i++)
    scanf(&G->vexs[i]);
  //��ʼ���ڽӾ���
  for (i = 0; i< G->numVertexes; i++)
    for (j = 0; j< G->numVertexes; j++)
      G->arc[i][j] = INFINITY;
    
  for (k = 0; k < G->numEdges; k++)
  {
    printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
    scanf("%d,%d,%d", &i, &j, &w);
    G->arc[i][j] = w;
    G->arc[j][i] = G->arc[i][j];
  }
}