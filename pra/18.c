#include<stdio.h>

int main(void)
{
	int num = 47, i, j;
	int a[12];
	
	printf("num:%d\n", num);
	i = 0;
	while(num > 0)
	{
		j = num % 2;
		num = num / 2;
		a[i] = j;
		i++;
	}

	printf("二进制为：");	
	for(i - 1; i - 1 >= 0; i--)
	{
		printf("%d", a[i - 1]);
	}
	printf("\n");

	return 0;
}
