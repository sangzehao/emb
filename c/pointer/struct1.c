#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct stu{
	int age;
	char name[32];
	int score;
};


int main(void)
{
	int i, max;
	char *s[] = {"sang", "li", "wang", "sun", "zhao", "qian", "zhou", "chao", "ma", "fan"};
	struct stu a[10];

	srand(time(NULL));
	for(i = 0; i < 10; i++)
	{
		a[i].age = rand() % 100;
		a[i].score = rand() % 100;
		strcpy(a[i].name, *(s + i));
	}
	for(i = 0; i < 10; i++)
	{
		printf("%s %d %d\n", a[i].name, a[i].age, a[i].score);
	}

	max = 0;

	for(i = 1; i < 10; i++)
	{
		if(a[i].score > a[max].score)
			max = i;
	}

	printf("max : %s %d %d\n", a[max].name, a[max].age, a[max].score);


	return 0;
}

