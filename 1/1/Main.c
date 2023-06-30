#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include "Data.h"
#include "functionalities.h"

int main(){
    int* fd = createFileDescriptors();
    fd = createPipe(fd);
    createProcess();
    writeToPipe(fd);
    readFromPipe(fd);

    free(fd);
}