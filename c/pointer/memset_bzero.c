#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char *p;

	p = malloc(100);
	
	memset(p,97,100);
	bzero(p,100);
	puts(p);
	
	return 0;
}
