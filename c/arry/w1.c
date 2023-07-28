#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void p_out(int a[], int len);
int is_prime(int a);

int main(void)
{
	int arr[20], i;

	srand(time(NULL));
	for(i = 0; i < 20; i++)
	{
		arr[i] = rand() % 1000;
	}
	printf("arr:");
	p_out(arr, 20);
	printf("prime:");
	for(i = 0; i < 20; i++)
	{
		if(is_prime(arr[i]))
			printf("%d ", arr[i]);
	}
	printf("\n");

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

int is_prime(int a)
{
	int j;
		if(a < 2)
			return 1;

		for(j = 2; j <= a / 2; j++)
		{
			if(a % j == 0)
				return 0;
		}

		return 1;
}
