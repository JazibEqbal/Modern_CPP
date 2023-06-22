#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/*
    print- 1 2 3 4 5 from child
    print- 6 7 8 9 10 from parent

    parent should not print anything unless child process has sent a signal
    indicating that it is now done (parent has to wait to wait for child to terminate)
*/

void printChild()
{
    printf("1 2 3 4 5\n");
}

void printParent()
{
    printf("6 7 8 9 10\n");
}

int main()
{
    int res;
    int status;
    // fork the parent (check for success)
    if ((res = fork()) == -1)
    { // creation of child and parent
        printf("error\n");
    }
    // if we are in parent, wait for child and then call printParent
    if (res != 0)
    { // checks wheather child has 0 or not
        int childId = wait(&status);
        printParent();
        printf("returned id from wait is %d\n", childId);
        if (status == 0)
        {
            printf("child terminated succesfully\n");
        }
        else
        {
            printf("Something went wrong");
        }
    }
    if (res == 0)
    { // child id goes in parent id
        printChild();
        printf("Child Id is %d\n", getpid());
    }
    // if we are in child, call printChild
}