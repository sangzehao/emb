#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>


#define SHMSIZE 1024

//共享内存段

int main(int argc, char *argv[])
{
	int shemid;
	pid_t pid;

	shemid = shmget(IPC_PRIVATE, SHMSIZE, IPC_CREAT | IPC_EXCL | 0600);

	if(-1 == shemid)
	{
		perror("shmget()");
		return 1;
	}

	pid = fork();

	if(-1 == pid)
	{
		perror("fork()");
		goto ERROR;
	}

	if(0 == pid)
	{
		void *ptr = NULL;

		ptr = shmat(shemid, NULL, 0);

		memcpy(ptr, argv[1], strlen(argv[1]));

		shmdt(ptr);
		exit(0);
	}

	wait(NULL);
	void *ptr = NULL;
	ptr = shmat(shemid, NULL, 0);
	puts(ptr);
	printf("fdsf\n");
	shmdt(ptr);
	printf("sf\n");

	shmctl(shemid, IPC_RMID, NULL);

	return 0;

ERROR:
	shmctl(shemid, IPC_RMID, NULL);
	return 1;
}

