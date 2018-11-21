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
		//execlp("ls", "ls", "-l", NULL);
		//execl("/bin/ls", "ls", "-l", NULL);
		execl("./test", NULL);
		perror("execlp failed");
		exit(-1);
	}
	else if(pid > 0)
	{
		sleep(1);
		printf("This is parent, pid: %d\n", getpid());
	}

	return 0;
}
