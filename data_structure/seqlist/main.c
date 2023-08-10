#include<stdio.h>
#include<string.h>
#include "seqlist.h"

#define NAMESIZE 32

typedef struct{
	int id;
	char name[NAMESIZE];
}stu_t;

int show_arr(void *p);
int cmp_i(const void *p, const void *q);
int cmp_s(const void *p, const void *q);
int cmp_ci(const void *p, const void *key);

int main(void)
{
	seqlist *list = NULL;
	stu_t stu ;
	stu_t st ;
	stu_t *stt;
	int i;
	int id;
	char *name;

	seqlist_init(&list, sizeof(seqlist));
	for(i = 1; i <= 10; i++)
	{
		stu.id = i;
		snprintf(stu.name, NAMESIZE, "stu%d", i);
		seqlist_add(list, &stu);
	}
	seqlist_traval(list, show_arr);
	st.id = 3;
	strcpy(st.name, "stu9");
	id = 2;
	name = "stu4";
	printf("************del************\n");
	seqlist_del(list, &id, cmp_i);
	seqlist_traval(list, show_arr);
	printf("************del************\n");
	seqlist_del(list, &name, cmp_s);
	seqlist_traval(list, show_arr);
	
	printf("************chan************\n");
	seqlist_chan(list, &st, cmp_ci);
	seqlist_traval(list, show_arr);

	printf("************search***********\n");
	name = "stu5";
	stt = (stu_t *)seqlist_search(list, &name, cmp_s);
	if(stt == NULL)
		printf("no\n");
	else
		printf("%d %s\n", stt->id, stt->name);

	return 0;	
}
int cmp_ci(const void *p, const void *key)
{
	stu_t *s1 = (stu_t *)p;
	stu_t *s2 = (stu_t *)key;

	return s1->id - s2->id;
}

int show_arr(void *q)
{
	stu_t *p = (stu_t *)q;

	printf("%d %s\n", p->id, p->name);
}

int cmp_i(const void *p, const void *q)
{
	stu_t *s = (stu_t *)p;
	int *data = (int *)q;

	return s->id - *data;
}

int cmp_s(const void *p, const void *q)
{
	stu_t *s = (stu_t *)p;

	char **data = (char **)q;

	return strcmp(s->name, *data);
}
