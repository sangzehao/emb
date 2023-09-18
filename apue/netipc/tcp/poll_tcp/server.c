#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <poll.h>

#include "proto.h"

int main(void)
{
	
	int tcp_socket, accepted_socket;
	pid_t pid;
	struct sockaddr_in myaddr;
	struct msg_st rcvbuf;
	struct pollfd *pfd = NULL;
	int nfds = 1;
	int i, cnt;

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

	//listen,监听状态不会让程序阻塞
	if(-1 == listen(tcp_socket, 200))
	{
		perror("listen");
		exit(1);
	} 
	pfd = calloc(nfds, sizeof(struct pollfd));
	if(NULL == pfd)
	{
		perror("calloc()");
		return 1;
	}
	pfd[0].fd = tcp_socket;
	pfd[0].events = POLLIN;

	while(1)
	{
		if(-1 == poll(pfd, nfds, -1))
		{
			if(EINTR == errno)
				continue;
			perror("poll()");
			goto ERROR;
		}
		//事件发生,可以同时有几个事件
		for(i = 0; i < nfds; i++)
		{
			if(i == 0)
			{
				if(pfd[i].revents & POLLIN)
				{
					//这儿才会让堵塞，在这儿上边用poll
					accepted_socket = accept(tcp_socket, NULL, NULL);
					if(-1 == accepted_socket)
					{
						perror("accept");
						goto ERROR;
					}
					//成功后accepted用于数据交换, tcp_socket继续接受客户端连接
					//放入pfd
					nfds++;
					pfd = realloc(pfd, sizeof(struct pollfd) * nfds);
					pfd[nfds - 1].fd = accepted_socket;
					pfd[nfds - 1].events = POLLIN;
					pfd[nfds - 1].revents = 0;
				}
			}else{
				if(pfd[i].revents & POLLIN)
				{
					memset(rcvbuf.msg, 0, MAXMSG);
					cnt = read(pfd[i].fd, rcvbuf.msg, MAXMSG);
					if(-1 == cnt){
						perror("read()");
						goto ERROR;
					}
					if(0 == cnt)
					{
						close(pfd[i].fd);
						memmove(pfd + i, pfd + i + 1, (nfds - i - 1) * sizeof(struct pollfd));
						pfd = realloc(pfd, sizeof(struct pollfd) + (nfds - 1));
						nfds--;
						i--;
					}else{
						puts(rcvbuf.msg);
					}
				}
			}

		}
	}

	
	close(tcp_socket);
	exit(0);
ERROR:
	close(tcp_socket);
	exit(1);

}
