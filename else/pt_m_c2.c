#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5

static void *pthread_routine(void *s);

//加锁，控制顺序
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//设置通知，判断任务是否完成
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//任务, 作用是指定输出
static int curid;

int main(void)
{
	pthread_t pthd[N] = {};
	int pos[N] = {1, 2, 3, 4, 5};//不抢资源
	int i;
	int err;
	
	alarm(2);

	for(i = 0; i < N; i++)
	{
		err = pthread_create(pthd + i, NULL, pthread_routine, pos + i);
		if(err)
		{
			fprintf(stderr, "pthread(): %s\n", strerror(err));
			exit(1);
		}
	}
	//如果不加锁， 不抢锁，上一步线程创建完成后，线程就开始执行了。
	//线程是并发的，和main线程是平等的，谁也管不了谁，只有锁可以控制一下
	
	i = 0;
	while(1)
	{
		pthread_mutex_lock(&mutex);
	//	printf("curid:%d\n", curid);
		while(curid > 0)
		{
			pthread_cond_wait(&cond, &mutex);//等待，？解锁再上锁
		}
		curid = i + 1;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
		i = (i + 1) % N;
	}
	
	//pause();

	for(i = 0; i < N; i++)
		pthread_join(pthd[i], NULL);
	
	return 0;
}
	
static void *pthread_routine(void *s)
{
	int *key = (int *)s;
	int i = 0;

	while(1)
	{
		if(i == 5)
			break;
		pthread_mutex_lock(&mutex);
		while(curid != *key)
		{
			pthread_cond_wait(&cond, &mutex);
		}
		curid = -1;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
		printf("%d" , *key);
		fflush(NULL);
		i++;
	}

	pthread_exit(0);
}
