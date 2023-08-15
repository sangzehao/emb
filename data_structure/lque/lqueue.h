#ifndef __LQUEUE_H__
#define __LQUEUE_H__

struct node_st{
	void  *data;
	struct node_st *prev, *next;
};

typedef struct{
	struct node_st node;
	int size;
}lqueue;

typedef int (*pri)(const void *data);

int queue_init(lqueue **myque, int size);

int queue_isempty(lqueue *myque);

int queue_enq(lqueue *myque, const void *data);

int queue_deq(lqueue *myque, void *data);

int queue_destory(lqueue *myque);
#endif
