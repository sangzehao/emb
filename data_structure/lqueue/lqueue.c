#include <stdio.h>
#include "lqueue.h"

int lqueue_init(lqueue_t **s, int size)
{
	return dlisthead_init(s, size);
}

int lqueue_is_empty(const lqueue_t *s)
{
	return dlist_is_empty(s);
}

int lqueue_enq(lqueue_t *s, const void *data)
{
	return dlist_tail_insert(s, data);
}
static int __alway_cmp(const void *data, const void *key)
{
	return 0;
}

int lqueue_deq(lqueue_t *s, void *data)
{
	return dlist_fetch(s, NULL, __alway_cmp, data);
}

void lqueue_destory(lqueue_t *s)
{
	dlist_destroy(s);
}
