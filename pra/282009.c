#include <stdio.h>

int main (void)
{
	//求阶乘
	int num;
	int result;
	int i;


	printf("输入数字\n");
	scanf("%d",&num);

	//第一种方法 n*n-1....*1
/*   	result = num;	
	for(i = 1; i < num-1; i++)
	{
	 	result = result * (num - i);
	};
	printf("结果为%d\n", result);	
*/
	//第二种 n*1*2**...n-1,逻辑简单点
	result = num;
	for (i = 1; i < num; i++){
		result = result * i;
	}
	printf("结果为%d\n", result);
}
