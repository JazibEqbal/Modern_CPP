#include "functionalities.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>


int main(){
    const char* pipeName = "NamedPipe";
    CreateNamedPipe(pipeName);
    WriteToPipe(pipeName);
}