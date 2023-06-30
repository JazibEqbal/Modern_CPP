#include "functionalities.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>

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
void square(int *result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = i*i;
    }
}

void WriteToPipe(const char *pipeName,int *res){
    if((*res) == 0){
    int fd;
    if(fd = open(pipeName,O_WRONLY) == -1){//open for write only
        printf("Open failed\n");
        _exit(1);
    }; 
    int arr[5] = {1,2,3,4,5};
        if(write(fd,&arr,sizeof(arr)) == -1){
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
    int res[5];
        if(read(fd,&res,sizeof(res)) == -1){
            printf("Error while reading");
            _exit(1);
    }
    close(fd);
    }
}