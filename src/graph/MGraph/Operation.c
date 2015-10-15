#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"
#include "Assist.h"

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

/////////深度优先遍历O[n^2]/////////
Boolean visited[MAXVEX];
void DFS(MGraph G, int i)
{
  int j;
  visited[i] = TRUE;
  printf("%c ", G.vexs[i]);
  for (j = 0; j < G.numVertexes; j++)
    if (G.arc[i][j] != INFINITY && !visited[j])
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

/////////广度优化遍历/////////
void BFSTraverse(MGraph G)
{
  int i, j;
  Queue Q;
  //初始化所有顶点状态
  for (i = 0; i < G.numVertexes; i++)
    visited[i] = FALSE;
  InitQueue(&Q);
  for (i = 0; i < G.numVertexes; i++) {
    if (!visited[i]) {
      visited[i] = TRUE;
      printf("%c ", G.vexs[i]);
      EnQueue(&Q, i);
      while(!QueueEmpty(Q)) {
        DeQueue(&Q, &i);
        for (j = 0; j < G.numVertexes; j++) {
          if (G.arc[i][j] != INFINITY && !visited[j]) {
            visited[j] = TRUE;
            printf("%c ", G.vexs[j]);
            EnQueue(&Q, j);
          }
        }
      }
    }
  }
}

/////////Prim算法生成最小生成树O[n^2]/////////
void MiniSpanTree_Prim(MGraph G)
{
  int min, i, j, k;
  int adjvex[MAXVEX];
  int lowcost[MAXVEX];
  lowcost[0] = 0; //表示v0被纳入最小生成树，值为0表示已经纳入
  adjvex[0] = 0; //假设从v0开始计算
  
  for (i = 1; i < G.numVertexes; i++) {
    lowcost[i] = G.arc[0][i];
    adjvex[i] = 0;
  }
  
  for (i = 1; i < G.numVertexes; i++) {
    min = INFINITY;
    j = 1; k = 0;
    while(j < G.numVertexes) {
      if (lowcost[j] != 0 && lowcost[j] < min) {
        min = lowcost[j];
        k = j;
      }
      j++;
    }
    printf("(%d,%d)\n", adjvex[k], k);
    lowcost[k] = 0;
    for (j = 1; j < G.numVertexes; j++) {
      if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
        lowcost[j] = G.arc[k][j];
        adjvex[j] = k;
      }
    }
  }
}

/////////Kruskal算法生成最小生成树O[eloge]/////////
void MiniSpanTree_Kruskal(MGraph G)
{
  int i, j, k, n, m;
  Edge edge;
  Edge edges[MAXEDGE];
  int parent[MAXVEX];
  k = 0;
  for (i = 0; i < G.numVertexes; i++) {
    for (j = i; j < G.numVertexes; j++) {
      if (G.arc[i][j] < INFINITY) {
        edges[k].begin = i;
        edges[k].end = j;
        edges[k].weight = G.arc[i][j];
        k++;
      }
    }
  }
  
  for (i = 0; i < G.numEdges; i++) {
    for (j = i; j < G.numEdges; j ++) {
      if (edges[i].weight > edges[j].weight) {
        edge = edges[i];
        edges[i] = edges[j];
        edges[j] = edge;
      }
    }
  }
  
  //此处省略初始化edges函数
  for (i = 0; i < G.numVertexes; i++)
    parent[i] = 0;
  for (i = 0; i < G.numEdges; i++) {
    n = Find(parent, edges[i].begin);
    m = Find(parent, edges[i].end);
    if (n != m) {
      parent[n] = m;
      printf("(%d, %d) %d ",edges[i].begin, edges[i].end, edges[i].weight);
    }
  }
}

int Find(int *parent, int f) {
  while (parent[f] > 0)
    f = parent[f];
  return f;
}
