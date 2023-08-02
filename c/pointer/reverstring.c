#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int reverString(char **p, const char *s);

int main(void)
{
	char *a = NULL;

	reverString(&a, "hello everyone");
	puts(a);

	free(a);
	a = NULL;
		
	return 0;
}

int reverString(char **p, const char *s)
{
	int len, i;

	len = strlen(s);
	*p = malloc(len + 1);
	if(*p == NULL)
		return 0;
	for(i = 0; len - 1 >= 0; len--, i++)
	{
		*(*p + i) = s[len - 1];
	}
	(*p)[i] = '\0';

	return 1;
}
