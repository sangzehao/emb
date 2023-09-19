#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 128

extern char **environ;

int mybash(const char *file, char * const argv[]);

int main(int argc, char *argv[])
{
	int i = 0;
	char *buf = NULL;
	char *cmd[SIZE];
	char *str;
	int ret;
	size_t n;
	pid_t pid;

	while(1)
	{
		printf("[%s]%s:\n", getenv("PWD"), getenv("LOGNAME"));
		ret = getline(&buf, &n, stdin);
		if(-1 == ret)
		{
			perror("getline()");
			return -1;
		}
		
		i = 0;
		while(1)
		{
			str = strsep(&buf, " \n");
			if(!str)
				break;
			if(strcmp(str, "") == 0)//这个判断年必须放在判断为空后面，因为与空比较回报错
				continue;
			cmd[i++] = str;
		}
		cmd[i] = NULL;
		
		pid = fork();

		if(-1 == pid)
		{
			perror("fork()");
			return -1;
		}
		if(0 == pid)
		{
			mybash(cmd[0], cmd);
			exit(0);			
		}
		wait(NULL);
	}


	return 0;
}

int mybash(const char *file, char * const argv[])
{
	if(-1 == execvp(file, argv))
	{
		perror("execvp");
		return -1;
	}

	return 0;
}
