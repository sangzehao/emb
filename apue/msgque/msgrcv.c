#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#include "prot.h"

int main(void)
{
	key_t key;
	int ret;
	int msgid;
	struct msg_st rcvbuf;

	key = ftok(PATHNAME, PROJ_ID);	

	if(-1 == key)
	{
		perror("ftok()");
		return 1;
	}
	
	//创建/获取消息队实例
	msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0600);	
	if(-1 == msgid)
	{
		if(errno == EEXIST)
		{	
			msgid = msgget(key, 0);
		}else{
			perror("msgget()");
			return 1;
		}
	}
	while(1)
	{	
		printf("%d\n", __LINE__);	
		ret = msgrcv(msgid, &rcvbuf, MSGSIZE, -3, 0);
		if(-1 == ret)
		{
			perror("msgrcv()");
			return 1;
		}
		printf("%d\n", __LINE__);	
		printf("rcv:%s\n", rcvbuf.msg);
	//	printf("rcv:%ld\n", rcvbuf.mtype);
	}

	return 0;
}
