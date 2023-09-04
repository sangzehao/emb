#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void signal_handler(int s);
static void show(char (*s)[2], int row, int col);

int main(void){

//	signal(SIGINT, signal_handler);
	signal(SIGALRM, signal_handler);
	alarm(1);

	char dra[3][2]={
				'x','\0',
				'x','\0',
				'x','x'
	};
	
	printf("\033[2J");//清屏
	printf("\033[?25l");//隐藏光标
	show(dra, 3, 2);

	while(1)
		;

	return 0;
}

static void signal_handler(int s)
{
	alarm(1);
	int i, j;
	char dra[3][2]={
				'x','\0',
				'x','\0',
				'x','x'
	};
 	printf("\033[1B");
	printf("\033[3A");//光标上移3行
	printf("\033[2J");//清屏

	for(i = 0; i < 3; i++)
	{
 		printf("\033[11C");
		for(j = 0; j < 2; j++)
		{
			if(dra[i][j])
				printf("%c", dra[i][j]);
		}
		printf("\n");
	}

}

static void show(char (*s)[2], int row, int col)
{
	int i, j;

 	printf("\033[1;1H");
	for(i = 0; i < row; i++)
	{
 		printf("\033[11C");
		for(j = 0; j < col; j++)
		{
			if(s[i][j])
				printf("%c", s[i][j]);
		}
		printf("\n");
	}
}
