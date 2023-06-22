#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int res;

int *createFileDescriptor()
{
    int *fd = (int *)malloc(2 * sizeof(int));
    return fd; // returns the address of the first location of the 8 bytes of memory reserved for fd
}
/*
    create a pipe file
    accept a pointer to a file descriptor array & create the pipe
    check for any potential error
*/
int *createPipe(int *fd)
{
    if (pipe(fd) == -1)
    {
        printf("Pipe not created\n");
    }
    return fd; // returns the file descriptor which are now linked to pipe.
}

void createProcess()
{
    if ((res = fork()) == -1)
    {
        printf("error in creation for sys call\n");
    }
}

void writingToBuffer(int *fd)
{
    if (res == 0)
    {
        close(fd[0]);
        int arr[5] = {1, 2, 3, 4, 5};
        if (write(fd[1], arr, 20) == -1)
        {
            printf("Something went wrong in write...\n");
        }
        else
        {
            printf("Write successfull\n");
        }
        close(fd[1]);
    }
}

void readFromBuffer(int *fd)
{
    if (res != 0)
    {
        close(fd[1]);
        int data[5];
        if (read(fd[0], data, 20) == -1)
        {
            printf("Failure in read\n");
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                printf("Array elements is: %d\n", data[i]);
            }
        }
        close(fd[0]);
    }
}

int main()
{
    int *fd = createFileDescriptor();
    fd = createPipe(fd); // you pass unlinked descriptor into the function
    createProcess();
    writingToBuffer(fd);
    readFromBuffer(fd);
}
