#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int has_log_extension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    return dot && strcmp(dot, ".log") == 0;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    const char *logDir = "Logs";

    // Create "Logs" directory if it doesn't exist
    if (stat(logDir, &st) == -1) {
        if (mkdir(logDir, 0777) == 0) {
            printf("Directory 'Logs' created successfully.\n");
        } else {
            perror("Failed to create 'Logs' directory");
            return 1;
        }
    }

    // Open current directory
    dir = opendir(".");
    if (dir == NULL) {
        perror("Unable to open current directory");
        return 1;
    }

    // Loop through all entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip directories and "." ".."
        if (entry->d_type == DT_DIR) continue;
        if (!has_log_extension(entry->d_name)) continue;

        // Prepare old and new file paths
        char oldpath[1024];
        char newpath[1024];
        snprintf(oldpath, sizeof(oldpath), "./%s", entry->d_name);
        snprintf(newpath, sizeof(newpath), "./%s/%s", logDir, entry->d_name);

        // Move file
        if (rename(oldpath, newpath) == 0) {
            printf("Moved: %s -> %s\n", oldpath, newpath);
        } else {
            perror("Failed to move file");
        }
    }

    closedir(dir);
    return 0;
}

