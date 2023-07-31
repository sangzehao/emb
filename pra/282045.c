#include<stdio.h>

int main(void)
{
	int i, num, l_p, j;

	for(i = 0; i < 10000; i++)
	{
		num	= i * i;
		j = 10;
		l_p = num % j;
		if(num == i)
			printf("i:%d num:%d\n", i, num);
		while(l_p < num)
		{
			if(l_p == i)
			{
				printf("i:%d num:%d\n", i, num);
				break;
			}
			j *= 10;
			l_p = num % j;
		}
		
	}

	return 0;
}
