#include <stdio.h>

#include "myls.h"

#define BUFSIZE 2048

static int _ergodic(const char *pathname, long *bl_num);

int ergodic(const char *pathname)
{
	long bl_num = 0;

	_ergodic(pathname, &bl_num);
	
	printf("总用量：%ld\n", bl_num / 2);
}

static int _ergodic(const char *pathname, long *bl_num)
{
	struct stat s;
	DIR *dir = NULL;
	struct dirent *entry;
	char buf[BUFSIZE] = {};

	if(NULL == pathname)
		return 1;
	if(-1 == stat(pathname, &s))
	{
		perror("stat()");
		return 1;
	}

	
	if(!S_ISDIR(s.st_mode))
	{	
		*bl_num += s.st_blocks;
		return 1;
	}

	dir = opendir(pathname);
	if(NULL == dir)
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
				goto ERROR;
			break;
		}
		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		memset(buf, '\0', BUFSIZE);
		strncpy(buf, pathname, BUFSIZE);
		strncat(buf, "/", BUFSIZE - strlen(buf));
		strncat(buf, entry->d_name, BUFSIZE - strlen(buf));
		
		if(-1 == stat(buf, &s))
		{
			perror("buf_stat()");
			goto ERROR;
		}
		*bl_num = *bl_num + s.st_blocks;
	}
	closedir(dir);
	return 0;

ERROR:
	closedir(dir);
	return 1;	
}


