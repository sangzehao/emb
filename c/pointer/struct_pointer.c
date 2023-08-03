#include<stdio.h>

typedef struct stu{//定义新类型名
	int age;
	
	struct stu *p1, *p2;

}stu_st;//类型名

int main(void)
{
	stu_st a, b, c;
	struct stu d;
	d.age = 1;
	a.age = 1;

	printf("%d\n", d.age);
	a.p1 = &b;
	a.p2 = &c;
	b.age = 1;
	c.age = 2;

	printf("%d \n", (a.p1)->age);
	printf("%d \n", (a.p2)->age);
	printf("%ld\n", sizeof(stu_st));
	return 0;
}
