#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "dls_stack.h"

int stack_init(stack **mystack, int size)
{
	*mystack = malloc(sizeof(stack));

	if(*mystack == NULL)
		return -1;

	(*mystack)->size = size;
	(*mystack)->node.prev = &(*mystack)->node;
	(*mystack)->node.next = &(*mystack)->node;

	return 0;
}

static int __node_init(struct node_st **mynode, const void *data, int size)
{
	*mynode = malloc(sizeof(struct node_st) + size);
	
	if(*mynode == NULL)
		return -1;
	memcpy((*mynode)->data, data, size);

	return 0;
}

static void __node_insert(struct node_st *prev, struct node_st *mynode, struct node_st *next)
{
	mynode->next = next;
	mynode->prev = prev;
	prev->next = mynode;
	next->prev = mynode;
}

int stack_push(stack *mystack, const void *data)
{
	struct node_st *newnode;

	__node_init(&newnode, data, mystack->size);
	
	__node_insert(&mystack->node, newnode, mystack->node.next);

	return 0;
}

static void __fetch(struct node_st *mynode)
{
	mynode->next->prev = mynode->prev;
	mynode->prev->next = mynode->next;
	mynode->next = NULL;
	mynode->prev = NULL;
}
static void __destory(struct node_st *mynode)
{
	free(mynode);
	mynode = NULL;
}
static int __find(const stack *stack, const void *key, cmp_t cmp, struct node_st **findnode)
{
	struct node_st *cur;

	for(cur = stack->node.next; cur != &stack->node; cur = cur->next)
	{
		if(cmp(cur->data, key) == 0)
		{
			*findnode = cur;
			return 0;
		}

		return -1;
	}
}

/*int stack_pop(stack *mystack, void *data)
{

	__fetch(mystack->node.next);
	memcpy(data, (mystack->node.next)->data, mystack->size);
	__destory(mystack->node.next);

	return 0;
}*/

static int stack_fetch(stack *mystack, const void *key, cmp_t cmp, void *data)
{
	struct node_st *f = NULL;

	__find(mystack, key, cmp, &f);

	if(NULL == f)
		return -1;
	__fetch(f);
	memcpy(data, f->data, mystack->size);
	__destory(f);

	return 0;
}
static int __alway_cmp(const void *data, const void *key)
{
	return 0;
}

int stack_pop(stack *s, void *data)
{
	return stack_fetch(s, NULL, __alway_cmp, data);
}


int stack_isempty(stack *mystack)
{
	return mystack->node.next == &mystack->node;
}
