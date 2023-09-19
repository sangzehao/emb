#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
	int shmid;
	pid_t pid;

	shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | IPC_EXCL | 0600);
	
	if(-1 == shmid)
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
		//映射
		void *ptr = NULL;

		ptr = shmat(shmid, NULL, 0);//为0是默认权限，有umask决定
		memcpy(ptr, "hello", 5);
		shmdt(ptr);
		exit(0);
	}

	wait(NULL);
	
	void *ptr = NULL;
	ptr = shmat(shmid, NULL, 0);
	puts(ptr);
	shmdt(ptr);//解除映射，不是销毁, 必须输出之后再解除映射

	//pause();//?

	//销毁共享内存段
	shmctl(shmid, IPC_RMID, NULL);

	return 0;

ERROR:
	shmctl(shmid, IPC_RMID, NULL);
	return 1;

}

