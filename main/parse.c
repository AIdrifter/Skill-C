#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char *optarg;
void usage(char *argv0)
{
    fprintf(stderr,
            "Usage: %s [-c count] [-r] [-s]",
            argv0);
}
int main(int argc, char *argv[]) 
{
//    for (;;) {
//        // use : to block c
//        char c = getopt( argc, argv, "c:rs");
//        if (c == EOF) break;


    int c;
    while ((c = getopt(argc, argv, "c:rs")) != -1) 
    {
        switch (c) {
            case 'c':
                printf("parse c ");
                printf("input parameter is %s .....\n",optarg);
                break;
            case 'r':
                printf("parse r \n");
                break;
            case 's':
                printf("parse s \n");
                break;
            default:  // show usage
                usage(argv[0]);
                exit(1);
        }
    }
}
