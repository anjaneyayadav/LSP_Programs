#include<stdio.h>
int main()
{
        FILE *file;
        file=fopen("message.txt","a");
        if(file==NULL)
        {
                printf("file could not open\n");
        }
        fprintf(file,"GOODBYE!\n");
        fclose(file);
	
	printf("Message written to file successfully");
}
