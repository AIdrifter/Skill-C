#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int ret=0;
    FILE * pFile;
    pFile = fopen ("myfile.txt","wb+");
    ret = fwrite ("fopen example",sizeof(char),15,pFile);
    fprintf(stderr,"%d %s  ret %d\n",errno,strerror(errno),ret);

    ret = unlink("myfile.txt");
    fprintf(stderr,"%d %s  ret %d\n",errno,strerror(errno),ret);

    ret = fwrite ("fopen example",sizeof(char),15,pFile);
    fprintf(stderr,"%d %s  ret %d\n",errno,strerror(errno),ret);

    fclose(pFile);
}
