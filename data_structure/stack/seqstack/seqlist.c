#include<stdlib.h>
#include<string.h>
#include "seqlist.h"


int seqlist_init(seqlist **mylist, int size)
{
	*mylist = malloc(sizeof(seqlist));
	
	if(*mylist == NULL)
		return -1;

	(*mylist)->s_p = NULL;
	(*mylist)->numb = 0;
	(*mylist)->size = size;

	return 0;
}

int seqlist_traval(seqlist *mylist, pri p)
{
	int i;

	for(i = 0; i < mylist->numb; i++)
	{
		p((char *)mylist->s_p + i * mylist->size);
	}
	
	return 0;
}

int seqlist_add(seqlist *mylist, const void *data)
{
	mylist->s_p = realloc(mylist->s_p, (mylist->numb + 1)* mylist->size);

	if(mylist->s_p == NULL)
		return -1;
	memcpy((char *)mylist->s_p + mylist->numb * mylist->size, data, mylist->size);
	mylist->numb++;

	return 0;
}
int seqlist_add_first(seqlist *mylist, const void *data)
{	
	mylist->s_p = realloc(mylist->s_p, (mylist->numb + 1) * mylist->size);
	if(mylist->s_p == NULL)
		return -1;
	memcpy((char *)mylist->s_p + mylist->size, (char *)mylist->s_p, mylist->numb * mylist->size);
//	memmove((char *)mylist->s_p + mylist->size, mylist->s_p, mylist->numb * mylist->size);

	memcpy(mylist->s_p, data, mylist->size);
	mylist->numb++;

	return 0;
}


static int __find(seqlist *mylist, const void *key, cmp p)
{
	int i;

	for(i = 0; i < mylist->numb; i++)
	{
		if(p((char *)mylist->s_p + i * mylist->size, key) == 0)
			return i;
	}

	return -1;
}

int seqlist_del(seqlist *mylist, const void *key, cmp p)
{
	int f = __find(mylist, key, p);

	if(f == -1)
		return -1;
	memcpy((char *)mylist->s_p + f * mylist->size, (char *)mylist->s_p + (f + 1) * mylist->size, (mylist->numb - f - 1) * mylist->size);
	mylist->numb--;
	mylist->s_p = realloc(mylist->s_p, mylist->numb * mylist->size);
	return 0;
}

int seqlist_chan(seqlist *mylist, const  void * key, cmp p)
{
	int f = __find(mylist, key, p);

	if(f == -1)
		return -1;

	memcpy((char *)mylist->s_p +f * mylist->size, key, mylist->size);

	return 0;
}

void *seqlist_search(seqlist *mylist, const void *key, cmp p)
{
	int f = __find(mylist, key, p);

	if(f == -1)
		return NULL;

	return (char *)mylist->s_p + f * mylist->size;
}

int seqlist_isempty(const seqlist *mylist)
{
	return mylist->numb == 0;
}

int seqlist_numb(const seqlist *mylist)
{
	return mylist->numb;
}

static int __ffind(seqlist *mylist, cmp p)
{
	return 1;
}

int seqlist_fetch(seqlist *mylist, void *key)
{
	memcpy(key, (char *)mylist->s_p, mylist->size);
	
	memcpy((char *)mylist->s_p, (char *)mylist->s_p + mylist->size, (mylist->numb - 1) * mylist->size);
	mylist->numb--;
	mylist->s_p = realloc(mylist->s_p, mylist->numb * mylist->size);
	if(mylist->s_p == NULL)
		return -1;

	return 0;
}

void seqlist_destory(seqlist *mylist)
{
	free(mylist->s_p);
	mylist->s_p = NULL;
	free(mylist);
	mylist = NULL;
}
