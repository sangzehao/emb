#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fun(int n, int *s);

int main(void)
{
	int n, s, j;
	
	s = 0;
	srand(time(NULL));
	n = rand() % 100000;
	printf("%d\n", n);
	j = fun(n, &s);
//	s = s * 10 +fun(n, &s);
	s = s * 10 + j;
	printf("sum:%d\n", s);

	return 0;
}

int fun(int n, int *s)
{
	int i = 0, j;

	if(n > 0)
	{
		i = n % 10;
		n = n / 10;
		j = fun(n, s);
		*s = *s * 10 + j;
		printf("%d\n", i);
	}

	return i;
}
