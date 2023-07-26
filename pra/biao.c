#include<stdio.h>

int main(void){
	int i, j, result;

	for(i = 1; i < 10; i++){
		for(j = 1; j <= i; j++){
			result = i * j;
			printf("%d*%d = %-3d", j, i, result);
		}
		printf("\n");
	}
	return 0;
}
