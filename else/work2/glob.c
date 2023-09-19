#include <stdio.h>
#include <glob.h>

int main(void)
{
	int i = 0;

	glob_t gt;

	i = glob("/etc/*", 0, NULL, &gt);
	if(i != 0)
		return -1;
	i = glob("/etc/.*", GLOB_APPEND, NULL, &gt);
	if(i != 0)
		return -1;
	for(i = 0; i < gt.gl_pathc; i++)
	{
		puts((gt.gl_pathv)[i]);
	}
	
	globfree(&gt);

	return 0;

}
