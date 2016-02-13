#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int A[] = {1,2,3,4,5,6,7,8,9};
    char C[] = {'A','B','C','F','E','F','G','H','I'};
    memcpy(A,C,8);
    memcpy(C,A,8);
    memcpy(A+4,C,8);
    memcpy((void*)A+4,C,8);
    return 0;
    printf("hello world\n");
}


