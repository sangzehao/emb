#include<stdio.h>

int main(void)
{
	int a[10000];


	int i;

	for(i = 0; i < 10000; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
