#include <stdio.h>
#include <glob.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;

	glob_t *gt = NULL;
	
	gt = malloc(sizeof(glob_t *));
	i = glob("/etc/*", 0, NULL, gt);
	if(gt == NULL)
	{
		printf("dsf\n");
	}
	if(i != 0)
		return -1;
	i = glob("/etc/.*", GLOB_APPEND, NULL, gt);
	if(i != 0)
		return -1;
	for(i = 0; i < gt->gl_pathc; i++)
	{
		puts((gt->gl_pathv)[i]);
	}
	
	globfree(gt);

	return 0;

}
