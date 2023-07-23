#include<stdio.h>

int main(void){
	int i;

	i= 1;

	printf("i:%d\n", i);
	printf("i>>:%d\n", i>>1);
	printf("i:%d\n", i);
	printf("i<<:%d\n", i<<1);
	printf("~i:%d\n", ~i);

	return 0;
}
