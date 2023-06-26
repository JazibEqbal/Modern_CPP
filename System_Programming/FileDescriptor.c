/*
    a child process that executes ls -l
    all output should be redirected to a file called /tmp/output.txt

*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    int res;
    if((res = fork()) == -1){
        exit(1);
    }

    if(res == 0){
        char* command ="ls";
        char* const arr[] = {"ls","-l","/",NULL};
        execvp(command,arr);
    }
    printf("hehe\n");
}