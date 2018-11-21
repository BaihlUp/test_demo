#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t pid;

	pid = fork();
	if(pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	if(pid == 0)
	{
		while(1)
		{
			printf("This is child, ppid: %d, pid: %d\n", getppid(), getpid());
			sleep(1);
		}
	}
	else if(pid > 0)
	{
		sleep(10);
		printf("This is parent, going to die, pid: %d\n", getpid());
	}

	return 0;
}

