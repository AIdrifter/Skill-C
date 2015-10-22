#include <stdio.h>
#include <stdlib.h>

#define LOG_LEVEL_1 1
#define LOG_LEVEL_2 2
#define LOG_LEVEL_3 3
#define LOG_LEVEL_4 4

void foo(int number){
    int i;
    for(i=0;i<=number;i++)
        printf("test doo\n");
}

int main(){
    int flag=1;
    while(1){
        foo(LOG_LEVEL_1);
        foo(LOG_LEVEL_2);
        foo(LOG_LEVEL_3);
        foo(LOG_LEVEL_4);
    }
}
