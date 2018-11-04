#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
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

	memset(buffer, '\0', sizeof(buffer));

	fd = open("/home/myfifo", O_RDONLY);
	if(fd == -1)
	{
		sys_err("open error");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		len = read(fd, buffer, BUFSIZ);
		if(len == -1)
		{
			sys_err("write error");
			exit(EXIT_FAILURE);
		}
		write(STDOUT_FILENO, buffer, BUFSIZ);
	}
	close(fd);
}

