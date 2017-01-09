#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To resolve 32 bit or 64 bit pointer problem
// the best way is used intptr_t
// http://b8807053.pixnet.net/blog/post/164224857-%E4%BD%BF%E7%94%A8%E8%AE%8A%E6%95%B8%E5%9E%8B%E5%88%A5%E7%9A%84%E8%89%AF%E5%A5%BD%E7%BF%92%E6%85%A3
#include <stdint.h>

unsigned long func1(int a,int b){
    printf("%lu sum %d = %d %d \n",(intptr_t)&func1,a+b,a,b);
    return (intptr_t)&func1;
}

unsigned long func2(int a,int b){
    printf("%lu difference %d = %d %d \n",(intptr_t)&func2,a-b,a,b);
    return (intptr_t)&func2;
}

int main(){
    int a = 10,b = 15;
    // The printf sequence is from right to left
    // <-------------------
    char buffer[10] = {0};
    char buffer2[10] = {1,2,3,4,5,[5]=6};
    printf("check function pointer 0x%0lu 0x%0lu\n", func1(a,b), func2(a,b));
    printf("check buffer address 0x%0lu 0x%0lu ", (intptr_t)&buffer ,(intptr_t)&buffer2);
}



