#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct stat s;
	struct dirent *entry;

	if(argc < 2)
		return -1;
	if(-1 == stat(argv[1], &s))
	{
		perror("stat");
		return -1;
	}
	if(!S_ISDIR(s.st_mode))
	{
		printf("%snot is a directory\n", argv[1]);
		return -1;
	}
	dir = opendir(argv[1]);
	if(dir == NULL)
	{
		perror("opendir()");
		return -1;
	}

	while(1)
	{
		entry = readdir(dir);
		if(NULL == entry)
		{
			if(errno)
			{
				perror("readdir()");
				goto ERROR;
			}
			break;
		}
		printf("%s, %s , %d\n", argv[1], entry->d_name, entry->d_type);
	}
	
	closedir(dir);
	return 0;

ERROR:
	closedir(dir);
	return -1;
}
