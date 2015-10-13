#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

int main(int argc, const char *argv[])
{
  BiThrTree t;
  BiThrTree temp;
  CreateBiThrTree(&t);
  InThreading_HEAD(&temp, t);
  InOrderTraverse_Thr(temp);
  return OK;
}

