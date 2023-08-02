#include<stdio.h>

void show_arr(int *a, int n);
int main(void)
{
	int arr[6] = {1,2,34,5,5,7};
	int *p;

	p = arr;
	show_arr(arr, 6);
	printf("*p++:%d\n", *p++);//1
	show_arr(arr, 6);
	printf("(*p)++:%d\n", (*p)++);//2， 但是此时a[2]已经为3
	show_arr(arr, 6);
	printf("*(p++):%d\n", *(p++));//3
	show_arr(arr, 6);
	printf("++*p:%d\n", ++*p);//35
	show_arr(arr, 6);
	printf("*++p:%d\n", *++p);//5
	show_arr(arr, 6);
	
	return 0;
}

void show_arr(int *a, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("%d ", *(a + i));
	}

	printf("\n");
}
