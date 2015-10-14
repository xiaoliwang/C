/**
 * 图的邻接矩阵存储
 * author: TomCao
 * 
 */
#ifndef _BASE_DATA_
#define _BASE_DATA_

#define OK 1
#define ERROR 0
#define MAXVEX 100
#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;

typedef struct
{
  VertexType vexs[MAXVEX];
  EdgeType arc[MAXVEX][MAXVEX];
  int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G);

#endif
