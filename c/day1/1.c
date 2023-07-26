#include<stdio.h>

int main(void){
	int i, m;

	printf("shuru \n");
	scanf("%d", &i);
	scanf("%d", &m);
	printf("向左移一位：%d\n", i << 1);
	printf("向右移一位：%d\n", i >> 1);
	printf("按位与%d\n", i & m);
	printf("按位或%d\n", i | m);
	printf("按位异或%d\n", i ^ m);
	printf("m取反%d\n", ~m);
	printf("long double:%ld\n", sizeof(long double));


	return 0;
}
