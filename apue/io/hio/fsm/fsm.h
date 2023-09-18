#ifndef __FSM_H__
#define __FSM_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

//ADT
#define BUFSIZE 128

enum{STATE_R, STATE_W, STATE_E, STATE_T};

typedef struct{
	int rfd, wfd;
	char buf[BUFSIZE];
	int read_cnt;
	int write_cnt;
	int state;
	char *errmsg;
}fsm_t;

//初始化状态机
int fsm_init(fsm_t **fsm, int rfd, int wfd);

//运行
int fsm_drive(fsm_t *fsm);

//销毁
void fsm_destroy(fsm_t **fsm);

#endif
