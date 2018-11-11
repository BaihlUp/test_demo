#include<signal.h>
#include<stdio.h>

void sys_err(char *str)
{
	perror(str);
	exit(-1);
}

void sig_handle(int signum)		//回调函数
{
	printf("catch signal %d\n", signum);
	return 0;
}

int main()
{
	struct sigaction act, oldact;
	int ret = 0;

	act.sa_handler = sig_handle;	//设置回调函数
	sigemptyset(&act.sa_mask);		//清空sa_mask屏蔽字，只在sig_catch工作时有效
	act.sa_flags = 0;				//默认值

	ret = sigaction(SIGINT, &act, &oldact);	//注册信号捕捉函数
	if(ret == -1)
	{
		sys_err("sigaction error");
	}

	//可以使用捕捉多个信号
	ret = sigaction(SIGQUIT, &act, &oldact); //注册信号捕捉函数
	if(ret == -1)
	{
		sys_err("sigaction error");
	}

	while(1);

	return 0;
}

