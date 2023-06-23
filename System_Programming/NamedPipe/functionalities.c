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

void WriteToPipe(const char *pipeName){
    int fd;
    if(fd = open(pipeName,O_WRONLY) == -1){//open for write only
        printf("Open failed\n");
        _exit(1);
    }; 
    int number = 65;
    if(write(fd,&number,sizeof(int)) == -1){
        printf("Error while writing");
        _exit(1);
    }else{
        printf("\nWritten successfully\n");
    }
    close(fd);
}
