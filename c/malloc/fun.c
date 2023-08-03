#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int *arr = (int *)malloc(10 * sizeof(int));
	int *s = (int *)calloc(10, sizeof(int));
	int i;

	for(i = 0; i < 10; i++)
	{
		arr[i] = i;
	}	

	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++)
	{
		s[i] = i;
	}	
	for(i = 0; i < 10; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	s = (int *) realloc(s, 80);
	for(i = 0; i < 20; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	free(arr);
	arr = NULL;
	free(s);
	s = NULL;
	free(s);


	return 0;
}
