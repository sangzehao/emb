#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int num, i, max, min, j;
	
	i = 1;
	srand(time(NULL));
	while(i <= 10)
	{
		num = rand() % 1000;
		for(j = 2; j < num; j++)
		{
				if(num % j == 0)
					break;
		}
		if(j == num)
		{	
			if(i == 1)
				max = min = num;
			if(num < min)
				min = num;
			if(num > max)
				max = num;
			printf("%d ", num);
			i++;
		}
	}
	printf("\n");
	printf("max:%d\n", max);
	printf("min:%d\n", min);

	return 0;
}
