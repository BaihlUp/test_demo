#include<sys/types.h>
#include<stdio.h>
#include<signal.h>

int main()
{
	pid_t pid;

	pid = fork();
	if(pid == 0){
		printf("pid: %d, ppid: %d\n", getpid(), getppid());
		while(1);
	}
	else if(pid > 0){
		sleep(2);
		printf("pid: %d\n", getpid());
		kill(getpid(), SIGKILL);	
	}

	return 0;
}


