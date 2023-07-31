#include<stdio.h>

int is_primer(int n);

int main()
{
	int num ,i , left, right;

	printf("printf:");
	scanf("%d", &num);

	for(i = 2; i <= num / 2; i++)
	{
		if(is_primer(i) && is_primer(num - i))
			printf("%d = %d + %d\n", num, i, num - i);
	}

	return 0;
}

int is_primer(int n)
{
	int i;
	
	for(i = 2; i <= n / 2; i++)
	{
		if(n % i == 0)
			break;
	}

	return i > n / 2;
}
