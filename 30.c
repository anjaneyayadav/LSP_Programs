#include<stdio.h>
#include<unistd.h>

int main()
{
	const char *filename="file.txt";

	off_t new_length;

	printf("Enter the new length of file:");
	scanf("%ld",&new_length);

	if(truncate(filename,new_length)==0)
	{
		printf("%s truncate to %ld bytes successfully\n",filename,new_length);
	}
	else
	{
		printf("error truncating file");
	}
	return 0;
}
