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

int main(void)
{
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
			pthread_mutex_unlock(&mutex);
			pthread_mutex_lock(&mutex);	
		}
		task = i;
		pthread_mutex_unlock(&mutex);
	}

	//任务分完
	pthread_mutex_lock(&mutex);
	while(task > 0)
	{
		pthread_mutex_unlock(&mutex);
		pthread_mutex_lock(&mutex);
	}

	task = -1;
	pthread_mutex_unlock(&mutex);

	for(i = 0; i < M; i++)
		pthread_join(pthread[i], NULL);

	pthread_mutex_destroy(&mutex);

	return 0;
}

static void *pthread_handle(void *s)
{
	int mid;

	while(1)
	{
		pthread_mutex_lock(&mutex);
		
		if(0 == task)
		{
			pthread_mutex_unlock(&mutex);
			continue;
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
