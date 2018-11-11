#include<signal.h>
#include<stdio.h>

void sys_err(char *str)
{
	perror(str);
	exit(-1);
}

void print_set(sigset_t *set)
{
	int i = 0;
	for(i = 1; i < 32; i++)
	{
		//参数：i 为信号的编号
		if(sigismember(set, i)){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	printf("\n");
}

int main()
{
	sigset_t set, oldset, pedset;
	int ret;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	ret = sigprocmask(SIG_BLOCK, &set, &oldset);
	if(ret == -1)
	{
		sys_err("sigprocmask error");
	}
	while(1){
		ret = sigpending(&pedset);
		if(ret == -1)
		{
			sys_err("sigpending error");
		}
		//在信号触发之后才会看到未知信号集相应信号被置1
		print_set(&pedset);
		sleep(1);
	}

	return 0;
}





