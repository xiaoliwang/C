#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"
#include "Assist.h"

void CreateAlGraph(GraphAdjList *G)
{
  int i, j, k;
  EdgeNode *e;
  printf("输入顶点数和边数:\n");
  scanf("%d,%d", &G->numVertexes, &G->numEdges);
  for (i = 0; i < G->numVertexes; i++) {
    printf("请输入顶点的值");
    scanf("%*c%c", &G->adjList[i].data);
    G->adjList[i].firstedge = NULL;
  }
  for (k = 0; k < G->numEdges; k++) {
    printf("输入边(vi,vj)上的顶点序号:\n");
    scanf("%d,%d", &i, &j);
    e = (EdgeNode *) malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->next = G->adjList[i].firstedge;
    G->adjList[i].firstedge = e;
    
    //无向表需要对称再来一次
    e = (EdgeNode *) malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->next = G->adjList[j].firstedge;
    G->adjList[j].firstedge = e;
  }
}

/////////深度优先遍历O[n+e]/////////
Boolean visited[MAXVEX];
void DFS(GraphAdjList GL, int i)
{
  EdgeNode *p;
  visited[i] = TRUE;
  printf("%c ",GL.adjList[i].data);
  p = GL.adjList[i].firstedge;
  while (p)
  {
    if (!visited[p->adjvex])
      DFS(GL, p->adjvex);
    p = p->next;
  }
}

void DFSTraverse(GraphAdjList GL)
{
  int i;
  for (i = 0; i < GL.numVertexes; i++)
    visited[i] = FALSE;
  for (i = 0; i < GL.numVertexes; i++)
    if(!visited[i])
      DFS(GL, i);
}

/////////广度遍历算法/////////
void BFSTraverse(GraphAdjList GL)
{
  int i;
  EdgeNode *p;
  Queue Q;
  for (i = 0; i < GL.numVertexes; i++)
    visited[i] = FALSE;
  InitQueue(&Q);
  for (i = 0; i < GL.numVertexes; i++) {
    if (!visited[i]) {
      visited[i] = TRUE;
      printf("%c ", GL.adjList[i].data);
      EnQueue(&Q, i);
      while (!QueueEmpty(Q)) {
        DeQueue(&Q, &i);
        p = GL.adjList[i].firstedge;
        while (p) {
          if (!visited[p->adjvex]) {
            visited[p->adjvex] = TRUE;
            printf("%c ", GL.adjList[p->adjvex].data);
            EnQueue(&Q, p->adjvex);
          }
          p = p->next;
        }
      }
    }
  }
}