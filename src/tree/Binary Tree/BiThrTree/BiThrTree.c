#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

int main(int argc, const char *argv[])
{
  BiThrTree *T = (BiThrTree *) malloc(sizeof(BiThrTree));
  CreateBiThrTree(T);
  InThreading(*T);
  //InOrderTraverse_Thr(*T);
}

