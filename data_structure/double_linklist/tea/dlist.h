#ifndef __DLIST_H__
#define __DLIST_H__

/*struct node_st {
	void *data;
	struct node_st *prev, *next;
};*/

struct node_st {
	struct node_st *prev, *next;
	char data[0];
};

typedef struct {
	struct node_st node;
	int size;
}dlist_t;

typedef int (*cmp_t)(const void *data, const void *key);

typedef void (*pri_t)(const void *data);

int dlisthead_init(dlist_t **head, int size);

int dlist_head_insert(dlist_t *head, const void *data);

int dlist_tail_insert(dlist_t *head, const void *data);

int dlist_delete(dlist_t *head, const void *key, cmp_t cmp);

void dlist_traval(dlist_t *head, pri_t pri);

void dlist_destory(dlist_t *head);

int dlist_fetch(dlist_t *head, const void *key, cmp_t cmp, void *data);

int dlist_is_empty(const dlist_t *head);

void *dlist_get_first(const dlist_t *head);

#endif
