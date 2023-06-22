#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("My pid is: %d\n",getpid()); //1 times
    fork();
    printf("My pid is: %d\n",getpid()); //2 times
    fork();
    printf("My pid is: %d\n",getpid()); //4 times
    fork();
    printf("My pid is: %d\n",getpid()); //8 times == 1+2+4+8 = 15
}