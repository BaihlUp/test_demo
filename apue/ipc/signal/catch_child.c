#include<stdio.h>
#include<signal.h>

//有子进程终止，发送SIGCHLD信号时，该函数会被内核回调
void catch_child() 
{
	pid_t wpid;
	int status;

	//防止在执行回调函数时有多个子进程同时终止，需要使用循环
	while((wpid = wait(NULL)) != -1){
		printf("----catch child id: %d\n", wpid);
	}
}

int main()
{
	pid_t pid;
	int i;

	//阻塞 为了防止主进程还未注册信号处理函数，子进程就已经终止
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGCHLD);
	sigprocmask(SIG_BLOCK, &set, NULL);

	for(i = 0; i < 15; i++)
		if((pid = fork()) == 0)
			break;
	if(15 == i){
		struct sigaction act;

		act.sa_handler = catch_child;	//设置回调
		sigemptyset(&act.sa_mask);		//设置捕捉函数执行期间屏蔽字
		act.sa_flags = 0;				//设置默认属性，本信号自动屏蔽

		sigaction(SIGCHLD, &act, NULL);	//注册信号捕捉函数

		//解除阻塞
		sigprocmask(SIG_UNBLOCK, &set, NULL);

		printf("I am parent process %d\n", getpid());
		while(1);
	}
	else{
		printf("I am child process %d\n", getpid());
	}
	
	return 0;
}



