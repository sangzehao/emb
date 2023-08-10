#include<stdio.h>
#include"dlist.h"

int main(int argc, char *argv[])
{
	dlist_head *mylist;
	int i;

	dlist_init(&mylist, sizeof(char *));

	for(i = 1; i < argc; i++)
	{
		dlist_insert(mylist, argv + 1, LIST_INSERT_HEAD);
	}


	return 0;
}
