#include "functionalities.h"
#include "Data.h"
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>

int *createFileDescriptors()
{
    int* fd = (int*) malloc(2 * sizeof(int));
    return fd;
}

int *createPipe(int* fd)
{
    if(pipe(fd) == -1){
        printf("Pipe not created\n");
    }
    return fd;
}
int res;
void createProcess()
{
    if((res = fork()) == -1){
        printf("Cannot create fork\n");
        exit(1);
    }
}

void writeToPipe(int *fd)
{
    if(res == 0){
    // Closing the read channel
    close(fd[0]);
    
    struct Data arr[5];
    arr[0].DataId = 1;
    arr[0].DataValue = 100;
    arr[0].DataCategory = URGENT;
    
    arr[1].DataId = 2;
    arr[1].DataValue = 200;
    arr[1].DataCategory = DEFERRED;
    
    arr[2].DataId = 3;
    arr[2].DataValue = 300;
    arr[2].DataCategory = ROUTINE;
    
    arr[3].DataId = 4;
    arr[3].DataValue = 400;
    arr[3].DataCategory = URGENT;
    
    arr[4].DataId = 5;
    arr[4].DataValue = 500;
    arr[4].DataCategory = DEFERRED;
    
    // Writing to the pipe
    write(fd[1], arr, sizeof(arr));

    // Closing the write channel

    close(fd[1]);
    }
}

int findMaxDataValue(struct Data* arr){
    int maxDataValue = 0;
    
    for (int i = 0; i < 5; i++) {
        if (arr[i].DataValue > maxDataValue) {
            maxDataValue = arr[i].DataValue;
        }
    }
    return maxDataValue;
}

void findDataByCategory(struct Data* arr, DATA_CATEGORY cat) {    
    for (int i = 0; i < 5; i++) {
        if (arr[i].DataCategory == cat) {
            printf("Data Category is: %d\n", arr[i].DataCategory);
        }
    }
}
//reading fromPipe
void readFromPipe(int *fd)
{
    if(res !=0){
        close(fd[1]); //closing the write channel
        
        int of = open("tmp.txt", O_WRONLY | O_CREAT , 0777);
        if (of == -1) {
            printf("Failed to open the file.\n");
            exit(1);
        }
        dup2(of,1);
        // Redirect output to the file using dup2
        struct Data data[5];
        read(fd[0], data, sizeof(data));
        
        // Closing the read channel
        close(fd[0]);
                
        int maxData = findMaxDataValue(data);
        
        printf("Data Value is : %d", maxData);
        printf("\n");
        
        DATA_CATEGORY toFind = ROUTINE;
        findDataByCategory(data, toFind);

        close(of);
    }
}