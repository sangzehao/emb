#ifndef __PROTO_H__
#define __PROTO_H__


#define SERVERIP "10.11.3.135"
#define SERVERPORT 1122

#define MSGSIZE 128

//每个频道存储自己描述的结构体，不带真正的数据，如音乐数据
struct chn_list_entry{
	int8_t chnid; //>0是频道描述，有顺序的，等于0是频道列表
	int8_t len;//自述长度，更便捷，不用每次sizeof
	char descr[1];
}__attribute__((packed));


//存储频道列表的结构体
struct chn_list_st{
	int8_t chnid;
	struct chn_list_entry entrys[1];
}__attribute__((packed));

//存储频道数据的结构体
struct chn_data_st{
	int8_t chnid;
	char msg[MSGSIZE];
}__attribute__((packed));//保证单字节对齐

#endif

