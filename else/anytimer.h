#ifndef __ANYTIMER_H__
#define __ANYTIMER_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

int timer_init(int sec, void (*p)(void *s), void *para);

int timer_red(void);

int timer_cancel(int fd);

#endif
