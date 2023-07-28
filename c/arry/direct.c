#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
void p_out(int a[]);
void direct_sort(int a[]);

int main(void)
{
	int arr[N], i;

	srand(time(NULL));
	for(i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("start:\n");
	p_out(arr);
	direct_sort(arr);

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

void direct_sort(int a[])
{
	int i, j, key, mid;

	for(i = 1; i < N; i++)
	{
		key = a[i];
		for(j = i - 1; j >= 0; j--)
		{
			if(a[j] > key)
			{
				a[j + 1] = a[j];
			}else{
				break;
			}
		}
		a[j + 1] = key;
		p_out(a);
	}
	printf("\n");
}
