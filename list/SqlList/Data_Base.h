#ifndef _DATA_BASE_
#define _DATA_BASE_

#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef void* ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SqList;

#endif 