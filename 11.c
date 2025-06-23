#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
        char *yadav="test";
        struct stat st;

        if(stat(yadav,&st)==0)
        {
                if(S_ISDIR(st.st_mode))
                {
                        printf("%s directory is present\n",yadav);
                }
                else
                {
                        printf("%s not a directory\n",yadav);
                }
        }
        else
        {
                printf("unable to open directory\n");
        }
}




