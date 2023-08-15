#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#define CAPACITY 30

typedef struct{
	void *s_p;
	int numb;
	int size;
}stack;

typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);

int stack_init(stack **mystack, int size);

int stack_push(stack *mystack, const void *data);

int stack_del(stack *mystack, const void *data, cmp_t cmp);

int stack_pop(stack *mystack, void *key);

int stack_chan(stack *mystack, const void *data, const void *key, cmp_t cmp);

int stack_search(stack *mystack, const void *data, cmp_t cmp);

int stack_traval(const stack *mystack, pri_t pri);

int stack_isempty(stack *mystack);

int stack_isfull(stack *mystack);

void stack_destory(stack *mystack);

#endif
