#ifndef __DLIST_H__
#define __DLIST_H__

struct node_st{
	struct node_st *prev, *next;
	char data[0];
};

typedef struct{
	struct node_st node;
	int size;
}dlist_head;

enum{LIST_INSERT_HEAD, LIST_INSERT_TAIL};

typedef int (*cmp_t)(const void *data, const void *data);

int dlist_init(dlist_head **head, int size);

int dlist_insert(dlist_head *head, const void *key, int way);

int dlist_del(dlist_head *head, const void *key, cmp_t cmp);

#endif
