#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t i;
    int (*ptr_to_main)() = main;
    for (i=0; i<sizeof ptr_to_main; i++)
            printf("%.2x", ((unsigned char *)&ptr_to_main)[i]);
    puts("\n");
}

