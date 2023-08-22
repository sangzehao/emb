#include<stdio.h>

int main (void)
{
	int num1, num2, mid;
	int i ;

	printf("输入两个数：")
	scanf("%d %d", &num1, &num2);
	mid = num1;
	for (i = 1; i<num2; i++){
		num1 = num1 * mid % 1000;//巧妙 除了后三位，其它的位不管怎么乘都与后三位无关了	
	}
	if (num1 < 100)
		printf("后三位为：0%d\n", num1);
	else
		printf("  %d\n",num1);
/*	for (i = 0; i < 3; i++){
		num2 = num1 % 10;
		num1 = num1 / 10;
		printf("%d", num2);
		if (num1 == 0)
			break;
	}
*/ 
	/*if(num1 > 1000){
		num1 = num1 % 1000;
		if (num1 < 100)
			printf("输出结果为：0%d\n", num1);
		else
			printf("输出结果为：%d\n", num1);
	}
	else{
	printf("输出结果为：%d\n", num1);
	}
	*/
	return 0;
}
