#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int rever_str(char **p, const char *s);

int main(void)
{
	char *a = "hello word";
	char *q = NULL;

	rever_str(&q, a);
	puts(q);

	return 0;
}

int rever_str(char **p, const char *s)
{
	int i;

	*p = malloc(strlen(s) + 1);
	int len = strlen(s);
	if(*p == NULL)
		return -1;
	for(i = 0; len - 1 >= 0; i++,len--)
	{
		(*p)[i] = s[len - 1];
	}
	(*p)[i] = '\0';

	return 0;
}
