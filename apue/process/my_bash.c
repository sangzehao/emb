#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

extern  char **environ;

int main(int argc, char *argv[])
{
	size_t size = 128;
	char buf[size];
	char *p = buf;
	char *cmd[size];
	char *ret;
	int i;
	pid_t pid;

	while(1){

		printf("[%s@%s]", getenv("PWD"), getenv("LOGNAME"));
		i = 0;
		memset(buf, '\0', size);
		if(-1 == getline(&p, &size, stdin))
		{	
			perror("getline");
		}


		while(1)
		{
			ret = strsep(&p, " \n");
			if(NULL == ret)
				break;
			if(strcmp(ret, "") == 0)//有多个分割符连一块时，不能直接跳过所有。
				continue;
			cmd[i] = ret;
			printf("%s##\n", cmd[i]);
			i++;
		}
		cmd[i] = NULL;
		pid = fork();

		if(-1 == pid)
		{
			perror("pid()");
			return 1;
		}
		if(0 == pid)
		{
			if(-1 == execvp(cmd[0], cmd))
			{
				perror("execvp()");
			}
			exit(0);
		}
		wait(NULL);
	}

	return 0;

}
