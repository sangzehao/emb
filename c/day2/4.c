#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int num, guess;
	int count = 0;

	srand(time(NULL));
	num = rand() % 10;
	while(count < 4){
		printf("输入：");
		scanf("%d", &guess);
		if(guess == num){
			printf("nice!\n");
			break;
		}
		if(guess < num)
			printf("small!\n");
		if(guess > num)
			printf("big!\n");
	}
	if(4 == count)
		printf("fault!\n");
	
	return 0;
}
