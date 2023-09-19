#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"

int tree_init(tree_t **mytree, int size)
{
	*mytree = malloc(sizeof(tree_t));

	if(NULL == *mytree)
		return -1;

	(*mytree)->root = NULL;
	(*mytree)->size = size;
		
	return 0;
}

static int __node_init(struct node_st **mynode, const void *data, int size)
{
	*mynode = malloc(sizeof(struct node_st));

	if(NULL == *mynode)
		return -1;
	(*mynode)->data = malloc(size);
	if(NULL == (*mynode)->data)
	{
		free(*mynode);
		(*mynode)->data = NULL;
		return -1;
	}

	memcpy((*mynode)->data, data, size);

	return 0;
}

static int __node_insert(struct node_st **root, struct node_st **mynode, cmp_t cmp)
{
		int ret;

		if(NULL == *root)
		{
			*root = *mynode;
			return 0;
		}
	
		ret = cmp((*root)->data, (*mynode)->data);

		if(ret <= 0)
		{
			__node_insert(&(*root)->right, mynode, cmp);
		}
		else
		{
			__node_insert(&(*root)->left, mynode, cmp);
		}
		
		return 0;		
}

int tree_insert(tree_t *mytree, const void *data, cmp_t cmp)
{
	struct node_st *node;
	int ret;	

	ret = __node_init(&node, data, mytree->size);

	if(-1 == ret)
		return -1;

	__node_insert(&mytree->root, &node, cmp);

	return 0;
}

static int __traval(const struct node_st *root, pri_t pri)
{
	if(NULL == root)
		return -1;

	__traval(root->left, pri);
	pri(root->data);
	__traval(root->right, pri);

	return 0;
}

int tree_traval(const tree_t *mytree, pri_t pri)
{
	struct node_st *cur;
	int ret;
	
	__traval(mytree->root, pri);
}

static int __search(const struct node_st *root, const void *data, cmp_t cmp, pri_t pri)
{
	if(NULL == root)
		return -1;
	int ret;

	ret = cmp(root->data, data);

	if(0 == ret)
	{
		pri(root->data);
		return 0;
	}else if(ret < 0){
		__search(root->right, data, cmp, pri);
	}else{
		__search(root->left, data, cmp, pri);
	}
}

int tree_search(const tree_t *mytree, const void *data, cmp_t cmp, pri_t pri)
{
	return __search(mytree->root, data, cmp, pri);
}

static struct node_st *__search_del(struct node_st *root, const void *data, cmp_t cmp)
{
	int ret;

	ret = cmp(root->data, data);

	if(NULL == root)
		return NULL;
	if(0 == ret)
		return root;
	else if(ret >0)
		__search_del(root->left, data, cmp);
	else
		__search_del(root->right, data, cmp);
}

static struct node_st *__max(struct node_st *root)
{
	if(root == NULL)
		return NULL;
	if (root->right == NULL)
		return root;

	return __max(root->right);
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
	del = *root;
	if(0 == res)
	{
		if(l == NULL)
			*root = r;
		else{
			*root = (*root)->left;
			__max(l)->right = r;
		}
		del->left = del->right = NULL;
		free(del->data);
		del->data = NULL;
		free(del);
		del = NULL;
		return 0;
	
	}else if(res > 0)
		__del(&(*root)->left, data, cmp);
	else{
		__del(&(*root)->right, data, cmp);
	}
}


/*static int __del(struct node_st **root, const void *data, cmp_t cmp)
{
	if(NULL == *root)
		return -1;

	struct node_st *node;
	struct node_st *del;
	struct node_st *l;
	struct node_st *r;

	node = __search_del(*root, data, cmp);
	if(NULL == node)
		return -1;
	del = node;
	r = node->right;
	l = node->left;
	if(node->right != NULL)
	{
		node = node->right;
		if(l != NULL)
			__max(node)->left = l;
	}
	else{
		node = node->left;
	}

	del->left = del->right = NULL;
	free(del->data);
	del->data = NULL;
	free(del);
	del = NULL;

	return 0;
}*/

int tree_del(tree_t *mytree, const void *data, cmp_t cmp)
{
	return __del(&mytree->root, data, cmp);
}

static int __always_cmp(const void *data1, const void *data2)
{
	return 0;
}

static int __destory(struct node_st *root)
{
	if(NULL == root)
		return -1;
	__destory(root->left);
	__destory(root->right);
//	__del(&root, NULL, __always_cmp);
	free(root->data);
	root->data = NULL;
	free(root);
	root = NULL;

	return 0;
}

int tree_destory(tree_t **mytree)
{
	if(*mytree == NULL)
		return -1;
	__destory((*mytree)->root);
	
	free(*mytree);
	*mytree = NULL;

	return 0;
}
