#include<stdio.h>

typedef int num_t;

int main(void)
{
	num_t n;
	size_t s;

	printf("sizeof(n):%ld\n", sizeof(n));
	printf("sizeof(ssize_t):%ld\n", sizeof(ssize_t));
	printf("sizeof(size_t):%ld\n", sizeof(size_t));

	return 0;
}
