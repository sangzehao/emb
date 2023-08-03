#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void max_min(int *s, int *a, int *n);

int main(void)
{
	int a[10], i;
	int max, min;
		
	srand(time(NULL));
	for(i = 0; i < 10; i++)
	{
		*(a + i) = rand() % 100;
		printf("%d ", a[i]);
	}
	printf("\n");
	max = *a;
	min = *a;
	max_min(a, &max, &min);

	printf("max:%d min:%d\n", max, min);

	return 0;
}

void max_min(int *s, int *a, int *n)
{
	int i;

	for(i = 1; i < 10; i++)
	{
		if(*(s + i) > *a){
			*a = *(s + i);
		}
		else if(*(s + i) < *n)
			*n = *(s + i);
	}
	
}

