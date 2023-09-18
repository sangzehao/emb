#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define START 100
#define END 300
#define N ((END) - (START) + 1)

static int prm(int value);
static void *pthread_handle(void *s);

int main(void)
{
//	pthread_t pthread;
	pthread_t pthread[N] = {};
	int num[N] = {};
	int i, err, pos;

	for(i = START, pos = 0; i <= END; i++, pos++)
	{
		//if(err = pthread_create(pthread + j, NULL, pthread_handle, &i))
		/*
			这个不行，传递i的地址，会引起线程的竞争。
			因为各个线程是并发执行的，有可能第10个线程都创建出来了，但第一个还没取地址里的值了。
			当它去取时得到的值就不是预先想要给它的那个值了。

			解决办法
			(1)
				直接给值，不给地址。void *的参数不只可以接受万能指针，还能接受数值。
				只不过系统会给警告，不影响运行。把值强转为地址传进去后，在把地址强转为数。
			(2)
				创一个数组，给它们传不一样的地址，就不会竞争了，值也不会变，就行了。
		*/

		//if(err = pthread_create(pthread + pos, NULL, pthread_handle, (void *)i))
		num[pos] = i;
		if(err = pthread_create(pthread + pos, NULL, pthread_handle, num + pos))
		{
			fprintf(stderr, "create():%s\n", strerror(err));
			exit(1);
		}
	}
	
	for(i = 0; i < N; i++)
		pthread_join(pthread[i], NULL);

	printf("\n");

	return 0;
}

static void *pthread_handle(void *s)
{
	int *num = (int *)s;
	//int num = (int )s;
	if(prm(*num))
		printf("%d ", *num);

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

	return 1;
}
