/**
 * 图的邻接表存储
 * author: TomCao
 * 
 */
 
#ifndef _BASE_DATA_
#define _BASE_DATA_

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100

typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;

typedef struct EdgeNode
{
  int adjvex;
  EdgeType weight;
  struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
  VertexType data;
  EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
  AdjList adjList;
  int numVertexes, numEdges;
}GraphAdjList;

void CreateAlGraph(GraphAdjList *G);
void DFSTraverse(GraphAdjList GL);
#endif
