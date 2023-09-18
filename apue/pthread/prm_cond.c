#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define START 100
#define END 300
#define M 4

static int prm(int value);
static void *pthread_handle(void *s);

static int task;//任务

//初始化锁
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//初始化通知
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int main(void)
{
	//alarm(3);
	pthread_t pthread[M] = {};
	int i, err, j;

	//创线程
	for(i = 0; i < M; i++)
	{
		if(err = pthread_create(pthread + i, NULL, pthread_handle, NULL))
		{
			fprintf(stderr, "create():%s\n", strerror(err));
			exit(1);
		}
	}


	//分任务
	for(i = START; i <= END; i++)
	{
		pthread_mutex_lock(&mutex);
		while(task > 0)
		{
			//解锁，等通知，等pthread_cond_signal, pthread_cond_broadcast唤醒，再抢锁
			pthread_cond_wait(&cond, &mutex);
		}
		task = i;
		pthread_cond_signal(&cond);//通知至少一个
		pthread_mutex_unlock(&mutex);
	}

	//任务分完
	pthread_mutex_lock(&mutex);
	while(task > 0)
	{
		pthread_cond_wait(&cond, &mutex);
	}
	task = -1;
	pthread_cond_broadcast(&cond);//通知给所有
	pthread_mutex_unlock(&mutex);

	for(i = 0; i < M; i++)
		pthread_join(pthread[i], NULL);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);

	//while(1)
	//	;

	return 0;
}

static void *pthread_handle(void *s)
{
	int mid;

	while(1)
	{
		pthread_mutex_lock(&mutex);
		
		while(task == 0)
		{
			pthread_cond_wait(&cond, &mutex);	
		}
		if(-1 == task)
		{	
			pthread_mutex_unlock(&mutex);
			break;
		}
		if(task > 0)
		{
			mid = task;
			task = 0;
			//通知给main，只有每个都通知到才能保证main知道
			pthread_cond_broadcast(&cond);
			pthread_mutex_unlock(&mutex);		
			prm(mid);
		}
	}
	
	pthread_exit(0);
}

static int prm(int value)
{
	int i;
		
	i = 2;

	while(i <= value / 2)
	{
		if(value % i == 0)
			break;//yes
		i++;
	}

	if(i <= value / 2)
		return 0;//no
	
	printf("%d\n", value);

	return 1;
}
