/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/ 

/*
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
*/

/*
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
*/


/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/


/*
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
*/

/*
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
*/


/*
#include<stdio.h>
int main()
{
	if(link("file.txt","source.txt")==0)
	{
		printf("it is success");
	}
	else
	{
		printf("failed");
	}
}
*/

/*
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
*/

/*
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
*/


/*
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
*/


/*
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
*/


/*
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
*/

/*
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
*/


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

	




























































































