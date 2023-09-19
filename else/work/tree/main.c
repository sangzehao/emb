#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

int cmp_int(const void *data, const void *newdata);
int p_int(const void *data);

int main(void)
{
	int a[10] = {3,4,2,1,6,7,9,4,3,0};
	int i;
	int num = 6;

	tree_t *mytree;

	tree_init(&mytree, sizeof(int));

	if(NULL == mytree)
		return -1;

	for(i = 0; i < 10; i++)
	{
		tree_insert(mytree, &a[i], cmp_int);
	}

	tree_traval(mytree, p_int);
	printf("\n");

	tree_search(mytree, &num, cmp_int, p_int);
	printf("\n");

	tree_del(mytree, &num, cmp_int);
	tree_traval(mytree, p_int);
	printf("\n");

	tree_destory(&mytree);

	return 0;
}

int cmp_int(const void *data, const void *newdata)
{
	int *d1 = (int *)data;
	int *d2 = (int *)newdata;

	return *d1 - *d2;
}

int p_int(const void *data)
{
	int *d = (int *)data;

	printf("%d ", *d);

	return 0;
}
