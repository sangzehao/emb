#include<stdio.h>

int main(void)
{
	int i = 1, sum = 0;
	
	for(i; i <= 100; i++){
		if(i % 4 == 0 && 0 == i % 6)
			sum += i;
		if(sum > 400)
		{
			sum -= i;
			break;
		}
	}

	printf("%d\n", sum);

	return 0;
}
