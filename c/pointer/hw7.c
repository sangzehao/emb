#include<stdio.h>
#include<string.h>

//任意类型数组排序

void show_arr(void *s, int n, int size, void (*t)(void *, int));
void pp_i(void *t, int len);
void pp_c(void *t, int len);
void pp_s(void *t, int len);

int main(void)
{
	int a[] = {1,3,6,24,5,9,30,7,8};
	char c[] = {'a','d','e','b','c'};
	char *s[] = {"dbcd", "ccde", "bdef", "aefg"};

	show_arr(a, sizeof(a) / sizeof(int), sizeof(int), pp_i);
	printf("\n");
	show_arr(c, sizeof(c) / sizeof(char), sizeof(char), pp_c);
	printf("\n");
	show_arr(s, sizeof(s) / sizeof(char *), sizeof(char *), pp_s);
	printf("\n");

	return 0;
}
void pp_s(void *t, int len)
{
	int i, j;
	char *m = NULL;
	char **s = (char **)t;

	for(i = 0; i < len - 1; i++)
	{
		for(j = 0; j < len - 1 - i; j++)
		{
			if(strcmp(*(s + j ), *(s + j + 1)) > 0)
			{
				m = *(s + j);
				*(s + j) = *(s + j + 1);
				*(s + j + 1) = m;
			}
		}
	}

	for(i = 0; i < len; i++)
	{
		puts(*(s + i));
	}
}

void pp_c(void *t, int len)
{
	char *element = (char *)t;
	int i, j, mid;

	//排序前
	for(i = 0; i < len ; i++)
	{
		printf("%c ", element[i]);
	}
	printf("\n");
	//排序
	for(i = 0; i < len; i++)
	{
		for(j = i + 1; j < len; j++)
		{
			if(element[j] < element[j - 1])
			{
				mid = element[j - 1];
				element[j - 1] = element[j];
				element[j] = mid;
			}
		}
	}
	//排序后
	for(i = 0; i < len ; i++)
	{
		printf("%c ", element[i]);
	}
}

void pp_i(void *t, int len)
{
	int *element = (int *)t;
	int i, j, mid;

	//排序前
	for(i = 0; i < len ; i++)
	{
		printf("%d ", element[i]);
	}
	printf("\n");
	//排序
	for(i = 0; i < len; i++)
	{
		for(j = i + 1; j < len; j++)
		{
			if(element[j] < element[j - 1])
			{
				mid = element[j - 1];
				element[j - 1] = element[j];
				element[j] = mid;
			}
		}
	}
	//排序后
	for(i = 0; i < len ; i++)
	{
		printf("%d ", element[i]);
	}

}


void show_arr(void *s, int n, int size, void (*t)(void *, int))
{
	int i;
	t(s, n);// 排序；
	
/*	for(i = 0; i < n; i++)
	{
		p((char *)s + i * size);
	}
*/
}

