#ifndef __FSM_H__
#define __FSM_H__

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//ADT

#define BUFSIZE 256

//状态机状态
enum{STATE_R, STATE_W, STATE_E, STATE_T};

//状态机结构
typedef struct {
	int rfd, wfd;
	int read_cnt, write_cnt;
	int state;
	char buf[BUFSIZE];
	char *errmsg;
}fsm_t;

int fsm_init(fsm_t **fsm, int rfd, int wfd);

int fsm_driver(fsm_t *fsm);

void fsm_destroy(fsm_t **fsm);

#endif
