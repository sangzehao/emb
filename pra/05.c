#include<stdio.h>

int main(void)
{
	char i, s;
	
	for(i = 'a'; i < 'z' + 1; i++)
	{
		printf("%c ", i);
	}
	printf("\n");

	for(i = 'Z'; i > 'A' - 1; i--)
	{
		printf("%c ", i);
	}
	printf("\n");

	return 0;
}
