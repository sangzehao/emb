#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 10
int *p_out(int *p);

int main(void)
{
	int a[N];
	int i;

	srand(time(NULL));
	for(i = 0; i < N; i++)
	{
		a[i] = rand() % 10;
	}

	p_out(a);
	
	return 0;
}

int *p_out(int *p)
{
	int i;

	for(i = 0; i < N; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");

	return p;
}
