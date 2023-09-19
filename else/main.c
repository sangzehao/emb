#include "anytimer.h"

#define CAP 10

void show(void *s);

int main(void)
{
	int i = 0;
	int j;

	while(i < CAP)
	{
		timer_init(i, show, &i);
		i++;
	}

	for(i = 0; i < CAP; i++)
	{
		pause();
		timer_red();	
	}

	return 0;
}


void show(void *s)
{
	int *num = (int *)s;

	printf("pass %d second : alarm(%d)over!\n", *num + 1, *num + 1);
}
