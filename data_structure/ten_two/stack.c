#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"stack.h"

int stack_init(stack **mystack, int size)
{
	*mystack = malloc(sizeof(stack));

	if(*mystack == NULL)
		return -1;

	(*mystack)->s_p = NULL;
	(*mystack)->numb = 0;
	(*mystack)->size = size;

	return 0;
}

int stack_push(stack *mystack, const void *data)
{
	if(stack_isfull(mystack))
		return -1;

	mystack->s_p = realloc(mystack->s_p, (mystack->numb + 1) * mystack->size);

	if(mystack->s_p == NULL)
		return -1;
	memcpy((char *)mystack->s_p +mystack->size, mystack->s_p, mystack->numb * mystack->size);
	
	memcpy((char *)mystack->s_p, data, mystack->size);
	mystack->numb++;

	return 0;
}

static int __find(stack *mystack, const void *data, cmp_t p)
{
	int i; 

	for(i = 0; i < mystack->numb; i++)
	{
		if(p((char *)mystack->s_p + i * mystack->size, data) == 0)
			return i;
	}

	return -1;
}

int stack_del(stack *mystack, const void *data, cmp_t cmp)
{
	int f = __find(mystack, data, cmp);
	
	if(f == -1)
		return -1;
	memcpy((char *)mystack->s_p + f * mystack->size, (char *)mystack->s_p + (f + 1) * mystack->size, (mystack->numb - f -1) * mystack->size);
	mystack->numb--;
	mystack->s_p = realloc(mystack->s_p, mystack->numb * mystack->size);

	return 0;
}
int stack_pop(stack *mystack, void *key)
{
	if(stack_isempty(mystack))
		return -1;
	
	memcpy(key, (char *)mystack->s_p, mystack->size);
	memcpy((char *)mystack->s_p, (char *)mystack->s_p + mystack->size, (mystack->numb - 1) * mystack->size);
	mystack->numb--;
	mystack->s_p = realloc(mystack->s_p, mystack->numb * mystack->size);

	return 0;
}
int stack_chan(stack *mystack, const void *data, const void *key, cmp_t cmp)
{
	int f = __find(mystack, data, cmp);

	if(f == -1)
		return -1;
	memcpy((char *)mystack->s_p + f * mystack->size, key, mystack->size);

	return 0;

}
int stack_search(stack *mystack, const void *data, cmp_t cmp)
{	
	int f = __find(mystack, data, cmp);

	if(f == -1)
		return -1;
	return f;
}

int stack_traval(const stack *mystack, pri_t pri)
{
	int i;

	for(i = mystack->numb - 1; i >= 0; i--)
	{
		pri((char *)mystack->s_p + i * mystack->size);
	}

	return 0;
}

int stack_isempty(stack *mystack)
{
	return !mystack->numb;
}

int stack_isfull(stack *mystack)
{
	return mystack->numb == CAPACITY;
}

void stack_destory(stack *mystack)
{
	free(mystack->s_p);
	mystack->s_p = NULL;
	free(mystack);
	mystack = NULL;
}
