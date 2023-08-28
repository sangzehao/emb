#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "$6$JR8orMHs$YiPtva7Hg1QvhUba.ReCBJKJ..4hPCOZuyrUaf8zs2cqSLQ5vfpyed3bZbLRMh/WvmKSfnXN9d2.dXnFQdbhM.";
	char *p = str;
	char *ret;

	//ret = strtok(p, "$");
	while(1)
	{
		ret = strsep(&p, "$");
		if(NULL == ret)
			break;
		puts(ret);
	}

	return 0;
}
