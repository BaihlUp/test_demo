#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


void sys_err(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int main()
{
	int fd, len;
	char buffer[BUFSIZ + 1];
	int i = 0;

	memset(buffer, '\0', sizeof(buffer));

	int ret = mkfifo("/home/myfifo", 0777);	//不能在window系统下创建管道文件
	if(ret == -1)
	{
		sys_err("mkfifo error");
		exit(EXIT_FAILURE);
	}
	fd = open("/home/myfifo", O_WRONLY);
	if(fd == -1)
	{
		sys_err("open error");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		sprintf(buffer, "This is txt %d\n", i);
		len = write(fd, buffer, BUFSIZ);
		if(len == -1)
		{
			sys_err("write error\n");
			exit(EXIT_FAILURE);
		}
		i++;
		sleep(1);
	}
	close(fd);
}

