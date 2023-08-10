#include<stdio.h>
#include<string.h>
#include"list.h"

static void show_string(const void *data);
static int cmp_s(const void *data, const void *key);

int main(int argc, char *argv[])
{
	int i;

	listhead_t *mylist = NULL;
	listhead_t *revlist = NULL;
	listhead_init(&mylist, sizeof(char *));
	struct node_st *mid;

	for(i = 1; i < argc; i++)
	{
		//list_insert(mylist, argv + i, LIST_INSERT_TAIL);
		list_insert(mylist, argv +i, LIST_INSERT_HEAD);
	}
	list_traval(mylist, show_string);

	//删除
	list_delete(mylist, argv + 1, cmp_s);
	list_traval(mylist, show_string);

	printf("****reverse****\n");
	list_reverse(&revlist, mylist);
	list_traval(revlist, show_string);

	printf("****self_reverse_****\n");	
	list_self_reverse(mylist);
	list_traval(mylist, show_string);

	printf("*****mid*****\n");
	list_mid(mylist, &mid);
	printf("%s\n", *(char **)mid->data);

}

static void show_string(const void *data)
{
	char **d = (char **)data;

	printf("%s\n", *d);
}

static int cmp_s(const void *data, const void *key)
{
	char **p1 = (char **)data;
	char **p2 = (char **)key;

	return strcmp(*p1, *p2);
}
