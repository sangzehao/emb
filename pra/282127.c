#include<stdio.h>

int max_commu(int a, int b);
int max_comdi(int a, int b);

int main(void)
{
	int a = 23, b = 46;
	unsigned int c = 6;
	int d = -20;

	(c + d > 6) ? puts(">6") : puts("<=6");
	printf("%u\n", c + d);
	printf("max_common divisor:%d\n", max_comdi(a, b));
	printf("max_common multiple:%d\n", max_commu(a, b));
	

	return 0;
}

int max_comdi(int a, int b)
{
	int num = a > b ? a: b;
	int i;

	for(i = num; i >= 1; i--)
	{
		if(a % i == 0 && b % i == 0)
			return i;
	}
}

int max_commu(int a, int b)
{
	int num = a > b ? a : b;
	int i;

	while(num)
	{
		if(num % a == 0 && num % b == 0)
			return num;
		num++;
	}
}

