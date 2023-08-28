#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(void)
{
	int i;

	for(i = 0; environ[i]; i++)
		puts(environ[i]);
	
	printf("%s\n", getenv("PATH"));

	setenv("PATH", "sss", 1);

	printf("%s\n", getenv("PATH"));
	setenv("OLDPWD", "sss", 1);
	for(i = 0; environ[i]; i++)
		puts(environ[i]);

	return 0;
}
