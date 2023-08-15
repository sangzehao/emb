#ifndef __TREE_H__
#define __TREE_H__

struct node_st{
	void *data;
	struct node_st *left, *right;
};

typedef struct{
	struct node_st *root;
	int size;
}tree_t;

typedef int (*cmp_t)(const void *data, const void *newdata);

typedef int (*pri_t)(const void *data);

int tree_init(tree_t **mytree, int size);

//增
int tree_insert(tree_t *mytree, const void *newdata, cmp_t cmp );

//遍历
int tree_traval(const tree_t *mytree, pri_t pri);

//查找
int tree_search(const tree_t *mytree, const void *data, cmp_t cmp, pri_t pri);

int tree_delete(tree_t *mytree, const void *data, cmp_t cmp);



#endif
