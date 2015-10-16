#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

int main(int argc, const char *argv[])
{
  MGraph *G = (MGraph *) malloc(sizeof(MGraph));
  CreateMGraph(G);
  DFSTraverse(*G);
  puts("");
  BFSTraverse(*G);
  puts("");
  MiniSpanTree_Prim(*G);
  puts("");
  
  Pathmatirx *P = (Pathmatirx *) malloc(sizeof(Pathmatirx));
  ShortPathTable *D = (ShortPathTable *) malloc(sizeof(ShortPathTable));
  ShortestPath_Dijkstra(*G, P, D);
  int i;
  for(i = 0; i < G->numVertexes; ++i) {
    printf("%d,%d\n",(*P)[i], (*D)[i]);
  }
  puts("");
  
  Pathmatirx2 *P2 = (Pathmatirx2 *) malloc(sizeof(Pathmatirx2));
  ShortPathTable2 *D2 = (ShortPathTable2 *) malloc(sizeof(ShortPathTable2));
  ShortestPath_Floyd(*G, P2, D2);
  int v, w, k;
  for (v = 0; v < G->numVertexes; ++v) {
    for (w = v + 1; w < G->numVertexes; ++w) {
      printf("v%d-v%d weight: %d", v, w, (*D2)[v][w]);
      k = (*P2)[v][w];
      printf(" path: %d", v);
      while(k != w) {
        printf(" -> %d", k);
        k = (*P2)[k][w];
      }
      printf(" -> %d\n", w);
    }
    puts("");
  }
}
