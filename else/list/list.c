#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"


int list_init(list_t **mylist, int size)
{
	*mylist = malloc(sizeof(list_t));

	if(NULL == *mylist)
		return -1;
	(*mylist)->node.prev = (*mylist)->node.next = &(*mylist)->node;
	(*mylist)->size = size;
	
	return 0;
}

static int __init(struct node_st **newnode, const void *data, int size)
{
	*newnode = malloc(sizeof(struct node_st));

	if(NULL == *newnode)
		return -1;

	(*newnode)->data = malloc(size);
	if(NULL == (*newnode)->data)
	{
		free(*newnode);
		*newnode = NULL;
		return -1;
	}

	memcpy((*newnode)->data, data, size);
	
	return 0;
}

static int __insert(struct node_st *before, struct node_st *new, struct node_st *after)
{
	before->next = new;
	after->prev = new;
	new->next = after;
	new->prev = before;

	return 0;
}


int list_insert(list_t *mylist, const void *data)
{
	struct node_st *mynode;

	__init(&mynode, data, mylist->size);

	__insert(&mylist->node, mynode, mylist->node.next);

	return 0;
}


int list_traval(list_t *mylist, pri_t pri)
{
	struct node_st *cur;

	for(cur = mylist->node.next; cur != &mylist->node; cur = cur->next)
	{
		pri(cur->data);
	}	

	return 0;
}


static struct node_st *__find(list_t *mylist, const void *data, cmp_t cmp)
{
	struct node_st *cur;

	for(cur = mylist->node.next; cur != &mylist->node; cur = cur->next)
	{
		if(0 == cmp(cur->data, data))
			return cur;
	}

	return NULL;
}

int list_search(list_t *mylist, const void *data, cmp_t cmp, pri_t pri)
{
	struct node_st *mynode;

	mynode = __find(mylist, data, cmp);

	if(NULL == mynode)
		return -1;
	pri(mynode->data);
	
	return 0;
}

static int __fetch(struct node_st *mynode)
{
	mynode->prev->next = mynode->next;
	mynode->next->prev = mynode->prev;
	mynode->next = NULL;
	mynode->prev = NULL;

	return 0;
}

static void __destory(struct node_st **mynode)
{
	free((*mynode)->data);
	(*mynode)->data = NULL;
	free(*mynode);
	*mynode = NULL;
}

int list_del(list_t *mylist, const void *data, cmp_t cmp)
{
	struct node_st *mynode;

	mynode = __find(mylist, data, cmp);

	if(NULL == mynode)
		return -1;
	__fetch(mynode);


	
	return 0;
}

static void __des(struct node_st *mynode)
{
	free(mynode->data);
	mynode->data = NULL;
	free(mynode);
	mynode = NULL;
}
int list_chan(list_t *mylist, const void *data, const void *newdata, cmp_t cmp)
{
	struct node_st *mynode;

	mynode = __find(mylist, data, cmp);

	if(NULL == mynode)
		return -1;
	
	memcpy(mynode->data, newdata, mylist->size);

	return 0;
}
static int __cmp(const void *data1, const void *data2)
{
	return 0;
}

void list_destory(list_t **mylist)
{
	struct node_st *cur;
	
	while((*mylist)->node.next != &(*mylist)->node && (*mylist)->node.prev != &(*mylist)->node)
		list_del(*mylist, NULL, __cmp);
//得一个一个删除，不能for循环
	free(*mylist);
	*mylist = NULL;

}
