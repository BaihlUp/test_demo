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

int var = 100;

int main()
{
	int fd;
	int *p = NULL;
	off_t len;
	pid_t pid;

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
	//p = (int *)mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);  	//设置为MAP_PRIVATE，进程间无法共享内存
	p = (int *)mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		sys_err("mmap error");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if(pid == 0)
	{
		*p = 1000;
		var = 1000;
		printf("*p == %d, var == %d\n", *p, var);
	}
	else{
		sleep(1);
		printf("*p == %d, var == %d\n", *p, var);
	}
	
	int ret = munmap(p, len);
	if(ret == -1)
	{
		sys_err("munmap error");
		exit(EXIT_FAILURE);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}





