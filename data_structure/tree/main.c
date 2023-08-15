#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

static int int_cmp(const void *data, const void *newdata);
static int p_out(const void *data);

int main(void)
{
	int arr[] = {7,1,3,9,0,4,2,5,6,8};
	int i;
	int num = 6;

	tree_t *mytree;

	tree_init(&mytree, sizeof(int));

	for(i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		tree_insert(mytree, &i, int_cmp);
	}
	
	tree_traval(mytree, p_out);
	printf("\n");

	tree_search(mytree, &num, int_cmp, p_out);
	printf("\n");

	tree_delete(mytree, &num, int_cmp);
	tree_traval(mytree, p_out);
	printf("\n");

	return 0;
}

static int int_cmp(const void *data, const void *newdata)
{
	int *p1 = (int *)data;
	int *p2 = (int *)newdata;

	return *p1 - *p2;
}

static int p_out(const void *data)
{
	int *s = (int *)data;
	
	printf("%d ", *s);

	return 0;
}
