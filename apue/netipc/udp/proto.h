#ifndef __PROTO_H__
#define __PROTO_H__

#include <stdint.h>

#define SERVERIP "10.11.3.135"
#define SERVERPORT 1122

#define MSGSIZE 128

struct msg_st{
	int8_t id;
	char msg[MSGSIZE];
}__attribute__((packed));//保证单字节对齐

#endif

