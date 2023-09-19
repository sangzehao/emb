#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

int p_int(const void *data);
int cmp_int(const void *data, const void *new);

int main(void)
{
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	int i;
	int num = 3;
	int num2 = 6;
	int num_t = 33;

	list_t *mylist;

	list_init(&mylist, sizeof(int));

	if(NULL == mylist)
		return -1;
	
	for(i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		list_insert(mylist, &arr[i]);
	}
	list_traval(mylist, p_int);
	printf("\n");

	list_search(mylist, &num, cmp_int, p_int);
	printf("\n");

	list_del(mylist, &num, cmp_int);
	list_traval(mylist, p_int);
	printf("\n");

	list_chan(mylist, &num2, &num_t, cmp_int);
	list_traval(mylist, p_int);
	printf("\n");

	list_destory(&mylist);

	return 0;
}

int cmp_int(const void *data, const void *new)
{
	int *s1 = (int *)data;
	int *s2 = (int *)new;
	
	return *s1 - *s2;
}

int p_int(const void *data)
{
	int *s = (int *)data;

	printf("%d ", *s);
	
	return 0;
}
