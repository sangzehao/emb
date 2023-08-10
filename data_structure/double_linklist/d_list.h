#ifndef __D_LIST_H__
#define __D_LIST_H__

#include<stdlib.h>

struct node_dt
{
	void *data;
	struct node_dt *prev;
	struct node_dt *next;
};

typedef struct dlist_t{
	struct node_dt node;
	int size;
}dlist_t;

typedef int (*cmp_t)(const void *data, const void *key);
typedef int (*pri_t)(const void *data);

enum{DLIST_INSERT_HEAD, DLIST_INSERT_TAIL};
//初始化
int dlist_init(dlist_t **head, int size);

//插入
int dlist_insert(dlist_t *head, const void *data, int way);

//遍历
int dlist_traval(dlist_t *head, pri_t pri);

//删除
int dlist_del(dlist_t *head, const void *key, cmp_t cmp);

//销毁
int dlist_destory(dlist_t *head);


#endif
