#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent  *de;  // Pointer to directory entry
    DIR *dr = opendir("..");  // Open current directory (dot represents current)

    if (dr == NULL) 
    {
        perror("Could not open current directory");
        return 1;
    }

    printf("Files in current directory:\n");

    // Read and print all files and directories
    while ((de = readdir(dr)) != NULL) 
    {
        printf("%s\n", de->d_name);
    }

    closedir(dr);
    return 0;
}
