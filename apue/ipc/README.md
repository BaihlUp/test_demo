进程间通信：

popen1.c  : popen、fread、fwrite的使用方法

1、管道（pipe）
	pipe.c : pipe管道的使用
	pipe_execl.c : 管道中使用execl函数
	pipe_fork.c : 父子进程中使用管道

示例：
 	pipe_ls_wc.c : 使用管道方式，实现"ls -l | wc -l"的命令执行

2、命名管道（fifo）：可以实现无血缘关系的进程间通信
	fifo_w.c : 使用mkfifo创建命名管道，并写入数据
	fifo_r.c : 打开命名管道读数据

3、存储映射（mmap）：映射文件到内存
	mmap.c : mmap函数使用方法
	mmap_fork.c : 父子进程间使用mmap通信
	mmap_w.c : 向mmap映射区中写入
	mmap_r.c : 从mmap映射区中读取

4、信号（signal）：
	alarm.c：时钟信号
	setitimer.c：更精确的时钟信号
	kill.c ：发送指定的信号
	signal_set.c：几个设置信号集的函数使用
	signal.c ：使用signal函数捕捉信号
	sigaction.c ：使用sigaction函数捕捉信号
	catch_child.c ：父进程捕捉回收子进程


