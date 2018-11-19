#include<sys/stat.h>
#include<stdio.h>
#include<dirent.h>

void read_dir(char *dir)
{
	char path[256];
	DIR *dp;
	struct dirent *sdp;

	dp = opendir(dir);
	if(dp == NULL)
	{
		perror("opendir failed");
		return;
	}
	while((sdp = readdir(dp)) != NULL)
	{
		if(sdp->d_name[0] == '.')
			continue;
		sprintf(path, "%s/%s", dir, sdp->d_name);
		isFile(path);
	}

	closedir(dp);
}

void isFile(char *pathname)
{
	struct stat sbuf;

	if(-1 == stat(pathname, &sbuf))
	{
		perror("stat failed");
		return;
	}
	if(S_ISDIR(sbuf.st_mode))
	{
		//printf("%s:\n", pathname);
		read_dir(pathname);
	}
	printf("%s\t%d\n", pathname, sbuf.st_size);
	return ;
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		isFile(".");
	}
	else{
		while(--argc > 0)
		{
			isFile(*++argv);
		}
	}

	return 0;
}

