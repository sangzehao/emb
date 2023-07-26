#include<stdio.h>

int main(void)
{
	int i, num, j, sum;
	
	sum = 0;
	for(i = 2; i < 100; i++)
	{
		num = i;
		for(j = 2; j < num; j++)
		{
			if(num % j == 0)
				break;
		}
		if(j == num)
		{
			sum += num;
			printf("%d ", num);
		}
	}
	printf("\nsum:%d\n", sum);

	return 0;
}
