#include<stdio.h>

void swap(int *p, int *s);
int mystrlen(char *p);
void swap(int *p, int *s);
typedef int myint;

int main(void)
{
	char s[] = "hello";
	char *p = s;
	int a = 1, b = 2;
	myint c = 1;
	size_t d = -5;
	long e = -5;
 
	printf("c:%d\n", c);
	printf("d:%ld\n", d);
	printf("e:%ld\n", e);
	printf("%s\n", s = typeof(a));

//	printf("s[]:%p\n", s[]);
/*	printf("p:%p\n", p);
	printf("s:%p\n", s);
	printf("*p:%c\n", *p);
	printf("*(p + 1):%c\n", *(p + 1));
	printf("*p + 1:%d\n", *p + 1);
	printf("p + 1:%p\n", p + 1);
	p++;
	printf("p:%p\n", p);
	printf("*p:%c\n", *p);
	printf("p[1]:%c\n", p[1]);
	printf("s:%p\n", s);
	printf("*s:%c\n", *s);
	printf("len:%d\n", mystrlen(s));
	swap(&a, &b);
	printf("a:%d b:%d\n", a, b);
//	printf("typeof：%s\n", typeof a);
*/

	return 0;
}

int mystrlen(char *p)
{
	int len = 0;

	while(*p)
	{
		len++;
		p++;
	}

	return len;
}

void swap(int *p, int *s)
{
	int t;

	t = *p;
	*p = *s;
	*s = t;
}
