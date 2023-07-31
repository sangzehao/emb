#include<stdio.h>

int main(void)
{
	int num, i, unit, j;

	for(num = 100; num < 1000; num++)
	{
		for(i = 10; i < 40; i++)
		{
			if(i == num / i && num % i == 0)
			{
				unit = num % 10;
				j = num / 10;
				if(unit == j % 10 || unit == j / 10 || j % 10 == j / 10)
				{
					printf("num:%d\n", num);
					printf("i:%d\n", i);
				}
			}
		}
	}

}
