#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>

#define PATHNAME "/tmp/out"
#define N 20
#define BUFSIZE 16

static int semid;

static int V(void);
static int P(void);

int main(void)
{
	FILE *fp;
	pid_t pid;
	char buf[BUFSIZE];
	int i;

	fp = fopen(PATHNAME, "w");

	if(NULL == fp)
	{
		perror("fopen()");
		exit(1);
	}
	
	fputs("0", fp);
	fclose(fp);

	//创建信号量集
	semid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0600);
	if(-1 == semid)
	{
		perror("semget()");
		exit(1);
	}

	//设置信号量
	semctl(semid, 0, SETVAL, 1);

	for(i = 0; i < N; i++)
	{
		pid = fork();
		if(-1 == pid)
		{
			perror("fork()");
			goto FORK_ERROR;
		}
		if(0 == pid)
		{
			P();//p操作
			fp = fopen(PATHNAME, "r+");//io
			if(NULL == fp)
			{
				perror("chil_fopen()");
				exit(1);
			}
			fgets(buf, BUFSIZE, fp);
			rewind(fp);
			fprintf(fp, "%d", atoi(buf) + 1);
			fclose(fp);//刷新缓存
			V();//v操作
			exit(0);
		}
	}

	//收尸
	for(i = 0; i < N; i++)
		wait(NULL);

	semctl(semid, 0, IPC_RMID, NULL);
	return 0;

FORK_ERROR:
	semctl(semid, 0, IPC_RMID, NULL);
	exit(1);

}

static int P(void)
{
	struct sembuf sem;

	sem.sem_num = 0;
	sem.sem_op = -1;
	sem.sem_flg = 0;
	if(-1 == semop(semid, &sem, 1))
	{
		perror("semop()");
		return -1;
	}

	return 0;
}
static int V(void)
{
	struct sembuf sem;

	sem.sem_num = 0;
	sem.sem_op = 1;
	sem.sem_flg = 0;
	if(-1 == semop(semid, &sem, 1))
	{
		perror("semop()");
		return -1;
	}

	return 0;
}
