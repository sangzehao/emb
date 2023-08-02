#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add_element(int **p, int *len, int n);
int show_arr(const int *p, int *len);
int del_element(int **p, int *len, int elem);
int change(int *p, int *len, int n, int elem);
int find_it(int *p, int *len, int elem);

int main(void)
{
	int *p = NULL;
	int i, len;
	
	len = 0;
	for(i = 0; i < 10; i++)
	{
		add_element(&p, &len, i);
	}	
	show_arr(p, &len);
	printf("len:%d\n", len);
	del_element(&p, &len, 7);
	show_arr(p, &len);
	printf("len:%d\n", len);
	change(p, &len, 3, 33);
	show_arr(p, &len);
	printf("len:%d\n", len);
	i = find_it (p, &len, 6);

	printf("position:%d\n", i);

	return 0;
}

int show_arr(const int *p, int *len)
{
	int i;

	for(i = 0; i < *len; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");

	return 0;
}

static int search_of(const int *p, int *len, int n)//查找有没有
{
	int i;

	for(i = 0; i < *len; i++)
	{
		if(p[i] == n)
			return i;
	}

	return -1;
}

int add_element(int **p, int *len, int n)
{
	*p = realloc(*p, (*len + 1) * sizeof(int));
	if(NULL == *p)
		return -1;
	(*p)[*len] = n;
	(*len)++;

	return 0;
}

int del_element(int **p, int *len, int elem)
{
	int i;

	i = search_of(*p, len, elem);
	if(i != -1)
	{
		for(i; i < *len - 1; i++)
			(*p)[i] = (*p)[i + 1];
	}
	(*len)--;
	*p = realloc(*p, *len * sizeof(int));

	return 0;
}

int change(int *p, int *len, int n, int elem)
{
	int i = search_of (p, len, n);

	if(i != -1)
	{
		p[i] = elem;
	}

	return 0;
}

int find_it(int *p, int *len, int elem)
{
	int i = search_of (p, len, elem);
	if(i != -1)
		return i;
	return -1;
}
