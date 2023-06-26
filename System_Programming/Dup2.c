// CPP program to illustrate dup()
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>

int main()
{
	int outFd = open("OpenMe.txt", O_WRONLY | O_CREAT,0777);  //returns a fd to the file OpenMe.txt
    int errFd = open("err.txt",O_RDONLY | O_CREAT,0777);

    // int outFd = open("/home/kpit/Desktop/OpenMe.txt", O_WRONLY | O_CREAT,0777);
    // int errFd = open("/home/kpit/Desktop/err.txt",O_RDONLY | O_CREAT,0777);

    int res;
    if((res = fork()) == -1){
        exit(1);
    }

    if(res == 0){
        dup2(outFd,1); //channel 1 of child is now redirected to outFd.txt
        dup2(errFd,2);
        char* command ="ls";
        char* const arr[] = {"ls","-l","/",NULL};
        execvp(command,arr);   //child process gets replaced by exec command //child terminates
    }
        close(outFd);
        close(errFd);
    printf("hehe\n");
}
