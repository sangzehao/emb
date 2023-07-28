#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//冒泡排序
void p_out(int a[]);
void bub_sort(int a[]);

#define N 10

int main(void)
{
	int arr[N];
	int i;

	srand(time(NULL));

	for(i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("start:");
	p_out(arr);
	bub_sort(arr);

	return 0;
}

void p_out(int a[])
{
	int i;

	for(i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void bub_sort(int a[])
{
	int i, j;
	
	for(i = 0; i < N - 1; i++)
	{
		for(j = 1; j < N - i; j++)
		{
			if(a[j - 1] > a[j])
			{
				a[j - 1] = a[j - 1] ^ a[j];
				a[j] = a[j - 1] ^ a[j];
				a[j - 1] = a[j - 1] ^ a[j];
			}
		}
		p_out(a);
	}
}
