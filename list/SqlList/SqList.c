#define MAXSIZE 20 /*存储空间初始分配量*/
typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE];
	int length;
} SqList;

