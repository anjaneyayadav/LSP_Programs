#include<stdio.h>
#include<stdlib.h>
int main()
{
        FILE *rak;
        char hm[1024];
        rak=fopen("data.csv","r");
        if(rak==NULL)
        {
                printf("failed to open file");
		return 1;
        }
        while(fgets(hm,sizeof(hm),rak)!=NULL)
        {
                printf("%s",hm);
        }
        fclose(rak);
	return 0;
}
