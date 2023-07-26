//冒泡排序 时间复杂度O(n^2) 最好情况O(n)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void p_out(int a[], int len);
void bubble_sort(int a[], int len);

int main(void)
{
	int i, a[15];

	srand(time(NULL));
	for(i = 0; i < 15; i++)
	{
		a[i] = rand() % 100;
	}
	printf("start:");
	p_out(a, 15);
	bubble_sort(a,15);
	printf("end:");
	p_out(a, 15);

	return 0;
}

void p_out(int a[], int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void bubble_sort(int a[], int len)
{
	int i, j;

	for(i = 0; i < len - 1; i++)
	{
		for(j = 1; j < len; j++)
		{
			if(a[j] < a[j - 1])
			{
				a[j] = a[j - 1] ^ a[j];
				a[j - 1] = a[j - 1] ^ a[j];
				a[j] = a[j] ^ a[j - 1];
			}
		}
		p_out(a, len);
	}
}
