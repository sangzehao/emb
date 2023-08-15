#ifndef _STACK_H_
#define _STACK_H_
#include "list.h"
#define CAP 32
typedef head_t queue_t;

int queue_init(queue_t **myqueue, int size);//初始化
int queue_empty(queue_t *myqueue); //是否为空队列
int queue_pull(queue_t *myqueue);  //是否溢出
int queue_push(queue_t *myqueue, void *data);//入队
int queue_pop(queue_t *myqueue,void *data);
#endif

