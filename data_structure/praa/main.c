#include<stdio.h>
#include<string.h>
#include "queue.h"


//static void show_str(const void *data);
//static int cmp_str(const void *data, const void *data1);
int main(int argc, char *argv[])
{
//	int a[] = {1, 2, 3, 4, 5};
	char *p;
	int i;
	queue_t *mylist;
	queue_init(&mylist, sizeof(char *));
	
	for(i = 0; i < argc; i++)
	{
		if(queue_pull(mylist))
			break;
		//queue_push(mylist, &argv[i]);
		queue_push(mylist, argv + i);
	}	

	for(i = 0; i < argc; i++)
	{
		if(queue_empty(mylist))
			break;
		queue_pop(mylist, &p);
		printf("%s ", p);
	}
	printf("\n");
	return 0;
}
/*
static void show_str(const void *data)
{
	char **p = (char **)data;
	printf("%s\n", *p);
}

static int cmp_str(const void *data, const void *data1)
{
	node_t *p = (node_t *)data;
	char **p1 = (char **)data1;

	return strcmp(p->data, *p1);
}
*/

