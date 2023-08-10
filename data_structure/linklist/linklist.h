#ifndef __LINKLIST_H__
#define __LINKLIST_H__

//数据结点类型
typedef struct node_st
{
	void *l_p;
	struct node_st *next;
}data_node;

//头结点类型
typedef struct
{
	int size;
	data_node *next;	
}listhead;

enum{LIST_INSERT_HEAD, LIST_INSERT_TAIL};

typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);
//初始化头结点
int listhead_init(listhead **head, int size);

//增
int list_insert(listhead *head, const void *data, int way);

//删
int list_del(const listhead *head, const void *key, cmp_t cmp);

//改
int list_chan(const listhead *head, const void *key, cmp_t cmp);

//查
void *list_search(const listhead *head, const void *key, cmp_t cmp);

//遍历

void list_traval(const listhead* head, pri_t pri);

//销毁
int list_destory(listhead* head);

#endif
