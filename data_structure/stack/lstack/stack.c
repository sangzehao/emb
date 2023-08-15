#include<stdio.h>
#include "stack.h"


int stack_init(stack **mystack, int size)
{
	return listhead_init(mystack, size);
}

int stack_push(stack *mystack, const void *data)
{

	return list_insert(mystack, data, LIST_INSERT_HEAD);
}

static int  __alwaycmp(stack *mystack, void *data)
{
	return 0;
}	
	
int stack_pop(stack *mystack, void *data)
{
	return list_fetch(mystack, data, __alwaycmp);
}

void stack_destory(stack *mystack)
{
	return list_destroy(mystack);
}
