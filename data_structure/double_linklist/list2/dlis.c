#include<stdlib.h>
#include<string.h>

#include "dlist.h"


int dlist_init(dlist_head **head, int size)
{
	*head = malloc(sizeof(dlist_head));

	if(head == NULL)
		return -1;
	(*head)->node.next = (*head)->node.prev = &(*head)->node;
	(*head)->size = size;

	return 0;
}
static int __newnode(const dlist_head *head, struct node_st **newnode)
{
	*newnode = malloc(sizeof(struct node_st) + head->size);

	if(*newnode == NULL)
		return -1;
	return 0;
}

static int __nodeinit(dlist_head *head, struct node_st *newnode, const void *key)
{
	memcpy(&newnode + 1, key, head->size);

	return 0;
}

static int __nodeinsert(struct node_st *newnode, struct node_st *before, struct node_st *after)
{
	newnode->next = after;
	newnode->prev = before;
	after->prev = newnode;
	before->next = newnode;

	return 0;
}


int dlist_insert(dlist_head *head, const void *key, int way)
{
	struct node_st *f;

	__newnode(head, &f);

	if(f == NULL)
		return -1;
	
	__nodeinit(head, f, key);
	
	if(way == LIST_INSERT_HEAD)
	{
		__nodeinsert(f, &(head->node), head->node.next);	
	}else if(way == LIST_INSERT_TAIL){
		__nodeinsert(f, head->node.prev, &(head->node));
	}else{
		return 0;
	}

	return 0;
}

static int __find(dlist_head *head, const void *key, struct node_st **f)
{
	struct node_st cur;

	for(cur = head->node.next; cur != &head->node; cur = cur->next)
	{
		if(cmp(cur->data, key) == 0)
		{
			*f = cur;
			return 0;
		}
	}

	return -1;	
}

static int __fetch(dlist_head *head, struct node_st *node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	node->next = NULL;
	node->prev = NULL;

	return 0;
}



int dlist_del(dlist_head *head, const void *key, cmp_t cmp)
{
	struct node_st *f;
	int pos;

	pos = __find(head, key, &f);
	if(pos == -1)
		return -1;
	__fetch(head, f);

}
