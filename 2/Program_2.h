#ifndef PROGRAM_2_H
#define PROGRAM_2_H
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>

void CreateNamedPipe(const char *pipeName);

int* createNewProcess();

void square(int *result, int size);

void WriteToPipe(const char *pipeName,int *res);

void readFromPipe(const char *pipeName,int *res);

#endif // PROGRAM_2_H
