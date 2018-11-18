#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	system("pwd");
	if(argc != 2)
	{
		fprintf(stderr, "Usage: <pathname>\n");
		return -1;		
	}
	if(-1 == chdir(argv[1]))
	{
		perror("chdir failed");
		return -1;
	}

	system("pwd");
	printf("chdir %s success\n", argv[1]);

	char buf[64] = {0};
	if(NULL == getcwd(buf, sizeof(buf)))
	{
		perror("getcwd failed");
		return -1;
	}
	printf("%s\n", buf);
	
	return 0;
}
