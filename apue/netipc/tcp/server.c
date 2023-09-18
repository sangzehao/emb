#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "proto.h"

int main(void)
{
	
	int tcp_socket, accepted_socket;
	pid_t pid;
	struct sockaddr_in myaddr;

	tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	if(-1 == tcp_socket)
	{
		perror("socket");
		return 1;
	}

	//绑定
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_IP, &myaddr.sin_addr);

	if(-1 == bind(tcp_socket, (struct sockaddr *) &myaddr, sizeof(myaddr)))
	{
		perror("bind");
		return 1;
	}

	//listen
	if(-1 == listen(tcp_socket, 200))
	{
		perror("listen");
		exit(1);
	}

	while(1)
	{
		accepted_socket = accept(tcp_socket, NULL, NULL);
		if(-1 == accepted_socket)
		{
			perror("accept");
			goto ERROR;
		}
		//成功后accepted用于数据交换, tcp_socket继续接受客户端连接
		pid = fork();
		if(-1 == pid)
		{
			perror("fork()");
			goto ERROR;
		}
		if(0 == pid)
		{
			close(tcp_socket);
			sleep(1);
			write(accepted_socket, "hello", 6);
			close(accepted_socket);
			exit(0);
		}
	}
	
	close(tcp_socket);
	exit(0);
ERROR:
	close(tcp_socket);

}
