#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>          //standard unix functions

int main(){
    int n1;
    int returnedId = fork();  //fork creates a child process.
    if(returnedId == -1){
        printf("Sys call failed\n");
    } else if(returnedId == 0){
        sleep(10);
        printf("In child process\n");
        printf("CHILD ID is: %d and my parent id is %d\n",getpid(), getppid());
    }else{
         sleep(10);
        printf("In parent process\n");
        printf("PARENT ID is: %d and my parent id is %d\n",getpid(), getppid());
    }
}