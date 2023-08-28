#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

int main(void)
{
	int num1, num2;

	printf("val:%d\n", setjmp(env));
	
	printf("scanf:");	
	scanf("%d%d", &num1, &num2);

	if(num2 == 0)
		longjmp(env, 2);

	printf("%d\n", num2);
}
