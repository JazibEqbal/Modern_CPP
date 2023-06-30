#ifndef DATA_H
#define DATA_H
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

//enumfor storing categorical data
typedef enum {
    URGENT,
    DEFERRED,
    ROUTINE
} DATA_CATEGORY;

//structure
struct Data
{
    int DataId;
    int DataValue;
    DATA_CATEGORY DataCategory;
 
};

#endif // DATA_H
