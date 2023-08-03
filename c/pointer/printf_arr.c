#include<stdio.h>
#include<string.h>

void show_arr(const void *s, int n, int size, void (*p)(const void *));
void p_c(const void *p);
void p_i(const void *p);
void p_s(const void *p);

int main(void)
{
	char *s = "hello everyone";
	int a[] = {1,2,3,4,5,6,7,8};
	char *b[] = {"dfsf", "kgfj", "dfko"};
	
	printf("%s\n", *b);
	show_arr(s, strlen(s), sizeof(char), p_c);
	printf("\n");	
	show_arr(a, sizeof(a) / sizeof(int), sizeof(int), p_i);
	printf("\n");
	show_arr(b, sizeof(b) / sizeof(char *), sizeof(char *), p_s);
	printf("\n");

	return 0;
}
void p_s(const void *p)
{
	char **data = (char **)p;
	printf("%s ", *data);
}

void p_i(const void *p)
{
	int *data = (int *)p;

	printf("%d ", *data);
}

void p_c(const void *p)
{
	char *data = (char *)p;
	printf("%c", *data);
}

void show_arr(const void *s, int n, int size, void (*p)(const void *))
{
	int i;

	for(i = 0; i < n; i++)
	{
		p((char *)s + i * size);
	}

}
