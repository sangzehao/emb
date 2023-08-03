#include<stdio.h>

int main(void)
{
	char s[] = "helloooo";

	char *p = s;

	printf("s:%ld\n", sizeof(s));
	printf("p:%ld\n", sizeof(p));
	printf("int:%ld\n", sizeof(int));
	printf("long:%ld\n", sizeof(long));
	printf("long long:%ld\n", sizeof(long long));
	printf("float:%ld\n", sizeof(float));
	printf("double:%ld\n", sizeof(double));

	return 0;
}
