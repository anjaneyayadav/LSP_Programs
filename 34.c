#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{
	struct stat st;

	if(stat("file.txt",&st)==-1)
	{
		printf("failed to get file info\n");
		return 1;
	}
	printf("permissions of file.txt:");

	printf((st.st_mode & S_IRUSR) ? "r":"-");
	printf((st.st_mode & S_IWUSR) ? "r":"-");
	printf((st.st_mode & S_IXUSR) ? "r":"-");

	printf((st.st_mode & S_IRGRP) ? "r":"-");
        printf((st.st_mode & S_IWGRP) ? "r":"-");
        printf((st.st_mode & S_IXGRP) ? "r":"-");

        printf((st.st_mode & S_IROTH) ? "r":"-");
        printf((st.st_mode & S_IWOTH) ? "r":"-");
        printf((st.st_mode & S_IXOTH) ? "r":"-");

	printf("\n");

	return 0;
}
