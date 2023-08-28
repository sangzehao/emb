#include <stdio.h>
#include <stdlib.h>

static void my_atexit1(void)
{
	printf("exit1\n");
}

static void my_atexit2(void)
{
	printf("exit2\n");
}

int main(void)
{
	//my_exit2就算是写前边也是先调用1， 先写的最后调用
//	if(atexit(my_atexit2) != 0)
//		return 1;
	if(atexit(my_atexit1))
		printf("1\n");
	if(atexit(my_atexit1))
		printf("2\n");
	if(atexit(my_atexit2))
		printf("3\n");//printf都不输出,因为atexit都是返回之后才调用的

	return 0;
}
