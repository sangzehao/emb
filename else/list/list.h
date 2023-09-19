#ifndef __LIST_H__
#define __LIST_H__

struct node_st{
	void *data;
	struct node_st *prev, *next;
};

typedef struct{
	struct node_st node;
	int size;
}list_t;

typedef int (*cmp_t)(const void *data, const void *newdata);

typedef int (*pri_t)(const void *data);

int list_init(list_t **mylist, int size);

int list_insert(list_t *mylist, const void *data);

int list_del(list_t *mylist, const void *data, cmp_t cmp);

//改
int list_chan(list_t *mylist, const void *data, const void *newdata, cmp_t cmp);

int list_search(list_t *mylist, const void *data, cmp_t cmp, pri_t pri);

int list_traval(list_t *mylist, pri_t pri);

void list_destory(list_t **mylist);

#endif
