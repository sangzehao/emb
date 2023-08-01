#include<stdio.h>
#include<string.h>

char *my_strncpy(char *p , const char *s, int n);
char *my_strncat(char *p, const char *s, int n);

int main(void)
{
	//char s[] ="hellohelli";
	char s[] ="hello";
	char a[10] = "we";
	
//	my_strncpy(a, s, 3);
	my_strncat(a, s, 7);
	puts(a);

	return 0;
}

char *my_strncpy(char *p , const char *s, int n)
{
	int i;

	for(i = 0; s[i] && i < n; i++)
	{
		p[i] = s[i];
	}
	p[i] = '\0';

	return p;
}

char *my_strncat(char *p, const char *s, int n)
{
	int len = strlen(p);
	int i;

	for(i = 0; s[i] && i < n; i++)
	{
		p[len + i] = s[i];
	}
	p[len + i] = '\0';

	return p;	
}
