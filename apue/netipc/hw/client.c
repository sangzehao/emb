#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "proto.h"

int main(int argc, char *argv[])
{
	int tcp_socket;
	struct sockaddr_in server_addr;
	struct msg_st rcvbuf;
	int cnt;
	
	if(argc < 2)
		exit(1);

	tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == tcp_socket)
	{
		perror("socket()");
		exit(1);
	}

	//请求建立连接
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_IP, &server_addr.sin_addr);

	if(-1 == connect(tcp_socket, (void *)&server_addr, sizeof(server_addr)))
	{
		perror("connect()");
		goto ERROR;
	}
	write(tcp_socket, argv[1], strlen(argv[1]));
	while(1)
	{
		memset(&rcvbuf, '\0', MAXMSG);
		cnt = read(tcp_socket, &rcvbuf, MAXMSG);
		if(-1 == cnt)
		{
			perror("read");
			goto ERROR;
		}
		if(strncmp(rcvbuf.msg, "!end", 4) == 0)
		{
			break;
		}
		write(1, &rcvbuf, cnt);
	}
	close(tcp_socket);
	exit(1);
ERROR:
	close(tcp_socket);
	exit(1);

}

