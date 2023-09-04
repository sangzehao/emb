#ifndef __TBF_H__
#define __TBF_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


//令牌桶库，令牌桶不只一个

#define TBFMAX 10 //让它最多1024个

/*
   令牌桶初始化
   返回值是所在令牌桶库的索引值（我们把所有的令牌桶地址存放在一个令牌桶指针结构体数组中），相当于文件描述符
*/
int tbf_init(int cps, int burst);

//取令牌,返回取道的令牌数，tb是令牌桶描述符
int tbf_fetch_token(int tb, int ntokens);

//销毁指定令牌
int tbf_destory(int tb);

//销毁令牌桶库
int tbf_destory_all(void);

#endif
