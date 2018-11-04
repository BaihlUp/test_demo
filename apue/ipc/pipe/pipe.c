#include<unistd.h> //pipe
#include<stdio.h>
#include<stdlib.h>

/*
	管道使用的局限性：
			1、只能在具有血缘关系的进程中使用
			2、单边半双工通信，就是只能在一端读一端写
			3、缓存区中的数据只能读一次
*/

int main()
{
	int data_len;
	int file_pipes[2];
	char buffer[BUFSIZ + 1];
	const char some_data[] = "123";

	memset(buffer, '\0', sizeof(buffer));

	if(pipe(file_pipes) == 0)
	{
		/*
			file_pipes[0] ：管道的读端
			file_pipes[1] ：管道的写端
		*/
		data_len = write(file_pipes[1], some_data, strlen(some_data));
		printf("Wrote %d bytes\n", data_len);
		data_len = read(file_pipes[0], buffer, BUFSIZ);
		buffer[data_len] = '\0';
		printf("Read %d bytes, txt is: %s\n", data_len, buffer);

		close(file_pipes[0]);
		close(file_pipes[1]);
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE); 
}

