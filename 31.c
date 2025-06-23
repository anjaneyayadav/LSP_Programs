#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fp;
	char line[1024];
	char search[100];
	int linenumber=0;
	int found=0;

	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		printf("failed to open file\n");
		return 1;
	}
	printf("Enter the string search:");
	scanf("%s",search);

	while(fgets(line,sizeof(line),fp))
	{
		linenumber++;
		if(strstr(line,search))
		{
			printf("%d found the line %s",linenumber,line);
			found=1;
		}
	}
	if(!found)
	{
		printf("String %s not in the file\n",search);
	}
	fclose(fp);
	return 0;
}	
