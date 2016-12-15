#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int ret=0;
    FILE * pFile;
    char buffer[100];
    pFile = fopen ("myfile.txt","rwb+");
    ret = fwrite ("fopen example",sizeof(char),15,pFile);
    fprintf(stderr,"%d %s  ret %d\n",errno,strerror(errno),ret);

    ret = fread (buffer,1,5,pFile);
    printf(".......... %s \n",buffer);

    ret = unlink("myfile.txt");
    fprintf(stderr,"%d %s  ret %d\n",errno,strerror(errno),ret);

    ret = fwrite ("fopen example",sizeof(char),15,pFile);
    fprintf(stderr,"%d %s  ret %d\n",errno,strerror(errno),ret);

    ret = fread (buffer,1,20,pFile);
    printf(".......... %s \n",buffer);

    fprintf(stderr,"%d %s  ret %d\n",errno,strerror(errno),ret);

    fclose(pFile);
}
