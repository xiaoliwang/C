#include "Data_Base.h"

Status InitSqList(SqList *L){
	if (!L)
		return ERROR;
	for(int i = 0; i < MAXSIZE - 4; i++){
		a->value[i] = "liam";
		a->length = i;
		
	}
	return OK;
}

Status GetElem(SqList L, int i, ElemType *e){
	if (L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e){
	int k;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i < 1 || i > L->length + 1)
		return ERROR;
	if (i <= L->length){
		for ( k <= L->length - 1; k >= i - 1; k--)
			L->data[k+1] = L->data[k];
	}
	L->data[i-1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType e){
	int k;
	if (L->length == 1)
		return ERROR;
	if (i < 1 || i > L->length)
		return ERROR;
	e = L->data[i-1];
	if (i < L->length){
		for ( k = i; k < L->length; k++)
			L->data[i-1] = L->data[i]
	}
	L->length--;
	return OK;
}


