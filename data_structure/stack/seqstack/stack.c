#include<stdio.h>
#include"stack.h"

int stack_init(stack **s, int size)
{
	return seqlist_init(s, size);
}

int stack_is_empty(const stack *s)
{
	return seqlist_isempty(s);
}

int stack_is_full(const stack *s)
{
	return seqlist_numb(s) == STACK_FULL;
}

int stack_push(stack *s, const void *data)
{
	if(stack_is_full(s))
		return -1;

	return seqlist_add_first(s, data);
}

int stack_pop(stack *s, void *data)
{
	if(stack_is_empty(s))
		return -1;
	
	return seqlist_fetch(s, data);
}

void stack_destory(stack *s)
{
	return seqlist_destory(s);
}
