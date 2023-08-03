#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char *a = "hello";
	char *t = "hew";
	char *s = malloc(10);
	
	int (*p)(const char *, const char *);
	size_t (*q)(const char *);
	char *(*h)(char *, const char *);

	p = strcmp;
	q = strlen;
	h = strcpy;
	printf("size_t:%ld\n", sizeof(size_t));	
	printf("%d\n", p(a, t));
	printf("%ld\n", q(a));
	h(s, a);
	puts(s);
	
	return 0;
}
