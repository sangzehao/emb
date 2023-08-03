#include<stdio.h>
#include<string.h>

#define NAMESIZE 32

struct stu{
	int age;
	char name[NAMESIZE];
	float score;
};

int main(void)
{
	struct stu s1 = {12, "sang", 34};
	
	struct stu s2;
	struct stu *p;
	
	p = &s2;
	s2.age = 20;
	strcpy(s2.name, "li");
	s2.score = 39;

	printf("%d %s %f\n", s1.age, s1.name, s1.score);
	printf("%d %s %f\n", p->age, p->name, p->score);

	return 0;
}
