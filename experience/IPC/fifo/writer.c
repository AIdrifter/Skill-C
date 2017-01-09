#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define FIFONAME "MY_FIFO"
int idx=0;

int SetIpcFileValue (const char *filename, const char *value, int valueSize )
{
    printf("before write %d\n",idx++);
    int fd;

    /* create the FIFO (named pipe) */
    if(mkfifo(filename, 0666)==-1)
    {
        printf("mkfifo() status\n:%s\n", strerror(errno));
    }

    /* write "Hi" to the FIFO */
    fd = open(filename, O_WRONLY);
    printf("open() status\n:%s\n", strerror(errno));
    write(fd, value, valueSize);
    close(fd);

    printf("after write \n");
    /* remove the FIFO */
    unlink(filename);
}

int main(){
    char buf[100]={'\0'};
    while(1){
        sprintf(buf,"NUMBER %d",idx);
        SetIpcFileValue(FIFONAME,buf,sizeof(buf));
        sleep(3);
    }
}
