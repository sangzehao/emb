#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int a[4][5];
	int i, j, n,max, mid;
	
	srand(time(NULL));
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			a[i][j] = rand() % 100;		
		}
	}

	for(i = 0; i < 4; i++)
	{
		max = 0;
		for(j = 1; j < 5; j++)
		{
			if(a[i][j] > a[i][max] )
				max = j;
		}
		mid = a[i][j - 1];
	   	a[i][j - 1] = a[i][max];
		a[i][max] = mid;	
	}
	
	printf("最大放后边\n");	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			printf("%-2d ", a[i][j]);
		}
		printf("\n");
	}
	
	printf("每一行排序\n");
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			for(n = 1; n < 5; n++){
				if(a[i][n] < a[i][n - 1])
				{
					mid = a[i][n];
					a[i][n] = a[i][n - 1];
					a[i][n - 1] = mid;
				}
			}
		}
	}	
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			printf("%-2d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
