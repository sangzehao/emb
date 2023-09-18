#ifndef __PROT_H_
#define __PROT_H_

#define PATHNAME "/home/sang/emb"
#define PROJ_ID 'b' //不管多大，只有最低处的8bit位有效
					//即作多（0-255）256种

#define MSGSIZE 1024

struct msg_st {
	long mtype;
	char msg[MSGSIZE];
};

#endif
