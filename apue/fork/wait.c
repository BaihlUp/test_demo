#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;

	pid = fork();
	if(pid == -1)
	{
		perror("fork failed");
		return -1;
	}
	if(pid == 0)
	{
		sleep(10);
		printf("This is child, going to die, ppid: %d, pid: %d\n", getppid(), getpid());
	}
	else if(pid > 0)
	{
		int wpid, status;
		//wpid: 回收的子进程pid
		wpid = wait(&status); //阻塞等待子进程终止
		if(wpid == -1){
			perror("wait failed");
			return -1;
		}
		
		if(WIFEXITED(status)){	//为真，说明子进程正常退出
			printf("child exit with %d\n", WEXITSTATUS(status));
		}
		
		if(WIFSIGNALED(status)){		//为真，说明子进程是被信号终止的，获取具体信号
			printf("child kill with signal %d\n", WTERMSIG(status));
		}
		printf("This is parent, pid: %d, parent finish, child pid: %d\n", getpid(), wpid);
	}

	return 0;
}

