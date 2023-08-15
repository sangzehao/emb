#ifndef __SEQLIST_H__
#define __SEQLIST_H__

typedef struct{ //顺序表
	void *s_p;
	int numb;
	int size;
}seqlist;



int seqlist_init(seqlist **mylist, int size);

typedef int (*pri)(void *p);

int seqlist_traval(seqlist *mylist, pri p);

int seqlist_add(seqlist *mylist, const void *data);

//增加新元素在首位置
int seqlist_add_first(seqlist *mylist, const void *data);

typedef int(*cmp)(const void *key1, const void *key2);

int seqlist_del(seqlist *mylist, const void *key, cmp p);

//取出数据并删除

int seqlist_fetch(seqlist *mylist, void *key);

int seqlist_chan(seqlist *mylist, const void *key, cmp p);

void *seqlist_search(seqlist *mylist, const void *key, cmp p);

//二分查找
void *seqlist_binary_search(seqlist *mylist);

//判断是否为空
int seqlist_isempty(const seqlist *mylist);

//是否超过容量
int seqlist_numb(const seqlist *mylist);

void seqlist_destory(seqlist *mylist);

#endif
