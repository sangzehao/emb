#include <stdio.h>
#include "dlist.h"

static void show_char(const void *data);
static int char_cmp(const void *data, const void *key);

int main(int argc, char *argv[])
{
	dlist_t *mylist;
	int i;
	char c;

	// 将argv[1]的每一个字符存储到双向环链中
	if (argc < 2)
		return 1;

	dlisthead_init(&mylist, sizeof(char));
	for (i = 0; argv[1][i]; i++) {
		// dlist_head_insert(mylist, argv[1] + i);
		dlist_tail_insert(mylist, argv[1] + i);
	}
	dlist_traval(mylist, show_char);
	putchar('\n');
	printf("**************删除*************\n");
	c = '3';
	dlist_delete(mylist, &c, char_cmp);
	dlist_traval(mylist, show_char);
	putchar('\n');

	dlist_destory(mylist);

	return 0;
}

static void show_char(const void *data)
{
	const char *d = data;
	putchar(*d);
}

static int char_cmp(const void *data, const void *key)
{
	const char *d = (const char *)data;
	const char *k = (const char *)key;

	return *d - *k;
}


