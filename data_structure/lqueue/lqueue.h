#ifndef __LQUEUE_H__
#define __LQUEUE_H__

#include "dlist.h"

typedef dlist_t lqueue_t;

int lqueue_init(lqueue_t **s, int size);

int lqueue_is_empty(const lqueue_t *s);

int lqueue_enq(lqueue_t *s, const void *data);

int lqueue_deq(lqueue_t *s, void *data);

void lqueue_destory(lqueue_t *s);

#endif
