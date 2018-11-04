#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

void sys_err(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int main()
{
	int data_len;
	int file_pipes[2];
	char buffer[BUFSIZ + 1];
	const char some_data[] = "123";
	pid_t fork_result;
	FILE *popen_fp;
	int len;

	memset(buffer, '\0', sizeof(buffer));

	if(pipe(file_pipes) == 0)
	{
		fork_result = fork();
		if(fork_result == -1)
		{
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if(fork_result == 0)
		{
			close(file_pipes[0]);
			dup2(file_pipes[1], STDOUT_FILENO);
			execlp("ls", "ls", NULL);
			sys_err("execlp ls error");
		}
		else
		{
			close(file_pipes[1]);
			dup2(file_pipes[0], STDIN_FILENO);
			execlp("wc", "wc", "-l", NULL);
			sys_err("execlp wc error");
		}
	
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE); 
}


