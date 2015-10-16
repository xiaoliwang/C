#include <stdlib.h>
#include <stdio.h>
#include "BaseData.h"

void CreateTopo(GraphAdjList GL)
{
  int i, n, m, w;
  EdgeNode *e;
  puts("请输入点的数目和边的数目");
  scanf("%d,%d", &GL->numVertexes, &GL->numEdges);
  for (i = 0; i < GL->numVertexes; ++i) {
    puts("输入点的值：");
    scanf("%*c%c", &GL->adjList[i].data);
    GL->adjList[i].firstedge = NULL;
    GL->adjList[i].in = 0;
  }
  for (i = 0; i < GL->numEdges; ++i) {
    puts("输入边的端点及权");
    scanf("%d,%d,%d", &n, &m, &w);
    e = (EdgeNode *) malloc(sizeof(EdgeNode));
    e->adjvex = m;
    e->weight = w;
    e->next = GL->adjList[n].firstedge;
    ++GL->adjList[m].in;
    GL->adjList[n].firstedge = e;
  }
}

/////////拓扑排序O[n+e]/////////
Status TopologicalSort(GraphAdjList GL)
{
  EdgeNode *e;
  int i, k, gettop;
  int top = 0;
  int count = 0;
  int *stack;
  int *etv, *ltv; //事件最早时间及最迟时间
  int *stack2; //序列栈
  int top2;
  stack = (int *) malloc(GL->numVertexes * sizeof(int));
  for (i = 0; i < GL->numVertexes; i++)
    if (GL->adjList[i].in == 0)
      stack[++top] = i;
  /*  
  top2 = 0;
  etv = (int *) malloc(GL->numVertexes * sizeof(int));
  for (i = 0; i < GL->numVertexes i++)
    etv[i] = 0;
  stack2 = (int *) malloc(GL->numVertexes * sizeof(int));
  */
  while (top != 0) {
    gettop = stack[top--];
    printf("%c -> ", GL->adjList[gettop].data);
    count++;
    //stack2[++top2] = gettop;
    
    for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
      k = e->adjvex;
      if (!(--GL->adjList[k].in))
        stack[++top] = k;
      //if ((etv[gettop] + e->weight) > etv[k])
       // etv[k] = etv[gettop] + e->weight;
    }
  }
  if (count < GL->numVertexes)
    return ERROR;
  return OK;
}

/////////关键路径/////////
void CriticalPath(GraphAdjList GL)
{
  EdgeNode *e;
  int i, gettop, k, j;
  int ete, lte;
  TopologicalSort(GL);
}