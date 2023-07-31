#include<stdio.h>

int main(void)
{
	int a = 123;

	printf("10:%d\n", a);
	printf("16:%x\n", a);
	printf("8:%o\n", a);
	printf("%d\n", 0123);//八进制的123
	printf("%d\n", 0x123);//16进制
	printf("%d\n", 123);
	printf("%f\n", 123.4);
	printf("%f\n", 1.234e2);

	return 0;
}
