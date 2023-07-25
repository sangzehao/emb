#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int num, count, i, j;

	count = 0;
	srand(time(NULL));
	num = rand() % 100000;
	printf("%d\n", num);
	while(num)
	{	
		i = num % 10;
		num = num / 10;
		count++;
		printf("%d ", i);

	}
	printf("\n%d位\n", count);
	
	return 0;
}
