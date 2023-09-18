#include <stdio.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include "proto.h"

int main(void)
{
	int udp_socket;
	struct sockaddr_in myaddr, remote_addr;
	socklen_t  remote_addr_len;
	struct msg_st rcvbuf;
	int cnt;

	//创建
	udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udp_socket)
	{
		perror("socket");
		exit(1);
	}

	//绑定
	myaddr.sin_family = AF_INET;
	//网络字节序
	myaddr.sin_port = htons(SERVERPORT);
	
	//点分十进制转整形
	inet_aton(SERVERIP, &myaddr.sin_addr);
	if(-1 == bind(udp_socket, (struct sockaddr *)&myaddr, sizeof(myaddr)))
	{
		perror("bind()");
		goto BIND_ERROR;
	}

	
	remote_addr_len = sizeof(struct sockaddr_in);

	//等待请求
	while(1)
	{
		cnt = recvfrom(udp_socket, &rcvbuf, sizeof(rcvbuf), 0, (struct sockaddr *)&remote_addr, &remote_addr_len);
		if(-1 == cnt)
		{
			perror("recvfrom()");
			goto BIND_ERROR;
		}

		printf("*************\n");
		printf("client ip:%s, port:%d\n", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port    ));
		printf("msg id:%d, msg:%s\n", rcvbuf.id, rcvbuf.msg);
		printf("********************************\n");

		//发送回信息
		rcvbuf.id = 123;
		strcpy(rcvbuf.msg, "OK");
		sendto(udp_socket, &rcvbuf, sizeof(rcvbuf.id) + strlen(rcvbuf.msg) + 1, 0, (struct sockaddr *)&remote_addr, remote_addr_len);

	}
	close(udp_socket);	

	exit(0);

BIND_ERROR:
	close(udp_socket);
	exit(1);
}
