/**
 * 图的拓扑排序
 * author TomCao
 */
#ifndef _BASE_DATA_
#define _BASE_DATA_
#define OK 1;
#define ERROR 0;
#define MAXVEX 30

typedef int Status;

typedef struct EdgeNode
{
  int adjvex;
  int weight;
  struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
  int in;
  int data;
  EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
  AdjList adjList;
  int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

void CreateTopo(GraphAdjList GL);
Status TopologicalSort(GraphAdjList GL);
#endif