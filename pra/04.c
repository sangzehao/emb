#include<stdio.h>

int main(void)
{
	int i, num, sum, n;

	for(i = 100; i < 999; i++)
	{
		sum = 0;	
		num = i;
		while(num)
		{
			n = num % 10;
			sum += n * n * n;
			num = num / 10;
		}
		if(sum == i)
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}
