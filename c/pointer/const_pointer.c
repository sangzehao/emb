#include<stdio.h>

int main(void)
{
	char s[] = "hello";
	
	char *const q = s;//指针常量，指针类型的常量，q 是指针，是常量；

//	q++;
//	*q = 'l';

//	printf("%c\n", *q);

	const char *p = s;//常量指针,常量的指针，所以*p只读；
	
	p++;
//	*p = "w";
	
	printf("%c\n", *p);

	return 0;
}
