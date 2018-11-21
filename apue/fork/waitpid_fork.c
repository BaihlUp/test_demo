#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	pid_t pid, tmpid;
	int i;

	for(i = 0; i < 3; i++)
	{
		pid = fork();
		if(pid == 0){
			break;
		}
		if(i == 2)
		{
			tmpid = pid;
		}
	}
	if(i == 3)
	{
		int wpid, status;
		//wpid = waitpid(-1, &status, 0); //阻塞回收任意结束的子进程
		//while((wpid = waitpid(-1, NULL, WNOHANG)) != -1)  //非阻塞回收任意子进程
		while((wpid = waitpid(tmpid, NULL, WNOHANG)) != -1) //非阻塞回收指定子进程
		{
			if(wpid > 0){
				printf("This is parent, pid: %d, wait child pid: %d\n", getpid(), wpid);	
			}
			else if(wpid == 0){
				continue;
			}
		}
		if(wpid == -1)	//表示没有子进程可以回收了
		{
			perror("waitpid failed");  //waitpid failed: No child processes
			return 0;
		}
	}
	else
	{
		sleep(1);
		printf("This is child, going to die, ppid: %d, pid: %d\n", getppid(), getpid());
	}

	return 0;
}

