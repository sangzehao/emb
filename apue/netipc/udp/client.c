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

int main(int argc, char *argv[])
{
	int udp_socket;
	struct sockaddr_in server_addr;
	struct msg_st rcvbuf, sndbuf;
	int cnt;

	if(argc < 3)
		exit(1);

	//创建套接字
	udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
	
	if(-1 == udp_socket)
	{
		perror("socket");
		exit(1);
	}
	//bind可省略
	
	sndbuf.id = atoi(argv[1]);
	strncpy(sndbuf.msg, argv[2], MSGSIZE);
	
	//server地址
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVERPORT);
	
	inet_aton(SERVERIP, &server_addr.sin_addr);
	sendto(udp_socket, &sndbuf, sizeof(sndbuf.id) + strlen(sndbuf.msg) + 1, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
	
	cnt = recvfrom(udp_socket, &rcvbuf, sizeof(rcvbuf), 0, NULL,  NULL);
	if(-1 == cnt)
	{
		perror("recvfrom()");
		goto ERROR;
	}

	printf("**************\n");
	printf("msg if :%id, msg:%s\n", rcvbuf.id, rcvbuf.msg);
	printf("*********\n");
	close(udp_socket);

	exit(0);
ERROR:
	close(udp_socket);
	exit(1);
}
