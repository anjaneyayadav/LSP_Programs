#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    const char *dirname = "Documents";

    // Create directory with 0777 permissions (read/write/execute for all)
    if (mkdir(dirname, 0777) == 0)
    {
        printf("Directory '%s' created successfully.\n", dirname);
    }
    else
    {
        perror("Failed to create directory");
    }

    return 0;
}

