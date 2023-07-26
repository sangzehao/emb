#include<stdio.h>

int sumn(int n);
int amass_sumn(int n);
int fib(int n);

int  main(void)
{
	printf("sumn:%d\n", sumn(10));
	printf("amass_sumn:%d\n", amass_sumn(5));
	printf("fib:%d\n", fib(5));

	return 0;
}

int sumn(int n)
{
	if(n == 1)
		return 1;

	return n + sumn(n - 1);
}

int amass_sumn(int n)
{
	if(n == 1)
		return 1;
	
	return n * amass_sumn(n - 1);
}

int fib(int n)
{
	if(n == 1 || n == 2)
		return 1;
	
	return fib(n - 1) + fib(n - 2);
}
