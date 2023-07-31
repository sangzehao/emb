#include<stdio.h>

int main(void)
{
	int a1, d, i, nsum, asum;

	for(a1 = 1; ; a1++)
	{
		for(d = 1; d < 6; d++)
		{	
			nsum = 0;
			asum  = 1;
			for(i = 0; i < 4; i++)
			{
				nsum += (a1 + i * d);
			   	asum *= (a1 + i * d);	
			}
			if(nsum == 26 && asum == 880)
				break;
		}
		if(nsum == 26 && asum == 880)
			break;
	}
	printf("a1:%d d:%d\n", a1, d);

	return 0;
}
