#include <stdio.h>
#include <string.h>

struct msg{
	int id;
	char msg[2];
};


int main(void)
{
	struct msg mymsg;
	char s[] = "要";
	
	printf("s:%ld\n", sizeof(s));
	printf("len1:%ld\n", sizeof(struct msg));
	
	mymsg.id = 1;
	strcpy(mymsg.msg ,"he");

	printf("len2:%ld\n", sizeof(mymsg.id) + strlen(mymsg.msg));
	

	return 0;
}
