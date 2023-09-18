#ifndef __PROTO_H__
#define __PROTO_H__

//都得要地址和类型

//server地址
#define SERVER_IP "10.11.3.135"
#define SERVER_PORT 1024

//对话格式（数据类型）
#define MAXMSG 1024

struct msg_st{
	char msg[MAXMSG];
}__attribute__((packed));

#endif
