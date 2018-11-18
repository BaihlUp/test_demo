#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *sdp;

	if(argc != 2)
	{
		fprintf(stderr, "Usage: <dirpathname>\n");
		return -1;
	}
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		perror("opendir failed");
		return -1;
	}

	while((sdp = readdir(dp)) != NULL)
	{
		//排除.开头的文件或目录
		if(sdp->d_name[0] == '.')
			continue;
		printf("%s\t", sdp->d_name);
	}
	printf("\n");

	closedir(dp);

	return 0;
}

