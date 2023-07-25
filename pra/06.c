#include<stdio.h>

int main(void)
{
	float sum, num, pos;
	float i;

	sum = pos = 0;
	for(i = 1; i < 101; i++)
	{
		num = 1 / i;
		if(pos == 0)
		{
			sum += num;
			pos = 1;
			printf("%6f ", sum);
			continue;
		}
		if(pos == 1)
		{
			sum -= num;
			pos = 0;
			printf("%6f ", sum);
			continue;
		}
	}
	printf("\n");

	return 0;
}
