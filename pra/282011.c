#include <stdio.h>

int main(void)
{
	int day = 1;
	int sum = 1;
	for ( day; day < 10; day++){
		sum = (sum + 1) * 2;
	}
	printf("共有%d个桃子！\n", sum);
	return 0;
}
