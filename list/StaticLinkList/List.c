#define MAXSIZE 1000
typedef struct{
	ElemType data;
	int cur;
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space){
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

int Malloc_SLL(StaticLinkList space){
	int i = space[0].cur;

	if(space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}
