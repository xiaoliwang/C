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
  
  stack = (int *) malloc(GL->numVertexes * sizeof(int));
  for (i = 0; i < GL->numVertexes; i++)
    if (GL->adjList[i].in == 0)
      stack[++top] = i;
  
  while (top != 0) {
    gettop = stack[top--];
    printf("%c -> ", GL->adjList[gettop].data);
    count++;
    
    for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
      k = e->adjvex;
      if (!(--GL->adjList[k].in))
        stack[++top] = k;
    }
  }
  if (count < GL->numVertexes)
    return ERROR;
  return OK;
}

/////////关键路径/////////
int *etv, *ltv; //事件发生最早时间及最迟时间
int *stack2;
int top2;
/**
 * 关键路径准备信息
 * 获取每个结点最早开始时间
 */
void PreCriticalPath(GraphAdjList GL)
{
  int i, k, gettop;
  EdgeNode *e;
  //初始化栈
  int top1 = 0;
  int *stack1 = (int *) malloc(GL->numVertexes * sizeof(int));
  top2 = 0;
  stack2 = (int *) malloc(GL->numVertexes * sizeof(int));
  //初始化事件最早时间
  etv = (int *) malloc(GL->numVertexes * sizeof(int));
  for (i = 0; i < GL->numVertexes; ++i)
    etv[i] = 0;
  
  for (i = 0; i < GL->numVertexes; ++i)
    if (GL->adjList[i].in == 0)
      stack1[++top1] = i;
  
  while (top1) {
    gettop = stack1[top1--];
    stack2[++top2] = gettop;
    for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
      k = e->adjvex;
      if (!(--GL->adjList[k].in))
        stack1[++top1] = k;
      if ((etv[gettop] + e->weight) > etv[k])
        etv[k] = etv[gettop] + e->weight;
    }
  }
}


void CriticalPath(GraphAdjList GL)
{
  EdgeNode *e;
  int i, gettop, k, j;
  int ete, lte;
  PreCriticalPath(GL);
  
  //初始化ltv，为最晚一个开始时间
  ltv = (int *) malloc(GL->numVertexes * sizeof(int));
  k = etv[stack2[top2--]];
  for (i = 0; i < GL->numVertexes; i++)
    ltv[i] = k;
  
  while (top2 != 0) {
    gettop = stack2[top2--];
    for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
      k = e->adjvex;
      if (ltv[k] - e->weight < ltv[gettop])
        ltv[gettop] = ltv[k] - e->weight;
    }
  }
  for (j = 0; j < GL->numVertexes; j++) {
    for (e = GL->adjList[j].firstedge; e; e = e->next) {
      k = e->adjvex;
      ete = etv[j];
      lte = ltv[k] - e->weight;
      if (ete == lte)
        printf("<v%c,v%c> length: %d, ", GL->adjList[j].data, GL->adjList[k].data, e->weight);
    }
  }
}

