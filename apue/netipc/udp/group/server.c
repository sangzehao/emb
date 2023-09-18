#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <stdlib.h>
#include <unistd.h>
#include "group_proto.h"

int main(void)
{
	int udp_socket;
	struct sockaddr_in myaddr;
	struct ip_mreqn imr;

	udp_socket = socket(AF_INET,  SOCK_DGRAM, 0);

	if(-1 == udp_socket)
	{
		perror("socket()");
		return 1;
	}
	//广播要传的参数，结构体类型
	//先将本地设置为多播
	inet_aton(GROUP_IP, &imr.imr_multiaddr);//组播ip
	//组播接口本地ip
	imr.imr_address.s_addr = IPPROTO_IP;
	imr.imr_ifindex = if_nametoindex("ens33");

	if(-1 == setsockopt(udp_socket, IPPROTO_IP, IP_MULTICAST_IF, &imr, sizeof(imr)))
	{
		perror("setsockopt()");
		goto ERROR1;
	}

	//被动的需要绑,组播服务端是主动端，主动给客户端发

	myaddr.sin_family = AF_INET;
	//转为网络字节序
	myaddr.sin_port = htons(RCV_PORT);
	//把点分十进制ipv4地址转为32位二进制数字
	inet_aton(GROUP_IP, &myaddr.sin_addr);

	//开始发送
	while(1)
	{
		sendto(udp_socket, "遥遥领先", 16, 0, (struct sockaddr*)&myaddr, sizeof(myaddr));
		sleep(1);
	}

	close(udp_socket);
	exit(0);
ERROR1:
	close(udp_socket);
	exit(1);
	

	




}
