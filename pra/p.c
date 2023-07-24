#include<stdio.h>

int main(void)
{
	int i, j;
	char s;

	s = 'A';
	for(i =1; i < 10; i++)
	{
		for(j = 0; j < i; j++)
		{	
			printf("%c ", s + j * 1);
		}
		printf("\n");
	}

	return 0;
}
