#include <stdio.h>

void main (int argc, char *argv[])
{
    while (--argc)              /* an abbreviation of while(--argc != 0) */
    {
        printf ("%s ", *++argv);
    }
    puts("");
    printf ("argv[0] %s \n", argv[0]);
}

