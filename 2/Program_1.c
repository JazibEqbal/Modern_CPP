#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
#include<pthread.h>

void showHostname() {
    int pid = fork();

    if (pid == -1) {
        printf("Failed to fork a new process.\n");
        exit(1);
    }
    if (pid == 0) {
        execlp("hostname", "hostname", NULL);
    } 
}

void showDateAndTime() {
    int res = fork();

    if (res == -1) {
        printf("Failed to fork a new process.\n");
        exit(1);
    } 
    if (res == 0) {
        execlp("date", "date", NULL);
    }
}


void showNames(){
        int res = fork();

    if (res == -1) {
        printf("Failed to fork a new process.\n");
        exit(1);
    } 
    if (res == 0) {
        execlp("ls","-l","/home/kpit/Desktop",NULL);

    }
}
