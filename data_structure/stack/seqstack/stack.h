#ifndef __STACK_H__
#define __STACK_H__

#include "seqlist.h"

#define STACK_FULL 50

typedef seqlist stack;

int stack_init(stack **s, int size);

int stack_is_empty(const stack *s);

int stack_is_full(const stack *s);

int stack_push(stack *s, const void *data);

int stack_pop(stack *s, void *data);

void stack_destory(stack *s);

#endif

