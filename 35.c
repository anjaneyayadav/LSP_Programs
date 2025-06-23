#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void deleteDirectory(const char *path)
{
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (!dir)
    {
        perror("Cannot open directory");
        return;
    }

    char filepath[1024];

    while ((entry = readdir(dir)) != NULL)
    {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Build full path
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(filepath, &st) == 0)
       	{
            if (S_ISDIR(st.st_mode))
	    {
                // Recursively delete subdirectory
                deleteDirectory(filepath);
            }
	    else
	    {
                // Delete file
                if (remove(filepath) != 0)
                    perror(filepath);
            }
        }
    }

    closedir(dir);

    // Finally delete the now-empty directory
    if (rmdir(path) == 0)
    {
        printf("Deleted directory: %s\n", path);
    
    }
    else
    {
	perror("Error deleting directory");

    }
}
int main()
{
    const char *target = "Temp";

    deleteDirectory(target);

    return 0;
}























