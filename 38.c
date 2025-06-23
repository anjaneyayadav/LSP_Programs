#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char dirname[100];
    time_t now;
    struct tm *t;

    // Get current time
    time(&now);
    t = localtime(&now);

    // Format date as "YYYY-MM-DD"
    strftime(dirname, sizeof(dirname), "%Y-%m-%d", t);

    // Create directory with 0777 permissions
    if (mkdir(dirname, 0777) == 0) {
        printf("Directory '%s' created successfully.\n", dirname);
    } else {
        perror("Failed to create directory");
    }

    return 0;
}

