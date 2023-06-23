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
    write some data into the file
    check if write was successful
*/
void WriteToPipe(const char* pipeName);

#endif // FUNCTIONALITIES_H
