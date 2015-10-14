#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

int main(int argc, const char *argv[])
{
  GraphAdjList *G = (GraphAdjList *) malloc(sizeof(GraphAdjList));
  CreateAlGraph(G);
}