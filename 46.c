#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int has_txt_extension(const char *filename) {
    const char *ext = strrchr(filename, '.');
    return ext && strcmp(ext, ".txt") == 0;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    FILE *output, *input;
    char buffer[1024];
    struct stat st;

    output = fopen("combined.txt", "w");
    if (output == NULL) {
        perror("Failed to create combined.txt");
        return 1;
    }

    dir = opendir(".");
    if (dir == NULL) {
        perror("Failed to open current directory");
        fclose(output);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip if not a regular file or not ending in .txt or is combined.txt itself
        if (!has_txt_extension(entry->d_name) || strcmp(entry->d_name, "combined.txt") == 0)
            continue;

        if (stat(entry->d_name, &st) == 0 && S_ISREG(st.st_mode)) {
            input = fopen(entry->d_name, "r");
            if (input == NULL) {
                perror(entry->d_name);
                continue;
            }

            fprintf(output, "\n--- Contents of %s ---\n", entry->d_name);

            while (fgets(buffer, sizeof(buffer), input)) {
                fputs(buffer, output);
            }

            fclose(input);
        }
    }

    closedir(dir);
    fclose(output);

    printf("All .txt files combined into 'combined.txt'\n");
    return 0;
}

