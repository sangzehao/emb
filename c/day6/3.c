#include<stdio.h>
//#include"4.h"
#include"5.h"
#define BASEYEAR	1970
#define SECONDYEAR (365 * 24 * 60 * 60UL)//无符号long
#define MAX2NUM(x, y) (x) > (y) ? (x) : (y)
#define SQUEAR(x) (x) * (x)
#define CONN(x) x##x
//宏就是起个替换作用，所以一定注意括号
#define SWAP(x, y) x = x ^ y; y = x ^ y; x = x ^ y

int main(void)
{
	int a = 1, b = 2;
	
	printf("BASEYEAR:%d\n", BASEYEAR);	
	printf("SECONDYEAR:%ld\n", SECONDYEAR);
	printf("MAX2NUM:%d\n", MAX2NUM(1, 2));
	printf("SQUEAR:%d\n", SQUEAR(2));
//	printf("%c\n", CONN('h'));
	SWAP(a, b);
	printf("a:%d b:%d\n", a, b);
//	printf("glob:%d\n", glob);
	printf("ssh:%d\n", s);

	return 0;
}
