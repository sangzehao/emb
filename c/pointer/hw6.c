#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//比较argv[1],argv[2]并大的倒序输出
char  *rever_str(char *p, char **s);

int main(int argc, char *arg[])
{
	if(argc < 2)
		return -1;
	int i;
	char *s = NULL;
	char *p;

	i = strcmp(arg[1], arg[2]);
	p = i > 0 ? arg[1] : arg[2];
	
	printf("%s", rever_str(p, &s));
	free(s);
	s = NULL;
	printf("\n");

	return 0;
}

char  *rever_str(char *p, char **s)
{
	*s = malloc(strlen(p) + 1);
	int i, len;

	len = strlen(p);

	for(i = 0; len - 1 >= 0; i++, len--)
	{
		(*s)[i] = p[len - 1];
	}
	(*s)[i] = '\0';

	return *s;
}
