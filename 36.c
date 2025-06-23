#include <stdio.h>

int main()
{
    FILE *file;
    char line[1024];
    int count = 0;

    file = fopen("log.txt", "r");

    if (file == NULL)
    {
        perror("Unable to open file");
        return 1;
    }

    while (fgets(line, sizeof(line), file) && count < 10)
    {
        printf("%s", line);  // Line already includes newline
        count++;
    }

    fclose(file);
    return 0;
}

