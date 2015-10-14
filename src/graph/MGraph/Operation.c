#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

void CreateMGraph(MGraph *G)
{
  int i, j, k, w;
  puts("输入顶点数和边数(num,num)");
  scanf("%d,%d", &G->numVertexes, &G->numEdges);
  for (i = 0; i < G->numVertexes; i++) {
    puts("请输入顶点的值");
    scanf("%*c%c", &G->vexs[i]);
  }
  //初始化邻接矩阵
  for (i = 0; i< G->numVertexes; i++)
    for (j = 0; j< G->numVertexes; j++)
      G->arc[i][j] = INFINITY;
    
  for (k = 0; k < G->numEdges; k++)
  {
    printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
    scanf("%d,%d,%d", &i, &j, &w);
    G->arc[i][j] = w;
    G->arc[j][i] = G->arc[i][j];
  }
}

/////////深度优先遍历/////////
Boolean visited[MAXVEX];
void DFS(MGraph G, int i)
{
  int j;
  visited[i] = TRUE;
  printf("%c ", G.vexs[i]);
  for (j = 0; j < G.numVertexes; j++)
    if (G.arc[i][j] == 1 && !visited[j])
      DFS(G, j);
}

void DFSTraverse(MGraph G)
{
  int i;
  //初始化所有顶点状态为未访问状态
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = FALSE;
  for (i = 0; i < G.numVertexes; i++)
    //对未访问过的顶点调用DFS，连通图只会执行一次
    if (!visited[i])
      DFS(G, i);
}
