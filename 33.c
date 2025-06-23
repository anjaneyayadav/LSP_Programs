#include<stdio.h>

int main()
{
	FILE *fp;

	fp=fopen("empty.txt","w");
	if(fp==NULL)
	{
		printf("failed to create");
		return 1;
	}
	else
	{
		printf("Successfully created file");
	}
	fclose(fp);
	return 0;
}
