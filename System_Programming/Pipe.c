#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2]; // file descriptor array --keys
    // creating pipe
    if (pipe(fd) == -1)
    {
        printf("Pipe not created\n");
    }
    int res;
    if ((res = fork()) == -1)
    {
        printf("EXIT\n");
        return EXIT_FAILURE;
    }
    /*
    if we are in parent we create a variable and store number 5 in it.
    Before write, since noread operationhappens in parent, we close the read channel
    we open the write channel of PIPE and write the data into it after write, I must close the write channel.
    */
    if (res == 0)
    {
        close(fd[0]); // closing read channel
        int number = 5;
        // if write is successfull return value should be equal to number of bytes written
        if (write(fd[1], &number, sizeof(int)) == -1)
        { // (output, pointer to buffer,size of data)
            printf("Something went wrong in write...\n");
        }
        else
        {
            printf("Write successfull\n");
            // return EXIT_SUCCESS;
        }
        close(fd[1]); // write channel can be closed now
    }

    /*
        child starts by closing the write channel (since it does not want to write anything into the pipe)
        it then reads from the pipe whatever data is present inside it.
        if read is successfull , we multiply the number by itself to print the square
        we then close the read channel
    */

    if (res != 0)
    {
        close(fd[1]); // closing the write channel
        int data;
        // wait(NULL);
        if (read(fd[0], &data, sizeof(int)) == -1)
        {
            printf("Failure in read\n");
        }
        else
        {
            printf("Square of %d is %d\n", data, data * data);
            // return EXIT_SUCCESS;
        }
        close(fd[0]);
    }
}
//read can not happen before write  --child is writing parent is reading