#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char *s = malloc(sizeof(char) * 100);
//	s = "hello";
	//char *s;
	char *p = malloc(sizeof(char) * 100);
	p = "llo";
	printf("%s\n", s);

	*s = *p;

	printf("%s\n", s);

	return 0;

}

