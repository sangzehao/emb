#include <stdio.h>

int d_n(int num, int n);
static int __chan(int num, int n, int *sum);

int main(void)
{
	int num = 24;

	printf("%d\n", d_n(num, 2));
	printf("%d\n", d_n(num, 8));
	printf("%d\n", d_n(num, 16));

	return 0;
}

static int __chan(int num, int n, int *sum)
{
	int mod = 0;
	int j;

	if(num > 0)
	{
		mod = num % n;
		num = num / n;
		j = __chan(num, n, sum);
		*sum = *sum * 10 + j;		
	}

	return mod;
}

int d_n(int num, int n)
{
	int ret = 0;
	int sum = 0;

 	ret = __chan(num, n, &sum);

	sum = sum * 10 + ret;

	return sum;
}
