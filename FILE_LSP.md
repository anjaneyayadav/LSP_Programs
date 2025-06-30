
1.Write a C program to create a new text file and write "Hello, World!" to it?
```
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd;
	int ret;
	char buf[64]="Hello,World";

	fd=open("file.txt",O_WRONLY|O_CREAT,0755);
	if(fd<0)
	{
		printf("File doesn't open\n");
		return;
	}
	printf("File open successfully\n");
	ret=write(fd,buf,strlen(buf));
	if(ret<0)
	{
		printf("File doesn't read\n");
		return;
	}
	buf[ret]=NULL;
	printf("%d bytes from file",ret,buf);
	close(fd);
}
```
2.Develop a C program to open an existing text file and display its contents?
```
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd;
	int ret;
	char buf[64];

	fd=open("file.txt",O_RDONLY);
	if(fd<0)
	{
		printf("failed to open file\n");
		return;
	}
	printf("open file successfully\n");
	ret=read(fd,buf,64);
	if(ret<0)
	{
		printf("failed to read file\n");
		return;
	}
	buf[ret]=NULL;
	printf("%d contents of file%s\n",ret,buf);
	close(fd);
}
```
3.Implement a C program to create a new directory named "Test" in the current directory?
```
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int status;
	status=mkdir("Test",0755);
	if(status==0)
	{
		printf("directory created successfully\n");
	}
	else
	{
		printf("directory not created\n");
	}
}
```
4,51. Write a C program to check if a file named "sample.txt " exists in the current directory?
```
#include<stdio.h>
#include<unistd.h>

int main()
{
	if(access("sample.txt",F_OK)==0)
	{
		printf("sample.txt exist in the current directory\n");
	}
	else
	{
		printf("not in current directory\n");
	}
}
```
5,55. Develop a C program to rename a file from "oldname.txt" to "newname.txt"?
```
#include<stdio.h>

int main()
{
	if(rename("oldname.txt","newname.txt")==0)
	{
		printf("rename successfully\n");
	}
	else
	{
		printf("failed to rename file\n");
	}
}
```
6,54. Implement a C program to delete a file named "delete_me.txt"?
```
#include<stdio.h>
#include<unistd.h>

int main()
{
	const *filename="delete_me.txt";
	if(remove(filename==0))
	{
		printf("file removed successfully\n",filename);
	}
	else
	{
		printf("failed to remove file\n");
	}
}
```

7,56. Write a C program to copy the contents of one file to another?
```
#include<stdio.h>

int main()
{
	FILE *src,*dest;
	int ch;

	src=fopen("source file.txt","r");
	if(src==NULL)
	{
		perror("Failed to open source file\n");
		return 1;
	}
	dest=fopen("destination file.txt","w");
	if(dest==NULL)
	{
		perror("failed to open destination file\n");
		fclose(src);
		return 1;
	}
	while((ch==fgetc(src))!=EOF)
	{
		fputc(ch,dest);
	}
	printf("file copied successfully\n");
	
	fclose(src);
	fclose(dest);
	
	return 0;
}
```

8. Develop a C program to move a file from one directory to another?
```
#include<stdio.h>

int main()
{
	const char *source="/home/anjaneyayadav/Linux/filemanagement/practice/source/sample.txt";

	const char *destination="/home/anjaneyayadav/Linux/filemanagement/practice/dest/sample.txt";

	if(rename(source,destination)==0)
	{
		printf("file moved successfully\n");
	}
	else
	{
		perror("failed to move file");
	}
}
```

9,58.Implement a C program to list all files in the current directory?
```
#include<stdio.h>
#include<dirent.h>

int main()
{
	struct dirent *de;
	DIR *dr=opendir("..");
	if(dr==NULL)
	{
		perror("could not open current directory\n");
		return 1;
	}
	printf("file in current directory\n");

	while((de=readdir(dr))!=NULL)
	{
		printf("%s\n",de->d_name);
	}
	close(dr);
	return 0;
}
```

10,59. Write a C program to get the size of a file named "file.txt"?
```
#include<stdio.h>

int main()
{
	FILE *fp;
	long size;

	fp=fopen("file.txt","r");
	if(fp==NULL)
	{
		perror("error open file\n");
		return 1;
	}
	fseek(fp,0,SEEK_END);

	size=ftell(fp);
	
	fclose(fp);
	printf("bytes of the file.txt %ld",size);
	return 0;
}
```

11. Develop a C program to check if a directory named "Test" exists in the current directory? 
```
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	char *yadav="test";
	struct stat st;

	if(stat(yadav,&st)==0)
	{
		if(S_ISDIR(st.st_mode))
		{
			printf("%s directory is present",yadav);
		}
		else
		{
			printf("%s not directory present\n",yadav);
		}
	}
	else
	{
		printf("unable to open directory\n");
	}
}
```
12,60. Implement a C program to create a new directory named "Backup" in the parent directory?
```

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	const char*path="../Backup";

	int status=mkdir(path,0777);

	if(status==0)
	{
		printf("Backup directory created\n");
	}
	else
	{
		printf("not creating");
	}
	return 0;
}
```

13 Write a C program to recursively list all files and directories in a given directory?.
```
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void listAll(const char *path)
{
    DIR *folder;
    struct dirent *entry;
    struct stat info;
    char fullPath[512];

    folder = opendir(path);
    if (folder == NULL)
    {
        printf("Cannot open folder: %s\n", path);
        return;
    }

    while ((entry = readdir(folder)) != NULL)
    {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Create full path: folder + file name
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);



        printf("%s\n", fullPath);  // Print file or folder name
        stat(fullPath,&info);
        // If it's a folder, go inside it
        if (S_ISDIR(info.st_mode))
        {
            listAll(fullPath);  // Call function again (recursive)
        }
    }

    closedir(folder);
}

int main()
{
    listAll("."); // Start with current folder
    return 0;
}
```

14.Develop a C program to delete all files in a directory named "Temp"?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *folder = "Temp";
    DIR *dir;
    struct dirent *entry;
    char filepath[1024];
    struct stat st;

    dir = opendir(folder);
    if (dir == NULL) {
        perror("Unable to open directory 'Temp'");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(filepath, sizeof(filepath), "%s/%s", folder, entry->d_name);

        if (stat(filepath, &st) == 0 && S_ISREG(st.st_mode)) {
            if (remove(filepath) == 0) {
                printf("Deleted: %s\n", filepath);
            } else {
                perror(filepath);
            }
        }
    }

    closedir(dir);
    return 0;
}
```
15,61,70. Implement a C program to count the number of lines in a file named "data.txt?
```
#include<stdio.h>

int main()
{
	FILE*file;
	char ch;
	int lines=0;

	file=fopen("data.txt","r");
	if(file==NULL)
	{
		printf("failed to open file\n");
		return 1;
	}
	while((ch=fgetc(file))!=EOF)
	{
		if(ch=='\n')
		{
			lines++;
		}
	}
	fclose(file);

	printf("%d lines of the file",lines);

	return 0;
}
```

16,62. Write a C program to append "Goodbye!" to the end of an existing file named  "message.txt"?
```
#include<stdio.h>

int main()
{
	FILE*file;
	file=fopen("message.txt","a");
	if(file==NULL)
	{
		printf("failed to open file\n");
	}
	fprintf(file,"GOODBYE!\n");
	fclose(file);

	printf("message written to file successfully");
	return 0;
}
```

17,64. Implement a C program to change the permissions of a file named "file.txt" to read only? 
```
#include<stdio.h>
#include<sys/stat.h>

int main()
{
	if(chmod("file.txt",0777)==0)
	{
		printf("success");
	}
	else
	{
		printf("failure");
	}
}
```

18,65.Write a C program to change the ownership of a file named "file.txt" to the user "user1"? 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
int main()
{
    const char *filename = "file.txt";
    const char *username = "user1";
    // Get user info from username
    struct passwd *pwd = getpwnam(username);
    if (pwd == NULL)
    {
        printf("User %s not found.\n", username);
        return 1;
    }
    uid_t uid = pwd->pw_uid;
    gid_t gid = pwd->pw_gid;
    // Change ownership of the file
    if (chown(filename, uid, gid) == 0)
    {
        printf("Ownership of %s changed to user %s\n", filename, username);
    }
    else
    {
        perror("Failed to change ownership");
        return 1;
    }
    return 0;
}
```

19,66. Develop a C program to get the last modified timestamp of a file named "file.txt"?
```
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
	const char*filename="file.txt";
	struct stat fileInfo;

	if(stat(filename,&fileInfo)!=0)
	{
		printf("could not get file information");
		return 1;
	}
	char*mTime=ctime(&fileInfo.st_mtime);
	{
		printf("last modified file information %s %s",filename,mTime);
	}
	return 0;
}
```
20,67. Implement a C program to create a temporary file and write some data to it?
```
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *filename=tmpfile();

	if(filename==NULL)
	{
		printf("failed to create file");
		return 1;
	}
	fprintf(filename,"this is temporary data");

	rewind(filename);

	char buffer[100];
	while(fgets(buffer,sizeof(buffer),filename)!=NULL)
	{
		printf("read from tmp file:%s",buffer);
	}
	fclose(filename);
	return 0;
}
```

21. Write a C program to check if a given path refers to a file or a directory?
```
#include<stdio.h>
#include<sys/stat.h>

int main()
{
	char path[256];
	struct stat info;

	printf("Enter a path:");
	scanf("%s",path);

	if(stat(path,&info)!=0)
	{
		printf("Error:can't access file\n");
		return 1;
	}
	if(S_ISREG(info.st_mode))
	{
		printf("it is a regular file\n");
	}
	else if(S_ISDIR(info.st_mode))
	{
		printf("it is a directory\n");
	}
	else
	{
		printf("neither it is file or directory");
	}
	return 0;
}
```
22. Develop a C program to create a hard link named "hardlink.txt" to a file named "source.txt"?
```
#include<stdio.h>
#include<unistd.h>
int main()
{
	const char *original="source.txt";
	const char *hardlink="hardlink.txt";

	if(link(original,hardlink)==0)
	{
		printf("it is success");
	}
	else
	{
		printf("failed");
	}
}
```

23,74. Implement a C program to read and display the contents of a CSV file named "data.csv"? 
```
#include<stdio.h>
#include<stdlib.h>

int main()
{
        FILE *yadav;
        char suri[1024];

        yadav=fopen("data.csv","r");
        if(yadav==NULL)
        {
                printf("failed to open file");
		return 1;
        }
        while(fgets(suri,sizeof(suri),yadav)!=NULL)
        {
                printf("%s",suri);
        }
        fclose(yadav);
	return 0;
}
```

24. Write a C program to get the absolute path of the current working directory?
```
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
	char path[PATH_MAX];

	if(getcwd(path,sizeof(path))!=NULL)
	{
		printf("current working directory %s ",path);
	}
	else
	{
		printf("not current working directory");
	}
}
```
25. Develop a C program to get the size of a directory named "Documents"?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

long long get_directory_size(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    long long total_size = 0;
    char fullpath[1024];

    dir = opendir(path);
    if (dir == NULL) {
        perror(path);
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &st) == 0) 
	{
            if (S_ISREG(st.st_mode)) 
	    {
                total_size += st.st_size;  // Add file size
            }
	    else if (S_ISDIR(st.st_mode)) 
	    {
                total_size += get_directory_size(fullpath);  // Recursive call
            }
        }
    }

    closedir(dir);
    return total_size;
}

int main() {
    const char *dirname = "Documents";

    long long size = get_directory_size(dirname);

    printf("Total size of '%s': %lld bytes\n", dirname, size);

    return 0;
}
```

26,83. Implement a C program to recursively copy all files and directories from one directory to another?
``` 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void copy_file(const char *src, const char *dest) {
    int in, out;
    char buffer[4096];
    ssize_t bytes;

    in = open(src, O_RDONLY);
    if (in < 0) {
        perror(src);
        return;
    }

    out = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        perror(dest);
        close(in);
        return;
    }

    while ((bytes = read(in, buffer, sizeof(buffer))) > 0) {
        write(out, buffer, bytes);
    }

    close(in);
    close(out);
}

void copy_directory(const char *src, const char *dest) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char src_path[1024], dest_path[1024];

    if (mkdir(dest, 0777) == -1 && errno != EEXIST) {
        perror(dest);
        return;
    }

    dir = opendir(src);
    if (!dir) {
        perror(src);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        if (stat(src_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                // Recursively copy subdirectory
                copy_directory(src_path, dest_path);
            } else if (S_ISREG(st.st_mode)) {
                // Copy file
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main() {
    const char *source_dir = "SourceDir";
    const char *destination_dir = "DestDir";

    copy_directory(source_dir, destination_dir);
    printf("Directory '%s' copied to '%s' successfully.\n", source_dir, destination_dir);

    return 0;
}
```
27. Write a C program to get the number of files in a directory named "Images"?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    const char *dirname = "Images";
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char path[1024];
    int file_count = 0;

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(path, sizeof(path), "%s/%s",dirname,entry->d_name);

	if(stat(path,&st)==0 && S_ISREG(st.st_mode))
	{
		file_count++;
	}
    }
    closedir(dir);
    printf("Number of regular files in "%s":%d\n",dirname,file_count);
    return 0;
}
```

28.Develop a C program to create a FIFO (named pipe) named "myfifo" in the currunt directory?
``` 
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>

int main()
{
	const char *fifoname="myfifo";

	if(mkfifo(fifoname,0666)==-1)
	{
		if(errno==EEXIST)
		{
			printf("file already exist %s\n",fifoname);
		}
		else
		{
			printf("no exist");
		}
	}
	else
	{
		printf("create new file %s\n",fifoname);
	}
	return 0;
}
```

29. Implement a C program to read data from a FIFO named "myfifo"?
```
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;
	const char *filename="myfifo";
	char buffer[256];

	fd=open(filename,O_RDONLY);
	if(fd<0)
	{
		printf("failed to open file");
		return 1;
	}
	ssize_t byteread=read(fd,buffer,sizeof(buffer)-1);
	if(byteread>0)
	{
		buffer[byteread]='\0';
		printf("read data:%s\n",buffer);
	}
	else
	{
		printf("read file or No data");
	}
	close(fd);
	return 0;
}
```

30,75. Write a C program to truncate a file named "file.txt" to a specified length?
```
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "file.txt";
    off_t length = 10;  // Truncate to 10 bytes

    if (truncate(filename, length) == 0) {
        printf("File '%s' truncated to %ld bytes.\n", filename, (long)length);
    } else {
        perror("Failed to truncate file");
    }

    return 0;
}
```
31. Develop a C program to search for a specific string in a file named "data.txt" and display the line number(s) where it occurs?
``` 
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    char line[1024];
    const char *search = "target"; // string to search
    int lineno = 1, found = 0;

    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, search)) {
            printf("Found at line %d: %s", lineno, line);
            found = 1;
        }
        lineno++;
    }

    if (!found) {
        printf("String not found.\n");
    }

    fclose(file);
    return 0;
}
```
32. Implement a C program to get the file type (regular file, directory, symbolic link, etc.) of a given path? 
```
#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *path = "file.txt";
    struct stat st;
 if (lstat(path, &st) == -1) {
        perror("Unable to get file information");
        return 1;
    }

    if (S_ISREG(st.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(st.st_mode))
        printf("Symbolic link\n");
    else
        printf("Other type\n");

    return 0;
}
```
33. Write a C program to create a new empty file named "empty.txt"?
```
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("empty.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Failed to create file");
        return 1;
    }
    printf("empty.txt created.\n");
    close(fd);
    return 0;
}
```
34. Develop a C program to get the permissions (mode) of a file named "file.txt"?
```
#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;

    if (stat("file.txt", &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("Permissions of file.txt: %o\n", st.st_mode & 0777);
    return 0;
}
```
35. Implement a C program to recursively delete a directory named "Temp" and all its contents?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void delete_dir(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    char fullpath[1024];
    struct stat st;

    if (!dir) {
        perror(path);
        return;
    }

    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (lstat(fullpath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                delete_dir(fullpath); // recursive call
            } else {
                remove(fullpath);
            }
        }
    }

    closedir(dir);
    if (rmdir(path) == 0)
        printf("Deleted directory: %s\n", path);
    else
        perror("rmdir");
}

int main() {
    delete_dir("Temp");
    return 0;
}
```

36. Write a C program to read and display the first 10 lines of a file named "log.txt"?
```
#include<stdio.h>

int main()
{
	FILE*file;
	char line[1024];
	int count=0;

	file=fopen("log.txt","r");
	if(file==NULL)
	{
		printf("failed to open file");
		return 1;
	}
	while(fgets(line,sizeof(line),file) && count<10)
	{
		printf("%s",line);
		count++;
	}
	fclose(file);
	return 0;
}
```

37. Develop a C program to read data from a text file named "input.txt" and write it to another file named "output.txt" in reverse order? 
```
#include<stdio.h>

int main()
{
	FILE *input,*output;
	long file_size;

	input=fopen("input.txt","r");
	if(input==NULL)
	{
		printf("failed to open file");
		return 1;
	}
	output=fopen("output.txt","w");
	if(output==NULL)
	{
		printf("failed to open file");
		fclose(input);
		return 1;
	}
	fseek(input,0,SEEK_END);
	file_size=ftell(input);

	for(long i=file_size-1;i>=0;i--)
	{
		fseek(input,i,SEEK_SET);
		int ch=fgetc(input);
		fputc(ch,output);
	}
	printf("file reversed successfully");

	fclose(input);
	fclose(output);

	return 0;
}
```

38. Implement a C program to create a new directory named with the current date in the format "YYYY-MM-DD"? 
```
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<sys/types.h>

int main()
{
	char dirname[100];
	time_t now;
	struct time *t;

	time(&now);
	t=localtime(&now);

	strftime(dirname,sizeof(dirname),"%y->%m->%d",t);

	if(mkdir(dirname,0777)==0)
	{
		printf("directory created successfully %s\n",dirname);
	}
	else
	{
		printf("failed to create");
	}
	return 0;
}
```

39,78. Write a C program to read and display the contents of a binary file named "binary.bin"?
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    unsigned char buffer[1024];
    size_t bytesRead;

    file = fopen("binary.bin", "rb");
    if (file == NULL) 
    {
        perror("Failed to open file");
        return 1;
    }

    printf("Contents of binary.bin (in hexadecimal):\n");

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        for (size_t i = 0; i < bytesRead; i++)
        {
            printf("%02X ", buffer[i]); 
        }
    }

    printf("\n");
    fclose(file);
    return 0;
}
```

40. Develop a C program to get the size of the largest file in a directory?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main() 
{
    const char *directory = "."; 
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    char fullpath[1024];
    long largestSize = 0;
    char largestFile[256] = "";

    dir = opendir(directory);
    if (dir == NULL) 
    {
        perror("Unable to open directory");
        return 1;
    }
    while ((entry = readdir(dir)) != NULL)
    {
           if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
	   {
		   continue;
	   }
           snprintf(fullpath, sizeof(fullpath), "%s/%s", directory, entry->d_name);

        if (stat(fullpath, &st) == 0 && S_ISREG(st.st_mode)) 
	{
            if (st.st_size > largestSize) 
	    {
                largestSize = st.st_size;
                strncpy(largestFile, entry->d_name, sizeof(largestFile));
            }
        }
    }

    closedir(dir);

    if (largestSize > 0) 
    {
        printf("Largest file: %s (%ld bytes)\n", largestFile, largestSize);
    }
    else 
    {
        printf("No regular files found in directory.\n");
    }

    return 0;
}
```

41. Implement a C program to check if a file named "data.txt" is readable?
```
#include <stdio.h>
#include <unistd.h>  

int main()
{
    const char *filename = "data.txt";

    if (access(filename, R_OK) == 0)
    {
        printf("The file '%s' is readable.\n", filename);
    }
    else
    {
        perror("File is not readable or does not exist");
    }

    return 0;
}
```

42,79. Write a C program to create a new directory named "Logs" and move all files with the ".log" extension into it? 
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int has_log_extension(const char *filename)
{
    const char *dot = strrchr(filename, '.');
    return dot && strcmp(dot, ".log") == 0;
}

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    const char *logDir = "Logs";

    if (stat(logDir, &st) == -1)
    {
        if (mkdir(logDir, 0777) == 0)
       	{
            printf("Directory 'Logs' created successfully.\n");
        }
       	else
       	{
            perror("Failed to create 'Logs' directory");
            return 1;
        }
    }

    dir = opendir(".");
    if (dir == NULL) 
    {
        perror("Unable to open current directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if (entry->d_type == DT_DIR)
	{
		continue;
	}
        if (!has_log_extension(entry->d_name))
	{
		continue;
	}
        char oldpath[1024];
        char newpath[1024];
        snprintf(oldpath, sizeof(oldpath), "./%s", entry->d_name);
        snprintf(newpath, sizeof(newpath), "./%s/%s", logDir, entry->d_name);

        if (rename(oldpath, newpath) == 0)
       	{
            printf("Moved: %s -> %s\n", oldpath, newpath);
        } 
	else
       	{
            perror("Failed to move file");
        }
    }

    closedir(dir);
    return 0;
}
```

43. Develop a C program to check if a file named "config.ini" is writable?
```
#include <stdio.h>
#include <unistd.h>  

int main()
{
    const char *filename = "config.ini";

    if (access(filename, W_OK) == 0)
    {
        printf("The file '%s' is writable.\n", filename);
    }
    else
    {
        perror("File is not writable or does not exist");
    }

    return 0;
}
```

44,81. Implement a C program to read the contents of a text file named "instructions.txt" and execute the instructions as shell commands? 
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    char command[1024];

    file = fopen("instructions.txt", "r");
    if (file == NULL) 
    {
        perror("Unable to open instructions.txt");
        return 1;
    }

    printf("Executing shell commands from instructions.txt:\n\n");

    while (fgets(command, sizeof(command), file) != NULL)
    {
        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) == 0)
	{
		continue;
	}
        printf(">> %s\n", command);
        int status = system(command);

        if (status == -1) 
	{
            perror("system() failed");
        }
       	else
       	{
            printf("Command executed with exit code: %d\n\n", WEXITSTATUS(status));
        }
    }

    fclose(file);
    return 0;
}
```
45. Write a C program to get the number of hard links to a file named "file.txt"?
```
#include <stdio.h>
#include <sys/stat.h>

int main() 
{
    struct stat st;

    if (stat("file.txt", &st) == -1) 
    {
        perror("Unable to get file information");
        return 1;
    }

    printf("Number of hard links to 'file.txt': %lu\n", st.st_nlink);

    return 0;
}
```

46. Develop a C program to copy the contents of all text files in a directory into a single file named "combined.txt"?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int has_txt_extension(const char *filename)
{
    const char *ext = strrchr(filename, '.');
    return ext && strcmp(ext, ".txt") == 0;
}

int main()
{
    DIR *dir;
    struct dirent *entry;
    FILE *output, *input;
    char buffer[1024];
    struct stat st;

    output = fopen("combined.txt", "w");
    if (output == NULL)
    {
        perror("Failed to create combined.txt");
        return 1;
    }

    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Failed to open current directory");
        fclose(output);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (!has_txt_extension(entry->d_name) || strcmp(entry->d_name, "combined.txt") == 0)
	{
            continue;
	}
        if (stat(entry->d_name, &st) == 0 && S_ISREG(st.st_mode)) 
	{
            input = fopen(entry->d_name, "r");
            if (input == NULL)
	    {
                perror(entry->d_name);
                continue;
            }

            fprintf(output, "\n--- Contents of %s ---\n", entry->d_name);

            while (fgets(buffer, sizeof(buffer), input))
	    {
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
```

47. Implement a C program to recursively calculate the total size of all files in a directory and its subdirectories? 
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

long long getTotalSize(const char *path)
{
    struct dirent *entry;
    struct stat st;
    DIR *dir = opendir(path);
    long long totalSize = 0;

    if (dir == NULL)
    {
        perror(path);
        return 0;
    }

    char fullpath[1024];

    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
	{
            continue;
	}
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &st) == 0)
       	{
            if (S_ISREG(st.st_mode)) 
	    {
                totalSize += st.st_size;
            } 
	    else if (S_ISDIR(st.st_mode)) 
	    {
                totalSize += getTotalSize(fullpath);
            }
        }
    }

    closedir(dir);
    return totalSize;
}

int main() 
{
    const char *targetDir = ".";
    long long size = getTotalSize(targetDir);

    printf("Total size of all files in '%s': %lld bytes\n", targetDir, size);

    return 0;
}
```

48. Write a C program to get the number of bytes in a file named "data.bin"?
```
#include <stdio.h>

int main() 
{
    FILE *file;
    long size;

    file = fopen("data.bin", "rb");
    if (file == NULL) 
    {
        perror("Unable to open file");
        return 1;
    }

    fseek(file, 0, SEEK_END);    
    size = ftell(file);    
    fclose(file);

    printf("Size of 'data.bin': %ld bytes\n", size);
    return 0;
}
```

49. Develop a C program to create a new directory named with the current timestamp in the format "YYYY-MM-DD-HH-MM-SS"?
```
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    char dirname[100];
    time_t now;
    struct tm *t;

    time(&now);
    t = localtime(&now);

    strftime(dirname, sizeof(dirname), "%Y-%m-%d-%H-%M-%S", t);

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
```

50. Write a C program to create a new directory named "Documents" in the current directory? 
```
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    const char *dirname = "Documents";

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
```
51. Develop a C program to check if a file named "file.txt" exists in the current directory?
``` 
#include<stdio.h>
#include<unistd.h>

int main()
{
	if(access("sample.txt",F_OK)==0)
	{
		printf("sample.txt exist in the current directory\n");
	}
	else
	{
		printf("not in current directory\n");
	}
}
```
52. Implement a C program to open a file named "data.txt" in read mode and display its contents?
```
#include <stdio.h>

int main() 
{
    FILE *file;
    char ch;

    file = fopen("data.txt", "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    printf("Contents of data.txt:\n\n");

    while ((ch = fgetc(file)) != EOF) 
    {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
```
53. Write a C program to create a new text file named "output.txt" and write "Hello, World!" 
to it?
```
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd;
	int ret;
	char buf[64]="Hello,World";

	fd=open("file.txt",O_WRONLY|O_CREAT,0755);
	if(fd<0)
	{
		printf("File doesn't open\n");
		return;
	}
	printf("File open successfully\n");
	ret=write(fd,buf,strlen(buf));
	if(ret<0)
	{
		printf("File doesn't read\n");
		return;
	}
	buf[ret]=NULL;
	printf("%d bytes from file",ret,buf);
	close(fd);
}
```
54. Develop a C program to delete a file named "delete_me.txt" from the current directory?
``` 
#include<stdio.h>
#include<unistd.h>

int main()
{
	const *filename="delete_me.txt";
	if(remove(filename==0))
	{
		printf("file removed successfully\n",filename);
	}
	else
	{
		printf("failed to remove file\n");
	}
}
```
55. Implement a C program to rename a file from "old_name.txt" to "new_name.txt"? 
```
#include<stdio.h>
int main()
{
	if(rename("oldname.txt","newname.txt")==0)
	{
		printf("rename successfully\n");
	}
	else
	{
		printf("failed to rename file\n");
	}
}
```
56. Write a C program to copy the contents of one file to another file? 
```
#include<stdio.h>

int main()
{
	FILE *src,*dest;
	int ch;

	src=fopen("source file.txt","r");
	if(src==NULL)
	{
		perror("Failed to open source file\n");
		return 1;
	}
	dest=fopen("destination file.txt","w");
	if(dest==NULL)
	{
		perror("failed to open destination file\n");
		fclose(src);
		return 1;
	}
	while((ch==fgetc(src))!=EOF)
	{
		fputc(ch,dest);
	}
	printf("file copied successfully\n");
	
	fclose(src);
	fclose(dest);
	
	return 0;
}
```
57. Develop a C program to move a file named "file.txt" to a directory named "Backup"?
```
#include <stdio.h>

int main()
{
    const char *source = "file.txt";
    const char *destination = "Backup/file.txt";

    if (rename(source, destination) == 0) 
    {
        printf("File moved to 'Backup/' directory successfully.\n");
    }
    else
    {
        perror("Failed to move the file");
    }

    return 0;
}
```
58. Implement a C program to list all files and directories in the current directory? 
```
#include<stdio.h>
#include<dirent.h>

int main()
{
	struct dirent *de;
	DIR *dr=opendir("..");
	if(dr==NULL)
	{
		perror("could not open current directory\n");
		return 1;
	}
	printf("file in current directory\n");

	while((de=readdir(dr))!=NULL)
	{
		printf("%s\n",de->d_name);
	}
	close(dr);
	return 0;
}
```
59. Write a C program to get the size of a file named "data.txt"? 
```
#include<stdio.h>
int main()
{
	FILE *fp;
	long size;

	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		perror("error open file\n");
		return 1;
	}
	fseek(fp,0,SEEK_END);

	size=ftell(fp);
	
	fclose(fp);
	printf("bytes of the data.txt %ld",size);
	return 0;
}
```
60. Develop a C program to create a new directory named "Pictures" in the parent 
directory?
```
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	const char*path="../Backup";

	int status=mkdir(path,0777);

	if(status==0)
	{
		printf("Backup directory created\n");
	}
	else
	{
		printf("not creating");
	}
	return 0;
}
```
61. Develop a C program to count the number of lines in a file named "log.txt"? 
```
#include<stdio.h>

int main()
{
	FILE*file;
	char ch;
	int lines=0;

	file=fopen("log.txt","r");
	if(file==NULL)
	{
		printf("failed to open file\n");
		return 1;
	}
	while((ch=fgetc(file))!=EOF)
	{
		if(ch=='\n')
		{
			lines++;
		}
	}
	fclose(file);

	printf("%d lines of the file",lines);

	return 0;
}
```
62. Implement a C program to append "Goodbye!" to the end of an existing file named 
"message.txt"?
```
#include<stdio.h>

int main()
{
	FILE*file;
	file=fopen("message.txt","a");
	if(file==NULL)
	{
		printf("failed to open file\n");
	}
	fprintf(file,"GOODBYE!\n");
	fclose(file);

	printf("message written to file successfully");
	return 0;
}
```
63,71. Write a C program to create a symbolic link named "link.txt" to a file named "target.txt"? 
```
#include <stdio.h>
#include <unistd.h>

int main() 
{
    const char *target = "target.txt";
    const char *linkname = "link.txt";

    if (symlink(target, linkname) == 0) 
    {
        printf("Symbolic link '%s' created pointing to '%s'\n", linkname, target);
    } 
    else
    {
        perror("Failed to create symbolic link");
    }

    return 0;
}
```
64. Develop a C program to change the permissions of a file named "file.txt" to read-only?
```
#include<stdio.h>
#include<sys/stat.h>

int main()
{
	if(chmod("file.txt",0777)==0)
	{
		printf("success");
	}
	else
	{
		printf("failure");
	}
}
```
65. Implement a C program to change the ownership of a file named "file.txt" to the user 
"user1?
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
int main()
{
    const char *filename = "file.txt";
    const char *username = "user1";
    // Get user info from username
    struct passwd *pwd = getpwnam(username);
    if (pwd == NULL)
    {
        printf("User %s not found.\n", username);
        return 1;
    }
    uid_t uid = pwd->pw_uid;
    gid_t gid = pwd->pw_gid;
    // Change ownership of the file
    if (chown(filename, uid, gid) == 0)
    {
        printf("Ownership of %s changed to user %s\n", filename, username);
    }
    else
    {
        perror("Failed to change ownership");
        return 1;
    }
    return 0;
}
```
66. Write a C program to get the last modified timestamp of a file named "file.txt"?
```
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
	const char*filename="file.txt";
	struct stat fileInfo;

	if(stat(filename,&fileInfo)!=0)
	{
		printf("could not get file information");
		return 1;
	}
	char*mTime=ctime(&fileInfo.st_mtime);
	{
		printf("last modified file information %s %s",filename,mTime);
	}
	return 0;
}
```
67. Develop a C program to create a temporary file and write some data to it?
```
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *filename=tmpfile();

	if(filename==NULL)
	{
		printf("failed to create file");
		return 1;
	}
	fprintf(filename,"this is temporary data");

	rewind(filename);

	char buffer[100];
	while(fgets(buffer,sizeof(buffer),filename)!=NULL)
	{
		printf("read from tmp file:%s",buffer);
	}
	fclose(filename);
	return 0;
}
```
68. Implement a C program to get the size of a file named "image.jpg"?
```
#include <stdio.h>

int main()
{
    FILE *file;
    long size;

    file = fopen("image.jpg", "rb");  
    if (file == NULL) 
    {
        perror("Failed to open image.jpg");
        return 1;
    }

    fseek(file, 0, SEEK_END);  
    size = ftell(file);        
    fclose(file);     
    printf("Size of 'image.jpg': %ld bytes\n", size);
    return 0;
}
```
69. Write a C program to create a new text file named "notes.txt" and write multiple lines of text to it?
```
#include <stdio.h>

int main() 
{
    FILE *file = fopen("notes.txt", "w");  
    if (file == NULL) 
    {
        perror("Failed to create file");
        retur 1;
    }	
    fprintf(file, "This is line 1.\n");
    fprintf(file, "This is line 2.\n");
    fprintf(file, "This is line 3.\n");
    fprintf(file, "End of notes.\n");

    fclose(file);
    printf("File 'notes.txt' created and written successfully.\n");

    return 0;
}
```
70. Develop a C program to count the number of words in a file named "essay.txt"? 
```
#include<stdio.h>

int main()
{
	FILE*file;
	char ch;
	int lines=0;

	file=fopen("essay.txt","r");
	if(file==NULL)
	{
		printf("failed to open file\n");
		return 1;
	}
	while((ch=fgetc(file))!=EOF)
	{
		if(ch=='\n')
		{
			lines++;
		}
	}
	fclose(file);

	printf("%d lines of the file",lines);

	return 0;
}
```
71. Write a C program to create a symbolic link named "shortcut.txt" to a file named 
"target.txt"? 
```
#include <stdio.h>
#include <unistd.h>

int main() 
{
    const char *target = "target.txt";
    const char *linkname = "shortcut.txt";

    if (symlink(target, linkname) == 0) 
    {
        printf("Symbolic link '%s' created pointing to '%s'\n", linkname, target);
    } 
    else
    {
        perror("Failed to create symbolic link");
    }

    return 0;
}
```

72.Develop a C program to change the permissions of a file named "important.doc" to read and write for the owner only? 
```
#include <stdio.h>
#include <sys/stat.h>

int main() 
{
    const char *filename = "important.doc";

    if (chmod(filename, 0600) == 0)
    {
        printf("Permissions changed successfully for '%s'.\n", filename);
    }
    else
    {
        perror("Failed to change permissions");
    }

    return 0;
}
```
73. Write a C program to get the last access time of a file named "data.txt"?
```
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    const char *filename = "data.txt";
    struct stat st;

    if (stat(filename, &st) == -1) 
    {
        perror("Failed to get file info");
        return 1;
    }

    printf("Last access time of '%s': %s", filename, ctime(&st.st_atime));

    return 0;
}
```
74. Develop a C program to read and display the contents of a CSV file named "data.csv"?
```
#include<stdio.h>
#include<stdlib.h>

int main()
{
        FILE *yadav;
        char suri[1024];

        yadav=fopen("data.csv","r");
        if(yadav==NULL)
        {
                printf("failed to open file");
                return 1;
        }
        while(fgets(suri,sizeof(suri),yadav)!=NULL)
        {
                printf("%s",suri);
        }
        fclose(yadav);
        return 0;
}
```
75. Implement a C program to truncate a file named "file.txt" to a specified length?
```
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "file.txt";
    off_t length = 10;  // Truncate to 10 bytes

    if (truncate(filename, length) == 0) {
        printf("File '%s' truncated to %ld bytes.\n", filename, (long)length);
    } else {
        perror("Failed to truncate file");
    }

    return 0;
}
```
76. Write a C program to search for a specific word in a file named "data.txt" and display the line number(s) where it occurs? 
```
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file = fopen("data.txt", "r");
    char line[1024];
    const char *word = "example"; 
    int lineno = 1, found = 0;

    if (file == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, word))
       	{
            printf("Found on line %d: %s", lineno, line);
            found = 1;
        }
        lineno++;
    }

    if (!found)
    {
        printf("Word '%s' not found in file.\n", word);
    }

    fclose(file);
    return 0;
}
```

77,84. Develop a C program to get the file type (regular file, directory, symbolic link,etc.) of a given path?
```
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    const char *path = "example.txt"; 
    struct stat st;

    if (lstat(path, &st) == -1) 
    {
        perror("Failed to get file status");
        return 1;
    }

    printf("File type of '%s': ", path);
    if (S_ISREG(st.st_mode))
    {
        printf("Regular file\n");
    }
    else if (S_ISDIR(st.st_mode))
    {
        printf("Directory\n");
    }
    else if (S_ISLNK(st.st_mode))
    {
        printf("Symbolic link\n");
    }
    else if (S_ISCHR(st.st_mode))
    {
        printf("Character device\n");
    }
    else if (S_ISBLK(st.st_mode))
    {
        printf("Block device\n");
    }
    else if (S_ISFIFO(st.st_mode))
    {
        printf("FIFO (named pipe)\n");
    }
    else if (S_ISSOCK(st.st_mode))
    {
        printf("Socket\n");
    }
    else
    {
        printf("Unknown type\n");
    }

    return 0;
}
```
78. Implement a C program to read and display the contents of a binary file named 
"binary.bin"?
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    unsigned char buffer[1024];
    size_t bytesRead;

    file = fopen("binary.bin", "rb");
    if (file == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    printf("Contents of binary.bin (in hexadecimal):\n");

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        for (size_t i = 0; i < bytesRead; i++)
        {
            printf("%02X ", buffer[i]);
        }
    }

    printf("\n");
    fclose(file);
    return 0;
}
```
79. Implement a C program to create a new directory named "Logs" and move all files with 
the ".log" extension into it?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int has_log_extension(const char *filename)
{
    const char *dot = strrchr(filename, '.');
    return dot && strcmp(dot, ".log") == 0;
}

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    const char *logDir = "Logs";

    if (stat(logDir, &st) == -1)
    {
        if (mkdir(logDir, 0777) == 0)
        {
            printf("Directory 'Logs' created successfully.\n");
        }
        else
        {
            perror("Failed to create 'Logs' directory");
            return 1;
        }
    }

    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Unable to open current directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
                continue;
        }
        if (!has_log_extension(entry->d_name))
        {
                continue;
        }
        char oldpath[1024];
        char newpath[1024];
        snprintf(oldpath, sizeof(oldpath), "./%s", entry->d_name);
        snprintf(newpath, sizeof(newpath), "./%s/%s", logDir, entry->d_name);

        if (rename(oldpath, newpath) == 0)
        {
            printf("Moved: %s -> %s\n", oldpath, newpath);
        }
        else
        {
            perror("Failed to move file");
        }
    }

    closedir(dir);
    return 0;
}
```
80. Write a C program to check if a file named "config.ini" is writable?
```
#include <stdio.h>
#include <unistd.h>

int main() 
{
    const char *filename = "config.ini";

    if (access(filename, W_OK) == 0) 
    {
        printf("The file '%s' is writable.\n", filename);
    }
    else 
    {
        perror("Write access check failed");
    }

    return 0;
}
```
81. Develop a C program to read the contents of a text file named "instructions.txt" and 
execute the instructions as shell commands?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    char command[1024];

    file = fopen("instructions.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open instructions.txt");
        return 1;
    }

    printf("Executing shell commands from instructions.txt:\n\n");

    while (fgets(command, sizeof(command), file) != NULL)
    {
        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) == 0)
        {
                continue;
        }
        printf(">> %s\n", command);
        int status = system(command);

        if (status == -1)
        {
            perror("system() failed");
        }
        else
        {
            printf("Command executed with exit code: %d\n\n", WEXITSTATUS(status));
        }
    }

    fclose(file);
    return 0;
}
```

82.Develop a C program to read data from a binary file named "data.bin" and display it in hexadecimal format? 
```
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *file = fopen("data.bin", "rb");  
    if (file == NULL) 
    {
        perror("Failed to open data.bin");
        return 1;
    }

    unsigned char buffer[16]; 
    size_t bytesRead;
    size_t offset = 0;

    printf("Hex dump of data.bin:\n\n");

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) 
    {
        printf("%08zx  ", offset);
        for (size_t i = 0; i < bytesRead; ++i)
       	{
            printf("%02x ", buffer[i]);
        }
        for (size_t i = bytesRead; i < 16; ++i) 
	{
            printf("   ");
        }
        printf(" |");
        for (size_t i = 0; i < bytesRead; ++i) 
	{
            if (buffer[i] >= 32 && buffer[i] <= 126)
	    {
                putchar(buffer[i]);
	    }
 	    else
	    {
                putchar('.');
	    }
        }
        printf("|\n");

        offset += bytesRead;
    }

    fclose(file);
    return 0;
}
```
83. Develop a C program to recursively copy all files and directories from one directory to 
another?
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void copy_file(const char *src, const char *dest) {
    int in, out;
    char buffer[4096];
    ssize_t bytes;

    in = open(src, O_RDONLY);
    if (in < 0) {
        perror(src);
        return;
    }

    out = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        perror(dest);
        close(in);
        return;
    }

    while ((bytes = read(in, buffer, sizeof(buffer))) > 0) {
        write(out, buffer, bytes);
    }

    close(in);
    close(out);
}

void copy_directory(const char *src, const char *dest) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char src_path[1024], dest_path[1024];

    if (mkdir(dest, 0777) == -1 && errno != EEXIST) {
        perror(dest);
        return;
    }

    dir = opendir(src);
    if (!dir) {
        perror(src);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        if (stat(src_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                // Recursively copy subdirectory
                copy_directory(src_path, dest_path);
            } else if (S_ISREG(st.st_mode)) {
                // Copy file
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main() {
    const char *source_dir = "SourceDir";
    const char *destination_dir = "DestDir";

    copy_directory(source_dir, destination_dir);
    printf("Directory '%s' copied to '%s' successfully.\n", source_dir, destination_dir);

    return 0;
}
```





















































