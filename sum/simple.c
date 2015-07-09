#include <stdio.h>

void main(){
	int i, sum = 0, n = 100;
	for (i = 1; i <= n; i++){
		sum = sum + i;
	}
	printf("%d\n",sum);
}