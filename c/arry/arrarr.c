#include<stdio.h>

int main(void)
{
	int a[2][3] = {1, 2, 3, 4, 5, 6};
	
	printf("%p\n", a[0]);//首地址
	printf("%p\n", a);//首地址
	printf("%p\n", &a + 1);//首地址加24，运算能力是24
	printf("%p\n", &a[0]);//首地址
	printf("%p\n", &a[0] + 1);//首地址加12，运算能力12
	printf("%p\n", a[0] + 1);//首地址加4，运算能力是4
	printf("%p\n", a - 1);//首地址-12，运算能力12
	//运算能力看你自己的元素类型，对数组去地址，运算能力为i整个数组长度

	printf("%d\n", *(*(a + 1) + 1));

	return 0;
}
