#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	int i;
#if 0
	for(i = 0; i < 5; i++)
	{
		if((pid = fork()) == 0)
		{
			printf("I am parent child process, ppid: %d, pid: %d\n", getppid(), getpid(), i);
			break;
		}
	}
	if(i == 5)
	{
		printf("I am parent process, pid: %d\n", getpid());
	}else {
		printf("I am parent child process, ppid: %d, pid: %d\n", getppid(), getpid(), i);
	}
#endif
	pid = fork();
	if(pid > 0)
	{
		printf("I am parent process, ppid: %d, pid: %d\n", getppid(), getpid());
	}else if(pid == 0)
	{
		printf("I am child process, ppid: %d, pid: %d\n", getppid(), getpid());
	}


	return 0;
}

