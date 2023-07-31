#include<stdio.h>

int main(void)
{
	int num, i, res, j, t;
	
	printf("num:");
	scanf("%d", &num);
	num = num * num * num;
	printf("cube:%d\n", num);
	
	t = num / 2;
	for( i = t + !(t % 2); i > 0; i -= 2)
	{
		j = i;
		res = 0;
		while( res < num && j > 0)
		{
			res += j;
			j -= 2;
		}
		j += 2;
		if(res == num)
		{
			printf("%d = ", num);
			while(j <= i)
			{
				if(j == i)
					printf("%d\n", j);
				else
					printf("%d + ", j);
				j += 2;
			}
		}

	}

	return 0;
}
