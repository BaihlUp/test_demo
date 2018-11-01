#include<stdio.h>
#include<stdlib.h>

int main()
{
	#if 0
	FILE *read_fp;
	char buffer[BUFSIZ + 1];
	int chars_read;
	memset(buffer, '\0', sizeof(buffer));
	read_fp = popen("uname -r", "r");
	if(read_fp != NULL)
	{
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		if(chars_read > 0)
		{
			printf("Output was: %s\n", buffer);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);		//#include<stdlib.h>
	}
	exit(EXIT_FAILURE);    //#include<stdlib.h>
	#endif 

#if 0
	FILE *write_fp;
	char buffer[BUFSIZ + 1];
	sprintf(buffer, "%s", "This is test\n");

	write_fp = popen("od -c", "w");
	if(write_fp != NULL)
	{
		fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);		//#include<stdlib.h>
	}
	exit(EXIT_FAILURE); 
#endif

	FILE *read_fp;
	char buffer[BUFSIZ + 1];
	char chars_len;

	memset(buffer, '\0', sizeof(buffer));  //单引号和双引号\0是有差异的

	read_fp = popen("ps ax", "r");
	if(read_fp != NULL)
	{
		chars_len = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while(chars_len > 0)
		{
			buffer[chars_len -1] = '\0';
			printf("Reading %d:\n %s\n", BUFSIZ, buffer);
			memset(buffer, "\0", sizeof(buffer));
			chars_len = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS); 	//#include<stdlib.h>
	}
	exit(EXIT_FAILURE); 
}


