// #include "functionalities.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
#include "Program_1.h"
#include "Program_2.h"

int main(){
    showHostname();
    showDateAndTime();
    showNames();

    const char* pipe_fd = "NamedForkPipe";
    int input_array[5];
    int result_array[5];

    CreateNamedPipe(pipe_fd);
    createNewProcess();
    WriteToPipe(pipe_fd, result_array);
    square(result_array, 5);
    readFromPipe(pipe_fd, input_array);
}