#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "functionalities.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*
    create a named pipe
    pipe name could be taken as input
*/
void CreateNamedPipe(const char* pipeName);

/*
    use fork call to create new process
*/

int* createNewProcess();
/*
    write some data into the file
    check if write was successful
*/
void WriteToPipe(const char* pipeName,int *res);

void readFromPipe(const char* pipeName,int *res);

#endif // FUNCTIONALITIES_H
