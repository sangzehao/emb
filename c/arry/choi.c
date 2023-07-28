#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
void p_out(int a[]);
void choice_sort(int a[]);

int main(void)
{
	int arr[N], i;

	srand(time(NULL));

	for(i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("start");
	p_out(arr);
	choice_sort(arr);

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

void choice_sort(int a[])
{
	int i, j, min, mid;

	for(i = 0; i < N - 1; i++)
	{
		min = i;
		for(j = i + 1; j < N; j++)
		{
			if(a[min] > a[j])
			{
				min = j;
			}
		}
		mid = a[i];
		a[i] = a[min];
		a[min] = mid;

/*		a[i] = a[i] ^ a[min];
		a[min] = a[i] ^ a[min];
		a[i] = a[i] ^ a[min]; 异或在数组中不能随便用，因为很可能有两个元素值一样，又是按地址取值的，第一个式子后a[i],a[min]就全为0 了
*/
		p_out(a);
	}
	printf("\n");
}
