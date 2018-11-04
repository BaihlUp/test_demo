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


