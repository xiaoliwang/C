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
}
