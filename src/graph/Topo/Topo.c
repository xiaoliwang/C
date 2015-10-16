#include <stdlib.h>
#include <stdio.h>
#include "BaseData.h"

int main(int argc, const char *argv[])
{
  GraphAdjList GL = (GraphAdjList )malloc(sizeof (graphAdjList));
  CreateTopo(GL);
  int status = TopologicalSort(GL);
  printf("\n%d\n", status);
}