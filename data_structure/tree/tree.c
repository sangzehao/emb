#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"


int tree_init(tree_t **mytree, int size)
{
	*mytree = malloc(sizeof(tree_t));

	if(*mytree == NULL)
		return -1;
	(*mytree)->root = NULL;
	(*mytree)->size = size;

	return 0;
}

static int __insert(struct node_st **root, const void*data, cmp_t cmp, int size)
{
	struct node_st *newnode;
	int ret;

	if(*root == NULL)
	{
		newnode = malloc (sizeof(struct node_st));
		if(newnode == NULL)
			return -1;
		newnode->data = malloc(size);
		if(newnode->data == NULL){
			free(newnode);
			newnode = NULL;
			return -1;
		}
		memcpy(newnode->data, data, size);	
		*root = newnode;
		(*root)->left = NULL;
		(*root)->right = NULL;

		return 0;
	}
	
	ret = cmp((*root)->data, data);

	if(ret > 0)//放左子树；
		__insert(&(*root)->left, data, cmp, size);
	else
		__insert(&(*root)->right, data, cmp, size);

}

int tree_insert(tree_t *mytree, const void *data, cmp_t cmp)
{
	return __insert(&(mytree->root), data, cmp, mytree->size);
}

//中序

static int __traval(const struct node_st *root, pri_t pri)
{
	if(NULL == root)
		return -1;
	__traval(root->left, pri);
	pri(root->data);
	__traval(root->right, pri);

}

int tree_traval(const tree_t *mytree, pri_t pri)
{
	return __traval(mytree->root, pri);
}

static struct node_st *__find(struct node_st *root, const void *data, cmp_t cmp)
{
	int ret;

	if(root == NULL)
		return NULL;
	
	ret = cmp((root)->data, data);
	
	if(ret == 0)
		return root;
	else if(ret > 0)
		return __find(root->left, data, cmp);
	else
		return __find(root->right, data, cmp);
}

int tree_search(const tree_t *mytree, const void *data, cmp_t cmp, pri_t pri)
{
	struct node_st *newnode;

	newnode = __find(mytree->root, data, cmp);

	if(NULL == newnode)
		return -1;
	pri(newnode->data);

	return 0;
}

static struct node_st *__max_l(struct node_st *root)
{
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return root;

	return __max_l(root->right);
}


static int __del(struct node_st **root, const void *data, cmp_t cmp)
{
	if(NULL == *root)
		return -1;

	struct node_st *r, *l, *del; 
	int res;
	
	res = cmp((*root)->data, data);
	
	r = (*root)->right;
	l = (*root)->left;
	del = *root;//记着，为了最后要释放
	if(0 == res)
	{
		if(l == NULL)
			*root = r;
		else
		{
			*root = (*root)->left;
			__max_l(l)->right = r;
		}
		del->left = del->right =NULL;
		free(del->data);
		del->data = NULL;
		free(del);
		del = NULL;
		return 0;
	}
	else if(res < 0)
		return __del(&(*root)->right, data, cmp);
	else
		return __del(&(*root)->left, data, cmp);

	return 0;
}

int tree_delete(tree_t *mytree, const void *data, cmp_t cmp)
{
	return __del(&mytree->root, data, cmp);
}
