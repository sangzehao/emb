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
	char *buf = NULL;
	int cnt;

	udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udp_socket)
	{
		perror("udp_socket");
		exit(1);
	}

	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(RCV_PORT);
	inet_aton("0.0.0.0", &myaddr.sin_addr);
	
	if(-1 == bind(udp_socket, (struct sockaddr *)&myaddr, sizeof(myaddr)))
	{
		perror("bind()");
		goto ERROR1;
	}

	inet_aton(GROUP_IP, &imr.imr_multiaddr);
	inet_aton("0.0.0.0", &imr.imr_address);
	imr.imr_ifindex = if_nametoindex("ens33");

	if(-1 == setsockopt(udp_socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &imr, sizeof(imr)))
	{
		perror("setsockopt");
		goto ERROR1;
	}

	buf = malloc(MAX_MSG);

	while(1)
	{
		memset(buf, '\0', MAX_MSG);
		cnt = recvfrom(udp_socket, buf, MAX_MSG, 0, NULL, NULL);
		if(-1 == cnt)
		{
			perror("recvfrom()");
			goto ERROR1;
		}

		if(strcmp(buf, "bye") == 0)
			break;
		puts(buf);
	}

	close(udp_socket);
	free(buf);
	buf = NULL;

	exit(0);
ERROR1:
	close(udp_socket);
	exit(1);
}

