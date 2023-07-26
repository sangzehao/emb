#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//时间复杂度O（n^2）, 最好O（n）
void p_out(int a[], int len);
void insert_sort(int a[], int len);

int main(void)
{
	int a[15], i = 0;

	srand(time(NULL));
	for(i; i < 15; i++)
	{
		a[i] = rand() % 100;
	}
	printf("start:");
	p_out(a, 15);
	insert_sort(a, 15);
	printf("after:");
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
void insert_sort(int a[], int len)
{
	int i, j, tem;

	for(i = 1; i < len; i++)
	{
		j = i - 1;
		tem = a[i];
		while(j >= 0 && a[j] > tem)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tem;
		p_out(a, len);
	}
}

/*void insert_sort(int a[], int len)
{
	int i, tem, j;

	for(i = 1; i < len - 1; i++)
	{
		j = i - 1;
		tem = a[i];
		while(j >= 0)
		{
			if(a[j] > tem)
			{
				a[j] = a[j + 1] ^ a[j];
				a[j + 1] = a[j + 1] ^ a[j];			
				a[j] = a[j] ^ a[j + 1];
			}
			j--;
		}
		p_out(a, len);
	}
}
*/
