#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int a=5, b= 6, c;

    sum:
        c = a+b;

    printf("Address of sum label in memory: %p", &&sum);
    return 0;
}

