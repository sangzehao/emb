#include<stdio.h>

int main(void)
{
	int i, j, num1, num2, mid;

	for(num1 = 2; num1 < 10000; num1++)
	{	
		num2 = 1;
		j = num1 / 2;
		while(j > 1)
		{
			if(num1 % j == 0)
				num2 += j;
			j--;
		}

		j = num2 / 2;
		mid = 1;
		while(j > 1)
		{
			if(num2 % j == 0)
				mid += j;
			j--;
		}
		if(mid == num1 && num1 < num2)
		{
			printf("num1:%d num2:%d\n", num1, num2);
		}
		
	}
	
	return 0;
}

