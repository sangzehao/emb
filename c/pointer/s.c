#include<stdio.h>
#include<string.h>

#define SIZE 32

typedef struct things{
	char name[SIZE];
	int price;
	char type[SIZE];
	struct things *s;
}goods;

int main(void)
{
	goods tea = {"reatea", 3, "drink"};
	struct things bread = {"sandwich", 8, "flour product"};
	goods *p;
	p = &bread;
	goods apple;

	tea.s = &apple;
	apple.price = 5;
	strcpy((tea.s)->name, "xiao");
	strcpy(bread.name, "xiaosang");
	printf("%s\n", (tea.s)->name);

	printf("%d\n", (tea.s)->price);
	printf("%s %d %s\n", tea.name, tea.price, tea.type);
	printf("%s %d %s\n", bread.name, bread.price, bread.type);
	printf("%s %d %s\n", p->name, p->price, p->type);

	return 0;
}
