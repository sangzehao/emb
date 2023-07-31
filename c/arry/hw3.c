#include<stdio.h>

int main(void)
{
	int a[10][10] = {};
	int i, j, value;
	
	a[0][0] = 1;
	for(i = 1; i < 10; i++)
	{
		for(j = 0; j < i + 1; j++)
		{
			if(j > 0)
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}else{
				a[i][j] = 1;
			}	
		}
	}

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < i + 1; j++)
		{
			printf("%-3d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
