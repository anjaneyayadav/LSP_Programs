3. Write a C program to demonstrate the use of fork() system call.
```
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
	pid_t pid;

	pid=fork();

	if(pid<0)
	{
		printf("fork failed");
		return 1;
	}
	else if(pid==0)
	{
		printf("Child process:\n");
		printf("Child PID:%d\n",getpid());
		printf("Parent PID:%d\n",getpid());
	}
	else
	{
		printf("Parent process:\n");
		printf("Parent PID:%d\n",getpid());
		printf("Child PID:%d\n",pid);
	}
	return 0;

}
```
6. Write a C program to illustrate the use of the execvp() function.
```
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

	char *args[]={"ls","-l",NULL};
	printf("Before execvp()\n");

	execvp(args[0],args);
	printf("Execvp failed");

	return 1;
}
```
10. Write a program in C to create a child process using fork() and print its PID
```
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
	pid_t pid;

	pid=fork();

	if(pid<0)
	{
		printf("fork failed");
		return 1;
	}
	else if(pid==0)
	{
		printf("Child process:\n");
		printf("Child PID:%d\n",getpid());
	}
	else
	{
		printf("Parent process:\n");
		printf("Child PID:%d\n",pid);
		printf("Parent PID:%d\n",getppid());
	}
	return 1;
}
```
15. Write a C program to create multiple child processes using fork() and display their PIDs.
```
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int i,n=3;
	pid_t pid;

	for(i=0;i<n;i++)
	{
		pid=fork();
		if(pid<0)
		{
			printf("fork failed");
			exit(0);
		}
		else if(pid==0)
		{
			printf("Child %d:PID=%d,Parent:PID %d\n",i+1,getpid(),getppid());
			exit(0);
		}
	}
		sleep(1);
		printf("Parent process(PID=%d) created %d child processes \n",getpid,n);
		return 0;
}
```
19. Write a program in C to create a zombie process and explain how to avoid it.
```
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid;

	pid=fork();

	if(pid<0)
	{
		printf("Fork failed");
		exit(0);
	}
	else if(pid==0)
	{
		printf("Child Process PID:%d\n",getpid());
		printf("Child Processing...\n");
		exit(0);
	}
	else
	{
		printf("Parent Process PID:%d\n",getpid());
		printf("Child PID:%d\n",pid);
		sleep(20);
		printf("Parent Exiting...\n");
	}
	return 0;
}
```
25. Write a program in C to create a daemon process.
```
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid;

	pid=fork();

	if(pid<0)
	{
		printf("Fork failed");
		exit(1);
	}
	else if(pid==0)
	{
		printf("child process created ");
	}
	else
	{
		printf("Parent process:");
		exit(1);
	}
	setsid();
	chdir("/");
	umask();
	close(0);
	close(1);
	close(2);
	while(1)
	{
		sleep(10);
	}
	return 0;
}
```
28. Write a C program to demonstrate the use of the system() function for executing shell commands.
```
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("List File working in current directory\n");
	system("ls -l");

	printf("Display the date and time\n");
	system("date");

	printf("Create a Empty yadav.txt \n");
	system("touch yadav.txt");

	printf("yadav.txt os existing or not\n");
	system("ls -l yadav.txt");

	return 0;
}
```
32. Write a C program to create a process using fork() and pass arguments to the child process. 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        printf("Child: I am the child process. PID = %d\n", getpid());

        char *args[] = {"ls", "-l", "/", NULL};

        execvp(args[0], args);

        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Parent: I am the parent process. PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
```
35. Write a program in C to demonstrate process synchronization using semaphores.
```
// client //
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include<sys/types.h>

#define SHM_KEY 25223
#define SEM_KEY 46532

void main()
{
        int shmid,semid;
        char *shmptr;
        struct sembuf smop;

        shmid=shmget(SHM_KEY,512,0);
        semid=semget(SEM_KEY,2,0);
        shmptr=shmat(shmid,NULL,0);
  //      semctl(semid,0,SETVAL,0);
  //     semctl(semid,1,SETVAL,0);
        smop.sem_num=0;
        smop.sem_op=1;
        smop.sem_flg=0;
        printf("Enter the message for server:");
        scanf("%s",shmptr);
        semop(semid,&smop,1);
}
//server//
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include<sys/types.h>

#define SHM_KEY 25223
#define SEM_KEY 46532

void main()
{
        int shmid,semid;
        char *shmptr=NULL;
        struct sembuf smop;

        shmid=shmget(SHM_KEY,512,IPC_CREAT|0666);
        semid=semget(SEM_KEY,2,IPC_CREAT|0666);
        shmptr=shmat(shmid,NULL,0);
        semctl(semid,0,SETVAL,0);
        semctl(semid,1,SETVAL,0);
        smop.sem_num=0;
        smop.sem_op=-1;
        smop.sem_flg=0;
        printf("Waiting for message from client\n");
        semop(semid,&smop,1);
        printf("Received %s\n",shmptr);
}
```
39. Write a C program to demonstrate the use of the execvpe() function.
```
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    char *args[] = {"printenv", "MY_CUSTOM_VAR", NULL};
    char *envp[] = {"MY_CUSTOM_VAR=HelloExecvpe", NULL};

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("Child: Running execvpe to print MY_CUSTOM_VAR\n");
        execvpe("printenv", args, envp);
        perror("execvpe failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
        printf("Parent: Child finished executing.\n");
    }

    return 0;
}
```
42. Write a C program to create a process group and change its process group ID (PGID).
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        printf("Child: PID = %d, PGID before = %d\n", getpid(), getpgrp());

        if (setpgid(0, 0) == 0)
        {
            printf("Child: PGID successfully changed.\n");
        }
        else
        {
            perror("Child: Failed to change PGID");
        }

        printf("Child: New PGID = %d\n", getpgrp());
        sleep(2);
        exit(0);
    }
    else
    {
        printf("Parent: PID = %d, PGID = %d\n", getpid(), getpgrp());

        wait(NULL);
        printf("Parent: Child has exited.\n");
    }

    return 0;
}
```
45. Write a program in C to demonstrate inter-process communication (IPC) using shared 
memory.
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_SIZE 1024
#define SHM_KEY 1234

int main()
{
    int shmid;
    char *shmptr;

    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        sleep(1);

        shmptr = (char *)shmat(shmid, NULL, 0);
        if (shmptr == (char *)(-1))
        {
            perror("shmat failed (child)");
            exit(1);
        }

        printf("Child: Reading from shared memory: \"%s\"\n", shmptr);

        shmdt(shmptr);
        exit(0);
    }
    else
    {
        shmptr = (char *)shmat(shmid, NULL, 0);
        if (shmptr == (char *)(-1))
        {
            perror("shmat failed (parent)");
            exit(1);
        }

        const char *message = "Hello from parent using shared memory!";
        strcpy(shmptr, message);
        printf("Parent: Message written to shared memory.\n");

        shmdt(shmptr);

        wait(NULL);

        shmctl(shmid, IPC_RMID, NULL);
        printf("Parent: Shared memory removed.\n");
    }

    return 0;
}
```
49. Write a C program to create a child process using vfork() and demonstrate its usage.
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    printf("Parent process started. PID = %d\n", getpid());

    pid = vfork();

    if (pid < 0)
    {
        perror("vfork failed");
        exit(1);
    }

    if (pid == 0)
    {
        printf("Child process. PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Child: Executing 'ls -l'\n");
        execlp("ls", "ls", "-l", NULL);

         perror("execlp failed");
        _exit(1);
    }
    else
    {
        printf("Parent: Waiting for child to exec or exit...\n");
    }

    printf("Parent process continues. PID = %d\n", getpid());
    return 0;
}
```
52. Write a C program to create a pipeline between two processes using the pipe() system 
call. 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    int pipefd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent via pipe!";
    char read_msg[100];

    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }
    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        close(pipefd[1]);
        read(pipefd[0], read_msg, sizeof(read_msg));
        printf("Child: Received message from pipe: \"%s\"\n", read_msg);
        close(pipefd[0]);
    }
    else
    {
        close(pipefd[0]);
        write(pipefd[1], write_msg, strlen(write_msg) + 1);
        close(pipefd[1]);
    }

    return 0;
}
```
55. Write a program in C to demonstrate the use of the nice() system call for adjusting 
process priority. 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    int curr_nice, new_nice;

    curr_nice = getpriority(PRIO_PROCESS, 0);
    if (curr_nice == -1 && errno != 0)
    {
        perror("getpriority failed");
        return 1;
    }

    printf("Current nice value: %d\n", curr_nice);

    new_nice = nice(5);

    if (new_nice == -1 && errno != 0)
    {
        perror("nice failed");
        return 1;
    }

    printf("New nice value after nice(5): %d\n", new_nice);
    for (int i = 0; i < 5; i++)
    {
        printf("Working... (nice=%d)\n", new_nice);
        sleep(1);
    }

    return 0;
}
```
59. Write a C program to demonstrate the use of the clone() system call to create a thread.
```
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>

#define STACK_SIZE 1024*1024

int thread_func(void *arg)
{
    char *message = (char *)arg;
    printf("Inside thread: %s\n", message);
    strcpy(message, "Modified by thread");
    return 0;
}

int main()
{
    char *stack;
    char *message = malloc(100);
    strcpy(message, "Hello from main");

    stack = malloc(STACK_SIZE);
    if (stack == NULL)
    {
        perror("Failed to allocate stack");
        exit(1);
    }

    pid_t pid = clone(thread_func, stack + STACK_SIZE,
                      CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD,
                      message);

    if (pid == -1)
    {
        perror("clone failed");
        exit(1);
    }

    waitpid(pid, NULL, 0);

    printf("Back in main: message = %s\n", message);

    free(stack);
    free(message);

    return 0;
}
```
62. Write a C program to create a child process using fork() and communicate between 
parent and child using pipes.
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }
    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {

        close(pipefd[1]);

        read(pipefd[0], read_msg, sizeof(read_msg));
        printf("Child: Received message from parent: \"%s\"\n", read_msg);

        close(pipefd[0]);
    }
    else
    {
        close(pipefd[0]);

        write(pipefd[1], write_msg, strlen(write_msg) + 1);
        printf("Parent: Sent message to child.\n");

        close(pipefd[1]);

        wait(NULL);
    }

    return 0;
}
```
66. Write a C program to demonstrate process synchronization using the fork() and wait() 
system calls. 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Main process started. PID = %d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        printf("Child process started. PID = %d\n", getpid());
        printf("Child: Doing some work...\n");
        sleep(3);
        printf("Child: Work done. Exiting...\n");
        exit(0);
    }
    else
    {
        printf("Parent: Waiting for child process to complete...\n");
        wait(NULL);
        printf("Parent: Child has completed. Continuing execution.\n");
    }

    return 0;
}
```
69. Write a C program to create a process using fork() and change its scheduling policy
using sched_setscheduler().
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    struct sched_param schedParam;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        printf("Child PID = %d\n", getpid());

        schedParam.sched_priority = 10;

        if (sched_setscheduler(0, SCHED_RR, &schedParam) == -1)
        {
            perror("sched_setscheduler failed (need root?)");
        }
        else
        {
            printf("Child: Scheduling policy changed to SCHED_RR with priority 10\n");
        }
        int policy = sched_getscheduler(0);
        if (policy == -1)
        {
            perror("sched_getscheduler failed");
        }
        else
        {
            printf("Child: Current scheduling policy = %s\n",
                   policy == SCHED_OTHER ? "SCHED_OTHER" :
                   policy == SCHED_FIFO ? "SCHED_FIFO" :
                   policy == SCHED_RR   ? "SCHED_RR" : "UNKNOWN");
        }
        for (int i = 0; i < 5; i++)
        {
            printf("Child: Running iteration %d...\n", i + 1);
            sleep(1);
        }
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("Parent: Child has finished execution.\n");
    }
    return 0;
}
```
72. Write a C program to create a child process using fork() and demonstrate inter-process 
communication (IPC) using shared memory. 
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SHM_SIZE 1024
#define SHM_KEY 12345

int main()
{
    int shmid;
    char *shmptr;

    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0)
{
        perror("shmget failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0)
{
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
{
        sleep(1); 
        shmptr = (char *)shmat(shmid, NULL, 0);
        if (shmptr == (char *)(-1)) {
            perror("shmat failed (child)");
            exit(1);
        }

        printf("Child: Message from shared memory: \"%s\"\n", shmptr);
        shmdt(shmptr);
        exit(0);
    }
    else
 {
        shmptr = (char *)shmat(shmid, NULL, 0);
        if (shmptr == (char *)(-1))
        {
            perror("shmat failed (parent)");
            exit(1);
        }
        const char *message = "Hello from parent to child via shared memory!";
        strcpy(shmptr, message);
        printf("Parent: Message written to shared memory.\n");
        shmdt(shmptr);

        wait(NULL);
        shmctl(shmid, IPC_RMID, NULL);
        printf("Parent: Shared memory removed.\n");
    }
    return 0;
}
```
76. Write a C program to demonstrate the use of the prctl() system call to change process
attributes.
```
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>
#include <unistd.h>

int main()
{
    char name[17]; 
    
    if (prctl(PR_SET_NAME, "MyCustomProc", 0, 0, 0) == -1)
    {
        perror("prctl(PR_SET_NAME) failed");
        return 1;
    }
    printf("Process name set to 'MyCustomProc'\n");

    if (prctl(PR_GET_NAME, name, 0, 0, 0) == -1)
    {
        perror("prctl(PR_GET_NAME) failed");
        return 1;
    }
    printf("Process name retrieved using prctl: %s\n", name);

    printf("Process is running (PID = %d)...\n", getpid());
    sleep(5);

    return 0;
}
```
80. Write a C program to create a child process using fork() and demonstrate process 
synchronization using semaphores. 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

union semun
{
    int val;
};
void sem_wait(int semid)
{
    struct sembuf sops = {0, -1, 0};
    semop(semid, &sops, 1);
}
void sem_signal(int semid)
{
    struct sembuf sops = {0, 1, 0};
    semop(semid, &sops, 1);
}
int main()
{
    key_t key = ftok("semfile", 65); 
    int semid;

    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1)
    {
        perror("semget failed");
        exit(1);
    }
    union semun sem_union;
    sem_union.val = 1;
    if (semctl(semid, 0, SETVAL, sem_union) == -1)
    {
        perror("semctl SETVAL failed");
        exit(1);
    }
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    if (pid == 0)
    {
        sem_wait(semid);
        printf("Child: Entering critical section...\n");
        sleep(2); 
        printf("Child: Exiting critical section.\n");
        sem_signal(semid);
        exit(0);
    }
    else
    {
        sem_wait(semid);
        printf("Parent: Entering critical section...\n");
        sleep(2);
        printf("Parent: Exiting critical section.\n");
        sem_signal(semid);

        wait(NULL); // Wait for child to finish

        semctl(semid, 0, IPC_RMID);
        printf("Parent: Semaphore removed.\n");
    }

    return 0;
}
```
82.Write a C program to create a child process using fork() and demonstrate process 
communication using message queues. 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/wait.h>

struct msg_buffer
 {
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    pid_t pid;

    key = ftok("msgqueuefile", 65);
    if (key == -1)
    {
        perror("ftok failed");
        exit(1);
    }
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("msgget failed");
        exit(1);
    }
    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    if (pid == 0)
    {
        struct msg_buffer message;

        if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1)
        {
            perror("msgrcv failed");
            exit(1);
        }
        printf("Child: Received message from parent: \"%s\"\n", message.msg_text);
        exit(0);
    }
    else
    {
        struct msg_buffer message;
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from parent using message queue!");

        if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1)
        {
            perror("msgsnd failed");
            exit(1);
        }

        printf("Parent: Message sent to child.\n");

        wait(NULL);  

        msgctl(msgid, IPC_RMID, NULL);
        printf("Parent: Message queue removed.\n");
    }
    return 0;
}
```
86.Write a C program to create a child process using fork() and demonstrate process 
synchronization using condition variables.
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/wait.h>

typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int ready;
}shared_data_t;

int main()
{
    shared_data_t *shared = mmap(NULL, sizeof(shared_data_t), PROT_READ | PROT_WRITE,
                                 MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (shared == MAP_FAILED)
    {
        perror("mmap failed");
        exit(1);
    }
    pthread_mutexattr_t mutex_attr;
    pthread_condattr_t cond_attr;

    pthread_mutexattr_init(&mutex_attr);
    pthread_condattr_init(&cond_attr);

    pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);
    pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(&shared->mutex, &mutex_attr);
    pthread_cond_init(&shared->cond, &cond_attr);
    shared->ready = 0;

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        sleep(2);

        pthread_mutex_lock(&shared->mutex);
        shared->ready = 1;
        printf("Child: Signaling parent via condition variable.\n");
        pthread_cond_signal(&shared->cond);
        pthread_mutex_unlock(&shared->mutex);

        exit(0);
    }
    else
    {
        pthread_mutex_lock(&shared->mutex);
        while (shared->ready == 0)
        {
            printf("Parent: Waiting for child to signal...\n");
            pthread_cond_wait(&shared->cond, &shared->mutex);
        }
        printf("Parent: Received signal from child. Continuing...\n");
        pthread_mutex_unlock(&shared->mutex);

        wait(NULL); 

        pthread_mutex_destroy(&shared->mutex);
        pthread_cond_destroy(&shared->cond);
        munmap(shared, sizeof(shared_data_t));
    }
    return 0;
}
```
90. Write a C program to create a child process using fork() and demonstrate process 
communication using sockets. 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int sv[2]; 
    pid_t pid;

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1)
    {
        perror("socketpair failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        close(sv[0]);
        char buffer[100];
        read(sv[1], buffer, sizeof(buffer));
        printf("Child: Received from parent: \"%s\"\n", buffer);

        const char *child_msg = "Hello from child!";
        write(sv[1], child_msg, strlen(child_msg) + 1); 

        close(sv[1]);
        exit(0);
    }
    else
    {
        close(sv[1]);

        const char *parent_msg = "Hello from parent!";
        write(sv[0], parent_msg, strlen(parent_msg) + 1); 

        char buffer[100];
        read(sv[0], buffer, sizeof(buffer));
        printf("Parent: Received from child: \"%s\"\n", buffer);

        close(sv[0]);
        wait(NULL);  // Wait for child
    }
    return 0;
}
```
92. Write a C program to create a child process using fork() and demonstrate process 
synchronization using mutexes. 
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/wait.h>

typedef struct
{
    pthread_mutex_t mutex;
} shared_data_t;

int main()
{
    shared_data_t *shared = mmap(NULL, sizeof(shared_data_t), PROT_READ | PROT_WRITE,
                                 MAP_SHARED | MAP_ANONYMOUS,-1, 0);
    if (shared == MAP_FAILED)
    {
        perror("mmap failed");
        exit(1);
    }
    pthread_mutexattr_t mutex_attr;
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);

    pthread_mutex_init(&shared->mutex, &mutex_attr);

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        sleep(1);  
        pthread_mutex_lock(&shared->mutex);
        printf("Child: Entered critical section.\n");
        sleep(2);
        printf("Child: Exiting critical section.\n");
        pthread_mutex_unlock(&shared->mutex);

        exit(0);
    }
    else
    {
        pthread_mutex_lock(&shared->mutex);
        printf("Parent: Entered critical section.\n");
        sleep(2);
        printf("Parent: Exiting critical section.\n");
        pthread_mutex_unlock(&shared->mutex);

        wait(NULL);
        pthread_mutex_destroy(&shared->mutex);
        pthread_mutexattr_destroy(&mutex_attr);
        munmap(shared, sizeof(shared_data_t));
    }
    return 0;
}
```
96. Write a C program to create a child process using fork() and demonstrate process 
communication using named pipes (FIFOs).
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

#define FIFO_NAME "myfifo"

int main()
{
    if (mkfifo(FIFO_NAME, 0666) == -1)
    {
        perror("mkfifo");
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        char buffer[100];
        int fd = open(FIFO_NAME, O_RDONLY);
        if (fd == -1)
        {
            perror("Child: open failed");
            exit(1);
        }

        read(fd, buffer, sizeof(buffer));
        printf("Child: Received message from parent: \"%s\"\n", buffer);
        close(fd);
        exit(0);
    }
    else
    {
        int fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1)
        {
            perror("Parent: open failed");
            exit(1);
        }

        const char *message = "Hello from parent via FIFO!";
        write(fd, message, strlen(message) + 1);  
        close(fd);
        wait(NULL); 
        unlink(FIFO_NAME);
        printf("Parent: FIFO removed.\n");
    }
    return 0;
}
```
100.Write a C program to create a child process using fork() and demonstrate 
process communication using shared memory and semaphores
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define SHM_KEY 1234
#define SEM_KEY 5678
#define SHM_SIZE 1024

union semun
{
    int val;
};

void sem_wait(int semid)
{
    struct sembuf sb = {0, -1, 0}; 
    semop(semid, &sb, 1);
}

void sem_signal(int semid)
{
    struct sembuf sb = {0, 1, 0};  
    semop(semid, &sb, 1);
}

int main()
{
    int shmid, semid;
    char *shmptr;
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget failed");
        exit(1);
    }
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1)
    {
        perror("semget failed");
        exit(1);
    }
    union semun sem_union;
    sem_union.val = 0;
    if (semctl(semid, 0, SETVAL, sem_union) == -1)
    {
        perror("semctl SETVAL failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        sleep(1); 
        shmptr = (char *)shmat(shmid, NULL, 0);
        if (shmptr == (char *)-1)
        {
            perror("shmat failed (child)");
            exit(1);
        }

        sem_wait(semid);

        printf("Child: Read from shared memory: \"%s\"\n", shmptr);

        shmdt(shmptr); 
        exit(0);
    }
    else
    {
        shmptr = (char *)shmat(shmid, NULL, 0);
        if (shmptr == (char *)-1)
        {
            perror("shmat failed (parent)");
            exit(1);
        }

        const char *message = "Hello from parent via shared memory!";
        strcpy(shmptr, message);
        printf("Parent: Written message to shared memory.\n");

        sem_signal(semid);  

        wait(NULL); 

        shmdt(shmptr);
        shmctl(shmid, IPC_RMID, NULL); 
        semctl(semid, 0, IPC_RMID);   

        printf("Parent: Cleaned up shared memory and semaphore.\n");
    }
    return 0;
}
```




























