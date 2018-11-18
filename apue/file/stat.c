#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

/*
	穿透符号链接：
		stat函数：会
		lstat函数：不会
*/

int main(int argc, char *argv[])
{
	struct stat sbuf;

	if(argc != 2){
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int ret = lstat(argv[1], &sbuf);
	//int ret = stat(argv[1], &sbuf);
	if(ret == -1)
	{
		perror("stat failed");
		exit(-1);
	}
	printf("file size: %d\n", sbuf.st_size);

	if(S_ISREG(sbuf.st_mode))
	{
		printf("file type: regular file\n");
	}
	else if(S_ISDIR(sbuf.st_mode)){
		printf("file type: directory\n");
	}
	else if(S_ISCHR(sbuf.st_mode)){
		printf("file type: character device\n");
	}
	else if(S_ISBLK(sbuf.st_mode)){
		printf("file type: block device\n");
	}
	else if(S_ISFIFO(sbuf.st_mode)){
		printf("file type: FIFO\n");
	}
	else if(S_ISLNK(sbuf.st_mode)){		
		printf("file type: symbolic link\n");
	}	
	else if(S_ISSOCK(sbuf.st_mode)){
		printf("file type: socket\n");
	}
	
	return 0;
}

