#include<stdio.h>

#define AREA(a,b) ((a) * (b))
#define SUM(a,b) (a + b)
#define SWAP(a,b) {int c; c = a; a = b; b = c;}

int main(void)
{
	int a, b, c, d;
	int n = 1;
	int m = 2;
	
	a = AREA(2,3);
	b = SUM(n, m);
	SWAP(n, m);

	printf("a:%d\n", a);
	printf("b:%d\n", b);
	printf("n:%d\n", n);
	printf("m:%d\n", m);

	return 0;
}
