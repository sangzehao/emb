#include<stdio.h>

int main(void)
{
	int num1, num2, i, div, remain, big, low;

	remain = 1;
	printf("printf:\n");
	scanf("%d%d", &num1, &num2);
	big = num1 > num2 ? num1 : num2;
	low = num1 < num2 ? num1 : num2;

	printf("%d, %d\n", big, low);
	div = big / low;
	remain = big % low;
	i = div;
	num2 = low;
	while(remain)
	{	
		i = div;
		div = i / remain;
		num2 = remain;
		remain = i % remain;
	}
	printf("%d\n", num2);

	return 0;
}
