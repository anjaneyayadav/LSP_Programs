#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void listAll(const char *path)
{
    DIR *folder;//pointer to directory stream opened with opendir().
    struct dirent *entry;// used to loop through directory entries (files/folders).
    struct stat info;// used to loop through directory entries (files/folders).
    char fullPath[512];//stores the full path of each file/folder for processing.

    folder = opendir(path);
    if (folder == NULL)
    {
        printf("Cannot open folder: %s\n", path);
        return;
    }

    while ((entry = readdir(folder)) != NULL)
    {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Create full path: folder + file name
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);



        printf("%s\n", fullPath);  // Print file or folder name
        stat(fullPath,&info);
        // If it's a folder, go inside it
        if (S_ISDIR(info.st_mode)) 
	{
            listAll(fullPath);  // Call function again (recursive)
        }
    }

    closedir(folder);
}

int main() 
{
    listAll("."); // Start with current folder
    return 0;
}
