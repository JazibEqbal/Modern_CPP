#include "functionalities.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
/*
    mkfifo can be used to create a named pipe
    pipe file permisiions can also be set
    we also need to check if creation failed(two possible reasons)
        -- file with same name in same location exists(conflict in names)
        -- OS sys call failure
*/
void CreateNamedPipe(const char *pipeName){
    if(mkfifo(pipeName,0777) == -1){
        if(errno == EEXIST){
            printf("Same name with file already exists\n");
        }
    }
}

int* createNewProcess(){
    int *val = (int*) malloc(1 * sizeof(int)); //returns a pointer to the block of 4 bytes created on heap
    if(((*val) = fork()) == -1){
        printf("Fork not created\n");
        _exit(1);
    }
    return val;
}

void WriteToPipe(const char *pipeName,int *res){
    if((*res) == 0){
    int fd;
    if(fd = open(pipeName,O_WRONLY) == -1){//open for write only
        printf("Open failed\n");
        _exit(1);
    }; 
    int number = 65;
        if(write(fd,&number,sizeof(int)) == -1){
            printf("Error while writing");
            _exit(1);
    }
    close(fd);
    }
}

void readFromPipe(const char *pipeName,int *res){
    if((*res) != 0){
    int fd;
    if(fd = open(pipeName,O_RDONLY) == -1){//open for write only
            printf("Open failed\n");
            _exit(1);
    }; 
    int number;
        if(read(fd,&number,sizeof(int)) == -1){
            printf("Error while reading");
            _exit(1);
    }
    //printf("%d\n",number);
    close(fd);
    }
}