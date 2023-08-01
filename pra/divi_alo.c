#include<stdio.h>

int gcd(int a, int b);

int main(void)
{
	int num1, num2, i, div, remain, big, low;

	remain = 1;
	printf("printf:\n");
	scanf("%d%d", &num1, &num2);
	printf("result：%d\n", gcd(num1, num2));

	return 0;
}

int gcd(int a, int b)
{
	int big, low, remain;

	big = a > b ? a : b;
	low = a < b ? a : b;

	remain = 1;

	while(remain)
	{
		remain = big % low;
		big = low;
		low = remain;
	}

	return big;
}
