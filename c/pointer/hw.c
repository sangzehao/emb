#include<stdio.h>

char *mystr(const char *haystack, const char *needle);

int main(void)
{
	char a[] = "heoloiliol";
	char s[] = "ol";

	printf("%p\n", a);	
	printf("%p\n", mystr(a, s));
	printf("%ld\n", mystr(a, s) - a);
	
	return 0;
}

char *mystr(const char *haystack, const char *needle)
{
	while(*haystack)
	{
		const char *a = haystack;
		const char *b = needle;

		while(*a == *b && *b)
		{
			a++;
			b++;
		}
		if(!*b)
			return (char *)haystack;
		haystack++;
	}
	return NULL;
}
