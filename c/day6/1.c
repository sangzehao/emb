#include<stdio.h>

int test(int a, int b, int c);

int main(void)
{
	//volatile int n = 1;
	int n = 1;
	test(n, n++, ++n);

	return 0;
}

int test(int a, int b, int c)
{
	printf("a:%d b:%d c:%d\n", a, b, c);
}
