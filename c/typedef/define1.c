#include<stdio.h>
#include<string.h>

#define N 20

typedef struct Books{
	char title[N];
	char author[N];
	char subject[N];
	int book_id;
}Book;

int main(void)
{
	struct Books c;
	Book java;

	strcpy(c.title, "c语言");
	strcpy(c.author, "Runoob");
	strcpy(c.subject, "编程语言");
	c.book_id = 1;
	
	typeof(c.book_id) a;

	a = 1;

	printf("%d\n", a);		
	printf("%ld\n", sizeof(a));
	strcpy(java.title, "java语言");
	strcpy(java.author, "james");
	strcpy(java.subject, "编程语言");
	java.book_id  = 2;

	printf("%s\n", c.subject);
	printf("%d\n", c.book_id);
	printf("%s\n", c.title);
	printf("%s\n", c.author);
	printf("\n");
	printf("%s\n", java.subject);
	printf("%d\n", java.book_id);
	printf("%s\n", java.title);
	printf("%s\n", java.author);

	return 0;
}
