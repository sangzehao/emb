#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int reverstring(char *p, const char *s);

int main(void)
{
	char s[] = "hello";
//	char *a = (char *)malloc((strlen(s) + 1) * sizeof(char));
	char *a = NULL;	

	reverstring(a, s);
	puts(a);

	return 0;
}

int reverstring(char *p, const char *s)
{
	int len, i;

	len  = strlen(s);
	for(i= 0; len -1>= 0; i++, len--)
	{
		*(p + i) = s[len - 1];
	}

	return 0;



}
