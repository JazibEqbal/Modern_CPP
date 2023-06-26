#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/*
    I need to launch a process: ls -l /top/testing from my C program
*/

/*
    echo $PATH -- location compiler will search for
    echo $HOME -- stores home directory of current user

    1) execl: path is not searched, so specify full location yourself
    2) execlp: path is available, all path locations will be searched, so no need to specify fill location
    3) execvp: path is available so we can pass a const char array of arguments
                const char* commands = {"path", NULL};
                execvp("cat", commands);

    4) execve: all env variables are available,array of arguments work

    l: list of arguments
    p: path env variable is available
    v: vector(array) of arguments  can be passed
    e: all env var are available for access
*/

int main(){
    int res;
    if((res = fork()) == -1){
        exit(1); // bcz fork failed
    }
    if(res == 0){
        execlp("ls","-l","/home/kpit/Desktop/demo",NULL);
        //execlp("systemctl","status", "NetworkManager",NULL);
        //execlp("ls","-l","/tmp",NULL);
    }
    //printf("Haha\n"); //parent will still execute this
}

/*
    exec mandatory: 
        1) do u want 2 specify full path of the program OR only a program name
            - program that u want 2 run is part of environment path or not?
            - would like to use env variables at system level
        2) do u want 2 write entire path ans its arguments in one line
          OR
          use an array of command names & arguments instead?
*/

/*
    ./program - shell is parent and a new child process is created: ./program
*/