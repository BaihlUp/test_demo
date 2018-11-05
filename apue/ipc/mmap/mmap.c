#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>

void sys_err(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int main()
{
	int fd;
	char *p = NULL;
	off_t len;

	fd = open("testmap", O_RDWR|O_CREAT|O_TRUNC, 0644);
	if(fd == -1)
	{
		sys_err("open error");
		exit(EXIT_FAILURE);
	}

	ftruncate(fd, 20);
	len = lseek(fd, 0, SEEK_END);
	if(len == -1)
	{
		sys_err("lseek error");
		exit(EXIT_FAILURE);
	}
	p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		sys_err("mmap error");
		exit(EXIT_FAILURE);
	}
	strcpy(p, "hello mmap");

	printf("---%s\n", p);

	int ret = munmap(p, len);
	if(ret == -1)
	{
		sys_err("munmap error");
		exit(EXIT_FAILURE);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}




