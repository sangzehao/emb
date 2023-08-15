#ifndef __STACK_H__
#define __STACK_H__

include "list.h"

typedef listhead_t stack;

int listhead_init(stack **mystack, int size);

int stack_push(stack *mystack, const void *key);

int stack_pop(stack *mystack, void *key);

void stack_destory(stack *mystack);

