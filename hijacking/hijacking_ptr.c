#include <stdio.h>
#include <stdlib.h>

int fun1(){
    printf("%s...\n",__func__);
}

int fun2(){
    printf("%s...\n",__func__);
}


int main(){
    printf("fun1 0x%x  fun2 0x%x\n",&fun1,&fun2);
    fun1();
    fun2();
    // hijacking function 1 to 2
    
}
