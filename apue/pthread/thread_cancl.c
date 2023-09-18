#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

static void *pthread_handler(void *s);

int main(void)
{
	pthread_t thread;
	int err;
	int count = 0;

	if(err = pthread_create(&thread, NULL, pthread_handler, NULL))
	{
		fprintf(stderr, "is ERR , %s\n", strerror(err));
		exit(1);
	}

	while(1)
	{
		if(count > 4)
			break;
		write(1, "m", 1);
		sleep(1);
		count++;
	}
	
	//向线程发送取消请求
	pthread_cancel(thread);//thread线程并不是马上结束，而是 thread下一次调用取消点函数再结束，write()就是

	pthread_join(thread, NULL);

	return 0;
}

//终止处理函数
static void clean_up1(void *s)
{
	printf("%s is called\n", __FUNCTION__);
}

static void clean_up2(void *s)
{
	printf("%s is called\n", __FUNCTION__);
}

static void *pthread_handler(void *s)
{
	int i = 0;

	pthread_cleanup_push(clean_up1, NULL);
	pthread_cleanup_push(clean_up2, NULL);

	while(1)
	{
		i++;
	//	if(i > 10)
	//		break;
		write(1, "p", 1);
		sleep(1);
	}
	
	pthread_exit(0);

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
}
