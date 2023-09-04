#include "tbf.h"

//令牌结构体
typedef struct{
	int token;//令牌
	int cps;//速率
	int burst;//上限
}tbf_t;

//令牌桶库结构, 结构体类型指针数组，存放的是令牌桶的地址
tbf_t *jobs[TBFMAX] = {};

int tbf_init(int cps, int burst);
int tbf_destory_all(void);
int tbf_destory(int tb);
int tbf_fetch_token(int tb, int ntokens);
static void alarm_handler(int s);
static void sig_moulder_load(void);
static int __get_free_pos(void);

static int inited;

int tbf_init(int cps, int burst)
{
	int pos;

	tbf_t *me = NULL;

	me = malloc(sizeof(tbf_t *));
	if(NULL == me)
		return -1;

	me->token = 0;
	me->cps = cps;
	me->burst = burst;

	//找位置
	pos = __get_free_pos();

	if(-1 == pos)
	{
		free(me);
		return -1;
	}
	jobs[pos] = me;

	//第一个令牌桶初始化成功之后，信号处理函数就要开始设置闹钟,开始一直积攒令牌了
	if(!inited)
	{
		sig_moulder_load();//注册信号行为的函数
		inited = 1;
	}

	return pos;

/*
   	这样不行，不能按顺序放，因为后续可能销毁某一个令牌桶，前边就有可能空出位置了，所以不是每次都依次往后放的。
	jobs[loc] = me;
	loc++;
*/
} 

static int __get_free_pos(void)
{
	int i;

	for(i = 0; i < TBFMAX; i++)
	{
		if(!jobs[i])
			return i;//找到空闲位置了
	}

	return -1;//满了
}

static void sig_moulder_load(void)
{
	signal(SIGALRM, alarm_handler);
	alarm(1);//每隔一秒发出一次SIGALRM信号
}

//信号处理函数，接受到信号每个令牌桶按速率增加令牌
static void alarm_handler(int s)
{
	int i;
	
	alarm(1);
	//为什么这里还要设置闹钟？因为第一个alarm是在外部第一次由内核发出SIGALRM信号，是第一次启动这个信号。得到信号后,调用alarm_handler，里边也有alarm,则由这个alarm接管个alarm的余值，上个就没用了，因为一个进程中只能有一个alarm。

	for(i = 0; i < TBFMAX; i++)
	{
		if(jobs[i] != NULL)
		{
			jobs[i]->token += jobs[i]->cps;
			if(jobs[i]->token > jobs[i]->burst)
				jobs[i]->token = jobs[i]->burst;
		}
	}
}

//取令牌,在一个令牌桶中取令牌

int tbf_fetch_token(int tb, int ntokens)
{
	if(tb < 0 || tb >= TBFMAX)
		return 0;
	if(jobs[tb] == NULL)
		return 0;//*****是结束还是等它创建,应该是结束

//	while(jobs[tb]->token <= 0)
//		pause();//不是传错了？，等它满

	while(jobs[tb]->token <= 0)
		return 0;

	if(jobs[tb]->token < ntokens)
	{
		ntokens = jobs[tb]->token;
		jobs[tb]->token = 0;
		return ntokens;;
	}
	
	jobs[tb]->token -= ntokens;

	return ntokens;
}

//销毁单个令牌桶
int tbf_destory(int tb)
{
	if(tb < 0 || tb >= TBFMAX)
		return -1;

	if(jobs[tb] == NULL)
		return 0;

	free(jobs[tb]);
	jobs[tb] = NULL;

	return 0;
}

//销毁所有令牌桶
int tbf_destory_all(void)
{
	int i;

	for(i = 0; i < TBFMAX; i++)
	{
		if(jobs[i] != NULL)
		{
			free(jobs[i]);
			jobs[i] = NULL;
		}
	}

	return 0;
}
