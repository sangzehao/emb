#ifndef __DLIST_H__
#define __DLIST_H__

// ADT
// 数据结点
struct node_st {
	struct node_st *prev, *next; // 前驱 后继指针域
	char data[0]; // 数据域
};

// 头结点
typedef struct {
	struct node_st node;
	int size;
}dlist_t; 

typedef int (*cmp_t)(const void *data, const void *key);

typedef void (*pri_t)(const void *data);

// 初始化头结点
int dlisthead_init(dlist_t **head, int size);

// 插入
int dlist_head_insert(dlist_t *head, const void *data);

int dlist_tail_insert(dlist_t *head, const void *data);

// 删除
int dlist_delete(dlist_t *head, const void *key, cmp_t cmp);

// 查找
void *dlist_search(const dlist_t *head, const void *key, cmp_t cmp);

// 获取结点：得到指定结点的数据并将这个结点从链表中移除
int dlist_fetch(dlist_t *head, const void *key, cmp_t cmp, void *data);

// 遍历
void dlist_traval(const dlist_t *head, pri_t pri);

// 销毁
void dlist_destroy(dlist_t *head);

// 链表是否为空
int dlist_is_empty(const dlist_t *head);

// 获取第一个数据结点的数据
void *dlist_get_first(const dlist_t *head);


#endif

