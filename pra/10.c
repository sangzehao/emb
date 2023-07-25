#include<stdio.h>

int main(void)
{
	int a, b;

	for(a = 0; a < 10; a++)
	{
		for(b = 0; b <= 12 - a && b < 10; b++ )
		{
			if(a + b == 12)
				printf("%d + %d = 12\n", a, b);
		}
	}

	return 0;
}
