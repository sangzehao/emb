#include<stdlib.h>
#include<string.h>
#include"dlist.h"

int dlisthead_init(dlist_t **head, int size)
{
	*head = malloc(sizeof(dlist_t));

	if(NULL == *head)
		return -1;

	(*head)->node.data = NULL;
	(*head)->node.prev = &(*head)->node;
	(*head)->node.prev = &(*head)->node;
	(*head)->size = size;

	return 0;
}

static int __node_init(struct node_st **newnode, const void *data, int size)
{
	*newnode = malloc(sizeof(struct node_st));
	if(NULL == *newnode)
		return -1;
	(*newnode)->data = malloc(size);
	if(NULL == (*newnode)->data)
	{
		free(*newnode);
		return -1;
	}
	memcpy((*newnode)->data, data, size);

	return 0;
}

static void __insert(struct node_st *newnode, struct node_st *before, struct node_st *after)
{
	newnode->prev = before;
	newnode->next = after;
	before->next = newnode;
	after->prev = newnode;
}

int dlist_head_insert(dlist_t *head, const void *data)
{
	struct node_st *mynode;

	__node_init(&mynode, data, head->size);

	__insert(mynode, &head->node, head->node.next);
}

int dlist_tail_insert(dlist_t *head, const void *data)
{
	struct node_st *mynode;
	
	__node_init(&mynode, data, head->size);

	__insert(mynode, head->node.prev, &head->node);
}

static int __find(dlist_t *head, const void *key, cmp_t cmp, struct node_st **findnode)
{
	struct node_st *cur;

	for(cur = head->node.next; cur != &head->node; cur = cur->next)
	{
		if(cmp(cur->data, key) == 0)
		{
			*findnode = cur;
			return 0;
		}
	}

	return -1;
}

static void __fetch(struct node_st *f)
{
	f->prev->next = f->next;
	f->next->prev = f->prev;
	f->prev = f->next = NULL;
}

static void __destory(struct node_st *f)
{
	free(f->data);
	f->data = NULL;
	free(f);
	f = NULL;
}

int dlist_delete(dlist_t *head, const void *key, cmp_t cmp)
{
	struct node_st *f;

	if(-1 == __find(head, key, cmp, &f))
		return -1;

	__fetch(f);

	__destory(f);

	return 0;
}

void dlist_traval(dlist_t *head, pri_t pri)
{
	struct node_st *cur;

	for(cur = head->node.next; cur != &head->node; cur = cur->next)
		pri(cur->data);
}

static int __always_cmp(const void *data, const void *key)
{
	return 0;
}

void dlist_destory(dlist_t *head)
{
	while(head->node.next != &head->node)
	{
		dlist_delete(head, NULL, __always_cmp);
	}

	free(head);
	head = NULL;
}

int dlist_fetch(dlist_t *head, const void *key, cmp_t cmp, void *data){
	
	struct node_st *cur;
	
	int f = __find(head, key, cmp, &cur);

	if(f == -1)
		return -1;

	memcpy(data, cur->data, head->size);
	__fetch(cur);

	__destory(cur);

	return 0l;
}

int dlist_is_empty(const dlist_t *head)
{
	if(head->node.next == &head->node)
		return 0;

	return -1;
}

void *dlist_get_first(const dlist_t *head)
{
	int f = dlist_is_empty(head);

	if(f == -1)
		return NULL;
	
	return (head->node.next)->data;
}
