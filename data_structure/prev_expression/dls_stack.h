#ifndef __STACH_H__
#define __STACH_H__


#include<stdio.h>

struct node_st{
	struct node_st *prev, *next;
	char data[0];
};

typedef struct {
	struct node_st node;
	int size;
}stack;

typedef int (*cmp_t)(const void *data, const void *key);

int stack_init(stack **mystack, int size);

int stack_push(stack *mystack, const void *data);

int stack_pop(stack *mystack, void *data);

int stack_isempty(stack *mystack);

int stack_destory(stack *mystack);

#endif
