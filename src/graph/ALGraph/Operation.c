#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

void CreateAlGraph(GraphAdjList *G)
{
  int i, j, k;
  EdgeNode *e;
  printf("输入顶点数和边数:\n");
  scanf("%d,%d", &G->numVertexes, &G->numEdges);
  for (i = 0; i < G->numVertexes; i++) {
    scanf(&G->adjList[i].data);
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