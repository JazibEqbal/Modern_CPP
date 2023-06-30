#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include "Data.h"

int* createFileDescriptors();
int* createPipe(int*);
void createProcess();
void writeToPipe(int*);
void readFromPipe(int *fd);
int findMaxDataValue(struct Data* arr);

void findDataByCategory(struct Data* arr, DATA_CATEGORY cat);
#endif // FUNCTIONALITIES_H
