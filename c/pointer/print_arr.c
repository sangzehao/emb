#include<stdio.h>
#include<string.h>

int show_arr(const void *arr, int n, int size, void (*p)(const void *));
void p_c(const void *p);
void p_i(const void *p);
void p_s(const void *p);

int main(void)
{
	char s[] = "hello";
	int  a[] = {1,2,3,4,5,6,7};
	char *t[] = {"das", "jidj", "fdsu"};
	
	show_arr(s, strlen(s), sizeof(char), p_c);
	printf("\n");
	show_arr(a, sizeof(a) / sizeof(int), sizeof(int), p_i);
	printf("\n");
	show_arr(t, sizeof(t) / sizeof(char *), sizeof(char *), p_s);
	printf("\n");

	return 0;
}

void p_c(const void *p)
{
	const char *q = (const char *)p;

	printf("%c", *q);
}
void p_i(const void *p)
{
	const int *q = (const int *)p;
	
	printf("%d", *q);
}
void p_s(const void *p)
{
	const char **q = (const char **)p;
   	printf("%s ", *q);	
}
int show_arr(const void *arr, int n, int size, void (*p)(const void *))
{
	int i;

	for(i = 0; i < n; i++)
	{
		p((char *)arr + i * size);
	}
	
	return 0;
}
