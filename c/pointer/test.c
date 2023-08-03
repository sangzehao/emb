#include<stdio.h>
#include<stdlib.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int chu(int a, int b);
int op(int a, int b, int (*p)(int a, int b));

int main(int argc, char *argv[])
{
	int num1, num2;

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	if(*argv[2] == '+')
		printf("%d\n", op(num1, num2, add));

	return 0;


}
int op(int a, int b, int (*p)(int a, int b))
{
	return p(a, b);
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int chu(int a, int b)
{
	return a / b;
}
