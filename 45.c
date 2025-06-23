#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;

    if (stat("file.txt", &st) == -1) {
        perror("Unable to get file information");
        return 1;
    }

    printf("Number of hard links to 'file.txt': %lu\n", st.st_nlink);

    return 0;
}

