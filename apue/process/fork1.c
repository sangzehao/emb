#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	pid_t pid;
	int i;
	
	printf("start:");//父进程会复制自己的缓存区给子进程，缓存区有啥都会复制

	pid = fork();//从这儿复制完之后，父子各有一个完全相同的虚拟存储区，初始状态一样，之后各自操作，互不影响
	int num = 100;

	if(pid > 0)
	{
		num = 5;
		printf("parent:");
		//for(i = 0; i < 5; i++)
		//	puts(environ[i]);
		printf("num:%d\n", num);
		while(1)
			;
	}
	else{
		printf("child:");
		//for(i = 0; i < 5; i++)
		//	puts(environ[i]);
		//num = 5;
		printf("num:%d\n", num);
	}
	

	return 0;
}
