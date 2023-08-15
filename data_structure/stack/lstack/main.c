#include <stdio.h>

#include "list.h"

static void show_string(const void *data);

int main(int argc, char *argv[])
{
	int i;

	listhead_t *mylist = NULL;
	listhead_t *newlist = NULL;

	// 单链表中存储的是指针数组中的每一个元素(指针)
	listhead_init(&mylist, sizeof(char *));

	for (i = 0; i < argc; i++) {
		// list_insert(mylist, argv + i, LIST_INSERT_HEAD);
		list_insert(mylist, argv + i, LIST_INSERT_TAIL);
	}

	list_traval(mylist, show_string);

	// 产生逆序新链表
	printf("**************新链表*****************\n");
	list_newlist_reverse(&newlist, mylist);
	list_traval(newlist, show_string);
	printf("*************逆序*************\n");
	list_reverse(newlist);
	list_traval(newlist, show_string);

	list_destroy(mylist);

	return 0;
}

static void show_string(const void *data)
{
	char **d = (char **)data;
	printf("%s\n", *d);
}


