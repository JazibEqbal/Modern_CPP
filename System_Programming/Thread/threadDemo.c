#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

/*
    pthread_t *__restrict__ __newthread, //pointer to thread variable
    const pthread_attr_t *__restrict__ __attr, //pointer to attributes for thread for advanced operation
    void *(*__start_routine)(void *), //pointer to the function
    void *__restrict__ __arg    //arguments to be passed
*/
void* square(void* arg){
    int* n = (int*) arg; 
    printf("Square of %d is %d", n, (*n)*(*n));
}

void* printHello(){
    printf("Thread\n");
}

int main(){
    int* n = (int*) malloc(1*sizeof(int)); //convert void pointer to valid int pointer
    *n = 5;
    pthread_t  t1;
    pthread_create(&t1,NULL,&square,(void*)n); //4th parameter is argument

    pthread_join(t1,NULL);
    free(n);
}