#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAXSIZE 32

int file_mode_name(struct stat res, char *s);
int file_mode(struct stat res, char *buf);
int get_time(struct stat res, char *buf, int size);

int main(int argc, char *argv[])
{
	struct stat s;
	struct passwd *p = NULL;
	struct group *g = NULL;
	
	char mode[] = "rwxrwxrwx";
	char mode_n[10];
	char buf[MAXSIZE];


	if(argc < 2)
		return -1;
	if(-1 == stat(argv[1], &s))
	{
		perror("stat()");
		return -1;
	}

	p = getpwuid(s.st_uid);
	g = getgrgid(s.st_gid);

	get_time(s, buf, MAXSIZE);
	file_mode(s, mode);
	file_mode_name(s, mode_n);
	printf("%s", mode_n);
	printf("%s ", mode);
	printf("%ld ", s.st_nlink);
	printf("%s ", p->pw_name);
	printf("%s ", g->gr_name);
	printf("%ld ", s.st_size);
	printf("%s ", buf);
	printf("%s ", argv[1]);
	printf("\n");
}

int file_mode_name(struct stat res, char *s)
{
	switch(res.st_mode & S_IFMT)
	{
		case S_IFSOCK:
			strcpy(s,"套接字");
			break;
		case S_IFLNK:
			strcpy(s, "链接");
			break;
		case S_IFREG:
			strcpy(s, "-");
			break;
		case S_IFBLK:
			strcpy(s, "块");
			break;
		case S_IFDIR:
			strcpy(s, "目录");
			break;
		case S_IFCHR:
			strcpy(s, "字符");
			break;
		case S_IFIFO:
			strcpy(s, "管道");
			break;
	}

	return 0;
}

int file_mode(struct stat res, char *buf)
{
	int i;
	
	int all_mode[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};

	for(i = 0; i < 9; i++)
	{
		if((res.st_mode & all_mode[i]) == 0)
			buf[i] = '-';
	}

	return 0;
}

int get_time(struct stat res, char *buf, int size)
{
	struct tm *temp;

	temp = localtime(&res.st_atim.tv_sec);
	if(NULL == temp)
		return -1;
	strftime(buf, size, "%m月  %d %H:%M", temp);
}
