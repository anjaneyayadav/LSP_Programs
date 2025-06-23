#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	const char*path="../Backup";

	int status=mkdir(path,0777);

	if(status==0)
	{
		printf("Backup directory is created\n");
	}
	else
	{
		printf("directory is not created");
	}
	return 0;
}

