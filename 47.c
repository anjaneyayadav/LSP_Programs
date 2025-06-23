#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

long long getTotalSize(const char *path) {
    struct dirent *entry;
    struct stat st;
    DIR *dir = opendir(path);
    long long totalSize = 0;

    if (dir == NULL) {
        perror(path);
        return 0;
    }

    char fullpath[1024];

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                totalSize += st.st_size;
            } else if (S_ISDIR(st.st_mode)) {
                // Recurse into subdirectory
                totalSize += getTotalSize(fullpath);
            }
        }
    }

    closedir(dir);
    return totalSize;
}

int main() {
    const char *targetDir = ".";  // Use "." for current directory
    long long size = getTotalSize(targetDir);

    printf("Total size of all files in '%s': %lld bytes\n", targetDir, size);

    return 0;
}

