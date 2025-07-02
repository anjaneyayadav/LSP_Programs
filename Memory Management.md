86. Write a C program to demonstrate dynamic memory allocation using malloc().
```
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr;
	int n=5;

	ptr=(int*)malloc(n* sizeof(int));

	if(ptr==NULL)
	{
		printf("memory allocation failed");
		return 1;
	}
	for(int i=0;i<n;i++)
	{
		ptr[i]=i+1;
		printf("ptr[%d]=%d\n",i,ptr[i]);
	}
	free(ptr);
	return 0;
}
```
87. Implement a C program to allocate memory for an array dynamically using calloc().
```
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr;
	int n=5;

	ptr=(int*)calloc(n,sizeof(int));

	if(ptr==NULL)
	{
		printf("memory allocation failed\n");
		return 1;
	}
	for(int i=0;i<n;i++)
	{
		printf("ptr[%d]=%d\n",i,ptr[i]);
	}
	free(ptr);
	return 0;
}
```
88. Write a C program to resize dynamically allocated memory using realloc().
```
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr;
	int n=3;

	ptr=(int*)malloc(n* sizeof(int));
	if(ptr==NULL)
	{
		printf("allocation failed\n");
		return 1;
	}
	for(int i=0;i<n;i++)
	{
		ptr[i]=i+1;
	}
	n=6;
	ptr=(int*)realloc(ptr,n* sizeof(int));

	if(ptr==NULL)
	{
		printf("reallocation failed\n");
		return 1;
	}
	for(int i=0;i<n;i++)
	{
		ptr[i]=i+1;
	}
	printf("resized array:\n");
	for(int i=0;i<n;i++)
	{
		printf("ptr[%d]=%d\n",i,ptr[i]);
	}
	free(ptr);
	return 0;
}
```
89. Develop a program in C to allocate memory for a linked list node dynamically.
```
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
};
int main()
{
	struct node*head=malloc(sizeof(struct node));

	if(head==NULL)
	{
		printf("memory allocation failed\n");
		return 1;
	}
	head->data=100;
	head->next=NULL;

	printf("Node created with data =%d\n",head->data);

	free(head);
	return 0;
}
```
90. Implement a C program to simulate memory allocation using the first-fit algorithm.
```
#include<stdio.h>

int main()
{
	int blocksize[]={100,500,200,300,600};
	int processsize[]={212,417,112,426};
	int blockcount=sizeof(blocksize)/sizeof(blocksize[0]);
	int processcount=sizeof(processsize)/sizeof(processsize[0]);
	int allocation[processcount];

	for(int i=0;i<processcount;i++)
	{
		allocation[i]=-1;
	}
	for(int i=0;i<processcount;i++)
	{
		for(int j=0;j<blockcount;j++)
		{
			if(blocksize[j]>=processsize[i])
			{
				allocation[i]=j;
				blocksize[j]-=processsize[i];
				break;
			}
		}
	}
	printf("process no.\tsize\tblock.no\n");
	for(int i=0;i<processcount;i++)
	{
		printf("%d\t\t%d\t",i+1,processsize[i]);
		if(allocation[i]!=-1)
		{
			printf("%d\n",allocation[i]+1);
		}
		else
		{
			printf("Not allocation\n");
		}
	}
	return 0;
}
```
91. Write a C program to simulate memory allocation using the best-fit algorithm.
```
#include<stdio.h>

#define MAX 10

int main()
{
        int blocksize[MAX]={100,500,200,300,600};
        int processsize[MAX]={212,417,112,426};
        int allocation[MAX]={-1,-1,-1,-1};// -1 means not allocated to anyone
        int bestindex;
        int i,j;

        for(i=0;i<4;i++)
        {
                bestindex=-1;
                for(j=0;j<5;j++)
                {
                        if(blocksize[j]>=processsize[i])
                        {
                                if(bestindex==-1 || blocksize[j]<blocksize[bestindex])
                                {
                                        bestindex=j;
                                }
                        }
                }
                if(bestindex!=-1)
                {
                        allocation[i]=bestindex;
                        blocksize[bestindex]-=processsize[i];
                }
        }
        for(i=0;i<4;i++)
        {
                printf("Process %d -> ",i+1);

                if(allocation[i]!=-1)
                {
                        printf("Block %d\n",allocation[i]+1);
                }
                else
                {
                        printf("Not Allocated\n");
                }
        }
        return 0;
}
```
92. Develop a C program to simulate memory allocation using the worst-fit algorithm.
```
#include <stdio.h>
#define MAX 10
int main()
{
    int blocksize[MAX] = {100,500,200,300,600};
    int processsize[MAX] = {212, 417, 112, 426};
    int allocation[MAX];
    int worstindex;
    int i,j;

    for(i=0;i<4;i++)
    {
            allocation[i]=-1;
    }
    for(i=0;i<4;i++)
    {
            worstindex=-1;
            for(j=0;j<5;j++)
            {
                    if(blocksize[j]>=processsize[i])
                    {
                            if(worstindex==-1 || blocksize[j]>blocksize[worstindex])
                            {
                                    worstindex=j;
                            }
                    }
            }
            if(worstindex!=-1)
            {
                    allocation[i]=worstindex;
                    blocksize[worstindex]-=processsize[i];
            }
    }
    for(i=0;i<4;i++)
    {
            printf("Process %d ->",i+1);
            if(allocation[i]!=-1)
            {
                    printf("Block %d\n",allocation[i]+1);
            }
            else
            {
                    printf("Not Allocated\n");
            }
    }
    return 0;
}
```
93. Implement a C program to simulate memory allocation using the next-fit algorithm.
```
#include <stdio.h>
#define MAX 10

int main()
{
    int blocksize[MAX] = {100, 500, 200, 300, 600};
    int processsize[MAX] = {212, 417, 112, 426};
    int allocation[MAX];
    int  i, j;
    int  lastPos = 0,count=0;


    for (i = 0; i < 4; i++)
    {
            allocation[i] = -1;
    }
    for (i = 0; i < 4; i++)
    {
        j = lastPos;
        while (count < 5)
        {
            if (blocksize[j] >= processsize[i])
            {
                allocation[i] = j;
                blocksize[j] -= processsize[i];
                lastPos = j;
                break;
            }
            j = (j + 1) % 5;
            count++;
        }
    }
    for (i = 0; i < 4; i++)
    {
            printf("Process %d  " ,i+1);
            if(allocation[i]!=-1)
            {
                    printf("block size of %d\n",allocation[i]+1);
            }
            else
            {
                    printf("not allocated\n");
            }
    }
    return 0;
}
```
94. Write a C program to implement a simple memory allocator using the buddy system.
```
#include <stdio.h>
#include <math.h>

#define MAX 1024  

int memory[MAX];
int is_allocated[MAX];  

int nextPowerOf2(int n) 
{
    int power = 1;
    while (power < n) power <<= 1;
    return power;
}

void buddy_alloc(int size) 
{
    int req_size = nextPowerOf2(size);
    if (req_size > MAX) 
    {
        printf("Not enough memory\n");
        return;
    }

    for (int i = 0; i < MAX; i += req_size) 
    {
        int free = 1;
        for (int j = i; j < i + req_size; j++) 
	{
            if (is_allocated[j]) 
	    {
                free = 0;
                break;
            }
        }

        if (free) 
	      {
            for (int j = i; j < i + req_size; j++)
                is_allocated[j] = 1;

            printf("Allocated %d bytes at index %d\n", req_size, i);
            return;
        }
    }

    printf("Failed to allocate\n");
}

void buddy_free(int index, int size) 
{
    int block_size = nextPowerOf2(size);
    for (int i = index; i < index + block_size && i < MAX; i++)
    {
        is_allocated[i] = 0;
    }
    printf("Freed %d bytes from index %d\n", block_size, index);
}

int main() 
{
    buddy_alloc(200);
    buddy_alloc(100);
    buddy_free(0, 200);
    buddy_alloc(50);
    return 0;
}
```
95. Develop a C program to implement a memory allocator using a custom memory 
management algorithm. 
```
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024

char memory[MEMORY_SIZE];
int free_list[MEMORY_SIZE];

void init_allocator()
{
    for (int i = 0; i < MEMORY_SIZE; i++) 
    {
        free_list[i] = 0;
    }
}

void* my_malloc(int size) 
{
    for (int i = 0; i <= MEMORY_SIZE - size; i++) 
    {
        int j;
        for (j = 0; j < size; j++)
       	{
            if (free_list[i + j])
                break;
        }

        if (j == size)
       	{
            for (j = 0; j < size; j++) 
	    {
                free_list[i + j] = 1;
            }
            return &memory[i];
        }
    }
    return NULL;
}

void my_free(void *ptr, int size) 
{
    int offset = (char *)ptr - memory;
    for (int i = offset; i < offset + size; i++) 
    {
        free_list[i] = 0;
    }
}

int main() 
{
    init_allocator();
    void *p1 = my_malloc(100);
    void *p2 = my_malloc(200);

    if (p1) printf("Allocated 100 bytes\n");
    if (p2) printf("Allocated 200 bytes\n");

    my_free(p1, 100);
    printf("Freed 100 bytes\n");

    return 0;
}
```
96. Write a C program to demonstrate memory mapping using mmap().
```
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    const char *filename = "mmap_example.txt";
    const char *message = "Hello from mmap!\n";
    int fd;
    char *map;
    size_t length = 4096;

    fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    if (ftruncate(fd, length) == -1)
    {
        perror("ftruncate");
        close(fd);
        return 1;
    }
    map = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }
    strcpy(map, message);
    printf("Written to file using mmap: %s", map);

    munmap(map, length);
    close(fd);

    return 0;
}
```
97. Implement a C program to read from and write to a memory-mapped file.
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>      
#include <unistd.h>     
#include <sys/mman.h>   
#include <sys/stat.h>   

#define FILE_PATH "mapped_file.txt"
#define FILE_SIZE 1024 

int main() 
{
    int fd;
    char *map;

    fd = open(FILE_PATH, O_RDWR | O_CREAT, 0666);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    if (ftruncate(fd, FILE_SIZE) == -1)
    {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    map = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) 
    {
        perror("mmap");
        close(fd);
        return 1;
    }
    const char *message = "Hello from mmap!";
    memcpy(map, message, strlen(message));

    printf("Reading from memory-mapped file: %s\n", map);

    munmap(map, FILE_SIZE);
    close(fd);

    return 0;

}
```
98. Develop a C program to demonstrate shared memory usage using shmget() and shmat().
```
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHM_KEY 25223

void main()
{
        int shmid;
        char *shmptr=NULL;
        shmid=shmget(SHM_KEY,512,IPC_CREAT|0666);
        shmptr=shmat(shmid,NULL,0);
        printf("Waiting for message from client\n");
        printf("Received:%s\n",shmptr);

}
```
99. Write a C program to create a shared memory segment and synchronize access using
semaphores.
```
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
        printf("Waiting for message from client\n");
        semop(semid,&smop,1);
        printf("Received %s\n",shmptr);
}
```
100. Implement a C program to simulate page replacement algorithms like FIFO, LRU, and
optimal.
```
#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int isHit(int frames[], int n, int page) 
{
    for (int i = 0; i < n; i++)
        if (frames[i] == page) return 1;
    return 0;
}

int fifo(int pages[], int n, int frames[], int f) 
{
    int faults = 0, index = 0;

    for (int i = 0; i < n; i++) 
    {
        if (!isHit(frames, f, pages[i])) 
	{
            frames[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }
    }
    return faults;
}

int lru(int pages[], int n, int frames[], int f)
{
    int faults = 0, time[MAX_FRAMES] = {0}, t = 0;

    for (int i = 0; i < f; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) 
    {
        int found = 0;
        for (int j = 0; j < f; j++) 
	{
            if (frames[j] == pages[i]) 
	    {
                time[j] = ++t;
                found = 1;
                break;
            }
        }

        if (!found)
       	{
            int min_time = INT_MAX, min_index = -1;
            for (int j = 0; j < f; j++)
	    {
                if (time[j] < min_time)
	       	{
                    min_time = time[j];
                    min_index = j;
                }
            }
            frames[min_index] = pages[i];
            time[min_index] = ++t;
            faults++;
        }
    }

    return faults;
}

int optimal(int pages[], int n, int frames[], int f)
{
    int faults = 0;

    for (int i = 0; i < f; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) 
    {
        if (!isHit(frames, f, pages[i])) 
	{
            int index = -1, farthest = i;
            for (int j = 0; j < f; j++) 
	    {
                int k;
                for (k = i + 1; k < n; k++) 
		{
                    if (frames[j] == pages[k]) break;
                }
                if (k > farthest) 
		{
                    farthest = k;
                    index = j;
                }
            }
            if (index == -1) index = 0;
            frames[index] = pages[i];
            faults++;
        }
    }

    return faults;
}

int main() 
{
    int pages[MAX_PAGES], n, frames[MAX_FRAMES], f;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("\nPage Faults:\n");

    for (int i = 0; i < f; i++) frames[i] = -1;
    printf("FIFO:    %d\n", fifo(pages, n, frames, f));

    for (int i = 0; i < f; i++) frames[i] = -1;
    printf("LRU:     %d\n", lru(pages, n, frames, f));

    for (int i = 0; i < f; i++) frames[i] = -1;
    printf("Optimal: %d\n", optimal(pages, n, frames, f));

    return 0;
}
```
