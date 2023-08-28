#include <stdio.h>
#include <shadow.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>

#define _XOPEN_SOURCE 

int main(int argc, char *argv[])
{
	struct spwd *sp;
	char *passwd;
	char *cry_passwd;
	char *ret;

	if(argc < 2)
		return 1;

	//获得密码	
	sp = getspnam(argv[1]);
	
	if(NULL == sp)
	{
		perror("getspanm()");
		return 1;
	}

	printf("%s\n", sp->sp_namp);
	printf("%s\n", sp->sp_pwdp);
	
	//输入密码
	passwd = getpass("passwd:");
	
	if(NULL == passwd)
	{
		perror("getpass()");
		return 1;
	}

	printf("mypass:%s\n", passwd);
	
	//输入的密码加密
	cry_passwd = crypt(passwd, sp->sp_pwdp);
	
	if(NULL == cry_passwd)
		return 1;
	
	printf("cry_passwd:%s\n", cry_passwd);

	//比对校验

	if(strcmp(sp->sp_pwdp, cry_passwd) == 0)
		printf("true\n");
	else
		printf("false\n");

	//分割字符串
	//strsep
/*	while(1)
	{
		ret = strsep(&(sp->sp_pwdp), "$s");
		if(NULL == ret)
			return 1;
		puts(ret);
	}
*/

	//strtok

	ret = strtok(sp->sp_pwdp, "$");
	while(ret != NULL)
	{
		puts(ret);
		ret = strtok(NULL, "$");
	}


	return 0;
}
