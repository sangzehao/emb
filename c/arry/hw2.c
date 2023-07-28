#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20
void stat(int a[], int pos);

int main(void)
{
	int a[N], i, j;

	srand(time(NULL));
	printf("原始数据:\n");
	for(i = 0; i < N; i++)
	{
		a[i] = rand() % 101;
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 1; i <=10; i++)
	{
		
		printf("%d~%d:", 10 * i - 10, 10 * i - 1 + (i == 10));
		stat(a, i - 1);
	}

	return 0;
}

void stat(int a[], int pos)
{
	int i;

	for(i = 0; i < N; i++)
	{
		if(a[i] / 10 == pos)
		{
			printf("*");

		}else if(pos == 9 && a[i] == 100){
			printf("*");
		}
	}	
	printf("\n");
}
