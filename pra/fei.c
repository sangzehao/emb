#include<stdio.h>

int main(void)
{
	int f1, f2, sum, i;
	
	f1 =  f2 = 1;
	for(i = 0 ; i < 10; i++)
	{
		printf("%d %d ", f1, f2);
		f1 = f1 + f2;
		f2 = f1 + f2;
	}

	return 0;
}
