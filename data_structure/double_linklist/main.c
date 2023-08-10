#include<stdio.h>
#include<string.h>
#include"d_list.h"

int show_str(const void *data);
static int cmp_s(const void *data, const void *key);

int main(int argc, char *argv[])
{
	dlist_t *mydlist = NULL;
	int i;

	dlist_init(&mydlist, sizeof(char *));
	for(i = 0; i < argc; i++)
	{
		//dlist_insert(mydlist, argv + i, DLIST_INSERT_HEAD);
		dlist_insert(mydlist, argv + i, DLIST_INSERT_TAIL);
	}
	dlist_traval(mydlist, show_str);

	//删除
	printf("*****del*****\n");
	dlist_del(mydlist, argv + 1, cmp_s);
	dlist_traval(mydlist, show_str);

	printf("****destory****\n");
	dlist_destory(mydlist);
	if(mydlist == NULL) 
		i = -1;
	printf("%d\n", i);

	return 0;
}

int show_str(const void *data)
{
	char **d = (char **)data;

	printf("%s\n", *d);

	return 0;
}

static int cmp_s(const void *data, const void *key)
{
	char **s1 = (char **)data;
	char **s2 = (char **)key;

	return strcmp(*s1, *s2);	
}
