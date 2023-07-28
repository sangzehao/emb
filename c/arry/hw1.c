#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20

void p_out(int a[]);//打印
void reverse(int a[]);//倒序
void odd_even(int a[]);//奇偶分离

int main(void)
{
	int arr[N], i;

	srand(time(NULL));
	for(i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("原始数组为：\n");
	p_out(arr);
	reverse(arr);
	printf("倒序后：\n");
	p_out(arr);
	odd_even(arr);
	printf("奇偶调整后：\n");
	p_out(arr);

	return 0;
}

void p_out(int a[])//打印输出
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void reverse(int a[])//倒序
{
	int i, j, key;

	for(i = 1; i < N; i++)
	{
		key  = a[i];
		j = i - 1;
		while(a[j] < key && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void odd_even(int a[])//奇偶分离
{
	int i, j, mid;
	
	j = N - 1;
	i = 0;
	
	for(i; i < j; i++){
		if(a[i] % 2)
		{
			for(j; j != i; j--)
			{
				if(a[j] % 2 == 0)
				{
					mid = a[i];
					a[i] = a[j];
					a[j] = mid;
					break;
				}
			}
		}
	}

}
