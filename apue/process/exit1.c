#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler1(void)
{
	printf("1\n");
}

void handler2(void)
{
	printf("2\n");
}

int main(void)
{
	atexit(handler1);
	atexit(handler2);

	printf("fsf");

	exit(0);

	//_exit(0);

	//return 0;
}
