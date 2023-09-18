#ifndef __FSM_H__
#define __FSM_H__

#define BUFSIZE	1024

// ADT
enum {STATE_R, STATE_W, STATE_E, STATE_T};

typedef struct {
	int rfd, wfd;
	char buf[BUFSIZE];
	int read_cnt; // 读到的字节个数
	int write_cnt; // 写入的字节个数
	int state;
	char *errmsg; // 记录异常函数
}fsm_t;

// 接口
// 初始化状态机
int fsm_init(fsm_t **fsm, int rfd, int wfd);

// 状态机运行
int fsm_drive(fsm_t *fsm);

// 销毁
void fsm_destroy(fsm_t **fsm);

#endif

