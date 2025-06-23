#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    const char *directory = ".";  // Change this if you want another directory
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    char fullpath[1024];
    long largestSize = 0;
    char largestFile[256] = "";

    dir = opendir(directory);
    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", directory, entry->d_name);

        if (stat(fullpath, &st) == 0 && S_ISREG(st.st_mode)) {
            if (st.st_size > largestSize) {
                largestSize = st.st_size;
                strncpy(largestFile, entry->d_name, sizeof(largestFile));
            }
        }
    }

    closedir(dir);

    if (largestSize > 0) {
        printf("Largest file: %s (%ld bytes)\n", largestFile, largestSize);
    } else {
        printf("No regular files found in directory.\n");
    }

    return 0;
}

