#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void square(int n){
    printf("Square of %d is %d\n",n,n*n);
}

int main(){
    int n=5;
    //fork the parent and create the child. (confirm if this was successfull)
    int res;
    if((res = fork()) == -1){       //an asignment operation return right hand operand converted to type of left hand operand
        printf("Error");
    }
    //if we are in parent dont do anything
    if(res !=0){
        printf("Not doing anything\n");
    }
    //if we are in child , call square
    if(res == 0 ){
        square(n);
    }
}