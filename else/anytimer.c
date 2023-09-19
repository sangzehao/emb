#include "anytimer.h"

#define HOUSESIZE 1024

static int inited;

typedef struct alarm_t{
	int sec;
	void (*p)(void *s);
	void *para;
}alar_t;

alar_t *house[HOUSESIZE] = {};

static void sig_handler(int s)
{}

int timer_init(int sec, void (*p)(void *s), void *para)
{
	int i;
	struct alarm_t *timer;
	struct itimerval tim;

	tim.it_interval.tv_usec = 0;
	tim.it_interval.tv_sec = 1;
	tim.it_value.tv_sec = 1;
	tim.it_value.tv_usec = 0;

	timer = malloc(sizeof(struct alarm_t));

	if(NULL == timer)
	{
		return -1;
	}

	timer->sec = sec;
	timer->p = p;
	timer->para = para;

	if(0 == inited)
	{
		inited = 1;
		setitimer(ITIMER_REAL, &tim, 0);
		signal(SIGALRM, sig_handler);
	}
	
	for(i = 0; i < HOUSESIZE; i++)
	{
		if(!house[i])
		{
			house[i] = timer;
			break;
		}
	}
}

int timer_red(void)
{
	int i;

	for(i = 0; i < HOUSESIZE; i++)
	{
		if(!house[i])
			continue;
		if(!house[i]->sec){
			house[i]->p(house[i]->para);
			timer_cancel(i);
		}else{
			house[i]->sec--;
		}
	}
}

int timer_cancel(int fd)
{
	free(house[fd]);
	house[fd] = NULL;

	return 0;
}
