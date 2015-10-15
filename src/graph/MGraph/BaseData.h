/**
 * 图的邻接矩阵存储
 * author: TomCao
 * 
 */
#ifndef _BASE_DATA_
#define _BASE_DATA_

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 20
#define MAXEDGE 20
#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;

typedef struct
{
  VertexType vexs[MAXVEX];
  EdgeType arc[MAXVEX][MAXVEX];
  int numVertexes, numEdges;
}MGraph;

typedef struct
{
  int begin;
  int end;
  int weight;
}Edge;

void CreateMGraph(MGraph *G);
void DFSTraverse(MGraph G);
void BFSTraverse(MGraph G);
void MiniSpanTree_Prim(MGraph G);
void MiniSpanTree_Kruskal(MGraph G);
int Find(int *parent, int f);
#endif
