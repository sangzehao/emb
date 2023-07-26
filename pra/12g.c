#include<stdio.h>

int fun(int num, int *sum);

int main(void)
{
	int num = 10929;
	int sum, j;

	sum = 0;

	j = fun(num, &sum);
	sum = sum * 10 + j;
	printf("sum:%d\n", sum);

	return 0;
}
int  fun(int num, int * sum)
{
	int i, j;

	i = 0;
	if (num > 0){
		i = num % 10;
		num = num / 10;
		j = fun(num, sum);
		*sum = *sum * 10 + j;
//		*sum = *sum * 10 + fun(num, sum); 不行
		printf("%d \n", i);

	}
//	printf("*sum:%d\n", *sum);

	return i;
}
