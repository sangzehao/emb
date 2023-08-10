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

typedef int(*cmp)(const void *key1, const void *key2);

int seqlist_del(seqlist *mylist, const void *key, cmp p);

int seqlist_chan(seqlist *mylist, const void *key, cmp p);

void *seqlist_search(seqlist *mylist, const void *key, cmp p);

void *seqlist_binary_search(seqlia);

#endif
