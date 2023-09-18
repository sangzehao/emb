#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/msg.h>
#include "prot.h"

int main(int argc, char *argv[])
{
	key_t key;
	int msgid;
	struct msg_st sndbuf;

	if(argc < 3)
		return -1;
	
	//生成key
	key = ftok(PATHNAME, PROJ_ID);

	if(-1 == key)
	{
		perror("ftok()");
		exit(1);
	}

	//创建获取消息队列实例
	msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0600);

	if(-1 == msgid)
	{
		if(errno == EEXIST)
			msgid = msgget(key, 0);
		else{
			perror("msgget()");
			exit(1);
		}
	}

	//发消息，入队
	sndbuf.mtype = atol(argv[1]);
	strncpy(sndbuf.msg, argv[2], MSGSIZE);
	msgsnd(msgid, &sndbuf, strlen(argv[2]) + 1, 0);
	//msgsnd(msgid, &sndbuf, strlen(argv[2]) + sizeof(sndbuf.mtype), 0);
	
	exit(0);
}

