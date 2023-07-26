#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//选择排序时间复杂度O（n^2）每轮只交换一次
void p_out(int a[], int len);
void choice_sort(int a[], int len);

int main(void)
{
	int a[15], i;
	
	srand(time(NULL));
	for(i = 0; i < 15; i++)
	{
		a[i] = rand() % 100;
	}
	printf("start:");
	p_out(a, 15);
	choice_sort(a, 15);
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

void choice_sort(int a[], int len)
{
	int i, j, tem, mid;

	for(i = 0; i < len - 1; i++)
	{
		j = i + 1;
		tem = a[i];
		for(j; j < len; j++)
		{
		/*	if(a[j] < a[i])
			{ 这个不是选择排序，每轮交换次数不是一次
				a[j] = a[j] ^ a[i];
				a[i] = a[i] ^ a[j];
				a[j] = a[j] ^ a[i];
			}
		*/

			if(a[j] < tem)
			{
				tem = a[j];
				mid = j;
			}
		}	
		a[mid] = a[i];
		a[i] = tem;
		p_out(a, len);
	}
}
