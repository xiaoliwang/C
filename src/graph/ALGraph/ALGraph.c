#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

int main(int argc, const char *argv[])
{
  GraphAdjList *GL = (GraphAdjList *) malloc(sizeof(GraphAdjList));
  CreateAlGraph(GL);
  DFSTraverse(*GL);
  puts("");
  BFSTraverse(*GL);
  puts("");
}
