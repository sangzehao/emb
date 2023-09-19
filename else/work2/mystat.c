#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char *file_type(struct stat *s);
int show(struct stat *s, const char *path);
char *file_mode(struct stat *s);
long dtoh(long num);
char *three_time(const time_t *timep);

int main(int argc, char *argv[])
{
	struct stat s;
	
	if(argc < 2)
		return -1;

	if(-1 == stat(argv[1], &s))
	{
		perror("stat()");
		return -1;
	}

	show(&s, argv[1]);

	return 0;
}

int show(struct stat *s, const char* path)
{
	
	printf("  文件：%s\n", path);
	printf("  大小：%ld\t\t块:%ld\t\tIO块:%ld\t%s\n", s->st_size, s->st_blocks, s->st_blksize, file_type(s));
	printf(" 设备：%ldh/%ldd\tinode:%ld\t硬链接：%ld\n", dtoh(s->st_dev), s->st_dev, s->st_ino, s->st_nlink);
	printf("权限：(0%o/%s)\t", s->st_mode & 0777, file_mode(s));
	printf("Uid:(%d/\t%s)\tGid(%d/\t%s)\n", s->st_uid, getpwuid(s->st_uid)->pw_name, s->st_gid, getgrgid(s->st_gid)->gr_name);
	printf("最近访问：%s\n", three_time(&(s->st_atime)));
	printf("最近更改：%s\n", three_time(&(s->st_mtime)));
	printf("最近改动：%s\n", three_time(&(s->st_ctime)));
}

char *three_time(const time_t *timep)
{
	struct tm *tmp;
	static char buf[512];

	tmp = localtime(timep);
	if(NULL == tmp)
		return NULL;
	
	strftime(buf, 512, "%Y-%m-%d %T", tmp);

	return buf;
}

char *file_mode(struct stat *s)
{
	static char m[] = "rwxrwxrwx";
	int d[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	int i;

	for(i = 0; i < strlen(m); i++)
	{
		if(!(s->st_mode & d[i]))
			m[i] = '-';
	}
	
	return m;
}

char *file_type(struct stat *s)
{
	switch (s->st_mode & S_IFMT)
	{
		case S_IFSOCK:
			return "s";
		case S_IFLNK:
			return "link";
		case S_IFREG:
			return "regular";
		case S_IFBLK:
			return "block";
		case S_IFDIR:
			return "dir";
		case S_IFCHR:  
			return "Character device";
		case S_IFIFO: 
			return "FIFO";
	}
}

static long __dtoh(long num, long *res)
{
	long mode = 0;
	long j;

	if(num > 0)
	{
		mode = num % 16;
		num = num / 16;
		j = __dtoh(num, res);
		*res = *res * 10 + j;	
	}

	return mode;
}

long dtoh(long num)
{
	long ret;
	long res = 0;

	ret = __dtoh(num, &res);

	return res = res * 10 + ret;
}
