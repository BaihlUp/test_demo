#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat statbuf;
	
	if(argc != 2)
	{
		fprintf(stderr, "Usage: <pathname>\n");
		return -1;		
	}
	if(stat(argv[1], &statbuf) < 0)
	{
		perror("stat failed");
		return -1;
	}
	
	if(chmod(argv[1], (statbuf.st_mode)& (~S_IXOTH)) < 0)
	{
		perror("chmod failed");
		return -1;
	}
	
	return 0;
}
