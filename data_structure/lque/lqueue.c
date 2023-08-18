#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"lqueue.h"

int queue_init(lqueue **myque, int size)
{
	*myque = malloc(sizeof(lqueue));

	if(NULL == *myque)
		return -1;

	(*myque)->size = size;
	(*myque)->node.prev = (*myque)->node.next = &((*myque)->node);
	(*myque)->node.data = NULL;

	return 0;
}
int queue_enq(lqueue *myque, const void *data)
{
	struct node_st *mynode;
	
	mynode = malloc(sizeof(struct node_st));
	if(NULL == mynode)
		return -1;
	mynode->data = malloc(myque->size);
	if(NULL == mynode->data)
	{
		free(mynode);
		mynode = NULL;
		return -1;
	}
	memcpy(mynode->data, data, myque->size);
	//头插

	mynode->next = myque->node.next;
	mynode->prev = &myque->node;
	(myque->node.next)->prev = mynode;
	myque->node.next = mynode;
	
	return 0;
}

int queue_deq(lqueue *myque, void *data)
{
	struct node_st *newnode;
	
	newnode = myque->node.prev;

	memcpy(data, newnode->data, myque->size);
	newnode->prev->next = newnode->next;
	newnode->next->prev = newnode->prev;
	newnode->next = NULL;
	newnode->prev = NULL;
	free(newnode->data);
	newnode->data = NULL;
	free(newnode);
	newnode = NULL;
	
	return 0;
}

int queue_isempty(lqueue *myque)
{
	return (myque->node.next == &myque->node) && (myque->node.prev == &myque->node);
}
