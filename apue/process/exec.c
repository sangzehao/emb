#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	pid_t pid;
	
	char buf[] = "write\n";
	char *args[] = {"ls", "-l", "-i", NULL};

//	write(stdout, buf, strlen(buf));
	printf("start\n");

	pid = fork();

	if(-1 == pid)
	{
		perror("fork()");
		return 1;
	}

	if(0 == pid)
	//	execl("/bin/ls", "ls", "-l", "-i", NULL);
	//	execlp("ls", "ls", "-l", "-i", NULL);
	//	execv("/bin/ls", args);
		execvp("ls", args);

	printf("end\n");

	wait(NULL);

	return 0;
}
