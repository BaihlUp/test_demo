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
	pid_t pid;
	int *p;
	
	//匿名映射
	p = mmap(NULL, 40, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANON, -1, 0);
	if(p == MAP_FAILED)
	{
		sys_err("mmap failed");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if(pid == -1)
	{
		sys_err("fork failed");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		*p = 1000;
		printf("child pid = %d, *p = %d\n", getpid(), *p);
	}
	if(pid > 0)
	{
		sleep(1);
		printf("parent pid = %d, *p = %d\n", pid, *p);
		wait(NULL);
	}
}


