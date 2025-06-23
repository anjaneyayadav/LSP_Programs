#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char path[PATH_MAX];

    if (getcwd(path, sizeof(path)) != NULL) {
        printf("Current working directory: %s\n", path);
    } else {
        perror("getcwd() error");
    }

    return 0;
}

