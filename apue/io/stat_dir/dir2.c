#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
 
#define BUFSIZE 128

int analy(char *file);
int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;

	analy(argv[1]);

	return 0;
}

int analy(char *file)
{
	struct stat s;
	DIR *dir;
	struct dirent *entry;
	char buf[BUFSIZE] = {};

	if(-1 == stat(file, &s))
	{
		return -1;
	}

	if(!S_ISDIR(s.st_mode))
	{
		return -1;
	}
	dir = opendir(file);
	if(dir == NULL)
	{
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
		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;//一直无限循环的原因，.里边仍然有. ..里边也有..。它俩无限循环了，这就是输出不会停止的原因

		strncpy(buf, file, BUFSIZE);
		strncat(buf, "/", BUFSIZE - strlen(buf));
		strncat(buf, entry->d_name, BUFSIZE - strlen(buf));//关键点造路径，传得是路径而不是名字
		printf("%s->%s\n", file, entry->d_name);
		analy(buf);
	
	}
	
	closedir(dir);
	return 0;

ERROR:
	closedir(dir);
	return -1;
}
