#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	char path[1024];
	struct stat st;

	printf("Enter the file or directory path:");
	scanf("%s",path);

	if(lstat(path,&st)==-1)
	{
		printf("fail to get file information\n");
		return 1;
	}
	if(S_ISREG(st.st_mode))
	{
		printf("it is regular file\n");
	}
	else if(S_ISDIR(st.st_mode))
	{
		printf("it is a directory\n");
	}
	else if(S_ISLNK(st.st_mode))
	{
		printf("it is a symbollic link\n");
	}
	else if(S_ISCHR(st.st_mode))
	{
		printf("it is a character\n");
	}
	else if(S_ISFIFO(st.st_mode))
	{
		printf("it is a fifo file\n");
	}
	else if(S_ISBLK(st.st_mode))
	{
		printf("it is a block device \n");
	}
	else
	{
		printf("Unknown file type");
	}
	return 0;
}

