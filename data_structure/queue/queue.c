#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"queue.h"

int queue_init(queue **myque, int capacity, int size)
{
	*myque = malloc(sizeof(queue));
	if (*myque == NULL)
		return -1;
	(*myque)->front = (*myque)->tail = 0;
	(*myque)->capacity = capacity;
	(*myque)->size  = size; 
	(*myque)->start = calloc(capacity, size);
	
	return 0;
}

int queue_isempty(queue *myque)
{
	return myque->front == myque->tail;
}

int queue_isfull(queue *myque)
{
	return (myque->tail + 1) % myque->capacity == myque->front;
}


int queue_enq(queue *myque, const void *data)
{
	if(queue_isfull(myque))
		return -1;
	memcpy((char *)myque->start + myque->tail * myque->size, data, myque->size);


	myque->tail = (myque->tail + 1) % myque->capacity;
	
	return 0;
}

int queue_deq(queue *myque, void *data)
{
	if(queue_isempty(myque))
		return -1;
	memcpy(data, (char *)myque->start + myque->front * myque->size, myque->size);

	myque->front = (myque->front + 1) % myque->capacity;

	return 0;	

}

void queue_destory(queue **myque)
{
	free((*myque)->start);
	(*myque)->start = NULL;
	free(*myque);
	*myque = NULL;
}
