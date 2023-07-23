#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//希尔排序，不稳定，相同值的元素可能会改变顺序
void p_out(int a[], int len);
void shell_sort(int a[], int len);

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
	shell_sort(a, 15);
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

void shell_sort(int a[], int len)
{
	int i, j, step, mid;

	step = (0 + len - 1) / 2;
	while(step > 0){
		for(i = step;  i < len; i++)
		{
			j = i - step;
			mid = a[i];
			while(j >= 0 && a[j] > mid)
			{	
				a[j + step] = a[j];
				j -= step;
			}
			a[j + step] = mid;
		}
		step /= 2;
		p_out(a, len);
	}
}
