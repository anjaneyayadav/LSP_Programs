#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    const char *filename = "file.txt";
    struct stat fileInfo;

    // Get file information
    if (stat(filename, &fileInfo) != 0)
    {
        perror("Could not get file information");
        return 1;
    }

    // Convert the last modified time to a readable format
    char *modTime = ctime(&fileInfo.st_mtime);
	{
		printf("Last modified time of %s: %s", filename, modTime);
	}
   	return 0;
}
