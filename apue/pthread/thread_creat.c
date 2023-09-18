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
	
	pthread_join(thread, NULL);

	return 0;
}

static void *pthread_handler(void *s)
{
	while(1)
	{
		write(1, "p", 1);
		sleep(1);
		pthread_exit(0);
	}
}
