#ifndef __LIST_H__
#define __LIST_H__

// 数据结点
struct node_st {
	void *data;
	struct node_st *next;
};

// 头结点
typedef struct {
	struct node_st node;
	int size;
}listhead_t;

// 插入方式 头插 尾插
enum {LIST_INSERT_HEAD, LIST_INSERT_TAIL};

typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);

// 初始化头结点
int listhead_init(listhead_t **head, int size);

// 插入
int list_insert(listhead_t *head, const void *data, int way);
// 删除
int list_delete(listhead_t *head, const void *key, cmp_t cmp);

//取出
int list_fetch(listhead_t *head, void *key, cmp_t cmp);

// 查找
void *list_search(const listhead_t *head, const void *key, cmp_t cmp);

// 遍历
void list_traval(const listhead_t *head, pri_t pri);

// 销毁
void list_destroy(listhead_t *head);

// 逆序生成一个新的链表返回
// listhead_t *list_newlist_reverse(const listhead_t *head);
int list_newlist_reverse(listhead_t **newhead, const listhead_t *head);

// 将链表逆序
void list_reverse(listhead_t *head);

#endif

