#include<stdio.h>

int main(void)
{	
	int num, l_3, r_3, i, j, n, pos_l, pos_r;
	
	
	for(num = 100000; num <= 999999; num++)
	{
		for(i = 300; i < 1000; i++)
		{
			pos_r = pos_l = 0;

			if(i == num / i && num % i == 0)
			{
				l_3 = num % 1000;
				r_3 = num / 1000;
				for(n = 1; n < 40; n++)
				{
					if(n == l_3 / n && l_3 % n == 0)
					{
						pos_l = 1;
					}else if(n == r_3 / n && r_3 % n == 0)
					{
						pos_r = 1;
					}
				}
			}
			if(pos_r == 1 && pos_l == 1)
				printf("%d ", num);
		}
	}
	printf("\n");

	return 0;
}
