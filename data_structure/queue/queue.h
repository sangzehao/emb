#ifndef __QUEUE_H__
#define __QUEUE_H__


typedef struct{
	void *start;//data
	int front;
	int tail;
	int capacity;
	int size;
}queue;


int queue_init(queue **myque, int capacity, int size);

int queue_enq(queue *myque, const void *data);

int queue_deq(queue *myque, void *data);

int queue_isempty(queue *myque);

int queue_isfull(queue *myque);

void queue_destory(queue **myque);

#endif
