#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


#define N 5

static void *thread_routine(void *s);

static int curid;

//加锁，让一个一个输出
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//通知法，让按顺序输出
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int main(void)
{
	int i;
	int pos[N] = {0, 1, 2, 3, 4};
	pthread_t tid[N] ={};

	alarm(5);

	//创线程
	for(i = 0; i < N; i++)
	{
		pthread_create(tid + i, NULL, thread_routine, pos + i);
	}
	
	i = 0;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		
		//其余线程执行完，curid为-1
		while(curid != -1)
		{
			pthread_cond_wait(&cond, &mutex);
		}
		curid = i;
		pthread_cond_broadcast(&cond);//没有解锁
		pthread_mutex_unlock(&mutex);
		i = (i + 1) % N;
	}

	pause();

	for(i = 0; i < N; i++)
		pthread_join(tid[i], NULL);

	return 0;
}


static void *thread_routine(void *s)
{
	int *key = (int *)s;//可当作自己的线程号

	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(*key != curid)
		{
			pthread_cond_wait(&cond, &mutex);
		}
		curid = -1;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
		printf("%c", 'a' + *key);
		fflush(NULL);
	}

	pthread_exit(0);
}
