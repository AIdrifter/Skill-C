#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a,*b,c;
    int array[100]={0};
    int i;
    for(i=0;i<=99;i++)
        array[i]=i;
    a=array;
    b=array;
    c=array;


    for(i=0;i<=99;i++){
        printf("a[%d] ",a[i]);
        printf("a[%d] ",b[i]);
        printf("a[%d] ",c[i]);
    }
}
